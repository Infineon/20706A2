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

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

#
# Flags construction
#
CY_RECIPE_CFLAGS?=\
    $(CY_CORE_CFLAGS)\
    $(CY_TOOLCHAIN_CFLAGS)\
    -Wno-unused-variable\
    -Wno-unused-function\
    @$(CY_CORE_PATCH_CFLAGS)

CY_RECIPE_ASFLAGS?=\
    $(CY_CORE_SFLAGS)\
    $(CY_TOOLCHAIN_ASFLAGS)

ifeq ($(NO_OBFS),)
CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH:.elf=.sym)
else
CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH)
endif

# get resource usage information for build
-include $(dir $(CY_CORE_PATCH))/firmware_resource_usage.inc
CY_CORE_DEFINES+=-DCY_PATCH_ENTRIES_BASE=$(CY_PATCH_ENTRIES_BASE)

CY_RECIPE_LDFLAGS?=\
    $(LDFLAGS)\
    $(CY_TOOLCHAIN_LDFLAGS)\
    $(CY_CORE_LDFLAGS)\
    -Wl,--entry=$(CY_CORE_APP_ENTRY)\
    -Wl,--no-warn-mismatch\
    -Wl,--just-symbols="$(CY_CORE_PATCH_SYMBOLS)"\
    -T$(CY_CONFIG_DIR)/$(APPNAME).ld

CY_RECIPE_ARFLAGS?=$(CY_TOOLCHAIN_ARFLAGS)

#
# Defines construction
#
CY_RECIPE_DEFINES?=\
    $(addprefix -D,$(DEFINES))\
    $(CY_APP_DEFINES)\
    $(CY_APP_OTA_DEFINES)\
    $(CY_CORE_DEFINES)\
    $(CY_CORE_EXTRA_DEFINES)\
    $(CY_TOOLCHAIN_DEBUG_DEFINES)\
    -DSPAR_CRT_SETUP=$(CY_CORE_APP_ENTRY)\
    $(foreach feature,$(CY_COMPONENT_LIST),-DCOMPONENT_$(subst -,_,$(feature)))\
    -DCY_SUPPORTS_DEVICE_VALIDATION\
    -D$(subst -,_,$(DEVICE))

#
# Application version information
# Format is 2-bytes app id, 1-byte major, 1-byte minor
#
ifndef APP_VERSION_APP_ID
APP_VERSION_APP_ID = 0
endif
ifndef APP_VERSION_MAJOR
APP_VERSION_MAJOR = 0
endif
ifndef APP_VERSION_MINOR
APP_VERSION_MINOR = 0
endif
APP_VERSION = $(shell env printf "0x%02X%02X%04X" $(APP_VERSION_MINOR) $(APP_VERSION_MAJOR) $(APP_VERSION_APP_ID))

#
# Includes construction
#
# macro to remove duplicate paths from INC lists, but preserve order of 1st instances
define f_uniq_paths
$(eval seen :=)$(foreach _,$1,$(if $(filter $(abspath $_),$(abspath ${seen})),,$(eval seen += $_)))${seen}
endef
# build COMPONENT includes with proper directory prefix
CY_COMPONENT_PATHS=$(addprefix COMPONENT_,$(COMPONENTS))
CY_COMPONENT_DISABLE_FILTERS=$(addprefix %/COMPONENT_,$(filter-out CY_DEFAULT_COMPONENT,$(DISABLE_COMPONENTS)))
CY_COMPONENT_SEARCH_PATHS=$(patsubst ./%,%,$(CY_SEARCH_APP_INCLUDES) $(SEARCH_LIBS_AND_INCLUDES) $(INCLUDES))
#$(info CY_COMPONENT_SEARCH_PATHS $(CY_COMPONENT_SEARCH_PATHS))
CY_COMPONENT_INCLUDES=$(filter-out $(CY_COMPONENT_DISABLE_FILTERS), \
        $(foreach search_path,$(CY_COMPONENT_SEARCH_PATHS), \
          $(foreach component,$(CY_COMPONENT_PATHS), \
            $(wildcard $(search_path)/$(component)) )))
#$(info CY_COMPONENT_INCLUDES $(CY_COMPONENT_INCLUDES))
#$(info CY_COMPONENT_DISABLE_FILTERS $(CY_COMPONENT_DISABLE_FILTERS))
CY_RECIPE_INCLUDES?=\
    $(CY_TOOLCHAIN_INCLUDES)\
    $(addprefix -I,$(INCLUDES))\
    $(addprefix -I,$(CY_SEARCH_APP_INCLUDES))\
    $(addprefix -I,$(call f_uniq_paths,$(CY_COMPONENT_INCLUDES)))
#$(info CY_RECIPE_INCLUDES $(CY_RECIPE_INCLUDES))

#
# Sources construction
#
CY_RECIPE_SOURCE=$(CY_SEARCH_APP_SOURCE)

#
# Libraries construction
#
CY_RECIPE_LIBS=$(LDLIBS) $(CY_SEARCH_APP_LIBS)

#
# Generate source step
#
ifeq ($(LIBNAME),)
CY_RECIPE_GENERATED_FLAG=TRUE
CY_RECIPE_GENERATED=$(CY_GENERATED_DIR)/lib_installer.c
CY_RECIPE_GENSRC=\
    bash --norc --noprofile\
    "$(CY_INTERNAL_BASELIB_PATH)/make/scripts/bt_gen_lib_installer.bash"\
    "--shell=$(CY_MODUS_SHELL_DIR_BWC)"\
    "--scripts=$(CY_INTERNAL_BASELIB_PATH)/make/scripts"\
    "--out=$(CY_RECIPE_GENERATED)"\
    $(addprefix $(CY_INTERNAL_BASELIB_PATH)/$(CY_CORE_PATCH_LIB_PATH)/,$(CY_APP_PATCH_LIBS))\
    $(addprefix $(CY_APP_PATCH_LIBS_PRO_PATH)/,$(CY_APP_PATCH_LIBS_PRO))\
    $(if $(VERBOSE),"--verbose")\
    && CY_CMD_TERM=
endif

#
# Prebuild step
#
ifeq ($(LIBNAME),)
CY_RECIPE_PREBUILD?=\
    bash --norc --noprofile\
    "$(CY_INTERNAL_BASELIB_PATH)/make/scripts/bt_pre_build.bash"\
    --shell="$(CY_MODUS_SHELL_DIR_BWC)"\
    --scripts="$(CY_INTERNAL_BASELIB_PATH)/make/scripts"\
    --defs="$(CY_CORE_LD_DEFS)"\
    --patch="$(CY_CORE_PATCH_SYMBOLS)"\
    --ld="$(CY_CONFIG_DIR)/$(APPNAME).ld"\
    $(if $(findstring 1,$(DIRECT_LOAD)),--direct)\
    $(if $(VERBOSE),"--verbose")\
    && CY_CMD_TERM=
endif

#
# Postbuild step
#
ifeq ($(LIBNAME),)
CY_RECIPE_POSTBUILD?=\
    bash --norc --noprofile\
    "$(CY_INTERNAL_BASELIB_PATH)/make/scripts/bt_post_build.bash"\
    --shell="$(CY_MODUS_SHELL_DIR_BWC)"\
    --cross="$(CY_CROSSPATH)/arm-none-eabi-"\
    --scripts="$(CY_INTERNAL_BASELIB_PATH)/make/scripts"\
    --tools="$(CY_WICED_TOOLS_DIR)"\
    --builddir="$(CY_CONFIG_DIR)"\
    --elfname="$(APPNAME).elf"\
    --appname="$(APPNAME)"\
    --appver="$(APP_VERSION)"\
    --hdf="$(CY_CORE_HDF)"\
    --entry="$(CY_CORE_APP_ENTRY).entry"\
    --cgslist="$(CY_CORE_CGSLIST)"\
    --cgsargs="$(CY_CORE_CGS_ARGS)"\
    --btp="$(CY_CORE_BTP)"\
    --id="$(CY_CORE_HCI_ID)"\
    --overridebaudfile="$(CY_INTERNAL_BASELIB_PATH)/platforms/BAUDRATEFILE.txt"\
    --chip="$(CHIP)$(CHIP_REV)"\
    --target="$(TARGET)"\
    --minidriver="$(CY_CORE_MINIDRIVER)"\
    --ds2_app="$(CY_DS2_APP_HEX)"\
    --failsafe="$(CY_CORE_FAIL_SAFE_CGS)"\
    --clflags="$(CY_CORE_APP_CHIPLOAD_FLAGS)"\
    --extras=$(CY_APP_OTA)$(APP_STATIC_DATA)$(CY_CORE_APP_XIP_EXTRA)$(CY_CORE_DS2_EXTRA)$(CY_CORE_DIRECT_LOAD)\
    $(if $(VERBOSE),"--verbose")\
    && CY_CMD_TERM=
endif

#
# add dependency to ensure configurator sources generated before BSP projects are built
#
$(SEARCH_LIBS_AND_INCLUDES): gen_config

#
# add vscode informational message
#
ifeq ($(LIBNAME),)
ifeq ($(CY_SECONDSTAGE),)
vscode: vscode_bt_information
endif
endif

vscode_bt_information:
	@echo;\
	echo "VSCode for $(TARGET) hardware debugging:";\
	echo; \
	echo " - Edit makefile (or override with command line) to build for hardware debug";\
	echo "   by setting ENABLE_DEBUG=1.";\
	echo " - Rebuild application, program, attach debugger.";\
	echo " - Launch debugger with Run->Start debugging, or F5.";\
	echo "See document \"WICED Hardware Debugging for Bluetooth Kits\" for details.";\
	echo;

################################################################################
# Programmer tool
################################################################################
ifeq ($(KITPROG3_BRIDGE),1)
CY_PROGTOOL_FW_LOADER=$(CY_INTERNAL_TOOL_fw-loader_EXE)
progtool:
	$(CY_NOISE)echo;\
	echo ==============================================================================;\
	echo "Available commands";\
	echo ==============================================================================;\
	echo;\
	"$(CY_PROGTOOL_FW_LOADER)" --help | sed s/'	'/' '/g;\
	echo ==============================================================================;\
	echo "Connected device(s)";\
	echo ==============================================================================;\
	echo;\
	deviceList=$$("$(CY_PROGTOOL_FW_LOADER)" --device-list | grep "FW Version" | sed s/'	'/' '/g);\
	if [[ ! -n "$$deviceList" ]]; then\
		echo "ERROR: Could not find any connected devices";\
		echo;\
		exit 1;\
	else\
		echo "$$deviceList";\
		echo;\
	fi;\
	echo ==============================================================================;\
	echo "Input command";\
	echo ==============================================================================;\
	echo;\
	echo " Specify the command (and optionally the device name).";\
	echo " E.g. --mode kp3-daplink KitProg3 CMSIS-DAP HID-0123456789ABCDEF";\
	echo;\
	read -p " > " -a params;\
	echo;\
	echo ==============================================================================;\
	echo "Run command";\
	echo ==============================================================================;\
	echo;\
	paramsSize=$${#params[@]};\
	if [[ $$paramsSize > 2 ]]; then\
		if [[ $${params[1]} == "kp3-"* ]]; then\
			deviceName="$${params[@]:2:$$paramsSize}";\
			"$(CY_PROGTOOL_FW_LOADER)" $${params[0]} $${params[1]} "$$deviceName" | sed s/'	'/' '/g;\
		else\
			deviceName="$${params[@]:1:$$paramsSize}";\
			"$(CY_PROGTOOL_FW_LOADER)" $${params[0]} "$$deviceName" | sed s/'	'/' '/g;\
		fi;\
	else\
		"$(CY_PROGTOOL_FW_LOADER)" "$${params[@]}" | sed s/'	'/' '/g;\
	fi;

else
progtool:
	$(CY_NOISE)echo "This kit does not have a USB Serial device supported by Progtool."

endif
.PHONY: progtool
