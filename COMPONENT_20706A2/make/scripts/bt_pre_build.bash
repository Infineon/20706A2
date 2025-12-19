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
# This script performs pre-build operations to create *.ld file.
#
# usage:
# 	bt_pre_build.bash 	--shell=<modus shell path>
#						--scripts=<wiced scripts path>
#						--def=<ld predefines>
#						--patch=<patch elf file>
#						--ld=<ld script file>
#						--direct_load
#						--overlay=<overlay ld script snippet file>
#						--verbose
#
#######################################################################################################################

USAGE="(-s=|--shell=)<shell path> (-w=|--scripts=)<wiced scripts path> (-f=|--defs=)<linker defines> (-p=|--patch=)<patch elf> (-l=|--ld=)<linker script output> (-o=|--overlay=)<overlay snippet> (-d|--direct)"
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
			CYWICEDSCRIPTS="${i#*=}"
			shift
			;;
		-f=*|--defs=*)
			CY_APP_LD_DEFS="${i#*=}"
			shift
			;;
		-p=*|--patch=*)
			CY_APP_PATCH="${i#*=}"
			shift
			;;
		-l=*|--ld=*)
			CY_APP_LD="${i#*=}"
			shift
			;;
		-o=*|--overlay=*)
			CY_APP_OVERLAY="${i#*=}"
			shift
			;;
		-d|--direct)
			CY_APP_DIRECT_LOAD=1
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
			echo "bad parameter $i"
			echo "usage: $0 $USAGE"
			echo "failed to generate $CY_APP_LD"
			exit 1
			;;
	esac
done

if [ "$VERBOSE" != "" ]; then
	echo Script: bt_pre_build
	echo 1: CYMODUSSHELL    : $CYMODUSSHELL
	echo 2: CYWICEDSCRIPTS  : $CYWICEDSCRIPTS
	echo 3: CY_APP_LD_DEFS  : $CY_APP_LD_DEFS
	echo 4: CY_APP_PATCH    : $CY_APP_PATCH
	echo 5: CY_APP_LD       : $CY_APP_LD
	echo 6: DIRECT_LOAD     : $CY_APP_DIRECT_LOAD
	echo 7: OVERLAY         : $CY_APP_OVERLAY
fi

# if *.ld exists, don't make a new one
# we will always run this until we can have 'make clean' that removes *.ld
if [ -e "$CY_APP_LD" ]; then
    echo "$CY_APP_LD already present, use clean if it needs updating"
    exit 0
fi

set +e

# set up some tools that may be native and not modus-shell
CY_TOOL_PERL=perl
if ! type "$CY_TOOL_PERL" &> /dev/null; then
CY_TOOL_PERL=$CYMODUSSHELL/bin/perl
fi

#create ld file
"$CY_TOOL_PERL" -I "$CYWICEDSCRIPTS" "$CYWICEDSCRIPTS/wiced-gen-ld.pl" $CY_APP_LD_DEFS DIRECT_LOAD=$CY_APP_DIRECT_LOAD "$CY_APP_PATCH" "$CY_APP_OVERLAY" out="$CY_APP_LD"
if [ $? -eq 0 ]; then
   echo "generated $CY_APP_LD"
else
   echo "failed to generate $CY_APP_LD"
   exit 1
fi
