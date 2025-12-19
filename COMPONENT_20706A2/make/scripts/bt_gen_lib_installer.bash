#!/bin/bash
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
(set -o igncr) 2>/dev/null && set -o igncr; # this comment is required
set -e

#######################################################################################################################
# This script is designed to generate a source file used to init patch libraries.
#
# usage:
# 	gen_source_lib_installer.bash <OUTPUT_FILE>
# 	bt_gen_lib_installer.bash 	--shell=<modus shell path>
#								--scripts=<wiced scripts path>
#								--out=<output *.c file>
#								--verbose
#								<list of libraries *.a>
#
#######################################################################################################################

USAGE="(-s=|--shell=)<shell path> (-w=|--scripts=)<wiced scripts path> (-o=|--out=)<output file> <libraries>"
if [[ $# -eq 0 ]]; then
	echo "usage: $0 $USAGE"
	exit 1
fi

for i in "$@"
do
	case $i in
		-s=*|--shell=*)
			CYMODUSSHELL="${i#*=}"
			shift
			;;
		-w=*|--scripts=*)
			SCRIPTS_DIR="${i#*=}"
			SCRIPTS_DIR=${SCRIPTS_DIR//\\/\/}
			shift
			;;
		-o=*|--out=*)
			OUTPUT_FILE="${i#*=}"
			OUTPUT_FILE=${OUTPUT_FILE//\\/\/}
			shift
			;;
		-v|--verbose)
			VERBOSE=1
			shift
			;;
		-h|--help)
			HELP=1
			echo "usage: $0 $USAGE"
			exit 1
			;;
		*)
			LIBS+=" $i"
			;;
	esac
done

if [ "$VERBOSE" != "" ]; then
	echo "Script: $0"
	echo "1: CYMODUSSHELL : $CYMODUSSHELL"
	echo "2: SCRIPTS_DIR  : $SCRIPTS_DIR"
	echo "3: OUTPUT_FILE  : $OUTPUT_FILE"
	echo "4: LIBRARIES    : $LIBS"
fi

# if lib_installer exists, don't make a new one
# we need to always generate until we can 'make clean' to remove existing
if [ -e "$OUTPUT_FILE" ]; then
    echo "$OUTPUT_FILE already present, use clean if it needs updating"
    exit 0
fi

set +e

# set up some tools that may be native and not modus-shell
CY_TOOL_PERL=perl
if ! type "$CY_TOOL_PERL" &> /dev/null; then
CY_TOOL_PERL=$CYMODUSSHELL/bin/perl
fi


"$CY_TOOL_PERL" -I "${SCRIPTS_DIR}" "${SCRIPTS_DIR}/wiced-gen-lib-installer.pl" $LIBS "${OUTPUT_FILE}"
if [ $? -eq 0 ]; then
   echo "generated $OUTPUT_FILE"
else
   echo "failed to generate $OUTPUT_FILE"
   exit 1
fi
