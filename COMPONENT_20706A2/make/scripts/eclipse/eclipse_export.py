#!/usr/bin/env python3
#
# (c) 2016-2025, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
# This software, associated documentation and materials ("Software") is
# owned by Infineon Technologies AG or one of its affiliates ("Infineon")
# and is protected by and subject to worldwide patent protection, worldwide
# copyright laws, and international treaty provisions. Therefore, you may use
# this Software only as provided in the license agreement accompanying the
# software package from which you obtained this Software. If no license
# agreement applies, then any use, reproduction, modification, translation, or
# compilation of this Software is prohibited without the express written
# permission of Infineon.
# 
# Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
# IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
# THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
# SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
# Infineon reserves the right to make changes to the Software without notice.
# You are responsible for properly designing, programming, and testing the
# functionality and safety of your intended application of the Software, as
# well as complying with any legal requirements related to its use. Infineon
# does not guarantee that the Software will be free from intrusion, data theft
# or loss, or other breaches ("Security Breaches"), and Infineon shall have
# no liability arising out of any Security Breaches. Unless otherwise
# explicitly approved by Infineon, the Software may not be used in any
# application where a failure of the Product or any consequences of the use
# thereof can reasonably be expected to result in personal injury.
#

import argparse
import os.path
import re
import sys
from collections import namedtuple

ECLIPSE_FILE_LINK = '1'
ECLIPSE_DIRECTORY_LINK = '2'
ECLIPSE_LINK_STRING = '\t\t<link>\n\t\t\t<name>{0}</name>\n\t\t\t<type>{1}</type>\n\t\t\t<locationURI>{2}</locationURI>\n\t\t</link>\n'

"""
input file format:(1 comma seperated entries per line)
------------------
app_name
external sources
external includes
external apps
external searches
getlibs shared dir
"""
def parse_inFile(fileName):
    """
    Parses a .cmsisdata file to extract the information necessary for project connection file creation

    Returns a tuple of (project_name device_name core linker_script defineList includePathList cSrcList asmSrcList headersList libsList)
    """
    inFileData = namedtuple('inFileData', 'app_name sources includes apps searches shared_dir')

    with open(fileName, 'r') as fp:
        app_name = fp.readline().strip()
        sources = list(filter(None, fp.readline().strip().split(',')))
        includes = list(filter(None, fp.readline().strip().split(',')))
        apps = list(filter(None, fp.readline().strip().split(',')))
        searches = list(filter(None, fp.readline().strip().split(',')))
        shared_dir = fp.readline().strip()
    return inFileData(app_name, sources, includes, apps, searches, shared_dir)

def process_in_file_item(item):
    return item.strip().strip('\"').rstrip('/')

def create_eclipse_uri(path):
    if not path.startswith('../'):
        return 'file://' + path

    parent_count = 0
    parent_path = path
    while parent_path.startswith('../'):
        parent_path = parent_path.lstrip('../')
        parent_count += 1
    return 'PARENT-{0}-PROJECT_LOC/{1}'.format(parent_count, parent_path)

def create_virtual_folders_if_not_exist(virtual_path, virtual_dir_set):
    resources = ''
    path = ''
    dirs = re.split('/|\\\\', virtual_path)
    for dir in dirs:
        if path != '' and dir != '':
            path += '/'
        path += dir
        if path and not path in virtual_dir_set:
            virtual_dir_set.add(path)
            resources += ECLIPSE_LINK_STRING.format(path, ECLIPSE_DIRECTORY_LINK, 'virtual:/virtual')
    return resources

def create_single_link(item, link_type, virtual_parent, virtual_dir_set):
    processed_item = process_in_file_item(item)
    virtual_path = os.path.join(virtual_parent, os.path.basename(processed_item))
    uri = create_eclipse_uri(processed_item)

    return create_virtual_folders_if_not_exist(virtual_parent, virtual_dir_set) + ECLIPSE_LINK_STRING.format(virtual_path, link_type, uri)

def create_linked_resources(inFileData):
    resources = ''
    virtual_dir_set = set()

    for item in inFileData.sources:
        resources += create_single_link(item, ECLIPSE_FILE_LINK, 'external_source', virtual_dir_set)
    for item in inFileData.includes:
        resources += create_single_link(item, ECLIPSE_DIRECTORY_LINK, 'external_includes', virtual_dir_set)
    for item in inFileData.apps:
        resources += create_single_link(item, ECLIPSE_DIRECTORY_LINK, '', virtual_dir_set)
    for item in inFileData.searches:
        processed_item = process_in_file_item(item)
        # if the directory is rooted from the shared_dir, then we create a virtual path rooted from a new virtual shared_dir. The virtual shared_dir will be placed directory under the project
        if inFileData.shared_dir != '' and inFileData.shared_dir and processed_item.startswith(inFileData.shared_dir):
            virtual_getlibs_dir = os.path.basename(inFileData.shared_dir)
            # directory rooted from getlibs dir
            virtual_rooted_dir = os.path.dirname(processed_item[len(inFileData.shared_dir) + 1 : ])
            virtual_dir = os.path.join(virtual_getlibs_dir, virtual_rooted_dir)
            resources += create_single_link(item, ECLIPSE_DIRECTORY_LINK, virtual_dir, virtual_dir_set)
        else:
            resources += create_single_link(item, ECLIPSE_DIRECTORY_LINK, '', virtual_dir_set)
    return resources

def replace_project_data(inFileData, template, output):
    filedata = ''
    with open(template, 'r') as fp:
        filedata = fp.read()

    newfileData = filedata.replace('&&APP_NAME&&', inFileData.app_name).replace('&&LINKED_RESOURCES&&',create_linked_resources(inFileData))

    with open(output, 'w') as fp:
        fp.writelines(newfileData)

def is_valid_file(parser, arg):
    if not os.path.isfile(arg):
        parser.error('The file %s does not exist!' % arg)
    return arg

def run_export():
    argParser = argparse.ArgumentParser()
    argParser.add_argument('-i', dest='inFile', required=True, help='Project data file generated by `make eclipse`', metavar='FILE', type=lambda x: is_valid_file(argParser, x))
    argParser.add_argument('-p', dest='templateFile', required=True, help='The eclipse template .project file', metavar='FILE', type=lambda x: is_valid_file(argParser, x))
    argParser.add_argument('-o', dest='outputFile', required=True, help='The eclipse .project file to create', metavar='FILE')

    args = argParser.parse_args()

    inFileData = parse_inFile(args.inFile)
    replace_project_data(inFileData, args.templateFile, args.outputFile)


def main():
    try:
        run_export()
    except Exception as error:
        print("ERROR: %s" % error)
        sys.exit(1)

if __name__ == '__main__':
    main()
