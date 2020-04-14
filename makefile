#
# Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
# Cypress Semiconductor Corporation. All Rights Reserved.
#
# This software, including source code, documentation and related
# materials ("Software"), is owned by Cypress Semiconductor Corporation
# or one of its subsidiaries ("Cypress") and is protected by and subject to
# worldwide patent protection (United States and foreign),
# United States copyright laws and international treaty provisions.
# Therefore, you may use this Software only as provided in the license
# agreement accompanying the software package from which you
# obtained this Software ("EULA").
# If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
# non-transferable license to copy, modify, and compile the Software
# source code solely for use in connection with Cypress's
# integrated circuit products. Any reproduction, modification, translation,
# compilation, or representation of this Software except as specified
# above is prohibited without the express written permission of Cypress.
#
# Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
# reserves the right to make changes to the Software without notice. Cypress
# does not assume any liability arising out of the application or use of the
# Software or any product or circuit described in the Software. Cypress does
# not authorize its products for use in any products where a malfunction or
# failure of the Cypress product may reasonably be expected to result in
# significant property damage, injury or death ("High Risk Product"). By
# including Cypress's product in a High Risk Product, the manufacturer
# of such system or application assumes all risk of such use and in doing
# so agrees to indemnify Cypress against all liability.
#

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

#
# Basic Configuration
#
LIBNAME=$(CY_TARGET_DEVICE)_baselib
TOOLCHAIN=GCC_ARM
CONFIG?=Debug

#
# Advanced Configuration
#
SOURCES=
INCLUDES=\
    $(CY_BASELIB_PATH)/include \
    $(CY_BASELIB_PATH)/include/hal \
    $(CY_BASELIB_PATH)/include/internal \
    $(CY_BASELIB_PATH)/include/stack \
    $(CY_BASELIB_PATH)/internal/$(CY_TARGET_DEVICE) \
    $(CY_SHARED_PATH)/dev-kit/btsdk-include \
    $(CY_SHARED_PATH)/dev-kit/bsp/TARGET_$(TARGET)
DEFINES=
VFP_SELECT=
CFLAGS=
CXXFLAGS=
ASFLAGS=
LDFLAGS=
LDLIBS=
LINKER_SCRIPT=
PREBUILD=
POSTBUILD=
COMPONENT=

################################################################################
# Paths
################################################################################

# Path (absolute or relative) to the project
CY_APP_PATH=.

# Path to the root of the BTSDK
CY_SHARED_PATH=$(CY_APP_PATH)/../../..
# absolute path to the root of the BTSDK
CY_SHARED_PATH_ABS=$(CURDIR)/../../..

# Path (absolute or relative) to the base library
CY_BASELIB_PATH=$(CY_SHARED_PATH)/dev-kit/baselib/$(CY_TARGET_DEVICE)

# lib-specific includes
INCLUDES+=

# Extra makefiles includes - target makefile
CY_EXTRA_INCLUDES=$(CY_SHARED_PATH)/dev-kit/bsp/TARGET_$(TARGET)/$(TARGET).mk

# Absolute path to the compiler (Default: GCC in the tools)
CY_COMPILER_PATH=

# Locate ModusToolbox IDE helper tools folders in default installation
# locations for Windows, Linux, and macOS.
CY_WIN_HOME=$(subst \,/,$(USERPROFILE))
CY_TOOLS_PATHS ?= $(wildcard \
    $(CY_WIN_HOME)/ModusToolbox/tools_* \
    $(HOME)/ModusToolbox/tools_* \
    /Applications/ModusToolbox/tools_* \
    $(CY_IDE_TOOLS_DIR))

# If you install ModusToolbox IDE in a custom location, add the path to its
# "tools_X.Y" folder (where X and Y are the version number of the tools
# folder).
CY_TOOLS_PATHS+=

# Default to the newest installed tools folder, or the users override (if it's
# found).
CY_TOOLS_DIR=$(lastword $(sort $(wildcard $(CY_TOOLS_PATHS))))

ifeq ($(CY_TOOLS_DIR),)
$(error Unable to find any of the available CY_TOOLS_PATHS -- $(CY_TOOLS_PATHS))
endif

# getlibs path
CY_GETLIBS_PATH=.

# if not coming from app makefile (IDE), skip recipe
ifeq ($(CY_TARGET_DEVICE)$(TARGET),)
CY_SKIP_RECIPE=1
endif

# added as work around until make/core 'make vscode' always creates rsp files
ifneq ($(filter vscode,$(MAKECMDGOALS)),)
VSCODE_WA:=$(shell $(foreach listfile,inclist.rsp liblist.rsp artifact.rsp,\
     mkdir -p $(CY_BASELIB_PATH)/build/$(TARGET)/$(CONFIG)/$(dir $(listfile));\
     touch $(CY_BASELIB_PATH)/build/$(TARGET)/$(CONFIG)/$(listfile);))
endif

include $(CY_TOOLS_DIR)/make/start.mk

# if not coming from app makefile (IDE), stub out all: target
ifeq ($(CY_TARGET_DEVICE)$(TARGET),)
all:
	@echo This is not a buildable application project - \"make $@\" : Success
endif
