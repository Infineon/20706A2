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
# List the supported toolchains
#
CY_SUPPORTED_TOOLCHAINS=GCC_ARM

ifeq ($(OS),Windows_NT)
    CY_OS_DIR=Windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CY_OS_DIR=Linux64
    endif
    ifeq ($(UNAME_S),Darwin)
        CY_OS_DIR=OSX
    endif
endif
CY_WICED_TOOLS_DIR=$(CY_WICED_TOOLS_ROOT)/$(CY_OS_DIR)


################################################################################
# Feature processing
################################################################################
# create a RAM download image *.hcd
DIRECT_LOAD?=0
ifeq ($(DIRECT_LOAD),1)
CY_CORE_DIRECT_LOAD=_DIRECT_
CY_CORE_CGS_ARGS+=-O DLConfigSSLocation:$(PLATFORM_DIRECT_LOAD_BASE_ADDR)
CY_CORE_CGS_ARGS+=-O DLMaxWriteSize:249
else
# Base address
CY_CORE_CGS_ARGS+=-A $(CY_FLASH0_BEGIN_ADDR)
endif

# BT Device address
ifneq ($(BT_DEVICE_ADDRESS),)
CY_CORE_CGS_ARGS+=-O DLConfigBD_ADDRBase:$(BT_DEVICE_ADDRESS)
endif

# HCI transport
CY_APP_DEFINES+=\
    -DWICED_HCI_TRANSPORT_UART=1 \
    -DWICED_HCI_TRANSPORT_SPI=2
ifeq ($(TRANSPORT),UART)
CY_APP_DEFINES+=-DWICED_HCI_TRANSPORT=1
else
CY_APP_DEFINES+=-DWICED_HCI_TRANSPORT=2
endif

# use btp file to determine flash layout
CY_CORE_LD_DEFS+=BTP=$(CY_CORE_BTP)

#
# Core flags and defines
#
CY_CORE_CFLAGS+=\
	$(CY_CORE_COMMON_OPTIONS)\
	-ffreestanding\
	-fshort-wchar

CY_CORE_SFLAGS=

CY_CORE_LDFLAGS=\
    -nodefaultlibs -nostdlib\
    $(CY_CORE_EXTRA_LD_FLAGS)

CY_CORE_DEFINES+=\
	-DCYW$(CHIP)$(CHIP_REV)=1 \
	-DBCM$(CHIP)$(CHIP_REV)=1 \
	-DBCM$(CHIP)=1 \
	-DCYW$(CHIP)=1 \
	-DCHIP=$(CHIP) \
	-DAPP_CHIP=$(CHIP) \
	-DOTA_CHIP=$(CHIP) \
	-DCHIP_REV_$(BLD)_$(CHIP)$(CHIP_REV)=1 \
	-DBCM20703 \
	-DBUILDCFG \
	-DCOMPILER_ARM \
	-DSPAR_APP_SETUP=application_setup \
	-D__TARGET_CPU_CORTEX_M3 \
	-D__ARMCC_VERSION=400677 \
	-DPLATFORM='"$(subst -,_,$(TARGET))"'

CY_CORE_EXTRA_DEFINES=\
	-DWICED_SDK_MAJOR_VER=2 \
	-DWICED_SDK_MINOR_VER=4 \
	-DWICED_SDK_REV_NUMBER=0 \
	-DWICED_SDK_BUILD_NUMBER=6698

#
# Set the output file paths
#
ifneq ($(CY_BUILD_LOCATION),)
CY_APP_ELF_FILE?=$(CY_INTERNAL_BUILD_LOCATION)/$(APPNAME)/$(TARGET)/$(CONFIG)/$(APPNAME).elf
else
CY_APP_ELF_FILE?=\$$\{cy_prj_path\}/$(notdir $(CY_INTERNAL_BUILD_LOC))/$(TARGET)/$(CONFIG)/$(APPNAME).elf
endif

#
# Tools specifics
#
# declare configurator support conditionally for all boards
ifneq ($(LIBNAME),BTSDK_TopLevel)
CY_SUPPORTED_TOOL_TYPES+=bt-configurator
endif

ifeq ($(CY_TARGET_DEVICE),20819A1)
CY_SUPPORTED_TOOL_TYPES+=cype-tool
endif
# hint for bt-configurator
CY_OPEN_bt_configurator_DEVICE=--device 20xxx

# application-specific tools
ifneq ($(CY_OS_DIR),Windows)
  CY_BT_APP_TOOLS_WINDOWS_ONLY=MeshClient WsOtaUpgrade WMBT hello_client
  CY_OPEN_TYPE_LIST+=$(filter-out $(CY_BT_APP_TOOLS_WINDOWS_ONLY),$(CY_BT_APP_TOOLS))
  CY_SUPPORTED_TOOL_TYPES+=$(filter-out $(CY_BT_APP_TOOLS_WINDOWS_ONLY),$(CY_BT_APP_TOOLS))
else
  CY_OPEN_TYPE_LIST+=$(CY_BT_APP_TOOLS)
  CY_SUPPORTED_TOOL_TYPES+=$(CY_BT_APP_TOOLS)
endif
CY_BT_APP_TOOLS_DIR=$(CY_SHARED_PATH)/tools
CY_BT_APP_TOOLS_DIR_ABS=$(CY_SHARED_PATH_ABS)/tools

ifneq ($(filter BTSpy,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
  CY_OPEN_BTSpy_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/BTSpy/$(CY_OS_DIR)/BTSpy.exe
else
  ifeq ($(CY_OS_DIR),Linux64)
    CY_OPEN_BTSpy_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/BTSpy/$(CY_OS_DIR)/RunBtSpy.sh
  else
    CY_OPEN_BTSpy_TOOL=open
    CY_OPEN_BTSpy_TOOL_ARGS=-a $(CY_BT_APP_TOOLS_DIR_ABS)/btsdk-utils/BTSpy/$(CY_OS_DIR)/bt_spy.app
  endif
endif
CY_OPEN_BTSpy_tool_EXT=
CY_OPEN_BTSpy_FILE=
CY_OPEN_BTSpy_TOOL_FLAGS=
CY_OPEN_BTSpy_TOOL_NEWCFG_FLAGS=
endif

ifneq ($(filter ClientControl,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
  CY_OPEN_ClientControl_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-host-apps-bt-ble/client_control/$(CY_OS_DIR)/ClientControl.exe
else
  ifeq ($(CY_OS_DIR),Linux64)
    CY_OPEN_ClientControl_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-host-apps-bt-ble/client_control/$(CY_OS_DIR)/RunClientControl.sh
  else
    CY_OPEN_ClientControl_TOOL=open
    CY_OPEN_ClientControl_TOOL_ARGS=-a $(CY_BT_APP_TOOLS_DIR_ABS)/btsdk-host-apps-bt-ble/client_control/$(CY_OS_DIR)/ClientControl.app
  endif
endif
endif

ifneq ($(filter MeshClient,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
CY_OPEN_MeshClient_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-peer-apps-mesh/$(CY_OS_DIR)/MeshClient/Release/x86/MeshClient.exe
endif
endif

ifneq ($(filter ClientControlMesh,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
  CY_OPEN_ClientControlMesh_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-host-apps-mesh/VS_ClientControl/Release/ClientControlMesh
else
  ifeq ($(CY_OS_DIR),Linux64)
    CY_OPEN_ClientControlMesh_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-host-apps-mesh/Qt_ClientControl/$(CY_OS_DIR)/RunClientControl.sh
  else
    CY_OPEN_ClientControlMesh_TOOL=open
    CY_OPEN_ClientControlMesh_TOOL_ARGS=-a $(CY_BT_APP_TOOLS_DIR_ABS)/btsdk-host-apps-mesh/Qt_ClientControl/$(CY_OS_DIR)/mesh_client.app
  endif
endif
endif

# need to add ota image file
ifneq ($(filter WsOtaUpgrade,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
CY_OPEN_WsOtaUpgrade_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-peer-apps-ota/$(CY_OS_DIR)/WsOtaUpgrade/Release/x64/WsOtaUpgrade.exe
CY_OPEN_WsOtaUpgrade_TOOL_ARGS=$(CY_CONFIG_DIR)/$(APPNAME)_$(TARGET).ota.bin
endif
endif

# need to sign ota image file ecdsa_genkey, ecdsa_sign, ecdsa_verify
ifneq ($(filter ecdsa_genkey,$(CY_BT_APP_TOOLS)),)
CY_OPEN_ecdsa_genkey_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/ecdsa256/bin/$(CY_OS_DIR)/ecdsa_genkey
endif
ifneq ($(filter ecdsa_sign,$(CY_BT_APP_TOOLS)),)
CY_OPEN_ecdsa_sign_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/ecdsa256/bin/$(CY_OS_DIR)/ecdsa_genkey
CY_OPEN_ecdsa_sign_TOOL_ARGS=$(CY_CONFIG_DIR)/$(APPNAME)_$(TARGET).ota.bin
endif
ifneq ($(filter ecdsa_verify,$(CY_BT_APP_TOOLS)),)
CY_OPEN_ecdsa_verify_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/ecdsa256/bin/$(CY_OS_DIR)/ecdsa_verify
CY_OPEN_ecdsa_verify_TOOL_ARGS=$(CY_CONFIG_DIR)/$(APPNAME)_$(TARGET).ota.bin
endif

# manufacturing test, display in file system
ifneq ($(filter WMBT,$(CY_BT_APP_TOOLS)),)
$(info $(subst /,\,$(CY_BT_APP_TOOLS_DIR)/btsdk-utils/wmbt))
CY_OPEN_WMBT_TOOL=explorer.exe
CY_OPEN_WMBT_TOOL_ARGS=/separate /e $(subst /,\,$(CY_INTERNAL_APPLOC)/tools/btsdk-utils/wmbt)
endif

# hello client peer app
ifneq ($(filter hello_client,$(CY_BT_APP_TOOLS)),)
ifeq ($(CY_OS_DIR),Windows)
CY_OPEN_hello_client_TOOL=$(CY_BT_APP_TOOLS_DIR)/btsdk-peer-apps-ble/hello_sensor/$(CY_OS_DIR)/HelloClient/Release/x64/HelloClient.exe
endif
endif

#
# vscode app launchers
#
define tool_launch_json
{\
 \"label\": \"Tool: $(1)\",\
 \"type\": \"process\",\
 \"command\": \"$(CY_OPEN_$(1)_TOOL)\",\
 \"args\": [$(foreach tool_arg,$(CY_OPEN_$(1)_TOOL_ARGS),\"$(tool_arg)\",)],\
 \"problemMatcher\": \"\$$gcc\",\
},
endef
CY_BT_APP_TOOLS_JSON=$(foreach tool,$(CY_BT_APP_TOOLS),$(call tool_launch_json,$(tool)))

#
# IDE specifics for program/debug
#
CY_OPENOCD_ARG =-s $(CY_INTERNAL_BASELIB_PATH)/platforms
CY_OPENOCD_ARG+=-f CYW$(CY_TARGET_DEVICE)_openocd.cfg

CY_JLINK_DEVICE_CFG=Cortex-M4
CY_OPENOCD_DEVICE_CFG=$(CY_INTERNAL_BASELIB_PATH)/platforms/CYW$(CY_TARGET_DEVICE)_openocd.cfg

CY_VSCODE_ARGS="s|&&RELEASETARGET&&|build/$(TARGET)/Release/$(APPNAME).elf|g;"\
                "s|&&DEBUGTARGET&&|build/$(TARGET)/Debug/$(APPNAME).elf|g;"\
                "s|&&MODUSSHELL&&|$(CY_MODUS_SHELL_DIR)|g;"\
                "s|&&TARGET&&|$(TARGET)|g;"\
                "s|&&OPENOCDSEARCH&&|$(CY_INTERNAL_BASELIB_PATH)/platforms|g;"\
                "s|&&OPENOCDFILE&&|$(CY_OPENOCD_DEVICE_CFG)|g;"\
                "s|&&MODUSTOOLCHAIN&&|$(subst ",,$(CY_COMPILER_DIR))|g;"\
                "s|&&MODUSTOOLCHAINVERSION&&|$(subst ",,$(subst gcc-,,$(notdir $(CY_COMPILER_DIR))))|g;"\
                "s|&&CFLAGS&&|$(CY_RECIPE_CFLAGS)|g;"\
                "s|&&MODUSOPENOCD&&|$(CY_OPENOCD_DIR)|g;"\
                "s|&&DEVICEATTACH&&|$(CY_JLINK_DEVICE_CFG)|g;"\
                "s|&&MODUSLIBMANAGER&&|$(CY_LIBRARY_MANAGER_DIR)|g;"\
                "s|&&GDBPATH&&|$(CY_COMPILER_DIR)|g;"\
                "s|&&CLIENTCONTROLMESH&&|$(CY_CLIENT_CONTROL_MESH)|g;"\
                "s|&&BTAPPTOOLS&&|$(CY_BT_APP_TOOLS_JSON)|g;"\

CY_ECLIPSE_ARGS="s|&&CY_OPENOCD_ARG&&|$(CY_OPENOCD_ARG)|;"\
                "s|&&CY_JLINK_DEVICE&&|$(CY_JLINK_DEVICE_CFG)|;"\
                "s|&&CY_APPNAME&&|$(CY_IDE_PRJNAME)|;"\
                "s|&&CY_PROG_FILE&&|$(CY_APP_ELF_FILE)|;"
