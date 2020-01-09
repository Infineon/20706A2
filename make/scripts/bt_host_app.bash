#!/bin/bash
(set -o igncr) 2>/dev/null && set -o igncr; # this comment is required
set -e

#######################################################################################################################
# This script launches host applications from Eclipse external tools bash launch configs
#
# usage:
# 	bt_host_app.bash	--path=<app path>
#						--oshint=<os hint>
#						--verbose
#
#######################################################################################################################

USAGE="(-p=|--path=)<app path> (-o=|--oshint=)<os hint>"
if [[ $# -eq 0 ]]; then
	echo "usage: $0 $USAGE"
	exit 1
fi

for i in "$@"
do
	case $i in
		-p=*|--path=*)
			CY_APP_PATH="${i#*=}"
			shift
			;;
		-o=*|--oshint=*)
			CY_OS_HINT="${i#*=}"
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
	echo Script: bt_host_app.bash, launches app
	echo 1: CY_APP_PATH  	: $CY_APP_PATH
	echo 2: CY_OS_HINT  	: $CY_OS_HINT
fi

if [[ $CY_APP_PATH = *"client_control"* ]]; then
  echo ""
  echo "ClientControl source code provided at $CY_APP_PATH"
  echo ""
  if [ "$CY_OS_HINT" = "Windows" ]; then
    CY_APP_PATH="$CY_APP_PATH/Windows/ClientControl.exe"
	echo "App full path $CY_APP_PATH"
	if [ -e "$CY_APP_PATH" ]; then
	  $CY_APP_PATH
	else
	  echo "$CY_APP_PATH not found, exiting"
	  exit 1
	fi
  else
	if [ "$CY_OS_HINT" = "Linux" ]; then
	  CY_APP_PATH="$CY_APP_PATH/Linux64/RunClientControl.sh"
	  echo "App full path $CY_APP_PATH"
	  if [ -e "$CY_APP_PATH" ]; then
	    $CY_APP_PATH
	  else
	    echo "$CY_APP_PATH not found, exiting"
	    exit 1
	  fi
	else
	  CY_APP_PATH="$CY_APP_PATH/OSX/ClientControl.app"
	  echo "App full path $CY_APP_PATH"
	  if [ -e "$CY_APP_PATH" ]; then
	    open -a $CY_APP_PATH
	  else
	    echo "$CY_APP_PATH not found, exiting"
	  exit 1
	fi
  fi
fi
fi

if [[ $CY_APP_PATH = *"BTSpy"* ]]; then
  if [ "$CY_OS_HINT" = "Windows" ]; then
    CY_APP_PATH="$CY_APP_PATH/BTSpy.exe"
	echo "App full path $CY_APP_PATH"
	if [ -e "$CY_APP_PATH" ]; then
	  $CY_APP_PATH
	else
	  echo "$CY_APP_PATH not found, exiting"
	  exit 1
	fi
  else
	if [ "$CY_OS_HINT" = "Linux" ]; then
	  CY_APP_PATH="$CY_APP_PATH/RunBtSpy.sh"
	  echo "App full path $CY_APP_PATH"
	  if [ -e "$CY_APP_PATH" ]; then
	    $CY_APP_PATH
	  else
	    echo "$CY_APP_PATH not found, exiting"
	    exit 1
	  fi
	else
	  CY_APP_PATH="$CY_APP_PATH/bt_spy.app"
	  echo "App full path $CY_APP_PATH"
	  if [ -e "$CY_APP_PATH" ]; then
	    open -a $CY_APP_PATH
	  else
	    echo "$CY_APP_PATH not found, exiting"
	    exit 1
	  fi
    fi
  fi
fi
