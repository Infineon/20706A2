/*------------------------------------------------------------------------------------------------------------------------------
// Autocreated by: param2adrmap.pl  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/gps/gpsu/ver/param  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/BT_MODEM_NEW/BTRF_control/ver/param  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/share/ver/param  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/bpl/ver/param  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/jtmode/ver/param  \
//  +incdir+/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/aud/ver/param  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/share/ver/param/asic_config.v  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/share/ver/param/adrmap.h  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/spiffy/ver/param/spiffy_offset_adrmap.h+spi_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/spiffy/ver/param/spiffy_offset_adrmap.h=spiffy2_+spiffy2_base \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/aburst/ver/param/aburst_adr_offset.h+aburst_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/pcm2/ver/param/pcm2_offset_adrmap.h+pcm2_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/usb/ver/param/hub_offset_adrmap.h=hub0_+hub_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/usb/ver/param/usb_offset_adrmap.h=usb0_+usb0_usb_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/usb/ver/param/usb_offset_adrmap.h=usb1_+usb1_usb_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/usb/ver/param/usb_offset_adrmap.h=usb2_+usb2_usb_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/lhl/ver/param/lhl_adrmap.h+lhl_adr_base  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/mia/ver/param/mia_adrmap.h+mia_adr_base  \
//  -replace=_offset\b:  \
//  /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/share/ver/param/shim_regs_paras.vh+SHIM_BASE='h00330000 -replace=_offset\b: /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0/btfm_core/share/ver/param/ubdc_regs_paras.vh+UBDC_BASE='h00330000 \
//  -replace=_offset\b: -overwrite -min_address=0x00300000 -waive=gps_ch1_MsTrigActual -waive=gps_ch2_MsTrigActual  \
//  -waive=gps_ch3_MsTrigActual -waive=gps_ch4_MsTrigActual -waive=gps_ch5_MsTrigActual -waive=gps_ch6_MsTrigActual  \
//  -waive=gps_ch7_MsTrigActual -waive=gps_ch8_MsTrigActual -waive=gps_ch9_MsTrigActual -waive=gps_ch10_MsTrigActual  \
//  -waive=gps_ch11_MsTrigActual -waive=gps_ch12_MsTrigActual  \
//  -outdir=/projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0_verification/btfm_core/bcm20703_btfm_top/ver/vtb/test/output
// By: janel
// In: /projects/BCM20703_A0/users/janel/7_26_FPGA13/bcm20703a0_verification/btfm_core/bcm20703_btfm_top/ver/vtb/test
//------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef REGISTER_H
  #define REGISTER_H

  #define base_code_adr                                  0x00000000
  #define base_code                                      (*(volatile unsigned int *)base_code_adr)
  #define base_sram_adr                                  0x20000000
  #define base_sram                                      (*(volatile unsigned int *)base_sram_adr)
  #define base_peripherals_adr                           0x40000000
  #define base_peripherals                               (*(volatile unsigned int *)base_peripherals_adr)
  #define base_extern_sram_adr                           0x60000000
  #define base_extern_sram                               (*(volatile unsigned int *)base_extern_sram_adr)
  #define base_extern_device_adr                         0xa0000000
  #define base_extern_device                             (*(volatile unsigned int *)base_extern_device_adr)
  #define base_ppb_adr                                   0xe0000000
  #define base_ppb                                       (*(volatile unsigned int *)base_ppb_adr)
  #define base_IntIRom_adr                               0x00000000
  #define base_IntIRom                                   (*(volatile unsigned int *)base_IntIRom_adr)
  #define last_IntIRom_adr                               0x000c7fff
  #define last_IntIRom                                   (*(volatile unsigned int *)last_IntIRom_adr)
  #define base_IntMemPrc_adr                             0x000d0000
  #define base_IntMemPrc                                 (*(volatile unsigned int *)base_IntMemPrc_adr)
  #define last_IntMemPrc_adr                             0x000dffff
  #define last_IntMemPrc                                 (*(volatile unsigned int *)last_IntMemPrc_adr)
  #define base_IntMemCm3_adr                             0x00200000
  #define base_IntMemCm3                                 (*(volatile unsigned int *)base_IntMemCm3_adr)
  #define last_IntMemCm3_adr                             0x00247fff
  #define last_IntMemCm3                                 (*(volatile unsigned int *)last_IntMemCm3_adr)
  #define base_IntDRom_adr                               0x00260000
  #define base_IntDRom                                   (*(volatile unsigned int *)base_IntDRom_adr)
  #define last_IntDRom_adr                               0x0026bfff
  #define last_IntDRom                                   (*(volatile unsigned int *)last_IntDRom_adr)
  #define base_hw_regs_cm3_adr                           0x00300000
  #define base_hw_regs_cm3                               (*(volatile unsigned int *)base_hw_regs_cm3_adr)
  #define last_hw_regs_cm3_adr                           0x00337fff
  #define last_hw_regs_cm3                               (*(volatile unsigned int *)last_hw_regs_cm3_adr)
  #define base_rtx_fifo_adr                              0x00370000
  #define base_rtx_fifo                                  (*(volatile unsigned int *)base_rtx_fifo_adr)
  #define base_rf_regs_adr                               0x00600000
  #define base_rf_regs                                   (*(volatile unsigned int *)base_rf_regs_adr)
  #define base_clb_regs_adr                              0x00640000
  #define base_clb_regs                                  (*(volatile unsigned int *)base_clb_regs_adr)
  #define gci_regs_adr_base                              0x00650000
  #define base_axi_wlan_adr                              0x00680000
  #define base_axi_wlan                                  (*(volatile unsigned int *)base_axi_wlan_adr)
  #define last_axi_wlan_adr                              0x007fffff
  #define last_axi_wlan                                  (*(volatile unsigned int *)last_axi_wlan_adr)
  #define base_usb3_regs_adr                             0x00330000
  #define base_usb3_regs                                 (*(volatile unsigned int *)base_usb3_regs_adr)
  #define last_usb3_regs_adr                             0x00333fff
  #define last_usb3_regs                                 (*(volatile unsigned int *)last_usb3_regs_adr)
  #define base_epm_ram_adr                               0x00400000
  #define base_epm_ram                                   (*(volatile unsigned int *)base_epm_ram_adr)
  #define last_epm_ram_adr                               0x004fffff
  #define last_epm_ram                                   (*(volatile unsigned int *)last_epm_ram_adr)
  #define base_epm_flash_adr                             0x00500000
  #define base_epm_flash                                 (*(volatile unsigned int *)base_epm_flash_adr)
  #define last_epm_flash_adr                             0x005fffff
  #define last_epm_flash                                 (*(volatile unsigned int *)last_epm_flash_adr)
  #define base_GpsMem_adr                                0x000e0000
  #define base_GpsMem                                    (*(volatile unsigned int *)base_GpsMem_adr)
  #define last_GpsMem_adr                                0x0013ffff
  #define last_GpsMem                                    (*(volatile unsigned int *)last_GpsMem_adr)
  #define base_WlanMem1_M0_adr                           0x00140000
  #define base_WlanMem1_M0                               (*(volatile unsigned int *)base_WlanMem1_M0_adr)
  #define last_WlanMem1_M0_adr                           0x001affff
  #define last_WlanMem1_M0                               (*(volatile unsigned int *)last_WlanMem1_M0_adr)
  #define base_WlanMem2_M0_adr                           0x001e0000
  #define base_WlanMem2_M0                               (*(volatile unsigned int *)base_WlanMem2_M0_adr)
  #define last_WlanMem2_M0_adr                           0x001fffff
  #define last_WlanMem2_M0                               (*(volatile unsigned int *)last_WlanMem2_M0_adr)
  #define base_WlanMem2_M1_adr                           0x00280000
  #define base_WlanMem2_M1                               (*(volatile unsigned int *)base_WlanMem2_M1_adr)
  #define last_WlanMem2_M1_adr                           0x0029ffff
  #define last_WlanMem2_M1                               (*(volatile unsigned int *)last_WlanMem2_M1_adr)
  #define base_power_WD_adr                              0x00390000
  #define base_power_WD                                  (*(volatile unsigned int *)base_power_WD_adr)
  #define last_power_WD_adr                              0x00397fff
  #define last_power_WD                                  (*(volatile unsigned int *)last_power_WD_adr)
  #define base_clb_regs_adr                              0x00640000
  #define base_clb_regs                                  (*(volatile unsigned int *)base_clb_regs_adr)
  #define clb_sr_cntl_0_adr                              0x00640000                                                   // base_clb_regs_adr + 0x00000004 * 0x00000000
  #define clb_sr_cntl_0                                  (*(volatile unsigned int *)clb_sr_cntl_0_adr)
  #define clb_sr_cntl_1_adr                              0x00640004                                                   // base_clb_regs_adr + 0x00000004 * 0x00000001
  #define clb_sr_cntl_1                                  (*(volatile unsigned int *)clb_sr_cntl_1_adr)
  #define clb_sr_cntl_2_adr                              0x00640008                                                   // base_clb_regs_adr + 0x00000004 * 0x00000002
  #define clb_sr_cntl_2                                  (*(volatile unsigned int *)clb_sr_cntl_2_adr)
  #define clb_sr_cntl_3_adr                              0x0064000c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000003
  #define clb_sr_cntl_3                                  (*(volatile unsigned int *)clb_sr_cntl_3_adr)
  #define clb_sr_cntl_4_adr                              0x00640010                                                   // base_clb_regs_adr + 0x00000004 * 0x00000004
  #define clb_sr_cntl_4                                  (*(volatile unsigned int *)clb_sr_cntl_4_adr)
  #define clb_sr_cntl_5_adr                              0x00640014                                                   // base_clb_regs_adr + 0x00000004 * 0x00000005
  #define clb_sr_cntl_5                                  (*(volatile unsigned int *)clb_sr_cntl_5_adr)
  #define clb_sr_cntl_6_adr                              0x00640018                                                   // base_clb_regs_adr + 0x00000004 * 0x00000006
  #define clb_sr_cntl_6                                  (*(volatile unsigned int *)clb_sr_cntl_6_adr)
  #define clb_sr_cntl_7_adr                              0x0064001c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000007
  #define clb_sr_cntl_7                                  (*(volatile unsigned int *)clb_sr_cntl_7_adr)
  #define clb_sr_cntl_8_adr                              0x00640020                                                   // base_clb_regs_adr + 0x00000004 * 0x00000008
  #define clb_sr_cntl_8                                  (*(volatile unsigned int *)clb_sr_cntl_8_adr)
  #define clb_sr_cntl_9_adr                              0x00640024                                                   // base_clb_regs_adr + 0x00000004 * 0x00000009
  #define clb_sr_cntl_9                                  (*(volatile unsigned int *)clb_sr_cntl_9_adr)
  #define clb_sr_cntl_a_adr                              0x00640028                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000a
  #define clb_sr_cntl_a                                  (*(volatile unsigned int *)clb_sr_cntl_a_adr)
  #define clb_sr_cntl_b_adr                              0x0064002c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000b
  #define clb_sr_cntl_b                                  (*(volatile unsigned int *)clb_sr_cntl_b_adr)
  #define clb_sr_cntl_c_adr                              0x00640030                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000c
  #define clb_sr_cntl_c                                  (*(volatile unsigned int *)clb_sr_cntl_c_adr)
  #define clb_sr_cntl_d_adr                              0x00640034                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000d
  #define clb_sr_cntl_d                                  (*(volatile unsigned int *)clb_sr_cntl_d_adr)
  #define clb_sr_cntl_e_adr                              0x00640038                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000e
  #define clb_sr_cntl_e                                  (*(volatile unsigned int *)clb_sr_cntl_e_adr)
  #define clb_sr_cntl_f_adr                              0x0064003c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000000f
  #define clb_sr_cntl_f                                  (*(volatile unsigned int *)clb_sr_cntl_f_adr)
  #define clb_sr_cntl_10_adr                             0x00640040                                                   // base_clb_regs_adr + 0x00000004 * 0x00000010
  #define clb_sr_cntl_10                                 (*(volatile unsigned int *)clb_sr_cntl_10_adr)
  #define clb_sr_cntl_11_adr                             0x00640044                                                   // base_clb_regs_adr + 0x00000004 * 0x00000011
  #define clb_sr_cntl_11                                 (*(volatile unsigned int *)clb_sr_cntl_11_adr)
  #define clb_sr_cntl_12_adr                             0x00640048                                                   // base_clb_regs_adr + 0x00000004 * 0x00000012
  #define clb_sr_cntl_12                                 (*(volatile unsigned int *)clb_sr_cntl_12_adr)
  #define clb_sr_cntl_13_adr                             0x0064004c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000013
  #define clb_sr_cntl_13                                 (*(volatile unsigned int *)clb_sr_cntl_13_adr)
  #define clb_extra_sw_ctl_adr                           0x00640050                                                   // base_clb_regs_adr + 0x00000004 * 0x00000014
  #define clb_extra_sw_ctl                               (*(volatile unsigned int *)clb_extra_sw_ctl_adr)
  #define clb_ldo_cntl_0_adr                             0x00640054                                                   // base_clb_regs_adr + 0x00000004 * 0x00000015
  #define clb_ldo_cntl_0                                 (*(volatile unsigned int *)clb_ldo_cntl_0_adr)
  #define clb_ldo_cntl_1_adr                             0x00640058                                                   // base_clb_regs_adr + 0x00000004 * 0x00000016
  #define clb_ldo_cntl_1                                 (*(volatile unsigned int *)clb_ldo_cntl_1_adr)
  #define clb_ldo_cntl_2_adr                             0x0064005c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000017
  #define clb_ldo_cntl_2                                 (*(volatile unsigned int *)clb_ldo_cntl_2_adr)
  #define clb_ldo_cntl_3_adr                             0x00640060                                                   // base_clb_regs_adr + 0x00000004 * 0x00000018
  #define clb_ldo_cntl_3                                 (*(volatile unsigned int *)clb_ldo_cntl_3_adr)
  #define clb_ldo_cntl_4_adr                             0x00640064                                                   // base_clb_regs_adr + 0x00000004 * 0x00000019
  #define clb_ldo_cntl_4                                 (*(volatile unsigned int *)clb_ldo_cntl_4_adr)
  #define clb_ldo_cntl_5_adr                             0x00640068                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001a
  #define clb_ldo_cntl_5                                 (*(volatile unsigned int *)clb_ldo_cntl_5_adr)
  #define clb_ldo_cntl_6_adr                             0x0064006c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001b
  #define clb_ldo_cntl_6                                 (*(volatile unsigned int *)clb_ldo_cntl_6_adr)
  #define clb_ldo_cntl_7_adr                             0x00640070                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001c
  #define clb_ldo_cntl_7                                 (*(volatile unsigned int *)clb_ldo_cntl_7_adr)
  #define clb_ldo_cntl_8_adr                             0x00640074                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001d
  #define clb_ldo_cntl_8                                 (*(volatile unsigned int *)clb_ldo_cntl_8_adr)
  #define clb_ldo_cntl_9_adr                             0x00640078                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001e
  #define clb_ldo_cntl_9                                 (*(volatile unsigned int *)clb_ldo_cntl_9_adr)
  #define clb_ldo_cntl_a_adr                             0x0064007c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000001f
  #define clb_ldo_cntl_a                                 (*(volatile unsigned int *)clb_ldo_cntl_a_adr)
  #define clb_ldo_cntl_b_adr                             0x00640080                                                   // base_clb_regs_adr + 0x00000004 * 0x00000020
  #define clb_ldo_cntl_b                                 (*(volatile unsigned int *)clb_ldo_cntl_b_adr)
  #define clb_bt2clb_PMU_pmu_ovride_adr                  0x00640084                                                   // base_clb_regs_adr + 0x00000004 * 0x00000021
  #define clb_bt2clb_PMU_pmu_ovride                      (*(volatile unsigned int *)clb_bt2clb_PMU_pmu_ovride_adr)
  #define clb_bt2clb_PMU_sr_cntl_en_adr                  0x00640088                                                   // base_clb_regs_adr + 0x00000004 * 0x00000022
  #define clb_bt2clb_PMU_sr_cntl_en                      (*(volatile unsigned int *)clb_bt2clb_PMU_sr_cntl_en_adr)
  #define clb_bt2clb_PMU_ldo_cntl_en_adr                 0x0064008c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000023
  #define clb_bt2clb_PMU_ldo_cntl_en                     (*(volatile unsigned int *)clb_bt2clb_PMU_ldo_cntl_en_adr)
  #define clb_slna_0_adr                                 0x00640090                                                   // base_clb_regs_adr + 0x00000004 * 0x00000024
  #define clb_slna_0                                     (*(volatile unsigned int *)clb_slna_0_adr)
  #define clb_slna_1_adr                                 0x00640094                                                   // base_clb_regs_adr + 0x00000004 * 0x00000025
  #define clb_slna_1                                     (*(volatile unsigned int *)clb_slna_1_adr)
  #define clb_slna_2_adr                                 0x00640098                                                   // base_clb_regs_adr + 0x00000004 * 0x00000026
  #define clb_slna_2                                     (*(volatile unsigned int *)clb_slna_2_adr)
  #define clb_slna_3_adr                                 0x0064009c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000027
  #define clb_slna_3                                     (*(volatile unsigned int *)clb_slna_3_adr)
  #define xo_en_adr                                      0x006400a0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000028
  #define xo_en                                          (*(volatile unsigned int *)xo_en_adr)
  #define clb_bt2clb_spare2_adr                          0x006400a4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000029
  #define clb_bt2clb_spare2                              (*(volatile unsigned int *)clb_bt2clb_spare2_adr)
  #define clb_sram_stby_0_adr                            0x006400a8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002a
  #define clb_sram_stby_0                                (*(volatile unsigned int *)clb_sram_stby_0_adr)
  #define clb_sram_stby_1_adr                            0x006400ac                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002b
  #define clb_sram_stby_1                                (*(volatile unsigned int *)clb_sram_stby_1_adr)
  #define clb_sram_stby_2_adr                            0x006400b0                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002c
  #define clb_sram_stby_2                                (*(volatile unsigned int *)clb_sram_stby_2_adr)
  #define clb_sram_stby_3_adr                            0x006400b4                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002d
  #define clb_sram_stby_3                                (*(volatile unsigned int *)clb_sram_stby_3_adr)
  #define clb_sram_sel_0_adr                             0x006400b8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002e
  #define clb_sram_sel_0                                 (*(volatile unsigned int *)clb_sram_sel_0_adr)
  #define clb_sram_sel_1_adr                             0x006400bc                                                   // base_clb_regs_adr + 0x00000004 * 0x0000002f
  #define clb_sram_sel_1                                 (*(volatile unsigned int *)clb_sram_sel_1_adr)
  #define clb_sram_sel_2_adr                             0x006400c0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000030
  #define clb_sram_sel_2                                 (*(volatile unsigned int *)clb_sram_sel_2_adr)
  #define clb_sram_sel_3_adr                             0x006400c4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000031
  #define clb_sram_sel_3                                 (*(volatile unsigned int *)clb_sram_sel_3_adr)
  #define clb_clk_ctl_0_adr                              0x006400c8                                                   // base_clb_regs_adr + 0x00000004 * 0x00000032
  #define clb_clk_ctl_0                                  (*(volatile unsigned int *)clb_clk_ctl_0_adr)
  #define clb_clk_ctl_1_adr                              0x006400cc                                                   // base_clb_regs_adr + 0x00000004 * 0x00000033
  #define clb_clk_ctl_1                                  (*(volatile unsigned int *)clb_clk_ctl_1_adr)
  #define clb_clk_ctl_2_adr                              0x006400d0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000034
  #define clb_clk_ctl_2                                  (*(volatile unsigned int *)clb_clk_ctl_2_adr)
  #define clb_clk_ctl_3_adr                              0x006400d4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000035
  #define clb_clk_ctl_3                                  (*(volatile unsigned int *)clb_clk_ctl_3_adr)
  #define clb_clk_ctl_4_adr                              0x006400d8                                                   // base_clb_regs_adr + 0x00000004 * 0x00000036
  #define clb_clk_ctl_4                                  (*(volatile unsigned int *)clb_clk_ctl_4_adr)
  #define clb_clk_ctl_5_adr                              0x006400dc                                                   // base_clb_regs_adr + 0x00000004 * 0x00000037
  #define clb_clk_ctl_5                                  (*(volatile unsigned int *)clb_clk_ctl_5_adr)
  #define clb_clk_ctl_6_adr                              0x006400e0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000038
  #define clb_clk_ctl_6                                  (*(volatile unsigned int *)clb_clk_ctl_6_adr)
  #define clb_clk_ctl_7_adr                              0x006400e4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000039
  #define clb_clk_ctl_7                                  (*(volatile unsigned int *)clb_clk_ctl_7_adr)
  #define clb_clk_ctl_8_adr                              0x006400e8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003a
  #define clb_clk_ctl_8                                  (*(volatile unsigned int *)clb_clk_ctl_8_adr)
  #define clb_clk_ctl_9_adr                              0x006400ec                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003b
  #define clb_clk_ctl_9                                  (*(volatile unsigned int *)clb_clk_ctl_9_adr)
  #define clb_clk_ctl_a_adr                              0x006400f0                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003c
  #define clb_clk_ctl_a                                  (*(volatile unsigned int *)clb_clk_ctl_a_adr)
  #define clb_extlpo_ctl_adr                             0x006400f4                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003d
  #define clb_extlpo_ctl                                 (*(volatile unsigned int *)clb_extlpo_ctl_adr)
  #define clb_rcal_ctl_adr                               0x006400f8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003e
  #define clb_rcal_ctl                                   (*(volatile unsigned int *)clb_rcal_ctl_adr)
  #define clb_rfsw_ctl_0_adr                             0x006400fc                                                   // base_clb_regs_adr + 0x00000004 * 0x0000003f
  #define clb_rfsw_ctl_0                                 (*(volatile unsigned int *)clb_rfsw_ctl_0_adr)
  #define clb_rfsw_ctl_1_adr                             0x00640100                                                   // base_clb_regs_adr + 0x00000004 * 0x00000040
  #define clb_rfsw_ctl_1                                 (*(volatile unsigned int *)clb_rfsw_ctl_1_adr)
  #define clb_rfsw_ctl_2_adr                             0x00640104                                                   // base_clb_regs_adr + 0x00000004 * 0x00000041
  #define clb_rfsw_ctl_2                                 (*(volatile unsigned int *)clb_rfsw_ctl_2_adr)
  #define clb_rfsw_ctl_3_adr                             0x00640108                                                   // base_clb_regs_adr + 0x00000004 * 0x00000042
  #define clb_rfsw_ctl_3                                 (*(volatile unsigned int *)clb_rfsw_ctl_3_adr)
  #define clb_rfsw_ctl_4_adr                             0x0064010c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000043
  #define clb_rfsw_ctl_4                                 (*(volatile unsigned int *)clb_rfsw_ctl_4_adr)
  #define clb_rfsw_ctl_5_adr                             0x00640110                                                   // base_clb_regs_adr + 0x00000004 * 0x00000044
  #define clb_rfsw_ctl_5                                 (*(volatile unsigned int *)clb_rfsw_ctl_5_adr)
  #define clb_rfsw_ctl_6_adr                             0x00640114                                                   // base_clb_regs_adr + 0x00000004 * 0x00000045
  #define clb_rfsw_ctl_6                                 (*(volatile unsigned int *)clb_rfsw_ctl_6_adr)
  #define clb_rfsw_ctl_7_adr                             0x00640118                                                   // base_clb_regs_adr + 0x00000004 * 0x00000046
  #define clb_rfsw_ctl_7                                 (*(volatile unsigned int *)clb_rfsw_ctl_7_adr)
  #define clb_rfsw_ctl_8_adr                             0x0064011c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000047
  #define clb_rfsw_ctl_8                                 (*(volatile unsigned int *)clb_rfsw_ctl_8_adr)
  #define clb_pwr_sw_ctl_0_adr                           0x00640120                                                   // base_clb_regs_adr + 0x00000004 * 0x00000048
  #define clb_pwr_sw_ctl_0                               (*(volatile unsigned int *)clb_pwr_sw_ctl_0_adr)
  #define clb_pwr_sw_ctl_1_adr                           0x00640124                                                   // base_clb_regs_adr + 0x00000004 * 0x00000049
  #define clb_pwr_sw_ctl_1                               (*(volatile unsigned int *)clb_pwr_sw_ctl_1_adr)
  #define clb_pwr_sw_ctl_2_adr                           0x00640128                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004a
  #define clb_pwr_sw_ctl_2                               (*(volatile unsigned int *)clb_pwr_sw_ctl_2_adr)
  #define clb_sh_bg_ctl_0_adr                            0x0064012c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004b
  #define clb_sh_bg_ctl_0                                (*(volatile unsigned int *)clb_sh_bg_ctl_0_adr)
  #define clb_sh_bg_ctl_1_adr                            0x00640130                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004c
  #define clb_sh_bg_ctl_1                                (*(volatile unsigned int *)clb_sh_bg_ctl_1_adr)
  #define clb_sh_bg_ctl_2_adr                            0x00640134                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004d
  #define clb_sh_bg_ctl_2                                (*(volatile unsigned int *)clb_sh_bg_ctl_2_adr)
  #define clb_sh_bg_ctl_3_adr                            0x00640138                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004e
  #define clb_sh_bg_ctl_3                                (*(volatile unsigned int *)clb_sh_bg_ctl_3_adr)
  #define clb_sh_bg_ctl_4_adr                            0x0064013c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000004f
  #define clb_sh_bg_ctl_4                                (*(volatile unsigned int *)clb_sh_bg_ctl_4_adr)
  #define clb_sh_bg_ctl_5_adr                            0x00640140                                                   // base_clb_regs_adr + 0x00000004 * 0x00000050
  #define clb_sh_bg_ctl_5                                (*(volatile unsigned int *)clb_sh_bg_ctl_5_adr)
  #define clb_ext_lpo_adr                                0x00640144                                                   // base_clb_regs_adr + 0x00000004 * 0x00000051
  #define clb_ext_lpo                                    (*(volatile unsigned int *)clb_ext_lpo_adr)
  #define clb_vreg2p5_ctrl_adr                           0x00640148                                                   // base_clb_regs_adr + 0x00000004 * 0x00000052
  #define clb_vreg2p5_ctrl                               (*(volatile unsigned int *)clb_vreg2p5_ctrl_adr)
  #define clb_mini_pmu_0_adr                             0x0064014c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000053
  #define clb_mini_pmu_0                                 (*(volatile unsigned int *)clb_mini_pmu_0_adr)
  #define clb_mini_pmu_1_adr                             0x00640150                                                   // base_clb_regs_adr + 0x00000004 * 0x00000054
  #define clb_mini_pmu_1                                 (*(volatile unsigned int *)clb_mini_pmu_1_adr)
  #define clb_mini_pmu_2_adr                             0x00640154                                                   // base_clb_regs_adr + 0x00000004 * 0x00000055
  #define clb_mini_pmu_2                                 (*(volatile unsigned int *)clb_mini_pmu_2_adr)
  #define clb_mini_pmu_3_adr                             0x00640158                                                   // base_clb_regs_adr + 0x00000004 * 0x00000056
  #define clb_mini_pmu_3                                 (*(volatile unsigned int *)clb_mini_pmu_3_adr)
  #define clb_BT2WLAN_pwrup_adr                          0x0064015c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000057
  #define clb_BT2WLAN_pwrup                              (*(volatile unsigned int *)clb_BT2WLAN_pwrup_adr)
  #define clb_WLAN_SRAM_adr                              0x00640160                                                   // base_clb_regs_adr + 0x00000004 * 0x00000058
  #define clb_WLAN_SRAM                                  (*(volatile unsigned int *)clb_WLAN_SRAM_adr)
  #define clb_pds_spare_adr                              0x00640164                                                   // base_clb_regs_adr + 0x00000004 * 0x00000059
  #define clb_pds_spare                                  (*(volatile unsigned int *)clb_pds_spare_adr)
  #define clb_ovd_rf_0_adr                               0x00640168                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005a
  #define clb_ovd_rf_0                                   (*(volatile unsigned int *)clb_ovd_rf_0_adr)
  #define clb_ovd_rf_1_adr                               0x0064016c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005b
  #define clb_ovd_rf_1                                   (*(volatile unsigned int *)clb_ovd_rf_1_adr)
  #define clb_ovd_rf_2_adr                               0x00640170                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005c
  #define clb_ovd_rf_2                                   (*(volatile unsigned int *)clb_ovd_rf_2_adr)
  #define clb_ovd_rf_3_adr                               0x00640174                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005d
  #define clb_ovd_rf_3                                   (*(volatile unsigned int *)clb_ovd_rf_3_adr)
  #define clb_ovd_rf_4_adr                               0x00640178                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005e
  #define clb_ovd_rf_4                                   (*(volatile unsigned int *)clb_ovd_rf_4_adr)
  #define clb_ovd_rf_5_adr                               0x0064017c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000005f
  #define clb_ovd_rf_5                                   (*(volatile unsigned int *)clb_ovd_rf_5_adr)
  #define clb_ovd_rf_6_adr                               0x00640180                                                   // base_clb_regs_adr + 0x00000004 * 0x00000060
  #define clb_ovd_rf_6                                   (*(volatile unsigned int *)clb_ovd_rf_6_adr)
  #define clb_ovd_rf_7_adr                               0x00640184                                                   // base_clb_regs_adr + 0x00000004 * 0x00000061
  #define clb_ovd_rf_7                                   (*(volatile unsigned int *)clb_ovd_rf_7_adr)
  #define clb_ovd_rf_8_adr                               0x00640188                                                   // base_clb_regs_adr + 0x00000004 * 0x00000062
  #define clb_ovd_rf_8                                   (*(volatile unsigned int *)clb_ovd_rf_8_adr)
  #define clb_ovd_rf_9_adr                               0x0064018c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000063
  #define clb_ovd_rf_9                                   (*(volatile unsigned int *)clb_ovd_rf_9_adr)
  #define clb_ovd_io_0_adr                               0x00640190                                                   // base_clb_regs_adr + 0x00000004 * 0x00000064
  #define clb_ovd_io_0                                   (*(volatile unsigned int *)clb_ovd_io_0_adr)
  #define clb_ovd_misc_0_adr                             0x00640194                                                   // base_clb_regs_adr + 0x00000004 * 0x00000065
  #define clb_ovd_misc_0                                 (*(volatile unsigned int *)clb_ovd_misc_0_adr)
  #define clb_ovd_misc_1_adr                             0x00640198                                                   // base_clb_regs_adr + 0x00000004 * 0x00000066
  #define clb_ovd_misc_1                                 (*(volatile unsigned int *)clb_ovd_misc_1_adr)
  #define clb_clk_ctl_b_adr                              0x0064019c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000067
  #define clb_clk_ctl_b                                  (*(volatile unsigned int *)clb_clk_ctl_b_adr)
  #define clb_clk_ctl_c_adr                              0x006401a0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000068
  #define clb_clk_ctl_c                                  (*(volatile unsigned int *)clb_clk_ctl_c_adr)
  #define clb_clk_ctl_d_adr                              0x006401a4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000069
  #define clb_clk_ctl_d                                  (*(volatile unsigned int *)clb_clk_ctl_d_adr)
  #define clb_clk_ctl_e_adr                              0x006401a8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006a
  #define clb_clk_ctl_e                                  (*(volatile unsigned int *)clb_clk_ctl_e_adr)
  #define clb_clk_ctl_f_adr                              0x006401ac                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006b
  #define clb_clk_ctl_f                                  (*(volatile unsigned int *)clb_clk_ctl_f_adr)
  #define clb_clk_ctl_10_adr                             0x006401b0                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006c
  #define clb_clk_ctl_10                                 (*(volatile unsigned int *)clb_clk_ctl_10_adr)
  #define clb_clk_ctl_11_adr                             0x006401b4                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006d
  #define clb_clk_ctl_11                                 (*(volatile unsigned int *)clb_clk_ctl_11_adr)
  #define clb_clk_ctl_12_adr                             0x006401b8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006e
  #define clb_clk_ctl_12                                 (*(volatile unsigned int *)clb_clk_ctl_12_adr)
  #define clb_clk_ctl_13_adr                             0x006401bc                                                   // base_clb_regs_adr + 0x00000004 * 0x0000006f
  #define clb_clk_ctl_13                                 (*(volatile unsigned int *)clb_clk_ctl_13_adr)
  #define clb_clk_ctl_14_adr                             0x006401c0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000070
  #define clb_clk_ctl_14                                 (*(volatile unsigned int *)clb_clk_ctl_14_adr)
  #define clb_clk_ctl_15_adr                             0x006401c4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000071
  #define clb_clk_ctl_15                                 (*(volatile unsigned int *)clb_clk_ctl_15_adr)
  #define clb_clk_ctl_16_adr                             0x006401c8                                                   // base_clb_regs_adr + 0x00000004 * 0x00000072
  #define clb_clk_ctl_16                                 (*(volatile unsigned int *)clb_clk_ctl_16_adr)
  #define clb_clk_ctl_17_adr                             0x006401cc                                                   // base_clb_regs_adr + 0x00000004 * 0x00000073
  #define clb_clk_ctl_17                                 (*(volatile unsigned int *)clb_clk_ctl_17_adr)
  #define clb_clk_ctl_18_adr                             0x006401d0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000074
  #define clb_clk_ctl_18                                 (*(volatile unsigned int *)clb_clk_ctl_18_adr)
  #define clb_sh_bg_ctl_6_adr                            0x006401d4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000075
  #define clb_sh_bg_ctl_6                                (*(volatile unsigned int *)clb_sh_bg_ctl_6_adr)
  #define clb_sh_bg_ctl_7_adr                            0x006401d8                                                   // base_clb_regs_adr + 0x00000004 * 0x00000076
  #define clb_sh_bg_ctl_7                                (*(volatile unsigned int *)clb_sh_bg_ctl_7_adr)
  #define clb_slna_4_adr                                 0x006401dc                                                   // base_clb_regs_adr + 0x00000004 * 0x00000077
  #define clb_slna_4                                     (*(volatile unsigned int *)clb_slna_4_adr)
  #define clb_otp_intlpo_ctl_adr                         0x006401e0                                                   // base_clb_regs_adr + 0x00000004 * 0x00000078
  #define clb_otp_intlpo_ctl                             (*(volatile unsigned int *)clb_otp_intlpo_ctl_adr)
  #define clb_mini_pmu_4_adr                             0x006401e4                                                   // base_clb_regs_adr + 0x00000004 * 0x00000079
  #define clb_mini_pmu_4                                 (*(volatile unsigned int *)clb_mini_pmu_4_adr)
  #define clb_mini_pmu_5_adr                             0x006401e8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007a
  #define clb_mini_pmu_5                                 (*(volatile unsigned int *)clb_mini_pmu_5_adr)
  #define clb_mini_pmu_6_adr                             0x006401ec                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007b
  #define clb_mini_pmu_6                                 (*(volatile unsigned int *)clb_mini_pmu_6_adr)
  #define clb_mini_pmu_7_adr                             0x006401f0                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007c
  #define clb_mini_pmu_7                                 (*(volatile unsigned int *)clb_mini_pmu_7_adr)
  #define clb_mini_pmu_8_adr                             0x006401f4                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007d
  #define clb_mini_pmu_8                                 (*(volatile unsigned int *)clb_mini_pmu_8_adr)
  #define clb_mini_pmu_9_adr                             0x006401f8                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007e
  #define clb_mini_pmu_9                                 (*(volatile unsigned int *)clb_mini_pmu_9_adr)
  #define clb_usb3_ctrl1_adr                             0x006401fc                                                   // base_clb_regs_adr + 0x00000004 * 0x0000007f
  #define clb_usb3_ctrl1                                 (*(volatile unsigned int *)clb_usb3_ctrl1_adr)
  #define clb_read_rf_0_adr                              0x00640200                                                   // base_clb_regs_adr + 0x00000004 * 0x00000080
  #define clb_read_rf_0                                  (*(volatile unsigned int *)clb_read_rf_0_adr)
  #define clb_read_rf_1_adr                              0x00640204                                                   // base_clb_regs_adr + 0x00000004 * 0x00000081
  #define clb_read_rf_1                                  (*(volatile unsigned int *)clb_read_rf_1_adr)
  #define clb_read_rf_2_adr                              0x00640208                                                   // base_clb_regs_adr + 0x00000004 * 0x00000082
  #define clb_read_rf_2                                  (*(volatile unsigned int *)clb_read_rf_2_adr)
  #define clb_read_rf_3_adr                              0x0064020c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000083
  #define clb_read_rf_3                                  (*(volatile unsigned int *)clb_read_rf_3_adr)
  #define clb_read_rf_4_adr                              0x00640210                                                   // base_clb_regs_adr + 0x00000004 * 0x00000084
  #define clb_read_rf_4                                  (*(volatile unsigned int *)clb_read_rf_4_adr)
  #define clb_read_rf_5_adr                              0x00640214                                                   // base_clb_regs_adr + 0x00000004 * 0x00000085
  #define clb_read_rf_5                                  (*(volatile unsigned int *)clb_read_rf_5_adr)
  #define clb_read_rf_6_adr                              0x00640218                                                   // base_clb_regs_adr + 0x00000004 * 0x00000086
  #define clb_read_rf_6                                  (*(volatile unsigned int *)clb_read_rf_6_adr)
  #define clb_read_rf_7_adr                              0x0064021c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000087
  #define clb_read_rf_7                                  (*(volatile unsigned int *)clb_read_rf_7_adr)
  #define clb_read_rf_8_adr                              0x00640220                                                   // base_clb_regs_adr + 0x00000004 * 0x00000088
  #define clb_read_rf_8                                  (*(volatile unsigned int *)clb_read_rf_8_adr)
  #define clb_read_rf_9_adr                              0x00640224                                                   // base_clb_regs_adr + 0x00000004 * 0x00000089
  #define clb_read_rf_9                                  (*(volatile unsigned int *)clb_read_rf_9_adr)
  #define clb_read_rf_a_adr                              0x00640228                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008a
  #define clb_read_rf_a                                  (*(volatile unsigned int *)clb_read_rf_a_adr)
  #define clb_read_rf_b_adr                              0x0064022c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008b
  #define clb_read_rf_b                                  (*(volatile unsigned int *)clb_read_rf_b_adr)
  #define clb_read_rf_c_adr                              0x00640230                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008c
  #define clb_read_rf_c                                  (*(volatile unsigned int *)clb_read_rf_c_adr)
  #define clb_read_rf_d_adr                              0x00640234                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008d
  #define clb_read_rf_d                                  (*(volatile unsigned int *)clb_read_rf_d_adr)
  #define clb_read_rf_e_adr                              0x00640238                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008e
  #define clb_read_rf_e                                  (*(volatile unsigned int *)clb_read_rf_e_adr)
  #define clb_read_rf_f_adr                              0x0064023c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000008f
  #define clb_read_rf_f                                  (*(volatile unsigned int *)clb_read_rf_f_adr)
  #define clb_read_rf_10_adr                             0x00640240                                                   // base_clb_regs_adr + 0x00000004 * 0x00000090
  #define clb_read_rf_10                                 (*(volatile unsigned int *)clb_read_rf_10_adr)
  #define clb_read_rf_11_adr                             0x00640244                                                   // base_clb_regs_adr + 0x00000004 * 0x00000091
  #define clb_read_rf_11                                 (*(volatile unsigned int *)clb_read_rf_11_adr)
  #define clb_read_rf_12_adr                             0x00640248                                                   // base_clb_regs_adr + 0x00000004 * 0x00000092
  #define clb_read_rf_12                                 (*(volatile unsigned int *)clb_read_rf_12_adr)
  #define clb_read_pmu_0_adr                             0x0064024c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000093
  #define clb_read_pmu_0                                 (*(volatile unsigned int *)clb_read_pmu_0_adr)
  #define clb_read_io_0_adr                              0x00640250                                                   // base_clb_regs_adr + 0x00000004 * 0x00000094
  #define clb_read_io_0                                  (*(volatile unsigned int *)clb_read_io_0_adr)
  #define clb_read_io_1_adr                              0x00640254                                                   // base_clb_regs_adr + 0x00000004 * 0x00000095
  #define clb_read_io_1                                  (*(volatile unsigned int *)clb_read_io_1_adr)
  #define clb_read_io_2_adr                              0x00640258                                                   // base_clb_regs_adr + 0x00000004 * 0x00000096
  #define clb_read_io_2                                  (*(volatile unsigned int *)clb_read_io_2_adr)
  #define clb_read_misc_0_adr                            0x0064025c                                                   // base_clb_regs_adr + 0x00000004 * 0x00000097
  #define clb_read_misc_0                                (*(volatile unsigned int *)clb_read_misc_0_adr)
  #define clb_read_misc_1_adr                            0x00640260                                                   // base_clb_regs_adr + 0x00000004 * 0x00000098
  #define clb_read_misc_1                                (*(volatile unsigned int *)clb_read_misc_1_adr)
  #define clb_read_misc_2_adr                            0x00640264                                                   // base_clb_regs_adr + 0x00000004 * 0x00000099
  #define clb_read_misc_2                                (*(volatile unsigned int *)clb_read_misc_2_adr)
  #define clb_read_misc_3_adr                            0x00640268                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009a
  #define clb_read_misc_3                                (*(volatile unsigned int *)clb_read_misc_3_adr)
  #define clb_sr_cntl_0_clb_adr                          0x0064026c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009b
  #define clb_sr_cntl_0_clb                              (*(volatile unsigned int *)clb_sr_cntl_0_clb_adr)
  #define clb_sr_cntl_1_clb_adr                          0x00640270                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009c
  #define clb_sr_cntl_1_clb                              (*(volatile unsigned int *)clb_sr_cntl_1_clb_adr)
  #define clb_sr_cntl_2_clb_adr                          0x00640274                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009d
  #define clb_sr_cntl_2_clb                              (*(volatile unsigned int *)clb_sr_cntl_2_clb_adr)
  #define clb_sr_cntl_3_clb_adr                          0x00640278                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009e
  #define clb_sr_cntl_3_clb                              (*(volatile unsigned int *)clb_sr_cntl_3_clb_adr)
  #define clb_sr_cntl_4_clb_adr                          0x0064027c                                                   // base_clb_regs_adr + 0x00000004 * 0x0000009f
  #define clb_sr_cntl_4_clb                              (*(volatile unsigned int *)clb_sr_cntl_4_clb_adr)
  #define clb_sr_cntl_5_clb_adr                          0x00640280                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a0
  #define clb_sr_cntl_5_clb                              (*(volatile unsigned int *)clb_sr_cntl_5_clb_adr)
  #define clb_sr_cntl_6_clb_adr                          0x00640284                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a1
  #define clb_sr_cntl_6_clb                              (*(volatile unsigned int *)clb_sr_cntl_6_clb_adr)
  #define clb_sr_cntl_7_clb_adr                          0x00640288                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a2
  #define clb_sr_cntl_7_clb                              (*(volatile unsigned int *)clb_sr_cntl_7_clb_adr)
  #define clb_sr_cntl_8_clb_adr                          0x0064028c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a3
  #define clb_sr_cntl_8_clb                              (*(volatile unsigned int *)clb_sr_cntl_8_clb_adr)
  #define clb_sr_cntl_9_clb_adr                          0x00640290                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a4
  #define clb_sr_cntl_9_clb                              (*(volatile unsigned int *)clb_sr_cntl_9_clb_adr)
  #define clb_sr_cntl_a_clb_adr                          0x00640294                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a5
  #define clb_sr_cntl_a_clb                              (*(volatile unsigned int *)clb_sr_cntl_a_clb_adr)
  #define clb_sr_cntl_b_clb_adr                          0x00640298                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a6
  #define clb_sr_cntl_b_clb                              (*(volatile unsigned int *)clb_sr_cntl_b_clb_adr)
  #define clb_sr_cntl_c_clb_adr                          0x0064029c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a7
  #define clb_sr_cntl_c_clb                              (*(volatile unsigned int *)clb_sr_cntl_c_clb_adr)
  #define clb_sr_cntl_d_clb_adr                          0x006402a0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a8
  #define clb_sr_cntl_d_clb                              (*(volatile unsigned int *)clb_sr_cntl_d_clb_adr)
  #define clb_sr_cntl_e_clb_adr                          0x006402a4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000a9
  #define clb_sr_cntl_e_clb                              (*(volatile unsigned int *)clb_sr_cntl_e_clb_adr)
  #define clb_sr_cntl_f_clb_adr                          0x006402a8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000aa
  #define clb_sr_cntl_f_clb                              (*(volatile unsigned int *)clb_sr_cntl_f_clb_adr)
  #define clb_sr_cntl_10_clb_adr                         0x006402ac                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ab
  #define clb_sr_cntl_10_clb                             (*(volatile unsigned int *)clb_sr_cntl_10_clb_adr)
  #define clb_ldo_cntl_0_clb_adr                         0x006402b0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ac
  #define clb_ldo_cntl_0_clb                             (*(volatile unsigned int *)clb_ldo_cntl_0_clb_adr)
  #define clb_ldo_cntl_1_clb_adr                         0x006402b4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ad
  #define clb_ldo_cntl_1_clb                             (*(volatile unsigned int *)clb_ldo_cntl_1_clb_adr)
  #define clb_ldo_cntl_2_clb_adr                         0x006402b8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ae
  #define clb_ldo_cntl_2_clb                             (*(volatile unsigned int *)clb_ldo_cntl_2_clb_adr)
  #define clb_ldo_cntl_3_clb_adr                         0x006402bc                                                   // base_clb_regs_adr + 0x00000004 * 0x000000af
  #define clb_ldo_cntl_3_clb                             (*(volatile unsigned int *)clb_ldo_cntl_3_clb_adr)
  #define clb_ldo_cntl_4_clb_adr                         0x006402c0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b0
  #define clb_ldo_cntl_4_clb                             (*(volatile unsigned int *)clb_ldo_cntl_4_clb_adr)
  #define clb_ldo_cntl_5_clb_adr                         0x006402c4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b1
  #define clb_ldo_cntl_5_clb                             (*(volatile unsigned int *)clb_ldo_cntl_5_clb_adr)
  #define clb_ldo_cntl_6_clb_adr                         0x006402c8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b2
  #define clb_ldo_cntl_6_clb                             (*(volatile unsigned int *)clb_ldo_cntl_6_clb_adr)
  #define clb_ldo_cntl_7_clb_adr                         0x006402cc                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b3
  #define clb_ldo_cntl_7_clb                             (*(volatile unsigned int *)clb_ldo_cntl_7_clb_adr)
  #define clb_ldo_cntl_8_clb_adr                         0x006402d0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b4
  #define clb_ldo_cntl_8_clb                             (*(volatile unsigned int *)clb_ldo_cntl_8_clb_adr)
  #define clb_ldo_cntl_9_clb_adr                         0x006402d4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b5
  #define clb_ldo_cntl_9_clb                             (*(volatile unsigned int *)clb_ldo_cntl_9_clb_adr)
  #define clb_ldo_cntl_a_clb_adr                         0x006402d8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b6
  #define clb_ldo_cntl_a_clb                             (*(volatile unsigned int *)clb_ldo_cntl_a_clb_adr)
  #define clb_clb2bt_PMU_pmu_ovride_adr                  0x006402dc                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b7
  #define clb_clb2bt_PMU_pmu_ovride                      (*(volatile unsigned int *)clb_clb2bt_PMU_pmu_ovride_adr)
  #define clb_clb2bt_PMU_latch_valid_adr                 0x006402e0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b8
  #define clb_clb2bt_PMU_latch_valid                     (*(volatile unsigned int *)clb_clb2bt_PMU_latch_valid_adr)
  #define clb_clb2bt_PMU_sr_cntl_en_adr                  0x006402e4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000b9
  #define clb_clb2bt_PMU_sr_cntl_en                      (*(volatile unsigned int *)clb_clb2bt_PMU_sr_cntl_en_adr)
  #define clb_clb2bt_PMU_ldo_cntl_en_adr                 0x006402e8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ba
  #define clb_clb2bt_PMU_ldo_cntl_en                     (*(volatile unsigned int *)clb_clb2bt_PMU_ldo_cntl_en_adr)
  #define clb_clb2bt_PMU_status_adr                      0x006402ec                                                   // base_clb_regs_adr + 0x00000004 * 0x000000bb
  #define clb_clb2bt_PMU_status                          (*(volatile unsigned int *)clb_clb2bt_PMU_status_adr)
  #define clb_rf_read_0_adr                              0x006402f0                                                   // base_clb_regs_adr + 0x00000004 * 0x000000bc
  #define clb_rf_read_0                                  (*(volatile unsigned int *)clb_rf_read_0_adr)
  #define clb_mini_pmu_read_0_adr                        0x006402f4                                                   // base_clb_regs_adr + 0x00000004 * 0x000000bd
  #define clb_mini_pmu_read_0                            (*(volatile unsigned int *)clb_mini_pmu_read_0_adr)
  #define clb_mini_pmu_read_1_adr                        0x006402f8                                                   // base_clb_regs_adr + 0x00000004 * 0x000000be
  #define clb_mini_pmu_read_1                            (*(volatile unsigned int *)clb_mini_pmu_read_1_adr)
  #define clb_mini_pmu_read_2_adr                        0x006402fc                                                   // base_clb_regs_adr + 0x00000004 * 0x000000bf
  #define clb_mini_pmu_read_2                            (*(volatile unsigned int *)clb_mini_pmu_read_2_adr)
  #define clb_mini_pmu_read_3_adr                        0x00640300                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c0
  #define clb_mini_pmu_read_3                            (*(volatile unsigned int *)clb_mini_pmu_read_3_adr)
  #define clb_mini_pmu_read_4_adr                        0x00640304                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c1
  #define clb_mini_pmu_read_4                            (*(volatile unsigned int *)clb_mini_pmu_read_4_adr)
  #define clb_sh_bg_ctl_0_read_adr                       0x00640308                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c2
  #define clb_sh_bg_ctl_0_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_0_read_adr)
  #define clb_sh_bg_ctl_1_read_adr                       0x0064030c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c3
  #define clb_sh_bg_ctl_1_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_1_read_adr)
  #define clb_sh_bg_ctl_2_read_adr                       0x00640310                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c4
  #define clb_sh_bg_ctl_2_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_2_read_adr)
  #define clb_sh_bg_ctl_3_read_adr                       0x00640314                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c5
  #define clb_sh_bg_ctl_3_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_3_read_adr)
  #define clb_sh_bg_ctl_4_read_adr                       0x00640318                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c6
  #define clb_sh_bg_ctl_4_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_4_read_adr)
  #define clb_sh_bg_ctl_5_read_adr                       0x0064031c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c7
  #define clb_sh_bg_ctl_5_read                           (*(volatile unsigned int *)clb_sh_bg_ctl_5_read_adr)
  #define clb_vreg2p5_ctrl_read_adr                      0x00640320                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c8
  #define clb_vreg2p5_ctrl_read                          (*(volatile unsigned int *)clb_vreg2p5_ctrl_read_adr)
  #define clb_xtal_read_adr                              0x00640324                                                   // base_clb_regs_adr + 0x00000004 * 0x000000c9
  #define clb_xtal_read                                  (*(volatile unsigned int *)clb_xtal_read_adr)
  #define clb_rcal_ctl_read_adr                          0x00640328                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ca
  #define clb_rcal_ctl_read                              (*(volatile unsigned int *)clb_rcal_ctl_read_adr)
  #define clb_mini_pmu_read_5_adr                        0x0064032c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000cb
  #define clb_mini_pmu_read_5                            (*(volatile unsigned int *)clb_mini_pmu_read_5_adr)
  #define clb_usb3_read_adr                              0x00640330                                                   // base_clb_regs_adr + 0x00000004 * 0x000000cc
  #define clb_usb3_read                                  (*(volatile unsigned int *)clb_usb3_read_adr)
  #define clb_usb3_ctrl2_adr                             0x00640334                                                   // base_clb_regs_adr + 0x00000004 * 0x000000cd
  #define clb_usb3_ctrl2                                 (*(volatile unsigned int *)clb_usb3_ctrl2_adr)
  #define clb_usb3_ctrl3_adr                             0x00640338                                                   // base_clb_regs_adr + 0x00000004 * 0x000000ce
  #define clb_usb3_ctrl3                                 (*(volatile unsigned int *)clb_usb3_ctrl3_adr)
  #define clb_clk_ctl_19_adr                             0x0064033c                                                   // base_clb_regs_adr + 0x00000004 * 0x000000cf
  #define clb_clk_ctl_19                                 (*(volatile unsigned int *)clb_clk_ctl_19_adr)
  #define clb_clk_ctl_1a_adr                             0x00640340                                                   // base_clb_regs_adr + 0x00000004 * 0x000000d0
  #define clb_clk_ctl_1a                                 (*(volatile unsigned int *)clb_clk_ctl_1a_adr)
  #define clb_straps_read_adr                            0x00640344                                                   // base_clb_regs_adr + 0x00000004 * 0x000000d1
  #define clb_straps_read                                (*(volatile unsigned int *)clb_straps_read_adr)
  #define clb_bt2clb_PMU_pmu_ovride2_adr                 0x00640348                                                   // base_clb_regs_adr + 0x00000004 * 0x000000d2
  #define clb_bt2clb_PMU_pmu_ovride2                     (*(volatile unsigned int *)clb_bt2clb_PMU_pmu_ovride2_adr)
  #define gci_corecapabilities0_adr                      0x00650000                                                   // gci_regs_adr_base + gci_corecapabilities0
  #define gci_corecapabilities0                          (*(volatile unsigned int *)gci_corecapabilities0_adr)
  #define gci_corecapabilities1_adr                      0x00650004                                                   // gci_regs_adr_base + gci_corecapabilities1
  #define gci_corecapabilities1                          (*(volatile unsigned int *)gci_corecapabilities1_adr)
  #define gci_corecapabilities2_adr                      0x00650008                                                   // gci_regs_adr_base + gci_corecapabilities2
  #define gci_corecapabilities2                          (*(volatile unsigned int *)gci_corecapabilities2_adr)
  #define gci_corectrl_c_adr                             0x0065000c                                                   // gci_regs_adr_base + gci_corectrl_c
  #define gci_corectrl_c                                 (*(volatile unsigned int *)gci_corectrl_c_adr)
  #define gci_corestatus_c_adr                           0x00650010                                                   // gci_regs_adr_base + gci_corestatus_c
  #define gci_corestatus_c                               (*(volatile unsigned int *)gci_corestatus_c_adr)
  #define gci_gciintstatus_adr                           0x00650014                                                   // gci_regs_adr_base + gci_gciintstatus
  #define gci_gciintstatus                               (*(volatile unsigned int *)gci_gciintstatus_adr)
  #define gci_gciintmask_adr                             0x00650018                                                   // gci_regs_adr_base + gci_gciintmask
  #define gci_gciintmask                                 (*(volatile unsigned int *)gci_gciintmask_adr)
  #define gci_gciwakemask_adr                            0x0065001c                                                   // gci_regs_adr_base + gci_gciwakemask
  #define gci_gciwakemask                                (*(volatile unsigned int *)gci_gciwakemask_adr)
  #define gci_gcilevelinterruptstatussummary_adr         0x00650020                                                   // gci_regs_adr_base + gci_gcilevelinterruptstatussummary
  #define gci_gcilevelinterruptstatussummary             (*(volatile unsigned int *)gci_gcilevelinterruptstatussummary_adr)
  #define gci_gcieventinterruptstatussummary_adr         0x00650024                                                   // gci_regs_adr_base + gci_gcieventinterruptstatussummary
  #define gci_gcieventinterruptstatussummary             (*(volatile unsigned int *)gci_gcieventinterruptstatussummary_adr)
  #define gci_gciwakelevelinterruptstatussummary_adr     0x00650028                                                   // gci_regs_adr_base + gci_gciwakelevelinterruptstatussummary
  #define gci_gciwakelevelinterruptstatussummary         (*(volatile unsigned int *)gci_gciwakelevelinterruptstatussummary_adr)
  #define gci_gciwakeeventinterruptstatussummary_adr     0x0065002c                                                   // gci_regs_adr_base + gci_gciwakeeventinterruptstatussummary
  #define gci_gciwakeeventinterruptstatussummary         (*(volatile unsigned int *)gci_gciwakeeventinterruptstatussummary_adr)
  #define gci_semaphoreinterruptstatus_adr               0x00650030                                                   // gci_regs_adr_base + gci_semaphoreinterruptstatus
  #define gci_semaphoreinterruptstatus                   (*(volatile unsigned int *)gci_semaphoreinterruptstatus_adr)
  #define gci_semaphoreinterruptmask_adr                 0x00650034                                                   // gci_regs_adr_base + gci_semaphoreinterruptmask
  #define gci_semaphoreinterruptmask                     (*(volatile unsigned int *)gci_semaphoreinterruptmask_adr)
  #define gci_semaphorerequest_adr                       0x00650038                                                   // gci_regs_adr_base + gci_semaphorerequest
  #define gci_semaphorerequest                           (*(volatile unsigned int *)gci_semaphorerequest_adr)
  #define gci_semaphorereserve_adr                       0x0065003c                                                   // gci_regs_adr_base + gci_semaphorereserve
  #define gci_semaphorereserve                           (*(volatile unsigned int *)gci_semaphorereserve_adr)
  #define gci_gciindirectaddress_adr                     0x00650040                                                   // gci_regs_adr_base + gci_gciindirectaddress
  #define gci_gciindirectaddress                         (*(volatile unsigned int *)gci_gciindirectaddress_adr)
  #define gci_gcigpiocontrol_c_adr                       0x00650044                                                   // gci_regs_adr_base + gci_gcigpiocontrol_c
  #define gci_gcigpiocontrol_c                           (*(volatile unsigned int *)gci_gcigpiocontrol_c_adr)
  #define gci_gcigpiostatus_adr                          0x00650048                                                   // gci_regs_adr_base + gci_gcigpiostatus
  #define gci_gcigpiostatus                              (*(volatile unsigned int *)gci_gcigpiostatus_adr)
  #define gci_gcigpiomask_c_adr                          0x0065004c                                                   // gci_regs_adr_base + gci_gcigpiomask_c
  #define gci_gcigpiomask_c                              (*(volatile unsigned int *)gci_gcigpiomask_c_adr)
  #define gci_gcieventsummary_adr                        0x00650050                                                   // gci_regs_adr_base + gci_gcieventsummary
  #define gci_gcieventsummary                            (*(volatile unsigned int *)gci_gcieventsummary_adr)
  #define gci_gcimisccontrol_c_adr                       0x00650054                                                   // gci_regs_adr_base + gci_gcimisccontrol_c
  #define gci_gcimisccontrol_c                           (*(volatile unsigned int *)gci_gcimisccontrol_c_adr)
  #define gci_gcigpiointmask_adr                         0x00650058                                                   // gci_regs_adr_base + gci_gcigpiointmask
  #define gci_gcigpiointmask                             (*(volatile unsigned int *)gci_gcigpiointmask_adr)
  #define gci_gcigpiowakemask_adr                        0x0065005c                                                   // gci_regs_adr_base + gci_gcigpiowakemask
  #define gci_gcigpiowakemask                            (*(volatile unsigned int *)gci_gcigpiowakemask_adr)
  #define gci_gciinput0_c_adr                            0x00650060                                                   // gci_regs_adr_base + gci_gciinput0_c
  #define gci_gciinput0_c                                (*(volatile unsigned int *)gci_gciinput0_c_adr)
  #define gci_gciinput1_c_adr                            0x00650064                                                   // gci_regs_adr_base + gci_gciinput1_c
  #define gci_gciinput1_c                                (*(volatile unsigned int *)gci_gciinput1_c_adr)
  #define gci_gciinput2_c_adr                            0x00650068                                                   // gci_regs_adr_base + gci_gciinput2_c
  #define gci_gciinput2_c                                (*(volatile unsigned int *)gci_gciinput2_c_adr)
  #define gci_gciinput3_c_adr                            0x0065006c                                                   // gci_regs_adr_base + gci_gciinput3_c
  #define gci_gciinput3_c                                (*(volatile unsigned int *)gci_gciinput3_c_adr)
  #define gci_gciinput4_c_adr                            0x00650070                                                   // gci_regs_adr_base + gci_gciinput4_c
  #define gci_gciinput4_c                                (*(volatile unsigned int *)gci_gciinput4_c_adr)
  #define gci_gciinput5_c_adr                            0x00650074                                                   // gci_regs_adr_base + gci_gciinput5_c
  #define gci_gciinput5_c                                (*(volatile unsigned int *)gci_gciinput5_c_adr)
  #define gci_gciinput6_c_adr                            0x00650078                                                   // gci_regs_adr_base + gci_gciinput6_c
  #define gci_gciinput6_c                                (*(volatile unsigned int *)gci_gciinput6_c_adr)
  #define gci_gciinput7_c_adr                            0x0065007c                                                   // gci_regs_adr_base + gci_gciinput7_c
  #define gci_gciinput7_c                                (*(volatile unsigned int *)gci_gciinput7_c_adr)
  #define gci_gciinput8_c_adr                            0x00650080                                                   // gci_regs_adr_base + gci_gciinput8_c
  #define gci_gciinput8_c                                (*(volatile unsigned int *)gci_gciinput8_c_adr)
  #define gci_gciinput9_c_adr                            0x00650084                                                   // gci_regs_adr_base + gci_gciinput9_c
  #define gci_gciinput9_c                                (*(volatile unsigned int *)gci_gciinput9_c_adr)
  #define gci_gciinput10_c_adr                           0x00650088                                                   // gci_regs_adr_base + gci_gciinput10_c
  #define gci_gciinput10_c                               (*(volatile unsigned int *)gci_gciinput10_c_adr)
  #define gci_gciinput11_c_adr                           0x0065008c                                                   // gci_regs_adr_base + gci_gciinput11_c
  #define gci_gciinput11_c                               (*(volatile unsigned int *)gci_gciinput11_c_adr)
  #define gci_gciinput12_c_adr                           0x00650090                                                   // gci_regs_adr_base + gci_gciinput12_c
  #define gci_gciinput12_c                               (*(volatile unsigned int *)gci_gciinput12_c_adr)
  #define gci_gciinput13_c_adr                           0x00650094                                                   // gci_regs_adr_base + gci_gciinput13_c
  #define gci_gciinput13_c                               (*(volatile unsigned int *)gci_gciinput13_c_adr)
  #define gci_gciinput14_c_adr                           0x00650098                                                   // gci_regs_adr_base + gci_gciinput14_c
  #define gci_gciinput14_c                               (*(volatile unsigned int *)gci_gciinput14_c_adr)
  #define gci_gciinput15_c_adr                           0x0065009c                                                   // gci_regs_adr_base + gci_gciinput15_c
  #define gci_gciinput15_c                               (*(volatile unsigned int *)gci_gciinput15_c_adr)
  #define gci_gciinput16_c_adr                           0x006500a0                                                   // gci_regs_adr_base + gci_gciinput16_c
  #define gci_gciinput16_c                               (*(volatile unsigned int *)gci_gciinput16_c_adr)
  #define gci_gciinput17_c_adr                           0x006500a4                                                   // gci_regs_adr_base + gci_gciinput17_c
  #define gci_gciinput17_c                               (*(volatile unsigned int *)gci_gciinput17_c_adr)
  #define gci_gciinput18_c_adr                           0x006500a8                                                   // gci_regs_adr_base + gci_gciinput18_c
  #define gci_gciinput18_c                               (*(volatile unsigned int *)gci_gciinput18_c_adr)
  #define gci_gciinput19_c_adr                           0x006500ac                                                   // gci_regs_adr_base + gci_gciinput19_c
  #define gci_gciinput19_c                               (*(volatile unsigned int *)gci_gciinput19_c_adr)
  #define gci_gciinput20_c_adr                           0x006500b0                                                   // gci_regs_adr_base + gci_gciinput20_c
  #define gci_gciinput20_c                               (*(volatile unsigned int *)gci_gciinput20_c_adr)
  #define gci_gciinput21_c_adr                           0x006500b4                                                   // gci_regs_adr_base + gci_gciinput21_c
  #define gci_gciinput21_c                               (*(volatile unsigned int *)gci_gciinput21_c_adr)
  #define gci_gciinput22_c_adr                           0x006500b8                                                   // gci_regs_adr_base + gci_gciinput22_c
  #define gci_gciinput22_c                               (*(volatile unsigned int *)gci_gciinput22_c_adr)
  #define gci_gciinput23_c_adr                           0x006500bc                                                   // gci_regs_adr_base + gci_gciinput23_c
  #define gci_gciinput23_c                               (*(volatile unsigned int *)gci_gciinput23_c_adr)
  #define gci_gciinput24_c_adr                           0x006500c0                                                   // gci_regs_adr_base + gci_gciinput24_c
  #define gci_gciinput24_c                               (*(volatile unsigned int *)gci_gciinput24_c_adr)
  #define gci_gciinput25_c_adr                           0x006500c4                                                   // gci_regs_adr_base + gci_gciinput25_c
  #define gci_gciinput25_c                               (*(volatile unsigned int *)gci_gciinput25_c_adr)
  #define gci_gciinput26_c_adr                           0x006500c8                                                   // gci_regs_adr_base + gci_gciinput26_c
  #define gci_gciinput26_c                               (*(volatile unsigned int *)gci_gciinput26_c_adr)
  #define gci_gciinput27_c_adr                           0x006500cc                                                   // gci_regs_adr_base + gci_gciinput27_c
  #define gci_gciinput27_c                               (*(volatile unsigned int *)gci_gciinput27_c_adr)
  #define gci_gciinput28_c_adr                           0x006500d0                                                   // gci_regs_adr_base + gci_gciinput28_c
  #define gci_gciinput28_c                               (*(volatile unsigned int *)gci_gciinput28_c_adr)
  #define gci_gciinput29_c_adr                           0x006500d4                                                   // gci_regs_adr_base + gci_gciinput29_c
  #define gci_gciinput29_c                               (*(volatile unsigned int *)gci_gciinput29_c_adr)
  #define gci_gciinput30_c_adr                           0x006500d8                                                   // gci_regs_adr_base + gci_gciinput30_c
  #define gci_gciinput30_c                               (*(volatile unsigned int *)gci_gciinput30_c_adr)
  #define gci_gciinput31_c_adr                           0x006500dc                                                   // gci_regs_adr_base + gci_gciinput31_c
  #define gci_gciinput31_c                               (*(volatile unsigned int *)gci_gciinput31_c_adr)
  #define gci_gcievent0_adr                              0x006500e0                                                   // gci_regs_adr_base + gci_gcievent0
  #define gci_gcievent0                                  (*(volatile unsigned int *)gci_gcievent0_adr)
  #define gci_gcievent1_adr                              0x006500e4                                                   // gci_regs_adr_base + gci_gcievent1
  #define gci_gcievent1                                  (*(volatile unsigned int *)gci_gcievent1_adr)
  #define gci_gcievent2_adr                              0x006500e8                                                   // gci_regs_adr_base + gci_gcievent2
  #define gci_gcievent2                                  (*(volatile unsigned int *)gci_gcievent2_adr)
  #define gci_gcievent3_adr                              0x006500ec                                                   // gci_regs_adr_base + gci_gcievent3
  #define gci_gcievent3                                  (*(volatile unsigned int *)gci_gcievent3_adr)
  #define gci_gcievent4_adr                              0x006500f0                                                   // gci_regs_adr_base + gci_gcievent4
  #define gci_gcievent4                                  (*(volatile unsigned int *)gci_gcievent4_adr)
  #define gci_gcievent5_adr                              0x006500f4                                                   // gci_regs_adr_base + gci_gcievent5
  #define gci_gcievent5                                  (*(volatile unsigned int *)gci_gcievent5_adr)
  #define gci_gcievent6_adr                              0x006500f8                                                   // gci_regs_adr_base + gci_gcievent6
  #define gci_gcievent6                                  (*(volatile unsigned int *)gci_gcievent6_adr)
  #define gci_gcievent7_adr                              0x006500fc                                                   // gci_regs_adr_base + gci_gcievent7
  #define gci_gcievent7                                  (*(volatile unsigned int *)gci_gcievent7_adr)
  #define gci_gcievent8_adr                              0x00650100                                                   // gci_regs_adr_base + gci_gcievent8
  #define gci_gcievent8                                  (*(volatile unsigned int *)gci_gcievent8_adr)
  #define gci_gcievent9_adr                              0x00650104                                                   // gci_regs_adr_base + gci_gcievent9
  #define gci_gcievent9                                  (*(volatile unsigned int *)gci_gcievent9_adr)
  #define gci_gcievent10_adr                             0x00650108                                                   // gci_regs_adr_base + gci_gcievent10
  #define gci_gcievent10                                 (*(volatile unsigned int *)gci_gcievent10_adr)
  #define gci_gcievent11_adr                             0x0065010c                                                   // gci_regs_adr_base + gci_gcievent11
  #define gci_gcievent11                                 (*(volatile unsigned int *)gci_gcievent11_adr)
  #define gci_gcievent12_adr                             0x00650110                                                   // gci_regs_adr_base + gci_gcievent12
  #define gci_gcievent12                                 (*(volatile unsigned int *)gci_gcievent12_adr)
  #define gci_gcievent13_adr                             0x00650114                                                   // gci_regs_adr_base + gci_gcievent13
  #define gci_gcievent13                                 (*(volatile unsigned int *)gci_gcievent13_adr)
  #define gci_gcievent14_adr                             0x00650118                                                   // gci_regs_adr_base + gci_gcievent14
  #define gci_gcievent14                                 (*(volatile unsigned int *)gci_gcievent14_adr)
  #define gci_gcievent15_adr                             0x0065011c                                                   // gci_regs_adr_base + gci_gcievent15
  #define gci_gcievent15                                 (*(volatile unsigned int *)gci_gcievent15_adr)
  #define gci_gcievent16_adr                             0x00650120                                                   // gci_regs_adr_base + gci_gcievent16
  #define gci_gcievent16                                 (*(volatile unsigned int *)gci_gcievent16_adr)
  #define gci_gcievent17_adr                             0x00650124                                                   // gci_regs_adr_base + gci_gcievent17
  #define gci_gcievent17                                 (*(volatile unsigned int *)gci_gcievent17_adr)
  #define gci_gcievent18_adr                             0x00650128                                                   // gci_regs_adr_base + gci_gcievent18
  #define gci_gcievent18                                 (*(volatile unsigned int *)gci_gcievent18_adr)
  #define gci_gcievent19_adr                             0x0065012c                                                   // gci_regs_adr_base + gci_gcievent19
  #define gci_gcievent19                                 (*(volatile unsigned int *)gci_gcievent19_adr)
  #define gci_gcievent20_adr                             0x00650130                                                   // gci_regs_adr_base + gci_gcievent20
  #define gci_gcievent20                                 (*(volatile unsigned int *)gci_gcievent20_adr)
  #define gci_gcievent21_adr                             0x00650134                                                   // gci_regs_adr_base + gci_gcievent21
  #define gci_gcievent21                                 (*(volatile unsigned int *)gci_gcievent21_adr)
  #define gci_gcievent22_adr                             0x00650138                                                   // gci_regs_adr_base + gci_gcievent22
  #define gci_gcievent22                                 (*(volatile unsigned int *)gci_gcievent22_adr)
  #define gci_gcievent23_adr                             0x0065013c                                                   // gci_regs_adr_base + gci_gcievent23
  #define gci_gcievent23                                 (*(volatile unsigned int *)gci_gcievent23_adr)
  #define gci_gcievent24_adr                             0x00650140                                                   // gci_regs_adr_base + gci_gcievent24
  #define gci_gcievent24                                 (*(volatile unsigned int *)gci_gcievent24_adr)
  #define gci_gcievent25_adr                             0x00650144                                                   // gci_regs_adr_base + gci_gcievent25
  #define gci_gcievent25                                 (*(volatile unsigned int *)gci_gcievent25_adr)
  #define gci_gcievent26_adr                             0x00650148                                                   // gci_regs_adr_base + gci_gcievent26
  #define gci_gcievent26                                 (*(volatile unsigned int *)gci_gcievent26_adr)
  #define gci_gcievent27_adr                             0x0065014c                                                   // gci_regs_adr_base + gci_gcievent27
  #define gci_gcievent27                                 (*(volatile unsigned int *)gci_gcievent27_adr)
  #define gci_gcievent28_adr                             0x00650150                                                   // gci_regs_adr_base + gci_gcievent28
  #define gci_gcievent28                                 (*(volatile unsigned int *)gci_gcievent28_adr)
  #define gci_gcievent29_adr                             0x00650154                                                   // gci_regs_adr_base + gci_gcievent29
  #define gci_gcievent29                                 (*(volatile unsigned int *)gci_gcievent29_adr)
  #define gci_gcievent30_adr                             0x00650158                                                   // gci_regs_adr_base + gci_gcievent30
  #define gci_gcievent30                                 (*(volatile unsigned int *)gci_gcievent30_adr)
  #define gci_gcievent31_adr                             0x0065015c                                                   // gci_regs_adr_base + gci_gcievent31
  #define gci_gcievent31                                 (*(volatile unsigned int *)gci_gcievent31_adr)
  #define gci_gcioutput0_adr                             0x00650160                                                   // gci_regs_adr_base + gci_gcioutput0
  #define gci_gcioutput0                                 (*(volatile unsigned int *)gci_gcioutput0_adr)
  #define gci_gcioutput1_adr                             0x00650164                                                   // gci_regs_adr_base + gci_gcioutput1
  #define gci_gcioutput1                                 (*(volatile unsigned int *)gci_gcioutput1_adr)
  #define gci_gcioutput2_adr                             0x00650168                                                   // gci_regs_adr_base + gci_gcioutput2
  #define gci_gcioutput2                                 (*(volatile unsigned int *)gci_gcioutput2_adr)
  #define gci_gcioutput3_adr                             0x0065016c                                                   // gci_regs_adr_base + gci_gcioutput3
  #define gci_gcioutput3                                 (*(volatile unsigned int *)gci_gcioutput3_adr)
  #define gci_gcicontrol0_adr                            0x00650170                                                   // gci_regs_adr_base + gci_gcicontrol0
  #define gci_gcicontrol0                                (*(volatile unsigned int *)gci_gcicontrol0_adr)
  #define gci_gcicontrol1_adr                            0x00650174                                                   // gci_regs_adr_base + gci_gcicontrol1
  #define gci_gcicontrol1                                (*(volatile unsigned int *)gci_gcicontrol1_adr)
  #define gci_gciinterruptpolarity_adr                   0x00650178                                                   // gci_regs_adr_base + gci_gciinterruptpolarity
  #define gci_gciinterruptpolarity                       (*(volatile unsigned int *)gci_gciinterruptpolarity_adr)
  #define gci_gcilevelinterruptmask_adr                  0x0065017c                                                   // gci_regs_adr_base + gci_gcilevelinterruptmask
  #define gci_gcilevelinterruptmask                      (*(volatile unsigned int *)gci_gcilevelinterruptmask_adr)
  #define gci_gcieventinterruptmask_adr                  0x00650180                                                   // gci_regs_adr_base + gci_gcieventinterruptmask
  #define gci_gcieventinterruptmask                      (*(volatile unsigned int *)gci_gcieventinterruptmask_adr)
  #define gci_gciwakelevelinterruptmask_adr              0x00650184                                                   // gci_regs_adr_base + gci_gciwakelevelinterruptmask
  #define gci_gciwakelevelinterruptmask                  (*(volatile unsigned int *)gci_gciwakelevelinterruptmask_adr)
  #define gci_gciwakeeventinterruptmask_adr              0x00650188                                                   // gci_regs_adr_base + gci_gciwakeeventinterruptmask
  #define gci_gciwakeeventinterruptmask                  (*(volatile unsigned int *)gci_gciwakeeventinterruptmask_adr)
  #define gci_gcihwmask_adr                              0x0065018c                                                   // gci_regs_adr_base + gci_gcihwmask
  #define gci_gcihwmask                                  (*(volatile unsigned int *)gci_gcihwmask_adr)
  #define gci_gciinbandlevelinterruptmask_adr            0x00650190                                                   // gci_regs_adr_base + gci_gciinbandlevelinterruptmask
  #define gci_gciinbandlevelinterruptmask                (*(volatile unsigned int *)gci_gciinbandlevelinterruptmask_adr)
  #define gci_gciinbandeventinterruptmask_adr            0x00650194                                                   // gci_regs_adr_base + gci_gciinbandeventinterruptmask
  #define gci_gciinbandeventinterruptmask                (*(volatile unsigned int *)gci_gciinbandeventinterruptmask_adr)
  #define gci_gciinbandlevelinterruptstatussummary_adr   0x00650198                                                   // gci_regs_adr_base + gci_gciinbandlevelinterruptstatussummary
  #define gci_gciinbandlevelinterruptstatussummary       (*(volatile unsigned int *)gci_gciinbandlevelinterruptstatussummary_adr)
  #define gci_gciinbandeventinterruptstatussummary_adr   0x0065019c                                                   // gci_regs_adr_base + gci_gciinbandeventinterruptstatussummary
  #define gci_gciinbandeventinterruptstatussummary       (*(volatile unsigned int *)gci_gciinbandeventinterruptstatussummary_adr)
  #define gci_seciauxtx_adr                              0x006501a0                                                   // gci_regs_adr_base + gci_seciauxtx
  #define gci_seciauxtx                                  (*(volatile unsigned int *)gci_seciauxtx_adr)
  #define gci_seciauxrx_c_adr                            0x006501a4                                                   // gci_regs_adr_base + gci_seciauxrx_c
  #define gci_seciauxrx_c                                (*(volatile unsigned int *)gci_seciauxrx_c_adr)
  #define gci_secitxdatatag_c_adr                        0x006501a8                                                   // gci_regs_adr_base + gci_secitxdatatag_c
  #define gci_secitxdatatag_c                            (*(volatile unsigned int *)gci_secitxdatatag_c_adr)
  #define gci_secirxdatatag_c_adr                        0x006501ac                                                   // gci_regs_adr_base + gci_secirxdatatag_c
  #define gci_secirxdatatag_c                            (*(volatile unsigned int *)gci_secirxdatatag_c_adr)
  #define gci_secitxdatamask_c_adr                       0x006501b0                                                   // gci_regs_adr_base + gci_secitxdatamask_c
  #define gci_secitxdatamask_c                           (*(volatile unsigned int *)gci_secitxdatamask_c_adr)
  #define gci_seciuseformat0tx_c_adr                     0x006501b4                                                   // gci_regs_adr_base + gci_seciuseformat0tx_c
  #define gci_seciuseformat0tx_c                         (*(volatile unsigned int *)gci_seciuseformat0tx_c_adr)
  #define gci_seciformat0txoffset_c_adr                  0x006501b8                                                   // gci_regs_adr_base + gci_seciformat0txoffset_c
  #define gci_seciformat0txoffset_c                      (*(volatile unsigned int *)gci_seciformat0txoffset_c_adr)
  #define gci_seciformat0rxoffset_c_adr                  0x006501bc                                                   // gci_regs_adr_base + gci_seciformat0rxoffset_c
  #define gci_seciformat0rxoffset_c                      (*(volatile unsigned int *)gci_seciformat0rxoffset_c_adr)
  #define gci_seciformat1txoffset_c_adr                  0x006501c0                                                   // gci_regs_adr_base + gci_seciformat1txoffset_c
  #define gci_seciformat1txoffset_c                      (*(volatile unsigned int *)gci_seciformat1txoffset_c_adr)
  #define gci_gcirxfifocommoncontrol_c_adr               0x006501c4                                                   // gci_regs_adr_base + gci_gcirxfifocommoncontrol_c
  #define gci_gcirxfifocommoncontrol_c                   (*(volatile unsigned int *)gci_gcirxfifocommoncontrol_c_adr)
  #define gci_gcirxfifoperipcontrol_adr                  0x006501c8                                                   // gci_regs_adr_base + gci_gcirxfifoperipcontrol
  #define gci_gcirxfifoperipcontrol                      (*(volatile unsigned int *)gci_gcirxfifoperipcontrol_adr)
  #define gci_seciuartescapevalue_c_adr                  0x006501d0                                                   // gci_regs_adr_base + gci_seciuartescapevalue_c
  #define gci_seciuartescapevalue_c                      (*(volatile unsigned int *)gci_seciuartescapevalue_c_adr)
  #define gci_seciuartautobaudctr_c_adr                  0x006501d4                                                   // gci_regs_adr_base + gci_seciuartautobaudctr_c
  #define gci_seciuartautobaudctr_c                      (*(volatile unsigned int *)gci_seciuartautobaudctr_c_adr)
  #define gci_secififolevel_c_adr                        0x006501d8                                                   // gci_regs_adr_base + gci_secififolevel_c
  #define gci_secififolevel_c                            (*(volatile unsigned int *)gci_secififolevel_c_adr)
  #define gci_seciuartdata_c_adr                         0x006501dc                                                   // gci_regs_adr_base + gci_seciuartdata_c
  #define gci_seciuartdata_c                             (*(volatile unsigned int *)gci_seciuartdata_c_adr)
  #define gci_seciuartbaudratedivisor_c_adr              0x006501e0                                                   // gci_regs_adr_base + gci_seciuartbaudratedivisor_c
  #define gci_seciuartbaudratedivisor_c                  (*(volatile unsigned int *)gci_seciuartbaudratedivisor_c_adr)
  #define gci_seciuartfcr_c_adr                          0x006501e4                                                   // gci_regs_adr_base + gci_seciuartfcr_c
  #define gci_seciuartfcr_c                              (*(volatile unsigned int *)gci_seciuartfcr_c_adr)
  #define gci_seciuartlcr_c_adr                          0x006501e8                                                   // gci_regs_adr_base + gci_seciuartlcr_c
  #define gci_seciuartlcr_c                              (*(volatile unsigned int *)gci_seciuartlcr_c_adr)
  #define gci_seciuartmcr_c_adr                          0x006501ec                                                   // gci_regs_adr_base + gci_seciuartmcr_c
  #define gci_seciuartmcr_c                              (*(volatile unsigned int *)gci_seciuartmcr_c_adr)
  #define gci_seciuartlsr_c_adr                          0x006501f0                                                   // gci_regs_adr_base + gci_seciuartlsr_c
  #define gci_seciuartlsr_c                              (*(volatile unsigned int *)gci_seciuartlsr_c_adr)
  #define gci_seciuartmsr_c_adr                          0x006501f4                                                   // gci_regs_adr_base + gci_seciuartmsr_c
  #define gci_seciuartmsr_c                              (*(volatile unsigned int *)gci_seciuartmsr_c_adr)
  #define gci_seciuartbaudrateadjustment_c_adr           0x006501f8                                                   // gci_regs_adr_base + gci_seciuartbaudrateadjustment_c
  #define gci_seciuartbaudrateadjustment_c               (*(volatile unsigned int *)gci_seciuartbaudrateadjustment_c_adr)
  #define gci_gciinbandintmask_adr                       0x006501fc                                                   // gci_regs_adr_base + gci_gciinbandintmask
  #define gci_gciinbandintmask                           (*(volatile unsigned int *)gci_gciinbandintmask_adr)
  #define gci_gcichipcontrol_c_adr                       0x00650200                                                   // gci_regs_adr_base + gci_gcichipcontrol_c
  #define gci_gcichipcontrol_c                           (*(volatile unsigned int *)gci_gcichipcontrol_c_adr)
  #define gci_gcichipstatus_c_adr                        0x00650204                                                   // gci_regs_adr_base + gci_gcichipstatus_c
  #define gci_gcichipstatus_c                            (*(volatile unsigned int *)gci_gcichipstatus_c_adr)
  #define gci_gcigpioout_adr                             0x00650208                                                   // gci_regs_adr_base + gci_gcigpioout
  #define gci_gcigpioout                                 (*(volatile unsigned int *)gci_gcigpioout_adr)
  #define gci_gcigpiooutread_c_adr                       0x0065020c                                                   // gci_regs_adr_base + gci_gcigpiooutread_c
  #define gci_gcigpiooutread_c                           (*(volatile unsigned int *)gci_gcigpiooutread_c_adr)
  #define rom_adr_base                                   0x00000000                                                   // base_IntIRom
  #define smi_mem_adr_base                               0xf0000000
  #define ram_adr_base                                   0x00200000                                                   // base_IntMemCm3
  #define pmu_adr_base                                   0x00320000                                                   // base_hw_regs_cm3 + 0x00020000
  #define mtu_adr_base                                   0x00324000                                                   // base_hw_regs_cm3 + 0x00024000
  #define fmm_fifo_adr_base                              0x00325000                                                   // base_hw_regs_cm3 + 0x00025000
  #define aud_fifo_adr_base                              0x00326000                                                   // base_hw_regs_cm3 + 0x00026000
  #define aud_fifo_regs_adr_base                         0x00326c00                                                   // base_hw_regs_cm3 + 0x00026c00
  #define audio_adr_base                                 0x00327000                                                   // base_hw_regs_cm3 + 0x00027000
  #define vco_adr_base                                   0x00327400                                                   // base_hw_regs_cm3 + 0x00027400
  #define iq_adr_base                                    0x00327500                                                   // base_hw_regs_cm3 + 0x00027500
  #define fmrf_adr_base                                  0x00327600                                                   // base_hw_regs_cm3 + 0x00027600
  #define apb_adr_base                                   0x00328000                                                   // base_hw_regs_cm3 + 0x00028000
  #define modem_adr_base                                 0x0031fc00                                                   // base_hw_regs_cm3 + 0x0001fc00
  #define modem_adr_new_base                             0x0031f800                                                   // base_hw_regs_cm3 + 0x0001f800
  #define rf_adr_base                                    0x00600000                                                   // base_rf_regs
  #define sri_bk_adr_base                                0x0031e000                                                   // base_hw_regs_cm3 + 0x0001e000
  #define bpl_hclk_base_adr                              0x00314000                                                   // base_hw_regs_cm3 + 0x00014000
  #define bpl_hclk_base                                  (*(volatile unsigned int *)bpl_hclk_base_adr)
  #define phy_adr_base                                   0x00318000                                                   // base_hw_regs_cm3 + 0x00018000
  #define ptu_adr_base                                   0x00360000                                                   // base_hw_regs_cm3 + 0x00060000
  #define prc_adr_base                                   0x00310000                                                   // base_hw_regs_cm3 + 0x00010000
  #define ptu_aux_adr_base                               0x00350000                                                   // base_hw_regs_cm3 + 0x00050000
  #define smi_ahb_adr_base                               0x00308000                                                   // base_hw_regs_cm3 + 0x00008000
  #define dmac_adr_base                                  0x00300000                                                   // base_hw_regs_cm3 + 0x00000000
  #define memory_map_base                                0x00000000
  #define rmppause_adr_base                              0x00328000                                                   // apb_adr_base + 0x00000000
  #define watchdog_adr_base                              0x00329000                                                   // apb_adr_base + 0x00001000
  #define timers_adr_base                                0x0032a000                                                   // apb_adr_base + 0x00002000
  #define gpio2_adr_base                                 0x0032b000                                                   // apb_adr_base + 0x00003000
  #define gpio_adr_base                                  0x0032c000                                                   // apb_adr_base + 0x00004000
  #define swp_adr_base                                   0x0032d000                                                   // apb_adr_base + 0x00005000
  #define otp_adr_base                                   0x0032e000                                                   // apb_adr_base + 0x00006000
  #define mia_adr_base                                   0x00334000
  #define lhl_adr_base                                   0x00336000
  #define pause_adr                                      0x00328000                                                   // rmppause_adr_base + 0x00000000
  #define pause                                          (*(volatile unsigned int *)pause_adr)
  #define remap_adr                                      0x00328004                                                   // rmppause_adr_base + 0x00000004
  #define remap                                          (*(volatile unsigned int *)remap_adr)
  #define resetstatus_adr                                0x00328008                                                   // rmppause_adr_base + 0x00000008
  #define resetstatus                                    (*(volatile unsigned int *)resetstatus_adr)
  #define resetstatusclr_adr                             0x0032800c                                                   // rmppause_adr_base + 0x0000000c
  #define resetstatusclr                                 (*(volatile unsigned int *)resetstatusclr_adr)
  #define rpcperiphid0_adr                               0x00328fe0                                                   // rmppause_adr_base + 0x00000fe0
  #define rpcperiphid0                                   (*(volatile unsigned int *)rpcperiphid0_adr)
  #define rpcperiphid1_adr                               0x00328fe4                                                   // rmppause_adr_base + 0x00000fe4
  #define rpcperiphid1                                   (*(volatile unsigned int *)rpcperiphid1_adr)
  #define rpcperiphid2_adr                               0x00328fe8                                                   // rmppause_adr_base + 0x00000fe8
  #define rpcperiphid2                                   (*(volatile unsigned int *)rpcperiphid2_adr)
  #define rpcperiphid3_adr                               0x00328fec                                                   // rmppause_adr_base + 0x00000fec
  #define rpcperiphid3                                   (*(volatile unsigned int *)rpcperiphid3_adr)
  #define rpcpcellid0_adr                                0x00328ff0                                                   // rmppause_adr_base + 0x00000ff0
  #define rpcpcellid0                                    (*(volatile unsigned int *)rpcpcellid0_adr)
  #define rpcpcellid1_adr                                0x00328ff4                                                   // rmppause_adr_base + 0x00000ff4
  #define rpcpcellid1                                    (*(volatile unsigned int *)rpcpcellid1_adr)
  #define rpcpcellid2_adr                                0x00328ff8                                                   // rmppause_adr_base + 0x00000ff8
  #define rpcpcellid2                                    (*(volatile unsigned int *)rpcpcellid2_adr)
  #define rpcpcellid3_adr                                0x00328ffc                                                   // rmppause_adr_base + 0x00000ffc
  #define rpcpcellid3                                    (*(volatile unsigned int *)rpcpcellid3_adr)
  #define wdogload_adr                                   0x00329000                                                   // watchdog_adr_base + 0x00000000
  #define wdogload                                       (*(volatile unsigned int *)wdogload_adr)
  #define wdogvalue_adr                                  0x00329004                                                   // watchdog_adr_base + 0x00000004
  #define wdogvalue                                      (*(volatile unsigned int *)wdogvalue_adr)
  #define wdogcontrol_adr                                0x00329008                                                   // watchdog_adr_base + 0x00000008
  #define wdogcontrol                                    (*(volatile unsigned int *)wdogcontrol_adr)
  #define wdogintclr_adr                                 0x0032900c                                                   // watchdog_adr_base + 0x0000000c
  #define wdogintclr                                     (*(volatile unsigned int *)wdogintclr_adr)
  #define wdogris_adr                                    0x00329010                                                   // watchdog_adr_base + 0x00000010
  #define wdogris                                        (*(volatile unsigned int *)wdogris_adr)
  #define wdogmis_adr                                    0x00329014                                                   // watchdog_adr_base + 0x00000014
  #define wdogmis                                        (*(volatile unsigned int *)wdogmis_adr)
  #define wdoglock_adr                                   0x00329c00                                                   // watchdog_adr_base + 0x00000c00
  #define wdoglock                                       (*(volatile unsigned int *)wdoglock_adr)
  #define wdogitcr_adr                                   0x00329f00                                                   // watchdog_adr_base + 0x00000f00
  #define wdogitcr                                       (*(volatile unsigned int *)wdogitcr_adr)
  #define wdogitop_adr                                   0x00329f04                                                   // watchdog_adr_base + 0x00000f04
  #define wdogitop                                       (*(volatile unsigned int *)wdogitop_adr)
  #define wdogperiphid0_adr                              0x00329fe0                                                   // watchdog_adr_base + 0x00000fe0
  #define wdogperiphid0                                  (*(volatile unsigned int *)wdogperiphid0_adr)
  #define wdogperiphid1_adr                              0x00329fe4                                                   // watchdog_adr_base + 0x00000fe4
  #define wdogperiphid1                                  (*(volatile unsigned int *)wdogperiphid1_adr)
  #define wdogperiphid2_adr                              0x00329fe8                                                   // watchdog_adr_base + 0x00000fe8
  #define wdogperiphid2                                  (*(volatile unsigned int *)wdogperiphid2_adr)
  #define wdogperiphid3_adr                              0x00329fec                                                   // watchdog_adr_base + 0x00000fec
  #define wdogperiphid3                                  (*(volatile unsigned int *)wdogperiphid3_adr)
  #define wdogpcellid0_adr                               0x00329ff0                                                   // watchdog_adr_base + 0x00000ff0
  #define wdogpcellid0                                   (*(volatile unsigned int *)wdogpcellid0_adr)
  #define wdogpcellid1_adr                               0x00329ff4                                                   // watchdog_adr_base + 0x00000ff4
  #define wdogpcellid1                                   (*(volatile unsigned int *)wdogpcellid1_adr)
  #define wdogpcellid2_adr                               0x00329ff8                                                   // watchdog_adr_base + 0x00000ff8
  #define wdogpcellid2                                   (*(volatile unsigned int *)wdogpcellid2_adr)
  #define wdogpcellid3_adr                               0x00329ffc                                                   // watchdog_adr_base + 0x00000ffc
  #define wdogpcellid3                                   (*(volatile unsigned int *)wdogpcellid3_adr)
  #define timer1load_adr                                 0x0032a000                                                   // timers_adr_base + 0x00000000
  #define timer1load                                     (*(volatile unsigned int *)timer1load_adr)
  #define timer1value_adr                                0x0032a004                                                   // timers_adr_base + 0x00000004
  #define timer1value                                    (*(volatile unsigned int *)timer1value_adr)
  #define timer1control_adr                              0x0032a008                                                   // timers_adr_base + 0x00000008
  #define timer1control                                  (*(volatile unsigned int *)timer1control_adr)
  #define timer1intclr_adr                               0x0032a00c                                                   // timers_adr_base + 0x0000000c
  #define timer1intclr                                   (*(volatile unsigned int *)timer1intclr_adr)
  #define timer1ris_adr                                  0x0032a010                                                   // timers_adr_base + 0x00000010
  #define timer1ris                                      (*(volatile unsigned int *)timer1ris_adr)
  #define timer1mis_adr                                  0x0032a014                                                   // timers_adr_base + 0x00000014
  #define timer1mis                                      (*(volatile unsigned int *)timer1mis_adr)
  #define timer1bgload_adr                               0x0032a018                                                   // timers_adr_base + 0x00000018
  #define timer1bgload                                   (*(volatile unsigned int *)timer1bgload_adr)
  #define timer1test_adr                                 0x0032a01c                                                   // timers_adr_base + 0x0000001c
  #define timer1test                                     (*(volatile unsigned int *)timer1test_adr)
  #define timer2load_adr                                 0x0032a020                                                   // timers_adr_base + 0x00000020
  #define timer2load                                     (*(volatile unsigned int *)timer2load_adr)
  #define timer2value_adr                                0x0032a024                                                   // timers_adr_base + 0x00000024
  #define timer2value                                    (*(volatile unsigned int *)timer2value_adr)
  #define timer2control_adr                              0x0032a028                                                   // timers_adr_base + 0x00000028
  #define timer2control                                  (*(volatile unsigned int *)timer2control_adr)
  #define timer2intclr_adr                               0x0032a02c                                                   // timers_adr_base + 0x0000002c
  #define timer2intclr                                   (*(volatile unsigned int *)timer2intclr_adr)
  #define timer2ris_adr                                  0x0032a030                                                   // timers_adr_base + 0x00000030
  #define timer2ris                                      (*(volatile unsigned int *)timer2ris_adr)
  #define timer2mis_adr                                  0x0032a034                                                   // timers_adr_base + 0x00000034
  #define timer2mis                                      (*(volatile unsigned int *)timer2mis_adr)
  #define timer2bgload_adr                               0x0032a038                                                   // timers_adr_base + 0x00000038
  #define timer2bgload                                   (*(volatile unsigned int *)timer2bgload_adr)
  #define timer2test_adr                                 0x0032a03c                                                   // timers_adr_base + 0x0000003c
  #define timer2test                                     (*(volatile unsigned int *)timer2test_adr)
  #define timeritcr_adr                                  0x0032af00                                                   // timers_adr_base + 0x00000f00
  #define timeritcr                                      (*(volatile unsigned int *)timeritcr_adr)
  #define timeritop_adr                                  0x0032af04                                                   // timers_adr_base + 0x00000f04
  #define timeritop                                      (*(volatile unsigned int *)timeritop_adr)
  #define tperiphid0_adr                                 0x0032afe0                                                   // timers_adr_base + 0x00000fe0
  #define tperiphid0                                     (*(volatile unsigned int *)tperiphid0_adr)
  #define tperiphid1_adr                                 0x0032afe4                                                   // timers_adr_base + 0x00000fe4
  #define tperiphid1                                     (*(volatile unsigned int *)tperiphid1_adr)
  #define tperiphid2_adr                                 0x0032afe8                                                   // timers_adr_base + 0x00000fe8
  #define tperiphid2                                     (*(volatile unsigned int *)tperiphid2_adr)
  #define tperiphid3_adr                                 0x0032afec                                                   // timers_adr_base + 0x00000fec
  #define tperiphid3                                     (*(volatile unsigned int *)tperiphid3_adr)
  #define tpcellid0_adr                                  0x0032aff0                                                   // timers_adr_base + 0x00000ff0
  #define tpcellid0                                      (*(volatile unsigned int *)tpcellid0_adr)
  #define tpcellid1_adr                                  0x0032aff4                                                   // timers_adr_base + 0x00000ff4
  #define tpcellid1                                      (*(volatile unsigned int *)tpcellid1_adr)
  #define tpcellid2_adr                                  0x0032aff8                                                   // timers_adr_base + 0x00000ff8
  #define tpcellid2                                      (*(volatile unsigned int *)tpcellid2_adr)
  #define tpcellid3_adr                                  0x0032affc                                                   // timers_adr_base + 0x00000ffc
  #define tpcellid3                                      (*(volatile unsigned int *)tpcellid3_adr)
  #define gpio2data_adr                                  0x0032b000                                                   // gpio2_adr_base + 0x00000000
  #define gpio2data                                      (*(volatile unsigned int *)gpio2data_adr)
  #define gpio2dir_adr                                   0x0032b400                                                   // gpio2_adr_base + 0x00000400
  #define gpio2dir                                       (*(volatile unsigned int *)gpio2dir_adr)
  #define gpio2is_adr                                    0x0032b404                                                   // gpio2_adr_base + 0x00000404
  #define gpio2is                                        (*(volatile unsigned int *)gpio2is_adr)
  #define gpio2ibe_adr                                   0x0032b408                                                   // gpio2_adr_base + 0x00000408
  #define gpio2ibe                                       (*(volatile unsigned int *)gpio2ibe_adr)
  #define gpio2iev_adr                                   0x0032b40c                                                   // gpio2_adr_base + 0x0000040c
  #define gpio2iev                                       (*(volatile unsigned int *)gpio2iev_adr)
  #define gpio2ie_adr                                    0x0032b410                                                   // gpio2_adr_base + 0x00000410
  #define gpio2ie                                        (*(volatile unsigned int *)gpio2ie_adr)
  #define gpio2ris_adr                                   0x0032b414                                                   // gpio2_adr_base + 0x00000414
  #define gpio2ris                                       (*(volatile unsigned int *)gpio2ris_adr)
  #define gpio2mis_adr                                   0x0032b418                                                   // gpio2_adr_base + 0x00000418
  #define gpio2mis                                       (*(volatile unsigned int *)gpio2mis_adr)
  #define gpio2ic_adr                                    0x0032b41c                                                   // gpio2_adr_base + 0x0000041c
  #define gpio2ic                                        (*(volatile unsigned int *)gpio2ic_adr)
  #define gpio2afsel_adr                                 0x0032b420                                                   // gpio2_adr_base + 0x00000420
  #define gpio2afsel                                     (*(volatile unsigned int *)gpio2afsel_adr)
  #define gpio2itcr_adr                                  0x0032b600                                                   // gpio2_adr_base + 0x00000600
  #define gpio2itcr                                      (*(volatile unsigned int *)gpio2itcr_adr)
  #define gpio2itip1_adr                                 0x0032b604                                                   // gpio2_adr_base + 0x00000604
  #define gpio2itip1                                     (*(volatile unsigned int *)gpio2itip1_adr)
  #define gpio2itip2_adr                                 0x0032b608                                                   // gpio2_adr_base + 0x00000608
  #define gpio2itip2                                     (*(volatile unsigned int *)gpio2itip2_adr)
  #define gpio2itop1_adr                                 0x0032b60c                                                   // gpio2_adr_base + 0x0000060c
  #define gpio2itop1                                     (*(volatile unsigned int *)gpio2itop1_adr)
  #define gpio2itop2_adr                                 0x0032b610                                                   // gpio2_adr_base + 0x00000610
  #define gpio2itop2                                     (*(volatile unsigned int *)gpio2itop2_adr)
  #define gpio2itop3_adr                                 0x0032b614                                                   // gpio2_adr_base + 0x00000614
  #define gpio2itop3                                     (*(volatile unsigned int *)gpio2itop3_adr)
  #define gpio2periphid0_adr                             0x0032bfe0                                                   // gpio2_adr_base + 0x00000fe0
  #define gpio2periphid0                                 (*(volatile unsigned int *)gpio2periphid0_adr)
  #define gpio2periphid1_adr                             0x0032bfe4                                                   // gpio2_adr_base + 0x00000fe4
  #define gpio2periphid1                                 (*(volatile unsigned int *)gpio2periphid1_adr)
  #define gpio2periphid2_adr                             0x0032bfe8                                                   // gpio2_adr_base + 0x00000fe8
  #define gpio2periphid2                                 (*(volatile unsigned int *)gpio2periphid2_adr)
  #define gpio2periphid3_adr                             0x0032bfec                                                   // gpio2_adr_base + 0x00000fec
  #define gpio2periphid3                                 (*(volatile unsigned int *)gpio2periphid3_adr)
  #define gpio2pcellid0_adr                              0x0032bff0                                                   // gpio2_adr_base + 0x00000ff0
  #define gpio2pcellid0                                  (*(volatile unsigned int *)gpio2pcellid0_adr)
  #define gpio2pcellid1_adr                              0x0032bff4                                                   // gpio2_adr_base + 0x00000ff4
  #define gpio2pcellid1                                  (*(volatile unsigned int *)gpio2pcellid1_adr)
  #define gpio2pcellid2_adr                              0x0032bff8                                                   // gpio2_adr_base + 0x00000ff8
  #define gpio2pcellid2                                  (*(volatile unsigned int *)gpio2pcellid2_adr)
  #define gpio2pcellid3_adr                              0x0032bffc                                                   // gpio2_adr_base + 0x00000ffc
  #define gpio2pcellid3                                  (*(volatile unsigned int *)gpio2pcellid3_adr)
  #define gpiodata_adr                                   0x0032c000                                                   // gpio_adr_base + 0x00000000
  #define gpiodata                                       (*(volatile unsigned int *)gpiodata_adr)
  #define gpiodir_adr                                    0x0032c400                                                   // gpio_adr_base + 0x00000400
  #define gpiodir                                        (*(volatile unsigned int *)gpiodir_adr)
  #define gpiois_adr                                     0x0032c404                                                   // gpio_adr_base + 0x00000404
  #define gpiois                                         (*(volatile unsigned int *)gpiois_adr)
  #define gpioibe_adr                                    0x0032c408                                                   // gpio_adr_base + 0x00000408
  #define gpioibe                                        (*(volatile unsigned int *)gpioibe_adr)
  #define gpioiev_adr                                    0x0032c40c                                                   // gpio_adr_base + 0x0000040c
  #define gpioiev                                        (*(volatile unsigned int *)gpioiev_adr)
  #define gpioie_adr                                     0x0032c410                                                   // gpio_adr_base + 0x00000410
  #define gpioie                                         (*(volatile unsigned int *)gpioie_adr)
  #define gpioris_adr                                    0x0032c414                                                   // gpio_adr_base + 0x00000414
  #define gpioris                                        (*(volatile unsigned int *)gpioris_adr)
  #define gpiomis_adr                                    0x0032c418                                                   // gpio_adr_base + 0x00000418
  #define gpiomis                                        (*(volatile unsigned int *)gpiomis_adr)
  #define gpioic_adr                                     0x0032c41c                                                   // gpio_adr_base + 0x0000041c
  #define gpioic                                         (*(volatile unsigned int *)gpioic_adr)
  #define gpioafsel_adr                                  0x0032c420                                                   // gpio_adr_base + 0x00000420
  #define gpioafsel                                      (*(volatile unsigned int *)gpioafsel_adr)
  #define gpioitcr_adr                                   0x0032c600                                                   // gpio_adr_base + 0x00000600
  #define gpioitcr                                       (*(volatile unsigned int *)gpioitcr_adr)
  #define gpioitip1_adr                                  0x0032c604                                                   // gpio_adr_base + 0x00000604
  #define gpioitip1                                      (*(volatile unsigned int *)gpioitip1_adr)
  #define gpioitip2_adr                                  0x0032c608                                                   // gpio_adr_base + 0x00000608
  #define gpioitip2                                      (*(volatile unsigned int *)gpioitip2_adr)
  #define gpioitop1_adr                                  0x0032c60c                                                   // gpio_adr_base + 0x0000060c
  #define gpioitop1                                      (*(volatile unsigned int *)gpioitop1_adr)
  #define gpioitop2_adr                                  0x0032c610                                                   // gpio_adr_base + 0x00000610
  #define gpioitop2                                      (*(volatile unsigned int *)gpioitop2_adr)
  #define gpioitop3_adr                                  0x0032c614                                                   // gpio_adr_base + 0x00000614
  #define gpioitop3                                      (*(volatile unsigned int *)gpioitop3_adr)
  #define gpioperiphid0_adr                              0x0032cfe0                                                   // gpio_adr_base + 0x00000fe0
  #define gpioperiphid0                                  (*(volatile unsigned int *)gpioperiphid0_adr)
  #define gpioperiphid1_adr                              0x0032cfe4                                                   // gpio_adr_base + 0x00000fe4
  #define gpioperiphid1                                  (*(volatile unsigned int *)gpioperiphid1_adr)
  #define gpioperiphid2_adr                              0x0032cfe8                                                   // gpio_adr_base + 0x00000fe8
  #define gpioperiphid2                                  (*(volatile unsigned int *)gpioperiphid2_adr)
  #define gpioperiphid3_adr                              0x0032cfec                                                   // gpio_adr_base + 0x00000fec
  #define gpioperiphid3                                  (*(volatile unsigned int *)gpioperiphid3_adr)
  #define gpiopcellid0_adr                               0x0032cff0                                                   // gpio_adr_base + 0x00000ff0
  #define gpiopcellid0                                   (*(volatile unsigned int *)gpiopcellid0_adr)
  #define gpiopcellid1_adr                               0x0032cff4                                                   // gpio_adr_base + 0x00000ff4
  #define gpiopcellid1                                   (*(volatile unsigned int *)gpiopcellid1_adr)
  #define gpiopcellid2_adr                               0x0032cff8                                                   // gpio_adr_base + 0x00000ff8
  #define gpiopcellid2                                   (*(volatile unsigned int *)gpiopcellid2_adr)
  #define gpiopcellid3_adr                               0x0032cffc                                                   // gpio_adr_base + 0x00000ffc
  #define gpiopcellid3                                   (*(volatile unsigned int *)gpiopcellid3_adr)
  #define cr_clk_div_sel_adr                             0x00320000                                                   // pmu_adr_base + 0x00000000
  #define cr_clk_div_sel                                 (*(volatile unsigned int *)cr_clk_div_sel_adr)
  #define cr_clk_src_sel_adr                             0x00320004                                                   // pmu_adr_base + 0x00000004
  #define cr_clk_src_sel                                 (*(volatile unsigned int *)cr_clk_src_sel_adr)
  #define cr_clk_switch_adr                              0x00320008                                                   // pmu_adr_base + 0x00000008
  #define cr_clk_switch                                  (*(volatile unsigned int *)cr_clk_switch_adr)
  #define cr_xtal_lpo_div_adr                            0x0032000c                                                   // pmu_adr_base + 0x0000000c
  #define cr_xtal_lpo_div                                (*(volatile unsigned int *)cr_xtal_lpo_div_adr)
  #define cr_lpo_sel_adr                                 0x00320010                                                   // pmu_adr_base + 0x00000010
  #define cr_lpo_sel                                     (*(volatile unsigned int *)cr_lpo_sel_adr)
  #define cr_err_est_cnt_adr                             0x00320014                                                   // pmu_adr_base + 0x00000014
  #define cr_err_est_cnt                                 (*(volatile unsigned int *)cr_err_est_cnt_adr)
  #define cr_err_result_adr                              0x00320018                                                   // pmu_adr_base + 0x00000018
  #define cr_err_result                                  (*(volatile unsigned int *)cr_err_result_adr)
  #define cr_err_en_adr                                  0x0032001c                                                   // pmu_adr_base + 0x0000001c
  #define cr_err_en                                      (*(volatile unsigned int *)cr_err_en_adr)
  #define cr_sleep_cnt_adr                               0x00320020                                                   // pmu_adr_base + 0x00000020
  #define cr_sleep_cnt                                   (*(volatile unsigned int *)cr_sleep_cnt_adr)
  #define cr_warmup_cnt_adr                              0x00320024                                                   // pmu_adr_base + 0x00000024
  #define cr_warmup_cnt                                  (*(volatile unsigned int *)cr_warmup_cnt_adr)
  #define cr_sleep_en_adr                                0x00320028                                                   // pmu_adr_base + 0x00000028
  #define cr_sleep_en                                    (*(volatile unsigned int *)cr_sleep_en_adr)
  #define cr_sleep_remain_adr                            0x0032002c                                                   // pmu_adr_base + 0x0000002c
  #define cr_sleep_remain                                (*(volatile unsigned int *)cr_sleep_remain_adr)
  #define version_adr                                    0x00320030                                                   // pmu_adr_base + 0x00000030
  #define version                                        (*(volatile unsigned int *)version_adr)
  #define xtal_strap_adr                                 0x00320034                                                   // pmu_adr_base + 0x00000034
  #define xtal_strap                                     (*(volatile unsigned int *)xtal_strap_adr)
  #define cr_rpu_gate_ctl_adr                            0x00320038                                                   // pmu_adr_base + 0x00000038
  #define cr_rpu_gate_ctl                                (*(volatile unsigned int *)cr_rpu_gate_ctl_adr)
  #define cr_mem_stby_ctl_adr0                           0x0032003c                                                   // pmu_adr_base + 0x0000003c
  #define cr_mem_stby_ctl0                               (*(volatile unsigned int *)cr_mem_stby_ctl_adr0)
  #define cr_xtal_1m_int_adr                             0x00320040                                                   // pmu_adr_base + 0x00000040
  #define cr_xtal_1m_int                                 (*(volatile unsigned int *)cr_xtal_1m_int_adr)
  #define cr_xtal_1m_frac_adr                            0x00320044                                                   // pmu_adr_base + 0x00000044
  #define cr_xtal_1m_frac                                (*(volatile unsigned int *)cr_xtal_1m_frac_adr)
  #define cr_i2c_pump_adr                                0x00320048                                                   // pmu_adr_base + 0x00000048
  #define cr_i2c_pump                                    (*(volatile unsigned int *)cr_i2c_pump_adr)
  #define sr_warmup_remain_adr                           0x0032004c                                                   // pmu_adr_base + 0x0000004c
  #define sr_warmup_remain                               (*(volatile unsigned int *)sr_warmup_remain_adr)
  #define sr_clk_status_adr                              0x00320050                                                   // pmu_adr_base + 0x00000050
  #define sr_clk_status                                  (*(volatile unsigned int *)sr_clk_status_adr)
  #define cr_lpo_timer_adr                               0x00320054                                                   // pmu_adr_base + 0x00000054
  #define cr_lpo_timer                                   (*(volatile unsigned int *)cr_lpo_timer_adr)
  #define cr_wake_int_en_adr                             0x00320058                                                   // pmu_adr_base + 0x00000058
  #define cr_wake_int_en                                 (*(volatile unsigned int *)cr_wake_int_en_adr)
  #define cr_pulse_reset_adr                             0x0032005c                                                   // pmu_adr_base + 0x0000005c
  #define cr_pulse_reset                                 (*(volatile unsigned int *)cr_pulse_reset_adr)
  #define cr_level_reset_adr                             0x00320060                                                   // pmu_adr_base + 0x00000060
  #define cr_level_reset                                 (*(volatile unsigned int *)cr_level_reset_adr)
  #define cr_mem_ctl_adr                                 0x00320064                                                   // pmu_adr_base + 0x00000064
  #define cr_mem_ctl                                     (*(volatile unsigned int *)cr_mem_ctl_adr)
  #define cr_pad_config_adr0                             0x00320068                                                   // pmu_adr_base + 0x00000068
  #define cr_pad_config0                                 (*(volatile unsigned int *)cr_pad_config_adr0)
  #define cr_pad_config_adr1                             0x0032006c                                                   // pmu_adr_base + 0x0000006c
  #define cr_pad_config1                                 (*(volatile unsigned int *)cr_pad_config_adr1)
  #define cr_pad_config_adr2                             0x00320070                                                   // pmu_adr_base + 0x00000070
  #define cr_pad_config2                                 (*(volatile unsigned int *)cr_pad_config_adr2)
  #define cr_pad_config_adr3                             0x00320074                                                   // pmu_adr_base + 0x00000074
  #define cr_pad_config3                                 (*(volatile unsigned int *)cr_pad_config_adr3)
  #define cr_pad_config_adr4                             0x00320078                                                   // pmu_adr_base + 0x00000078
  #define cr_pad_config4                                 (*(volatile unsigned int *)cr_pad_config_adr4)
  #define cr_pad_config_adr5                             0x0032007c                                                   // pmu_adr_base + 0x0000007c
  #define cr_pad_config5                                 (*(volatile unsigned int *)cr_pad_config_adr5)
  #define cr_pad_config_adr6                             0x00320080                                                   // pmu_adr_base + 0x00000080
  #define cr_pad_config6                                 (*(volatile unsigned int *)cr_pad_config_adr6)
  #define cr_pad_dbg_ctl_adr                             0x00320084                                                   // pmu_adr_base + 0x00000084
  #define cr_pad_dbg_ctl                                 (*(volatile unsigned int *)cr_pad_dbg_ctl_adr)
  #define cr_pad_fcn_ctl_adr0                            0x00320088                                                   // pmu_adr_base + 0x00000088
  #define cr_pad_fcn_ctl0                                (*(volatile unsigned int *)cr_pad_fcn_ctl_adr0)
  #define cr_pad_fcn_ctl_adr1                            0x0032008c                                                   // pmu_adr_base + 0x0000008c
  #define cr_pad_fcn_ctl1                                (*(volatile unsigned int *)cr_pad_fcn_ctl_adr1)
  #define cr_pad_fcn_ctl_adr2                            0x00320090                                                   // pmu_adr_base + 0x00000090
  #define cr_pad_fcn_ctl2                                (*(volatile unsigned int *)cr_pad_fcn_ctl_adr2)
  #define cr_ptu_clk_en_adr                              0x00320094                                                   // pmu_adr_base + 0x00000094
  #define cr_ptu_clk_en                                  (*(volatile unsigned int *)cr_ptu_clk_en_adr)
  #define cr_bpl_upi_gate_ctl_adr                        0x00320098                                                   // pmu_adr_base + 0x00000098
  #define cr_bpl_upi_gate_ctl                            (*(volatile unsigned int *)cr_bpl_upi_gate_ctl_adr)
  #define cr_pll_wrmup_cnt_adr                           0x0032009c                                                   // pmu_adr_base + 0x0000009c
  #define cr_pll_wrmup_cnt                               (*(volatile unsigned int *)cr_pll_wrmup_cnt_adr)
  #define cr_sdio_clk_sel_adr                            0x003200a0                                                   // pmu_adr_base + 0x000000a0
  #define cr_sdio_clk_sel                                (*(volatile unsigned int *)cr_sdio_clk_sel_adr)
  #define cr_pwr_ctl_adr                                 0x003200a4                                                   // pmu_adr_base + 0x000000a4
  #define cr_pwr_ctl                                     (*(volatile unsigned int *)cr_pwr_ctl_adr)
  #define cr_mem_ovst_ctl_adr                            0x003200a8                                                   // pmu_adr_base + 0x000000a8
  #define cr_mem_ovst_ctl                                (*(volatile unsigned int *)cr_mem_ovst_ctl_adr)
  #define cr_xtal_buf_dly_byp_adr                        0x003200ac                                                   // pmu_adr_base + 0x000000ac
  #define cr_xtal_buf_dly_byp                            (*(volatile unsigned int *)cr_xtal_buf_dly_byp_adr)
  #define cr_lpo_tim_ctl_adr                             0x003200b0                                                   // pmu_adr_base + 0x000000b0
  #define cr_lpo_tim_ctl                                 (*(volatile unsigned int *)cr_lpo_tim_ctl_adr)
  #define cr_tport_clk_sel_adr                           0x003200b4                                                   // pmu_adr_base + 0x000000b4
  #define cr_tport_clk_sel                               (*(volatile unsigned int *)cr_tport_clk_sel_adr)
  #define cr_ptu_clk_gate_on_adr                         0x003200b8                                                   // pmu_adr_base + 0x000000b8
  #define cr_ptu_clk_gate_on                             (*(volatile unsigned int *)cr_ptu_clk_gate_on_adr)
  #define cr_ptu_clk_gate_off_adr                        0x003200bc                                                   // pmu_adr_base + 0x000000bc
  #define cr_ptu_clk_gate_off                            (*(volatile unsigned int *)cr_ptu_clk_gate_off_adr)
  #define sr_pmu_status_adr                              0x003200c0                                                   // pmu_adr_base + 0x000000c0
  #define sr_pmu_status                                  (*(volatile unsigned int *)sr_pmu_status_adr)
  #define sr_pmu_en_adr                                  0x003200c4                                                   // pmu_adr_base + 0x000000c4
  #define sr_pmu_en                                      (*(volatile unsigned int *)sr_pmu_en_adr)
  #define sr_pmu_sdis_adr                                0x003200c8                                                   // pmu_adr_base + 0x000000c8
  #define sr_pmu_sdis                                    (*(volatile unsigned int *)sr_pmu_sdis_adr)
  #define fm_sleep_cnt_adr                               0x003200cc                                                   // pmu_adr_base + 0x000000cc
  #define fm_sleep_cnt                                   (*(volatile unsigned int *)fm_sleep_cnt_adr)
  #define fm_warn_cnt_adr                                0x003200d0                                                   // pmu_adr_base + 0x000000d0
  #define fm_warn_cnt                                    (*(volatile unsigned int *)fm_warn_cnt_adr)
  #define cr_wake_int_en_4_adr                           0x003200d4                                                   // pmu_adr_base + 0x000000d4
  #define cr_wake_int_en_4                               (*(volatile unsigned int *)cr_wake_int_en_4_adr)
  #define fm_warmup_cnt_adr                              0x003200d8                                                   // pmu_adr_base + 0x000000d8
  #define fm_warmup_cnt                                  (*(volatile unsigned int *)fm_warmup_cnt_adr)
  #define cr_mtu_clk_en_adr                              0x003200dc                                                   // pmu_adr_base + 0x000000dc
  #define cr_mtu_clk_en                                  (*(volatile unsigned int *)cr_mtu_clk_en_adr)
  #define cr_clk_req_cfg_adr                             0x003200e0                                                   // pmu_adr_base + 0x000000e0
  #define cr_clk_req_cfg                                 (*(volatile unsigned int *)cr_clk_req_cfg_adr)
  #define cr_pad_config_adr7                             0x003200e4                                                   // pmu_adr_base + 0x000000e4
  #define cr_pad_config7                                 (*(volatile unsigned int *)cr_pad_config_adr7)
  #define fm_sleep_en_adr                                0x003200e8                                                   // pmu_adr_base + 0x000000e8
  #define fm_sleep_en                                    (*(volatile unsigned int *)fm_sleep_en_adr)
  #define fm_sleep_remain_adr                            0x003200ec                                                   // pmu_adr_base + 0x000000ec
  #define fm_sleep_remain                                (*(volatile unsigned int *)fm_sleep_remain_adr)
  #define cr_mem_tm_ctl_adr                              0x003200f0                                                   // pmu_adr_base + 0x000000f0
  #define cr_mem_tm_ctl                                  (*(volatile unsigned int *)cr_mem_tm_ctl_adr)
  #define cr_mem_stby_ctl_adr1                           0x003200f4                                                   // pmu_adr_base + 0x000000f4
  #define cr_mem_stby_ctl1                               (*(volatile unsigned int *)cr_mem_stby_ctl_adr1)
  #define cr_wake_int_en_2_adr                           0x003200f8                                                   // pmu_adr_base + 0x000000f8
  #define cr_wake_int_en_2                               (*(volatile unsigned int *)cr_wake_int_en_2_adr)
  #define cr_buf_wrmup_cnt_adr                           0x003200fc                                                   // pmu_adr_base + 0x000000fc
  #define cr_buf_wrmup_cnt                               (*(volatile unsigned int *)cr_buf_wrmup_cnt_adr)
  #define cr_pulse_reset_peri_adr                        0x00320100                                                   // pmu_adr_base + 0x00000100
  #define cr_pulse_reset_peri                            (*(volatile unsigned int *)cr_pulse_reset_peri_adr)
  #define cr_level_reset_peri_adr                        0x00320104                                                   // pmu_adr_base + 0x00000104
  #define cr_level_reset_peri                            (*(volatile unsigned int *)cr_level_reset_peri_adr)
  #define fm_hclk_fm_on_adr                              0x00320108                                                   // pmu_adr_base + 0x00000108
  #define fm_hclk_fm_on                                  (*(volatile unsigned int *)fm_hclk_fm_on_adr)
  #define cr_pad_config_adr8                             0x00320110                                                   // pmu_adr_base + 0x00000110
  #define cr_pad_config8                                 (*(volatile unsigned int *)cr_pad_config_adr8)
  #define cr_mem_stby_ctl_adr2                           0x00320114                                                   // pmu_adr_base + 0x00000114
  #define cr_mem_stby_ctl2                               (*(volatile unsigned int *)cr_mem_stby_ctl_adr2)
  #define cr_mem_stby_ctl_adr3                           0x00320118                                                   // pmu_adr_base + 0x00000118
  #define cr_mem_stby_ctl3                               (*(volatile unsigned int *)cr_mem_stby_ctl_adr3)
  #define cr_ns_clk_ctl_adr                              0x0032010c                                                   // pmu_adr_base + 0x0000010c
  #define cr_ns_clk_ctl                                  (*(volatile unsigned int *)cr_ns_clk_ctl_adr)
  #define cr_iic_clk_sel_adr                             0x003201bc                                                   // pmu_adr_base + 0x000001bc
  #define cr_iic_clk_sel                                 (*(volatile unsigned int *)cr_iic_clk_sel_adr)
  #define cr_smux_ctl_adr0                               0x0032011c                                                   // pmu_adr_base + 0x0000011c
  #define cr_smux_ctl0                                   (*(volatile unsigned int *)cr_smux_ctl_adr0)
  #define cr_smux_ctl_adr1                               0x00320120                                                   // pmu_adr_base + 0x00000120
  #define cr_smux_ctl1                                   (*(volatile unsigned int *)cr_smux_ctl_adr1)
  #define cr_smux_ctl_adr2                               0x00320124                                                   // pmu_adr_base + 0x00000124
  #define cr_smux_ctl2                                   (*(volatile unsigned int *)cr_smux_ctl_adr2)
  #define cr_smux_ctl_adr3                               0x00320128                                                   // pmu_adr_base + 0x00000128
  #define cr_smux_ctl3                                   (*(volatile unsigned int *)cr_smux_ctl_adr3)
  #define cr_smux_ctl_adr4                               0x0032012c                                                   // pmu_adr_base + 0x0000012c
  #define cr_smux_ctl4                                   (*(volatile unsigned int *)cr_smux_ctl_adr4)
  #define cr_smux_ctl_adr5                               0x00320130                                                   // pmu_adr_base + 0x00000130
  #define cr_smux_ctl5                                   (*(volatile unsigned int *)cr_smux_ctl_adr5)
  #define cr_smux_ctl_adr8                               0x00320134                                                   // pmu_adr_base + 0x00000134
  #define cr_smux_ctl8                                   (*(volatile unsigned int *)cr_smux_ctl_adr8)
  #define cr_smux_ctl_adr10                              0x00320154                                                   // pmu_adr_base + 0x00000154
  #define cr_smux_ctl10                                  (*(volatile unsigned int *)cr_smux_ctl_adr10)
  #define cr_smux_ctl_adr6                               0x00320138                                                   // pmu_adr_base + 0x00000138
  #define cr_smux_ctl6                                   (*(volatile unsigned int *)cr_smux_ctl_adr6)
  #define cr_smux_ctl_adr7                               0x0032013c                                                   // pmu_adr_base + 0x0000013c
  #define cr_smux_ctl7                                   (*(volatile unsigned int *)cr_smux_ctl_adr7)
  #define cr_smux_ctl_adr9                               0x00320150                                                   // pmu_adr_base + 0x00000150
  #define cr_smux_ctl9                                   (*(volatile unsigned int *)cr_smux_ctl_adr9)
  #define cr_err_ovr_val_adr                             0x00320140                                                   // pmu_adr_base + 0x00000140
  #define cr_err_ovr_val                                 (*(volatile unsigned int *)cr_err_ovr_val_adr)
  #define cr_err_format_adr                              0x00320144                                                   // pmu_adr_base + 0x00000144
  #define cr_err_format                                  (*(volatile unsigned int *)cr_err_format_adr)
  #define cr_sleep_slots_adr                             0x00320148                                                   // pmu_adr_base + 0x00000148
  #define cr_sleep_slots                                 (*(volatile unsigned int *)cr_sleep_slots_adr)
  #define cr_dap_clk_sel_adr                             0x0032014c                                                   // pmu_adr_base + 0x0000014c
  #define cr_dap_clk_sel                                 (*(volatile unsigned int *)cr_dap_clk_sel_adr)
  #define cr_jtmode_status_adr                           0x00320180                                                   // pmu_adr_base + 0x00000180
  #define cr_jtmode_status                               (*(volatile unsigned int *)cr_jtmode_status_adr)
  #define cr_smuxo_inv_adr                               0x00320158                                                   // pmu_adr_base + 0x00000158
  #define cr_smuxo_inv                                   (*(volatile unsigned int *)cr_smuxo_inv_adr)
  #define cr_dmp_wr_ptr_adr                              0x00320160                                                   // pmu_adr_base + 0x00000160
  #define cr_dmp_wr_ptr                                  (*(volatile unsigned int *)cr_dmp_wr_ptr_adr)
  #define cr_dmp_rd_ptr_status_adr                       0x00320164                                                   // pmu_adr_base + 0x00000164
  #define cr_dmp_rd_ptr_status                           (*(volatile unsigned int *)cr_dmp_rd_ptr_status_adr)
  #define cr_dmp_p2s_config_adr                          0x00320168                                                   // pmu_adr_base + 0x00000168
  #define cr_dmp_p2s_config                              (*(volatile unsigned int *)cr_dmp_p2s_config_adr)
  #define cr_dmp_mem_adr                                 0x00320200                                                   // pmu_adr_base + 0x00000200
  #define cr_dmp_mem                                     (*(volatile unsigned int *)cr_dmp_mem_adr)
  #define cr_aes_clk_cfg_adr                             0x0032016c                                                   // pmu_adr_base + 0x0000016c
  #define cr_aes_clk_cfg                                 (*(volatile unsigned int *)cr_aes_clk_cfg_adr)
  #define epm_flash_pad_ctl_adr                          0x00320170                                                   // pmu_adr_base + 0x00000170
  #define epm_flash_pad_ctl                              (*(volatile unsigned int *)epm_flash_pad_ctl_adr)
  #define cr_pad_config_slim_adr                         0x00320174                                                   // pmu_adr_base + 0x00000174
  #define cr_pad_config_slim                             (*(volatile unsigned int *)cr_pad_config_slim_adr)
  #define cr_fmrc_count_adr                              0x00320178                                                   // pmu_adr_base + 0x00000178
  #define cr_fmrc_count                                  (*(volatile unsigned int *)cr_fmrc_count_adr)
  #define cr_fm_xtal_ctl_adr                             0x0032017c                                                   // pmu_adr_base + 0x0000017c
  #define cr_fm_xtal_ctl                                 (*(volatile unsigned int *)cr_fm_xtal_ctl_adr)
  #define cr_pad_config_src_adr                          0x0032015c                                                   // pmu_adr_base + 0x0000015c
  #define cr_pad_config_src                              (*(volatile unsigned int *)cr_pad_config_src_adr)
  #define bgldo_adr                                      0x00320184                                                   // pmu_adr_base + 0x00000184
  #define bgldo                                          (*(volatile unsigned int *)bgldo_adr)
  #define hvldo_adr                                      0x00320188                                                   // pmu_adr_base + 0x00000188
  #define hvldo                                          (*(volatile unsigned int *)hvldo_adr)
  #define lpldo_adr                                      0x0032018c                                                   // pmu_adr_base + 0x0000018c
  #define lpldo                                          (*(volatile unsigned int *)lpldo_adr)
  #define btldo_adr                                      0x00320190                                                   // pmu_adr_base + 0x00000190
  #define btldo                                          (*(volatile unsigned int *)btldo_adr)
  #define auxldo_adr                                     0x00320194                                                   // pmu_adr_base + 0x00000194
  #define auxldo                                         (*(volatile unsigned int *)auxldo_adr)
  #define gpsldo_adr                                     0x00320198                                                   // pmu_adr_base + 0x00000198
  #define gpsldo                                         (*(volatile unsigned int *)gpsldo_adr)
  #define gpsrfldo_adr                                   0x0032019c                                                   // pmu_adr_base + 0x0000019c
  #define gpsrfldo                                       (*(volatile unsigned int *)gpsrfldo_adr)
  #define cr_spi_clk_sel_adr                             0x003201a0                                                   // pmu_adr_base + 0x000001a0
  #define cr_spi_clk_sel                                 (*(volatile unsigned int *)cr_spi_clk_sel_adr)
  #define cr_pad_config_adr9                             0x003201a4                                                   // pmu_adr_base + 0x000001a4
  #define cr_pad_config9                                 (*(volatile unsigned int *)cr_pad_config_adr9)
  #define cr_pad_fcn_ctl_adr3                            0x003201a8                                                   // pmu_adr_base + 0x000001a8
  #define cr_pad_fcn_ctl3                                (*(volatile unsigned int *)cr_pad_fcn_ctl_adr3)
  #define cr_pad_config_adr10                            0x003201ac                                                   // pmu_adr_base + 0x000001ac
  #define cr_pad_config10                                (*(volatile unsigned int *)cr_pad_config_adr10)
  #define cr_pad_config_adr11                            0x003201b0                                                   // pmu_adr_base + 0x000001b0
  #define cr_pad_config11                                (*(volatile unsigned int *)cr_pad_config_adr11)
  #define cr_pad_config_adr12                            0x003201b4                                                   // pmu_adr_base + 0x000001b4
  #define cr_pad_config12                                (*(volatile unsigned int *)cr_pad_config_adr12)
  #define cr_pad_fcn_ctl_adr4                            0x003201b8                                                   // pmu_adr_base + 0x000001b8
  #define cr_pad_fcn_ctl4                                (*(volatile unsigned int *)cr_pad_fcn_ctl_adr4)
  #define cr_mem_stby_ctl_adr4                           0x003201c0                                                   // pmu_adr_base + 0x000001c0
  #define cr_mem_stby_ctl4                               (*(volatile unsigned int *)cr_mem_stby_ctl_adr4)
  #define iso_cntl_adr                                   0x003201c4                                                   // pmu_adr_base + 0x000001c4
  #define iso_cntl                                       (*(volatile unsigned int *)iso_cntl_adr)
  #define bgldo_sleepcntl_adr                            0x003201c8                                                   // pmu_adr_base + 0x000001c8
  #define bgldo_sleepcntl                                (*(volatile unsigned int *)bgldo_sleepcntl_adr)
  #define hvldo_sleepcntl_adr                            0x003201cc                                                   // pmu_adr_base + 0x000001cc
  #define hvldo_sleepcntl                                (*(volatile unsigned int *)hvldo_sleepcntl_adr)
  #define lpldo_sleepcntl_adr                            0x003201d0                                                   // pmu_adr_base + 0x000001d0
  #define lpldo_sleepcntl                                (*(volatile unsigned int *)lpldo_sleepcntl_adr)
  #define btldo_sleepcntl_adr                            0x003201d4                                                   // pmu_adr_base + 0x000001d4
  #define btldo_sleepcntl                                (*(volatile unsigned int *)btldo_sleepcntl_adr)
  #define ldo_cntl_enable_adr                            0x003201d8                                                   // pmu_adr_base + 0x000001d8
  #define ldo_cntl_enable                                (*(volatile unsigned int *)ldo_cntl_enable_adr)
  #define otp_stby_mode_adr                              0x003201dc                                                   // pmu_adr_base + 0x000001dc
  #define otp_stby_mode                                  (*(volatile unsigned int *)otp_stby_mode_adr)
  #define cr_ptu_sda_adr                                 0x003201e0                                                   // pmu_adr_base + 0x000001e0
  #define cr_ptu_sda                                     (*(volatile unsigned int *)cr_ptu_sda_adr)
  #define cr_tcxo_buf_warmup_cnt_adr                     0x003201e4                                                   // pmu_adr_base + 0x000001e4
  #define cr_tcxo_buf_warmup_cnt                         (*(volatile unsigned int *)cr_tcxo_buf_warmup_cnt_adr)
  #define cr_xo_tcxo_force_pd_adr                        0x003201e8                                                   // pmu_adr_base + 0x000001e8
  #define cr_xo_tcxo_force_pd                            (*(volatile unsigned int *)cr_xo_tcxo_force_pd_adr)
  #define cr_tport2_clk_sel_adr                          0x003201ec                                                   // pmu_adr_base + 0x000001ec
  #define cr_tport2_clk_sel                              (*(volatile unsigned int *)cr_tport2_clk_sel_adr)
  #define temp_adc_indadr_adr                            0x003201f0                                                   // pmu_adr_base + 0x000001f0
  #define temp_adc_indadr                                (*(volatile unsigned int *)temp_adc_indadr_adr)
  #define temp_adc_rdata_adr                             0x003201f4                                                   // pmu_adr_base + 0x000001f4
  #define temp_adc_rdata                                 (*(volatile unsigned int *)temp_adc_rdata_adr)
  #define temp_adc_wdata_adr                             0x003201f8                                                   // pmu_adr_base + 0x000001f8
  #define temp_adc_wdata                                 (*(volatile unsigned int *)temp_adc_wdata_adr)
  #define wlan_mem_sel_adr                               0x003201fc                                                   // pmu_adr_base + 0x000001fc
  #define wlan_mem_sel                                   (*(volatile unsigned int *)wlan_mem_sel_adr)
  #define gps_mem_sel_adr                                0x00320204                                                   // pmu_adr_base + 0x00000204
  #define gps_mem_sel                                    (*(volatile unsigned int *)gps_mem_sel_adr)
  #define nfc_scratch_pad1_adr                           0x00320208                                                   // pmu_adr_base + 0x00000208
  #define nfc_scratch_pad1                               (*(volatile unsigned int *)nfc_scratch_pad1_adr)
  #define nfc_scratch_pad2_adr                           0x0032020c                                                   // pmu_adr_base + 0x0000020c
  #define nfc_scratch_pad2                               (*(volatile unsigned int *)nfc_scratch_pad2_adr)
  #define nfc_scratch_pad3_adr                           0x00320210                                                   // pmu_adr_base + 0x00000210
  #define nfc_scratch_pad3                               (*(volatile unsigned int *)nfc_scratch_pad3_adr)
  #define nfc_scratch_pad4_adr                           0x00320214                                                   // pmu_adr_base + 0x00000214
  #define nfc_scratch_pad4                               (*(volatile unsigned int *)nfc_scratch_pad4_adr)
  #define cr_gci_clk_sel_adr                             0x00320220                                                   // pmu_adr_base + 0x00000220
  #define cr_gci_clk_sel                                 (*(volatile unsigned int *)cr_gci_clk_sel_adr)
  #define cr_mia_clk_cfg_adr                             0x00320230                                                   // pmu_adr_base + 0x00000230
  #define cr_mia_clk_cfg                                 (*(volatile unsigned int *)cr_mia_clk_cfg_adr)
  #define cr_mstr_sleep_sel_adr                          0x00320400                                                   // pmu_adr_base + 0x00000400
  #define cr_mstr_sleep_sel                              (*(volatile unsigned int *)cr_mstr_sleep_sel_adr)
  #define cr_ifpll_on_adr                                0x00320404                                                   // pmu_adr_base + 0x00000404
  #define cr_ifpll_on                                    (*(volatile unsigned int *)cr_ifpll_on_adr)
  #define cr_rpu_1m_div_adr                              0x00320408                                                   // pmu_adr_base + 0x00000408
  #define cr_rpu_1m_div                                  (*(volatile unsigned int *)cr_rpu_1m_div_adr)
  #define cr_rpu_rpu_div_adr                             0x0032040c                                                   // pmu_adr_base + 0x0000040c
  #define cr_rpu_rpu_div                                 (*(volatile unsigned int *)cr_rpu_rpu_div_adr)
  #define cr_rpu_pause_div_adr                           0x00320410                                                   // pmu_adr_base + 0x00000410
  #define cr_rpu_pause_div                               (*(volatile unsigned int *)cr_rpu_pause_div_adr)
  #define cr_rpu_fast_pause_div_adr                      0x00320414                                                   // pmu_adr_base + 0x00000414
  #define cr_rpu_fast_pause_div                          (*(volatile unsigned int *)cr_rpu_fast_pause_div_adr)
  #define cr_rpu_wake_config_adr                         0x00320418                                                   // pmu_adr_base + 0x00000418
  #define cr_rpu_wake_config                             (*(volatile unsigned int *)cr_rpu_wake_config_adr)
  #define cr_rpu_sleep_en_adr                            0x0032041c                                                   // pmu_adr_base + 0x0000041c
  #define cr_rpu_sleep_en                                (*(volatile unsigned int *)cr_rpu_sleep_en_adr)
  #define cr_rpu_warmup_cnt_adr                          0x00320420                                                   // pmu_adr_base + 0x00000420
  #define cr_rpu_warmup_cnt                              (*(volatile unsigned int *)cr_rpu_warmup_cnt_adr)
  #define cr_rpu_pllwarm_cnt_adr                         0x00320424                                                   // pmu_adr_base + 0x00000424
  #define cr_rpu_pllwarm_cnt                             (*(volatile unsigned int *)cr_rpu_pllwarm_cnt_adr)
  #define cr_rpu_sleep_cnt_adr                           0x00320428                                                   // pmu_adr_base + 0x00000428
  #define cr_rpu_sleep_cnt                               (*(volatile unsigned int *)cr_rpu_sleep_cnt_adr)
  #define cr_rpu_sleep_slots_adr                         0x0032042c                                                   // pmu_adr_base + 0x0000042c
  #define cr_rpu_sleep_slots                             (*(volatile unsigned int *)cr_rpu_sleep_slots_adr)
  #define cr_rpu_N_div_adr                               0x00320430                                                   // pmu_adr_base + 0x00000430
  #define cr_rpu_N_div                                   (*(volatile unsigned int *)cr_rpu_N_div_adr)
  #define cr_rpu_M_div_adr                               0x00320434                                                   // pmu_adr_base + 0x00000434
  #define cr_rpu_M_div                                   (*(volatile unsigned int *)cr_rpu_M_div_adr)
  #define cr_rpu_div_en_adr                              0x00320438                                                   // pmu_adr_base + 0x00000438
  #define cr_rpu_div_en                                  (*(volatile unsigned int *)cr_rpu_div_en_adr)
  #define cr_rpu_div_update_adr                          0x0032043c                                                   // pmu_adr_base + 0x0000043c
  #define cr_rpu_div_update                              (*(volatile unsigned int *)cr_rpu_div_update_adr)
  #define cr_rpu_divMN_force_adr                         0x00320440                                                   // pmu_adr_base + 0x00000440
  #define cr_rpu_divMN_force                             (*(volatile unsigned int *)cr_rpu_divMN_force_adr)
  #define cr_bt_N_div_adr                                0x00320444                                                   // pmu_adr_base + 0x00000444
  #define cr_bt_N_div                                    (*(volatile unsigned int *)cr_bt_N_div_adr)
  #define cr_bt_M_div_adr                                0x00320448                                                   // pmu_adr_base + 0x00000448
  #define cr_bt_M_div                                    (*(volatile unsigned int *)cr_bt_M_div_adr)
  #define cr_bt_div_en_adr                               0x0032044c                                                   // pmu_adr_base + 0x0000044c
  #define cr_bt_div_en                                   (*(volatile unsigned int *)cr_bt_div_en_adr)
  #define cr_bt_div_update_adr                           0x00320450                                                   // pmu_adr_base + 0x00000450
  #define cr_bt_div_update                               (*(volatile unsigned int *)cr_bt_div_update_adr)
  #define cr_slim_src_sel_adr                            0x00320454                                                   // pmu_adr_base + 0x00000454
  #define cr_slim_src_sel                                (*(volatile unsigned int *)cr_slim_src_sel_adr)
  #define cr_slim_clk_en_adr                             0x00320458                                                   // pmu_adr_base + 0x00000458
  #define cr_slim_clk_en                                 (*(volatile unsigned int *)cr_slim_clk_en_adr)
  #define cr_ptu_N_div_adr                               0x0032045c                                                   // pmu_adr_base + 0x0000045c
  #define cr_ptu_N_div                                   (*(volatile unsigned int *)cr_ptu_N_div_adr)
  #define cr_ptu_M_div_adr                               0x00320460                                                   // pmu_adr_base + 0x00000460
  #define cr_ptu_M_div                                   (*(volatile unsigned int *)cr_ptu_M_div_adr)
  #define cr_ptu_div_en_adr                              0x00320464                                                   // pmu_adr_base + 0x00000464
  #define cr_ptu_div_en                                  (*(volatile unsigned int *)cr_ptu_div_en_adr)
  #define cr_ptu_div_update_adr                          0x00320468                                                   // pmu_adr_base + 0x00000468
  #define cr_ptu_div_update                              (*(volatile unsigned int *)cr_ptu_div_update_adr)
  #define gps_sleep_en_adr                               0x0032046c                                                   // pmu_adr_base + 0x0000046c
  #define gps_sleep_en                                   (*(volatile unsigned int *)gps_sleep_en_adr)
  #define gps_sleep_cnt_adr                              0x00320470                                                   // pmu_adr_base + 0x00000470
  #define gps_sleep_cnt                                  (*(volatile unsigned int *)gps_sleep_cnt_adr)
  #define gps_sleep_remain_adr                           0x00320474                                                   // pmu_adr_base + 0x00000474
  #define gps_sleep_remain                               (*(volatile unsigned int *)gps_sleep_remain_adr)
  #define cr_tsxo_adc_cntl_adr                           0x00320478                                                   // pmu_adr_base + 0x00000478
  #define cr_tsxo_adc_cntl                               (*(volatile unsigned int *)cr_tsxo_adc_cntl_adr)
  #define sr_rpu_sleep_remain0_adr                       0x0032047c                                                   // pmu_adr_base + 0x0000047c
  #define sr_rpu_sleep_remain0                           (*(volatile unsigned int *)sr_rpu_sleep_remain0_adr)
  #define sr_rpu_sleep_remain1_adr                       0x00320480                                                   // pmu_adr_base + 0x00000480
  #define sr_rpu_sleep_remain1                           (*(volatile unsigned int *)sr_rpu_sleep_remain1_adr)
  #define cr_hv3_warm_cnt_adr                            0x00320484                                                   // pmu_adr_base + 0x00000484
  #define cr_hv3_warm_cnt                                (*(volatile unsigned int *)cr_hv3_warm_cnt_adr)
  #define cr_dbg_mux_sel_adr                             0x00320488                                                   // pmu_adr_base + 0x00000488
  #define cr_dbg_mux_sel                                 (*(volatile unsigned int *)cr_dbg_mux_sel_adr)
  #define cr_smps_cnt_adr                                0x0032048c                                                   // pmu_adr_base + 0x0000048c
  #define cr_smps_cnt                                    (*(volatile unsigned int *)cr_smps_cnt_adr)
  #define cr_smps_en_adr                                 0x00320490                                                   // pmu_adr_base + 0x00000490
  #define cr_smps_en                                     (*(volatile unsigned int *)cr_smps_en_adr)
  #define cr_smps_config_adr                             0x00320494                                                   // pmu_adr_base + 0x00000494
  #define cr_smps_config                                 (*(volatile unsigned int *)cr_smps_config_adr)
  #define fm_cfg_adr                                     0x00320498                                                   // pmu_adr_base + 0x00000498
  #define fm_cfg                                         (*(volatile unsigned int *)fm_cfg_adr)
  #define adc_cap_dst_adr                                0x0032049c                                                   // pmu_adr_base + 0x0000049c
  #define adc_cap_dst                                    (*(volatile unsigned int *)adc_cap_dst_adr)
  #define adc_cap_cfg_adr                                0x003204a0                                                   // pmu_adr_base + 0x000004a0
  #define adc_cap_cfg                                    (*(volatile unsigned int *)adc_cap_cfg_adr)
  #define sr_ahb_bridge_status_adr                       0x003204a4                                                   // pmu_adr_base + 0x000004a4
  #define sr_ahb_bridge_status                           (*(volatile unsigned int *)sr_ahb_bridge_status_adr)
  #define sr_ahb_bridge_en_adr                           0x003204a8                                                   // pmu_adr_base + 0x000004a8
  #define sr_ahb_bridge_en                               (*(volatile unsigned int *)sr_ahb_bridge_en_adr)
  #define coex_rst_ctl_adr                               0x003204ac                                                   // pmu_adr_base + 0x000004ac
  #define coex_rst_ctl                                   (*(volatile unsigned int *)coex_rst_ctl_adr)
  #define fmadc_clk_ctl_adr                              0x003204b0                                                   // pmu_adr_base + 0x000004b0
  #define fmadc_clk_ctl                                  (*(volatile unsigned int *)fmadc_clk_ctl_adr)
  #define sr_fll_cal_adr                                 0x003204b4                                                   // pmu_adr_base + 0x000004b4
  #define sr_fll_cal                                     (*(volatile unsigned int *)sr_fll_cal_adr)
  #define cr_adpll_ver_adr                               0x00321000                                                   // pmu_adr_base + 0x00001000
  #define cr_adpll_ver                                   (*(volatile unsigned int *)cr_adpll_ver_adr)
  #define cr_adpll_ctrl0_adr                             0x00321004                                                   // pmu_adr_base + 0x00001004
  #define cr_adpll_ctrl0                                 (*(volatile unsigned int *)cr_adpll_ctrl0_adr)
  #define cr_adpll_div_ratio_adr                         0x00321008                                                   // pmu_adr_base + 0x00001008
  #define cr_adpll_div_ratio                             (*(volatile unsigned int *)cr_adpll_div_ratio_adr)
  #define cr_adpll_lpf_ctrl0_adr                         0x0032100c                                                   // pmu_adr_base + 0x0000100c
  #define cr_adpll_lpf_ctrl0                             (*(volatile unsigned int *)cr_adpll_lpf_ctrl0_adr)
  #define cr_adpll_lpf_ctrl1_adr                         0x00321010                                                   // pmu_adr_base + 0x00001010
  #define cr_adpll_lpf_ctrl1                             (*(volatile unsigned int *)cr_adpll_lpf_ctrl1_adr)
  #define cr_adpll_lpf_ctrl2_adr                         0x00321014                                                   // pmu_adr_base + 0x00001014
  #define cr_adpll_lpf_ctrl2                             (*(volatile unsigned int *)cr_adpll_lpf_ctrl2_adr)
  #define cr_adpll_dco_ctrl0_adr                         0x00321018                                                   // pmu_adr_base + 0x00001018
  #define cr_adpll_dco_ctrl0                             (*(volatile unsigned int *)cr_adpll_dco_ctrl0_adr)
  #define cr_adpll_dco_ctrl1_adr                         0x0032101c                                                   // pmu_adr_base + 0x0000101c
  #define cr_adpll_dco_ctrl1                             (*(volatile unsigned int *)cr_adpll_dco_ctrl1_adr)
  #define cr_adpll_dco_ctrl2_adr                         0x00321020                                                   // pmu_adr_base + 0x00001020
  #define cr_adpll_dco_ctrl2                             (*(volatile unsigned int *)cr_adpll_dco_ctrl2_adr)
  #define cr_adpll_dither_ctrl0_adr                      0x00321024                                                   // pmu_adr_base + 0x00001024
  #define cr_adpll_dither_ctrl0                          (*(volatile unsigned int *)cr_adpll_dither_ctrl0_adr)
  #define cr_adpll_dither_ctrl1_adr                      0x00321028                                                   // pmu_adr_base + 0x00001028
  #define cr_adpll_dither_ctrl1                          (*(volatile unsigned int *)cr_adpll_dither_ctrl1_adr)
  #define cr_adpll_dco_ctrl_spare_adr                    0x0032102c                                                   // pmu_adr_base + 0x0000102c
  #define cr_adpll_dco_ctrl_spare                        (*(volatile unsigned int *)cr_adpll_dco_ctrl_spare_adr)
  #define cr_adpll_test_ctrl0_adr                        0x00321030                                                   // pmu_adr_base + 0x00001030
  #define cr_adpll_test_ctrl0                            (*(volatile unsigned int *)cr_adpll_test_ctrl0_adr)
  #define cr_adpll_test_ctrl1_adr                        0x00321034                                                   // pmu_adr_base + 0x00001034
  #define cr_adpll_test_ctrl1                            (*(volatile unsigned int *)cr_adpll_test_ctrl1_adr)
  #define cr_adpll_test_ctrl2_adr                        0x00321038                                                   // pmu_adr_base + 0x00001038
  #define cr_adpll_test_ctrl2                            (*(volatile unsigned int *)cr_adpll_test_ctrl2_adr)
  #define cr_adpll_test_ctrl3_adr                        0x0032103c                                                   // pmu_adr_base + 0x0000103c
  #define cr_adpll_test_ctrl3                            (*(volatile unsigned int *)cr_adpll_test_ctrl3_adr)
  #define cr_adpll_ol_ctrl0_adr                          0x00321040                                                   // pmu_adr_base + 0x00001040
  #define cr_adpll_ol_ctrl0                              (*(volatile unsigned int *)cr_adpll_ol_ctrl0_adr)
  #define cr_adpll_ol_ctrl1_adr                          0x00321044                                                   // pmu_adr_base + 0x00001044
  #define cr_adpll_ol_ctrl1                              (*(volatile unsigned int *)cr_adpll_ol_ctrl1_adr)
  #define cr_adpll_ol_ctrl2_adr                          0x00321048                                                   // pmu_adr_base + 0x00001048
  #define cr_adpll_ol_ctrl2                              (*(volatile unsigned int *)cr_adpll_ol_ctrl2_adr)
  #define cr_spm_ctrl0_adr                               0x00321200                                                   // pmu_adr_base + 0x00001200
  #define cr_spm_ctrl0                                   (*(volatile unsigned int *)cr_spm_ctrl0_adr)
  #define cr_spm_ctrl1_adr                               0x00321204                                                   // pmu_adr_base + 0x00001204
  #define cr_spm_ctrl1                                   (*(volatile unsigned int *)cr_spm_ctrl1_adr)
  #define cr_spm_ctrl2_adr                               0x00321208                                                   // pmu_adr_base + 0x00001208
  #define cr_spm_ctrl2                                   (*(volatile unsigned int *)cr_spm_ctrl2_adr)
  #define cr_spm_status_adr                              0x0032120c                                                   // pmu_adr_base + 0x0000120c
  #define cr_spm_status                                  (*(volatile unsigned int *)cr_spm_status_adr)
  #define cr_spm_ro_cnt0_adr                             0x00321210                                                   // pmu_adr_base + 0x00001210
  #define cr_spm_ro_cnt0                                 (*(volatile unsigned int *)cr_spm_ro_cnt0_adr)
  #define cr_spm_ro_cnt1_adr                             0x00321214                                                   // pmu_adr_base + 0x00001214
  #define cr_spm_ro_cnt1                                 (*(volatile unsigned int *)cr_spm_ro_cnt1_adr)
  #define cr_spm_ro_cnt2_adr                             0x00321218                                                   // pmu_adr_base + 0x00001218
  #define cr_spm_ro_cnt2                                 (*(volatile unsigned int *)cr_spm_ro_cnt2_adr)
  #define cr_spm_ro_cnt3_adr                             0x0032121c                                                   // pmu_adr_base + 0x0000121c
  #define cr_spm_ro_cnt3                                 (*(volatile unsigned int *)cr_spm_ro_cnt3_adr)
  #define cr_spm_ro_cnt4_adr                             0x00321220                                                   // pmu_adr_base + 0x00001220
  #define cr_spm_ro_cnt4                                 (*(volatile unsigned int *)cr_spm_ro_cnt4_adr)
  #define cr_spm_ro_cnt5_adr                             0x00321224                                                   // pmu_adr_base + 0x00001224
  #define cr_spm_ro_cnt5                                 (*(volatile unsigned int *)cr_spm_ro_cnt5_adr)
  #define cr_spm_ro_cnt6_adr                             0x00321228                                                   // pmu_adr_base + 0x00001228
  #define cr_spm_ro_cnt6                                 (*(volatile unsigned int *)cr_spm_ro_cnt6_adr)
  #define cr_spm_ro_cnt7_adr                             0x0032122c                                                   // pmu_adr_base + 0x0000122c
  #define cr_spm_ro_cnt7                                 (*(volatile unsigned int *)cr_spm_ro_cnt7_adr)
  #define cr_spm_ro_cnt8_adr                             0x00321230                                                   // pmu_adr_base + 0x00001230
  #define cr_spm_ro_cnt8                                 (*(volatile unsigned int *)cr_spm_ro_cnt8_adr)
  #define cr_spm_ro_cnt9_adr                             0x00321234                                                   // pmu_adr_base + 0x00001234
  #define cr_spm_ro_cnt9                                 (*(volatile unsigned int *)cr_spm_ro_cnt9_adr)
  #define cr_spm_ro_cnt10_adr                            0x00321238                                                   // pmu_adr_base + 0x00001238
  #define cr_spm_ro_cnt10                                (*(volatile unsigned int *)cr_spm_ro_cnt10_adr)
  #define cr_spm_ro_cnt11_adr                            0x0032123c                                                   // pmu_adr_base + 0x0000123c
  #define cr_spm_ro_cnt11                                (*(volatile unsigned int *)cr_spm_ro_cnt11_adr)
  #define cr_spm_ro_cnt12_adr                            0x00321240                                                   // pmu_adr_base + 0x00001240
  #define cr_spm_ro_cnt12                                (*(volatile unsigned int *)cr_spm_ro_cnt12_adr)
  #define cr_spm_ro_cnt13_adr                            0x00321244                                                   // pmu_adr_base + 0x00001244
  #define cr_spm_ro_cnt13                                (*(volatile unsigned int *)cr_spm_ro_cnt13_adr)
  #define cr_spm_ro_cnt14_adr                            0x00321248                                                   // pmu_adr_base + 0x00001248
  #define cr_spm_ro_cnt14                                (*(volatile unsigned int *)cr_spm_ro_cnt14_adr)
  #define cr_spm_ro_cnt15_adr                            0x0032124c                                                   // pmu_adr_base + 0x0000124c
  #define cr_spm_ro_cnt15                                (*(volatile unsigned int *)cr_spm_ro_cnt15_adr)
  #define cr_spm_ro_cnt16_adr                            0x00321250                                                   // pmu_adr_base + 0x00001250
  #define cr_spm_ro_cnt16                                (*(volatile unsigned int *)cr_spm_ro_cnt16_adr)
  #define cr_spm_ro_cnt17_adr                            0x00321254                                                   // pmu_adr_base + 0x00001254
  #define cr_spm_ro_cnt17                                (*(volatile unsigned int *)cr_spm_ro_cnt17_adr)
  #define cr_disable_wlan_xtal_ok_adr                    0x0032143c                                                   // pmu_adr_base + 0x0000143c
  #define cr_disable_wlan_xtal_ok                        (*(volatile unsigned int *)cr_disable_wlan_xtal_ok_adr)
  #define cr_current_sensor_ctl_adr                      0x00321500                                                   // pmu_adr_base + 0x00001500
  #define cr_current_sensor_ctl                          (*(volatile unsigned int *)cr_current_sensor_ctl_adr)
  #define cr_current_sensor_dir_adr                      0x00321504                                                   // pmu_adr_base + 0x00001504
  #define cr_current_sensor_dir                          (*(volatile unsigned int *)cr_current_sensor_dir_adr)
  #define cr_current_sensor_sts_adr                      0x00321508                                                   // pmu_adr_base + 0x00001508
  #define cr_current_sensor_sts                          (*(volatile unsigned int *)cr_current_sensor_sts_adr)
  #define cr_armjtag_cfg_adr                             0x0032150c                                                   // pmu_adr_base + 0x0000150c
  #define cr_armjtag_cfg                                 (*(volatile unsigned int *)cr_armjtag_cfg_adr)
  #define pwrwdog_ctrl_adr                               0x00390000                                                   // base_power_WD + 0x00000000 * 0x00000004
  #define pwrwdog_ctrl                                   (*(volatile unsigned int *)pwrwdog_ctrl_adr)
  #define pwrwdog_stat_adr                               0x00390004                                                   // base_power_WD + 0x00000001 * 0x00000004
  #define pwrwdog_stat                                   (*(volatile unsigned int *)pwrwdog_stat_adr)
  #define pwrwdog_dlyen_cnt_adr                          0x00390008                                                   // base_power_WD + 0x00000002 * 0x00000004
  #define pwrwdog_dlyen_cnt                              (*(volatile unsigned int *)pwrwdog_dlyen_cnt_adr)
  #define pwrwdog_stat_cnt_adr                           0x0039000c                                                   // base_power_WD + 0x00000003 * 0x00000004
  #define pwrwdog_stat_cnt                               (*(volatile unsigned int *)pwrwdog_stat_cnt_adr)
  #define pwrwdog_accu_ctrl_adr                          0x00390010                                                   // base_power_WD + 0x00000004 * 0x00000004
  #define pwrwdog_accu_ctrl                              (*(volatile unsigned int *)pwrwdog_accu_ctrl_adr)
  #define pwrwdog_accu_stat_adr                          0x00390014                                                   // base_power_WD + 0x00000005 * 0x00000004
  #define pwrwdog_accu_stat                              (*(volatile unsigned int *)pwrwdog_accu_stat_adr)
  #define pwrwdog_ctrl1_adr                              0x00391000                                                   // base_power_WD + 0x00000000 * 0x00000004 + 0x00001000
  #define pwrwdog_ctrl1                                  (*(volatile unsigned int *)pwrwdog_ctrl1_adr)
  #define pwrwdog_stat1_adr                              0x00391004                                                   // base_power_WD + 0x00000001 * 0x00000004 + 0x00001000
  #define pwrwdog_stat1                                  (*(volatile unsigned int *)pwrwdog_stat1_adr)
  #define pwrwdog_dlyen_cnt1_adr                         0x00391008                                                   // base_power_WD + 0x00000002 * 0x00000004 + 0x00001000
  #define pwrwdog_dlyen_cnt1                             (*(volatile unsigned int *)pwrwdog_dlyen_cnt1_adr)
  #define pwrwdog_stat_cnt1_adr                          0x0039100c                                                   // base_power_WD + 0x00000003 * 0x00000004 + 0x00001000
  #define pwrwdog_stat_cnt1                              (*(volatile unsigned int *)pwrwdog_stat_cnt1_adr)
  #define pwrwdog_accu_ctrl1_adr                         0x00391010                                                   // base_power_WD + 0x00000004 * 0x00000004 + 0x00001000
  #define pwrwdog_accu_ctrl1                             (*(volatile unsigned int *)pwrwdog_accu_ctrl1_adr)
  #define pwrwdog_accu_stat1_adr                         0x00391014                                                   // base_power_WD + 0x00000005 * 0x00000004 + 0x00001000
  #define pwrwdog_accu_stat1                             (*(volatile unsigned int *)pwrwdog_accu_stat1_adr)
  #define cr_pds_cfg0_adr                                0x00321510                                                   // pmu_adr_base + 0x00001510
  #define cr_pds_cfg0                                    (*(volatile unsigned int *)cr_pds_cfg0_adr)
  #define cr_pds_cfg1_adr                                0x00321514                                                   // pmu_adr_base + 0x00001514
  #define cr_pds_cfg1                                    (*(volatile unsigned int *)cr_pds_cfg1_adr)
  #define cr_pds_cfg2_adr                                0x00321518                                                   // pmu_adr_base + 0x00001518
  #define cr_pds_cfg2                                    (*(volatile unsigned int *)cr_pds_cfg2_adr)
  #define cr_pds_cfg3_adr                                0x0032151c                                                   // pmu_adr_base + 0x0000151c
  #define cr_pds_cfg3                                    (*(volatile unsigned int *)cr_pds_cfg3_adr)
  #define cr_pds_ctrl_adr                                0x00321520                                                   // pmu_adr_base + 0x00001520
  #define cr_pds_ctrl                                    (*(volatile unsigned int *)cr_pds_ctrl_adr)
  #define cr_pds_cfg4_adr                                0x00321524                                                   // pmu_adr_base + 0x00001524
  #define cr_pds_cfg4                                    (*(volatile unsigned int *)cr_pds_cfg4_adr)
  #define cr_pds_cfg5_adr                                0x00321528                                                   // pmu_adr_base + 0x00001528
  #define cr_pds_cfg5                                    (*(volatile unsigned int *)cr_pds_cfg5_adr)
  #define cr_pds_cfg6_adr                                0x00321534                                                   // pmu_adr_base + 0x00001534
  #define cr_pds_cfg6                                    (*(volatile unsigned int *)cr_pds_cfg6_adr)
  #define cr_pds_cfg7_adr                                0x00321538                                                   // pmu_adr_base + 0x00001538
  #define cr_pds_cfg7                                    (*(volatile unsigned int *)cr_pds_cfg7_adr)
  #define cr_ptu_aux_src_sel_adr                         0x0032152c                                                   // pmu_adr_base + 0x0000152c
  #define cr_ptu_aux_src_sel                             (*(volatile unsigned int *)cr_ptu_aux_src_sel_adr)
  #define gps_uart_mux_mode_adr                          0x00321530                                                   // pmu_adr_base + 0x00001530
  #define gps_uart_mux_mode                              (*(volatile unsigned int *)gps_uart_mux_mode_adr)
  #define cr_bt_sdio_intr_ctrl_adr                       0x0032153c                                                   // pmu_adr_base + 0x0000153c
  #define cr_bt_sdio_intr_ctrl                           (*(volatile unsigned int *)cr_bt_sdio_intr_ctrl_adr)
  #define cr_bt_sdio_intr_mask_adr                       0x00321540                                                   // pmu_adr_base + 0x00001540
  #define cr_bt_sdio_intr_mask                           (*(volatile unsigned int *)cr_bt_sdio_intr_mask_adr)
  #define cr_baja_temp_adr                               0x00321544                                                   // pmu_adr_base + 0x00001544
  #define cr_baja_temp                                   (*(volatile unsigned int *)cr_baja_temp_adr)
  #define cr_bt_to_wlan_misc_intr_ctrl_adr               0x00321548                                                   // pmu_adr_base + 0x00001548
  #define cr_bt_to_wlan_misc_intr_ctrl                   (*(volatile unsigned int *)cr_bt_to_wlan_misc_intr_ctrl_adr)
  #define cr_bt_to_wlan_misc_intr_mask_adr               0x0032154c                                                   // pmu_adr_base + 0x0000154c
  #define cr_bt_to_wlan_misc_intr_mask                   (*(volatile unsigned int *)cr_bt_to_wlan_misc_intr_mask_adr)
  #define adc2pmu_probe_adr                              0x00321550                                                   // pmu_adr_base + 0x00001550
  #define adc2pmu_probe                                  (*(volatile unsigned int *)adc2pmu_probe_adr)
  #define adc2pmu_dma_data_adr                           0x00321554                                                   // pmu_adr_base + 0x00001554
  #define adc2pmu_dma_data                               (*(volatile unsigned int *)adc2pmu_dma_data_adr)
  #define adc2pmu_dma_status_adr                         0x00321558                                                   // pmu_adr_base + 0x00001558
  #define adc2pmu_dma_status                             (*(volatile unsigned int *)adc2pmu_dma_status_adr)
  #define adc2pmu_ro_spare_adr                           0x0032155c                                                   // pmu_adr_base + 0x0000155c
  #define adc2pmu_ro_spare                               (*(volatile unsigned int *)adc2pmu_ro_spare_adr)
  #define cr_otp_clk_en_adr                              0x00321560                                                   // pmu_adr_base + 0x00001560
  #define cr_otp_clk_en                                  (*(volatile unsigned int *)cr_otp_clk_en_adr)
  #define fm_cRamD_adr                                   0x00324130                                                   // mtu_adr_base + 0x0000004c * 0x00000004
  #define fm_cRamD                                       (*(volatile unsigned int *)fm_cRamD_adr)
  #define fm_agcRamD_adr                                 0x00324214                                                   // mtu_adr_base + 0x00000085 * 0x00000004
  #define fm_agcRamD                                     (*(volatile unsigned int *)fm_agcRamD_adr)
  #define fm_mask_adr                                    0x00324040                                                   // mtu_adr_base + 0x00000010 * 0x00000004
  #define fm_mask                                        (*(volatile unsigned int *)fm_mask_adr)
  #define fm_rds_mask_adr                                0x00324044                                                   // mtu_adr_base + 0x00000011 * 0x00000004
  #define fm_rds_mask                                    (*(volatile unsigned int *)fm_rds_mask_adr)
  #define fm_flag_adr                                    0x00324048                                                   // mtu_adr_base + 0x00000012 * 0x00000004
  #define fm_flag                                        (*(volatile unsigned int *)fm_flag_adr)
  #define fm_rds_flag_adr                                0x0032404c                                                   // mtu_adr_base + 0x00000013 * 0x00000004
  #define fm_rds_flag                                    (*(volatile unsigned int *)fm_rds_flag_adr)
  #define fm_mask_shadow_adr                             0x003240b0                                                   // mtu_adr_base + 0x0000002c * 0x00000004
  #define fm_mask_shadow                                 (*(volatile unsigned int *)fm_mask_shadow_adr)
  #define fm_rds_mask_shadow_adr                         0x003240b4                                                   // mtu_adr_base + 0x0000002d * 0x00000004
  #define fm_rds_mask_shadow                             (*(volatile unsigned int *)fm_rds_mask_shadow_adr)
  #define fm_flag_shadow_adr                             0x003240b8                                                   // mtu_adr_base + 0x0000002e * 0x00000004
  #define fm_flag_shadow                                 (*(volatile unsigned int *)fm_flag_shadow_adr)
  #define fm_rds_flag_shadow_adr                         0x003240bc                                                   // mtu_adr_base + 0x0000002f * 0x00000004
  #define fm_rds_flag_shadow                             (*(volatile unsigned int *)fm_rds_flag_shadow_adr)
  #define rf_wild_base2_adr                              0x003242d0                                                   // mtu_adr_base + 0x000000b4 * 0x00000004
  #define rf_wild_base2                                  (*(volatile unsigned int *)rf_wild_base2_adr)
  #define rds_corr_data_adr                              0x00324b90                                                   // mtu_adr_base + 0x000002e4 * 0x00000004
  #define rds_corr_data                                  (*(volatile unsigned int *)rds_corr_data_adr)
  #define rds_corr_stat_adr                              0x00324b94                                                   // mtu_adr_base + 0x000002e5 * 0x00000004
  #define rds_corr_stat                                  (*(volatile unsigned int *)rds_corr_stat_adr)
  #define fm_ellip14_adr                                 0x00324bc4                                                   // mtu_adr_base + 0x000002f1 * 0x00000004
  #define fm_ellip14                                     (*(volatile unsigned int *)fm_ellip14_adr)
  #define fmrfdsp_reg104_adr                             0x00324cc8                                                   // mtu_adr_base + 0x00000332 * 0x00000004
  #define fmrfdsp_reg104                                 (*(volatile unsigned int *)fmrfdsp_reg104_adr)
  #define psd_psdout_d_adr                               0x00324bd4                                                   // mtu_adr_base + 0x000002f5 * 0x00000004
  #define psd_psdout_d                                   (*(volatile unsigned int *)psd_psdout_d_adr)
  #define fm_i2c_page_ctrl_adr                           0x003242ac                                                   // mtu_adr_base + 0x000000ab * 0x00000004
  #define fm_i2c_page_ctrl                               (*(volatile unsigned int *)fm_i2c_page_ctrl_adr)
  #define fm_rds_rdata_adr                               0x00324200                                                   // mtu_adr_base + 0x00000080 * 0x00000004
  #define fm_rds_rdata                                   (*(volatile unsigned int *)fm_rds_rdata_adr)
  #define fm_api_spare0_adr                              0x00324080                                                   // mtu_adr_base + 0x00000020 * 0x00000004
  #define fm_api_spare0                                  (*(volatile unsigned int *)fm_api_spare0_adr)
  #define fm_api_spare1_adr                              0x00324084                                                   // mtu_adr_base + 0x00000021 * 0x00000004
  #define fm_api_spare1                                  (*(volatile unsigned int *)fm_api_spare1_adr)
  #define fm_search_tune_mode_adr                        0x00324024                                                   // mtu_adr_base + 0x00000009 * 0x00000004
  #define fm_search_tune_mode                            (*(volatile unsigned int *)fm_search_tune_mode_adr)
  #define fm_audio_pause_adr                             0x00324010                                                   // mtu_adr_base + 0x00000004 * 0x00000004
  #define fm_audio_pause                                 (*(volatile unsigned int *)fm_audio_pause_adr)
  #define fm_audio_ctrl0_adr                             0x00324014                                                   // mtu_adr_base + 0x00000005 * 0x00000004
  #define fm_audio_ctrl0                                 (*(volatile unsigned int *)fm_audio_ctrl0_adr)
  #define fm_audio_ctrl1_adr                             0x00324018                                                   // mtu_adr_base + 0x00000006 * 0x00000004
  #define fm_audio_ctrl1                                 (*(volatile unsigned int *)fm_audio_ctrl1_adr)
  #define fm_rds_system_adr                              0x00324000                                                   // mtu_adr_base + 0x00000000 * 0x00000004
  #define fm_rds_system                                  (*(volatile unsigned int *)fm_rds_system_adr)
  #define fm_ctrl_adr                                    0x00324004                                                   // mtu_adr_base + 0x00000001 * 0x00000004
  #define fm_ctrl                                        (*(volatile unsigned int *)fm_ctrl_adr)
  #define fm_rds_ctrl0_adr                               0x00324008                                                   // mtu_adr_base + 0x00000002 * 0x00000004
  #define fm_rds_ctrl0                                   (*(volatile unsigned int *)fm_rds_ctrl0_adr)
  #define fm_rds_wline_adr                               0x00324050                                                   // mtu_adr_base + 0x00000014 * 0x00000004
  #define fm_rds_wline                                   (*(volatile unsigned int *)fm_rds_wline_adr)
  #define fm_rds_blkb_mask0_adr                          0x00324060                                                   // mtu_adr_base + 0x00000018 * 0x00000004
  #define fm_rds_blkb_mask0                              (*(volatile unsigned int *)fm_rds_blkb_mask0_adr)
  #define fm_rds_blkb_mask1_adr                          0x00324064                                                   // mtu_adr_base + 0x00000019 * 0x00000004
  #define fm_rds_blkb_mask1                              (*(volatile unsigned int *)fm_rds_blkb_mask1_adr)
  #define fm_rds_fifo_size_adr                           0x00324054                                                   // mtu_adr_base + 0x00000015 * 0x00000004
  #define fm_rds_fifo_size                               (*(volatile unsigned int *)fm_rds_fifo_size_adr)
  #define fm_rds_pi_mask0_adr                            0x00324070                                                   // mtu_adr_base + 0x0000001c * 0x00000004
  #define fm_rds_pi_mask0                                (*(volatile unsigned int *)fm_rds_pi_mask0_adr)
  #define fm_rds_pi_mask1_adr                            0x00324074                                                   // mtu_adr_base + 0x0000001d * 0x00000004
  #define fm_rds_pi_mask1                                (*(volatile unsigned int *)fm_rds_pi_mask1_adr)
  #define fm_i2c_write_stat0_adr                         0x00324088                                                   // mtu_adr_base + 0x00000022 * 0x00000004
  #define fm_i2c_write_stat0                             (*(volatile unsigned int *)fm_i2c_write_stat0_adr)
  #define fm_i2c_write_stat1_adr                         0x0032408c                                                   // mtu_adr_base + 0x00000023 * 0x00000004
  #define fm_i2c_write_stat1                             (*(volatile unsigned int *)fm_i2c_write_stat1_adr)
  #define aud_fifo_ping_adr                              0x00326000                                                   // aud_fifo_adr_base + 0x00000000
  #define aud_fifo_ping                                  (*(volatile unsigned int *)aud_fifo_ping_adr)
  #define aud_fifo_pong_adr                              0x00326200                                                   // aud_fifo_adr_base + 0x00000200
  #define aud_fifo_pong                                  (*(volatile unsigned int *)aud_fifo_pong_adr)
  #define audio_chrp_afcA_adr                            0x00327000                                                   // audio_adr_base + 0x00000000 * 0x00000004
  #define audio_chrp_afcA                                (*(volatile unsigned int *)audio_chrp_afcA_adr)
  #define audio_chrp_afcB_adr                            0x00327004                                                   // audio_adr_base + 0x00000001 * 0x00000004
  #define audio_chrp_afcB                                (*(volatile unsigned int *)audio_chrp_afcB_adr)
  #define audio_chrp_fcA_adr                             0x00327008                                                   // audio_adr_base + 0x00000002 * 0x00000004
  #define audio_chrp_fcA                                 (*(volatile unsigned int *)audio_chrp_fcA_adr)
  #define audio_chrp_fcB_adr                             0x0032700c                                                   // audio_adr_base + 0x00000003 * 0x00000004
  #define audio_chrp_fcB                                 (*(volatile unsigned int *)audio_chrp_fcB_adr)
  #define audio_chrp_mrkA_adr                            0x00327010                                                   // audio_adr_base + 0x00000004 * 0x00000004
  #define audio_chrp_mrkA                                (*(volatile unsigned int *)audio_chrp_mrkA_adr)
  #define audio_chrp_mrkB_adr                            0x00327014                                                   // audio_adr_base + 0x00000005 * 0x00000004
  #define audio_chrp_mrkB                                (*(volatile unsigned int *)audio_chrp_mrkB_adr)
  #define audio_chrp_spcA_adr                            0x00327018                                                   // audio_adr_base + 0x00000006 * 0x00000004
  #define audio_chrp_spcA                                (*(volatile unsigned int *)audio_chrp_spcA_adr)
  #define audio_chrp_spcB_adr                            0x0032701c                                                   // audio_adr_base + 0x00000007 * 0x00000004
  #define audio_chrp_spcB                                (*(volatile unsigned int *)audio_chrp_spcB_adr)
  #define audio_chrp_ctrl_adr                            0x00327020                                                   // audio_adr_base + 0x00000008 * 0x00000004
  #define audio_chrp_ctrl                                (*(volatile unsigned int *)audio_chrp_ctrl_adr)
  #define fm_dpath_ctrl1_adr                             0x00327040                                                   // audio_adr_base + 0x00000010 * 0x00000004
  #define fm_dpath_ctrl1                                 (*(volatile unsigned int *)fm_dpath_ctrl1_adr)
  #define audio_fra1_ctrl_adr                            0x00327080                                                   // audio_adr_base + 0x00000020 * 0x00000004
  #define audio_fra1_ctrl                                (*(volatile unsigned int *)audio_fra1_ctrl_adr)
  #define audio_fra1_ratio_adr                           0x00327084                                                   // audio_adr_base + 0x00000021 * 0x00000004
  #define audio_fra1_ratio                               (*(volatile unsigned int *)audio_fra1_ratio_adr)
  #define audio_fra1_minstep_adr                         0x00327088                                                   // audio_adr_base + 0x00000022 * 0x00000004
  #define audio_fra1_minstep                             (*(volatile unsigned int *)audio_fra1_minstep_adr)
  #define audio_hifi_enable_adr                          0x003270c0                                                   // audio_adr_base + 0x00000030 * 0x00000004
  #define audio_hifi_enable                              (*(volatile unsigned int *)audio_hifi_enable_adr)
  #define audio_hifi_coeffAd_adr                         0x003270c4                                                   // audio_adr_base + 0x00000031 * 0x00000004
  #define audio_hifi_coeffAd                             (*(volatile unsigned int *)audio_hifi_coeffAd_adr)
  #define audio_hifi_coeffDi_adr                         0x003270c8                                                   // audio_adr_base + 0x00000032 * 0x00000004
  #define audio_hifi_coeffDi                             (*(volatile unsigned int *)audio_hifi_coeffDi_adr)
  #define audio_hifi_ctrl_adr                            0x003270cc                                                   // audio_adr_base + 0x00000033 * 0x00000004
  #define audio_hifi_ctrl                                (*(volatile unsigned int *)audio_hifi_ctrl_adr)
  #define audio_hifi_intD_adr                            0x003270d0                                                   // audio_adr_base + 0x00000034 * 0x00000004
  #define audio_hifi_intD                                (*(volatile unsigned int *)audio_hifi_intD_adr)
  #define audio_hifi_frac_adr                            0x003270d4                                                   // audio_adr_base + 0x00000035 * 0x00000004
  #define audio_hifi_frac                                (*(volatile unsigned int *)audio_hifi_frac_adr)
  #define audio_hifi_hyst_adr                            0x003270d8                                                   // audio_adr_base + 0x00000036 * 0x00000004
  #define audio_hifi_hyst                                (*(volatile unsigned int *)audio_hifi_hyst_adr)
  #define audio_hifi_minadj_adr                          0x003270dc                                                   // audio_adr_base + 0x00000037 * 0x00000004
  #define audio_hifi_minadj                              (*(volatile unsigned int *)audio_hifi_minadj_adr)
  #define audio_hifi_seed_adr                            0x003270e0                                                   // audio_adr_base + 0x00000038 * 0x00000004
  #define audio_hifi_seed                                (*(volatile unsigned int *)audio_hifi_seed_adr)
  #define audio_hifi_direct_gain_adr                     0x003270e4                                                   // audio_adr_base + 0x00000039 * 0x00000004
  #define audio_hifi_direct_gain                         (*(volatile unsigned int *)audio_hifi_direct_gain_adr)
  #define audio_hifi_int_gain_adr                        0x003270e8                                                   // audio_adr_base + 0x0000003a * 0x00000004
  #define audio_hifi_int_gain                            (*(volatile unsigned int *)audio_hifi_int_gain_adr)
  #define audio_hifi_error_accum_adr                     0x003270ec                                                   // audio_adr_base + 0x0000003b * 0x00000004
  #define audio_hifi_error_accum                         (*(volatile unsigned int *)audio_hifi_error_accum_adr)
  #define audio_fmdac_seq_adr                            0x003270f0                                                   // audio_adr_base + 0x0000003c * 0x00000004
  #define audio_fmdac_seq                                (*(volatile unsigned int *)audio_fmdac_seq_adr)
  #define audio_fmdac_dsctrl_adr                         0x003270f4                                                   // audio_adr_base + 0x0000003d * 0x00000004
  #define audio_fmdac_dsctrl                             (*(volatile unsigned int *)audio_fmdac_dsctrl_adr)
  #define audio_fmdac_rdback1_adr                        0x003270f8                                                   // audio_adr_base + 0x0000003e * 0x00000004
  #define audio_fmdac_rdback1                            (*(volatile unsigned int *)audio_fmdac_rdback1_adr)
  #define audio_fmdac_rdback2_adr                        0x003270fc                                                   // audio_adr_base + 0x0000003f * 0x00000004
  #define audio_fmdac_rdback2                            (*(volatile unsigned int *)audio_fmdac_rdback2_adr)
  #define audio_fdiv_N_adr                               0x00327100                                                   // audio_adr_base + 0x00000040 * 0x00000004
  #define audio_fdiv_N                                   (*(volatile unsigned int *)audio_fdiv_N_adr)
  #define audio_fdiv_X_adr                               0x00327104                                                   // audio_adr_base + 0x00000041 * 0x00000004
  #define audio_fdiv_X                                   (*(volatile unsigned int *)audio_fdiv_X_adr)
  #define audio_fdiv_enable_adr                          0x00327108                                                   // audio_adr_base + 0x00000042 * 0x00000004
  #define audio_fdiv_enable                              (*(volatile unsigned int *)audio_fdiv_enable_adr)
  #define audio_fdiv_div2n_adr                           0x0032710c                                                   // audio_adr_base + 0x00000043 * 0x00000004
  #define audio_fdiv_div2n                               (*(volatile unsigned int *)audio_fdiv_div2n_adr)
  #define audio_fdiv_update_adr                          0x00327110                                                   // audio_adr_base + 0x00000044 * 0x00000004
  #define audio_fdiv_update                              (*(volatile unsigned int *)audio_fdiv_update_adr)
  #define audio_hld0_ctrl_adr                            0x00327140                                                   // audio_adr_base + 0x00000050 * 0x00000004
  #define audio_hld0_ctrl                                (*(volatile unsigned int *)audio_hld0_ctrl_adr)
  #define audio_hld0_stblen_adr                          0x00327144                                                   // audio_adr_base + 0x00000051 * 0x00000004
  #define audio_hld0_stblen                              (*(volatile unsigned int *)audio_hld0_stblen_adr)
  #define audio_hld0_stboff_adr                          0x00327148                                                   // audio_adr_base + 0x00000052 * 0x00000004
  #define audio_hld0_stboff                              (*(volatile unsigned int *)audio_hld0_stboff_adr)
  #define audio_hld1_ctrl_adr                            0x00327160                                                   // audio_adr_base + 0x00000058 * 0x00000004
  #define audio_hld1_ctrl                                (*(volatile unsigned int *)audio_hld1_ctrl_adr)
  #define audio_hld1_stblen_adr                          0x00327164                                                   // audio_adr_base + 0x00000059 * 0x00000004
  #define audio_hld1_stblen                              (*(volatile unsigned int *)audio_hld1_stblen_adr)
  #define audio_hld1_stboff_adr                          0x00327168                                                   // audio_adr_base + 0x0000005a * 0x00000004
  #define audio_hld1_stboff                              (*(volatile unsigned int *)audio_hld1_stboff_adr)
  #define audio_syn0_ctrl_adr                            0x00327180                                                   // audio_adr_base + 0x00000060 * 0x00000004
  #define audio_syn0_ctrl                                (*(volatile unsigned int *)audio_syn0_ctrl_adr)
  #define audio_syn1_ctrl_adr                            0x00327184                                                   // audio_adr_base + 0x00000061 * 0x00000004
  #define audio_syn1_ctrl                                (*(volatile unsigned int *)audio_syn1_ctrl_adr)
  #define audio_down_ctrl_adr                            0x00327188                                                   // audio_adr_base + 0x00000062 * 0x00000004
  #define audio_down_ctrl                                (*(volatile unsigned int *)audio_down_ctrl_adr)
  #define audio_mix2_ctrl_adr                            0x00327190                                                   // audio_adr_base + 0x00000064 * 0x00000004
  #define audio_mix2_ctrl                                (*(volatile unsigned int *)audio_mix2_ctrl_adr)
  #define audio_mix2_scale_adr                           0x00327194                                                   // audio_adr_base + 0x00000065 * 0x00000004
  #define audio_mix2_scale                               (*(volatile unsigned int *)audio_mix2_scale_adr)
  #define audio_mix2_sm_ctrl_adr                         0x00327198                                                   // audio_adr_base + 0x00000066 * 0x00000004
  #define audio_mix2_sm_ctrl                             (*(volatile unsigned int *)audio_mix2_sm_ctrl_adr)
  #define audio_mix2_sm_thresh_adr                       0x0032719c                                                   // audio_adr_base + 0x00000067 * 0x00000004
  #define audio_mix2_sm_thresh                           (*(volatile unsigned int *)audio_mix2_sm_thresh_adr)
  #define audio_rssi_ctrl_adr                            0x003271a0                                                   // audio_adr_base + 0x00000068 * 0x00000004
  #define audio_rssi_ctrl                                (*(volatile unsigned int *)audio_rssi_ctrl_adr)
  #define audio_rssi_avg0_adr                            0x003271a4                                                   // audio_adr_base + 0x00000069 * 0x00000004
  #define audio_rssi_avg0                                (*(volatile unsigned int *)audio_rssi_avg0_adr)
  #define audio_rssi_avg1_adr                            0x003271a8                                                   // audio_adr_base + 0x0000006a * 0x00000004
  #define audio_rssi_avg1                                (*(volatile unsigned int *)audio_rssi_avg1_adr)
  #define audio_clock_gate_adr                           0x003271b0                                                   // audio_adr_base + 0x0000006c * 0x00000004
  #define audio_clock_gate                               (*(volatile unsigned int *)audio_clock_gate_adr)
  #define audio_soft_reset_adr                           0x003271b4                                                   // audio_adr_base + 0x0000006d * 0x00000004
  #define audio_soft_reset                               (*(volatile unsigned int *)audio_soft_reset_adr)
  #define audio_dsel00_adr                               0x003271c0                                                   // audio_adr_base + 0x00000070 * 0x00000004
  #define audio_dsel00                                   (*(volatile unsigned int *)audio_dsel00_adr)
  #define audio_dsel01_adr                               0x003271c4                                                   // audio_adr_base + 0x00000071 * 0x00000004
  #define audio_dsel01                                   (*(volatile unsigned int *)audio_dsel01_adr)
  #define audio_dsel02_adr                               0x003271c8                                                   // audio_adr_base + 0x00000072 * 0x00000004
  #define audio_dsel02                                   (*(volatile unsigned int *)audio_dsel02_adr)
  #define audio_dsel03_adr                               0x003271cc                                                   // audio_adr_base + 0x00000073 * 0x00000004
  #define audio_dsel03                                   (*(volatile unsigned int *)audio_dsel03_adr)
  #define audio_dsel04_adr                               0x003271d0                                                   // audio_adr_base + 0x00000074 * 0x00000004
  #define audio_dsel04                                   (*(volatile unsigned int *)audio_dsel04_adr)
  #define audio_dsel05_adr                               0x003271d4                                                   // audio_adr_base + 0x00000075 * 0x00000004
  #define audio_dsel05                                   (*(volatile unsigned int *)audio_dsel05_adr)
  #define audio_dsel06_adr                               0x003271d8                                                   // audio_adr_base + 0x00000076 * 0x00000004
  #define audio_dsel06                                   (*(volatile unsigned int *)audio_dsel06_adr)
  #define audio_dsel07_adr                               0x003271dc                                                   // audio_adr_base + 0x00000077 * 0x00000004
  #define audio_dsel07                                   (*(volatile unsigned int *)audio_dsel07_adr)
  #define audio_dsel08_adr                               0x003271e0                                                   // audio_adr_base + 0x00000078 * 0x00000004
  #define audio_dsel08                                   (*(volatile unsigned int *)audio_dsel08_adr)
  #define audio_dsel09_adr                               0x003271e4                                                   // audio_adr_base + 0x00000079 * 0x00000004
  #define audio_dsel09                                   (*(volatile unsigned int *)audio_dsel09_adr)
  #define audio_dsel10_adr                               0x003271e8                                                   // audio_adr_base + 0x0000007a * 0x00000004
  #define audio_dsel10                                   (*(volatile unsigned int *)audio_dsel10_adr)
  #define audio_dsel11_adr                               0x003271ec                                                   // audio_adr_base + 0x0000007b * 0x00000004
  #define audio_dsel11                                   (*(volatile unsigned int *)audio_dsel11_adr)
  #define audio_dsel12_adr                               0x003271f0                                                   // audio_adr_base + 0x0000007c * 0x00000004
  #define audio_dsel12                                   (*(volatile unsigned int *)audio_dsel12_adr)
  #define audio_dsel13_adr                               0x003271f4                                                   // audio_adr_base + 0x0000007d * 0x00000004
  #define audio_dsel13                                   (*(volatile unsigned int *)audio_dsel13_adr)
  #define audio_dsel14_adr                               0x003271f8                                                   // audio_adr_base + 0x0000007e * 0x00000004
  #define audio_dsel14                                   (*(volatile unsigned int *)audio_dsel14_adr)
  #define audio_dsel15_adr                               0x003271fc                                                   // audio_adr_base + 0x0000007f * 0x00000004
  #define audio_dsel15                                   (*(volatile unsigned int *)audio_dsel15_adr)
  #define audio_ssel00_adr                               0x00327240                                                   // audio_adr_base + 0x00000090 * 0x00000004
  #define audio_ssel00                                   (*(volatile unsigned int *)audio_ssel00_adr)
  #define audio_ssel01_adr                               0x00327244                                                   // audio_adr_base + 0x00000091 * 0x00000004
  #define audio_ssel01                                   (*(volatile unsigned int *)audio_ssel01_adr)
  #define audio_ssel02_adr                               0x00327248                                                   // audio_adr_base + 0x00000092 * 0x00000004
  #define audio_ssel02                                   (*(volatile unsigned int *)audio_ssel02_adr)
  #define audio_ssel03_adr                               0x0032724c                                                   // audio_adr_base + 0x00000093 * 0x00000004
  #define audio_ssel03                                   (*(volatile unsigned int *)audio_ssel03_adr)
  #define audio_ssel04_adr                               0x00327250                                                   // audio_adr_base + 0x00000094 * 0x00000004
  #define audio_ssel04                                   (*(volatile unsigned int *)audio_ssel04_adr)
  #define audio_ssel05_adr                               0x00327254                                                   // audio_adr_base + 0x00000095 * 0x00000004
  #define audio_ssel05                                   (*(volatile unsigned int *)audio_ssel05_adr)
  #define audio_ssel06_adr                               0x00327258                                                   // audio_adr_base + 0x00000096 * 0x00000004
  #define audio_ssel06                                   (*(volatile unsigned int *)audio_ssel06_adr)
  #define audio_ssel07_adr                               0x0032725c                                                   // audio_adr_base + 0x00000097 * 0x00000004
  #define audio_ssel07                                   (*(volatile unsigned int *)audio_ssel07_adr)
  #define audio_ssel08_adr                               0x00327260                                                   // audio_adr_base + 0x00000098 * 0x00000004
  #define audio_ssel08                                   (*(volatile unsigned int *)audio_ssel08_adr)
  #define audio_ssel09_adr                               0x00327264                                                   // audio_adr_base + 0x00000099 * 0x00000004
  #define audio_ssel09                                   (*(volatile unsigned int *)audio_ssel09_adr)
  #define audio_ssel10_adr                               0x00327268                                                   // audio_adr_base + 0x0000009a * 0x00000004
  #define audio_ssel10                                   (*(volatile unsigned int *)audio_ssel10_adr)
  #define audio_ssel11_adr                               0x0032726c                                                   // audio_adr_base + 0x0000009b * 0x00000004
  #define audio_ssel11                                   (*(volatile unsigned int *)audio_ssel11_adr)
  #define audio_ssel12_adr                               0x00327270                                                   // audio_adr_base + 0x0000009c * 0x00000004
  #define audio_ssel12                                   (*(volatile unsigned int *)audio_ssel12_adr)
  #define audio_ssel13_adr                               0x00327274                                                   // audio_adr_base + 0x0000009d * 0x00000004
  #define audio_ssel13                                   (*(volatile unsigned int *)audio_ssel13_adr)
  #define audio_ssel14_adr                               0x00327278                                                   // audio_adr_base + 0x0000009e * 0x00000004
  #define audio_ssel14                                   (*(volatile unsigned int *)audio_ssel14_adr)
  #define audio_ssel15_adr                               0x0032727c                                                   // audio_adr_base + 0x0000009f * 0x00000004
  #define audio_ssel15                                   (*(volatile unsigned int *)audio_ssel15_adr)
  #define audio_ssel16_adr                               0x00327280                                                   // audio_adr_base + 0x000000a0 * 0x00000004
  #define audio_ssel16                                   (*(volatile unsigned int *)audio_ssel16_adr)
  #define audio_debug_sel_adr                            0x003273fc                                                   // audio_adr_base + 0x000000ff * 0x00000004
  #define audio_debug_sel                                (*(volatile unsigned int *)audio_debug_sel_adr)
  #define fmm_fifo_rd_update_adr                         0x00326800                                                   // aud_fifo_adr_base + 0x00000800
  #define fmm_fifo_rd_update                             (*(volatile unsigned int *)fmm_fifo_rd_update_adr)
  #define fmm_fifo_mode_adr                              0x00326804                                                   // aud_fifo_adr_base + 0x00000804
  #define fmm_fifo_mode                                  (*(volatile unsigned int *)fmm_fifo_mode_adr)
  #define fmm_fifo_waterline_adr                         0x00326808                                                   // aud_fifo_adr_base + 0x00000808
  #define fmm_fifo_waterline                             (*(volatile unsigned int *)fmm_fifo_waterline_adr)
  #define fmm_fifo2_rd_update_adr                        0x0032680c                                                   // aud_fifo_adr_base + 0x0000080c
  #define fmm_fifo2_rd_update                            (*(volatile unsigned int *)fmm_fifo2_rd_update_adr)
  #define fm_aud_fifo_ctrl_adr                           0x00326c00                                                   // aud_fifo_regs_adr_base + 0x00000000
  #define fm_aud_fifo_ctrl                               (*(volatile unsigned int *)fm_aud_fifo_ctrl_adr)
  #define fm_aud_fifo_stop_adr                           0x00326c04                                                   // aud_fifo_regs_adr_base + 0x00000004
  #define fm_aud_fifo_stop                               (*(volatile unsigned int *)fm_aud_fifo_stop_adr)
  #define fm_aud_fifo_rxwl_adr                           0x00326c08                                                   // aud_fifo_regs_adr_base + 0x00000008
  #define fm_aud_fifo_rxwl                               (*(volatile unsigned int *)fm_aud_fifo_rxwl_adr)
  #define fm_aud_fifo_txwl_adr                           0x00326c0c                                                   // aud_fifo_regs_adr_base + 0x0000000c
  #define fm_aud_fifo_txwl                               (*(volatile unsigned int *)fm_aud_fifo_txwl_adr)
  #define fm_aud_fifo_status0_rx_adr                     0x00326c10                                                   // aud_fifo_regs_adr_base + 0x00000010
  #define fm_aud_fifo_status0_rx                         (*(volatile unsigned int *)fm_aud_fifo_status0_rx_adr)
  #define fm_aud_fifo_status1_rx_adr                     0x00326c14                                                   // aud_fifo_regs_adr_base + 0x00000014
  #define fm_aud_fifo_status1_rx                         (*(volatile unsigned int *)fm_aud_fifo_status1_rx_adr)
  #define fm_aud_fifo_status0_tx_adr                     0x00326c18                                                   // aud_fifo_regs_adr_base + 0x00000018
  #define fm_aud_fifo_status0_tx                         (*(volatile unsigned int *)fm_aud_fifo_status0_tx_adr)
  #define fm_aud_fifo_status1_tx_adr                     0x00326c1c                                                   // aud_fifo_regs_adr_base + 0x0000001c
  #define fm_aud_fifo_status1_tx                         (*(volatile unsigned int *)fm_aud_fifo_status1_tx_adr)
  #define fm_aud_fifo_rate_N_adr                         0x00326c20                                                   // aud_fifo_regs_adr_base + 0x00000020
  #define fm_aud_fifo_rate_N                             (*(volatile unsigned int *)fm_aud_fifo_rate_N_adr)
  #define fm_aud_fifo_rate_M_adr                         0x00326c24                                                   // aud_fifo_regs_adr_base + 0x00000024
  #define fm_aud_fifo_rate_M                             (*(volatile unsigned int *)fm_aud_fifo_rate_M_adr)
  #define fm_aud_fifo_divMN_en_adr                       0x00326c28                                                   // aud_fifo_regs_adr_base + 0x00000028
  #define fm_aud_fifo_divMN_en                           (*(volatile unsigned int *)fm_aud_fifo_divMN_en_adr)
  #define fm_aud_fifo_mstr_ctl_adr                       0x00326c2c                                                   // aud_fifo_regs_adr_base + 0x0000002c
  #define fm_aud_fifo_mstr_ctl                           (*(volatile unsigned int *)fm_aud_fifo_mstr_ctl_adr)
  #define fm_aud_fifo_MN_ctrl_adr                        0x00326c30                                                   // aud_fifo_regs_adr_base + 0x00000030
  #define fm_aud_fifo_MN_ctrl                            (*(volatile unsigned int *)fm_aud_fifo_MN_ctrl_adr)
  #define fm_aud_fifo_MN_update_adr                      0x00326c34                                                   // aud_fifo_regs_adr_base + 0x00000034
  #define fm_aud_fifo_MN_update                          (*(volatile unsigned int *)fm_aud_fifo_MN_update_adr)
  #define fm_aud_fifo_RdWr_cnt_adr                       0x00326c40                                                   // aud_fifo_regs_adr_base + 0x00000040
  #define fm_aud_fifo_RdWr_cnt                           (*(volatile unsigned int *)fm_aud_fifo_RdWr_cnt_adr)
  #define fm_aud_fifo_DMA_ctrl0_adr                      0x00326c44                                                   // aud_fifo_regs_adr_base + 0x00000044
  #define fm_aud_fifo_DMA_ctrl0                          (*(volatile unsigned int *)fm_aud_fifo_DMA_ctrl0_adr)
  #define fm_aud_fifo_DMA_stat0_adr                      0x00326c48                                                   // aud_fifo_regs_adr_base + 0x00000048
  #define fm_aud_fifo_DMA_stat0                          (*(volatile unsigned int *)fm_aud_fifo_DMA_stat0_adr)
  #define fm_aud_fifo_DMA_stat1_adr                      0x00326c4c                                                   // aud_fifo_regs_adr_base + 0x0000004c
  #define fm_aud_fifo_DMA_stat1                          (*(volatile unsigned int *)fm_aud_fifo_DMA_stat1_adr)
  #define fmm_fifo_pre_adr                               0x00325000                                                   // fmm_fifo_adr_base + 0x00000000
  #define fmm_fifo_pre                                   (*(volatile unsigned int *)fmm_fifo_pre_adr)
  #define fmm_fifo_rds_adr                               0x00325800                                                   // fmm_fifo_adr_base + 0x00000800
  #define fmm_fifo_rds                                   (*(volatile unsigned int *)fmm_fifo_rds_adr)
  #define dc_ptu_addr_adr                                0x00360000                                                   // ptu_adr_base + 0x00000000
  #define dc_ptu_addr                                    (*(volatile unsigned int *)dc_ptu_addr_adr)
  #define dp_ep2i_hci_pkglen_adr                         0x00360004                                                   // ptu_adr_base + 0x00000004
  #define dp_ep2i_hci_pkglen                             (*(volatile unsigned int *)dp_ep2i_hci_pkglen_adr)
  #define dc_ptu_rw_adr                                  0x00360008                                                   // ptu_adr_base + 0x00000008
  #define dc_ptu_rw                                      (*(volatile unsigned int *)dc_ptu_rw_adr)
  #define dc_ptu_status_adr                              0x0036000c                                                   // ptu_adr_base + 0x0000000c
  #define dc_ptu_status                                  (*(volatile unsigned int *)dc_ptu_status_adr)
  #define dc_ptu_hci_sel_adr                             0x00360010                                                   // ptu_adr_base + 0x00000010
  #define dc_ptu_hci_sel                                 (*(volatile unsigned int *)dc_ptu_hci_sel_adr)
  #define dc_ptu_hc_sel_adr                              0x00360014                                                   // ptu_adr_base + 0x00000014
  #define dc_ptu_hc_sel                                  (*(volatile unsigned int *)dc_ptu_hc_sel_adr)
  #define dc_ptu_sel_ctl_adr                             0x00360018                                                   // ptu_adr_base + 0x00000018
  #define dc_ptu_sel_ctl                                 (*(volatile unsigned int *)dc_ptu_sel_ctl_adr)
  #define dp_uart_data_adr                               0x0036001c                                                   // ptu_adr_base + 0x0000001c
  #define dp_uart_data                                   (*(volatile unsigned int *)dp_uart_data_adr)
  #define dp_ep0_data_adr                                0x00360020                                                   // ptu_adr_base + 0x00000020
  #define dp_ep0_data                                    (*(volatile unsigned int *)dp_ep0_data_adr)
  #define dp_ep1_data_adr                                0x00360024                                                   // ptu_adr_base + 0x00000024
  #define dp_ep1_data                                    (*(volatile unsigned int *)dp_ep1_data_adr)
  #define dp_ep2_data_adr                                0x00360028                                                   // ptu_adr_base + 0x00000028
  #define dp_ep2_data                                    (*(volatile unsigned int *)dp_ep2_data_adr)
  #define dp_ep3_data_adr                                0x0036002c                                                   // ptu_adr_base + 0x0000002c
  #define dp_ep3_data                                    (*(volatile unsigned int *)dp_ep3_data_adr)
  #define dp_ep4_data_adr                                0x00360030                                                   // ptu_adr_base + 0x00000030
  #define dp_ep4_data                                    (*(volatile unsigned int *)dp_ep4_data_adr)
  #define dp_ep_trg_adr                                  0x00360034                                                   // ptu_adr_base + 0x00000034
  #define dp_ep_trg                                      (*(volatile unsigned int *)dp_ep_trg_adr)
  #define dp_ep0_pklen_adr                               0x00360038                                                   // ptu_adr_base + 0x00000038
  #define dp_ep0_pklen                                   (*(volatile unsigned int *)dp_ep0_pklen_adr)
  #define dp_ep2_pklen_adr                               0x0036003c                                                   // ptu_adr_base + 0x0000003c
  #define dp_ep2_pklen                                   (*(volatile unsigned int *)dp_ep2_pklen_adr)
  #define dp_ep3_pklen_adr                               0x00360040                                                   // ptu_adr_base + 0x00000040
  #define dp_ep3_pklen                                   (*(volatile unsigned int *)dp_ep3_pklen_adr)
  #define dp_ep4_pklen_adr                               0x00360044                                                   // ptu_adr_base + 0x00000044
  #define dp_ep4_pklen                                   (*(volatile unsigned int *)dp_ep4_pklen_adr)
  #define dp_ep2_dp_adr                                  0x00360048                                                   // ptu_adr_base + 0x00000048
  #define dp_ep2_dp                                      (*(volatile unsigned int *)dp_ep2_dp_adr)
  #define dp2_ep0_data_adr                               0x0036004c                                                   // ptu_adr_base + 0x0000004c
  #define dp2_ep0_data                                   (*(volatile unsigned int *)dp2_ep0_data_adr)
  #define dp2_ep1_data_adr                               0x00360050                                                   // ptu_adr_base + 0x00000050
  #define dp2_ep1_data                                   (*(volatile unsigned int *)dp2_ep1_data_adr)
  #define dp2_ep_trg_adr                                 0x00360054                                                   // ptu_adr_base + 0x00000054
  #define dp2_ep_trg                                     (*(volatile unsigned int *)dp2_ep_trg_adr)
  #define dp2_ep0_pklen_adr                              0x00360058                                                   // ptu_adr_base + 0x00000058
  #define dp2_ep0_pklen                                  (*(volatile unsigned int *)dp2_ep0_pklen_adr)
  #define dp3_ep0_data_adr                               0x0036005c                                                   // ptu_adr_base + 0x0000005c
  #define dp3_ep0_data                                   (*(volatile unsigned int *)dp3_ep0_data_adr)
  #define dp3_ep1_data_adr                               0x00360060                                                   // ptu_adr_base + 0x00000060
  #define dp3_ep1_data                                   (*(volatile unsigned int *)dp3_ep1_data_adr)
  #define dp3_ep_trg_adr                                 0x00360064                                                   // ptu_adr_base + 0x00000064
  #define dp3_ep_trg                                     (*(volatile unsigned int *)dp3_ep_trg_adr)
  #define dp3_ep0_pklen_adr                              0x00360068                                                   // ptu_adr_base + 0x00000068
  #define dp3_ep0_pklen                                  (*(volatile unsigned int *)dp3_ep0_pklen_adr)
  #define dc_ptu_hubcur_adr                              0x0036006c                                                   // ptu_adr_base + 0x0000006c
  #define dc_ptu_hubcur                                  (*(volatile unsigned int *)dc_ptu_hubcur_adr)
  #define srptu_base                                     0x00360074                                                   // dp_tail + 0x00000004
  #define sr_ptu_status_adr0                             0x00360074                                                   // srptu_base + 0x00000000
  #define sr_ptu_status0                                 (*(volatile unsigned int *)sr_ptu_status_adr0)
  #define sr_ptu_status_adr1                             0x00360078                                                   // srptu_base + 0x00000004
  #define sr_ptu_status1                                 (*(volatile unsigned int *)sr_ptu_status_adr1)
  #define sr_ptu_status_adr2                             0x0036007c                                                   // srptu_base + 0x00000008
  #define sr_ptu_status2                                 (*(volatile unsigned int *)sr_ptu_status_adr2)
  #define sr_ptu_status_adr3                             0x00360080                                                   // srptu_base + 0x0000000c
  #define sr_ptu_status3                                 (*(volatile unsigned int *)sr_ptu_status_adr3)
  #define sr_ptu_status_adr4                             0x00360084                                                   // srptu_base + 0x00000010
  #define sr_ptu_status4                                 (*(volatile unsigned int *)sr_ptu_status_adr4)
  #define sr_ptu_status_adr5                             0x00360088                                                   // srptu_base + 0x00000014
  #define sr_ptu_status5                                 (*(volatile unsigned int *)sr_ptu_status_adr5)
  #define sr_ptu_status_adr6                             0x0036008c                                                   // srptu_base + 0x00000018
  #define sr_ptu_status6                                 (*(volatile unsigned int *)sr_ptu_status_adr6)
  #define sr_ptu_status_adr7                             0x00360090                                                   // srptu_base + 0x0000001c
  #define sr_ptu_status7                                 (*(volatile unsigned int *)sr_ptu_status_adr7)
  #define sr_ptu_status_adr8                             0x00360094                                                   // srptu_base + 0x00000020
  #define sr_ptu_status8                                 (*(volatile unsigned int *)sr_ptu_status_adr8)
  #define sr_ptu_en_adr0                                 0x00360098                                                   // srptu_base + 0x00000024
  #define sr_ptu_en0                                     (*(volatile unsigned int *)sr_ptu_en_adr0)
  #define sr_ptu_en_adr1                                 0x0036009c                                                   // srptu_base + 0x00000028
  #define sr_ptu_en1                                     (*(volatile unsigned int *)sr_ptu_en_adr1)
  #define sr_ptu_en_adr2                                 0x003600a0                                                   // srptu_base + 0x0000002c
  #define sr_ptu_en2                                     (*(volatile unsigned int *)sr_ptu_en_adr2)
  #define sr_ptu_en_adr3                                 0x003600a4                                                   // srptu_base + 0x00000030
  #define sr_ptu_en3                                     (*(volatile unsigned int *)sr_ptu_en_adr3)
  #define sr_ptu_en_adr4                                 0x003600a8                                                   // srptu_base + 0x00000034
  #define sr_ptu_en4                                     (*(volatile unsigned int *)sr_ptu_en_adr4)
  #define sr_ptu_en_adr5                                 0x003600ac                                                   // srptu_base + 0x00000038
  #define sr_ptu_en5                                     (*(volatile unsigned int *)sr_ptu_en_adr5)
  #define sr_ptu_en_adr6                                 0x003600b0                                                   // srptu_base + 0x0000003c
  #define sr_ptu_en6                                     (*(volatile unsigned int *)sr_ptu_en_adr6)
  #define sr_ptu_en_adr7                                 0x003600b4                                                   // srptu_base + 0x00000040
  #define sr_ptu_en7                                     (*(volatile unsigned int *)sr_ptu_en_adr7)
  #define sr_ptu_en_adr8                                 0x003600b8                                                   // srptu_base + 0x00000044
  #define sr_ptu_en8                                     (*(volatile unsigned int *)sr_ptu_en_adr8)
  #define sr_ptu_dis_adr0                                0x003600bc                                                   // srptu_base + 0x00000048
  #define sr_ptu_dis0                                    (*(volatile unsigned int *)sr_ptu_dis_adr0)
  #define sr_ptu_dis_adr1                                0x003600c0                                                   // srptu_base + 0x0000004c
  #define sr_ptu_dis1                                    (*(volatile unsigned int *)sr_ptu_dis_adr1)
  #define sr_ptu_dis_adr2                                0x003600c4                                                   // srptu_base + 0x00000050
  #define sr_ptu_dis2                                    (*(volatile unsigned int *)sr_ptu_dis_adr2)
  #define sr_ptu_dis_adr3                                0x003600c8                                                   // srptu_base + 0x00000054
  #define sr_ptu_dis3                                    (*(volatile unsigned int *)sr_ptu_dis_adr3)
  #define sr_ptu_dis_adr4                                0x003600cc                                                   // srptu_base + 0x00000058
  #define sr_ptu_dis4                                    (*(volatile unsigned int *)sr_ptu_dis_adr4)
  #define sr_ptu_test_adr0                               0x003600d0                                                   // srptu_base + 0x0000005c
  #define sr_ptu_test0                                   (*(volatile unsigned int *)sr_ptu_test_adr0)
  #define sr_ptu_test_adr1                               0x003600d4                                                   // srptu_base + 0x00000060
  #define sr_ptu_test1                                   (*(volatile unsigned int *)sr_ptu_test_adr1)
  #define sr_ptu_test_adr2                               0x003600d8                                                   // srptu_base + 0x00000064
  #define sr_ptu_test2                                   (*(volatile unsigned int *)sr_ptu_test_adr2)
  #define sr_ptu_test_adr3                               0x003600dc                                                   // srptu_base + 0x00000068
  #define sr_ptu_test3                                   (*(volatile unsigned int *)sr_ptu_test_adr3)
  #define sr_ptu_test_adr4                               0x003600e0                                                   // srptu_base + 0x0000006c
  #define sr_ptu_test4                                   (*(volatile unsigned int *)sr_ptu_test_adr4)
  #define sr_ptu_inv_adr                                 0x003600e4                                                   // srptu_base + 0x00000070
  #define sr_ptu_inv                                     (*(volatile unsigned int *)sr_ptu_inv_adr)
  #define dc_ptu_pwron2good_adr                          0x003600e8                                                   // srptu_base + 0x00000074
  #define dc_ptu_pwron2good                              (*(volatile unsigned int *)dc_ptu_pwron2good_adr)
  #define sr_ptu_status_adr9                             0x003600ec                                                   // srptu_base + 0x00000078
  #define sr_ptu_status9                                 (*(volatile unsigned int *)sr_ptu_status_adr9)
  #define sr_ptu_en_adr9                                 0x003600f0                                                   // srptu_base + 0x0000007c
  #define sr_ptu_en9                                     (*(volatile unsigned int *)sr_ptu_en_adr9)
  #define sr_ptu_dis_adr9                                0x003600f4                                                   // srptu_base + 0x00000080
  #define sr_ptu_dis9                                    (*(volatile unsigned int *)sr_ptu_dis_adr9)
  #define sr_ptu_test_adr9                               0x003600f8                                                   // srptu_base + 0x00000084
  #define sr_ptu_test9                                   (*(volatile unsigned int *)sr_ptu_test_adr9)
  #define dp_ep2o_hci_pkglen_adr                         0x003600fc                                                   // srptu_base + 0x00000088
  #define dp_ep2o_hci_pkglen                             (*(volatile unsigned int *)dp_ep2o_hci_pkglen_adr)
  #define WLAN_status_adr                                0x00360100                                                   // srptu_base + 0x0000008c
  #define WLAN_status                                    (*(volatile unsigned int *)WLAN_status_adr)
  #define WLAN_ctrl_adr                                  0x00360104                                                   // srptu_base + 0x00000090
  #define WLAN_ctrl                                      (*(volatile unsigned int *)WLAN_ctrl_adr)
  #define WLAN_dis_adr                                   0x00360108                                                   // srptu_base + 0x00000094
  #define WLAN_dis                                       (*(volatile unsigned int *)WLAN_dis_adr)
  #define WLAN_level_mask_adr                            0x0036010c                                                   // srptu_base + 0x00000098
  #define WLAN_level_mask                                (*(volatile unsigned int *)WLAN_level_mask_adr)
  #define WLAN_edge_mode_adr                             0x00360110                                                   // srptu_base + 0x0000009c
  #define WLAN_edge_mode                                 (*(volatile unsigned int *)WLAN_edge_mode_adr)
  #define dc_ptu_dbg_sel_adr                             0x00360114                                                   // srptu_base + 0x000000a0
  #define dc_ptu_dbg_sel                                 (*(volatile unsigned int *)dc_ptu_dbg_sel_adr)
  #define uart_base                                      0x00360400                                                   // ptu_adr_base + 0x00000400
  #define iic_base                                       0x00360a00                                                   // ptu_adr_base + 0x00000a00
  #define spi_base                                       0x00360600                                                   // ptu_adr_base + 0x00000600
  #define aa_base                                        0x00360700                                                   // ptu_adr_base + 0x00000700
  #define db_uart_base                                   0x00360800                                                   // ptu_adr_base + 0x00000800
  #define rtc_base                                       0x00360900                                                   // ptu_adr_base + 0x00000900
  #define dsdio_base                                     0x00361000                                                   // ptu_adr_base + 0x00001000
  #define hub_base                                       0x00362000                                                   // ptu_adr_base + 0x00002000
  #define usb0_usb_base                                  0x00363000                                                   // ptu_adr_base + 0x00003000
  #define usb1_usb_base                                  0x00363400                                                   // ptu_adr_base + 0x00003400
  #define usb2_usb_base                                  0x00363800                                                   // ptu_adr_base + 0x00003800
  #define xyz_base                                       0x00363000                                                   // ptu_adr_base + 0x00003000
  #define ram_adr                                        0x00200000                                                   // ram_adr_base + 0x00000000
  #define ram                                            (*(volatile unsigned int *)ram_adr)
  #define dc_ptu_uart_dhbr_adr                           0x00360400                                                   // uart_base + 0x00000000
  #define dc_ptu_uart_dhbr                               (*(volatile unsigned int *)dc_ptu_uart_dhbr_adr)
  #define dc_ptu_uart_dlbr_adr                           0x00360404                                                   // uart_base + 0x00000004
  #define dc_ptu_uart_dlbr                               (*(volatile unsigned int *)dc_ptu_uart_dlbr_adr)
  #define dc_ptu_uart_ab0_adr                            0x00360408                                                   // uart_base + 0x00000008
  #define dc_ptu_uart_ab0                                (*(volatile unsigned int *)dc_ptu_uart_ab0_adr)
  #define dc_ptu_uart_fcr_adr                            0x00360410                                                   // uart_base + 0x00000010
  #define dc_ptu_uart_fcr                                (*(volatile unsigned int *)dc_ptu_uart_fcr_adr)
  #define dc_ptu_uart_ab1_adr                            0x00360414                                                   // uart_base + 0x00000014
  #define dc_ptu_uart_ab1                                (*(volatile unsigned int *)dc_ptu_uart_ab1_adr)
  #define dc_ptu_uart_lcr_adr                            0x0036041c                                                   // uart_base + 0x0000001c
  #define dc_ptu_uart_lcr                                (*(volatile unsigned int *)dc_ptu_uart_lcr_adr)
  #define dc_ptu_uart_mcr_adr                            0x00360420                                                   // uart_base + 0x00000020
  #define dc_ptu_uart_mcr                                (*(volatile unsigned int *)dc_ptu_uart_mcr_adr)
  #define dc_ptu_uart_lsr_adr                            0x00360424                                                   // uart_base + 0x00000024
  #define dc_ptu_uart_lsr                                (*(volatile unsigned int *)dc_ptu_uart_lsr_adr)
  #define dc_ptu_uart_msr_adr                            0x00360428                                                   // uart_base + 0x00000028
  #define dc_ptu_uart_msr                                (*(volatile unsigned int *)dc_ptu_uart_msr_adr)
  #define dc_ptu_uart_rfl_adr                            0x0036042c                                                   // uart_base + 0x0000002c
  #define dc_ptu_uart_rfl                                (*(volatile unsigned int *)dc_ptu_uart_rfl_adr)
  #define dc_ptu_uart_tfl_adr                            0x00360430                                                   // uart_base + 0x00000030
  #define dc_ptu_uart_tfl                                (*(volatile unsigned int *)dc_ptu_uart_tfl_adr)
  #define dc_ptu_uart_rfc_adr                            0x00360434                                                   // uart_base + 0x00000034
  #define dc_ptu_uart_rfc                                (*(volatile unsigned int *)dc_ptu_uart_rfc_adr)
  #define dc_ptu_uart_esc_adr                            0x00360438                                                   // uart_base + 0x00000038
  #define dc_ptu_uart_esc                                (*(volatile unsigned int *)dc_ptu_uart_esc_adr)
  #define dc_ptu_uart_abr_adr                            0x0036043c                                                   // uart_base + 0x0000003c
  #define dc_ptu_uart_abr                                (*(volatile unsigned int *)dc_ptu_uart_abr_adr)
  #define dc_free32_adr                                  0x00360440                                                   // uart_base + 0x00000040
  #define dc_free32                                      (*(volatile unsigned int *)dc_free32_adr)
  #define dc_free32_ctl_adr                              0x00360444                                                   // uart_base + 0x00000044
  #define dc_free32_ctl                                  (*(volatile unsigned int *)dc_free32_ctl_adr)
  #define uart_ho_pklen_adr                              0x00360448                                                   // uart_base + 0x00000048
  #define uart_ho_pklen                                  (*(volatile unsigned int *)uart_ho_pklen_adr)
  #define uart_hi_pklen_adr                              0x0036044c                                                   // uart_base + 0x0000004c
  #define uart_hi_pklen                                  (*(volatile unsigned int *)uart_hi_pklen_adr)
  #define uart_ho_dma_ctl_adr                            0x00360450                                                   // uart_base + 0x00000050
  #define uart_ho_dma_ctl                                (*(volatile unsigned int *)uart_ho_dma_ctl_adr)
  #define uart_hi_dma_ctl_adr                            0x00360454                                                   // uart_base + 0x00000054
  #define uart_hi_dma_ctl                                (*(volatile unsigned int *)uart_hi_dma_ctl_adr)
  #define uart_ho_bsize_adr                              0x00360458                                                   // uart_base + 0x00000058
  #define uart_ho_bsize                                  (*(volatile unsigned int *)uart_ho_bsize_adr)
  #define uart_hi_bsize_adr                              0x0036045c                                                   // uart_base + 0x0000005c
  #define uart_hi_bsize                                  (*(volatile unsigned int *)uart_hi_bsize_adr)
  #define fpga_id_adr                                    0x00360460                                                   // uart_base + 0x00000060
  #define fpga_id                                        (*(volatile unsigned int *)fpga_id_adr)
  #define dc_ptu_uart_extra_ctrl_adr                     0x00360464                                                   // uart_base + 0x00000064
  #define dc_ptu_uart_extra_ctrl                         (*(volatile unsigned int *)dc_ptu_uart_extra_ctrl_adr)
  #define iic_caddr_wctl_adr                             0x00360a00                                                   // iic_base + 0x00000000
  #define iic_caddr_wctl                                 (*(volatile unsigned int *)iic_caddr_wctl_adr)
  #define iic_wdata_adr0                                 0x00360a04                                                   // iic_base + 0x00000004
  #define iic_wdata0                                     (*(volatile unsigned int *)iic_wdata_adr0)
  #define iic_wdata_adr1                                 0x00360a08                                                   // iic_base + 0x00000008
  #define iic_wdata1                                     (*(volatile unsigned int *)iic_wdata_adr1)
  #define iic_wdata_adr2                                 0x00360a0c                                                   // iic_base + 0x0000000c
  #define iic_wdata2                                     (*(volatile unsigned int *)iic_wdata_adr2)
  #define iic_wdata_adr3                                 0x00360a10                                                   // iic_base + 0x00000010
  #define iic_wdata3                                     (*(volatile unsigned int *)iic_wdata_adr3)
  #define iic_wdata_adr4                                 0x00360a14                                                   // iic_base + 0x00000014
  #define iic_wdata4                                     (*(volatile unsigned int *)iic_wdata_adr4)
  #define iic_wdata_adr5                                 0x00360a18                                                   // iic_base + 0x00000018
  #define iic_wdata5                                     (*(volatile unsigned int *)iic_wdata_adr5)
  #define iic_wdata_adr6                                 0x00360a1c                                                   // iic_base + 0x0000001c
  #define iic_wdata6                                     (*(volatile unsigned int *)iic_wdata_adr6)
  #define iic_wdata_adr7                                 0x00360a20                                                   // iic_base + 0x00000020
  #define iic_wdata7                                     (*(volatile unsigned int *)iic_wdata_adr7)
  #define iic_wdata_adr8                                 0x00360a24                                                   // iic_base + 0x00000024
  #define iic_wdata8                                     (*(volatile unsigned int *)iic_wdata_adr8)
  #define iic_wdata_adr9                                 0x00360a28                                                   // iic_base + 0x00000028
  #define iic_wdata9                                     (*(volatile unsigned int *)iic_wdata_adr9)
  #define iic_wdata_adr10                                0x00360a2c                                                   // iic_base + 0x0000002c
  #define iic_wdata10                                    (*(volatile unsigned int *)iic_wdata_adr10)
  #define iic_wdata_adr11                                0x00360a30                                                   // iic_base + 0x00000030
  #define iic_wdata11                                    (*(volatile unsigned int *)iic_wdata_adr11)
  #define iic_wdata_adr12                                0x00360a34                                                   // iic_base + 0x00000034
  #define iic_wdata12                                    (*(volatile unsigned int *)iic_wdata_adr12)
  #define iic_wdata_adr13                                0x00360a38                                                   // iic_base + 0x00000038
  #define iic_wdata13                                    (*(volatile unsigned int *)iic_wdata_adr13)
  #define iic_wdata_adr14                                0x00360a3c                                                   // iic_base + 0x0000003c
  #define iic_wdata14                                    (*(volatile unsigned int *)iic_wdata_adr14)
  #define iic_wdata_adr15                                0x00360a40                                                   // iic_base + 0x00000040
  #define iic_wdata15                                    (*(volatile unsigned int *)iic_wdata_adr15)
  #define iic_wdata_adr16                                0x00360a44                                                   // iic_base + 0x00000044
  #define iic_wdata16                                    (*(volatile unsigned int *)iic_wdata_adr16)
  #define iic_wdata_adr17                                0x00360a48                                                   // iic_base + 0x00000048
  #define iic_wdata17                                    (*(volatile unsigned int *)iic_wdata_adr17)
  #define iic_wdata_adr18                                0x00360a4c                                                   // iic_base + 0x0000004c
  #define iic_wdata18                                    (*(volatile unsigned int *)iic_wdata_adr18)
  #define iic_wdata_adr19                                0x00360a50                                                   // iic_base + 0x00000050
  #define iic_wdata19                                    (*(volatile unsigned int *)iic_wdata_adr19)
  #define iic_wdata_adr20                                0x00360a54                                                   // iic_base + 0x00000054
  #define iic_wdata20                                    (*(volatile unsigned int *)iic_wdata_adr20)
  #define iic_wdata_adr21                                0x00360a58                                                   // iic_base + 0x00000058
  #define iic_wdata21                                    (*(volatile unsigned int *)iic_wdata_adr21)
  #define iic_wdata_adr22                                0x00360a5c                                                   // iic_base + 0x0000005c
  #define iic_wdata22                                    (*(volatile unsigned int *)iic_wdata_adr22)
  #define iic_wdata_adr23                                0x00360a60                                                   // iic_base + 0x00000060
  #define iic_wdata23                                    (*(volatile unsigned int *)iic_wdata_adr23)
  #define iic_wdata_adr24                                0x00360a64                                                   // iic_base + 0x00000064
  #define iic_wdata24                                    (*(volatile unsigned int *)iic_wdata_adr24)
  #define iic_wdata_adr25                                0x00360a68                                                   // iic_base + 0x00000068
  #define iic_wdata25                                    (*(volatile unsigned int *)iic_wdata_adr25)
  #define iic_wdata_adr26                                0x00360a6c                                                   // iic_base + 0x0000006c
  #define iic_wdata26                                    (*(volatile unsigned int *)iic_wdata_adr26)
  #define iic_wdata_adr27                                0x00360a70                                                   // iic_base + 0x00000070
  #define iic_wdata27                                    (*(volatile unsigned int *)iic_wdata_adr27)
  #define iic_wdata_adr28                                0x00360a74                                                   // iic_base + 0x00000074
  #define iic_wdata28                                    (*(volatile unsigned int *)iic_wdata_adr28)
  #define iic_wdata_adr29                                0x00360a78                                                   // iic_base + 0x00000078
  #define iic_wdata29                                    (*(volatile unsigned int *)iic_wdata_adr29)
  #define iic_wdata_adr30                                0x00360a7c                                                   // iic_base + 0x0000007c
  #define iic_wdata30                                    (*(volatile unsigned int *)iic_wdata_adr30)
  #define iic_wdata_adr31                                0x00360a80                                                   // iic_base + 0x00000080
  #define iic_wdata31                                    (*(volatile unsigned int *)iic_wdata_adr31)
  #define iic_wdata_adr32                                0x00360a84                                                   // iic_base + 0x00000084
  #define iic_wdata32                                    (*(volatile unsigned int *)iic_wdata_adr32)
  #define iic_wdata_adr33                                0x00360a88                                                   // iic_base + 0x00000088
  #define iic_wdata33                                    (*(volatile unsigned int *)iic_wdata_adr33)
  #define iic_wdata_adr34                                0x00360a8c                                                   // iic_base + 0x0000008c
  #define iic_wdata34                                    (*(volatile unsigned int *)iic_wdata_adr34)
  #define iic_wdata_adr35                                0x00360a90                                                   // iic_base + 0x00000090
  #define iic_wdata35                                    (*(volatile unsigned int *)iic_wdata_adr35)
  #define iic_wdata_adr36                                0x00360a94                                                   // iic_base + 0x00000094
  #define iic_wdata36                                    (*(volatile unsigned int *)iic_wdata_adr36)
  #define iic_wdata_adr37                                0x00360a98                                                   // iic_base + 0x00000098
  #define iic_wdata37                                    (*(volatile unsigned int *)iic_wdata_adr37)
  #define iic_wdata_adr38                                0x00360a9c                                                   // iic_base + 0x0000009c
  #define iic_wdata38                                    (*(volatile unsigned int *)iic_wdata_adr38)
  #define iic_wdata_adr39                                0x00360aa0                                                   // iic_base + 0x000000a0
  #define iic_wdata39                                    (*(volatile unsigned int *)iic_wdata_adr39)
  #define iic_wdata_adr40                                0x00360aa4                                                   // iic_base + 0x000000a4
  #define iic_wdata40                                    (*(volatile unsigned int *)iic_wdata_adr40)
  #define iic_wdata_adr41                                0x00360aa8                                                   // iic_base + 0x000000a8
  #define iic_wdata41                                    (*(volatile unsigned int *)iic_wdata_adr41)
  #define iic_wdata_adr42                                0x00360aac                                                   // iic_base + 0x000000ac
  #define iic_wdata42                                    (*(volatile unsigned int *)iic_wdata_adr42)
  #define iic_wdata_adr43                                0x00360ab0                                                   // iic_base + 0x000000b0
  #define iic_wdata43                                    (*(volatile unsigned int *)iic_wdata_adr43)
  #define iic_wdata_adr44                                0x00360ab4                                                   // iic_base + 0x000000b4
  #define iic_wdata44                                    (*(volatile unsigned int *)iic_wdata_adr44)
  #define iic_wdata_adr45                                0x00360ab8                                                   // iic_base + 0x000000b8
  #define iic_wdata45                                    (*(volatile unsigned int *)iic_wdata_adr45)
  #define iic_wdata_adr46                                0x00360abc                                                   // iic_base + 0x000000bc
  #define iic_wdata46                                    (*(volatile unsigned int *)iic_wdata_adr46)
  #define iic_wdata_adr47                                0x00360ac0                                                   // iic_base + 0x000000c0
  #define iic_wdata47                                    (*(volatile unsigned int *)iic_wdata_adr47)
  #define iic_wdata_adr48                                0x00360ac4                                                   // iic_base + 0x000000c4
  #define iic_wdata48                                    (*(volatile unsigned int *)iic_wdata_adr48)
  #define iic_wdata_adr49                                0x00360ac8                                                   // iic_base + 0x000000c8
  #define iic_wdata49                                    (*(volatile unsigned int *)iic_wdata_adr49)
  #define iic_wdata_adr50                                0x00360acc                                                   // iic_base + 0x000000cc
  #define iic_wdata50                                    (*(volatile unsigned int *)iic_wdata_adr50)
  #define iic_wdata_adr51                                0x00360ad0                                                   // iic_base + 0x000000d0
  #define iic_wdata51                                    (*(volatile unsigned int *)iic_wdata_adr51)
  #define iic_wdata_adr52                                0x00360ad4                                                   // iic_base + 0x000000d4
  #define iic_wdata52                                    (*(volatile unsigned int *)iic_wdata_adr52)
  #define iic_wdata_adr53                                0x00360ad8                                                   // iic_base + 0x000000d8
  #define iic_wdata53                                    (*(volatile unsigned int *)iic_wdata_adr53)
  #define iic_wdata_adr54                                0x00360adc                                                   // iic_base + 0x000000dc
  #define iic_wdata54                                    (*(volatile unsigned int *)iic_wdata_adr54)
  #define iic_wdata_adr55                                0x00360ae0                                                   // iic_base + 0x000000e0
  #define iic_wdata55                                    (*(volatile unsigned int *)iic_wdata_adr55)
  #define iic_wdata_adr56                                0x00360ae4                                                   // iic_base + 0x000000e4
  #define iic_wdata56                                    (*(volatile unsigned int *)iic_wdata_adr56)
  #define iic_wdata_adr57                                0x00360ae8                                                   // iic_base + 0x000000e8
  #define iic_wdata57                                    (*(volatile unsigned int *)iic_wdata_adr57)
  #define iic_wdata_adr58                                0x00360aec                                                   // iic_base + 0x000000ec
  #define iic_wdata58                                    (*(volatile unsigned int *)iic_wdata_adr58)
  #define iic_wdata_adr59                                0x00360af0                                                   // iic_base + 0x000000f0
  #define iic_wdata59                                    (*(volatile unsigned int *)iic_wdata_adr59)
  #define iic_wdata_adr60                                0x00360af4                                                   // iic_base + 0x000000f4
  #define iic_wdata60                                    (*(volatile unsigned int *)iic_wdata_adr60)
  #define iic_wdata_adr61                                0x00360af8                                                   // iic_base + 0x000000f8
  #define iic_wdata61                                    (*(volatile unsigned int *)iic_wdata_adr61)
  #define iic_wdata_adr62                                0x00360afc                                                   // iic_base + 0x000000fc
  #define iic_wdata62                                    (*(volatile unsigned int *)iic_wdata_adr62)
  #define iic_wdata_adr63                                0x00360b00                                                   // iic_base + 0x00000100
  #define iic_wdata63                                    (*(volatile unsigned int *)iic_wdata_adr63)
  #define iic_byte_cnt_adr                               0x00360b04                                                   // iic_base + 0x00000104
  #define iic_byte_cnt                                   (*(volatile unsigned int *)iic_byte_cnt_adr)
  #define iic_ctl_adr                                    0x00360b08                                                   // iic_base + 0x00000108
  #define iic_ctl                                        (*(volatile unsigned int *)iic_ctl_adr)
  #define iic_rd_en_int_adr                              0x00360b0c                                                   // iic_base + 0x0000010c
  #define iic_rd_en_int                                  (*(volatile unsigned int *)iic_rd_en_int_adr)
  #define iic_rdata_adr0                                 0x00360b10                                                   // iic_base + 0x00000110
  #define iic_rdata0                                     (*(volatile unsigned int *)iic_rdata_adr0)
  #define iic_rdata_adr1                                 0x00360b14                                                   // iic_base + 0x00000114
  #define iic_rdata1                                     (*(volatile unsigned int *)iic_rdata_adr1)
  #define iic_rdata_adr2                                 0x00360b18                                                   // iic_base + 0x00000118
  #define iic_rdata2                                     (*(volatile unsigned int *)iic_rdata_adr2)
  #define iic_rdata_adr3                                 0x00360b1c                                                   // iic_base + 0x0000011c
  #define iic_rdata3                                     (*(volatile unsigned int *)iic_rdata_adr3)
  #define iic_rdata_adr4                                 0x00360b20                                                   // iic_base + 0x00000120
  #define iic_rdata4                                     (*(volatile unsigned int *)iic_rdata_adr4)
  #define iic_rdata_adr5                                 0x00360b24                                                   // iic_base + 0x00000124
  #define iic_rdata5                                     (*(volatile unsigned int *)iic_rdata_adr5)
  #define iic_rdata_adr6                                 0x00360b28                                                   // iic_base + 0x00000128
  #define iic_rdata6                                     (*(volatile unsigned int *)iic_rdata_adr6)
  #define iic_rdata_adr7                                 0x00360b2c                                                   // iic_base + 0x0000012c
  #define iic_rdata7                                     (*(volatile unsigned int *)iic_rdata_adr7)
  #define iic_rdata_adr8                                 0x00360b30                                                   // iic_base + 0x00000130
  #define iic_rdata8                                     (*(volatile unsigned int *)iic_rdata_adr8)
  #define iic_rdata_adr9                                 0x00360b34                                                   // iic_base + 0x00000134
  #define iic_rdata9                                     (*(volatile unsigned int *)iic_rdata_adr9)
  #define iic_rdata_adr10                                0x00360b38                                                   // iic_base + 0x00000138
  #define iic_rdata10                                    (*(volatile unsigned int *)iic_rdata_adr10)
  #define iic_rdata_adr11                                0x00360b3c                                                   // iic_base + 0x0000013c
  #define iic_rdata11                                    (*(volatile unsigned int *)iic_rdata_adr11)
  #define iic_rdata_adr12                                0x00360b40                                                   // iic_base + 0x00000140
  #define iic_rdata12                                    (*(volatile unsigned int *)iic_rdata_adr12)
  #define iic_rdata_adr13                                0x00360b44                                                   // iic_base + 0x00000144
  #define iic_rdata13                                    (*(volatile unsigned int *)iic_rdata_adr13)
  #define iic_rdata_adr14                                0x00360b48                                                   // iic_base + 0x00000148
  #define iic_rdata14                                    (*(volatile unsigned int *)iic_rdata_adr14)
  #define iic_rdata_adr15                                0x00360b4c                                                   // iic_base + 0x0000014c
  #define iic_rdata15                                    (*(volatile unsigned int *)iic_rdata_adr15)
  #define iic_rdata_adr16                                0x00360b50                                                   // iic_base + 0x00000150
  #define iic_rdata16                                    (*(volatile unsigned int *)iic_rdata_adr16)
  #define iic_rdata_adr17                                0x00360b54                                                   // iic_base + 0x00000154
  #define iic_rdata17                                    (*(volatile unsigned int *)iic_rdata_adr17)
  #define iic_rdata_adr18                                0x00360b58                                                   // iic_base + 0x00000158
  #define iic_rdata18                                    (*(volatile unsigned int *)iic_rdata_adr18)
  #define iic_rdata_adr19                                0x00360b5c                                                   // iic_base + 0x0000015c
  #define iic_rdata19                                    (*(volatile unsigned int *)iic_rdata_adr19)
  #define iic_rdata_adr20                                0x00360b60                                                   // iic_base + 0x00000160
  #define iic_rdata20                                    (*(volatile unsigned int *)iic_rdata_adr20)
  #define iic_rdata_adr21                                0x00360b64                                                   // iic_base + 0x00000164
  #define iic_rdata21                                    (*(volatile unsigned int *)iic_rdata_adr21)
  #define iic_rdata_adr22                                0x00360b68                                                   // iic_base + 0x00000168
  #define iic_rdata22                                    (*(volatile unsigned int *)iic_rdata_adr22)
  #define iic_rdata_adr23                                0x00360b6c                                                   // iic_base + 0x0000016c
  #define iic_rdata23                                    (*(volatile unsigned int *)iic_rdata_adr23)
  #define iic_rdata_adr24                                0x00360b70                                                   // iic_base + 0x00000170
  #define iic_rdata24                                    (*(volatile unsigned int *)iic_rdata_adr24)
  #define iic_rdata_adr25                                0x00360b74                                                   // iic_base + 0x00000174
  #define iic_rdata25                                    (*(volatile unsigned int *)iic_rdata_adr25)
  #define iic_rdata_adr26                                0x00360b78                                                   // iic_base + 0x00000178
  #define iic_rdata26                                    (*(volatile unsigned int *)iic_rdata_adr26)
  #define iic_rdata_adr27                                0x00360b7c                                                   // iic_base + 0x0000017c
  #define iic_rdata27                                    (*(volatile unsigned int *)iic_rdata_adr27)
  #define iic_rdata_adr28                                0x00360b80                                                   // iic_base + 0x00000180
  #define iic_rdata28                                    (*(volatile unsigned int *)iic_rdata_adr28)
  #define iic_rdata_adr29                                0x00360b84                                                   // iic_base + 0x00000184
  #define iic_rdata29                                    (*(volatile unsigned int *)iic_rdata_adr29)
  #define iic_rdata_adr30                                0x00360b88                                                   // iic_base + 0x00000188
  #define iic_rdata30                                    (*(volatile unsigned int *)iic_rdata_adr30)
  #define iic_rdata_adr31                                0x00360b8c                                                   // iic_base + 0x0000018c
  #define iic_rdata31                                    (*(volatile unsigned int *)iic_rdata_adr31)
  #define iic_rdata_adr32                                0x00360b90                                                   // iic_base + 0x00000190
  #define iic_rdata32                                    (*(volatile unsigned int *)iic_rdata_adr32)
  #define iic_rdata_adr33                                0x00360b94                                                   // iic_base + 0x00000194
  #define iic_rdata33                                    (*(volatile unsigned int *)iic_rdata_adr33)
  #define iic_rdata_adr34                                0x00360b98                                                   // iic_base + 0x00000198
  #define iic_rdata34                                    (*(volatile unsigned int *)iic_rdata_adr34)
  #define iic_rdata_adr35                                0x00360b9c                                                   // iic_base + 0x0000019c
  #define iic_rdata35                                    (*(volatile unsigned int *)iic_rdata_adr35)
  #define iic_rdata_adr36                                0x00360ba0                                                   // iic_base + 0x000001a0
  #define iic_rdata36                                    (*(volatile unsigned int *)iic_rdata_adr36)
  #define iic_rdata_adr37                                0x00360ba4                                                   // iic_base + 0x000001a4
  #define iic_rdata37                                    (*(volatile unsigned int *)iic_rdata_adr37)
  #define iic_rdata_adr38                                0x00360ba8                                                   // iic_base + 0x000001a8
  #define iic_rdata38                                    (*(volatile unsigned int *)iic_rdata_adr38)
  #define iic_rdata_adr39                                0x00360bac                                                   // iic_base + 0x000001ac
  #define iic_rdata39                                    (*(volatile unsigned int *)iic_rdata_adr39)
  #define iic_rdata_adr40                                0x00360bb0                                                   // iic_base + 0x000001b0
  #define iic_rdata40                                    (*(volatile unsigned int *)iic_rdata_adr40)
  #define iic_rdata_adr41                                0x00360bb4                                                   // iic_base + 0x000001b4
  #define iic_rdata41                                    (*(volatile unsigned int *)iic_rdata_adr41)
  #define iic_rdata_adr42                                0x00360bb8                                                   // iic_base + 0x000001b8
  #define iic_rdata42                                    (*(volatile unsigned int *)iic_rdata_adr42)
  #define iic_rdata_adr43                                0x00360bbc                                                   // iic_base + 0x000001bc
  #define iic_rdata43                                    (*(volatile unsigned int *)iic_rdata_adr43)
  #define iic_rdata_adr44                                0x00360bc0                                                   // iic_base + 0x000001c0
  #define iic_rdata44                                    (*(volatile unsigned int *)iic_rdata_adr44)
  #define iic_rdata_adr45                                0x00360bc4                                                   // iic_base + 0x000001c4
  #define iic_rdata45                                    (*(volatile unsigned int *)iic_rdata_adr45)
  #define iic_rdata_adr46                                0x00360bc8                                                   // iic_base + 0x000001c8
  #define iic_rdata46                                    (*(volatile unsigned int *)iic_rdata_adr46)
  #define iic_rdata_adr47                                0x00360bcc                                                   // iic_base + 0x000001cc
  #define iic_rdata47                                    (*(volatile unsigned int *)iic_rdata_adr47)
  #define iic_rdata_adr48                                0x00360bd0                                                   // iic_base + 0x000001d0
  #define iic_rdata48                                    (*(volatile unsigned int *)iic_rdata_adr48)
  #define iic_rdata_adr49                                0x00360bd4                                                   // iic_base + 0x000001d4
  #define iic_rdata49                                    (*(volatile unsigned int *)iic_rdata_adr49)
  #define iic_rdata_adr50                                0x00360bd8                                                   // iic_base + 0x000001d8
  #define iic_rdata50                                    (*(volatile unsigned int *)iic_rdata_adr50)
  #define iic_rdata_adr51                                0x00360bdc                                                   // iic_base + 0x000001dc
  #define iic_rdata51                                    (*(volatile unsigned int *)iic_rdata_adr51)
  #define iic_rdata_adr52                                0x00360be0                                                   // iic_base + 0x000001e0
  #define iic_rdata52                                    (*(volatile unsigned int *)iic_rdata_adr52)
  #define iic_rdata_adr53                                0x00360be4                                                   // iic_base + 0x000001e4
  #define iic_rdata53                                    (*(volatile unsigned int *)iic_rdata_adr53)
  #define iic_rdata_adr54                                0x00360be8                                                   // iic_base + 0x000001e8
  #define iic_rdata54                                    (*(volatile unsigned int *)iic_rdata_adr54)
  #define iic_rdata_adr55                                0x00360bec                                                   // iic_base + 0x000001ec
  #define iic_rdata55                                    (*(volatile unsigned int *)iic_rdata_adr55)
  #define iic_rdata_adr56                                0x00360bf0                                                   // iic_base + 0x000001f0
  #define iic_rdata56                                    (*(volatile unsigned int *)iic_rdata_adr56)
  #define iic_rdata_adr57                                0x00360bf4                                                   // iic_base + 0x000001f4
  #define iic_rdata57                                    (*(volatile unsigned int *)iic_rdata_adr57)
  #define iic_rdata_adr58                                0x00360bf8                                                   // iic_base + 0x000001f8
  #define iic_rdata58                                    (*(volatile unsigned int *)iic_rdata_adr58)
  #define iic_rdata_adr59                                0x00360bfc                                                   // iic_base + 0x000001fc
  #define iic_rdata59                                    (*(volatile unsigned int *)iic_rdata_adr59)
  #define iic_rdata_adr60                                0x00360c00                                                   // iic_base + 0x00000200
  #define iic_rdata60                                    (*(volatile unsigned int *)iic_rdata_adr60)
  #define iic_rdata_adr61                                0x00360c04                                                   // iic_base + 0x00000204
  #define iic_rdata61                                    (*(volatile unsigned int *)iic_rdata_adr61)
  #define iic_rdata_adr62                                0x00360c08                                                   // iic_base + 0x00000208
  #define iic_rdata62                                    (*(volatile unsigned int *)iic_rdata_adr62)
  #define iic_rdata_adr63                                0x00360c0c                                                   // iic_base + 0x0000020c
  #define iic_rdata63                                    (*(volatile unsigned int *)iic_rdata_adr63)
  #define iic_scl_maxcnt_adr                             0x00360c10                                                   // iic_base + 0x00000210
  #define iic_scl_maxcnt                                 (*(volatile unsigned int *)iic_scl_maxcnt_adr)
  #define iic_scl_div_adr                                0x00360c14                                                   // iic_base + 0x00000214
  #define iic_scl_div                                    (*(volatile unsigned int *)iic_scl_div_adr)
  #define iic_scl_maxcnt_adr1                            0x00360c18                                                   // iic_base + 0x00000218
  #define iic_scl_maxcnt1                                (*(volatile unsigned int *)iic_scl_maxcnt_adr1)
  #define iic_scl_div_adr1                               0x00360c1c                                                   // iic_base + 0x0000021c
  #define iic_scl_div1                                   (*(volatile unsigned int *)iic_scl_div_adr1)
  #define db_uart_dhbr_adr                               0x00360800                                                   // db_uart_base + 0x00000000
  #define db_uart_dhbr                                   (*(volatile unsigned int *)db_uart_dhbr_adr)
  #define db_uart_dlbr_adr                               0x00360804                                                   // db_uart_base + 0x00000004
  #define db_uart_dlbr                                   (*(volatile unsigned int *)db_uart_dlbr_adr)
  #define db_uart_fcr_adr                                0x00360808                                                   // db_uart_base + 0x00000008
  #define db_uart_fcr                                    (*(volatile unsigned int *)db_uart_fcr_adr)
  #define db_uart_lcr_adr                                0x0036080c                                                   // db_uart_base + 0x0000000c
  #define db_uart_lcr                                    (*(volatile unsigned int *)db_uart_lcr_adr)
  #define db_uart_mcr_adr                                0x00360810                                                   // db_uart_base + 0x00000010
  #define db_uart_mcr                                    (*(volatile unsigned int *)db_uart_mcr_adr)
  #define db_uart_lsr_adr                                0x00360814                                                   // db_uart_base + 0x00000014
  #define db_uart_lsr                                    (*(volatile unsigned int *)db_uart_lsr_adr)
  #define db_uart_msr_adr                                0x00360818                                                   // db_uart_base + 0x00000018
  #define db_uart_msr                                    (*(volatile unsigned int *)db_uart_msr_adr)
  #define db_uart_data_adr                               0x0036081c                                                   // db_uart_base + 0x0000001c
  #define db_uart_data                                   (*(volatile unsigned int *)db_uart_data_adr)
  #define db_uart_snap_adr                               0x00360820                                                   // db_uart_base + 0x00000020
  #define db_uart_snap                                   (*(volatile unsigned int *)db_uart_snap_adr)
  #define db_uart_txw_adr                                0x00360824                                                   // db_uart_base + 0x00000024
  #define db_uart_txw                                    (*(volatile unsigned int *)db_uart_txw_adr)
  #define db_uart_rxw_adr                                0x00360828                                                   // db_uart_base + 0x00000028
  #define db_uart_rxw                                    (*(volatile unsigned int *)db_uart_rxw_adr)
  #define rtc_ucodem_start_adr                           0x00360900                                                   // rtc_base + 0x00000000
  #define rtc_ucodem_start                               (*(volatile unsigned int *)rtc_ucodem_start_adr)
  #define rtc_ucodem_stop_adr                            0x00360aff                                                   // rtc_base + 0x000001ff
  #define rtc_ucodem_stop                                (*(volatile unsigned int *)rtc_ucodem_stop_adr)
  #define rtc_tapm_stop_adr                              0x00360bff                                                   // rtc_base + 0x000002ff
  #define rtc_tapm_stop                                  (*(volatile unsigned int *)rtc_tapm_stop_adr)
  #define rtc_coeffm_stop_adr                            0x00360cff                                                   // rtc_base + 0x000003ff
  #define rtc_coeffm_stop                                (*(volatile unsigned int *)rtc_coeffm_stop_adr)
  #define rtc_integerd_adr                               0x00360d00                                                   // rtc_base + 0x00000400
  #define rtc_integerd                                   (*(volatile unsigned int *)rtc_integerd_adr)
  #define rtc_fractiond_adr                              0x00360d04                                                   // rtc_base + 0x00000404
  #define rtc_fractiond                                  (*(volatile unsigned int *)rtc_fractiond_adr)
  #define rtc_initial_pc_adr                             0x00360d08                                                   // rtc_base + 0x00000408
  #define rtc_initial_pc                                 (*(volatile unsigned int *)rtc_initial_pc_adr)
  #define rtc_config_adr                                 0x00360d0c                                                   // rtc_base + 0x0000040c
  #define rtc_config                                     (*(volatile unsigned int *)rtc_config_adr)
  #define dc_ptu_aux_rw_adr                              0x00350000                                                   // ptu_aux_adr_base + 0x00000000
  #define dc_ptu_aux_rw                                  (*(volatile unsigned int *)dc_ptu_aux_rw_adr)
  #define dc_ptu_aux_status_adr                          0x00350004                                                   // ptu_aux_adr_base + 0x00000004
  #define dc_ptu_aux_status                              (*(volatile unsigned int *)dc_ptu_aux_status_adr)
  #define dc_ptu_aux_hci_sel_adr                         0x00350008                                                   // ptu_aux_adr_base + 0x00000008
  #define dc_ptu_aux_hci_sel                             (*(volatile unsigned int *)dc_ptu_aux_hci_sel_adr)
  #define dc_ptu_aux_hc_sel_adr                          0x0035000c                                                   // ptu_aux_adr_base + 0x0000000c
  #define dc_ptu_aux_hc_sel                              (*(volatile unsigned int *)dc_ptu_aux_hc_sel_adr)
  #define dc_ptu_aux_sel_ctl_adr                         0x00350010                                                   // ptu_aux_adr_base + 0x00000010
  #define dc_ptu_aux_sel_ctl                             (*(volatile unsigned int *)dc_ptu_aux_sel_ctl_adr)
  #define dc_ptu_aux_ws_cfg_adr                          0x00350014                                                   // ptu_aux_adr_base + 0x00000014
  #define dc_ptu_aux_ws_cfg                              (*(volatile unsigned int *)dc_ptu_aux_ws_cfg_adr)
  #define dc_ptu_aux_reset_level_adr                     0x00350018                                                   // ptu_aux_adr_base + 0x00000018
  #define dc_ptu_aux_reset_level                         (*(volatile unsigned int *)dc_ptu_aux_reset_level_adr)
  #define dc_ptu_aux_reset_pulse_adr                     0x0035001c                                                   // ptu_aux_adr_base + 0x0000001c
  #define dc_ptu_aux_reset_pulse                         (*(volatile unsigned int *)dc_ptu_aux_reset_pulse_adr)
  #define dc_ptu_aux_clk_cfg_adr                         0x00350020                                                   // ptu_aux_adr_base + 0x00000020
  #define dc_ptu_aux_clk_cfg                             (*(volatile unsigned int *)dc_ptu_aux_clk_cfg_adr)
  #define srptuaux_base                                  0x00350024                                                   // dc_ptu_aux_tail
  #define sr_ptu_aux_status_adr0                         0x00350024                                                   // srptuaux_base + 0x00000000
  #define sr_ptu_aux_status0                             (*(volatile unsigned int *)sr_ptu_aux_status_adr0)
  #define sr_ptu_aux_en_adr0                             0x00350028                                                   // srptuaux_base + 0x00000004
  #define sr_ptu_aux_en0                                 (*(volatile unsigned int *)sr_ptu_aux_en_adr0)
  #define crptuaux_base                                  0x0035002c                                                   // sr_ptu_aux_tail
  #define cr_pulse_reset_ptu_aux_adr                     0x0035002c                                                   // crptuaux_base + 0x00000000
  #define cr_pulse_reset_ptu_aux                         (*(volatile unsigned int *)cr_pulse_reset_ptu_aux_adr)
  #define cr_level_reset_ptu_aux_adr                     0x00350030                                                   // crptuaux_base + 0x00000004
  #define cr_level_reset_ptu_aux                         (*(volatile unsigned int *)cr_level_reset_ptu_aux_adr)
  #define cr_ptu_aux_clk_en_adr                          0x00350034                                                   // crptuaux_base + 0x00000008
  #define cr_ptu_aux_clk_en                              (*(volatile unsigned int *)cr_ptu_aux_clk_en_adr)
  #define cr_ptu_aux_clk_gate_on_adr                     0x00350038                                                   // crptuaux_base + 0x0000000c
  #define cr_ptu_aux_clk_gate_on                         (*(volatile unsigned int *)cr_ptu_aux_clk_gate_on_adr)
  #define cr_ptu_aux_clk_gate_off_adr                    0x0035003c                                                   // crptuaux_base + 0x00000010
  #define cr_ptu_aux_clk_gate_off                        (*(volatile unsigned int *)cr_ptu_aux_clk_gate_off_adr)
  #define ptu_aux_dbg_sel_adr                            0x00350040                                                   // crptuaux_base + 0x00000014
  #define ptu_aux_dbg_sel                                (*(volatile unsigned int *)ptu_aux_dbg_sel_adr)
  #define aud_fdiv_slim_btp_sel_adr                      0x00350044                                                   // crptuaux_base + 0x00000018
  #define aud_fdiv_slim_btp_sel                          (*(volatile unsigned int *)aud_fdiv_slim_btp_sel_adr)
  #define pcm_base                                       0x00351000                                                   // ptu_aux_adr_base + 0x00001000
  #define slim_base                                      0x0035c000                                                   // ptu_aux_adr_base + 0x0000c000
  #define aburst_base                                    0x00352000                                                   // ptu_aux_adr_base + 0x00002000
  #define pcm2_base                                      0x00352100                                                   // ptu_aux_adr_base + 0x00002100
  #define uart2_base                                     0x00352200                                                   // ptu_aux_adr_base + 0x00002200
  #define uart2_hc_base                                  0x00352300                                                   // ptu_aux_adr_base + 0x00002300
  #define spiffy2_base                                   0x00352400                                                   // ptu_aux_adr_base + 0x00002400
  #define pcm_control_adr                                0x00351000                                                   // pcm_base + 0x00000000
  #define pcm_control                                    (*(volatile unsigned int *)pcm_control_adr)
  #define pcm_ch0_din_adr                                0x00351004                                                   // pcm_base + 0x00000004
  #define pcm_ch0_din                                    (*(volatile unsigned int *)pcm_ch0_din_adr)
  #define pcm_ch0_dout_adr                               0x00351008                                                   // pcm_base + 0x00000008
  #define pcm_ch0_dout                                   (*(volatile unsigned int *)pcm_ch0_dout_adr)
  #define pcm_ch1_din_adr                                0x0035100c                                                   // pcm_base + 0x0000000c
  #define pcm_ch1_din                                    (*(volatile unsigned int *)pcm_ch1_din_adr)
  #define pcm_ch1_dout_adr                               0x00351010                                                   // pcm_base + 0x00000010
  #define pcm_ch1_dout                                   (*(volatile unsigned int *)pcm_ch1_dout_adr)
  #define pcm_ch2_din_adr                                0x00351014                                                   // pcm_base + 0x00000014
  #define pcm_ch2_din                                    (*(volatile unsigned int *)pcm_ch2_din_adr)
  #define pcm_ch2_dout_adr                               0x00351018                                                   // pcm_base + 0x00000018
  #define pcm_ch2_dout                                   (*(volatile unsigned int *)pcm_ch2_dout_adr)
  #define pcm_waterline_adr                              0x0035101c                                                   // pcm_base + 0x0000001c
  #define pcm_waterline                                  (*(volatile unsigned int *)pcm_waterline_adr)
  #define pcm_fifo_rst_adr                               0x00351020                                                   // pcm_base + 0x00000020
  #define pcm_fifo_rst                                   (*(volatile unsigned int *)pcm_fifo_rst_adr)
  #define pcm_fifo_stat_adr                              0x00351024                                                   // pcm_base + 0x00000024
  #define pcm_fifo_stat                                  (*(volatile unsigned int *)pcm_fifo_stat_adr)
  #define pcm_misc_ctrl_adr                              0x00351028                                                   // pcm_base + 0x00000028
  #define pcm_misc_ctrl                                  (*(volatile unsigned int *)pcm_misc_ctrl_adr)
  #define pcm_control_2_adr                              0x0035102c                                                   // pcm_base + 0x0000002c
  #define pcm_control_2                                  (*(volatile unsigned int *)pcm_control_2_adr)
  #define pcm_waterlineo_adr                             0x00351030                                                   // pcm_base + 0x00000030
  #define pcm_waterlineo                                 (*(volatile unsigned int *)pcm_waterlineo_adr)
  #define pcm_ch0_din_ws_adr                             0x00351100                                                   // pcm_base + 0x00000100
  #define pcm_ch0_din_ws                                 (*(volatile unsigned int *)pcm_ch0_din_ws_adr)
  #define pcm_ch0_dout_ws_adr                            0x00351200                                                   // pcm_base + 0x00000200
  #define pcm_ch0_dout_ws                                (*(volatile unsigned int *)pcm_ch0_dout_ws_adr)
  #define pcm_ch1_din_ws_adr                             0x00351300                                                   // pcm_base + 0x00000300
  #define pcm_ch1_din_ws                                 (*(volatile unsigned int *)pcm_ch1_din_ws_adr)
  #define pcm_ch1_dout_ws_adr                            0x00351400                                                   // pcm_base + 0x00000400
  #define pcm_ch1_dout_ws                                (*(volatile unsigned int *)pcm_ch1_dout_ws_adr)
  #define pcm_ch2_din_ws_adr                             0x00351500                                                   // pcm_base + 0x00000500
  #define pcm_ch2_din_ws                                 (*(volatile unsigned int *)pcm_ch2_din_ws_adr)
  #define pcm_ch2_dout_ws_adr                            0x00351600                                                   // pcm_base + 0x00000600
  #define pcm_ch2_dout_ws                                (*(volatile unsigned int *)pcm_ch2_dout_ws_adr)
  #define pcm_aud_fdiv_N_adr                             0x00351080                                                   // pcm_base + 0x00000080
  #define pcm_aud_fdiv_N                                 (*(volatile unsigned int *)pcm_aud_fdiv_N_adr)
  #define pcm_aud_fdiv_X_adr                             0x00351084                                                   // pcm_base + 0x00000084
  #define pcm_aud_fdiv_X                                 (*(volatile unsigned int *)pcm_aud_fdiv_X_adr)
  #define pcm_aud_fdiv_enable_adr                        0x00351088                                                   // pcm_base + 0x00000088
  #define pcm_aud_fdiv_enable                            (*(volatile unsigned int *)pcm_aud_fdiv_enable_adr)
  #define pcm_aud_fdiv_div2n_adr                         0x0035108c                                                   // pcm_base + 0x0000008c
  #define pcm_aud_fdiv_div2n                             (*(volatile unsigned int *)pcm_aud_fdiv_div2n_adr)
  #define pcm_aud_fdiv_update_adr                        0x00351090                                                   // pcm_base + 0x00000090
  #define pcm_aud_fdiv_update                            (*(volatile unsigned int *)pcm_aud_fdiv_update_adr)
  #define aud_mux_ctrl_adr                               0x00351094                                                   // pcm_base + 0x00000094
  #define aud_mux_ctrl                                   (*(volatile unsigned int *)aud_mux_ctrl_adr)
  #define dc_ptu_uart2_dhbr_adr                          0x00352200                                                   // uart2_base + 0x00000000
  #define dc_ptu_uart2_dhbr                              (*(volatile unsigned int *)dc_ptu_uart2_dhbr_adr)
  #define dc_ptu_uart2_dlbr_adr                          0x00352204                                                   // uart2_base + 0x00000004
  #define dc_ptu_uart2_dlbr                              (*(volatile unsigned int *)dc_ptu_uart2_dlbr_adr)
  #define dc_ptu_uart2_ab0_adr                           0x00352208                                                   // uart2_base + 0x00000008
  #define dc_ptu_uart2_ab0                               (*(volatile unsigned int *)dc_ptu_uart2_ab0_adr)
  #define dc_ptu_uart2_fcr_adr                           0x00352210                                                   // uart2_base + 0x00000010
  #define dc_ptu_uart2_fcr                               (*(volatile unsigned int *)dc_ptu_uart2_fcr_adr)
  #define dc_ptu_uart2_ab1_adr                           0x00352214                                                   // uart2_base + 0x00000014
  #define dc_ptu_uart2_ab1                               (*(volatile unsigned int *)dc_ptu_uart2_ab1_adr)
  #define dc_ptu_uart2_lcr_adr                           0x0035221c                                                   // uart2_base + 0x0000001c
  #define dc_ptu_uart2_lcr                               (*(volatile unsigned int *)dc_ptu_uart2_lcr_adr)
  #define dc_ptu_uart2_mcr_adr                           0x00352220                                                   // uart2_base + 0x00000020
  #define dc_ptu_uart2_mcr                               (*(volatile unsigned int *)dc_ptu_uart2_mcr_adr)
  #define dc_ptu_uart2_lsr_adr                           0x00352224                                                   // uart2_base + 0x00000024
  #define dc_ptu_uart2_lsr                               (*(volatile unsigned int *)dc_ptu_uart2_lsr_adr)
  #define dc_ptu_uart2_msr_adr                           0x00352228                                                   // uart2_base + 0x00000028
  #define dc_ptu_uart2_msr                               (*(volatile unsigned int *)dc_ptu_uart2_msr_adr)
  #define dc_ptu_uart2_rfl_adr                           0x0035222c                                                   // uart2_base + 0x0000002c
  #define dc_ptu_uart2_rfl                               (*(volatile unsigned int *)dc_ptu_uart2_rfl_adr)
  #define dc_ptu_uart2_tfl_adr                           0x00352230                                                   // uart2_base + 0x00000030
  #define dc_ptu_uart2_tfl                               (*(volatile unsigned int *)dc_ptu_uart2_tfl_adr)
  #define dc_ptu_uart2_rfc_adr                           0x00352234                                                   // uart2_base + 0x00000034
  #define dc_ptu_uart2_rfc                               (*(volatile unsigned int *)dc_ptu_uart2_rfc_adr)
  #define dc_ptu_uart2_esc_adr                           0x00352238                                                   // uart2_base + 0x00000038
  #define dc_ptu_uart2_esc                               (*(volatile unsigned int *)dc_ptu_uart2_esc_adr)
  #define dc_ptu_uart2_abr_adr                           0x0035223c                                                   // uart2_base + 0x0000003c
  #define dc_ptu_uart2_abr                               (*(volatile unsigned int *)dc_ptu_uart2_abr_adr)
  #define uart_hc_ho_pklen_adr                           0x00352300                                                   // uart2_hc_base + 0x00000000
  #define uart_hc_ho_pklen                               (*(volatile unsigned int *)uart_hc_ho_pklen_adr)
  #define uart_hc_hi_pklen_adr                           0x00352304                                                   // uart2_hc_base + 0x00000004
  #define uart_hc_hi_pklen                               (*(volatile unsigned int *)uart_hc_hi_pklen_adr)
  #define uart_hc_ho_dma_ctl_adr                         0x00352308                                                   // uart2_hc_base + 0x00000008
  #define uart_hc_ho_dma_ctl                             (*(volatile unsigned int *)uart_hc_ho_dma_ctl_adr)
  #define uart_hc_hi_dma_ctl_adr                         0x0035230c                                                   // uart2_hc_base + 0x0000000c
  #define uart_hc_hi_dma_ctl                             (*(volatile unsigned int *)uart_hc_hi_dma_ctl_adr)
  #define uart_hc_ho_bsize_adr                           0x00352310                                                   // uart2_hc_base + 0x00000010
  #define uart_hc_ho_bsize                               (*(volatile unsigned int *)uart_hc_ho_bsize_adr)
  #define uart_hc_hi_bsize_adr                           0x00352314                                                   // uart2_hc_base + 0x00000014
  #define uart_hc_hi_bsize                               (*(volatile unsigned int *)uart_hc_hi_bsize_adr)
  #define uart_hc_int_status_adr                         0x00352318                                                   // uart2_hc_base + 0x00000018
  #define uart_hc_int_status                             (*(volatile unsigned int *)uart_hc_int_status_adr)
  #define uart_hc_int_enable_adr                         0x0035231c                                                   // uart2_hc_base + 0x0000001c
  #define uart_hc_int_enable                             (*(volatile unsigned int *)uart_hc_int_enable_adr)
  #define uart_hc_data_adr                               0x00352320                                                   // uart2_hc_base + 0x00000020
  #define uart_hc_data                                   (*(volatile unsigned int *)uart_hc_data_adr)
  #define dmacintstat_adr                                0x00300000                                                   // dmac_adr_base + 0x00000000
  #define dmacintstat                                    (*(volatile unsigned int *)dmacintstat_adr)
  #define dmacinttcstat_adr                              0x00300004                                                   // dmac_adr_base + 0x00000004
  #define dmacinttcstat                                  (*(volatile unsigned int *)dmacinttcstat_adr)
  #define dmacinttcclr_adr                               0x00300008                                                   // dmac_adr_base + 0x00000008
  #define dmacinttcclr                                   (*(volatile unsigned int *)dmacinttcclr_adr)
  #define dmacinterrstat_adr                             0x0030000c                                                   // dmac_adr_base + 0x0000000c
  #define dmacinterrstat                                 (*(volatile unsigned int *)dmacinterrstat_adr)
  #define dmacinterrclr_adr                              0x00300010                                                   // dmac_adr_base + 0x00000010
  #define dmacinterrclr                                  (*(volatile unsigned int *)dmacinterrclr_adr)
  #define dmacrawintc_adr                                0x00300014                                                   // dmac_adr_base + 0x00000014
  #define dmacrawintc                                    (*(volatile unsigned int *)dmacrawintc_adr)
  #define dmacrawinterr_adr                              0x00300018                                                   // dmac_adr_base + 0x00000018
  #define dmacrawinterr                                  (*(volatile unsigned int *)dmacrawinterr_adr)
  #define dmacenbldchns_adr                              0x0030001c                                                   // dmac_adr_base + 0x0000001c
  #define dmacenbldchns                                  (*(volatile unsigned int *)dmacenbldchns_adr)
  #define dmacsoftbreq_adr                               0x00300020                                                   // dmac_adr_base + 0x00000020
  #define dmacsoftbreq                                   (*(volatile unsigned int *)dmacsoftbreq_adr)
  #define dmacsoftsreq_adr                               0x00300024                                                   // dmac_adr_base + 0x00000024
  #define dmacsoftsreq                                   (*(volatile unsigned int *)dmacsoftsreq_adr)
  #define dmacsoftlbreq_adr                              0x00300028                                                   // dmac_adr_base + 0x00000028
  #define dmacsoftlbreq                                  (*(volatile unsigned int *)dmacsoftlbreq_adr)
  #define dmacsoftlsreq_adr                              0x0030002c                                                   // dmac_adr_base + 0x0000002c
  #define dmacsoftlsreq                                  (*(volatile unsigned int *)dmacsoftlsreq_adr)
  #define dmacconfig_adr                                 0x00300030                                                   // dmac_adr_base + 0x00000030
  #define dmacconfig                                     (*(volatile unsigned int *)dmacconfig_adr)
  #define dmacsync_adr                                   0x00300034                                                   // dmac_adr_base + 0x00000034
  #define dmacsync                                       (*(volatile unsigned int *)dmacsync_adr)
  #define dmacc0srcaddr_adr                              0x00300100                                                   // dmac_adr_base + 0x00000100
  #define dmacc0srcaddr                                  (*(volatile unsigned int *)dmacc0srcaddr_adr)
  #define dmacc0destaddr_adr                             0x00300104                                                   // dmac_adr_base + 0x00000104
  #define dmacc0destaddr                                 (*(volatile unsigned int *)dmacc0destaddr_adr)
  #define dmacc0llireg_adr                               0x00300108                                                   // dmac_adr_base + 0x00000108
  #define dmacc0llireg                                   (*(volatile unsigned int *)dmacc0llireg_adr)
  #define dmacc0control_adr                              0x0030010c                                                   // dmac_adr_base + 0x0000010c
  #define dmacc0control                                  (*(volatile unsigned int *)dmacc0control_adr)
  #define dmacc0config_adr                               0x00300110                                                   // dmac_adr_base + 0x00000110
  #define dmacc0config                                   (*(volatile unsigned int *)dmacc0config_adr)
  #define dmacc1srcaddr_adr                              0x00300120                                                   // dmac_adr_base + 0x00000120
  #define dmacc1srcaddr                                  (*(volatile unsigned int *)dmacc1srcaddr_adr)
  #define dmacc1destaddr_adr                             0x00300124                                                   // dmac_adr_base + 0x00000124
  #define dmacc1destaddr                                 (*(volatile unsigned int *)dmacc1destaddr_adr)
  #define dmacc1llireg_adr                               0x00300128                                                   // dmac_adr_base + 0x00000128
  #define dmacc1llireg                                   (*(volatile unsigned int *)dmacc1llireg_adr)
  #define dmacc1control_adr                              0x0030012c                                                   // dmac_adr_base + 0x0000012c
  #define dmacc1control                                  (*(volatile unsigned int *)dmacc1control_adr)
  #define dmacc1config_adr                               0x00300130                                                   // dmac_adr_base + 0x00000130
  #define dmacc1config                                   (*(volatile unsigned int *)dmacc1config_adr)
  #define dmacc2srcaddr_adr                              0x00300140                                                   // dmac_adr_base + 0x00000140
  #define dmacc2srcaddr                                  (*(volatile unsigned int *)dmacc2srcaddr_adr)
  #define dmacc2destaddr_adr                             0x00300144                                                   // dmac_adr_base + 0x00000144
  #define dmacc2destaddr                                 (*(volatile unsigned int *)dmacc2destaddr_adr)
  #define dmacc2llireg_adr                               0x00300148                                                   // dmac_adr_base + 0x00000148
  #define dmacc2llireg                                   (*(volatile unsigned int *)dmacc2llireg_adr)
  #define dmacc2control_adr                              0x0030014c                                                   // dmac_adr_base + 0x0000014c
  #define dmacc2control                                  (*(volatile unsigned int *)dmacc2control_adr)
  #define dmacc2config_adr                               0x00300150                                                   // dmac_adr_base + 0x00000150
  #define dmacc2config                                   (*(volatile unsigned int *)dmacc2config_adr)
  #define dmacc3srcaddr_adr                              0x00300160                                                   // dmac_adr_base + 0x00000160
  #define dmacc3srcaddr                                  (*(volatile unsigned int *)dmacc3srcaddr_adr)
  #define dmacc3destaddr_adr                             0x00300164                                                   // dmac_adr_base + 0x00000164
  #define dmacc3destaddr                                 (*(volatile unsigned int *)dmacc3destaddr_adr)
  #define dmacc3llireg_adr                               0x00300168                                                   // dmac_adr_base + 0x00000168
  #define dmacc3llireg                                   (*(volatile unsigned int *)dmacc3llireg_adr)
  #define dmacc3control_adr                              0x0030016c                                                   // dmac_adr_base + 0x0000016c
  #define dmacc3control                                  (*(volatile unsigned int *)dmacc3control_adr)
  #define dmacc3config_adr                               0x00300170                                                   // dmac_adr_base + 0x00000170
  #define dmacc3config                                   (*(volatile unsigned int *)dmacc3config_adr)
  #define dmacc4srcaddr_adr                              0x00300180                                                   // dmac_adr_base + 0x00000180
  #define dmacc4srcaddr                                  (*(volatile unsigned int *)dmacc4srcaddr_adr)
  #define dmacc4destaddr_adr                             0x00300184                                                   // dmac_adr_base + 0x00000184
  #define dmacc4destaddr                                 (*(volatile unsigned int *)dmacc4destaddr_adr)
  #define dmacc4llireg_adr                               0x00300188                                                   // dmac_adr_base + 0x00000188
  #define dmacc4llireg                                   (*(volatile unsigned int *)dmacc4llireg_adr)
  #define dmacc4control_adr                              0x0030018c                                                   // dmac_adr_base + 0x0000018c
  #define dmacc4control                                  (*(volatile unsigned int *)dmacc4control_adr)
  #define dmacc4config_adr                               0x00300190                                                   // dmac_adr_base + 0x00000190
  #define dmacc4config                                   (*(volatile unsigned int *)dmacc4config_adr)
  #define dmacc5srcaddr_adr                              0x003001a0                                                   // dmac_adr_base + 0x000001a0
  #define dmacc5srcaddr                                  (*(volatile unsigned int *)dmacc5srcaddr_adr)
  #define dmacc5destaddr_adr                             0x003001a4                                                   // dmac_adr_base + 0x000001a4
  #define dmacc5destaddr                                 (*(volatile unsigned int *)dmacc5destaddr_adr)
  #define dmacc5llireg_adr                               0x003001a8                                                   // dmac_adr_base + 0x000001a8
  #define dmacc5llireg                                   (*(volatile unsigned int *)dmacc5llireg_adr)
  #define dmacc5control_adr                              0x003001ac                                                   // dmac_adr_base + 0x000001ac
  #define dmacc5control                                  (*(volatile unsigned int *)dmacc5control_adr)
  #define dmacc5config_adr                               0x003001b0                                                   // dmac_adr_base + 0x000001b0
  #define dmacc5config                                   (*(volatile unsigned int *)dmacc5config_adr)
  #define dmacc6srcaddr_adr                              0x003001c0                                                   // dmac_adr_base + 0x000001c0
  #define dmacc6srcaddr                                  (*(volatile unsigned int *)dmacc6srcaddr_adr)
  #define dmacc6destaddr_adr                             0x003001c4                                                   // dmac_adr_base + 0x000001c4
  #define dmacc6destaddr                                 (*(volatile unsigned int *)dmacc6destaddr_adr)
  #define dmacc6llireg_adr                               0x003001c8                                                   // dmac_adr_base + 0x000001c8
  #define dmacc6llireg                                   (*(volatile unsigned int *)dmacc6llireg_adr)
  #define dmacc6control_adr                              0x003001cc                                                   // dmac_adr_base + 0x000001cc
  #define dmacc6control                                  (*(volatile unsigned int *)dmacc6control_adr)
  #define dmacc6config_adr                               0x003001d0                                                   // dmac_adr_base + 0x000001d0
  #define dmacc6config                                   (*(volatile unsigned int *)dmacc6config_adr)
  #define dmacc7srcaddr_adr                              0x003001e0                                                   // dmac_adr_base + 0x000001e0
  #define dmacc7srcaddr                                  (*(volatile unsigned int *)dmacc7srcaddr_adr)
  #define dmacc7destaddr_adr                             0x003001e4                                                   // dmac_adr_base + 0x000001e4
  #define dmacc7destaddr                                 (*(volatile unsigned int *)dmacc7destaddr_adr)
  #define dmacc7llireg_adr                               0x003001e8                                                   // dmac_adr_base + 0x000001e8
  #define dmacc7llireg                                   (*(volatile unsigned int *)dmacc7llireg_adr)
  #define dmacc7control_adr                              0x003001ec                                                   // dmac_adr_base + 0x000001ec
  #define dmacc7control                                  (*(volatile unsigned int *)dmacc7control_adr)
  #define dmacc7config_adr                               0x003001f0                                                   // dmac_adr_base + 0x000001f0
  #define dmacc7config                                   (*(volatile unsigned int *)dmacc7config_adr)
  #define dmactcr_adr                                    0x00300500                                                   // dmac_adr_base + 0x00000500
  #define dmactcr                                        (*(volatile unsigned int *)dmactcr_adr)
  #define dmacitop1_adr                                  0x00300504                                                   // dmac_adr_base + 0x00000504
  #define dmacitop1                                      (*(volatile unsigned int *)dmacitop1_adr)
  #define dmacitop2_adr                                  0x00300508                                                   // dmac_adr_base + 0x00000508
  #define dmacitop2                                      (*(volatile unsigned int *)dmacitop2_adr)
  #define dmacitop3_adr                                  0x0030050c                                                   // dmac_adr_base + 0x0000050c
  #define dmacitop3                                      (*(volatile unsigned int *)dmacitop3_adr)
  #define dmacperiphid0_adr                              0x00300fe0                                                   // dmac_adr_base + 0x00000fe0
  #define dmacperiphid0                                  (*(volatile unsigned int *)dmacperiphid0_adr)
  #define dmacperiphid1_adr                              0x00300fe4                                                   // dmac_adr_base + 0x00000fe4
  #define dmacperiphid1                                  (*(volatile unsigned int *)dmacperiphid1_adr)
  #define dmacperiphid2_adr                              0x00300fe8                                                   // dmac_adr_base + 0x00000fe8
  #define dmacperiphid2                                  (*(volatile unsigned int *)dmacperiphid2_adr)
  #define dmacperiphid3_adr                              0x00300fec                                                   // dmac_adr_base + 0x00000fec
  #define dmacperiphid3                                  (*(volatile unsigned int *)dmacperiphid3_adr)
  #define dmacpcellid0_adr                               0x00300ff0                                                   // dmac_adr_base + 0x00000ff0
  #define dmacpcellid0                                   (*(volatile unsigned int *)dmacpcellid0_adr)
  #define dmacpcellid1_adr                               0x00300ff4                                                   // dmac_adr_base + 0x00000ff4
  #define dmacpcellid1                                   (*(volatile unsigned int *)dmacpcellid1_adr)
  #define dmacpcellid2_adr                               0x00300ff8                                                   // dmac_adr_base + 0x00000ff8
  #define dmacpcellid2                                   (*(volatile unsigned int *)dmacpcellid2_adr)
  #define dmacpcellid3_adr                               0x00300ffc                                                   // dmac_adr_base + 0x00000ffc
  #define dmacpcellid3                                   (*(volatile unsigned int *)dmacpcellid3_adr)
  #define prc_brk_out0_adr                               0x00310000                                                   // prc_adr_base + 0x00000000
  #define prc_brk_out0                                   (*(volatile unsigned int *)prc_brk_out0_adr)
  #define prc_brk_out1_adr                               0x00310004                                                   // prc_adr_base + 0x00000004
  #define prc_brk_out1                                   (*(volatile unsigned int *)prc_brk_out1_adr)
  #define prc_brk_out2_adr                               0x00310008                                                   // prc_adr_base + 0x00000008
  #define prc_brk_out2                                   (*(volatile unsigned int *)prc_brk_out2_adr)
  #define prc_brk_out3_adr                               0x0031000c                                                   // prc_adr_base + 0x0000000c
  #define prc_brk_out3                                   (*(volatile unsigned int *)prc_brk_out3_adr)
  #define prc_brk_out4_adr                               0x00310010                                                   // prc_adr_base + 0x00000010
  #define prc_brk_out4                                   (*(volatile unsigned int *)prc_brk_out4_adr)
  #define prc_brk_out5_adr                               0x00310014                                                   // prc_adr_base + 0x00000014
  #define prc_brk_out5                                   (*(volatile unsigned int *)prc_brk_out5_adr)
  #define prc_brk_out6_adr                               0x00310018                                                   // prc_adr_base + 0x00000018
  #define prc_brk_out6                                   (*(volatile unsigned int *)prc_brk_out6_adr)
  #define prc_brk_out7_adr                               0x0031001c                                                   // prc_adr_base + 0x0000001c
  #define prc_brk_out7                                   (*(volatile unsigned int *)prc_brk_out7_adr)
  #define prc_brk_out8_adr                               0x00310020                                                   // prc_adr_base + 0x00000020
  #define prc_brk_out8                                   (*(volatile unsigned int *)prc_brk_out8_adr)
  #define prc_brk_out9_adr                               0x00310024                                                   // prc_adr_base + 0x00000024
  #define prc_brk_out9                                   (*(volatile unsigned int *)prc_brk_out9_adr)
  #define prc_brk_outA_adr                               0x00310028                                                   // prc_adr_base + 0x00000028
  #define prc_brk_outA                                   (*(volatile unsigned int *)prc_brk_outA_adr)
  #define prc_brk_outB_adr                               0x0031002c                                                   // prc_adr_base + 0x0000002c
  #define prc_brk_outB                                   (*(volatile unsigned int *)prc_brk_outB_adr)
  #define prc_brk_outC_adr                               0x00310030                                                   // prc_adr_base + 0x00000030
  #define prc_brk_outC                                   (*(volatile unsigned int *)prc_brk_outC_adr)
  #define prc_brk_outD_adr                               0x00310034                                                   // prc_adr_base + 0x00000034
  #define prc_brk_outD                                   (*(volatile unsigned int *)prc_brk_outD_adr)
  #define prc_brk_outE_adr                               0x00310038                                                   // prc_adr_base + 0x00000038
  #define prc_brk_outE                                   (*(volatile unsigned int *)prc_brk_outE_adr)
  #define prc_brk_outF_adr                               0x0031003c                                                   // prc_adr_base + 0x0000003c
  #define prc_brk_outF                                   (*(volatile unsigned int *)prc_brk_outF_adr)
  #define prc_brk_out10_adr                              0x00310040                                                   // prc_adr_base + 0x00000040
  #define prc_brk_out10                                  (*(volatile unsigned int *)prc_brk_out10_adr)
  #define prc_brk_out11_adr                              0x00310044                                                   // prc_adr_base + 0x00000044
  #define prc_brk_out11                                  (*(volatile unsigned int *)prc_brk_out11_adr)
  #define prc_brk_out12_adr                              0x00310048                                                   // prc_adr_base + 0x00000048
  #define prc_brk_out12                                  (*(volatile unsigned int *)prc_brk_out12_adr)
  #define prc_brk_out13_adr                              0x0031004c                                                   // prc_adr_base + 0x0000004c
  #define prc_brk_out13                                  (*(volatile unsigned int *)prc_brk_out13_adr)
  #define prc_brk_out14_adr                              0x00310050                                                   // prc_adr_base + 0x00000050
  #define prc_brk_out14                                  (*(volatile unsigned int *)prc_brk_out14_adr)
  #define prc_brk_out15_adr                              0x00310054                                                   // prc_adr_base + 0x00000054
  #define prc_brk_out15                                  (*(volatile unsigned int *)prc_brk_out15_adr)
  #define prc_brk_out16_adr                              0x00310058                                                   // prc_adr_base + 0x00000058
  #define prc_brk_out16                                  (*(volatile unsigned int *)prc_brk_out16_adr)
  #define prc_brk_out17_adr                              0x0031005c                                                   // prc_adr_base + 0x0000005c
  #define prc_brk_out17                                  (*(volatile unsigned int *)prc_brk_out17_adr)
  #define prc_brk_out18_adr                              0x00310060                                                   // prc_adr_base + 0x00000060
  #define prc_brk_out18                                  (*(volatile unsigned int *)prc_brk_out18_adr)
  #define prc_brk_out19_adr                              0x00310064                                                   // prc_adr_base + 0x00000064
  #define prc_brk_out19                                  (*(volatile unsigned int *)prc_brk_out19_adr)
  #define prc_brk_out1A_adr                              0x00310068                                                   // prc_adr_base + 0x00000068
  #define prc_brk_out1A                                  (*(volatile unsigned int *)prc_brk_out1A_adr)
  #define prc_brk_out1B_adr                              0x0031006c                                                   // prc_adr_base + 0x0000006c
  #define prc_brk_out1B                                  (*(volatile unsigned int *)prc_brk_out1B_adr)
  #define prc_brk_out1C_adr                              0x00310070                                                   // prc_adr_base + 0x00000070
  #define prc_brk_out1C                                  (*(volatile unsigned int *)prc_brk_out1C_adr)
  #define prc_brk_out1D_adr                              0x00310074                                                   // prc_adr_base + 0x00000074
  #define prc_brk_out1D                                  (*(volatile unsigned int *)prc_brk_out1D_adr)
  #define prc_brk_out1E_adr                              0x00310078                                                   // prc_adr_base + 0x00000078
  #define prc_brk_out1E                                  (*(volatile unsigned int *)prc_brk_out1E_adr)
  #define prc_brk_out1F_adr                              0x0031007c                                                   // prc_adr_base + 0x0000007c
  #define prc_brk_out1F                                  (*(volatile unsigned int *)prc_brk_out1F_adr)
  #define prc_brk_out20_adr                              0x00310080                                                   // prc_adr_base + 0x00000080
  #define prc_brk_out20                                  (*(volatile unsigned int *)prc_brk_out20_adr)
  #define prc_brk_out21_adr                              0x00310084                                                   // prc_adr_base + 0x00000084
  #define prc_brk_out21                                  (*(volatile unsigned int *)prc_brk_out21_adr)
  #define prc_brk_out22_adr                              0x00310088                                                   // prc_adr_base + 0x00000088
  #define prc_brk_out22                                  (*(volatile unsigned int *)prc_brk_out22_adr)
  #define prc_brk_out23_adr                              0x0031008c                                                   // prc_adr_base + 0x0000008c
  #define prc_brk_out23                                  (*(volatile unsigned int *)prc_brk_out23_adr)
  #define prc_brk_out24_adr                              0x00310090                                                   // prc_adr_base + 0x00000090
  #define prc_brk_out24                                  (*(volatile unsigned int *)prc_brk_out24_adr)
  #define prc_brk_out25_adr                              0x00310094                                                   // prc_adr_base + 0x00000094
  #define prc_brk_out25                                  (*(volatile unsigned int *)prc_brk_out25_adr)
  #define prc_brk_out26_adr                              0x00310098                                                   // prc_adr_base + 0x00000098
  #define prc_brk_out26                                  (*(volatile unsigned int *)prc_brk_out26_adr)
  #define prc_brk_out27_adr                              0x0031009c                                                   // prc_adr_base + 0x0000009c
  #define prc_brk_out27                                  (*(volatile unsigned int *)prc_brk_out27_adr)
  #define prc_brk_out28_adr                              0x003100a0                                                   // prc_adr_base + 0x000000a0
  #define prc_brk_out28                                  (*(volatile unsigned int *)prc_brk_out28_adr)
  #define prc_brk_out29_adr                              0x003100a4                                                   // prc_adr_base + 0x000000a4
  #define prc_brk_out29                                  (*(volatile unsigned int *)prc_brk_out29_adr)
  #define prc_brk_out2A_adr                              0x003100a8                                                   // prc_adr_base + 0x000000a8
  #define prc_brk_out2A                                  (*(volatile unsigned int *)prc_brk_out2A_adr)
  #define prc_brk_out2B_adr                              0x003100ac                                                   // prc_adr_base + 0x000000ac
  #define prc_brk_out2B                                  (*(volatile unsigned int *)prc_brk_out2B_adr)
  #define prc_brk_out2C_adr                              0x003100b0                                                   // prc_adr_base + 0x000000b0
  #define prc_brk_out2C                                  (*(volatile unsigned int *)prc_brk_out2C_adr)
  #define prc_brk_out2D_adr                              0x003100b4                                                   // prc_adr_base + 0x000000b4
  #define prc_brk_out2D                                  (*(volatile unsigned int *)prc_brk_out2D_adr)
  #define prc_brk_out2E_adr                              0x003100b8                                                   // prc_adr_base + 0x000000b8
  #define prc_brk_out2E                                  (*(volatile unsigned int *)prc_brk_out2E_adr)
  #define prc_brk_out2F_adr                              0x003100bc                                                   // prc_adr_base + 0x000000bc
  #define prc_brk_out2F                                  (*(volatile unsigned int *)prc_brk_out2F_adr)
  #define prc_brk_out30_adr                              0x003100c0                                                   // prc_adr_base + 0x000000c0
  #define prc_brk_out30                                  (*(volatile unsigned int *)prc_brk_out30_adr)
  #define prc_brk_out31_adr                              0x003100c4                                                   // prc_adr_base + 0x000000c4
  #define prc_brk_out31                                  (*(volatile unsigned int *)prc_brk_out31_adr)
  #define prc_brk_out32_adr                              0x003100c8                                                   // prc_adr_base + 0x000000c8
  #define prc_brk_out32                                  (*(volatile unsigned int *)prc_brk_out32_adr)
  #define prc_brk_out33_adr                              0x003100cc                                                   // prc_adr_base + 0x000000cc
  #define prc_brk_out33                                  (*(volatile unsigned int *)prc_brk_out33_adr)
  #define prc_brk_out34_adr                              0x003100d0                                                   // prc_adr_base + 0x000000d0
  #define prc_brk_out34                                  (*(volatile unsigned int *)prc_brk_out34_adr)
  #define prc_brk_out35_adr                              0x003100d4                                                   // prc_adr_base + 0x000000d4
  #define prc_brk_out35                                  (*(volatile unsigned int *)prc_brk_out35_adr)
  #define prc_brk_out36_adr                              0x003100d8                                                   // prc_adr_base + 0x000000d8
  #define prc_brk_out36                                  (*(volatile unsigned int *)prc_brk_out36_adr)
  #define prc_brk_out37_adr                              0x003100dc                                                   // prc_adr_base + 0x000000dc
  #define prc_brk_out37                                  (*(volatile unsigned int *)prc_brk_out37_adr)
  #define prc_brk_out38_adr                              0x003100e0                                                   // prc_adr_base + 0x000000e0
  #define prc_brk_out38                                  (*(volatile unsigned int *)prc_brk_out38_adr)
  #define prc_brk_out39_adr                              0x003100e4                                                   // prc_adr_base + 0x000000e4
  #define prc_brk_out39                                  (*(volatile unsigned int *)prc_brk_out39_adr)
  #define prc_brk_out3A_adr                              0x003100e8                                                   // prc_adr_base + 0x000000e8
  #define prc_brk_out3A                                  (*(volatile unsigned int *)prc_brk_out3A_adr)
  #define prc_brk_out3B_adr                              0x003100ec                                                   // prc_adr_base + 0x000000ec
  #define prc_brk_out3B                                  (*(volatile unsigned int *)prc_brk_out3B_adr)
  #define prc_brk_out3C_adr                              0x003100f0                                                   // prc_adr_base + 0x000000f0
  #define prc_brk_out3C                                  (*(volatile unsigned int *)prc_brk_out3C_adr)
  #define prc_brk_out3D_adr                              0x003100f4                                                   // prc_adr_base + 0x000000f4
  #define prc_brk_out3D                                  (*(volatile unsigned int *)prc_brk_out3D_adr)
  #define prc_brk_out3E_adr                              0x003100f8                                                   // prc_adr_base + 0x000000f8
  #define prc_brk_out3E                                  (*(volatile unsigned int *)prc_brk_out3E_adr)
  #define prc_brk_out3F_adr                              0x003100fc                                                   // prc_adr_base + 0x000000fc
  #define prc_brk_out3F                                  (*(volatile unsigned int *)prc_brk_out3F_adr)
  #define prc_brk_out40_adr                              0x00310100                                                   // prc_adr_base + 0x00000100
  #define prc_brk_out40                                  (*(volatile unsigned int *)prc_brk_out40_adr)
  #define prc_brk_out41_adr                              0x00310104                                                   // prc_adr_base + 0x00000104
  #define prc_brk_out41                                  (*(volatile unsigned int *)prc_brk_out41_adr)
  #define prc_brk_out42_adr                              0x00310108                                                   // prc_adr_base + 0x00000108
  #define prc_brk_out42                                  (*(volatile unsigned int *)prc_brk_out42_adr)
  #define prc_brk_out43_adr                              0x0031010c                                                   // prc_adr_base + 0x0000010c
  #define prc_brk_out43                                  (*(volatile unsigned int *)prc_brk_out43_adr)
  #define prc_brk_out44_adr                              0x00310110                                                   // prc_adr_base + 0x00000110
  #define prc_brk_out44                                  (*(volatile unsigned int *)prc_brk_out44_adr)
  #define prc_brk_out45_adr                              0x00310114                                                   // prc_adr_base + 0x00000114
  #define prc_brk_out45                                  (*(volatile unsigned int *)prc_brk_out45_adr)
  #define prc_brk_out46_adr                              0x00310118                                                   // prc_adr_base + 0x00000118
  #define prc_brk_out46                                  (*(volatile unsigned int *)prc_brk_out46_adr)
  #define prc_brk_out47_adr                              0x0031011c                                                   // prc_adr_base + 0x0000011c
  #define prc_brk_out47                                  (*(volatile unsigned int *)prc_brk_out47_adr)
  #define prc_brk_out48_adr                              0x00310120                                                   // prc_adr_base + 0x00000120
  #define prc_brk_out48                                  (*(volatile unsigned int *)prc_brk_out48_adr)
  #define prc_brk_out49_adr                              0x00310124                                                   // prc_adr_base + 0x00000124
  #define prc_brk_out49                                  (*(volatile unsigned int *)prc_brk_out49_adr)
  #define prc_brk_out4A_adr                              0x00310128                                                   // prc_adr_base + 0x00000128
  #define prc_brk_out4A                                  (*(volatile unsigned int *)prc_brk_out4A_adr)
  #define prc_brk_out4B_adr                              0x0031012c                                                   // prc_adr_base + 0x0000012c
  #define prc_brk_out4B                                  (*(volatile unsigned int *)prc_brk_out4B_adr)
  #define prc_brk_out4C_adr                              0x00310130                                                   // prc_adr_base + 0x00000130
  #define prc_brk_out4C                                  (*(volatile unsigned int *)prc_brk_out4C_adr)
  #define prc_brk_out4D_adr                              0x00310134                                                   // prc_adr_base + 0x00000134
  #define prc_brk_out4D                                  (*(volatile unsigned int *)prc_brk_out4D_adr)
  #define prc_brk_out4E_adr                              0x00310138                                                   // prc_adr_base + 0x00000138
  #define prc_brk_out4E                                  (*(volatile unsigned int *)prc_brk_out4E_adr)
  #define prc_brk_out4F_adr                              0x0031013c                                                   // prc_adr_base + 0x0000013c
  #define prc_brk_out4F                                  (*(volatile unsigned int *)prc_brk_out4F_adr)
  #define prc_brk_out50_adr                              0x00310140                                                   // prc_adr_base + 0x00000140
  #define prc_brk_out50                                  (*(volatile unsigned int *)prc_brk_out50_adr)
  #define prc_brk_out51_adr                              0x00310144                                                   // prc_adr_base + 0x00000144
  #define prc_brk_out51                                  (*(volatile unsigned int *)prc_brk_out51_adr)
  #define prc_brk_out52_adr                              0x00310148                                                   // prc_adr_base + 0x00000148
  #define prc_brk_out52                                  (*(volatile unsigned int *)prc_brk_out52_adr)
  #define prc_brk_out53_adr                              0x0031014c                                                   // prc_adr_base + 0x0000014c
  #define prc_brk_out53                                  (*(volatile unsigned int *)prc_brk_out53_adr)
  #define prc_brk_out54_adr                              0x00310150                                                   // prc_adr_base + 0x00000150
  #define prc_brk_out54                                  (*(volatile unsigned int *)prc_brk_out54_adr)
  #define prc_brk_out55_adr                              0x00310154                                                   // prc_adr_base + 0x00000154
  #define prc_brk_out55                                  (*(volatile unsigned int *)prc_brk_out55_adr)
  #define prc_brk_out56_adr                              0x00310158                                                   // prc_adr_base + 0x00000158
  #define prc_brk_out56                                  (*(volatile unsigned int *)prc_brk_out56_adr)
  #define prc_brk_out57_adr                              0x0031015c                                                   // prc_adr_base + 0x0000015c
  #define prc_brk_out57                                  (*(volatile unsigned int *)prc_brk_out57_adr)
  #define prc_brk_out58_adr                              0x00310160                                                   // prc_adr_base + 0x00000160
  #define prc_brk_out58                                  (*(volatile unsigned int *)prc_brk_out58_adr)
  #define prc_brk_out59_adr                              0x00310164                                                   // prc_adr_base + 0x00000164
  #define prc_brk_out59                                  (*(volatile unsigned int *)prc_brk_out59_adr)
  #define prc_brk_out5A_adr                              0x00310168                                                   // prc_adr_base + 0x00000168
  #define prc_brk_out5A                                  (*(volatile unsigned int *)prc_brk_out5A_adr)
  #define prc_brk_out5B_adr                              0x0031016c                                                   // prc_adr_base + 0x0000016c
  #define prc_brk_out5B                                  (*(volatile unsigned int *)prc_brk_out5B_adr)
  #define prc_brk_out5C_adr                              0x00310170                                                   // prc_adr_base + 0x00000170
  #define prc_brk_out5C                                  (*(volatile unsigned int *)prc_brk_out5C_adr)
  #define prc_brk_out5D_adr                              0x00310174                                                   // prc_adr_base + 0x00000174
  #define prc_brk_out5D                                  (*(volatile unsigned int *)prc_brk_out5D_adr)
  #define prc_brk_out5E_adr                              0x00310178                                                   // prc_adr_base + 0x00000178
  #define prc_brk_out5E                                  (*(volatile unsigned int *)prc_brk_out5E_adr)
  #define prc_brk_out5F_adr                              0x0031017c                                                   // prc_adr_base + 0x0000017c
  #define prc_brk_out5F                                  (*(volatile unsigned int *)prc_brk_out5F_adr)
  #define prc_brk_out60_adr                              0x00310180                                                   // prc_adr_base + 0x00000180
  #define prc_brk_out60                                  (*(volatile unsigned int *)prc_brk_out60_adr)
  #define prc_brk_out61_adr                              0x00310184                                                   // prc_adr_base + 0x00000184
  #define prc_brk_out61                                  (*(volatile unsigned int *)prc_brk_out61_adr)
  #define prc_brk_out62_adr                              0x00310188                                                   // prc_adr_base + 0x00000188
  #define prc_brk_out62                                  (*(volatile unsigned int *)prc_brk_out62_adr)
  #define prc_brk_out63_adr                              0x0031018c                                                   // prc_adr_base + 0x0000018c
  #define prc_brk_out63                                  (*(volatile unsigned int *)prc_brk_out63_adr)
  #define prc_brk_out64_adr                              0x00310190                                                   // prc_adr_base + 0x00000190
  #define prc_brk_out64                                  (*(volatile unsigned int *)prc_brk_out64_adr)
  #define prc_brk_out65_adr                              0x00310194                                                   // prc_adr_base + 0x00000194
  #define prc_brk_out65                                  (*(volatile unsigned int *)prc_brk_out65_adr)
  #define prc_brk_out66_adr                              0x00310198                                                   // prc_adr_base + 0x00000198
  #define prc_brk_out66                                  (*(volatile unsigned int *)prc_brk_out66_adr)
  #define prc_brk_out67_adr                              0x0031019c                                                   // prc_adr_base + 0x0000019c
  #define prc_brk_out67                                  (*(volatile unsigned int *)prc_brk_out67_adr)
  #define prc_brk_out68_adr                              0x003101a0                                                   // prc_adr_base + 0x000001a0
  #define prc_brk_out68                                  (*(volatile unsigned int *)prc_brk_out68_adr)
  #define prc_brk_out69_adr                              0x003101a4                                                   // prc_adr_base + 0x000001a4
  #define prc_brk_out69                                  (*(volatile unsigned int *)prc_brk_out69_adr)
  #define prc_brk_out6A_adr                              0x003101a8                                                   // prc_adr_base + 0x000001a8
  #define prc_brk_out6A                                  (*(volatile unsigned int *)prc_brk_out6A_adr)
  #define prc_brk_out6B_adr                              0x003101ac                                                   // prc_adr_base + 0x000001ac
  #define prc_brk_out6B                                  (*(volatile unsigned int *)prc_brk_out6B_adr)
  #define prc_brk_out6C_adr                              0x003101b0                                                   // prc_adr_base + 0x000001b0
  #define prc_brk_out6C                                  (*(volatile unsigned int *)prc_brk_out6C_adr)
  #define prc_brk_out6D_adr                              0x003101b4                                                   // prc_adr_base + 0x000001b4
  #define prc_brk_out6D                                  (*(volatile unsigned int *)prc_brk_out6D_adr)
  #define prc_brk_out6E_adr                              0x003101b8                                                   // prc_adr_base + 0x000001b8
  #define prc_brk_out6E                                  (*(volatile unsigned int *)prc_brk_out6E_adr)
  #define prc_brk_out6F_adr                              0x003101bc                                                   // prc_adr_base + 0x000001bc
  #define prc_brk_out6F                                  (*(volatile unsigned int *)prc_brk_out6F_adr)
  #define prc_brk_out70_adr                              0x003101c0                                                   // prc_adr_base + 0x000001c0
  #define prc_brk_out70                                  (*(volatile unsigned int *)prc_brk_out70_adr)
  #define prc_brk_out71_adr                              0x003101c4                                                   // prc_adr_base + 0x000001c4
  #define prc_brk_out71                                  (*(volatile unsigned int *)prc_brk_out71_adr)
  #define prc_brk_out72_adr                              0x003101c8                                                   // prc_adr_base + 0x000001c8
  #define prc_brk_out72                                  (*(volatile unsigned int *)prc_brk_out72_adr)
  #define prc_brk_out73_adr                              0x003101cc                                                   // prc_adr_base + 0x000001cc
  #define prc_brk_out73                                  (*(volatile unsigned int *)prc_brk_out73_adr)
  #define prc_brk_out74_adr                              0x003101d0                                                   // prc_adr_base + 0x000001d0
  #define prc_brk_out74                                  (*(volatile unsigned int *)prc_brk_out74_adr)
  #define prc_brk_out75_adr                              0x003101d4                                                   // prc_adr_base + 0x000001d4
  #define prc_brk_out75                                  (*(volatile unsigned int *)prc_brk_out75_adr)
  #define prc_brk_out76_adr                              0x003101d8                                                   // prc_adr_base + 0x000001d8
  #define prc_brk_out76                                  (*(volatile unsigned int *)prc_brk_out76_adr)
  #define prc_brk_out77_adr                              0x003101dc                                                   // prc_adr_base + 0x000001dc
  #define prc_brk_out77                                  (*(volatile unsigned int *)prc_brk_out77_adr)
  #define prc_brk_out78_adr                              0x003101e0                                                   // prc_adr_base + 0x000001e0
  #define prc_brk_out78                                  (*(volatile unsigned int *)prc_brk_out78_adr)
  #define prc_brk_out79_adr                              0x003101e4                                                   // prc_adr_base + 0x000001e4
  #define prc_brk_out79                                  (*(volatile unsigned int *)prc_brk_out79_adr)
  #define prc_brk_out7A_adr                              0x003101e8                                                   // prc_adr_base + 0x000001e8
  #define prc_brk_out7A                                  (*(volatile unsigned int *)prc_brk_out7A_adr)
  #define prc_brk_out7B_adr                              0x003101ec                                                   // prc_adr_base + 0x000001ec
  #define prc_brk_out7B                                  (*(volatile unsigned int *)prc_brk_out7B_adr)
  #define prc_brk_out7C_adr                              0x003101f0                                                   // prc_adr_base + 0x000001f0
  #define prc_brk_out7C                                  (*(volatile unsigned int *)prc_brk_out7C_adr)
  #define prc_brk_out7D_adr                              0x003101f4                                                   // prc_adr_base + 0x000001f4
  #define prc_brk_out7D                                  (*(volatile unsigned int *)prc_brk_out7D_adr)
  #define prc_brk_out7E_adr                              0x003101f8                                                   // prc_adr_base + 0x000001f8
  #define prc_brk_out7E                                  (*(volatile unsigned int *)prc_brk_out7E_adr)
  #define prc_brk_out7F_adr                              0x003101fc                                                   // prc_adr_base + 0x000001fc
  #define prc_brk_out7F                                  (*(volatile unsigned int *)prc_brk_out7F_adr)
  #define prc_patch_in_adr                               0x00310200                                                   // prc_adr_base + 0x00000200
  #define prc_patch_in                                   (*(volatile unsigned int *)prc_patch_in_adr)
  #define prc_patch_reg_en0_adr                          0x00310204                                                   // prc_adr_base + 0x00000204
  #define prc_patch_reg_en0                              (*(volatile unsigned int *)prc_patch_reg_en0_adr)
  #define prc_patch_reg_en1_adr                          0x00310208                                                   // prc_adr_base + 0x00000208
  #define prc_patch_reg_en1                              (*(volatile unsigned int *)prc_patch_reg_en1_adr)
  #define prc_patch_reg_en2_adr                          0x0031020c                                                   // prc_adr_base + 0x0000020c
  #define prc_patch_reg_en2                              (*(volatile unsigned int *)prc_patch_reg_en2_adr)
  #define prc_patch_reg_en3_adr                          0x00310210                                                   // prc_adr_base + 0x00000210
  #define prc_patch_reg_en3                              (*(volatile unsigned int *)prc_patch_reg_en3_adr)
  #define prc_dpatch_en_adr                              0x00310214                                                   // prc_adr_base + 0x00000214
  #define prc_dpatch_en                                  (*(volatile unsigned int *)prc_dpatch_en_adr)
  #define prc_data_brk0_adr                              0x00310220                                                   // prc_adr_base + 0x00000220
  #define prc_data_brk0                                  (*(volatile unsigned int *)prc_data_brk0_adr)
  #define prc_data_brk1_adr                              0x00310224                                                   // prc_adr_base + 0x00000224
  #define prc_data_brk1                                  (*(volatile unsigned int *)prc_data_brk1_adr)
  #define prc_data_brk2_adr                              0x00310228                                                   // prc_adr_base + 0x00000228
  #define prc_data_brk2                                  (*(volatile unsigned int *)prc_data_brk2_adr)
  #define prc_data_brk3_adr                              0x0031022c                                                   // prc_adr_base + 0x0000022c
  #define prc_data_brk3                                  (*(volatile unsigned int *)prc_data_brk3_adr)
  #define prc_data_pat0_adr                              0x00310230                                                   // prc_adr_base + 0x00000230
  #define prc_data_pat0                                  (*(volatile unsigned int *)prc_data_pat0_adr)
  #define prc_data_pat1_adr                              0x00310234                                                   // prc_adr_base + 0x00000234
  #define prc_data_pat1                                  (*(volatile unsigned int *)prc_data_pat1_adr)
  #define prc_data_pat2_adr                              0x00310238                                                   // prc_adr_base + 0x00000238
  #define prc_data_pat2                                  (*(volatile unsigned int *)prc_data_pat2_adr)
  #define prc_data_pat3_adr                              0x0031023c                                                   // prc_adr_base + 0x0000023c
  #define prc_data_pat3                                  (*(volatile unsigned int *)prc_data_pat3_adr)
  #define prcprotection_adr                              0x00310300                                                   // prc_adr_base + 0x00000300
  #define prcprotection                                  (*(volatile unsigned int *)prcprotection_adr)
  #define prc_periphid0_adr                              0x00310fe0                                                   // prc_adr_base + 0x00000fe0
  #define prc_periphid0                                  (*(volatile unsigned int *)prc_periphid0_adr)
  #define prc_periphid1_adr                              0x00310fe4                                                   // prc_adr_base + 0x00000fe4
  #define prc_periphid1                                  (*(volatile unsigned int *)prc_periphid1_adr)
  #define prc_periphid2_adr                              0x00310fe8                                                   // prc_adr_base + 0x00000fe8
  #define prc_periphid2                                  (*(volatile unsigned int *)prc_periphid2_adr)
  #define prc_periphid3_adr                              0x00310fec                                                   // prc_adr_base + 0x00000fec
  #define prc_periphid3                                  (*(volatile unsigned int *)prc_periphid3_adr)
  #define prc_pcellid0_adr                               0x00310ff0                                                   // prc_adr_base + 0x00000ff0
  #define prc_pcellid0                                   (*(volatile unsigned int *)prc_pcellid0_adr)
  #define prc_pcellid1_adr                               0x00310ff4                                                   // prc_adr_base + 0x00000ff4
  #define prc_pcellid1                                   (*(volatile unsigned int *)prc_pcellid1_adr)
  #define prc_pcellid2_adr                               0x00310ff8                                                   // prc_adr_base + 0x00000ff8
  #define prc_pcellid2                                   (*(volatile unsigned int *)prc_pcellid2_adr)
  #define prc_pcellid3_adr                               0x00310ffc                                                   // prc_adr_base + 0x00000ffc
  #define prc_pcellid3                                   (*(volatile unsigned int *)prc_pcellid3_adr)
  #define smbidcyr0_adr                                  0x00308000                                                   // smi_ahb_adr_base + 0x00000000
  #define smbidcyr0                                      (*(volatile unsigned int *)smbidcyr0_adr)
  #define smbwst1r0_adr                                  0x00308004                                                   // smi_ahb_adr_base + 0x00000004
  #define smbwst1r0                                      (*(volatile unsigned int *)smbwst1r0_adr)
  #define smbwst2r0_adr                                  0x00308008                                                   // smi_ahb_adr_base + 0x00000008
  #define smbwst2r0                                      (*(volatile unsigned int *)smbwst2r0_adr)
  #define smbwstoenr0_adr                                0x0030800c                                                   // smi_ahb_adr_base + 0x0000000c
  #define smbwstoenr0                                    (*(volatile unsigned int *)smbwstoenr0_adr)
  #define smbwstwenr0_adr                                0x00308010                                                   // smi_ahb_adr_base + 0x00000010
  #define smbwstwenr0                                    (*(volatile unsigned int *)smbwstwenr0_adr)
  #define smbcr0_adr                                     0x00308014                                                   // smi_ahb_adr_base + 0x00000014
  #define smbcr0                                         (*(volatile unsigned int *)smbcr0_adr)
  #define smbsr0_adr                                     0x00308018                                                   // smi_ahb_adr_base + 0x00000018
  #define smbsr0                                         (*(volatile unsigned int *)smbsr0_adr)
  #define smbidcyr1_adr                                  0x0030801c                                                   // smi_ahb_adr_base + 0x0000001c
  #define smbidcyr1                                      (*(volatile unsigned int *)smbidcyr1_adr)
  #define smbwst1r1_adr                                  0x00308020                                                   // smi_ahb_adr_base + 0x00000020
  #define smbwst1r1                                      (*(volatile unsigned int *)smbwst1r1_adr)
  #define smbwst2r1_adr                                  0x00308024                                                   // smi_ahb_adr_base + 0x00000024
  #define smbwst2r1                                      (*(volatile unsigned int *)smbwst2r1_adr)
  #define smbwstoenr1_adr                                0x00308028                                                   // smi_ahb_adr_base + 0x00000028
  #define smbwstoenr1                                    (*(volatile unsigned int *)smbwstoenr1_adr)
  #define smbwstwenr1_adr                                0x0030802c                                                   // smi_ahb_adr_base + 0x0000002c
  #define smbwstwenr1                                    (*(volatile unsigned int *)smbwstwenr1_adr)
  #define smbcr1_adr                                     0x00308030                                                   // smi_ahb_adr_base + 0x00000030
  #define smbcr1                                         (*(volatile unsigned int *)smbcr1_adr)
  #define smbsr1_adr                                     0x00308034                                                   // smi_ahb_adr_base + 0x00000034
  #define smbsr1                                         (*(volatile unsigned int *)smbsr1_adr)
  #define smbidcyr2_adr                                  0x00308038                                                   // smi_ahb_adr_base + 0x00000038
  #define smbidcyr2                                      (*(volatile unsigned int *)smbidcyr2_adr)
  #define smbwst1r2_adr                                  0x0030803c                                                   // smi_ahb_adr_base + 0x0000003c
  #define smbwst1r2                                      (*(volatile unsigned int *)smbwst1r2_adr)
  #define smbwst2r2_adr                                  0x00308040                                                   // smi_ahb_adr_base + 0x00000040
  #define smbwst2r2                                      (*(volatile unsigned int *)smbwst2r2_adr)
  #define smbwstoenr2_adr                                0x00308044                                                   // smi_ahb_adr_base + 0x00000044
  #define smbwstoenr2                                    (*(volatile unsigned int *)smbwstoenr2_adr)
  #define smbwstwenr2_adr                                0x00308048                                                   // smi_ahb_adr_base + 0x00000048
  #define smbwstwenr2                                    (*(volatile unsigned int *)smbwstwenr2_adr)
  #define smbcr2_adr                                     0x0030804c                                                   // smi_ahb_adr_base + 0x0000004c
  #define smbcr2                                         (*(volatile unsigned int *)smbcr2_adr)
  #define smbsr2_adr                                     0x00308050                                                   // smi_ahb_adr_base + 0x00000050
  #define smbsr2                                         (*(volatile unsigned int *)smbsr2_adr)
  #define smbidcyr3_adr                                  0x00308054                                                   // smi_ahb_adr_base + 0x00000054
  #define smbidcyr3                                      (*(volatile unsigned int *)smbidcyr3_adr)
  #define smbwst1r3_adr                                  0x00308058                                                   // smi_ahb_adr_base + 0x00000058
  #define smbwst1r3                                      (*(volatile unsigned int *)smbwst1r3_adr)
  #define smbwst2r3_adr                                  0x0030805c                                                   // smi_ahb_adr_base + 0x0000005c
  #define smbwst2r3                                      (*(volatile unsigned int *)smbwst2r3_adr)
  #define smbwstoenr3_adr                                0x00308060                                                   // smi_ahb_adr_base + 0x00000060
  #define smbwstoenr3                                    (*(volatile unsigned int *)smbwstoenr3_adr)
  #define smbwstwenr3_adr                                0x00308064                                                   // smi_ahb_adr_base + 0x00000064
  #define smbwstwenr3                                    (*(volatile unsigned int *)smbwstwenr3_adr)
  #define smbcr3_adr                                     0x00308068                                                   // smi_ahb_adr_base + 0x00000068
  #define smbcr3                                         (*(volatile unsigned int *)smbcr3_adr)
  #define smbsr3_adr                                     0x0030806c                                                   // smi_ahb_adr_base + 0x0000006c
  #define smbsr3                                         (*(volatile unsigned int *)smbsr3_adr)
  #define smbidcyr4_adr                                  0x00308070                                                   // smi_ahb_adr_base + 0x00000070
  #define smbidcyr4                                      (*(volatile unsigned int *)smbidcyr4_adr)
  #define smbwst1r4_adr                                  0x00308074                                                   // smi_ahb_adr_base + 0x00000074
  #define smbwst1r4                                      (*(volatile unsigned int *)smbwst1r4_adr)
  #define smbwst2r4_adr                                  0x00308078                                                   // smi_ahb_adr_base + 0x00000078
  #define smbwst2r4                                      (*(volatile unsigned int *)smbwst2r4_adr)
  #define smbwstoenr4_adr                                0x0030807c                                                   // smi_ahb_adr_base + 0x0000007c
  #define smbwstoenr4                                    (*(volatile unsigned int *)smbwstoenr4_adr)
  #define smbwstwenr4_adr                                0x00308080                                                   // smi_ahb_adr_base + 0x00000080
  #define smbwstwenr4                                    (*(volatile unsigned int *)smbwstwenr4_adr)
  #define smbcr4_adr                                     0x00308084                                                   // smi_ahb_adr_base + 0x00000084
  #define smbcr4                                         (*(volatile unsigned int *)smbcr4_adr)
  #define smbsr4_adr                                     0x00308088                                                   // smi_ahb_adr_base + 0x00000088
  #define smbsr4                                         (*(volatile unsigned int *)smbsr4_adr)
  #define smbidcyr5_adr                                  0x0030808c                                                   // smi_ahb_adr_base + 0x0000008c
  #define smbidcyr5                                      (*(volatile unsigned int *)smbidcyr5_adr)
  #define smbwst1r5_adr                                  0x00308090                                                   // smi_ahb_adr_base + 0x00000090
  #define smbwst1r5                                      (*(volatile unsigned int *)smbwst1r5_adr)
  #define smbwst2r5_adr                                  0x00308094                                                   // smi_ahb_adr_base + 0x00000094
  #define smbwst2r5                                      (*(volatile unsigned int *)smbwst2r5_adr)
  #define smbwstoenr5_adr                                0x00308098                                                   // smi_ahb_adr_base + 0x00000098
  #define smbwstoenr5                                    (*(volatile unsigned int *)smbwstoenr5_adr)
  #define smbwstwenr5_adr                                0x0030809c                                                   // smi_ahb_adr_base + 0x0000009c
  #define smbwstwenr5                                    (*(volatile unsigned int *)smbwstwenr5_adr)
  #define smbcr5_adr                                     0x003080a0                                                   // smi_ahb_adr_base + 0x000000a0
  #define smbcr5                                         (*(volatile unsigned int *)smbcr5_adr)
  #define smbsr5_adr                                     0x003080a4                                                   // smi_ahb_adr_base + 0x000000a4
  #define smbsr5                                         (*(volatile unsigned int *)smbsr5_adr)
  #define smbidcyr6_adr                                  0x003080a8                                                   // smi_ahb_adr_base + 0x000000a8
  #define smbidcyr6                                      (*(volatile unsigned int *)smbidcyr6_adr)
  #define smbwst1r6_adr                                  0x003080ac                                                   // smi_ahb_adr_base + 0x000000ac
  #define smbwst1r6                                      (*(volatile unsigned int *)smbwst1r6_adr)
  #define smbwst2r6_adr                                  0x003080b0                                                   // smi_ahb_adr_base + 0x000000b0
  #define smbwst2r6                                      (*(volatile unsigned int *)smbwst2r6_adr)
  #define smbwstoenr6_adr                                0x003080b4                                                   // smi_ahb_adr_base + 0x000000b4
  #define smbwstoenr6                                    (*(volatile unsigned int *)smbwstoenr6_adr)
  #define smbwstwenr6_adr                                0x003080b8                                                   // smi_ahb_adr_base + 0x000000b8
  #define smbwstwenr6                                    (*(volatile unsigned int *)smbwstwenr6_adr)
  #define smbcr6_adr                                     0x003080bc                                                   // smi_ahb_adr_base + 0x000000bc
  #define smbcr6                                         (*(volatile unsigned int *)smbcr6_adr)
  #define smbsr6_adr                                     0x003080c0                                                   // smi_ahb_adr_base + 0x000000c0
  #define smbsr6                                         (*(volatile unsigned int *)smbsr6_adr)
  #define smbidcyr7_adr                                  0x003080c4                                                   // smi_ahb_adr_base + 0x000000c4
  #define smbidcyr7                                      (*(volatile unsigned int *)smbidcyr7_adr)
  #define smbwst1r7_adr                                  0x003080c8                                                   // smi_ahb_adr_base + 0x000000c8
  #define smbwst1r7                                      (*(volatile unsigned int *)smbwst1r7_adr)
  #define smbwst2r7_adr                                  0x003080cc                                                   // smi_ahb_adr_base + 0x000000cc
  #define smbwst2r7                                      (*(volatile unsigned int *)smbwst2r7_adr)
  #define smbwstoenr7_adr                                0x003080d0                                                   // smi_ahb_adr_base + 0x000000d0
  #define smbwstoenr7                                    (*(volatile unsigned int *)smbwstoenr7_adr)
  #define smbwstwenr7_adr                                0x003080d4                                                   // smi_ahb_adr_base + 0x000000d4
  #define smbwstwenr7                                    (*(volatile unsigned int *)smbwstwenr7_adr)
  #define smbcr7_adr                                     0x003080d8                                                   // smi_ahb_adr_base + 0x000000d8
  #define smbcr7                                         (*(volatile unsigned int *)smbcr7_adr)
  #define smbsr7_adr                                     0x003080dc                                                   // smi_ahb_adr_base + 0x000000dc
  #define smbsr7                                         (*(volatile unsigned int *)smbsr7_adr)
  #define smbews_adr                                     0x003080e0                                                   // smi_ahb_adr_base + 0x000000e0
  #define smbews                                         (*(volatile unsigned int *)smbews_adr)
  #define smcperiphid0_adr                               0x00308fe0                                                   // smi_ahb_adr_base + 0x00000fe0
  #define smcperiphid0                                   (*(volatile unsigned int *)smcperiphid0_adr)
  #define smcperiphid1_adr                               0x00308fe4                                                   // smi_ahb_adr_base + 0x00000fe4
  #define smcperiphid1                                   (*(volatile unsigned int *)smcperiphid1_adr)
  #define smcperiphid2_adr                               0x00308fe8                                                   // smi_ahb_adr_base + 0x00000fe8
  #define smcperiphid2                                   (*(volatile unsigned int *)smcperiphid2_adr)
  #define smcperiphid3_adr                               0x00308fec                                                   // smi_ahb_adr_base + 0x00000fec
  #define smcperiphid3                                   (*(volatile unsigned int *)smcperiphid3_adr)
  #define smcpcellid0_adr                                0x00308ff0                                                   // smi_ahb_adr_base + 0x00000ff0
  #define smcpcellid0                                    (*(volatile unsigned int *)smcpcellid0_adr)
  #define smcpcellid1_adr                                0x00308ff4                                                   // smi_ahb_adr_base + 0x00000ff4
  #define smcpcellid1                                    (*(volatile unsigned int *)smcpcellid1_adr)
  #define smcpcellid2_adr                                0x00308ff8                                                   // smi_ahb_adr_base + 0x00000ff8
  #define smcpcellid2                                    (*(volatile unsigned int *)smcpcellid2_adr)
  #define smcpcellid3_adr                                0x00308ffc                                                   // smi_ahb_adr_base + 0x00000ffc
  #define smcpcellid3                                    (*(volatile unsigned int *)smcpcellid3_adr)
  #define bpl_base                                       0x00318000                                                   // phy_adr_base + 0x00000000
  #define cr_base                                        0x00318000                                                   // bpl_base + 0x00000000
  #define fisrt_grp_base                                 0x00318000                                                   // cr_base
  #define cr_adr0                                        0x00318000                                                   // cr_base + 0x00000000
  #define cr0                                            (*(volatile unsigned int *)cr_adr0)
  #define sr_op_state_adr                                0x00318004                                                   // cr_adr0 + 0x00000004
  #define sr_op_state                                    (*(volatile unsigned int *)sr_op_state_adr)
  #define sr_base                                        0x00318008                                                   // sr_op_state_adr + 0x00000004
  #define wib_cr_op_state_adr                            0x00318014                                                   // sr_base + 0x0000000c
  #define wib_cr_op_state                                (*(volatile unsigned int *)wib_cr_op_state_adr)
  #define cr_adr1                                        0x00318018                                                   // sr_base + 0x00000010
  #define cr1                                            (*(volatile unsigned int *)cr_adr1)
  #define wib_time_offset_adr                            0x0031801c                                                   // sr_base + 0x00000014
  #define wib_time_offset                                (*(volatile unsigned int *)wib_time_offset_adr)
  #define dc_base                                        0x00318024                                                   // phy_tail + 0x00000004
  #define dc_pc_ctx_idx_adr                              0x00318024                                                   // dc_base + 0x00000000
  #define dc_pc_ctx_idx                                  (*(volatile unsigned int *)dc_pc_ctx_idx_adr)
  #define dc_hopst_adr                                   0x00318028                                                   // dc_base + 0x00000004
  #define dc_hopst                                       (*(volatile unsigned int *)dc_hopst_adr)
  #define dc_prty_lo_adr                                 0x00318030                                                   // dc_base + 0x0000000c
  #define dc_prty_lo                                     (*(volatile unsigned int *)dc_prty_lo_adr)
  #define dc_prty_hi_adr                                 0x00318034                                                   // dc_base + 0x00000010
  #define dc_prty_hi                                     (*(volatile unsigned int *)dc_prty_hi_adr)
  #define dc_bta_lo_adr                                  0x00318038                                                   // dc_base + 0x00000014
  #define dc_bta_lo                                      (*(volatile unsigned int *)dc_bta_lo_adr)
  #define dc_bta_hi_adr                                  0x0031803c                                                   // dc_base + 0x00000018
  #define dc_bta_hi                                      (*(volatile unsigned int *)dc_bta_hi_adr)
  #define dc_clsdev_adr                                  0x00318040                                                   // dc_base + 0x0000001c
  #define dc_clsdev                                      (*(volatile unsigned int *)dc_clsdev_adr)
  #define dc_ipa_lo_adr                                  0x00318044                                                   // dc_base + 0x00000020
  #define dc_ipa_lo                                      (*(volatile unsigned int *)dc_ipa_lo_adr)
  #define dc_ipa_hi_adr                                  0x00318048                                                   // dc_base + 0x00000024
  #define dc_ipa_hi                                      (*(volatile unsigned int *)dc_ipa_hi_adr)
  #define dc_pg_uap_adr                                  0x0031804c                                                   // dc_base + 0x00000028
  #define dc_pg_uap                                      (*(volatile unsigned int *)dc_pg_uap_adr)
  #define dc_fhs_pyld_adr                                0x00318050                                                   // dc_base + 0x0000002c
  #define dc_fhs_pyld                                    (*(volatile unsigned int *)dc_fhs_pyld_adr)
  #define dc_n_iq_adr                                    0x00318054                                                   // dc_base + 0x00000030
  #define dc_n_iq                                        (*(volatile unsigned int *)dc_n_iq_adr)
  #define dc_iq_to_adr                                   0x00318058                                                   // dc_base + 0x00000034
  #define dc_iq_to                                       (*(volatile unsigned int *)dc_iq_to_adr)
  #define dc_iq_respto_adr                               0x0031805c                                                   // dc_base + 0x00000038
  #define dc_iq_respto                                   (*(volatile unsigned int *)dc_iq_respto_adr)
  #define dc_n_pg_adr                                    0x00318060                                                   // dc_base + 0x0000003c
  #define dc_n_pg                                        (*(volatile unsigned int *)dc_n_pg_adr)
  #define dc_pg_to_adr                                   0x00318064                                                   // dc_base + 0x00000040
  #define dc_pg_to                                       (*(volatile unsigned int *)dc_pg_to_adr)
  #define dc_pg_respto_adr                               0x00318068                                                   // dc_base + 0x00000044
  #define dc_pg_respto                                   (*(volatile unsigned int *)dc_pg_respto_adr)
  #define dc_newcon_to_adr                               0x0031806c                                                   // dc_base + 0x00000048
  #define dc_newcon_to                                   (*(volatile unsigned int *)dc_newcon_to_adr)
  #define dc_pg_ckoff_adr                                0x00318070                                                   // dc_base + 0x0000004c
  #define dc_pg_ckoff                                    (*(volatile unsigned int *)dc_pg_ckoff_adr)
  #define dc_n_pclk_oft_adr                              0x00318074                                                   // dc_base + 0x00000050
  #define dc_n_pclk_oft                                  (*(volatile unsigned int *)dc_n_pclk_oft_adr)
  #define dc_n_clk_oft_adr                               0x00318078                                                   // dc_base + 0x00000054
  #define dc_n_clk_oft                                   (*(volatile unsigned int *)dc_n_clk_oft_adr)
  #define dc_n_clk_wake_cnt_adr                          0x0031807c                                                   // dc_base + 0x00000058
  #define dc_n_clk_wake_cnt                              (*(volatile unsigned int *)dc_n_clk_wake_cnt_adr)
  #define dc_nclk_ctl_adr                                0x00318080                                                   // dc_base + 0x0000005c
  #define dc_nclk_ctl                                    (*(volatile unsigned int *)dc_nclk_ctl_adr)
  #define dc_nbtc_pclk_adr                               0x00318084                                                   // dc_base + 0x00000060
  #define dc_nbtc_pclk                                   (*(volatile unsigned int *)dc_nbtc_pclk_adr)
  #define dc_nbtc_clk_adr                                0x00318088                                                   // dc_base + 0x00000064
  #define dc_nbtc_clk                                    (*(volatile unsigned int *)dc_nbtc_clk_adr)
  #define dc_acode_dly_adr                               0x0031808c                                                   // dc_base + 0x00000068
  #define dc_acode_dly                                   (*(volatile unsigned int *)dc_acode_dly_adr)
  #define dc_cr_op_st_en_cnt_adr                         0x00318090                                                   // dc_base + 0x0000006c
  #define dc_cr_op_st_en_cnt                             (*(volatile unsigned int *)dc_cr_op_st_en_cnt_adr)
  #define dc_rtx_start_cnt_adr                           0x00318094                                                   // dc_base + 0x00000070
  #define dc_rtx_start_cnt                               (*(volatile unsigned int *)dc_rtx_start_cnt_adr)
  #define dc_pll_en_cnt_adr                              0x00318098                                                   // dc_base + 0x00000074
  #define dc_pll_en_cnt                                  (*(volatile unsigned int *)dc_pll_en_cnt_adr)
  #define dc_inq_ckoff_adr                               0x0031809c                                                   // dc_base + 0x00000078
  #define dc_inq_ckoff                                   (*(volatile unsigned int *)dc_inq_ckoff_adr)
  #define dc_smpl_ctl_adr                                0x003180a0                                                   // dc_base + 0x0000007c
  #define dc_smpl_ctl                                    (*(volatile unsigned int *)dc_smpl_ctl_adr)
  #define dc_slot_offset_adr                             0x003180a4                                                   // dc_base + 0x00000080
  #define dc_slot_offset                                 (*(volatile unsigned int *)dc_slot_offset_adr)
  #define dc_win_pkt0_adr                                0x003180a8                                                   // dc_base + 0x00000084
  #define dc_win_pkt0                                    (*(volatile unsigned int *)dc_win_pkt0_adr)
  #define dc_win_pkt1_adr                                0x003180ac                                                   // dc_base + 0x00000088
  #define dc_win_pkt1                                    (*(volatile unsigned int *)dc_win_pkt1_adr)
  #define dc_win_pkt2_adr                                0x003180b0                                                   // dc_base + 0x0000008c
  #define dc_win_pkt2                                    (*(volatile unsigned int *)dc_win_pkt2_adr)
  #define dc_win_txconfx_adr                             0x003180b4                                                   // dc_base + 0x00000090
  #define dc_win_txconfx                                 (*(volatile unsigned int *)dc_win_txconfx_adr)
  #define txconfx_st_adr                                 0x003180b8                                                   // dc_base + 0x00000094
  #define txconfx_st                                     (*(volatile unsigned int *)txconfx_st_adr)
  #define dc_icoex_adr                                   0x003180bc                                                   // dc_base + 0x00000098
  #define dc_icoex                                       (*(volatile unsigned int *)dc_icoex_adr)
  #define dc_icoex_freq0_adr                             0x003180c0                                                   // dc_base + 0x0000009c
  #define dc_icoex_freq0                                 (*(volatile unsigned int *)dc_icoex_freq0_adr)
  #define dc_icoex_freq1_adr                             0x003180c4                                                   // dc_base + 0x000000a0
  #define dc_icoex_freq1                                 (*(volatile unsigned int *)dc_icoex_freq1_adr)
  #define dc_icoex_freq2_adr                             0x003180c8                                                   // dc_base + 0x000000a4
  #define dc_icoex_freq2                                 (*(volatile unsigned int *)dc_icoex_freq2_adr)
  #define dc_icoex_freq3_adr                             0x003180cc                                                   // dc_base + 0x000000a8
  #define dc_icoex_freq3                                 (*(volatile unsigned int *)dc_icoex_freq3_adr)
  #define dc_bt_clk_offset_adr                           0x003180d0                                                   // dc_base + 0x000000ac
  #define dc_bt_clk_offset                               (*(volatile unsigned int *)dc_bt_clk_offset_adr)
  #define dc_diac_lo_adr                                 0x003180d4                                                   // dc_base + 0x000000b0
  #define dc_diac_lo                                     (*(volatile unsigned int *)dc_diac_lo_adr)
  #define dc_diac_hi_adr                                 0x003180d8                                                   // dc_base + 0x000000b4
  #define dc_diac_hi                                     (*(volatile unsigned int *)dc_diac_hi_adr)
  #define dc_giac_lo_adr                                 0x003180dc                                                   // dc_base + 0x000000b8
  #define dc_giac_lo                                     (*(volatile unsigned int *)dc_giac_lo_adr)
  #define dc_giac_hi_adr                                 0x003180e0                                                   // dc_base + 0x000000bc
  #define dc_giac_hi                                     (*(volatile unsigned int *)dc_giac_hi_adr)
  #define dc_dual_synch_adr                              0x003180e4                                                   // dc_base + 0x000000c0
  #define dc_dual_synch                                  (*(volatile unsigned int *)dc_dual_synch_adr)
  #define dc_win_pkt3_adr                                0x003180e8                                                   // dc_base + 0x000000c4
  #define dc_win_pkt3                                    (*(volatile unsigned int *)dc_win_pkt3_adr)
  #define dc_2clb_eci_lsw_adr                            0x003180ec                                                   // dc_base + 0x000000c8
  #define dc_2clb_eci_lsw                                (*(volatile unsigned int *)dc_2clb_eci_lsw_adr)
  #define dc_2clb_eci_msw_adr                            0x003180f0                                                   // dc_base + 0x000000cc
  #define dc_2clb_eci_msw                                (*(volatile unsigned int *)dc_2clb_eci_msw_adr)
  #define dc_cap_SyncCnt_adr                             0x003180f4                                                   // dc_base + 0x000000d0
  #define dc_cap_SyncCnt                                 (*(volatile unsigned int *)dc_cap_SyncCnt_adr)
  #define dc_scan_pg_cfg_adr                             0x003180f8                                                   // dc_base + 0x000000d4
  #define dc_scan_pg_cfg                                 (*(volatile unsigned int *)dc_scan_pg_cfg_adr)
  #define dc_pcxclkdiff_adr                              0x003180fc                                                   // dc_base + 0x000000d8
  #define dc_pcxclkdiff                                  (*(volatile unsigned int *)dc_pcxclkdiff_adr)
  #define dcenc_base                                     0x00318100                                                   // bpl_base + 0x00000100
  #define secnd_grp_base                                 0x00318100                                                   // dcenc_base
  #define encryption_key_adr0                            0x00318180                                                   // dcenc_base + 0x00000020 * 0x00000004
  #define encryption_key0                                (*(volatile unsigned int *)encryption_key_adr0)
  #define encryption_key_adr1                            0x00318184                                                   // dcenc_base + 0x00000021 * 0x00000004
  #define encryption_key1                                (*(volatile unsigned int *)encryption_key_adr1)
  #define encryption_key_adr2                            0x00318188                                                   // dcenc_base + 0x00000022 * 0x00000004
  #define encryption_key2                                (*(volatile unsigned int *)encryption_key_adr2)
  #define encryption_key_adr3                            0x0031818c                                                   // dcenc_base + 0x00000023 * 0x00000004
  #define encryption_key3                                (*(volatile unsigned int *)encryption_key_adr3)
  #define pcx_base                                       0x00318200                                                   // bpl_base + 0x00000200
  #define third_grp_base                                 0x00318200                                                   // pcx_base
  #define pc_idx_ptr_adr                                 0x00318200                                                   // pcx_base + 0x00000000 * 0x00000004
  #define pc_idx_ptr                                     (*(volatile unsigned int *)pc_idx_ptr_adr)
  #define pcx_ctl_adr                                    0x00318204                                                   // pcx_base + 0x00000001 * 0x00000004
  #define pcx_ctl                                        (*(volatile unsigned int *)pcx_ctl_adr)
  #define pcx_pckoff_adr                                 0x00318208                                                   // pcx_base + 0x00000002 * 0x00000004
  #define pcx_pckoff                                     (*(volatile unsigned int *)pcx_pckoff_adr)
  #define pcx_ckoff_adr                                  0x0031820c                                                   // pcx_base + 0x00000003 * 0x00000004
  #define pcx_ckoff                                      (*(volatile unsigned int *)pcx_ckoff_adr)
  #define pcx_timer_ctl_adr                              0x00318210                                                   // pcx_base + 0x00000004 * 0x00000004
  #define pcx_timer_ctl                                  (*(volatile unsigned int *)pcx_timer_ctl_adr)
  #define pcx_timer_val_adr                              0x00318214                                                   // pcx_base + 0x00000005 * 0x00000004
  #define pcx_timer_val                                  (*(volatile unsigned int *)pcx_timer_val_adr)
  #define pc_acscd_lo_adr                                0x00318218                                                   // pcx_base + 0x00000006 * 0x00000004
  #define pc_acscd_lo                                    (*(volatile unsigned int *)pc_acscd_lo_adr)
  #define pc_acscd_hi_adr                                0x0031821c                                                   // pcx_base + 0x00000007 * 0x00000004
  #define pc_acscd_hi                                    (*(volatile unsigned int *)pc_acscd_hi_adr)
  #define pcx_uap_adr                                    0x00318220                                                   // pcx_base + 0x00000008 * 0x00000004
  #define pcx_uap                                        (*(volatile unsigned int *)pcx_uap_adr)
  #define pcx_nap_adr                                    0x00318224                                                   // pcx_base + 0x00000009 * 0x00000004
  #define pcx_nap                                        (*(volatile unsigned int *)pcx_nap_adr)
  #define pcx_pbtclk_adr                                 0x00318228                                                   // pcx_base + 0x0000000a * 0x00000004
  #define pcx_pbtclk                                     (*(volatile unsigned int *)pcx_pbtclk_adr)
  #define pcx_btclk_adr                                  0x0031822c                                                   // pcx_base + 0x0000000b * 0x00000004
  #define pcx_btclk                                      (*(volatile unsigned int *)pcx_btclk_adr)
  #define pcx_last_synctr_adr                            0x00318230                                                   // pcx_base + 0x0000000c * 0x00000004
  #define pcx_last_synctr                                (*(volatile unsigned int *)pcx_last_synctr_adr)
  #define pcx_nat_ckoff_adr                              0x00318234                                                   // pcx_base + 0x0000000d * 0x00000004
  #define pcx_nat_ckoff                                  (*(volatile unsigned int *)pcx_nat_ckoff_adr)
  #define pcx2_pbtclk_adr                                0x00318238                                                   // pcx_base + 0x0000000e * 0x00000004
  #define pcx2_pbtclk                                    (*(volatile unsigned int *)pcx2_pbtclk_adr)
  #define pcx2_btclk_adr                                 0x0031823c                                                   // pcx_base + 0x0000000f * 0x00000004
  #define pcx2_btclk                                     (*(volatile unsigned int *)pcx2_btclk_adr)
  #define pc_varacscd_lo_adr                             0x00318240                                                   // pcx_base + 0x00000010 * 0x00000004
  #define pc_varacscd_lo                                 (*(volatile unsigned int *)pc_varacscd_lo_adr)
  #define pc_varacscd_hi_adr                             0x00318244                                                   // pcx_base + 0x00000011 * 0x00000004
  #define pc_varacscd_hi                                 (*(volatile unsigned int *)pc_varacscd_hi_adr)
  #define btclk_vsync_val1_adr                           0x00318248                                                   // pcx_base + 0x00000012 * 0x00000004
  #define btclk_vsync_val1                               (*(volatile unsigned int *)btclk_vsync_val1_adr)
  #define btclk_vsync_val2_adr                           0x0031824c                                                   // pcx_base + 0x00000013 * 0x00000004
  #define btclk_vsync_val2                               (*(volatile unsigned int *)btclk_vsync_val2_adr)
  #define amodb1_adr                                     0x00318254                                                   // pcx_base + 0x00000015 * 0x00000004
  #define amodb1                                         (*(volatile unsigned int *)amodb1_adr)
  #define amodb2_adr                                     0x00318258                                                   // pcx_base + 0x00000016 * 0x00000004
  #define amodb2                                         (*(volatile unsigned int *)amodb2_adr)
  #define mod_calc_ctl_adr                               0x0031825c                                                   // pcx_base + 0x00000017 * 0x00000004
  #define mod_calc_ctl                                   (*(volatile unsigned int *)mod_calc_ctl_adr)
  #define a_in_amodb1_adr                                0x00318260                                                   // pcx_base + 0x00000018 * 0x00000004
  #define a_in_amodb1                                    (*(volatile unsigned int *)a_in_amodb1_adr)
  #define b_in_amodb1_adr                                0x00318264                                                   // pcx_base + 0x00000019 * 0x00000004
  #define b_in_amodb1                                    (*(volatile unsigned int *)b_in_amodb1_adr)
  #define a_in_amodb2_adr                                0x00318268                                                   // pcx_base + 0x0000001a * 0x00000004
  #define a_in_amodb2                                    (*(volatile unsigned int *)a_in_amodb2_adr)
  #define b_in_amodb2_adr                                0x0031826c                                                   // pcx_base + 0x0000001b * 0x00000004
  #define b_in_amodb2                                    (*(volatile unsigned int *)b_in_amodb2_adr)
  #define sys_clk_captd_adr                              0x00318270                                                   // pcx_base + 0x0000001c * 0x00000004
  #define sys_clk_captd                                  (*(volatile unsigned int *)sys_clk_captd_adr)
  #define sys_pclk_captd_adr                             0x00318274                                                   // pcx_base + 0x0000001d * 0x00000004
  #define sys_pclk_captd                                 (*(volatile unsigned int *)sys_pclk_captd_adr)
  #define pcx_enc_bc_adr                                 0x0031829c                                                   // pcx_base + 0x00000027 * 0x00000004
  #define pcx_enc_bc                                     (*(volatile unsigned int *)pcx_enc_bc_adr)
  #define pcx_mc_cfg_adr                                 0x003182a0                                                   // pcx_base + 0x00000028 * 0x00000004
  #define pcx_mc_cfg                                     (*(volatile unsigned int *)pcx_mc_cfg_adr)
  #define pcx_btclk_no_offset_adr                        0x003182a4                                                   // pcx_base + 0x00000029 * 0x00000004
  #define pcx_btclk_no_offset                            (*(volatile unsigned int *)pcx_btclk_no_offset_adr)
  #define dc_mcmp_ctrl_adr                               0x003182a8                                                   // pcx_base + 0x0000002a * 0x00000004
  #define dc_mcmp_ctrl                                   (*(volatile unsigned int *)dc_mcmp_ctrl_adr)
  #define dc_mmc_rx_status_adr                           0x003182ac                                                   // pcx_base + 0x0000002b * 0x00000004
  #define dc_mmc_rx_status                               (*(volatile unsigned int *)dc_mmc_rx_status_adr)
  #define cdx_base                                       0x00318300                                                   // bpl_base + 0x00000300
  #define forth_grp_base                                 0x00318300                                                   // cdx_base
  #define dc_mss_pc_indx_adr                             0x00318300                                                   // cdx_base + 0x00000000 * 0x00000004
  #define dc_mss_pc_indx                                 (*(volatile unsigned int *)dc_mss_pc_indx_adr)
  #define tx_power_adr                                   0x00318304                                                   // cdx_base + 0x00000001 * 0x00000004
  #define tx_power                                       (*(volatile unsigned int *)tx_power_adr)
  #define xcdx_hold_ctl_adr                              0x00318308                                                   // cdx_base + 0x00000002 * 0x00000004
  #define xcdx_hold_ctl                                  (*(volatile unsigned int *)xcdx_hold_ctl_adr)
  #define modemFifoPtr_adr                               0x00318334                                                   // cdx_base + 0x0000000d * 0x00000004
  #define modemFifoPtr                                   (*(volatile unsigned int *)modemFifoPtr_adr)
  #define enh_base                                       0x00318340                                                   // cdx_tail + 0x00000001 * 0x00000004
  #define task_ind_adr                                   0x00318340                                                   // enh_base + 0x00000000 * 0x00000004
  #define task_ind                                       (*(volatile unsigned int *)task_ind_adr)
  #define btsch_ctl_adr                                  0x00318344                                                   // enh_base + 0x00000001 * 0x00000004
  #define btsch_ctl                                      (*(volatile unsigned int *)btsch_ctl_adr)
  #define wimax_cap_clk_adr                              0x00318348                                                   // enh_base + 0x00000002 * 0x00000004
  #define wimax_cap_clk                                  (*(volatile unsigned int *)wimax_cap_clk_adr)
  #define wimax_cap_pclk_adr                             0x0031834c                                                   // enh_base + 0x00000003 * 0x00000004
  #define wimax_cap_pclk                                 (*(volatile unsigned int *)wimax_cap_pclk_adr)
  #define pc_match_adr                                   0x00318350                                                   // enh_base + 0x00000004 * 0x00000004
  #define pc_match                                       (*(volatile unsigned int *)pc_match_adr)
  #define wib_ctr_iv0_adr                                0x00318354                                                   // enh_base + 0x00000005 * 0x00000004
  #define wib_ctr_iv0                                    (*(volatile unsigned int *)wib_ctr_iv0_adr)
  #define wib_ctr_iv1_adr                                0x00318358                                                   // enh_base + 0x00000006 * 0x00000004
  #define wib_ctr_iv1                                    (*(volatile unsigned int *)wib_ctr_iv1_adr)
  #define wib_ctr_iv2_adr                                0x0031835c                                                   // enh_base + 0x00000007 * 0x00000004
  #define wib_ctr_iv2                                    (*(volatile unsigned int *)wib_ctr_iv2_adr)
  #define wib_ctr_iv3_adr                                0x00318360                                                   // enh_base + 0x00000008 * 0x00000004
  #define wib_ctr_iv3                                    (*(volatile unsigned int *)wib_ctr_iv3_adr)
  #define wib_rtx_ctrl_adr                               0x00318364                                                   // enh_base + 0x00000009 * 0x00000004
  #define wib_rtx_ctrl                                   (*(volatile unsigned int *)wib_rtx_ctrl_adr)
  #define pc0_hs_cap_clk_adr                             0x00318368                                                   // enh_base + 0x0000000a * 0x00000004
  #define pc0_hs_cap_clk                                 (*(volatile unsigned int *)pc0_hs_cap_clk_adr)
  #define pc1_hs_cap_clk_adr                             0x0031836c                                                   // enh_base + 0x0000000b * 0x00000004
  #define pc1_hs_cap_clk                                 (*(volatile unsigned int *)pc1_hs_cap_clk_adr)
  #define pc2_hs_cap_clk_adr                             0x00318370                                                   // enh_base + 0x0000000c * 0x00000004
  #define pc2_hs_cap_clk                                 (*(volatile unsigned int *)pc2_hs_cap_clk_adr)
  #define pc3_hs_cap_clk_adr                             0x00318374                                                   // enh_base + 0x0000000d * 0x00000004
  #define pc3_hs_cap_clk                                 (*(volatile unsigned int *)pc3_hs_cap_clk_adr)
  #define pc4_hs_cap_clk_adr                             0x00318378                                                   // enh_base + 0x0000000e * 0x00000004
  #define pc4_hs_cap_clk                                 (*(volatile unsigned int *)pc4_hs_cap_clk_adr)
  #define enh_ctl_adr                                    0x0031837c                                                   // enh_base + 0x0000000f * 0x00000004
  #define enh_ctl                                        (*(volatile unsigned int *)enh_ctl_adr)
  #define rtx_fifo_ctl_adr                               0x00318380                                                   // enh_base + 0x00000010 * 0x00000004
  #define rtx_fifo_ctl                                   (*(volatile unsigned int *)rtx_fifo_ctl_adr)
  #define wib_txpktctr_lo_adr                            0x00318384                                                   // enh_base + 0x00000011 * 0x00000004
  #define wib_txpktctr_lo                                (*(volatile unsigned int *)wib_txpktctr_lo_adr)
  #define wib_txpktctr_hi_adr                            0x00318388                                                   // enh_base + 0x00000012 * 0x00000004
  #define wib_txpktctr_hi                                (*(volatile unsigned int *)wib_txpktctr_hi_adr)
  #define wib_rxpktctr_lo_adr                            0x0031838c                                                   // enh_base + 0x00000013 * 0x00000004
  #define wib_rxpktctr_lo                                (*(volatile unsigned int *)wib_rxpktctr_lo_adr)
  #define wib_rxpktctr_hi_adr                            0x00318390                                                   // enh_base + 0x00000014 * 0x00000004
  #define wib_rxpktctr_hi                                (*(volatile unsigned int *)wib_rxpktctr_hi_adr)
  #define wib_t_ifs_adr                                  0x00318394                                                   // enh_base + 0x00000015 * 0x00000004
  #define wib_t_ifs                                      (*(volatile unsigned int *)wib_t_ifs_adr)
  #define tbfc_ctrl_adr                                  0x00318398                                                   // enh_base + 0x00000016 * 0x00000004
  #define tbfc_ctrl                                      (*(volatile unsigned int *)tbfc_ctrl_adr)
  #define tbfc_trig_pkt_num_adr                          0x0031839c                                                   // enh_base + 0x00000017 * 0x00000004
  #define tbfc_trig_pkt_num                              (*(volatile unsigned int *)tbfc_trig_pkt_num_adr)
  #define tx_rx_anything_time_adr                        0x003183a0                                                   // enh_base + 0x00000018 * 0x00000004
  #define tx_rx_anything_time                            (*(volatile unsigned int *)tx_rx_anything_time_adr)
  #define tx_rx_anytime_adr                              0x003183a4                                                   // enh_base + 0x00000019 * 0x00000004
  #define tx_rx_anytime                                  (*(volatile unsigned int *)tx_rx_anytime_adr)
  #define rampup_bits_adr                                0x003183a8                                                   // enh_base + 0x0000001a * 0x00000004
  #define rampup_bits                                    (*(volatile unsigned int *)rampup_bits_adr)
  #define any_acs_code_adr                               0x003183ac                                                   // enh_base + 0x0000001b * 0x00000004
  #define any_acs_code                                   (*(volatile unsigned int *)any_acs_code_adr)
  #define pc_clk_reached_adr                             0x003183b0                                                   // enh_base + 0x0000001c * 0x00000004
  #define pc_clk_reached                                 (*(volatile unsigned int *)pc_clk_reached_adr)
  #define ext_synch_recv_ctrl_adr                        0x003183b4                                                   // enh_base + 0x0000001d * 0x00000004
  #define ext_synch_recv_ctrl                            (*(volatile unsigned int *)ext_synch_recv_ctrl_adr)
  #define ext_synch_recv_rise_clk_adr                    0x003183b8                                                   // enh_base + 0x0000001e * 0x00000004
  #define ext_synch_recv_rise_clk                        (*(volatile unsigned int *)ext_synch_recv_rise_clk_adr)
  #define ext_synch_recv_fall_clk_adr                    0x003183bc                                                   // enh_base + 0x0000001f * 0x00000004
  #define ext_synch_recv_fall_clk                        (*(volatile unsigned int *)ext_synch_recv_fall_clk_adr)
  #define ext_synch_trigger_bt_clk_adr                   0x003183c0                                                   // enh_base + 0x00000020 * 0x00000004
  #define ext_synch_trigger_bt_clk                       (*(volatile unsigned int *)ext_synch_trigger_bt_clk_adr)
  #define LTE_snap_ctrl_adr                              0x003183c4                                                   // enh_base + 0x00000021 * 0x00000004
  #define LTE_snap_ctrl                                  (*(volatile unsigned int *)LTE_snap_ctrl_adr)
  #define LTE_FRAME_snap_clk_adr                         0x003183c8                                                   // enh_base + 0x00000022 * 0x00000004
  #define LTE_FRAME_snap_clk                             (*(volatile unsigned int *)LTE_FRAME_snap_clk_adr)
  #define LTE_MWS_RX_snap_clk_adr                        0x003183cc                                                   // enh_base + 0x00000023 * 0x00000004
  #define LTE_MWS_RX_snap_clk                            (*(volatile unsigned int *)LTE_MWS_RX_snap_clk_adr)
  #define LTE_MWS_TX_snap_clk_adr                        0x003183d0                                                   // enh_base + 0x00000024 * 0x00000004
  #define LTE_MWS_TX_snap_clk                            (*(volatile unsigned int *)LTE_MWS_TX_snap_clk_adr)
  #define LTE_snap_pclk_adr                              0x003183d4                                                   // enh_base + 0x00000025 * 0x00000004
  #define LTE_snap_pclk                                  (*(volatile unsigned int *)LTE_snap_pclk_adr)
  #define LTE_coex_win0_adr                              0x003183d8                                                   // enh_base + 0x00000026 * 0x00000004
  #define LTE_coex_win0                                  (*(volatile unsigned int *)LTE_coex_win0_adr)
  #define LTE_coex_win1_adr                              0x003183dc                                                   // enh_base + 0x00000027 * 0x00000004
  #define LTE_coex_win1                                  (*(volatile unsigned int *)LTE_coex_win1_adr)
  #define gci_coex_out_mask_adr                          0x003183e0                                                   // enh_base + 0x00000028 * 0x00000004
  #define gci_coex_out_mask                              (*(volatile unsigned int *)gci_coex_out_mask_adr)
  #define ext_synch_trigger_bt_pclk_adr                  0x003183e4                                                   // enh_base + 0x00000029 * 0x00000004
  #define ext_synch_trigger_bt_pclk                      (*(volatile unsigned int *)ext_synch_trigger_bt_pclk_adr)
  #define fec_2_3_sft_ctrl_adr                           0x003183e8                                                   // enh_base + 0x0000002a * 0x00000004
  #define fec_2_3_sft_ctrl                               (*(volatile unsigned int *)fec_2_3_sft_ctrl_adr)
  #define fec_2_3_sft_status_adr                         0x003183ec                                                   // enh_base + 0x0000002b * 0x00000004
  #define fec_2_3_sft_status                             (*(volatile unsigned int *)fec_2_3_sft_status_adr)
  #define remote_counter_adr                             0x003183f0                                                   // enh_base + 0x0000002c * 0x00000004
  #define remote_counter                                 (*(volatile unsigned int *)remote_counter_adr)
  #define rpa_reslv_status_1_adr                         0x003183f4                                                   // enh_base + 0x0000002d * 0x00000004
  #define rpa_reslv_status_1                             (*(volatile unsigned int *)rpa_reslv_status_1_adr)
  #define rpa_reslv_status_2_adr                         0x003183f8                                                   // enh_base + 0x0000002e * 0x00000004
  #define rpa_reslv_status_2                             (*(volatile unsigned int *)rpa_reslv_status_2_adr)
  #define countr_threld_adr                              0x003183fc                                                   // enh_base + 0x0000002f * 0x00000004
  #define countr_threld                                  (*(volatile unsigned int *)countr_threld_adr)
  #define diag_base                                      0x00318400                                                   // bpl_base + 0x00000400
  #define fifth_grp_base                                 0x00318400                                                   // diag_base
  #define di_test_ctl_adr                                0x00318400                                                   // diag_base + 0x00000000 * 0x00000004
  #define di_test_ctl                                    (*(volatile unsigned int *)di_test_ctl_adr)
  #define di_mod_index_ctl_adr                           0x00318404                                                   // diag_base + 0x00000001 * 0x00000004
  #define di_mod_index_ctl                               (*(volatile unsigned int *)di_mod_index_ctl_adr)
  #define di_rf_ctl_adr0                                 0x00318408                                                   // diag_base + 0x00000002 * 0x00000004
  #define di_rf_ctl0                                     (*(volatile unsigned int *)di_rf_ctl_adr0)
  #define di_rf_ctl_adr1                                 0x0031840c                                                   // diag_base + 0x00000003 * 0x00000004
  #define di_rf_ctl1                                     (*(volatile unsigned int *)di_rf_ctl_adr1)
  #define di_tmode_ctl_adr                               0x00318410                                                   // diag_base + 0x00000004 * 0x00000004
  #define di_tmode_ctl                                   (*(volatile unsigned int *)di_tmode_ctl_adr)
  #define di_tmode_rx_hf_adr                             0x00318414                                                   // diag_base + 0x00000005 * 0x00000004
  #define di_tmode_rx_hf                                 (*(volatile unsigned int *)di_tmode_rx_hf_adr)
  #define di_tmode_tx_hf_adr                             0x00318418                                                   // diag_base + 0x00000006 * 0x00000004
  #define di_tmode_tx_hf                                 (*(volatile unsigned int *)di_tmode_tx_hf_adr)
  #define di_lcu_substate_adr0                           0x0031841c                                                   // diag_base + 0x00000007 * 0x00000004
  #define di_lcu_substate0                               (*(volatile unsigned int *)di_lcu_substate_adr0)
  #define di_lcu_substate_adr1                           0x00318420                                                   // diag_base + 0x00000008 * 0x00000004
  #define di_lcu_substate1                               (*(volatile unsigned int *)di_lcu_substate_adr1)
  #define di_tx_pattern_adr                              0x00318440                                                   // diag_base + 0x00000010 * 0x00000004
  #define di_tx_pattern                                  (*(volatile unsigned int *)di_tx_pattern_adr)
  #define di_tx_pattern_sel_adr                          0x00318444                                                   // diag_base + 0x00000011 * 0x00000004
  #define di_tx_pattern_sel                              (*(volatile unsigned int *)di_tx_pattern_sel_adr)
  #define sco_pc_context_adr                             0x00318448                                                   // diag_base + 0x00000012 * 0x00000004
  #define sco_pc_context                                 (*(volatile unsigned int *)sco_pc_context_adr)
  #define di_phy_fpga_vid_adr                            0x0031844c                                                   // diag_base + 0x00000013 * 0x00000004
  #define di_phy_fpga_vid                                (*(volatile unsigned int *)di_phy_fpga_vid_adr)
  #define di_phy_fpga_48m_dcm_adr                        0x00318450                                                   // diag_base + 0x00000014 * 0x00000004
  #define di_phy_fpga_48m_dcm                            (*(volatile unsigned int *)di_phy_fpga_48m_dcm_adr)
  #define fpga_txconfx_gen_ctl_adr                       0x00318458                                                   // diag_base + 0x00000016 * 0x00000004
  #define fpga_txconfx_gen_ctl                           (*(volatile unsigned int *)fpga_txconfx_gen_ctl_adr)
  #define park_base                                      0x0031847c                                                   // diag_tail + 0x00000001 * 0x00000004
  #define scox_d_sco_adr                                 0x00318480                                                   // park_base + 0x00000001 * 0x00000004
  #define scox_d_sco                                     (*(volatile unsigned int *)scox_d_sco_adr)
  #define scox_t_sco_adr                                 0x00318484                                                   // park_base + 0x00000002 * 0x00000004
  #define scox_t_sco                                     (*(volatile unsigned int *)scox_t_sco_adr)
  #define pcx_n_poll_adr                                 0x00318488                                                   // park_base + 0x00000003 * 0x00000004
  #define pcx_n_poll                                     (*(volatile unsigned int *)pcx_n_poll_adr)
  #define park_available01_adr                           0x0031848c                                                   // park_base + 0x00000004 * 0x00000004
  #define park_available01                               (*(volatile unsigned int *)park_available01_adr)
  #define park_ctl_adr                                   0x00318490                                                   // park_base + 0x00000005 * 0x00000004
  #define park_ctl                                       (*(volatile unsigned int *)park_ctl_adr)
  #define park_status_adr                                0x00318494                                                   // park_base + 0x00000006 * 0x00000004
  #define park_status                                    (*(volatile unsigned int *)park_status_adr)
  #define bt_aes_ses_key0_adr                            0x00318498                                                   // park_base + 0x00000007 * 0x00000004
  #define bt_aes_ses_key0                                (*(volatile unsigned int *)bt_aes_ses_key0_adr)
  #define bt_aes_ses_key1_adr                            0x0031849c                                                   // park_base + 0x00000008 * 0x00000004
  #define bt_aes_ses_key1                                (*(volatile unsigned int *)bt_aes_ses_key1_adr)
  #define bt_aes_ses_key2_adr                            0x003184a0                                                   // park_base + 0x00000009 * 0x00000004
  #define bt_aes_ses_key2                                (*(volatile unsigned int *)bt_aes_ses_key2_adr)
  #define bt_aes_ses_key3_adr                            0x003184a4                                                   // park_base + 0x0000000a * 0x00000004
  #define bt_aes_ses_key3                                (*(volatile unsigned int *)bt_aes_ses_key3_adr)
  #define bt_aes_status1_adr                             0x003184a8                                                   // park_base + 0x0000000b * 0x00000004
  #define bt_aes_status1                                 (*(volatile unsigned int *)bt_aes_status1_adr)
  #define bt_aes_status2_adr                             0x003184ac                                                   // park_base + 0x0000000c * 0x00000004
  #define bt_aes_status2                                 (*(volatile unsigned int *)bt_aes_status2_adr)
  #define sri_base                                       0x00318500                                                   // bpl_base + 0x00000500
  #define sixth_grp_base                                 0x00318500                                                   // sri_base
  #define dc_sri_rf_ctl_adr0                             0x00318524                                                   // sri_base + 0x00000009 * 0x00000004
  #define dc_sri_rf_ctl0                                 (*(volatile unsigned int *)dc_sri_rf_ctl_adr0)
  #define dc_sri_rf_ctl_adr1                             0x00318528                                                   // sri_base + 0x0000000a * 0x00000004
  #define dc_sri_rf_ctl1                                 (*(volatile unsigned int *)dc_sri_rf_ctl_adr1)
  #define dc_sri_rssi_val_adr                            0x0031852c                                                   // sri_base + 0x0000000b * 0x00000004
  #define dc_sri_rssi_val                                (*(volatile unsigned int *)dc_sri_rssi_val_adr)
  #define dc_sri_pwr_ctl_adr                             0x00318530                                                   // sri_base + 0x0000000c * 0x00000004
  #define dc_sri_pwr_ctl                                 (*(volatile unsigned int *)dc_sri_pwr_ctl_adr)
  #define dc_t_synth_pu_adr                              0x00318534                                                   // sri_base + 0x0000000d * 0x00000004
  #define dc_t_synth_pu                                  (*(volatile unsigned int *)dc_t_synth_pu_adr)
  #define dc_t_sl_ctl_adr                                0x00318538                                                   // sri_base + 0x0000000e * 0x00000004
  #define dc_t_sl_ctl                                    (*(volatile unsigned int *)dc_t_sl_ctl_adr)
  #define dc_t_pa_ramp_adr                               0x0031853c                                                   // sri_base + 0x0000000f * 0x00000004
  #define dc_t_pa_ramp                                   (*(volatile unsigned int *)dc_t_pa_ramp_adr)
  #define dc_t_pa_down_adr                               0x00318540                                                   // sri_base + 0x00000010 * 0x00000004
  #define dc_t_pa_down                                   (*(volatile unsigned int *)dc_t_pa_down_adr)
  #define dc_t_tx_pu_adr                                 0x00318544                                                   // sri_base + 0x00000011 * 0x00000004
  #define dc_t_tx_pu                                     (*(volatile unsigned int *)dc_t_tx_pu_adr)
  #define dc_t_rx_pu_adr                                 0x00318548                                                   // sri_base + 0x00000012 * 0x00000004
  #define dc_t_rx_pu                                     (*(volatile unsigned int *)dc_t_rx_pu_adr)
  #define bt_cont_event_ctl_en_adr                       0x0031854c                                                   // sri_base + 0x00000013 * 0x00000004
  #define bt_cont_event_ctl_en                           (*(volatile unsigned int *)bt_cont_event_ctl_en_adr)
  #define bt_cont_event_ctl_0_adr                        0x00318550                                                   // sri_base + 0x00000014 * 0x00000004
  #define bt_cont_event_ctl_0                            (*(volatile unsigned int *)bt_cont_event_ctl_0_adr)
  #define bt_cont_event_ctl_1_adr                        0x00318554                                                   // sri_base + 0x00000015 * 0x00000004
  #define bt_cont_event_ctl_1                            (*(volatile unsigned int *)bt_cont_event_ctl_1_adr)
  #define bt_cont_event_ctl_2_adr                        0x00318558                                                   // sri_base + 0x00000016 * 0x00000004
  #define bt_cont_event_ctl_2                            (*(volatile unsigned int *)bt_cont_event_ctl_2_adr)
  #define bt_cont_event_ctl_3_adr                        0x0031855c                                                   // sri_base + 0x00000017 * 0x00000004
  #define bt_cont_event_ctl_3                            (*(volatile unsigned int *)bt_cont_event_ctl_3_adr)
  #define bt_cont_event_ctl_4_adr                        0x00318560                                                   // sri_base + 0x00000018 * 0x00000004
  #define bt_cont_event_ctl_4                            (*(volatile unsigned int *)bt_cont_event_ctl_4_adr)
  #define dc_available01_adr                             0x00318564                                                   // sri_base + 0x00000019 * 0x00000004
  #define dc_available01                                 (*(volatile unsigned int *)dc_available01_adr)
  #define afh_base                                       0x00318600                                                   // bpl_base + 0x00000600
  #define seventh_grp_base                               0x00318600                                                   // afh_base
  #define dc_afh_ctl_adr                                 0x00318620                                                   // afh_base + 0x00000020
  #define dc_afh_ctl                                     (*(volatile unsigned int *)dc_afh_ctl_adr)
  #define dc_ind_d_ptr_adr                               0x00318624                                                   // afh_base + 0x00000024
  #define dc_ind_d_ptr                                   (*(volatile unsigned int *)dc_ind_d_ptr_adr)
  #define dc_hd_acc_cfg_adr                              0x00318628                                                   // afh_base + 0x00000028
  #define dc_hd_acc_cfg                                  (*(volatile unsigned int *)dc_hd_acc_cfg_adr)
  #define dc_up_opcode_adr                               0x0031862c                                                   // afh_base + 0x0000002c
  #define dc_up_opcode                                   (*(volatile unsigned int *)dc_up_opcode_adr)
  #define up_reg_b_adr                                   0x00318630                                                   // afh_base + 0x00000030
  #define up_reg_b                                       (*(volatile unsigned int *)up_reg_b_adr)
  #define up_reg_c_adr                                   0x00318634                                                   // afh_base + 0x00000034
  #define up_reg_c                                       (*(volatile unsigned int *)up_reg_c_adr)
  #define up_reg_d_adr                                   0x00318638                                                   // afh_base + 0x00000038
  #define up_reg_d                                       (*(volatile unsigned int *)up_reg_d_adr)
  #define dc_reg_a_adr                                   0x0031863c                                                   // afh_base + 0x0000003c
  #define dc_reg_a                                       (*(volatile unsigned int *)dc_reg_a_adr)
  #define dc_reg_b_adr                                   0x00318640                                                   // afh_base + 0x00000040
  #define dc_reg_b                                       (*(volatile unsigned int *)dc_reg_b_adr)
  #define dc_reg_c_adr                                   0x00318644                                                   // afh_base + 0x00000044
  #define dc_reg_c                                       (*(volatile unsigned int *)dc_reg_c_adr)
  #define dc_reg_d_adr                                   0x00318648                                                   // afh_base + 0x00000048
  #define dc_reg_d                                       (*(volatile unsigned int *)dc_reg_d_adr)
  #define dc_opcode_adr0                                 0x0031864c                                                   // afh_base + 0x0000004c
  #define dc_opcode0                                     (*(volatile unsigned int *)dc_opcode_adr0)
  #define dc_opcode_adr1                                 0x00318650                                                   // afh_base + 0x00000050
  #define dc_opcode1                                     (*(volatile unsigned int *)dc_opcode_adr1)
  #define dc_opcode_adr2                                 0x00318654                                                   // afh_base + 0x00000054
  #define dc_opcode2                                     (*(volatile unsigned int *)dc_opcode_adr2)
  #define dc_opcode_adr3                                 0x00318658                                                   // afh_base + 0x00000058
  #define dc_opcode3                                     (*(volatile unsigned int *)dc_opcode_adr3)
  #define dc_opcode_adr4                                 0x0031865c                                                   // afh_base + 0x0000005c
  #define dc_opcode4                                     (*(volatile unsigned int *)dc_opcode_adr4)
  #define dc_opcode_adr5                                 0x00318660                                                   // afh_base + 0x00000060
  #define dc_opcode5                                     (*(volatile unsigned int *)dc_opcode_adr5)
  #define dc_opcode_adr6                                 0x00318664                                                   // afh_base + 0x00000064
  #define dc_opcode6                                     (*(volatile unsigned int *)dc_opcode_adr6)
  #define dc_opcode_adr7                                 0x00318668                                                   // afh_base + 0x00000068
  #define dc_opcode7                                     (*(volatile unsigned int *)dc_opcode_adr7)
  #define dc_opcode_adr8                                 0x0031866c                                                   // afh_base + 0x0000006c
  #define dc_opcode8                                     (*(volatile unsigned int *)dc_opcode_adr8)
  #define dc_opcode_adr9                                 0x00318670                                                   // afh_base + 0x00000070
  #define dc_opcode9                                     (*(volatile unsigned int *)dc_opcode_adr9)
  #define dc_opcode_adr10                                0x00318674                                                   // afh_base + 0x00000074
  #define dc_opcode10                                    (*(volatile unsigned int *)dc_opcode_adr10)
  #define dc_opcode_adr11                                0x00318678                                                   // afh_base + 0x00000078
  #define dc_opcode11                                    (*(volatile unsigned int *)dc_opcode_adr11)
  #define dc_opcode_adr12                                0x0031867c                                                   // afh_base + 0x0000007c
  #define dc_opcode12                                    (*(volatile unsigned int *)dc_opcode_adr12)
  #define dc_opcode_adr13                                0x00318680                                                   // afh_base + 0x00000080
  #define dc_opcode13                                    (*(volatile unsigned int *)dc_opcode_adr13)
  #define dc_opcode_adr14                                0x00318684                                                   // afh_base + 0x00000084
  #define dc_opcode14                                    (*(volatile unsigned int *)dc_opcode_adr14)
  #define dc_opcode_adr15                                0x00318688                                                   // afh_base + 0x00000088
  #define dc_opcode15                                    (*(volatile unsigned int *)dc_opcode_adr15)
  #define dc_log_data_adr0                               0x0031868c                                                   // afh_base + 0x0000008c
  #define dc_log_data0                                   (*(volatile unsigned int *)dc_log_data_adr0)
  #define dc_log_data_adr1                               0x00318690                                                   // afh_base + 0x00000090
  #define dc_log_data1                                   (*(volatile unsigned int *)dc_log_data_adr1)
  #define dc_log_data_adr2                               0x00318694                                                   // afh_base + 0x00000094
  #define dc_log_data2                                   (*(volatile unsigned int *)dc_log_data_adr2)
  #define dc_log_data_adr3                               0x00318698                                                   // afh_base + 0x00000098
  #define dc_log_data3                                   (*(volatile unsigned int *)dc_log_data_adr3)
  #define dc_log_data_adr4                               0x0031869c                                                   // afh_base + 0x0000009c
  #define dc_log_data4                                   (*(volatile unsigned int *)dc_log_data_adr4)
  #define dc_fhout_adr                                   0x003186a0                                                   // afh_base + 0x000000a0
  #define dc_fhout                                       (*(volatile unsigned int *)dc_fhout_adr)
  #define dc_fk_remap_adr                                0x003186a4                                                   // afh_base + 0x000000a4
  #define dc_fk_remap                                    (*(volatile unsigned int *)dc_fk_remap_adr)
  #define dc_misc_ctl_adr                                0x003186a8                                                   // afh_base + 0x000000a8
  #define dc_misc_ctl                                    (*(volatile unsigned int *)dc_misc_ctl_adr)
  #define dc_x_clk_adr                                   0x003186ac                                                   // afh_base + 0x000000ac
  #define dc_x_clk                                       (*(volatile unsigned int *)dc_x_clk_adr)
  #define used_carriers_32t0_adr                         0x003186b0                                                   // afh_base + 0x000000b0
  #define used_carriers_32t0                             (*(volatile unsigned int *)used_carriers_32t0_adr)
  #define used_carriers_64t0_adr                         0x003186b4                                                   // afh_base + 0x000000b4
  #define used_carriers_64t0                             (*(volatile unsigned int *)used_carriers_64t0_adr)
  #define used_carriers_79t0_adr                         0x003186b8                                                   // afh_base + 0x000000b8
  #define used_carriers_79t0                             (*(volatile unsigned int *)used_carriers_79t0_adr)
  #define used_carriers_32t1_adr                         0x003186bc                                                   // afh_base + 0x000000bc
  #define used_carriers_32t1                             (*(volatile unsigned int *)used_carriers_32t1_adr)
  #define used_carriers_64t1_adr                         0x003186c0                                                   // afh_base + 0x000000c0
  #define used_carriers_64t1                             (*(volatile unsigned int *)used_carriers_64t1_adr)
  #define used_carriers_79t1_adr                         0x003186c4                                                   // afh_base + 0x000000c4
  #define used_carriers_79t1                             (*(volatile unsigned int *)used_carriers_79t1_adr)
  #define bt_aes_IV0_adr                                 0x003186c8                                                   // afh_base + 0x000000c8
  #define bt_aes_IV0                                     (*(volatile unsigned int *)bt_aes_IV0_adr)
  #define bt_aes_IV1_adr                                 0x003186cc                                                   // afh_base + 0x000000cc
  #define bt_aes_IV1                                     (*(volatile unsigned int *)bt_aes_IV1_adr)
  #define bt_aes_IV2_adr                                 0x003186d0                                                   // afh_base + 0x000000d0
  #define bt_aes_IV2                                     (*(volatile unsigned int *)bt_aes_IV2_adr)
  #define bt_aes_IV3_adr                                 0x003186d4                                                   // afh_base + 0x000000d4
  #define bt_aes_IV3                                     (*(volatile unsigned int *)bt_aes_IV3_adr)
  #define bt_aes_ctr0_0_adr                              0x003186d8                                                   // afh_base + 0x000000d8
  #define bt_aes_ctr0_0                                  (*(volatile unsigned int *)bt_aes_ctr0_0_adr)
  #define bt_aes_ctr0_1_adr                              0x003186dc                                                   // afh_base + 0x000000dc
  #define bt_aes_ctr0_1                                  (*(volatile unsigned int *)bt_aes_ctr0_1_adr)
  #define bt_aes_ctr0_2_adr                              0x003186e0                                                   // afh_base + 0x000000e0
  #define bt_aes_ctr0_2                                  (*(volatile unsigned int *)bt_aes_ctr0_2_adr)
  #define bt_aes_ctr0_3_adr                              0x003186e4                                                   // afh_base + 0x000000e4
  #define bt_aes_ctr0_3                                  (*(volatile unsigned int *)bt_aes_ctr0_3_adr)
  #define bt_aes_ctr_icv0_adr                            0x003186e8                                                   // afh_base + 0x000000e8
  #define bt_aes_ctr_icv0                                (*(volatile unsigned int *)bt_aes_ctr_icv0_adr)
  #define bt_aes_ctr_icv1_adr                            0x003186ec                                                   // afh_base + 0x000000ec
  #define bt_aes_ctr_icv1                                (*(volatile unsigned int *)bt_aes_ctr_icv1_adr)
  #define bt_aes_ctr_icv2_adr                            0x003186f0                                                   // afh_base + 0x000000f0
  #define bt_aes_ctr_icv2                                (*(volatile unsigned int *)bt_aes_ctr_icv2_adr)
  #define bt_aes_ctr_icv3_adr                            0x003186f4                                                   // afh_base + 0x000000f4
  #define bt_aes_ctr_icv3                                (*(volatile unsigned int *)bt_aes_ctr_icv3_adr)
  #define eighth_grp_base                                0x00318700                                                   // bpl_base + 0x00000700
  #define df_base                                        0x00318700                                                   // eighth_grp_base
  #define wib_df_ctrl1_reg_adr                           0x00318700                                                   // df_base + 0x00000000
  #define wib_df_ctrl1_reg                               (*(volatile unsigned int *)wib_df_ctrl1_reg_adr)
  #define wib_df_ctrl2_reg_adr                           0x00318704                                                   // df_base + 0x00000004
  #define wib_df_ctrl2_reg                               (*(volatile unsigned int *)wib_df_ctrl2_reg_adr)
  #define wib_df_ctrl3_reg_adr                           0x00318708                                                   // df_base + 0x00000008
  #define wib_df_ctrl3_reg                               (*(volatile unsigned int *)wib_df_ctrl3_reg_adr)
  #define wib_df_ctrl4_reg_adr                           0x0031870c                                                   // df_base + 0x0000000c
  #define wib_df_ctrl4_reg                               (*(volatile unsigned int *)wib_df_ctrl4_reg_adr)
  #define wib_df_spare_reg_adr                           0x00318710                                                   // df_base + 0x00000010
  #define wib_df_spare_reg                               (*(volatile unsigned int *)wib_df_spare_reg_adr)
  #define wib_ctrl_reg2_adr                              0x00318714                                                   // df_base + 0x00000014
  #define wib_ctrl_reg2                                  (*(volatile unsigned int *)wib_ctrl_reg2_adr)
  #define tx_rx_anytime_ctrl1_adr                        0x00318718                                                   // df_base + 0x00000018
  #define tx_rx_anytime_ctrl1                            (*(volatile unsigned int *)tx_rx_anytime_ctrl1_adr)
  #define tx_rx_anytime_ctrl2_adr                        0x0031871c                                                   // df_base + 0x0000001c
  #define tx_rx_anytime_ctrl2                            (*(volatile unsigned int *)tx_rx_anytime_ctrl2_adr)
  #define tx_rx_anytime_ctrl3_adr                        0x00318720                                                   // df_base + 0x00000020
  #define tx_rx_anytime_ctrl3                            (*(volatile unsigned int *)tx_rx_anytime_ctrl3_adr)
  #define tx_rx_anytime_ctrl4_adr                        0x00318724                                                   // df_base + 0x00000024
  #define tx_rx_anytime_ctrl4                            (*(volatile unsigned int *)tx_rx_anytime_ctrl4_adr)
  #define wib_le2m_adv_acs1_adr                          0x00318728                                                   // df_base + 0x00000028
  #define wib_le2m_adv_acs1                              (*(volatile unsigned int *)wib_le2m_adv_acs1_adr)
  #define wib_le2m_adv_acs2_adr                          0x0031872c                                                   // df_base + 0x0000002c
  #define wib_le2m_adv_acs2                              (*(volatile unsigned int *)wib_le2m_adv_acs2_adr)
  #define wib_le2m_data_acs1_adr                         0x00318730                                                   // df_base + 0x00000030
  #define wib_le2m_data_acs1                             (*(volatile unsigned int *)wib_le2m_data_acs1_adr)
  #define wib_le2m_data_acs2_adr                         0x00318734                                                   // df_base + 0x00000034
  #define wib_le2m_data_acs2                             (*(volatile unsigned int *)wib_le2m_data_acs2_adr)
  #define suppress_ctrl_adr                              0x00318738                                                   // df_base + 0x00000038
  #define suppress_ctrl                                  (*(volatile unsigned int *)suppress_ctrl_adr)
  #define suppress_fhout_mask0_adr                       0x0031873c                                                   // df_base + 0x0000003c
  #define suppress_fhout_mask0                           (*(volatile unsigned int *)suppress_fhout_mask0_adr)
  #define suppress_fhout_mask1_adr                       0x00318740                                                   // df_base + 0x00000040
  #define suppress_fhout_mask1                           (*(volatile unsigned int *)suppress_fhout_mask1_adr)
  #define suppress_fhout_mask2_adr                       0x00318744                                                   // df_base + 0x00000044
  #define suppress_fhout_mask2                           (*(volatile unsigned int *)suppress_fhout_mask2_adr)
  #define ninth_grp_1_base                               0x00318800                                                   // bpl_base + 0x00000800
  #define ninth_grp_2_base                               0x00318900                                                   // bpl_base + 0x00000900
  #define afh_mem_start_adr                              0x00318870                                                   // afh_base + 0x00000270
  #define afh_mem_start                                  (*(volatile unsigned int *)afh_mem_start_adr)
  #define afh_mem_end_adr                                0x003189b0                                                   // afh_base + 0x000003b0
  #define afh_mem_end                                    (*(volatile unsigned int *)afh_mem_end_adr)
  #define dc_saved_fhout_adr                             0x003189b4                                                   // afh_base + 0x000003b4
  #define dc_saved_fhout                                 (*(volatile unsigned int *)dc_saved_fhout_adr)
  #define dc_llr_fhs_pyld0_adr                           0x003189b8                                                   // afh_base + 0x000003b8
  #define dc_llr_fhs_pyld0                               (*(volatile unsigned int *)dc_llr_fhs_pyld0_adr)
  #define dc_llr_fhs_pyld1_adr                           0x003189bc                                                   // afh_base + 0x000003bc
  #define dc_llr_fhs_pyld1                               (*(volatile unsigned int *)dc_llr_fhs_pyld1_adr)
  #define dc_llr_fhs_pyld2_adr                           0x003189c0                                                   // afh_base + 0x000003c0
  #define dc_llr_fhs_pyld2                               (*(volatile unsigned int *)dc_llr_fhs_pyld2_adr)
  #define dc_llr_fhs_pyld3_adr                           0x003189c4                                                   // afh_base + 0x000003c4
  #define dc_llr_fhs_pyld3                               (*(volatile unsigned int *)dc_llr_fhs_pyld3_adr)
  #define dc_llr_fhs_pyld4_adr                           0x003189c8                                                   // afh_base + 0x000003c8
  #define dc_llr_fhs_pyld4                               (*(volatile unsigned int *)dc_llr_fhs_pyld4_adr)
  #define dc_llr_bd_adr0                                 0x003189cc                                                   // afh_base + 0x000003cc
  #define dc_llr_bd0                                     (*(volatile unsigned int *)dc_llr_bd_adr0)
  #define dc_llr_bd_adr1                                 0x003189d0                                                   // afh_base + 0x000003d0
  #define dc_llr_bd1                                     (*(volatile unsigned int *)dc_llr_bd_adr1)
  #define rtx_prog_rxdcnt_adr                            0x003189d4                                                   // afh_base + 0x000003d4
  #define rtx_prog_rxdcnt                                (*(volatile unsigned int *)rtx_prog_rxdcnt_adr)
  #define pkt_hdr_soft_dec_adr                           0x003189d8                                                   // afh_base + 0x000003d8
  #define pkt_hdr_soft_dec                               (*(volatile unsigned int *)pkt_hdr_soft_dec_adr)
  #define rxd_pyld_crc_adr                               0x003189dc                                                   // afh_base + 0x000003dc
  #define rxd_pyld_crc                                   (*(volatile unsigned int *)rxd_pyld_crc_adr)
  #define bt_aes_ctrl_adr                                0x003189e0                                                   // afh_base + 0x000003e0
  #define bt_aes_ctrl                                    (*(volatile unsigned int *)bt_aes_ctrl_adr)
  #define bt_aes_tx_pkt_cnt1_adr                         0x003189e4                                                   // afh_base + 0x000003e4
  #define bt_aes_tx_pkt_cnt1                             (*(volatile unsigned int *)bt_aes_tx_pkt_cnt1_adr)
  #define bt_aes_tx_pkt_cnt2_adr                         0x003189e8                                                   // afh_base + 0x000003e8
  #define bt_aes_tx_pkt_cnt2                             (*(volatile unsigned int *)bt_aes_tx_pkt_cnt2_adr)
  #define bt_aes_rx_pkt_cnt1_adr                         0x003189ec                                                   // afh_base + 0x000003ec
  #define bt_aes_rx_pkt_cnt1                             (*(volatile unsigned int *)bt_aes_rx_pkt_cnt1_adr)
  #define bt_aes_rx_pkt_cnt2_adr                         0x003189f0                                                   // afh_base + 0x000003f0
  #define bt_aes_rx_pkt_cnt2                             (*(volatile unsigned int *)bt_aes_rx_pkt_cnt2_adr)
  #define bt_aes_day_cnt_adr                             0x003189f4                                                   // afh_base + 0x000003f4
  #define bt_aes_day_cnt                                 (*(volatile unsigned int *)bt_aes_day_cnt_adr)
  #define bt_aes_esco_btclk_ovr_adr                      0x003189f8                                                   // afh_base + 0x000003f8
  #define bt_aes_esco_btclk_ovr                          (*(volatile unsigned int *)bt_aes_esco_btclk_ovr_adr)
  #define rtx_base                                       0x00318a00                                                   // bpl_base + 0x00000a00
  #define tenth_grp_base                                 0x00318a00                                                   // rtx_base
  #define null_def_adr                                   0x00318a08                                                   // rtx_base + 0x00000008
  #define null_def                                       (*(volatile unsigned int *)null_def_adr)
  #define poll_def_adr                                   0x00318a0c                                                   // rtx_base + 0x0000000c
  #define poll_def                                       (*(volatile unsigned int *)poll_def_adr)
  #define fhs_def_adr                                    0x00318a10                                                   // rtx_base + 0x00000010
  #define fhs_def                                        (*(volatile unsigned int *)fhs_def_adr)
  #define dm1_def_adr                                    0x00318a14                                                   // rtx_base + 0x00000014
  #define dm1_def                                        (*(volatile unsigned int *)dm1_def_adr)
  #define dh1_def_adr                                    0x00318a18                                                   // rtx_base + 0x00000018
  #define dh1_def                                        (*(volatile unsigned int *)dh1_def_adr)
  #define dm3_def_adr                                    0x00318a1c                                                   // rtx_base + 0x0000001c
  #define dm3_def                                        (*(volatile unsigned int *)dm3_def_adr)
  #define dh3_def_adr                                    0x00318a20                                                   // rtx_base + 0x00000020
  #define dh3_def                                        (*(volatile unsigned int *)dh3_def_adr)
  #define dm5_def_adr                                    0x00318a24                                                   // rtx_base + 0x00000024
  #define dm5_def                                        (*(volatile unsigned int *)dm5_def_adr)
  #define dh5_def_adr                                    0x00318a28                                                   // rtx_base + 0x00000028
  #define dh5_def                                        (*(volatile unsigned int *)dh5_def_adr)
  #define dh1_2_def_adr                                  0x00318a2c                                                   // rtx_base + 0x0000002c
  #define dh1_2_def                                      (*(volatile unsigned int *)dh1_2_def_adr)
  #define dh3_2_def_adr                                  0x00318a30                                                   // rtx_base + 0x00000030
  #define dh3_2_def                                      (*(volatile unsigned int *)dh3_2_def_adr)
  #define dh5_2_def_adr                                  0x00318a34                                                   // rtx_base + 0x00000034
  #define dh5_2_def                                      (*(volatile unsigned int *)dh5_2_def_adr)
  #define dh1_3_def_adr                                  0x00318a38                                                   // rtx_base + 0x00000038
  #define dh1_3_def                                      (*(volatile unsigned int *)dh1_3_def_adr)
  #define dh3_3_def_adr                                  0x00318a3c                                                   // rtx_base + 0x0000003c
  #define dh3_3_def                                      (*(volatile unsigned int *)dh3_3_def_adr)
  #define dh5_3_def_adr                                  0x00318a40                                                   // rtx_base + 0x00000040
  #define dh5_3_def                                      (*(volatile unsigned int *)dh5_3_def_adr)
  #define aux1_def_adr                                   0x00318a44                                                   // rtx_base + 0x00000044
  #define aux1_def                                       (*(volatile unsigned int *)aux1_def_adr)
  #define hv1_def_adr                                    0x00318a48                                                   // rtx_base + 0x00000048
  #define hv1_def                                        (*(volatile unsigned int *)hv1_def_adr)
  #define hv2_def_adr                                    0x00318a4c                                                   // rtx_base + 0x0000004c
  #define hv2_def                                        (*(volatile unsigned int *)hv2_def_adr)
  #define hv3_def_adr                                    0x00318a50                                                   // rtx_base + 0x00000050
  #define hv3_def                                        (*(volatile unsigned int *)hv3_def_adr)
  #define ev3_def_adr                                    0x00318a54                                                   // rtx_base + 0x00000054
  #define ev3_def                                        (*(volatile unsigned int *)ev3_def_adr)
  #define ev4_def_adr                                    0x00318a58                                                   // rtx_base + 0x00000058
  #define ev4_def                                        (*(volatile unsigned int *)ev4_def_adr)
  #define ev5_def_adr                                    0x00318a5c                                                   // rtx_base + 0x0000005c
  #define ev5_def                                        (*(volatile unsigned int *)ev5_def_adr)
  #define dv_def_adr                                     0x00318a60                                                   // rtx_base + 0x00000060
  #define dv_def                                         (*(volatile unsigned int *)dv_def_adr)
  #define ev3_2_def_adr                                  0x00318a64                                                   // rtx_base + 0x00000064
  #define ev3_2_def                                      (*(volatile unsigned int *)ev3_2_def_adr)
  #define ev5_2_def_adr                                  0x00318a68                                                   // rtx_base + 0x00000068
  #define ev5_2_def                                      (*(volatile unsigned int *)ev5_2_def_adr)
  #define ev3_3_def_adr                                  0x00318a6c                                                   // rtx_base + 0x0000006c
  #define ev3_3_def                                      (*(volatile unsigned int *)ev3_3_def_adr)
  #define ev5_3_def_adr                                  0x00318a70                                                   // rtx_base + 0x00000070
  #define ev5_3_def                                      (*(volatile unsigned int *)ev5_3_def_adr)
  #define ps_def_adr                                     0x00318a74                                                   // rtx_base + 0x00000074
  #define ps_def                                         (*(volatile unsigned int *)ps_def_adr)
  #define rsv0_def_adr                                   0x00318a78                                                   // rtx_base + 0x00000078
  #define rsv0_def                                       (*(volatile unsigned int *)rsv0_def_adr)
  #define rsv1_def_adr                                   0x00318a7c                                                   // rtx_base + 0x0000007c
  #define rsv1_def                                       (*(volatile unsigned int *)rsv1_def_adr)
  #define pkt_rpl_def_2_adr                              0x00318a80                                                   // rtx_base + 0x00000080
  #define pkt_rpl_def_2                                  (*(volatile unsigned int *)pkt_rpl_def_2_adr)
  #define pkt_rpl_def_3_adr                              0x00318a84                                                   // rtx_base + 0x00000084
  #define pkt_rpl_def_3                                  (*(volatile unsigned int *)pkt_rpl_def_3_adr)
  #define pkt_rpl_def_4_adr                              0x00318a88                                                   // rtx_base + 0x00000088
  #define pkt_rpl_def_4                                  (*(volatile unsigned int *)pkt_rpl_def_4_adr)
  #define pkt_rpl_def_5_adr                              0x00318a8c                                                   // rtx_base + 0x0000008c
  #define pkt_rpl_def_5                                  (*(volatile unsigned int *)pkt_rpl_def_5_adr)
  #define pkt_rpl_def_6_adr                              0x00318a90                                                   // rtx_base + 0x00000090
  #define pkt_rpl_def_6                                  (*(volatile unsigned int *)pkt_rpl_def_6_adr)
  #define pkt_rpl_def_7_adr                              0x00318a94                                                   // rtx_base + 0x00000094
  #define pkt_rpl_def_7                                  (*(volatile unsigned int *)pkt_rpl_def_7_adr)
  #define pkt_rpl_def_8_adr                              0x00318a98                                                   // rtx_base + 0x00000098
  #define pkt_rpl_def_8                                  (*(volatile unsigned int *)pkt_rpl_def_8_adr)
  #define pkt_rpl_def_9_adr                              0x00318a9c                                                   // rtx_base + 0x0000009c
  #define pkt_rpl_def_9                                  (*(volatile unsigned int *)pkt_rpl_def_9_adr)
  #define pkt_rpl_def_10_adr                             0x00318aa0                                                   // rtx_base + 0x000000a0
  #define pkt_rpl_def_10                                 (*(volatile unsigned int *)pkt_rpl_def_10_adr)
  #define pkt_rpl_def_11_adr                             0x00318aa4                                                   // rtx_base + 0x000000a4
  #define pkt_rpl_def_11                                 (*(volatile unsigned int *)pkt_rpl_def_11_adr)
  #define pkt_rpl_def_12_adr                             0x00318aa8                                                   // rtx_base + 0x000000a8
  #define pkt_rpl_def_12                                 (*(volatile unsigned int *)pkt_rpl_def_12_adr)
  #define pkt_rpl_def_13_adr                             0x00318aac                                                   // rtx_base + 0x000000ac
  #define pkt_rpl_def_13                                 (*(volatile unsigned int *)pkt_rpl_def_13_adr)
  #define pkt_rpl_def_14_adr                             0x00318ab0                                                   // rtx_base + 0x000000b0
  #define pkt_rpl_def_14                                 (*(volatile unsigned int *)pkt_rpl_def_14_adr)
  #define pkt_rpl_def_15_adr                             0x00318ab4                                                   // rtx_base + 0x000000b4
  #define pkt_rpl_def_15                                 (*(volatile unsigned int *)pkt_rpl_def_15_adr)
  #define prog_bt_trigger_cfg_adr                        0x00318ab8                                                   // rtx_base + 0x000000b8
  #define prog_bt_trigger_cfg                            (*(volatile unsigned int *)prog_bt_trigger_cfg_adr)
  #define prog_bt_int0_cfg_adr                           0x00318abc                                                   // rtx_base + 0x000000bc
  #define prog_bt_int0_cfg                               (*(volatile unsigned int *)prog_bt_int0_cfg_adr)
  #define prog_bt_int1_cfg_adr                           0x00318ac0                                                   // rtx_base + 0x000000c0
  #define prog_bt_int1_cfg                               (*(volatile unsigned int *)prog_bt_int1_cfg_adr)
  #define prog_bt_int2_cfg_adr                           0x00318ac4                                                   // rtx_base + 0x000000c4
  #define prog_bt_int2_cfg                               (*(volatile unsigned int *)prog_bt_int2_cfg_adr)
  #define prog_bt_int3_cfg_adr                           0x00318ac8                                                   // rtx_base + 0x000000c8
  #define prog_bt_int3_cfg                               (*(volatile unsigned int *)prog_bt_int3_cfg_adr)
  #define tx_pkt_info_adr                                0x00318acc                                                   // rtx_base + 0x000000cc
  #define tx_pkt_info                                    (*(volatile unsigned int *)tx_pkt_info_adr)
  #define tx_pkt_pyld_hdr_adr                            0x00318ad0                                                   // rtx_base + 0x000000d0
  #define tx_pkt_pyld_hdr                                (*(volatile unsigned int *)tx_pkt_pyld_hdr_adr)
  #define tx_fhs_pkt_hdr_adr                             0x00318ad4                                                   // rtx_base + 0x000000d4
  #define tx_fhs_pkt_hdr                                 (*(volatile unsigned int *)tx_fhs_pkt_hdr_adr)
  #define tx_dft_pkt_hdr_adr                             0x00318ad8                                                   // rtx_base + 0x000000d8
  #define tx_dft_pkt_hdr                                 (*(volatile unsigned int *)tx_dft_pkt_hdr_adr)
  #define tx_corrupt_cfg_adr                             0x00318adc                                                   // rtx_base + 0x000000dc
  #define tx_corrupt_cfg                                 (*(volatile unsigned int *)tx_corrupt_cfg_adr)
  #define logical_conn_info_adr                          0x00318ae0                                                   // rtx_base + 0x000000e0
  #define logical_conn_info                              (*(volatile unsigned int *)logical_conn_info_adr)
  #define txd_rxd_sco_length_adr                         0x00318ae4                                                   // rtx_base + 0x000000e4
  #define txd_rxd_sco_length                             (*(volatile unsigned int *)txd_rxd_sco_length_adr)
  #define txd_rxd_ctl_cfg_adr                            0x00318ae8                                                   // rtx_base + 0x000000e8
  #define txd_rxd_ctl_cfg                                (*(volatile unsigned int *)txd_rxd_ctl_cfg_adr)
  #define rxd_chk_notx_fhs_cfg_adr                       0x00318aec                                                   // rtx_base + 0x000000ec
  #define rxd_chk_notx_fhs_cfg                           (*(volatile unsigned int *)rxd_chk_notx_fhs_cfg_adr)
  #define rxd_chk_notx_acl_cfg_adr                       0x00318af0                                                   // rtx_base + 0x000000f0
  #define rxd_chk_notx_acl_cfg                           (*(volatile unsigned int *)rxd_chk_notx_acl_cfg_adr)
  #define rxd_chk_notx_sco_cfg_adr                       0x00318af4                                                   // rtx_base + 0x000000f4
  #define rxd_chk_notx_sco_cfg                           (*(volatile unsigned int *)rxd_chk_notx_sco_cfg_adr)
  #define rxd_hdr_ok_cfg_adr                             0x00318af8                                                   // rtx_base + 0x000000f8
  #define rxd_hdr_ok_cfg                                 (*(volatile unsigned int *)rxd_hdr_ok_cfg_adr)
  #define pkt_rx_1slot_max_cnt_adr                       0x00318afc                                                   // rtx_base + 0x000000fc
  #define pkt_rx_1slot_max_cnt                           (*(volatile unsigned int *)pkt_rx_1slot_max_cnt_adr)
  #define eleventh_grp_base                              0x00318b00                                                   // bpl_base + 0x00000b00
  #define pkt_rx_3slot_max_cnt_adr                       0x00318b00                                                   // rtx_base + 0x00000100
  #define pkt_rx_3slot_max_cnt                           (*(volatile unsigned int *)pkt_rx_3slot_max_cnt_adr)
  #define pkt_rx_5slot_max_cnt_adr                       0x00318b04                                                   // rtx_base + 0x00000104
  #define pkt_rx_5slot_max_cnt                           (*(volatile unsigned int *)pkt_rx_5slot_max_cnt_adr)
  #define multi_s_term_cnt_adr                           0x00318b08                                                   // rtx_base + 0x00000108
  #define multi_s_term_cnt                               (*(volatile unsigned int *)multi_s_term_cnt_adr)
  #define ips_synch_win_adr                              0x00318b0c                                                   // rtx_base + 0x0000010c
  #define ips_synch_win                                  (*(volatile unsigned int *)ips_synch_win_adr)
  #define synch_win_adr                                  0x00318b10                                                   // rtx_base + 0x00000110
  #define synch_win                                      (*(volatile unsigned int *)synch_win_adr)
  #define synch_trigger_offset_adr                       0x00318b14                                                   // rtx_base + 0x00000114
  #define synch_trigger_offset                           (*(volatile unsigned int *)synch_trigger_offset_adr)
  #define wib_wh_list_enh_ctrl_adr                       0x00318b18                                                   // rtx_base + 0x00000118
  #define wib_wh_list_enh_ctrl                           (*(volatile unsigned int *)wib_wh_list_enh_ctrl_adr)
  #define psk_synch_word_lo_adr                          0x00318b1c                                                   // rtx_base + 0x0000011c
  #define psk_synch_word_lo                              (*(volatile unsigned int *)psk_synch_word_lo_adr)
  #define psk_synch_word_hi_adr                          0x00318b20                                                   // rtx_base + 0x00000120
  #define psk_synch_word_hi                              (*(volatile unsigned int *)psk_synch_word_hi_adr)
  #define psk_pyld_mod_cfg_adr                           0x00318b24                                                   // rtx_base + 0x00000124
  #define psk_pyld_mod_cfg                               (*(volatile unsigned int *)psk_pyld_mod_cfg_adr)
  #define pkt_hdr_status_adr                             0x00318b28                                                   // rtx_base + 0x00000128
  #define pkt_hdr_status                                 (*(volatile unsigned int *)pkt_hdr_status_adr)
  #define pkt_log_adr                                    0x00318b2c                                                   // rtx_base + 0x0000012c
  #define pkt_log                                        (*(volatile unsigned int *)pkt_log_adr)
  #define pkt_picky_cnt_th_adr                           0x00318b30                                                   // rtx_base + 0x00000130
  #define pkt_picky_cnt_th                               (*(volatile unsigned int *)pkt_picky_cnt_th_adr)
  #define pyld_picky_err_cnt_adr                         0x00318b34                                                   // rtx_base + 0x00000134
  #define pyld_picky_err_cnt                             (*(volatile unsigned int *)pyld_picky_err_cnt_adr)
  #define wib_wh_list2_lo_adr                            0x00318b38                                                   // rtx_base + 0x00000138
  #define wib_wh_list2_lo                                (*(volatile unsigned int *)wib_wh_list2_lo_adr)
  #define wib_wh_list2_hi_adr                            0x00318b3c                                                   // rtx_base + 0x0000013c
  #define wib_wh_list2_hi                                (*(volatile unsigned int *)wib_wh_list2_hi_adr)
  #define wib_wh_list3_lo_adr                            0x00318b40                                                   // rtx_base + 0x00000140
  #define wib_wh_list3_lo                                (*(volatile unsigned int *)wib_wh_list3_lo_adr)
  #define wib_wh_list3_hi_adr                            0x00318b44                                                   // rtx_base + 0x00000144
  #define wib_wh_list3_hi                                (*(volatile unsigned int *)wib_wh_list3_hi_adr)
  #define wib_wh_list4_lo_adr                            0x00318b48                                                   // rtx_base + 0x00000148
  #define wib_wh_list4_lo                                (*(volatile unsigned int *)wib_wh_list4_lo_adr)
  #define wib_wh_list4_hi_adr                            0x00318b4c                                                   // rtx_base + 0x0000014c
  #define wib_wh_list4_hi                                (*(volatile unsigned int *)wib_wh_list4_hi_adr)
  #define wib_wh_list5_lo_adr                            0x00318b50                                                   // rtx_base + 0x00000150
  #define wib_wh_list5_lo                                (*(volatile unsigned int *)wib_wh_list5_lo_adr)
  #define wib_wh_list5_hi_adr                            0x00318b54                                                   // rtx_base + 0x00000154
  #define wib_wh_list5_hi                                (*(volatile unsigned int *)wib_wh_list5_hi_adr)
  #define wib_wh_list6_lo_adr                            0x00318b58                                                   // rtx_base + 0x00000158
  #define wib_wh_list6_lo                                (*(volatile unsigned int *)wib_wh_list6_lo_adr)
  #define wib_wh_list6_hi_adr                            0x00318b5c                                                   // rtx_base + 0x0000015c
  #define wib_wh_list6_hi                                (*(volatile unsigned int *)wib_wh_list6_hi_adr)
  #define wib_rtx_ctrl2_adr                              0x00318b60                                                   // rtx_base + 0x00000160
  #define wib_rtx_ctrl2                                  (*(volatile unsigned int *)wib_rtx_ctrl2_adr)
  #define prog_wht_seed_eir_adr                          0x00318b64                                                   // rtx_base + 0x00000164
  #define prog_wht_seed_eir                              (*(volatile unsigned int *)prog_wht_seed_eir_adr)
  #define wib_tx_pyld_info_adr                           0x00318b68                                                   // rtx_base + 0x00000168
  #define wib_tx_pyld_info                               (*(volatile unsigned int *)wib_tx_pyld_info_adr)
  #define wib_ctrl_reg_adr                               0x00318b6c                                                   // rtx_base + 0x0000016c
  #define wib_ctrl_reg                                   (*(volatile unsigned int *)wib_ctrl_reg_adr)
  #define wib_access_adr                                 0x00318b70                                                   // rtx_base + 0x00000170
  #define wib_access                                     (*(volatile unsigned int *)wib_access_adr)
  #define wib_advA_lo_adr                                0x00318b74                                                   // rtx_base + 0x00000174
  #define wib_advA_lo                                    (*(volatile unsigned int *)wib_advA_lo_adr)
  #define wib_advA_hi_adr                                0x00318b78                                                   // rtx_base + 0x00000178
  #define wib_advA_hi                                    (*(volatile unsigned int *)wib_advA_hi_adr)
  #define wib_TxA_lo_adr                                 0x00318b7c                                                   // rtx_base + 0x0000017c
  #define wib_TxA_lo                                     (*(volatile unsigned int *)wib_TxA_lo_adr)
  #define wib_TxA_hi_adr                                 0x00318b80                                                   // rtx_base + 0x00000180
  #define wib_TxA_hi                                     (*(volatile unsigned int *)wib_TxA_hi_adr)
  #define wib_InterLat_timer_adr                         0x00318b84                                                   // rtx_base + 0x00000184
  #define wib_InterLat_timer                             (*(volatile unsigned int *)wib_InterLat_timer_adr)
  #define wib_T0_Cnt_adr                                 0x00318b88                                                   // rtx_base + 0x00000188
  #define wib_T0_Cnt                                     (*(volatile unsigned int *)wib_T0_Cnt_adr)
  #define wh_list_mtch_no_clr_adr                        0x00318b8c                                                   // rtx_base + 0x0000018c
  #define wh_list_mtch_no_clr                            (*(volatile unsigned int *)wh_list_mtch_no_clr_adr)
  #define wib_coex_win0_adr                              0x00318b90                                                   // rtx_base + 0x00000190
  #define wib_coex_win0                                  (*(volatile unsigned int *)wib_coex_win0_adr)
  #define wib_coex_win1_adr                              0x00318b94                                                   // rtx_base + 0x00000194
  #define wib_coex_win1                                  (*(volatile unsigned int *)wib_coex_win1_adr)
  #define wib_rx_status_adr                              0x00318b98                                                   // rtx_base + 0x00000198
  #define wib_rx_status                                  (*(volatile unsigned int *)wib_rx_status_adr)
  #define wib_ScanA_lo_adr                               0x00318b9c                                                   // rtx_base + 0x0000019c
  #define wib_ScanA_lo                                   (*(volatile unsigned int *)wib_ScanA_lo_adr)
  #define wib_ScanA_hi_adr                               0x00318ba0                                                   // rtx_base + 0x000001a0
  #define wib_ScanA_hi                                   (*(volatile unsigned int *)wib_ScanA_hi_adr)
  #define wib_conn_lfsr_adr                              0x00318ba4                                                   // rtx_base + 0x000001a4
  #define wib_conn_lfsr                                  (*(volatile unsigned int *)wib_conn_lfsr_adr)
  #define wib_adv_acs_adr                                0x00318ba8                                                   // rtx_base + 0x000001a8
  #define wib_adv_acs                                    (*(volatile unsigned int *)wib_adv_acs_adr)
  #define wib_pkt_log_adr                                0x00318bac                                                   // rtx_base + 0x000001ac
  #define wib_pkt_log                                    (*(volatile unsigned int *)wib_pkt_log_adr)
  #define wib_InitA_lo_adr                               0x00318bb0                                                   // rtx_base + 0x000001b0
  #define wib_InitA_lo                                   (*(volatile unsigned int *)wib_InitA_lo_adr)
  #define wib_InitA_hi_adr                               0x00318bb4                                                   // rtx_base + 0x000001b4
  #define wib_InitA_hi                                   (*(volatile unsigned int *)wib_InitA_hi_adr)
  #define wib_AA_adr                                     0x00318bb8                                                   // rtx_base + 0x000001b8
  #define wib_AA                                         (*(volatile unsigned int *)wib_AA_adr)
  #define wib_pkt_end_max_cnt_adr                        0x00318bbc                                                   // rtx_base + 0x000001bc
  #define wib_pkt_end_max_cnt                            (*(volatile unsigned int *)wib_pkt_end_max_cnt_adr)
  #define wib_rtx_start_adr                              0x00318bc0                                                   // rtx_base + 0x000001c0
  #define wib_rtx_start                                  (*(volatile unsigned int *)wib_rtx_start_adr)
  #define wib_repl_pkt_adr                               0x00318bc4                                                   // rtx_base + 0x000001c4
  #define wib_repl_pkt                                   (*(volatile unsigned int *)wib_repl_pkt_adr)
  #define wib_wh_list1_lo_adr                            0x00318bc8                                                   // rtx_base + 0x000001c8
  #define wib_wh_list1_lo                                (*(volatile unsigned int *)wib_wh_list1_lo_adr)
  #define wib_wh_list1_hi_adr                            0x00318bcc                                                   // rtx_base + 0x000001cc
  #define wib_wh_list1_hi                                (*(volatile unsigned int *)wib_wh_list1_hi_adr)
  #define pkt_rx_max_slot_cnt_1_adr                      0x00318bd0                                                   // rtx_base + 0x000001d0
  #define pkt_rx_max_slot_cnt_1                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_1_adr)
  #define pkt_rx_max_slot_cnt_2_adr                      0x00318bd4                                                   // rtx_base + 0x000001d4
  #define pkt_rx_max_slot_cnt_2                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_2_adr)
  #define pkt_rx_max_slot_cnt_3_adr                      0x00318bd8                                                   // rtx_base + 0x000001d8
  #define pkt_rx_max_slot_cnt_3                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_3_adr)
  #define pkt_rx_max_slot_cnt_4_adr                      0x00318bdc                                                   // rtx_base + 0x000001dc
  #define pkt_rx_max_slot_cnt_4                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_4_adr)
  #define pkt_rx_max_slot_cnt_5_adr                      0x00318be0                                                   // rtx_base + 0x000001e0
  #define pkt_rx_max_slot_cnt_5                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_5_adr)
  #define pkt_rx_max_slot_cnt_6_adr                      0x00318be4                                                   // rtx_base + 0x000001e4
  #define pkt_rx_max_slot_cnt_6                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_6_adr)
  #define pkt_rx_max_slot_cnt_7_adr                      0x00318be8                                                   // rtx_base + 0x000001e8
  #define pkt_rx_max_slot_cnt_7                          (*(volatile unsigned int *)pkt_rx_max_slot_cnt_7_adr)
  #define pkt_rx_max_slot_ctrl_adr                       0x00318bec                                                   // rtx_base + 0x000001ec
  #define pkt_rx_max_slot_ctrl                           (*(volatile unsigned int *)pkt_rx_max_slot_ctrl_adr)
  #define wib_chan_adr                                   0x00318bf0                                                   // rtx_base + 0x000001f0
  #define wib_chan                                       (*(volatile unsigned int *)wib_chan_adr)
  #define wib_seed_adr                                   0x00318bf4                                                   // rtx_base + 0x000001f4
  #define wib_seed                                       (*(volatile unsigned int *)wib_seed_adr)
  #define wib_ses_key0_adr                               0x00318bf8                                                   // rtx_base + 0x000001f8
  #define wib_ses_key0                                   (*(volatile unsigned int *)wib_ses_key0_adr)
  #define wib_ses_key1_adr                               0x00318bfc                                                   // rtx_base + 0x000001fc
  #define wib_ses_key1                                   (*(volatile unsigned int *)wib_ses_key1_adr)
  #define twelfth_grp_base                               0x00318c00                                                   // bpl_base + 0x00000c00
  #define wib_ses_key2_adr                               0x00318c00                                                   // rtx_base + 0x00000200
  #define wib_ses_key2                                   (*(volatile unsigned int *)wib_ses_key2_adr)
  #define wib_ses_key3_adr                               0x00318c04                                                   // rtx_base + 0x00000204
  #define wib_ses_key3                                   (*(volatile unsigned int *)wib_ses_key3_adr)
  #define wib_aes_keyvalid_adr                           0x00318c08                                                   // rtx_base + 0x00000208
  #define wib_aes_keyvalid                               (*(volatile unsigned int *)wib_aes_keyvalid_adr)
  #define wib_ctr0_iv0_adr                               0x00318c0c                                                   // rtx_base + 0x0000020c
  #define wib_ctr0_iv0                                   (*(volatile unsigned int *)wib_ctr0_iv0_adr)
  #define wib_ctr0_iv1_adr                               0x00318c10                                                   // rtx_base + 0x00000210
  #define wib_ctr0_iv1                                   (*(volatile unsigned int *)wib_ctr0_iv1_adr)
  #define wib_ctr0_iv2_adr                               0x00318c14                                                   // rtx_base + 0x00000214
  #define wib_ctr0_iv2                                   (*(volatile unsigned int *)wib_ctr0_iv2_adr)
  #define wib_ctr0_iv3_adr                               0x00318c18                                                   // rtx_base + 0x00000218
  #define wib_ctr0_iv3                                   (*(volatile unsigned int *)wib_ctr0_iv3_adr)
  #define wib_ctr2_iv0_adr                               0x00318c1c                                                   // rtx_base + 0x0000021c
  #define wib_ctr2_iv0                                   (*(volatile unsigned int *)wib_ctr2_iv0_adr)
  #define wib_ctr2_iv1_adr                               0x00318c20                                                   // rtx_base + 0x00000220
  #define wib_ctr2_iv1                                   (*(volatile unsigned int *)wib_ctr2_iv1_adr)
  #define wib_ctr2_iv2_adr                               0x00318c24                                                   // rtx_base + 0x00000224
  #define wib_ctr2_iv2                                   (*(volatile unsigned int *)wib_ctr2_iv2_adr)
  #define wib_ctr2_iv3_adr                               0x00318c28                                                   // rtx_base + 0x00000228
  #define wib_ctr2_iv3                                   (*(volatile unsigned int *)wib_ctr2_iv3_adr)
  #define wib_rdctr0_iv0_adr                             0x00318c2c                                                   // rtx_base + 0x0000022c
  #define wib_rdctr0_iv0                                 (*(volatile unsigned int *)wib_rdctr0_iv0_adr)
  #define wib_rdctr0_iv1_adr                             0x00318c30                                                   // rtx_base + 0x00000230
  #define wib_rdctr0_iv1                                 (*(volatile unsigned int *)wib_rdctr0_iv1_adr)
  #define wib_rdctr0_iv2_adr                             0x00318c34                                                   // rtx_base + 0x00000234
  #define wib_rdctr0_iv2                                 (*(volatile unsigned int *)wib_rdctr0_iv2_adr)
  #define wib_rdctr0_iv3_adr                             0x00318c38                                                   // rtx_base + 0x00000238
  #define wib_rdctr0_iv3                                 (*(volatile unsigned int *)wib_rdctr0_iv3_adr)
  #define wib_aes_status_adr                             0x00318c3c                                                   // rtx_base + 0x0000023c
  #define wib_aes_status                                 (*(volatile unsigned int *)wib_aes_status_adr)
  #define wib_aes2_status_adr                            0x00318c40                                                   // rtx_base + 0x00000240
  #define wib_aes2_status                                (*(volatile unsigned int *)wib_aes2_status_adr)
  #define wib_mic_b0_adr                                 0x00318c44                                                   // rtx_base + 0x00000244
  #define wib_mic_b0                                     (*(volatile unsigned int *)wib_mic_b0_adr)
  #define wib_error_inj_adr                              0x00318c48                                                   // rtx_base + 0x00000248
  #define wib_error_inj                                  (*(volatile unsigned int *)wib_error_inj_adr)
  #define wib_wh_list7_lo_adr                            0x00318c4c                                                   // rtx_base + 0x0000024c
  #define wib_wh_list7_lo                                (*(volatile unsigned int *)wib_wh_list7_lo_adr)
  #define wib_wh_list7_hi_adr                            0x00318c50                                                   // rtx_base + 0x00000250
  #define wib_wh_list7_hi                                (*(volatile unsigned int *)wib_wh_list7_hi_adr)
  #define wib_wh_list8_lo_adr                            0x00318c54                                                   // rtx_base + 0x00000254
  #define wib_wh_list8_lo                                (*(volatile unsigned int *)wib_wh_list8_lo_adr)
  #define wib_wh_list8_hi_adr                            0x00318c58                                                   // rtx_base + 0x00000258
  #define wib_wh_list8_hi                                (*(volatile unsigned int *)wib_wh_list8_hi_adr)
  #define wib_wh_list9_lo_adr                            0x00318c5c                                                   // rtx_base + 0x0000025c
  #define wib_wh_list9_lo                                (*(volatile unsigned int *)wib_wh_list9_lo_adr)
  #define wib_wh_list9_hi_adr                            0x00318c60                                                   // rtx_base + 0x00000260
  #define wib_wh_list9_hi                                (*(volatile unsigned int *)wib_wh_list9_hi_adr)
  #define wib_wh_list10_lo_adr                           0x00318c64                                                   // rtx_base + 0x00000264
  #define wib_wh_list10_lo                               (*(volatile unsigned int *)wib_wh_list10_lo_adr)
  #define wib_wh_list10_hi_adr                           0x00318c68                                                   // rtx_base + 0x00000268
  #define wib_wh_list10_hi                               (*(volatile unsigned int *)wib_wh_list10_hi_adr)
  #define wib_wh_list11_lo_adr                           0x00318c6c                                                   // rtx_base + 0x0000026c
  #define wib_wh_list11_lo                               (*(volatile unsigned int *)wib_wh_list11_lo_adr)
  #define wib_wh_list11_hi_adr                           0x00318c70                                                   // rtx_base + 0x00000270
  #define wib_wh_list11_hi                               (*(volatile unsigned int *)wib_wh_list11_hi_adr)
  #define wib_wh_list12_lo_adr                           0x00318c74                                                   // rtx_base + 0x00000274
  #define wib_wh_list12_lo                               (*(volatile unsigned int *)wib_wh_list12_lo_adr)
  #define wib_wh_list12_hi_adr                           0x00318c78                                                   // rtx_base + 0x00000278
  #define wib_wh_list12_hi                               (*(volatile unsigned int *)wib_wh_list12_hi_adr)
  #define wib_wh_list13_lo_adr                           0x00318c7c                                                   // rtx_base + 0x0000027c
  #define wib_wh_list13_lo                               (*(volatile unsigned int *)wib_wh_list13_lo_adr)
  #define wib_wh_list13_hi_adr                           0x00318c80                                                   // rtx_base + 0x00000280
  #define wib_wh_list13_hi                               (*(volatile unsigned int *)wib_wh_list13_hi_adr)
  #define wib_wh_list14_lo_adr                           0x00318c84                                                   // rtx_base + 0x00000284
  #define wib_wh_list14_lo                               (*(volatile unsigned int *)wib_wh_list14_lo_adr)
  #define wib_wh_list14_hi_adr                           0x00318c88                                                   // rtx_base + 0x00000288
  #define wib_wh_list14_hi                               (*(volatile unsigned int *)wib_wh_list14_hi_adr)
  #define wib_wh_list15_lo_adr                           0x00318c8c                                                   // rtx_base + 0x0000028c
  #define wib_wh_list15_lo                               (*(volatile unsigned int *)wib_wh_list15_lo_adr)
  #define wib_wh_list15_hi_adr                           0x00318c90                                                   // rtx_base + 0x00000290
  #define wib_wh_list15_hi                               (*(volatile unsigned int *)wib_wh_list15_hi_adr)
  #define wib_wh_list16_lo_adr                           0x00318c94                                                   // rtx_base + 0x00000294
  #define wib_wh_list16_lo                               (*(volatile unsigned int *)wib_wh_list16_lo_adr)
  #define wib_wh_list16_hi_adr                           0x00318c98                                                   // rtx_base + 0x00000298
  #define wib_wh_list16_hi                               (*(volatile unsigned int *)wib_wh_list16_hi_adr)
  #define wib_wh_list17_lo_adr                           0x00318c9c                                                   // rtx_base + 0x0000029c
  #define wib_wh_list17_lo                               (*(volatile unsigned int *)wib_wh_list17_lo_adr)
  #define wib_wh_list17_hi_adr                           0x00318ca0                                                   // rtx_base + 0x000002a0
  #define wib_wh_list17_hi                               (*(volatile unsigned int *)wib_wh_list17_hi_adr)
  #define wib_wh_list18_lo_adr                           0x00318ca4                                                   // rtx_base + 0x000002a4
  #define wib_wh_list18_lo                               (*(volatile unsigned int *)wib_wh_list18_lo_adr)
  #define wib_wh_list18_hi_adr                           0x00318ca8                                                   // rtx_base + 0x000002a8
  #define wib_wh_list18_hi                               (*(volatile unsigned int *)wib_wh_list18_hi_adr)
  #define wib_wh_list19_lo_adr                           0x00318cac                                                   // rtx_base + 0x000002ac
  #define wib_wh_list19_lo                               (*(volatile unsigned int *)wib_wh_list19_lo_adr)
  #define wib_wh_list19_hi_adr                           0x00318cb0                                                   // rtx_base + 0x000002b0
  #define wib_wh_list19_hi                               (*(volatile unsigned int *)wib_wh_list19_hi_adr)
  #define wib_wh_list20_lo_adr                           0x00318cb4                                                   // rtx_base + 0x000002b4
  #define wib_wh_list20_lo                               (*(volatile unsigned int *)wib_wh_list20_lo_adr)
  #define wib_wh_list20_hi_adr                           0x00318cb8                                                   // rtx_base + 0x000002b8
  #define wib_wh_list20_hi                               (*(volatile unsigned int *)wib_wh_list20_hi_adr)
  #define wib_wh_list21_lo_adr                           0x00318cbc                                                   // rtx_base + 0x000002bc
  #define wib_wh_list21_lo                               (*(volatile unsigned int *)wib_wh_list21_lo_adr)
  #define wib_wh_list21_hi_adr                           0x00318cc0                                                   // rtx_base + 0x000002c0
  #define wib_wh_list21_hi                               (*(volatile unsigned int *)wib_wh_list21_hi_adr)
  #define wib_wh_list22_lo_adr                           0x00318cc4                                                   // rtx_base + 0x000002c4
  #define wib_wh_list22_lo                               (*(volatile unsigned int *)wib_wh_list22_lo_adr)
  #define wib_wh_list22_hi_adr                           0x00318cc8                                                   // rtx_base + 0x000002c8
  #define wib_wh_list22_hi                               (*(volatile unsigned int *)wib_wh_list22_hi_adr)
  #define wib_wh_list23_lo_adr                           0x00318ccc                                                   // rtx_base + 0x000002cc
  #define wib_wh_list23_lo                               (*(volatile unsigned int *)wib_wh_list23_lo_adr)
  #define wib_wh_list23_hi_adr                           0x00318cd0                                                   // rtx_base + 0x000002d0
  #define wib_wh_list23_hi                               (*(volatile unsigned int *)wib_wh_list23_hi_adr)
  #define wib_wh_list24_lo_adr                           0x00318cd4                                                   // rtx_base + 0x000002d4
  #define wib_wh_list24_lo                               (*(volatile unsigned int *)wib_wh_list24_lo_adr)
  #define wib_wh_list24_hi_adr                           0x00318cd8                                                   // rtx_base + 0x000002d8
  #define wib_wh_list24_hi                               (*(volatile unsigned int *)wib_wh_list24_hi_adr)
  #define wib_wh_list25_lo_adr                           0x00318cdc                                                   // rtx_base + 0x000002dc
  #define wib_wh_list25_lo                               (*(volatile unsigned int *)wib_wh_list25_lo_adr)
  #define wib_wh_list25_hi_adr                           0x00318ce0                                                   // rtx_base + 0x000002e0
  #define wib_wh_list25_hi                               (*(volatile unsigned int *)wib_wh_list25_hi_adr)
  #define wh_list_mtch_no_set1_adr                       0x00318ce4                                                   // rtx_base + 0x000002e4
  #define wh_list_mtch_no_set1                           (*(volatile unsigned int *)wh_list_mtch_no_set1_adr)
  #define wh_list_mtch_no_set2_adr                       0x00318ce8                                                   // rtx_base + 0x000002e8
  #define wh_list_mtch_no_set2                           (*(volatile unsigned int *)wh_list_mtch_no_set2_adr)
  #define wh_list_mtch_no_set3_adr                       0x00318cec                                                   // rtx_base + 0x000002ec
  #define wh_list_mtch_no_set3                           (*(volatile unsigned int *)wh_list_mtch_no_set3_adr)
  #define wh_list_mtch_no_set4_adr                       0x00318cf0                                                   // rtx_base + 0x000002f0
  #define wh_list_mtch_no_set4                           (*(volatile unsigned int *)wh_list_mtch_no_set4_adr)
  #define wh_list_mtch_no_set5_adr                       0x00318cf4                                                   // rtx_base + 0x000002f4
  #define wh_list_mtch_no_set5                           (*(volatile unsigned int *)wh_list_mtch_no_set5_adr)
  #define wh_list_mtch_no_set6_adr                       0x00318cf8                                                   // rtx_base + 0x000002f8
  #define wh_list_mtch_no_set6                           (*(volatile unsigned int *)wh_list_mtch_no_set6_adr)
  #define wh_list_mtch_no_set7_adr                       0x00318cfc                                                   // rtx_base + 0x000002fc
  #define wh_list_mtch_no_set7                           (*(volatile unsigned int *)wh_list_mtch_no_set7_adr)
  #define rtx_mem_start_adr                              0x00370000                                                   // base_rtx_fifo
  #define rtx_mem_start                                  (*(volatile unsigned int *)rtx_mem_start_adr)
  #define rtx_mem_start1_adr                             0x00370400                                                   // base_rtx_fifo + 0x00000400
  #define rtx_mem_start1                                 (*(volatile unsigned int *)rtx_mem_start1_adr)
  #define rtx_mem_start2_adr                             0x00370800                                                   // base_rtx_fifo + 0x00000800
  #define rtx_mem_start2                                 (*(volatile unsigned int *)rtx_mem_start2_adr)
  #define rtx_tx_buffer2_adr                             0x00370900                                                   // rtx_mem_start2_adr + 0x00000100
  #define rtx_tx_buffer2                                 (*(volatile unsigned int *)rtx_tx_buffer2_adr)
  #define rtx_rx_buffer_adr                              0x00370a00                                                   // rtx_mem_start2_adr + 0x00000200
  #define rtx_rx_buffer                                  (*(volatile unsigned int *)rtx_rx_buffer_adr)
  #define rtx_mem_end_adr                                0x00370afc                                                   // base_rtx_fifo + 0x00000afc
  #define rtx_mem_end                                    (*(volatile unsigned int *)rtx_mem_end_adr)
  #define white_list_mem_start_adr                       0x00370b00                                                   // base_rtx_fifo + 0x00000b00
  #define white_list_mem_start                           (*(volatile unsigned int *)white_list_mem_start_adr)
  #define white_list_mem_end_adr                         0x00370f00                                                   // base_rtx_fifo + 0x00000f00
  #define white_list_mem_end                             (*(volatile unsigned int *)white_list_mem_end_adr)
  #define irk_list_mem_start_adr                         0x00371000                                                   // base_rtx_fifo + 0x00001000
  #define irk_list_mem_start                             (*(volatile unsigned int *)irk_list_mem_start_adr)
  #define irk_list_mem_end_adr                           0x00371140                                                   // base_rtx_fifo + 0x00001140
  #define irk_list_mem_end                               (*(volatile unsigned int *)irk_list_mem_end_adr)
  #define apu_base                                       0x00318d00                                                   // rtx_tail + 0x00000004
  #define apu_control_adr                                0x00318d00                                                   // apu_base + 0x00000000
  #define apu_control                                    (*(volatile unsigned int *)apu_control_adr)
  #define apu_mode_adr                                   0x00318d04                                                   // apu_base + 0x00000004
  #define apu_mode                                       (*(volatile unsigned int *)apu_mode_adr)
  #define apu_stuff_length_adr                           0x00318d08                                                   // apu_base + 0x00000008
  #define apu_stuff_length                               (*(volatile unsigned int *)apu_stuff_length_adr)
  #define sco_idx_ptr_adr                                0x00318d0c                                                   // apu_base + 0x0000000c
  #define sco_idx_ptr                                    (*(volatile unsigned int *)sco_idx_ptr_adr)
  #define sco0_rx_decim_adr                              0x00318d10                                                   // apu_base + 0x00000010
  #define sco0_rx_decim                                  (*(volatile unsigned int *)sco0_rx_decim_adr)
  #define sco0_rx_cvsd_adr0                              0x00318d14                                                   // apu_base + 0x00000014
  #define sco0_rx_cvsd0                                  (*(volatile unsigned int *)sco0_rx_cvsd_adr0)
  #define sco0_rx_cvsd_adr1                              0x00318d18                                                   // apu_base + 0x00000018
  #define sco0_rx_cvsd1                                  (*(volatile unsigned int *)sco0_rx_cvsd_adr1)
  #define sco0_tx_intrp_adr                              0x00318d1c                                                   // apu_base + 0x0000001c
  #define sco0_tx_intrp                                  (*(volatile unsigned int *)sco0_tx_intrp_adr)
  #define sco0_tx_cvsd_adr0                              0x00318d20                                                   // apu_base + 0x00000020
  #define sco0_tx_cvsd0                                  (*(volatile unsigned int *)sco0_tx_cvsd_adr0)
  #define sco0_tx_cvsd_adr1                              0x00318d24                                                   // apu_base + 0x00000024
  #define sco0_tx_cvsd1                                  (*(volatile unsigned int *)sco0_tx_cvsd_adr1)
  #define sco1_rx_decim_adr                              0x00318d28                                                   // apu_base + 0x00000028
  #define sco1_rx_decim                                  (*(volatile unsigned int *)sco1_rx_decim_adr)
  #define sco1_rx_cvsd_adr0                              0x00318d2c                                                   // apu_base + 0x0000002c
  #define sco1_rx_cvsd0                                  (*(volatile unsigned int *)sco1_rx_cvsd_adr0)
  #define sco1_rx_cvsd_adr1                              0x00318d30                                                   // apu_base + 0x00000030
  #define sco1_rx_cvsd1                                  (*(volatile unsigned int *)sco1_rx_cvsd_adr1)
  #define sco1_tx_intrp_adr                              0x00318d34                                                   // apu_base + 0x00000034
  #define sco1_tx_intrp                                  (*(volatile unsigned int *)sco1_tx_intrp_adr)
  #define sco1_tx_cvsd_adr0                              0x00318d38                                                   // apu_base + 0x00000038
  #define sco1_tx_cvsd0                                  (*(volatile unsigned int *)sco1_tx_cvsd_adr0)
  #define sco1_tx_cvsd_adr1                              0x00318d3c                                                   // apu_base + 0x0000003c
  #define sco1_tx_cvsd1                                  (*(volatile unsigned int *)sco1_tx_cvsd_adr1)
  #define sco2_rx_decim_adr                              0x00318d40                                                   // apu_base + 0x00000040
  #define sco2_rx_decim                                  (*(volatile unsigned int *)sco2_rx_decim_adr)
  #define sco2_rx_cvsd_adr0                              0x00318d44                                                   // apu_base + 0x00000044
  #define sco2_rx_cvsd0                                  (*(volatile unsigned int *)sco2_rx_cvsd_adr0)
  #define sco2_rx_cvsd_adr1                              0x00318d48                                                   // apu_base + 0x00000048
  #define sco2_rx_cvsd1                                  (*(volatile unsigned int *)sco2_rx_cvsd_adr1)
  #define sco2_tx_intrp_adr                              0x00318d4c                                                   // apu_base + 0x0000004c
  #define sco2_tx_intrp                                  (*(volatile unsigned int *)sco2_tx_intrp_adr)
  #define sco2_tx_cvsd_adr0                              0x00318d50                                                   // apu_base + 0x00000050
  #define sco2_tx_cvsd0                                  (*(volatile unsigned int *)sco2_tx_cvsd_adr0)
  #define sco2_tx_cvsd_adr1                              0x00318d54                                                   // apu_base + 0x00000054
  #define sco2_tx_cvsd1                                  (*(volatile unsigned int *)sco2_tx_cvsd_adr1)
  #define apu_ram_base_adr                               0x00318d58                                                   // apu_base + 0x00000058
  #define apu_ram_base                                   (*(volatile unsigned int *)apu_ram_base_adr)
  #define apu_fifo_base_adr                              0x00318e78                                                   // apu_base + 0x00000178
  #define apu_fifo_base                                  (*(volatile unsigned int *)apu_fifo_base_adr)
  #define apu_fifo_rst_adr                               0x003192b0                                                   // apu_base + 0x000005b0
  #define apu_fifo_rst                                   (*(volatile unsigned int *)apu_fifo_rst_adr)
  #define apu_wlin_stat_adr                              0x003192b4                                                   // apu_base + 0x000005b4
  #define apu_wlin_stat                                  (*(volatile unsigned int *)apu_wlin_stat_adr)
  #define apu_wlin_trig_adr                              0x003192b8                                                   // apu_base + 0x000005b8
  #define apu_wlin_trig                                  (*(volatile unsigned int *)apu_wlin_trig_adr)
  #define plc_base                                       0x00319300                                                   // apu_tail + 0x00000004
  #define plc_enable_adr                                 0x00319300                                                   // plc_base + 0x00000000
  #define plc_enable                                     (*(volatile unsigned int *)plc_enable_adr)
  #define plc_mode_adr                                   0x00319304                                                   // plc_base + 0x00000004
  #define plc_mode                                       (*(volatile unsigned int *)plc_mode_adr)
  #define plc_config_adr                                 0x00319308                                                   // plc_base + 0x00000008
  #define plc_config                                     (*(volatile unsigned int *)plc_config_adr)
  #define plc_data_adr                                   0x0031930c                                                   // plc_base + 0x0000000c
  #define plc_data                                       (*(volatile unsigned int *)plc_data_adr)
  #define plc_status_adr                                 0x00319310                                                   // plc_base + 0x00000010
  #define plc_status                                     (*(volatile unsigned int *)plc_status_adr)
  #define plc_ch_b_base_addr_adr                         0x00319340                                                   // plc_base + 0x00000040
  #define plc_ch_b_base_addr                             (*(volatile unsigned int *)plc_ch_b_base_addr_adr)
  #define nfbc_base                                      0x00319404                                                   // plc_tail + 0x00000004
  #define nfbc_control_adr                               0x00319404                                                   // nfbc_base + 0x00000000
  #define nfbc_control                                   (*(volatile unsigned int *)nfbc_control_adr)
  #define sco0_tx_nfbc_adr0                              0x00319408                                                   // nfbc_base + 0x00000004
  #define sco0_tx_nfbc0                                  (*(volatile unsigned int *)sco0_tx_nfbc_adr0)
  #define sco1_tx_nfbc_adr0                              0x0031940c                                                   // nfbc_base + 0x00000008
  #define sco1_tx_nfbc0                                  (*(volatile unsigned int *)sco1_tx_nfbc_adr0)
  #define sco2_tx_nfbc_adr0                              0x00319410                                                   // nfbc_base + 0x0000000c
  #define sco2_tx_nfbc0                                  (*(volatile unsigned int *)sco2_tx_nfbc_adr0)
  #define sco0_tx_nfbc_adr1                              0x00319414                                                   // nfbc_base + 0x00000010
  #define sco0_tx_nfbc1                                  (*(volatile unsigned int *)sco0_tx_nfbc_adr1)
  #define sco1_tx_nfbc_adr1                              0x00319418                                                   // nfbc_base + 0x00000014
  #define sco1_tx_nfbc1                                  (*(volatile unsigned int *)sco1_tx_nfbc_adr1)
  #define sco2_tx_nfbc_adr1                              0x0031941c                                                   // nfbc_base + 0x00000018
  #define sco2_tx_nfbc1                                  (*(volatile unsigned int *)sco2_tx_nfbc_adr1)
  #define sco0_tx_nfbc_adr2                              0x00319420                                                   // nfbc_base + 0x0000001c
  #define sco0_tx_nfbc2                                  (*(volatile unsigned int *)sco0_tx_nfbc_adr2)
  #define sco1_tx_nfbc_adr2                              0x00319424                                                   // nfbc_base + 0x00000020
  #define sco1_tx_nfbc2                                  (*(volatile unsigned int *)sco1_tx_nfbc_adr2)
  #define sco2_tx_nfbc_adr2                              0x00319428                                                   // nfbc_base + 0x00000024
  #define sco2_tx_nfbc2                                  (*(volatile unsigned int *)sco2_tx_nfbc_adr2)
  #define sri_bk0_offset0_adr                            0x0031e000                                                   // sri_bk_adr_base + 0x00000000
  #define sri_bk0_offset0                                (*(volatile unsigned int *)sri_bk0_offset0_adr)
  #define sri_bk0_offset1_adr                            0x0031e004                                                   // sri_bk_adr_base + 0x00000004
  #define sri_bk0_offset1                                (*(volatile unsigned int *)sri_bk0_offset1_adr)
  #define sri_bk0_offset2_adr                            0x0031e008                                                   // sri_bk_adr_base + 0x00000008
  #define sri_bk0_offset2                                (*(volatile unsigned int *)sri_bk0_offset2_adr)
  #define sri_bk0_offset3_adr                            0x0031e00c                                                   // sri_bk_adr_base + 0x0000000c
  #define sri_bk0_offset3                                (*(volatile unsigned int *)sri_bk0_offset3_adr)
  #define sri_bk0_offset4_adr                            0x0031e010                                                   // sri_bk_adr_base + 0x00000010
  #define sri_bk0_offset4                                (*(volatile unsigned int *)sri_bk0_offset4_adr)
  #define sri_bk0_offset5_adr                            0x0031e014                                                   // sri_bk_adr_base + 0x00000014
  #define sri_bk0_offset5                                (*(volatile unsigned int *)sri_bk0_offset5_adr)
  #define sri_bk1_offset0_adr                            0x0031e020                                                   // sri_bk_adr_base + 0x00000020
  #define sri_bk1_offset0                                (*(volatile unsigned int *)sri_bk1_offset0_adr)
  #define sri_bk1_offset1_adr                            0x0031e024                                                   // sri_bk_adr_base + 0x00000024
  #define sri_bk1_offset1                                (*(volatile unsigned int *)sri_bk1_offset1_adr)
  #define sri_bk1_offset2_adr                            0x0031e028                                                   // sri_bk_adr_base + 0x00000028
  #define sri_bk1_offset2                                (*(volatile unsigned int *)sri_bk1_offset2_adr)
  #define sri_bk1_offset3_adr                            0x0031e02c                                                   // sri_bk_adr_base + 0x0000002c
  #define sri_bk1_offset3                                (*(volatile unsigned int *)sri_bk1_offset3_adr)
  #define sri_bk1_offset4_adr                            0x0031e030                                                   // sri_bk_adr_base + 0x00000030
  #define sri_bk1_offset4                                (*(volatile unsigned int *)sri_bk1_offset4_adr)
  #define sri_bk1_offset5_adr                            0x0031e034                                                   // sri_bk_adr_base + 0x00000034
  #define sri_bk1_offset5                                (*(volatile unsigned int *)sri_bk1_offset5_adr)
  #define sri_bk2_offset0_adr                            0x0031e040                                                   // sri_bk_adr_base + 0x00000040
  #define sri_bk2_offset0                                (*(volatile unsigned int *)sri_bk2_offset0_adr)
  #define sri_bk2_offset1_adr                            0x0031e044                                                   // sri_bk_adr_base + 0x00000044
  #define sri_bk2_offset1                                (*(volatile unsigned int *)sri_bk2_offset1_adr)
  #define sri_bk2_offset2_adr                            0x0031e048                                                   // sri_bk_adr_base + 0x00000048
  #define sri_bk2_offset2                                (*(volatile unsigned int *)sri_bk2_offset2_adr)
  #define sri_bk2_offset3_adr                            0x0031e04c                                                   // sri_bk_adr_base + 0x0000004c
  #define sri_bk2_offset3                                (*(volatile unsigned int *)sri_bk2_offset3_adr)
  #define sri_bk2_offset4_adr                            0x0031e050                                                   // sri_bk_adr_base + 0x00000050
  #define sri_bk2_offset4                                (*(volatile unsigned int *)sri_bk2_offset4_adr)
  #define sri_bk2_offset5_adr                            0x0031e054                                                   // sri_bk_adr_base + 0x00000054
  #define sri_bk2_offset5                                (*(volatile unsigned int *)sri_bk2_offset5_adr)
  #define sri_bk3_offset0_adr                            0x0031e060                                                   // sri_bk_adr_base + 0x00000060
  #define sri_bk3_offset0                                (*(volatile unsigned int *)sri_bk3_offset0_adr)
  #define sri_bk3_offset1_adr                            0x0031e064                                                   // sri_bk_adr_base + 0x00000064
  #define sri_bk3_offset1                                (*(volatile unsigned int *)sri_bk3_offset1_adr)
  #define sri_bk3_offset2_adr                            0x0031e068                                                   // sri_bk_adr_base + 0x00000068
  #define sri_bk3_offset2                                (*(volatile unsigned int *)sri_bk3_offset2_adr)
  #define sri_bk3_offset3_adr                            0x0031e06c                                                   // sri_bk_adr_base + 0x0000006c
  #define sri_bk3_offset3                                (*(volatile unsigned int *)sri_bk3_offset3_adr)
  #define sri_bk3_offset4_adr                            0x0031e070                                                   // sri_bk_adr_base + 0x00000070
  #define sri_bk3_offset4                                (*(volatile unsigned int *)sri_bk3_offset4_adr)
  #define sri_bk3_offset5_adr                            0x0031e074                                                   // sri_bk_adr_base + 0x00000074
  #define sri_bk3_offset5                                (*(volatile unsigned int *)sri_bk3_offset5_adr)
  #define dc_sri_schp0_sel_adr                           0x0031e078                                                   // sri_bk_adr_base + 0x00000078
  #define dc_sri_schp0_sel                               (*(volatile unsigned int *)dc_sri_schp0_sel_adr)
  #define dc_sri_schp1_sel_adr                           0x0031e07c                                                   // sri_bk_adr_base + 0x0000007c
  #define dc_sri_schp1_sel                               (*(volatile unsigned int *)dc_sri_schp1_sel_adr)
  #define dc_sri_schp2_sel_adr                           0x0031e080                                                   // sri_bk_adr_base + 0x00000080
  #define dc_sri_schp2_sel                               (*(volatile unsigned int *)dc_sri_schp2_sel_adr)
  #define dc_sri_schp3_sel_adr                           0x0031e084                                                   // sri_bk_adr_base + 0x00000084
  #define dc_sri_schp3_sel                               (*(volatile unsigned int *)dc_sri_schp3_sel_adr)
  #define bt_sch_hclk_accl_adr                           0x0031e088                                                   // sri_bk_adr_base + 0x00000088
  #define bt_sch_hclk_accl                               (*(volatile unsigned int *)bt_sch_hclk_accl_adr)
  #define sch_start_adr                                  0x0031e800                                                   // sri_bk_adr_base + 0x00000800
  #define sch_start                                      (*(volatile unsigned int *)sch_start_adr)
  #define sch_end_adr                                    0x0031f000                                                   // sri_bk_adr_base + 0x00001000
  #define sch_end                                        (*(volatile unsigned int *)sch_end_adr)
  #define modem_idcode_adr                               0x0031fc04                                                   // modem_adr_base + 0x00000001 * 0x00000004
  #define modem_idcode                                   (*(volatile unsigned int *)modem_idcode_adr)
  #define modem_adr_shifted_base                         0x0031fc08                                                   // modem_idcode_adr + 0x00000001 * 0x00000004
  #define modem_adr_bank1_base                           0x0031fc00                                                   // modem_adr_base
  #define modem_adr_bank2_base                           0x0031fd00                                                   // modem_adr_base + 0x00000100
  #define modem_adr_bank3_base                           0x0031fe00                                                   // modem_adr_base + 0x00000200
  #define modem_adr_bank4_base                           0x0031ff00                                                   // modem_adr_base + 0x00000300
  #define modem_adr_bank5_base                           0x0031f800                                                   // modem_adr_new_base
  #define modem_adr_bank6_base                           0x0031f900                                                   // modem_adr_new_base + 0x00000100
  #define modem_adr_bank7_base                           0x0031fa00                                                   // modem_adr_new_base + 0x00000200
  #define modem_adr_bank8_base                           0x0031fb00                                                   // modem_adr_new_base + 0x00000300
  #define gainLUT0_adr                                   0x0031fc08                                                   // modem_adr_shifted_base + 0x00000000 * 0x00000004
  #define gainLUT0                                       (*(volatile unsigned int *)gainLUT0_adr)
  #define gainLUT1_adr                                   0x0031fc0c                                                   // modem_adr_shifted_base + 0x00000001 * 0x00000004
  #define gainLUT1                                       (*(volatile unsigned int *)gainLUT1_adr)
  #define gainLUT2_adr                                   0x0031fc10                                                   // modem_adr_shifted_base + 0x00000002 * 0x00000004
  #define gainLUT2                                       (*(volatile unsigned int *)gainLUT2_adr)
  #define gainLUT3_adr                                   0x0031fc14                                                   // modem_adr_shifted_base + 0x00000003 * 0x00000004
  #define gainLUT3                                       (*(volatile unsigned int *)gainLUT3_adr)
  #define gainLUT4_adr                                   0x0031fc18                                                   // modem_adr_shifted_base + 0x00000004 * 0x00000004
  #define gainLUT4                                       (*(volatile unsigned int *)gainLUT4_adr)
  #define gainLUT5_adr                                   0x0031fc1c                                                   // modem_adr_shifted_base + 0x00000005 * 0x00000004
  #define gainLUT5                                       (*(volatile unsigned int *)gainLUT5_adr)
  #define gainLUT6_adr                                   0x0031fc20                                                   // modem_adr_shifted_base + 0x00000006 * 0x00000004
  #define gainLUT6                                       (*(volatile unsigned int *)gainLUT6_adr)
  #define gainLUT7_adr                                   0x0031fc24                                                   // modem_adr_shifted_base + 0x00000007 * 0x00000004
  #define gainLUT7                                       (*(volatile unsigned int *)gainLUT7_adr)
  #define gainLUT8_adr                                   0x0031fc28                                                   // modem_adr_shifted_base + 0x00000008 * 0x00000004
  #define gainLUT8                                       (*(volatile unsigned int *)gainLUT8_adr)
  #define agcCtrl0_adr                                   0x0031fc2c                                                   // modem_adr_shifted_base + 0x00000009 * 0x00000004
  #define agcCtrl0                                       (*(volatile unsigned int *)agcCtrl0_adr)
  #define agcCtrl1_adr                                   0x0031fc30                                                   // modem_adr_shifted_base + 0x0000000a * 0x00000004
  #define agcCtrl1                                       (*(volatile unsigned int *)agcCtrl1_adr)
  #define agcStatus_adr                                  0x0031fc34                                                   // modem_adr_shifted_base + 0x0000000b * 0x00000004
  #define agcStatus                                      (*(volatile unsigned int *)agcStatus_adr)
  #define rssiDcStatus_adr                               0x0031fc38                                                   // modem_adr_shifted_base + 0x0000000c * 0x00000004
  #define rssiDcStatus                                   (*(volatile unsigned int *)rssiDcStatus_adr)
  #define squelchCtrl_adr                                0x0031fc3c                                                   // modem_adr_shifted_base + 0x0000000d * 0x00000004
  #define squelchCtrl                                    (*(volatile unsigned int *)squelchCtrl_adr)
  #define rxPskCtrl0_adr                                 0x0031fc40                                                   // modem_adr_shifted_base + 0x0000000e * 0x00000004
  #define rxPskCtrl0                                     (*(volatile unsigned int *)rxPskCtrl0_adr)
  #define rxPskCtrl1_adr                                 0x0031fc44                                                   // modem_adr_shifted_base + 0x0000000f * 0x00000004
  #define rxPskCtrl1                                     (*(volatile unsigned int *)rxPskCtrl1_adr)
  #define dcOffEstCtrl0_adr                              0x0031fc48                                                   // modem_adr_shifted_base + 0x00000010 * 0x00000004
  #define dcOffEstCtrl0                                  (*(volatile unsigned int *)dcOffEstCtrl0_adr)
  #define dcOffEstCtrl1_adr                              0x0031fc4c                                                   // modem_adr_shifted_base + 0x00000011 * 0x00000004
  #define dcOffEstCtrl1                                  (*(volatile unsigned int *)dcOffEstCtrl1_adr)
  #define dcOffEstCtrl2_adr                              0x0031fc50                                                   // modem_adr_shifted_base + 0x00000012 * 0x00000004
  #define dcOffEstCtrl2                                  (*(volatile unsigned int *)dcOffEstCtrl2_adr)
  #define dcOffEstCtrl3_adr                              0x0031fc54                                                   // modem_adr_shifted_base + 0x00000013 * 0x00000004
  #define dcOffEstCtrl3                                  (*(volatile unsigned int *)dcOffEstCtrl3_adr)
  #define dcOffEstCtrl4_adr                              0x0031fc58                                                   // modem_adr_shifted_base + 0x00000014 * 0x00000004
  #define dcOffEstCtrl4                                  (*(volatile unsigned int *)dcOffEstCtrl4_adr)
  #define dcOffEstCtrl5_adr                              0x0031fc5c                                                   // modem_adr_shifted_base + 0x00000015 * 0x00000004
  #define dcOffEstCtrl5                                  (*(volatile unsigned int *)dcOffEstCtrl5_adr)
  #define demodCtrl_adr                                  0x0031fc60                                                   // modem_adr_shifted_base + 0x00000016 * 0x00000004
  #define demodCtrl                                      (*(volatile unsigned int *)demodCtrl_adr)
  #define syncCtrl_adr                                   0x0031fc64                                                   // modem_adr_shifted_base + 0x00000017 * 0x00000004
  #define syncCtrl                                       (*(volatile unsigned int *)syncCtrl_adr)
  #define eqCoeffCtrl0_adr                               0x0031fc68                                                   // modem_adr_shifted_base + 0x00000018 * 0x00000004
  #define eqCoeffCtrl0                                   (*(volatile unsigned int *)eqCoeffCtrl0_adr)
  #define eqCoeffCtrl1_adr                               0x0031fc6c                                                   // modem_adr_shifted_base + 0x00000019 * 0x00000004
  #define eqCoeffCtrl1                                   (*(volatile unsigned int *)eqCoeffCtrl1_adr)
  #define loopCoeffCtrl0_adr                             0x0031fc70                                                   // modem_adr_shifted_base + 0x0000001a * 0x00000004
  #define loopCoeffCtrl0                                 (*(volatile unsigned int *)loopCoeffCtrl0_adr)
  #define loopCoeffCtrl1_adr                             0x0031fc74                                                   // modem_adr_shifted_base + 0x0000001b * 0x00000004
  #define loopCoeffCtrl1                                 (*(volatile unsigned int *)loopCoeffCtrl1_adr)
  #define pskSyncWord0_adr                               0x0031fc78                                                   // modem_adr_shifted_base + 0x0000001c * 0x00000004
  #define pskSyncWord0                                   (*(volatile unsigned int *)pskSyncWord0_adr)
  #define pskSyncWord1_adr                               0x0031fc7c                                                   // modem_adr_shifted_base + 0x0000001d * 0x00000004
  #define pskSyncWord1                                   (*(volatile unsigned int *)pskSyncWord1_adr)
  #define pskSyncWord2_adr                               0x0031fc80                                                   // modem_adr_shifted_base + 0x0000001e * 0x00000004
  #define pskSyncWord2                                   (*(volatile unsigned int *)pskSyncWord2_adr)
  #define adjFcCtrl_adr                                  0x0031fc84                                                   // modem_adr_shifted_base + 0x0000001f * 0x00000004
  #define adjFcCtrl                                      (*(volatile unsigned int *)adjFcCtrl_adr)
  #define ifFreq_adr                                     0x0031fc88                                                   // modem_adr_shifted_base + 0x00000020 * 0x00000004
  #define ifFreq                                         (*(volatile unsigned int *)ifFreq_adr)
  #define dcOffCompQ_adr                                 0x0031fc8c                                                   // modem_adr_shifted_base + 0x00000021 * 0x00000004
  #define dcOffCompQ                                     (*(volatile unsigned int *)dcOffCompQ_adr)
  #define dcOffCompI_adr                                 0x0031fc90                                                   // modem_adr_shifted_base + 0x00000022 * 0x00000004
  #define dcOffCompI                                     (*(volatile unsigned int *)dcOffCompI_adr)
  #define modCtrl0_adr                                   0x0031fc94                                                   // modem_adr_shifted_base + 0x00000023 * 0x00000004
  #define modCtrl0                                       (*(volatile unsigned int *)modCtrl0_adr)
  #define modCtrl1_adr                                   0x0031fc98                                                   // modem_adr_shifted_base + 0x00000024 * 0x00000004
  #define modCtrl1                                       (*(volatile unsigned int *)modCtrl1_adr)
  #define loopCoeffCtrl2_adr                             0x0031fc9c                                                   // modem_adr_shifted_base + 0x00000025 * 0x00000004
  #define loopCoeffCtrl2                                 (*(volatile unsigned int *)loopCoeffCtrl2_adr)
  #define loopCoeffCtrl3_adr                             0x0031fca0                                                   // modem_adr_shifted_base + 0x00000026 * 0x00000004
  #define loopCoeffCtrl3                                 (*(volatile unsigned int *)loopCoeffCtrl3_adr)
  #define txQPskLutCtrl_adr                              0x0031fcac                                                   // modem_adr_shifted_base + 0x00000029 * 0x00000004
  #define txQPskLutCtrl                                  (*(volatile unsigned int *)txQPskLutCtrl_adr)
  #define tx8PskLutCtrl0_adr                             0x0031fcb0                                                   // modem_adr_shifted_base + 0x0000002a * 0x00000004
  #define tx8PskLutCtrl0                                 (*(volatile unsigned int *)tx8PskLutCtrl0_adr)
  #define tx8PskLutCtrl1_adr                             0x0031fcb4                                                   // modem_adr_shifted_base + 0x0000002b * 0x00000004
  #define tx8PskLutCtrl1                                 (*(volatile unsigned int *)tx8PskLutCtrl1_adr)
  #define tssiCtrl_adr                                   0x0031fcb8                                                   // modem_adr_shifted_base + 0x0000002c * 0x00000004
  #define tssiCtrl                                       (*(volatile unsigned int *)tssiCtrl_adr)
  #define tssiStatus_adr                                 0x0031fcbc                                                   // modem_adr_shifted_base + 0x0000002d * 0x00000004
  #define tssiStatus                                     (*(volatile unsigned int *)tssiStatus_adr)
  #define testCtrl_adr                                   0x0031fcc0                                                   // modem_adr_shifted_base + 0x0000002e * 0x00000004
  #define testCtrl                                       (*(volatile unsigned int *)testCtrl_adr)
  #define pa_vctrl_ctrl_adr                              0x0031fcc4                                                   // modem_adr_shifted_base + 0x0000002f * 0x00000004
  #define pa_vctrl_ctrl                                  (*(volatile unsigned int *)pa_vctrl_ctrl_adr)
  #define txPuCtrl_adr                                   0x0031fcc8                                                   // modem_adr_shifted_base + 0x00000030 * 0x00000004
  #define txPuCtrl                                       (*(volatile unsigned int *)txPuCtrl_adr)
  #define rxPuCtrl_adr                                   0x0031fccc                                                   // modem_adr_shifted_base + 0x00000031 * 0x00000004
  #define rxPuCtrl                                       (*(volatile unsigned int *)rxPuCtrl_adr)
  #define synthPuCtrl_adr                                0x0031fcd0                                                   // modem_adr_shifted_base + 0x00000032 * 0x00000004
  #define synthPuCtrl                                    (*(volatile unsigned int *)synthPuCtrl_adr)
  #define paRampCtrl_adr                                 0x0031fcd8                                                   // modem_adr_shifted_base + 0x00000034 * 0x00000004
  #define paRampCtrl                                     (*(volatile unsigned int *)paRampCtrl_adr)
  #define vcoloPuCtrl_adr                                0x0031fcdc                                                   // modem_adr_shifted_base + 0x00000035 * 0x00000004
  #define vcoloPuCtrl                                    (*(volatile unsigned int *)vcoloPuCtrl_adr)
  #define dsadcPuCtrl_adr                                0x0031fce0                                                   // modem_adr_shifted_base + 0x00000036 * 0x00000004
  #define dsadcPuCtrl                                    (*(volatile unsigned int *)dsadcPuCtrl_adr)
  #define trPuCtrl_adr                                   0x0031fce4                                                   // modem_adr_shifted_base + 0x00000037 * 0x00000004
  #define trPuCtrl                                       (*(volatile unsigned int *)trPuCtrl_adr)
  #define tssiPuCtrl_adr                                 0x0031fce8                                                   // modem_adr_shifted_base + 0x00000038 * 0x00000004
  #define tssiPuCtrl                                     (*(volatile unsigned int *)tssiPuCtrl_adr)
  #define clkCtrl_adr                                    0x0031fcf0                                                   // modem_adr_shifted_base + 0x0000003a * 0x00000004
  #define clkCtrl                                        (*(volatile unsigned int *)clkCtrl_adr)
  #define rxPskCtrl2_adr                                 0x0031fcf4                                                   // modem_adr_shifted_base + 0x0000003b * 0x00000004
  #define rxPskCtrl2                                     (*(volatile unsigned int *)rxPskCtrl2_adr)
  #define rxPskCtrl3_adr                                 0x0031fcf8                                                   // modem_adr_shifted_base + 0x0000003c * 0x00000004
  #define rxPskCtrl3                                     (*(volatile unsigned int *)rxPskCtrl3_adr)
  #define rxPskCtrl4_adr                                 0x0031fcfc                                                   // modem_adr_shifted_base + 0x0000003d * 0x00000004
  #define rxPskCtrl4                                     (*(volatile unsigned int *)rxPskCtrl4_adr)
  #define agcCtrl2_adr                                   0x0031fd00                                                   // modem_adr_shifted_base + 0x0000003e * 0x00000004
  #define agcCtrl2                                       (*(volatile unsigned int *)agcCtrl2_adr)
  #define revision_adr                                   0x0031fd04                                                   // modem_adr_shifted_base + 0x0000003f * 0x00000004
  #define revision                                       (*(volatile unsigned int *)revision_adr)
  #define dcOffCompQ1_adr                                0x0031fd08                                                   // modem_adr_shifted_base + 0x00000040 * 0x00000004
  #define dcOffCompQ1                                    (*(volatile unsigned int *)dcOffCompQ1_adr)
  #define dcOffCompI1_adr                                0x0031fd0c                                                   // modem_adr_shifted_base + 0x00000041 * 0x00000004
  #define dcOffCompI1                                    (*(volatile unsigned int *)dcOffCompI1_adr)
  #define dcOffCompQ2_adr                                0x0031fd10                                                   // modem_adr_shifted_base + 0x00000042 * 0x00000004
  #define dcOffCompQ2                                    (*(volatile unsigned int *)dcOffCompQ2_adr)
  #define dcOffCompI2_adr                                0x0031fd14                                                   // modem_adr_shifted_base + 0x00000043 * 0x00000004
  #define dcOffCompI2                                    (*(volatile unsigned int *)dcOffCompI2_adr)
  #define dcOffCompQ3_adr                                0x0031fd18                                                   // modem_adr_shifted_base + 0x00000044 * 0x00000004
  #define dcOffCompQ3                                    (*(volatile unsigned int *)dcOffCompQ3_adr)
  #define dcOffCompI3_adr                                0x0031fd1c                                                   // modem_adr_shifted_base + 0x00000045 * 0x00000004
  #define dcOffCompI3                                    (*(volatile unsigned int *)dcOffCompI3_adr)
  #define dcOffCompQ4_adr                                0x0031fd20                                                   // modem_adr_shifted_base + 0x00000046 * 0x00000004
  #define dcOffCompQ4                                    (*(volatile unsigned int *)dcOffCompQ4_adr)
  #define dcOffCompI4_adr                                0x0031fd24                                                   // modem_adr_shifted_base + 0x00000047 * 0x00000004
  #define dcOffCompI4                                    (*(volatile unsigned int *)dcOffCompI4_adr)
  #define iqComp1_adr                                    0x0031fd28                                                   // modem_adr_shifted_base + 0x00000048 * 0x00000004
  #define iqComp1                                        (*(volatile unsigned int *)iqComp1_adr)
  #define iqComp2_adr                                    0x0031fd2c                                                   // modem_adr_shifted_base + 0x00000049 * 0x00000004
  #define iqComp2                                        (*(volatile unsigned int *)iqComp2_adr)
  #define iqComp3_adr                                    0x0031fd30                                                   // modem_adr_shifted_base + 0x0000004a * 0x00000004
  #define iqComp3                                        (*(volatile unsigned int *)iqComp3_adr)
  #define iqComp4_adr                                    0x0031fd34                                                   // modem_adr_shifted_base + 0x0000004b * 0x00000004
  #define iqComp4                                        (*(volatile unsigned int *)iqComp4_adr)
  #define rxPskPhErr1_adr                                0x0031fd38                                                   // modem_adr_shifted_base + 0x0000004c * 0x00000004
  #define rxPskPhErr1                                    (*(volatile unsigned int *)rxPskPhErr1_adr)
  #define rxPskPhErr2_adr                                0x0031fd3c                                                   // modem_adr_shifted_base + 0x0000004d * 0x00000004
  #define rxPskPhErr2                                    (*(volatile unsigned int *)rxPskPhErr2_adr)
  #define rxPskPhErr3_adr                                0x0031fd40                                                   // modem_adr_shifted_base + 0x0000004e * 0x00000004
  #define rxPskPhErr3                                    (*(volatile unsigned int *)rxPskPhErr3_adr)
  #define rxPskPhErr4_adr                                0x0031fd44                                                   // modem_adr_shifted_base + 0x0000004f * 0x00000004
  #define rxPskPhErr4                                    (*(volatile unsigned int *)rxPskPhErr4_adr)
  #define rxPskPhErr5_adr                                0x0031fd48                                                   // modem_adr_shifted_base + 0x00000050 * 0x00000004
  #define rxPskPhErr5                                    (*(volatile unsigned int *)rxPskPhErr5_adr)
  #define rxPskPhErr6_adr                                0x0031fd4c                                                   // modem_adr_shifted_base + 0x00000051 * 0x00000004
  #define rxPskPhErr6                                    (*(volatile unsigned int *)rxPskPhErr6_adr)
  #define rxPskMagErr_adr                                0x0031fd50                                                   // modem_adr_shifted_base + 0x00000052 * 0x00000004
  #define rxPskMagErr                                    (*(volatile unsigned int *)rxPskMagErr_adr)
  #define slna_gainLUT0_adr                              0x0031fd54                                                   // modem_adr_shifted_base + 0x00000053 * 0x00000004
  #define slna_gainLUT0                                  (*(volatile unsigned int *)slna_gainLUT0_adr)
  #define slna_gainLUT1_adr                              0x0031fd58                                                   // modem_adr_shifted_base + 0x00000054 * 0x00000004
  #define slna_gainLUT1                                  (*(volatile unsigned int *)slna_gainLUT1_adr)
  #define slna_ctrl0_adr                                 0x0031fd5c                                                   // modem_adr_shifted_base + 0x00000055 * 0x00000004
  #define slna_ctrl0                                     (*(volatile unsigned int *)slna_ctrl0_adr)
  #define slna_ctrl1_adr                                 0x0031fd60                                                   // modem_adr_shifted_base + 0x00000056 * 0x00000004
  #define slna_ctrl1                                     (*(volatile unsigned int *)slna_ctrl1_adr)
  #define swp_Startkick_adr                              0x0031fd64                                                   // modem_adr_shifted_base + 0x00000057 * 0x00000004
  #define swp_Startkick                                  (*(volatile unsigned int *)swp_Startkick_adr)
  #define swp_EndInc_adr                                 0x0031fd68                                                   // modem_adr_shifted_base + 0x00000058 * 0x00000004
  #define swp_EndInc                                     (*(volatile unsigned int *)swp_EndInc_adr)
  #define swp_Thresh_adr                                 0x0031fd6c                                                   // modem_adr_shifted_base + 0x00000059 * 0x00000004
  #define swp_Thresh                                     (*(volatile unsigned int *)swp_Thresh_adr)
  #define swp_counter_adr                                0x0031fd70                                                   // modem_adr_shifted_base + 0x0000005a * 0x00000004
  #define swp_counter                                    (*(volatile unsigned int *)swp_counter_adr)
  #define swp_vcoCalCap_adr                              0x0031fd74                                                   // modem_adr_shifted_base + 0x0000005b * 0x00000004
  #define swp_vcoCalCap                                  (*(volatile unsigned int *)swp_vcoCalCap_adr)
  #define swp_threshRssi_adr                             0x0031fd78                                                   // modem_adr_shifted_base + 0x0000005c * 0x00000004
  #define swp_threshRssi                                 (*(volatile unsigned int *)swp_threshRssi_adr)
  #define swp_specVal0_adr                               0x0031fd7c                                                   // modem_adr_shifted_base + 0x0000005d * 0x00000004
  #define swp_specVal0                                   (*(volatile unsigned int *)swp_specVal0_adr)
  #define swp_specVal1_adr                               0x0031fd80                                                   // modem_adr_shifted_base + 0x0000005e * 0x00000004
  #define swp_specVal1                                   (*(volatile unsigned int *)swp_specVal1_adr)
  #define swp_specVal2_adr                               0x0031fd84                                                   // modem_adr_shifted_base + 0x0000005f * 0x00000004
  #define swp_specVal2                                   (*(volatile unsigned int *)swp_specVal2_adr)
  #define swp_specVal3_adr                               0x0031fd88                                                   // modem_adr_shifted_base + 0x00000060 * 0x00000004
  #define swp_specVal3                                   (*(volatile unsigned int *)swp_specVal3_adr)
  #define swp_specVal4_adr                               0x0031fd8c                                                   // modem_adr_shifted_base + 0x00000061 * 0x00000004
  #define swp_specVal4                                   (*(volatile unsigned int *)swp_specVal4_adr)
  #define swp_specVal5_adr                               0x0031fd90                                                   // modem_adr_shifted_base + 0x00000062 * 0x00000004
  #define swp_specVal5                                   (*(volatile unsigned int *)swp_specVal5_adr)
  #define swp_specVal6_adr                               0x0031fd94                                                   // modem_adr_shifted_base + 0x00000063 * 0x00000004
  #define swp_specVal6                                   (*(volatile unsigned int *)swp_specVal6_adr)
  #define swp_specVal7_adr                               0x0031fd98                                                   // modem_adr_shifted_base + 0x00000064 * 0x00000004
  #define swp_specVal7                                   (*(volatile unsigned int *)swp_specVal7_adr)
  #define swp_bitmapCnt_adr                              0x0031fd9c                                                   // modem_adr_shifted_base + 0x00000065 * 0x00000004
  #define swp_bitmapCnt                                  (*(volatile unsigned int *)swp_bitmapCnt_adr)
  #define swp_skipStart_adr                              0x0031fda0                                                   // modem_adr_shifted_base + 0x00000066 * 0x00000004
  #define swp_skipStart                                  (*(volatile unsigned int *)swp_skipStart_adr)
  #define swp_skipEnd_adr                                0x0031fda4                                                   // modem_adr_shifted_base + 0x00000067 * 0x00000004
  #define swp_skipEnd                                    (*(volatile unsigned int *)swp_skipEnd_adr)
  #define swp_Inc_adr                                    0x0031fda8                                                   // modem_adr_shifted_base + 0x00000068 * 0x00000004
  #define swp_Inc                                        (*(volatile unsigned int *)swp_Inc_adr)
  #define swp_skipStart2_adr                             0x0031fdac                                                   // modem_adr_shifted_base + 0x00000069 * 0x00000004
  #define swp_skipStart2                                 (*(volatile unsigned int *)swp_skipStart2_adr)
  #define psk_rssi_adr                                   0x0031fdb0                                                   // modem_adr_shifted_base + 0x0000006a * 0x00000004
  #define psk_rssi                                       (*(volatile unsigned int *)psk_rssi_adr)
  #define psk_acc_cnt_adr                                0x0031fdb4                                                   // modem_adr_shifted_base + 0x0000006b * 0x00000004
  #define psk_acc_cnt                                    (*(volatile unsigned int *)psk_acc_cnt_adr)
  #define ovrsync0_adr                                   0x0031fdb8                                                   // modem_adr_shifted_base + 0x0000006c * 0x00000004
  #define ovrsync0                                       (*(volatile unsigned int *)ovrsync0_adr)
  #define ovrsync1_adr                                   0x0031fdbc                                                   // modem_adr_shifted_base + 0x0000006d * 0x00000004
  #define ovrsync1                                       (*(volatile unsigned int *)ovrsync1_adr)
  #define ovrsync2_adr                                   0x0031fdc0                                                   // modem_adr_shifted_base + 0x0000006e * 0x00000004
  #define ovrsync2                                       (*(volatile unsigned int *)ovrsync2_adr)
  #define ovrsync3_adr                                   0x0031fdc4                                                   // modem_adr_shifted_base + 0x0000006f * 0x00000004
  #define ovrsync3                                       (*(volatile unsigned int *)ovrsync3_adr)
  #define swp_skipEnd2_adr                               0x0031fdc8                                                   // modem_adr_shifted_base + 0x00000070 * 0x00000004
  #define swp_skipEnd2                                   (*(volatile unsigned int *)swp_skipEnd2_adr)
  #define spurCancel_adr                                 0x0031fdcc                                                   // modem_adr_shifted_base + 0x00000071 * 0x00000004
  #define spurCancel                                     (*(volatile unsigned int *)spurCancel_adr)
  #define rssiMinMax_adr                                 0x0031fdd0                                                   // modem_adr_shifted_base + 0x00000072 * 0x00000004
  #define rssiMinMax                                     (*(volatile unsigned int *)rssiMinMax_adr)
  #define swp_pause_adr                                  0x0031fdd4                                                   // modem_adr_shifted_base + 0x00000073 * 0x00000004
  #define swp_pause                                      (*(volatile unsigned int *)swp_pause_adr)
  #define swp_advcds_adr                                 0x0031fdd8                                                   // modem_adr_shifted_base + 0x00000074 * 0x00000004
  #define swp_advcds                                     (*(volatile unsigned int *)swp_advcds_adr)
  #define swp_Maxcalcap_adr                              0x0031fddc                                                   // modem_adr_shifted_base + 0x00000075 * 0x00000004
  #define swp_Maxcalcap                                  (*(volatile unsigned int *)swp_Maxcalcap_adr)
  #define swp_MaxRssi_adr                                0x0031fde0                                                   // modem_adr_shifted_base + 0x00000076 * 0x00000004
  #define swp_MaxRssi                                    (*(volatile unsigned int *)swp_MaxRssi_adr)
  #define btmodem_spare0_adr                             0x0031fde4                                                   // modem_adr_shifted_base + 0x00000077 * 0x00000004
  #define btmodem_spare0                                 (*(volatile unsigned int *)btmodem_spare0_adr)
  #define fskAmp_sel_adr                                 0x0031fde8                                                   // modem_adr_shifted_base + 0x00000078 * 0x00000004
  #define fskAmp_sel                                     (*(volatile unsigned int *)fskAmp_sel_adr)
  #define agcStatus2_adr                                 0x0031fdec                                                   // modem_adr_shifted_base + 0x00000079 * 0x00000004
  #define agcStatus2                                     (*(volatile unsigned int *)agcStatus2_adr)
  #define qpskGain_adr                                   0x0031fdf0                                                   // modem_adr_shifted_base + 0x0000007a * 0x00000004
  #define qpskGain                                       (*(volatile unsigned int *)qpskGain_adr)
  #define agcCtrl3_adr                                   0x0031fdf4                                                   // modem_adr_shifted_base + 0x0000007b * 0x00000004
  #define agcCtrl3                                       (*(volatile unsigned int *)agcCtrl3_adr)
  #define agcCtrl4_adr                                   0x0031fdf8                                                   // modem_adr_shifted_base + 0x0000007c * 0x00000004
  #define agcCtrl4                                       (*(volatile unsigned int *)agcCtrl4_adr)
  #define agcCtrl5_adr                                   0x0031fe08                                                   // modem_adr_shifted_base + 0x00000080 * 0x00000004
  #define agcCtrl5                                       (*(volatile unsigned int *)agcCtrl5_adr)
  #define sri_slave_sel_adr                              0x0031fdfc                                                   // modem_adr_base + 0x000001fc
  #define sri_slave_sel                                  (*(volatile unsigned int *)sri_slave_sel_adr)
  #define txRaFracBase0_adr                              0x0031fe0c                                                   // modem_adr_shifted_base + 0x00000081 * 0x00000004
  #define txRaFracBase0                                  (*(volatile unsigned int *)txRaFracBase0_adr)
  #define txRaFracBase1_adr                              0x0031fe10                                                   // modem_adr_shifted_base + 0x00000082 * 0x00000004
  #define txRaFracBase1                                  (*(volatile unsigned int *)txRaFracBase1_adr)
  #define txRaFracShift0_adr                             0x0031fe14                                                   // modem_adr_shifted_base + 0x00000083 * 0x00000004
  #define txRaFracShift0                                 (*(volatile unsigned int *)txRaFracShift0_adr)
  #define txCtrl0_adr                                    0x0031fe18                                                   // modem_adr_shifted_base + 0x00000084 * 0x00000004
  #define txCtrl0                                        (*(volatile unsigned int *)txCtrl0_adr)
  #define txEquCtrl0_adr                                 0x0031fe1c                                                   // modem_adr_shifted_base + 0x00000085 * 0x00000004
  #define txEquCtrl0                                     (*(volatile unsigned int *)txEquCtrl0_adr)
  #define txEquCtrl1_adr                                 0x0031fe20                                                   // modem_adr_shifted_base + 0x00000086 * 0x00000004
  #define txEquCtrl1                                     (*(volatile unsigned int *)txEquCtrl1_adr)
  #define txEquCtrl2_adr                                 0x0031fe24                                                   // modem_adr_shifted_base + 0x00000087 * 0x00000004
  #define txEquCtrl2                                     (*(volatile unsigned int *)txEquCtrl2_adr)
  #define txEquCtrl3_adr                                 0x0031fe28                                                   // modem_adr_shifted_base + 0x00000088 * 0x00000004
  #define txEquCtrl3                                     (*(volatile unsigned int *)txEquCtrl3_adr)
  #define txEquCtrl4_adr                                 0x0031fe2c                                                   // modem_adr_shifted_base + 0x00000089 * 0x00000004
  #define txEquCtrl4                                     (*(volatile unsigned int *)txEquCtrl4_adr)
  #define rxCordicBaseLo_adr                             0x0031fe30                                                   // modem_adr_shifted_base + 0x0000008a * 0x00000004
  #define rxCordicBaseLo                                 (*(volatile unsigned int *)rxCordicBaseLo_adr)
  #define rxCtrl0_adr                                    0x0031fe34                                                   // modem_adr_shifted_base + 0x0000008b * 0x00000004
  #define rxCtrl0                                        (*(volatile unsigned int *)rxCtrl0_adr)
  #define spurCancelCtrl0_adr                            0x0031fe38                                                   // modem_adr_shifted_base + 0x0000008c * 0x00000004
  #define spurCancelCtrl0                                (*(volatile unsigned int *)spurCancelCtrl0_adr)
  #define spurCancelCtrl1_adr                            0x0031fe3c                                                   // modem_adr_shifted_base + 0x0000008d * 0x00000004
  #define spurCancelCtrl1                                (*(volatile unsigned int *)spurCancelCtrl1_adr)
  #define spurCancelCtrl2_adr                            0x0031fe40                                                   // modem_adr_shifted_base + 0x0000008e * 0x00000004
  #define spurCancelCtrl2                                (*(volatile unsigned int *)spurCancelCtrl2_adr)
  #define spurCancelCtrl3_adr                            0x0031fe44                                                   // modem_adr_shifted_base + 0x0000008f * 0x00000004
  #define spurCancelCtrl3                                (*(volatile unsigned int *)spurCancelCtrl3_adr)
  #define spurCancelCtrl4_adr                            0x0031fe48                                                   // modem_adr_shifted_base + 0x00000090 * 0x00000004
  #define spurCancelCtrl4                                (*(volatile unsigned int *)spurCancelCtrl4_adr)
  #define spurCancelCtrl5_adr                            0x0031fe4c                                                   // modem_adr_shifted_base + 0x00000091 * 0x00000004
  #define spurCancelCtrl5                                (*(volatile unsigned int *)spurCancelCtrl5_adr)
  #define spurCancelCtrl6_adr                            0x0031fe50                                                   // modem_adr_shifted_base + 0x00000092 * 0x00000004
  #define spurCancelCtrl6                                (*(volatile unsigned int *)spurCancelCtrl6_adr)
  #define wrssiStatus_adr                                0x0031fe54                                                   // modem_adr_shifted_base + 0x00000093 * 0x00000004
  #define wrssiStatus                                    (*(volatile unsigned int *)wrssiStatus_adr)
  #define hpfCtrl0_adr                                   0x0031fe58                                                   // modem_adr_shifted_base + 0x00000094 * 0x00000004
  #define hpfCtrl0                                       (*(volatile unsigned int *)hpfCtrl0_adr)
  #define hpfCtrl1_adr                                   0x0031fe5c                                                   // modem_adr_shifted_base + 0x00000095 * 0x00000004
  #define hpfCtrl1                                       (*(volatile unsigned int *)hpfCtrl1_adr)
  #define magEquLow0_adr                                 0x0031fe60                                                   // modem_adr_shifted_base + 0x00000096 * 0x00000004
  #define magEquLow0                                     (*(volatile unsigned int *)magEquLow0_adr)
  #define magEquLow1_adr                                 0x0031fe64                                                   // modem_adr_shifted_base + 0x00000097 * 0x00000004
  #define magEquLow1                                     (*(volatile unsigned int *)magEquLow1_adr)
  #define magEquLow2_adr                                 0x0031fe68                                                   // modem_adr_shifted_base + 0x00000098 * 0x00000004
  #define magEquLow2                                     (*(volatile unsigned int *)magEquLow2_adr)
  #define magEquLow3_adr                                 0x0031fe6c                                                   // modem_adr_shifted_base + 0x00000099 * 0x00000004
  #define magEquLow3                                     (*(volatile unsigned int *)magEquLow3_adr)
  #define magEquLow4_adr                                 0x0031fe70                                                   // modem_adr_shifted_base + 0x0000009a * 0x00000004
  #define magEquLow4                                     (*(volatile unsigned int *)magEquLow4_adr)
  #define magEquLow5_adr                                 0x0031fe74                                                   // modem_adr_shifted_base + 0x0000009b * 0x00000004
  #define magEquLow5                                     (*(volatile unsigned int *)magEquLow5_adr)
  #define magEquLow6_adr                                 0x0031fe78                                                   // modem_adr_shifted_base + 0x0000009c * 0x00000004
  #define magEquLow6                                     (*(volatile unsigned int *)magEquLow6_adr)
  #define magEquLow7_adr                                 0x0031fe7c                                                   // modem_adr_shifted_base + 0x0000009d * 0x00000004
  #define magEquLow7                                     (*(volatile unsigned int *)magEquLow7_adr)
  #define magEquHi0_adr                                  0x0031fe80                                                   // modem_adr_shifted_base + 0x0000009e * 0x00000004
  #define magEquHi0                                      (*(volatile unsigned int *)magEquHi0_adr)
  #define magEquHi1_adr                                  0x0031fe84                                                   // modem_adr_shifted_base + 0x0000009f * 0x00000004
  #define magEquHi1                                      (*(volatile unsigned int *)magEquHi1_adr)
  #define magEquHi2_adr                                  0x0031fe88                                                   // modem_adr_shifted_base + 0x000000a0 * 0x00000004
  #define magEquHi2                                      (*(volatile unsigned int *)magEquHi2_adr)
  #define magEquHi3_adr                                  0x0031fe8c                                                   // modem_adr_shifted_base + 0x000000a1 * 0x00000004
  #define magEquHi3                                      (*(volatile unsigned int *)magEquHi3_adr)
  #define magEquHi4_adr                                  0x0031fe90                                                   // modem_adr_shifted_base + 0x000000a2 * 0x00000004
  #define magEquHi4                                      (*(volatile unsigned int *)magEquHi4_adr)
  #define magEquHi5_adr                                  0x0031fe94                                                   // modem_adr_shifted_base + 0x000000a3 * 0x00000004
  #define magEquHi5                                      (*(volatile unsigned int *)magEquHi5_adr)
  #define magEquHi6_adr                                  0x0031fe98                                                   // modem_adr_shifted_base + 0x000000a4 * 0x00000004
  #define magEquHi6                                      (*(volatile unsigned int *)magEquHi6_adr)
  #define magEquHi7_adr                                  0x0031fe9c                                                   // modem_adr_shifted_base + 0x000000a5 * 0x00000004
  #define magEquHi7                                      (*(volatile unsigned int *)magEquHi7_adr)
  #define gdEquA1_adr                                    0x0031fea0                                                   // modem_adr_shifted_base + 0x000000a6 * 0x00000004
  #define gdEquA1                                        (*(volatile unsigned int *)gdEquA1_adr)
  #define gdEquA2_adr                                    0x0031fea4                                                   // modem_adr_shifted_base + 0x000000a7 * 0x00000004
  #define gdEquA2                                        (*(volatile unsigned int *)gdEquA2_adr)
  #define rxRaFracBase0_adr                              0x0031fea8                                                   // modem_adr_shifted_base + 0x000000a8 * 0x00000004
  #define rxRaFracBase0                                  (*(volatile unsigned int *)rxRaFracBase0_adr)
  #define rxRaFracBase1_adr                              0x0031feac                                                   // modem_adr_shifted_base + 0x000000a9 * 0x00000004
  #define rxRaFracBase1                                  (*(volatile unsigned int *)rxRaFracBase1_adr)
  #define rxRaFracShift0_adr                             0x0031feb0                                                   // modem_adr_shifted_base + 0x000000aa * 0x00000004
  #define rxRaFracShift0                                 (*(volatile unsigned int *)rxRaFracShift0_adr)
  #define rxRaFracShift1_adr                             0x0031feb4                                                   // modem_adr_shifted_base + 0x000000ab * 0x00000004
  #define rxRaFracShift1                                 (*(volatile unsigned int *)rxRaFracShift1_adr)
  #define BistCtrl0_adr                                  0x0031feb8                                                   // modem_adr_shifted_base + 0x000000ac * 0x00000004
  #define BistCtrl0                                      (*(volatile unsigned int *)BistCtrl0_adr)
  #define BistCtrl1_adr                                  0x0031febc                                                   // modem_adr_shifted_base + 0x000000ad * 0x00000004
  #define BistCtrl1                                      (*(volatile unsigned int *)BistCtrl1_adr)
  #define wrssiCtrl0_adr                                 0x0031fec0                                                   // modem_adr_shifted_base + 0x000000ae * 0x00000004
  #define wrssiCtrl0                                     (*(volatile unsigned int *)wrssiCtrl0_adr)
  #define wrssiCtrl1_adr                                 0x0031fec4                                                   // modem_adr_shifted_base + 0x000000af * 0x00000004
  #define wrssiCtrl1                                     (*(volatile unsigned int *)wrssiCtrl1_adr)
  #define wrssiCtrl2_adr                                 0x0031fec8                                                   // modem_adr_shifted_base + 0x000000b0 * 0x00000004
  #define wrssiCtrl2                                     (*(volatile unsigned int *)wrssiCtrl2_adr)
  #define wrssiCtrl3_adr                                 0x0031fecc                                                   // modem_adr_shifted_base + 0x000000b1 * 0x00000004
  #define wrssiCtrl3                                     (*(volatile unsigned int *)wrssiCtrl3_adr)
  #define wrssiCtrl4_adr                                 0x0031fed0                                                   // modem_adr_shifted_base + 0x000000b2 * 0x00000004
  #define wrssiCtrl4                                     (*(volatile unsigned int *)wrssiCtrl4_adr)
  #define wrssiCtrl5_adr                                 0x0031fed4                                                   // modem_adr_shifted_base + 0x000000b3 * 0x00000004
  #define wrssiCtrl5                                     (*(volatile unsigned int *)wrssiCtrl5_adr)
  #define agcCtrl6_adr                                   0x0031fed8                                                   // modem_adr_shifted_base + 0x000000b4 * 0x00000004
  #define agcCtrl6                                       (*(volatile unsigned int *)agcCtrl6_adr)
  #define agcCtrl7_adr                                   0x0031fedc                                                   // modem_adr_shifted_base + 0x000000b5 * 0x00000004
  #define agcCtrl7                                       (*(volatile unsigned int *)agcCtrl7_adr)
  #define agcCtrl8_adr                                   0x0031fee0                                                   // modem_adr_shifted_base + 0x000000b6 * 0x00000004
  #define agcCtrl8                                       (*(volatile unsigned int *)agcCtrl8_adr)
  #define agcCtrl9_adr                                   0x0031fee4                                                   // modem_adr_shifted_base + 0x000000b7 * 0x00000004
  #define agcCtrl9                                       (*(volatile unsigned int *)agcCtrl9_adr)
  #define ma_bec0_adr                                    0x0031fee8                                                   // modem_adr_shifted_base + 0x000000b8 * 0x00000004
  #define ma_bec0                                        (*(volatile unsigned int *)ma_bec0_adr)
  #define ma_bec1_adr                                    0x0031feec                                                   // modem_adr_shifted_base + 0x000000b9 * 0x00000004
  #define ma_bec1                                        (*(volatile unsigned int *)ma_bec1_adr)
  #define ma_bec2_adr                                    0x0031fef0                                                   // modem_adr_shifted_base + 0x000000ba * 0x00000004
  #define ma_bec2                                        (*(volatile unsigned int *)ma_bec2_adr)
  #define bt_agcRamAd_adr                                0x0031fef4                                                   // modem_adr_shifted_base + 0x000000bb * 0x00000004
  #define bt_agcRamAd                                    (*(volatile unsigned int *)bt_agcRamAd_adr)
  #define bt_agcRamBo_adr                                0x0031fef8                                                   // modem_adr_shifted_base + 0x000000bc * 0x00000004
  #define bt_agcRamBo                                    (*(volatile unsigned int *)bt_agcRamBo_adr)
  #define bt_agcRamD_adr                                 0x0031fefc                                                   // modem_adr_shifted_base + 0x000000bd * 0x00000004
  #define bt_agcRamD                                     (*(volatile unsigned int *)bt_agcRamD_adr)
  #define bt_wrssiRamAd_adr                              0x0031ff00                                                   // modem_adr_shifted_base + 0x000000be * 0x00000004
  #define bt_wrssiRamAd                                  (*(volatile unsigned int *)bt_wrssiRamAd_adr)
  #define bt_wrssiRamBo_adr                              0x0031ff04                                                   // modem_adr_shifted_base + 0x000000bf * 0x00000004
  #define bt_wrssiRamBo                                  (*(volatile unsigned int *)bt_wrssiRamBo_adr)
  #define bt_wrssiRamD_adr                               0x0031ff08                                                   // modem_adr_shifted_base + 0x000000c0 * 0x00000004
  #define bt_wrssiRamD                                   (*(volatile unsigned int *)bt_wrssiRamD_adr)
  #define rxCordicBaseHi_adr                             0x0031ff0c                                                   // modem_adr_shifted_base + 0x000000c1 * 0x00000004
  #define rxCordicBaseHi                                 (*(volatile unsigned int *)rxCordicBaseHi_adr)
  #define txDebug_adr                                    0x0031ff10                                                   // modem_adr_shifted_base + 0x000000c2 * 0x00000004
  #define txDebug                                        (*(volatile unsigned int *)txDebug_adr)
  #define bistStatus_adr                                 0x0031ff14                                                   // modem_adr_shifted_base + 0x000000c3 * 0x00000004
  #define bistStatus                                     (*(volatile unsigned int *)bistStatus_adr)
  #define hpfEqSwitch_adr                                0x0031ff18                                                   // modem_adr_shifted_base + 0x000000c4 * 0x00000004
  #define hpfEqSwitch                                    (*(volatile unsigned int *)hpfEqSwitch_adr)
  #define gainOvr0_adr                                   0x0031ff1c                                                   // modem_adr_shifted_base + 0x000000c5 * 0x00000004
  #define gainOvr0                                       (*(volatile unsigned int *)gainOvr0_adr)
  #define gainOvr1_adr                                   0x0031ff20                                                   // modem_adr_shifted_base + 0x000000c6 * 0x00000004
  #define gainOvr1                                       (*(volatile unsigned int *)gainOvr1_adr)
  #define tx_rf_ra_sig_adr                               0x0031ff24                                                   // modem_adr_shifted_base + 0x000000c7 * 0x00000004
  #define tx_rf_ra_sig                                   (*(volatile unsigned int *)tx_rf_ra_sig_adr)
  #define rx_rf_ra_sig_adr                               0x0031ff28                                                   // modem_adr_shifted_base + 0x000000c8 * 0x00000004
  #define rx_rf_ra_sig                                   (*(volatile unsigned int *)rx_rf_ra_sig_adr)
  #define txrx_ra_sig_adr                                0x0031ff2c                                                   // modem_adr_shifted_base + 0x000000c9 * 0x00000004
  #define txrx_ra_sig                                    (*(volatile unsigned int *)txrx_ra_sig_adr)
  #define txrx_ra_buftrk_adr                             0x0031ff30                                                   // modem_adr_shifted_base + 0x000000ca * 0x00000004
  #define txrx_ra_buftrk                                 (*(volatile unsigned int *)txrx_ra_buftrk_adr)
  #define analog_gain_lmt_adr                            0x0031ff34                                                   // modem_adr_shifted_base + 0x000000cb * 0x00000004
  #define analog_gain_lmt                                (*(volatile unsigned int *)analog_gain_lmt_adr)
  #define dig_gain_lmt_adr                               0x0031ff38                                                   // modem_adr_shifted_base + 0x000000cc * 0x00000004
  #define dig_gain_lmt                                   (*(volatile unsigned int *)dig_gain_lmt_adr)
  #define ma_bec3_adr                                    0x0031ff3c                                                   // modem_adr_shifted_base + 0x000000cd * 0x00000004
  #define ma_bec3                                        (*(volatile unsigned int *)ma_bec3_adr)
  #define tx_digGainQ1_adr                               0x0031ff40                                                   // modem_adr_shifted_base + 0x000000ce * 0x00000004
  #define tx_digGainQ1                                   (*(volatile unsigned int *)tx_digGainQ1_adr)
  #define tx_digGainQ2_adr                               0x0031ff44                                                   // modem_adr_shifted_base + 0x000000cf * 0x00000004
  #define tx_digGainQ2                                   (*(volatile unsigned int *)tx_digGainQ2_adr)
  #define tx_digGainQ3_adr                               0x0031ff48                                                   // modem_adr_shifted_base + 0x000000d0 * 0x00000004
  #define tx_digGainQ3                                   (*(volatile unsigned int *)tx_digGainQ3_adr)
  #define tx_digGainQ4_adr                               0x0031ff4c                                                   // modem_adr_shifted_base + 0x000000d1 * 0x00000004
  #define tx_digGainQ4                                   (*(volatile unsigned int *)tx_digGainQ4_adr)
  #define ma_bec4_adr                                    0x0031ff50                                                   // modem_adr_shifted_base + 0x000000d2 * 0x00000004
  #define ma_bec4                                        (*(volatile unsigned int *)ma_bec4_adr)
  #define ma_bec5_adr                                    0x0031ff54                                                   // modem_adr_shifted_base + 0x000000d3 * 0x00000004
  #define ma_bec5                                        (*(volatile unsigned int *)ma_bec5_adr)
  #define bt_agcRam1Ad_adr                               0x0031ff58                                                   // modem_adr_shifted_base + 0x000000d4 * 0x00000004
  #define bt_agcRam1Ad                                   (*(volatile unsigned int *)bt_agcRam1Ad_adr)
  #define bt_agcRam1Bo_adr                               0x0031ff5c                                                   // modem_adr_shifted_base + 0x000000d5 * 0x00000004
  #define bt_agcRam1Bo                                   (*(volatile unsigned int *)bt_agcRam1Bo_adr)
  #define bt_agcRam1D_adr                                0x0031ff60                                                   // modem_adr_shifted_base + 0x000000d6 * 0x00000004
  #define bt_agcRam1D                                    (*(volatile unsigned int *)bt_agcRam1D_adr)
  #define slna_gain0_adr                                 0x0031ff64                                                   // modem_adr_shifted_base + 0x000000d7 * 0x00000004
  #define slna_gain0                                     (*(volatile unsigned int *)slna_gain0_adr)
  #define slna_gain1_adr                                 0x0031ff68                                                   // modem_adr_shifted_base + 0x000000d8 * 0x00000004
  #define slna_gain1                                     (*(volatile unsigned int *)slna_gain1_adr)
  #define slna_gain2_adr                                 0x0031ff6c                                                   // modem_adr_shifted_base + 0x000000d9 * 0x00000004
  #define slna_gain2                                     (*(volatile unsigned int *)slna_gain2_adr)
  #define slna_gain3_adr                                 0x0031ff70                                                   // modem_adr_shifted_base + 0x000000da * 0x00000004
  #define slna_gain3                                     (*(volatile unsigned int *)slna_gain3_adr)
  #define slna_ctrl2_adr                                 0x0031ff74                                                   // modem_adr_shifted_base + 0x000000db * 0x00000004
  #define slna_ctrl2                                     (*(volatile unsigned int *)slna_ctrl2_adr)
  #define gainOvr2_adr                                   0x0031ff78                                                   // modem_adr_shifted_base + 0x000000dc * 0x00000004
  #define gainOvr2                                       (*(volatile unsigned int *)gainOvr2_adr)
  #define condScan_adr                                   0x0031ff80                                                   // modem_adr_shifted_base + 0x000000de * 0x00000004
  #define condScan                                       (*(volatile unsigned int *)condScan_adr)
  #define clippingDet_adr                                0x0031ff84                                                   // modem_adr_shifted_base + 0x000000df * 0x00000004
  #define clippingDet                                    (*(volatile unsigned int *)clippingDet_adr)
  #define spurChSel0_adr                                 0x0031ff88                                                   // modem_adr_shifted_base + 0x000000e0 * 0x00000004
  #define spurChSel0                                     (*(volatile unsigned int *)spurChSel0_adr)
  #define spurChSel1_adr                                 0x0031ff8c                                                   // modem_adr_shifted_base + 0x000000e1 * 0x00000004
  #define spurChSel1                                     (*(volatile unsigned int *)spurChSel1_adr)
  #define rxStatus0_adr                                  0x0031ff98                                                   // modem_adr_shifted_base + 0x000000e4 * 0x00000004
  #define rxStatus0                                      (*(volatile unsigned int *)rxStatus0_adr)
  #define rxRaFrac_adr                                   0x0031ff9c                                                   // modem_adr_shifted_base + 0x000000e5 * 0x00000004
  #define rxRaFrac                                       (*(volatile unsigned int *)rxRaFrac_adr)
  #define rxInitAngle_adr                                0x0031ffa0                                                   // modem_adr_shifted_base + 0x000000e6 * 0x00000004
  #define rxInitAngle                                    (*(volatile unsigned int *)rxInitAngle_adr)
  #define rxBlkRssiTarget_adr                            0x0031ffe4                                                   // modem_adr_shifted_base + 0x000000f7 * 0x00000004
  #define rxBlkRssiTarget                                (*(volatile unsigned int *)rxBlkRssiTarget_adr)
  #define modemSpare0_adr                                0x0031ffe8                                                   // modem_adr_shifted_base + 0x000000f8 * 0x00000004
  #define modemSpare0                                    (*(volatile unsigned int *)modemSpare0_adr)
  #define modemSpare1_adr                                0x0031ffec                                                   // modem_adr_shifted_base + 0x000000f9 * 0x00000004
  #define modemSpare1                                    (*(volatile unsigned int *)modemSpare1_adr)
  #define satDetThresh_adr                               0x0031fff0                                                   // modem_adr_shifted_base + 0x000000fa * 0x00000004
  #define satDetThresh                                   (*(volatile unsigned int *)satDetThresh_adr)
  #define satDetThresh1_adr                              0x0031fff4                                                   // modem_adr_shifted_base + 0x000000fb * 0x00000004
  #define satDetThresh1                                  (*(volatile unsigned int *)satDetThresh1_adr)
  #define satDetTimer_adr                                0x0031fff8                                                   // modem_adr_shifted_base + 0x000000fc * 0x00000004
  #define satDetTimer                                    (*(volatile unsigned int *)satDetTimer_adr)
  #define r_sri_slave_sel_adr                            0x0031fffc                                                   // modem_adr_base + 0x000003fc
  #define r_sri_slave_sel                                (*(volatile unsigned int *)r_sri_slave_sel_adr)
  #define papd_bypass_adr                                0x0031f800                                                   // modem_adr_new_base + 0x00000000 * 0x00000004
  #define papd_bypass                                    (*(volatile unsigned int *)papd_bypass_adr)
  #define papd_delHoldMax_adr                            0x0031f804                                                   // modem_adr_new_base + 0x00000001 * 0x00000004
  #define papd_delHoldMax                                (*(volatile unsigned int *)papd_delHoldMax_adr)
  #define papd_delWait_adr                               0x0031f808                                                   // modem_adr_new_base + 0x00000002 * 0x00000004
  #define papd_delWait                                   (*(volatile unsigned int *)papd_delWait_adr)
  #define papd_delHoldMin_adr                            0x0031f80c                                                   // modem_adr_new_base + 0x00000003 * 0x00000004
  #define papd_delHoldMin                                (*(volatile unsigned int *)papd_delHoldMin_adr)
  #define papd_LutMagIn_0_adr                            0x0031f810                                                   // modem_adr_new_base + 0x00000004 * 0x00000004
  #define papd_LutMagIn_0                                (*(volatile unsigned int *)papd_LutMagIn_0_adr)
  #define papd_LutMagIn_1_adr                            0x0031f814                                                   // modem_adr_new_base + 0x00000005 * 0x00000004
  #define papd_LutMagIn_1                                (*(volatile unsigned int *)papd_LutMagIn_1_adr)
  #define papd_LutMagIn_2_adr                            0x0031f818                                                   // modem_adr_new_base + 0x00000006 * 0x00000004
  #define papd_LutMagIn_2                                (*(volatile unsigned int *)papd_LutMagIn_2_adr)
  #define papd_LutMagIn_3_adr                            0x0031f81c                                                   // modem_adr_new_base + 0x00000007 * 0x00000004
  #define papd_LutMagIn_3                                (*(volatile unsigned int *)papd_LutMagIn_3_adr)
  #define papd_LutMagIn_4_adr                            0x0031f820                                                   // modem_adr_new_base + 0x00000008 * 0x00000004
  #define papd_LutMagIn_4                                (*(volatile unsigned int *)papd_LutMagIn_4_adr)
  #define papd_LutMagIn_5_adr                            0x0031f824                                                   // modem_adr_new_base + 0x00000009 * 0x00000004
  #define papd_LutMagIn_5                                (*(volatile unsigned int *)papd_LutMagIn_5_adr)
  #define papd_LutMagIn_6_adr                            0x0031f828                                                   // modem_adr_new_base + 0x0000000a * 0x00000004
  #define papd_LutMagIn_6                                (*(volatile unsigned int *)papd_LutMagIn_6_adr)
  #define papd_LutMagIn_7_adr                            0x0031f82c                                                   // modem_adr_new_base + 0x0000000b * 0x00000004
  #define papd_LutMagIn_7                                (*(volatile unsigned int *)papd_LutMagIn_7_adr)
  #define papd_LutMagIn_8_adr                            0x0031f830                                                   // modem_adr_new_base + 0x0000000c * 0x00000004
  #define papd_LutMagIn_8                                (*(volatile unsigned int *)papd_LutMagIn_8_adr)
  #define papd_LutMagIn_9_adr                            0x0031f834                                                   // modem_adr_new_base + 0x0000000d * 0x00000004
  #define papd_LutMagIn_9                                (*(volatile unsigned int *)papd_LutMagIn_9_adr)
  #define papd_LutMagIn_10_adr                           0x0031f838                                                   // modem_adr_new_base + 0x0000000e * 0x00000004
  #define papd_LutMagIn_10                               (*(volatile unsigned int *)papd_LutMagIn_10_adr)
  #define papd_LutMagIn_11_adr                           0x0031f83c                                                   // modem_adr_new_base + 0x0000000f * 0x00000004
  #define papd_LutMagIn_11                               (*(volatile unsigned int *)papd_LutMagIn_11_adr)
  #define papd_LutMagIn_12_adr                           0x0031f840                                                   // modem_adr_new_base + 0x00000010 * 0x00000004
  #define papd_LutMagIn_12                               (*(volatile unsigned int *)papd_LutMagIn_12_adr)
  #define papd_LutMagIn_13_adr                           0x0031f844                                                   // modem_adr_new_base + 0x00000011 * 0x00000004
  #define papd_LutMagIn_13                               (*(volatile unsigned int *)papd_LutMagIn_13_adr)
  #define papd_LutMagIn_14_adr                           0x0031f848                                                   // modem_adr_new_base + 0x00000012 * 0x00000004
  #define papd_LutMagIn_14                               (*(volatile unsigned int *)papd_LutMagIn_14_adr)
  #define papd_LutMagIn_15_adr                           0x0031f84c                                                   // modem_adr_new_base + 0x00000013 * 0x00000004
  #define papd_LutMagIn_15                               (*(volatile unsigned int *)papd_LutMagIn_15_adr)
  #define papd_LutMagIn_16_adr                           0x0031f850                                                   // modem_adr_new_base + 0x00000014 * 0x00000004
  #define papd_LutMagIn_16                               (*(volatile unsigned int *)papd_LutMagIn_16_adr)
  #define papd_LutAngIn_0_adr                            0x0031f854                                                   // modem_adr_new_base + 0x00000015 * 0x00000004
  #define papd_LutAngIn_0                                (*(volatile unsigned int *)papd_LutAngIn_0_adr)
  #define papd_LutAngIn_1_adr                            0x0031f858                                                   // modem_adr_new_base + 0x00000016 * 0x00000004
  #define papd_LutAngIn_1                                (*(volatile unsigned int *)papd_LutAngIn_1_adr)
  #define papd_LutAngIn_2_adr                            0x0031f85c                                                   // modem_adr_new_base + 0x00000017 * 0x00000004
  #define papd_LutAngIn_2                                (*(volatile unsigned int *)papd_LutAngIn_2_adr)
  #define papd_LutAngIn_3_adr                            0x0031f860                                                   // modem_adr_new_base + 0x00000018 * 0x00000004
  #define papd_LutAngIn_3                                (*(volatile unsigned int *)papd_LutAngIn_3_adr)
  #define papd_LutAngIn_4_adr                            0x0031f864                                                   // modem_adr_new_base + 0x00000019 * 0x00000004
  #define papd_LutAngIn_4                                (*(volatile unsigned int *)papd_LutAngIn_4_adr)
  #define papd_LutAngIn_5_adr                            0x0031f868                                                   // modem_adr_new_base + 0x0000001a * 0x00000004
  #define papd_LutAngIn_5                                (*(volatile unsigned int *)papd_LutAngIn_5_adr)
  #define papd_LutAngIn_6_adr                            0x0031f86c                                                   // modem_adr_new_base + 0x0000001b * 0x00000004
  #define papd_LutAngIn_6                                (*(volatile unsigned int *)papd_LutAngIn_6_adr)
  #define papd_LutAngIn_7_adr                            0x0031f870                                                   // modem_adr_new_base + 0x0000001c * 0x00000004
  #define papd_LutAngIn_7                                (*(volatile unsigned int *)papd_LutAngIn_7_adr)
  #define papd_LutAngIn_8_adr                            0x0031f874                                                   // modem_adr_new_base + 0x0000001d * 0x00000004
  #define papd_LutAngIn_8                                (*(volatile unsigned int *)papd_LutAngIn_8_adr)
  #define papd_LutAngIn_9_adr                            0x0031f878                                                   // modem_adr_new_base + 0x0000001e * 0x00000004
  #define papd_LutAngIn_9                                (*(volatile unsigned int *)papd_LutAngIn_9_adr)
  #define papd_LutAngIn_10_adr                           0x0031f87c                                                   // modem_adr_new_base + 0x0000001f * 0x00000004
  #define papd_LutAngIn_10                               (*(volatile unsigned int *)papd_LutAngIn_10_adr)
  #define papd_LutAngIn_11_adr                           0x0031f880                                                   // modem_adr_new_base + 0x00000020 * 0x00000004
  #define papd_LutAngIn_11                               (*(volatile unsigned int *)papd_LutAngIn_11_adr)
  #define papd_LutAngIn_12_adr                           0x0031f884                                                   // modem_adr_new_base + 0x00000021 * 0x00000004
  #define papd_LutAngIn_12                               (*(volatile unsigned int *)papd_LutAngIn_12_adr)
  #define papd_LutAngIn_13_adr                           0x0031f888                                                   // modem_adr_new_base + 0x00000022 * 0x00000004
  #define papd_LutAngIn_13                               (*(volatile unsigned int *)papd_LutAngIn_13_adr)
  #define papd_LutAngIn_14_adr                           0x0031f88c                                                   // modem_adr_new_base + 0x00000023 * 0x00000004
  #define papd_LutAngIn_14                               (*(volatile unsigned int *)papd_LutAngIn_14_adr)
  #define papd_LutAngIn_15_adr                           0x0031f890                                                   // modem_adr_new_base + 0x00000024 * 0x00000004
  #define papd_LutAngIn_15                               (*(volatile unsigned int *)papd_LutAngIn_15_adr)
  #define papd_LutAngIn_16_adr                           0x0031f894                                                   // modem_adr_new_base + 0x00000025 * 0x00000004
  #define papd_LutAngIn_16                               (*(volatile unsigned int *)papd_LutAngIn_16_adr)
  #define spurFreq0_adr                                  0x0031f898                                                   // modem_adr_new_base + 0x00000026 * 0x00000004
  #define spurFreq0                                      (*(volatile unsigned int *)spurFreq0_adr)
  #define spurFreqErr0_adr                               0x0031f89c                                                   // modem_adr_new_base + 0x00000027 * 0x00000004
  #define spurFreqErr0                                   (*(volatile unsigned int *)spurFreqErr0_adr)
  #define spurFreq1_adr                                  0x0031f8a0                                                   // modem_adr_new_base + 0x00000028 * 0x00000004
  #define spurFreq1                                      (*(volatile unsigned int *)spurFreq1_adr)
  #define spurFreqErr1_adr                               0x0031f8a4                                                   // modem_adr_new_base + 0x00000029 * 0x00000004
  #define spurFreqErr1                                   (*(volatile unsigned int *)spurFreqErr1_adr)
  #define spurFreq2_adr                                  0x0031f8a8                                                   // modem_adr_new_base + 0x0000002a * 0x00000004
  #define spurFreq2                                      (*(volatile unsigned int *)spurFreq2_adr)
  #define spurFreqErr2_adr                               0x0031f8ac                                                   // modem_adr_new_base + 0x0000002b * 0x00000004
  #define spurFreqErr2                                   (*(volatile unsigned int *)spurFreqErr2_adr)
  #define spurFreq3_adr                                  0x0031f8b0                                                   // modem_adr_new_base + 0x0000002c * 0x00000004
  #define spurFreq3                                      (*(volatile unsigned int *)spurFreq3_adr)
  #define spurFreqErr3_adr                               0x0031f8b4                                                   // modem_adr_new_base + 0x0000002d * 0x00000004
  #define spurFreqErr3                                   (*(volatile unsigned int *)spurFreqErr3_adr)
  #define spurEstCtrl0_adr                               0x0031f8b8                                                   // modem_adr_new_base + 0x0000002e * 0x00000004
  #define spurEstCtrl0                                   (*(volatile unsigned int *)spurEstCtrl0_adr)
  #define spurEstCtrl1_adr                               0x0031f8bc                                                   // modem_adr_new_base + 0x0000002f * 0x00000004
  #define spurEstCtrl1                                   (*(volatile unsigned int *)spurEstCtrl1_adr)
  #define adcCtrl_adr                                    0x0031f8c0                                                   // modem_adr_new_base + 0x00000030 * 0x00000004
  #define adcCtrl                                        (*(volatile unsigned int *)adcCtrl_adr)
  #define ck400PuCtrlRx_adr                              0x0031f8c4                                                   // modem_adr_new_base + 0x00000031 * 0x00000004
  #define ck400PuCtrlRx                                  (*(volatile unsigned int *)ck400PuCtrlRx_adr)
  #define papd_maxCount_adr                              0x0031f8c8                                                   // modem_adr_new_base + 0x00000032 * 0x00000004
  #define papd_maxCount                                  (*(volatile unsigned int *)papd_maxCount_adr)
  #define lna1_gainSet0_adr                              0x0031f8cc                                                   // modem_adr_new_base + 0x00000033 * 0x00000004
  #define lna1_gainSet0                                  (*(volatile unsigned int *)lna1_gainSet0_adr)
  #define lna1_gainSet1_adr                              0x0031f8d0                                                   // modem_adr_new_base + 0x00000034 * 0x00000004
  #define lna1_gainSet1                                  (*(volatile unsigned int *)lna1_gainSet1_adr)
  #define testCtrl2_adr                                  0x0031f8d4                                                   // modem_adr_new_base + 0x00000035 * 0x00000004
  #define testCtrl2                                      (*(volatile unsigned int *)testCtrl2_adr)
  #define slna_gain4_adr                                 0x0031f8d8                                                   // modem_adr_new_base + 0x00000036 * 0x00000004
  #define slna_gain4                                     (*(volatile unsigned int *)slna_gain4_adr)
  #define slna_gain5_adr                                 0x0031f8dc                                                   // modem_adr_new_base + 0x00000037 * 0x00000004
  #define slna_gain5                                     (*(volatile unsigned int *)slna_gain5_adr)
  #define slna_gain6_adr                                 0x0031f8e0                                                   // modem_adr_new_base + 0x00000038 * 0x00000004
  #define slna_gain6                                     (*(volatile unsigned int *)slna_gain6_adr)
  #define slna_gain7_adr                                 0x0031f8e4                                                   // modem_adr_new_base + 0x00000039 * 0x00000004
  #define slna_gain7                                     (*(volatile unsigned int *)slna_gain7_adr)
  #define slna_gain8_adr                                 0x0031f8e8                                                   // modem_adr_new_base + 0x0000003a * 0x00000004
  #define slna_gain8                                     (*(volatile unsigned int *)slna_gain8_adr)
  #define vcoBGPuCtrl_adr                                0x0031f8ec                                                   // modem_adr_new_base + 0x0000003b * 0x00000004
  #define vcoBGPuCtrl                                    (*(volatile unsigned int *)vcoBGPuCtrl_adr)
  #define spurChSel2_adr                                 0x0031f8f0                                                   // modem_adr_new_base + 0x0000003c * 0x00000004
  #define spurChSel2                                     (*(volatile unsigned int *)spurChSel2_adr)
  #define spurChSel3_adr                                 0x0031f8f4                                                   // modem_adr_new_base + 0x0000003d * 0x00000004
  #define spurChSel3                                     (*(volatile unsigned int *)spurChSel3_adr)
  #define spurFreq4_adr                                  0x0031f8f8                                                   // modem_adr_new_base + 0x0000003e * 0x00000004
  #define spurFreq4                                      (*(volatile unsigned int *)spurFreq4_adr)
  #define spurFreqErr4_adr                               0x0031f8fc                                                   // modem_adr_new_base + 0x0000003f * 0x00000004
  #define spurFreqErr4                                   (*(volatile unsigned int *)spurFreqErr4_adr)
  #define spurFreq5_adr                                  0x0031f900                                                   // modem_adr_new_base + 0x00000040 * 0x00000004
  #define spurFreq5                                      (*(volatile unsigned int *)spurFreq5_adr)
  #define spurFreqErr5_adr                               0x0031f904                                                   // modem_adr_new_base + 0x00000041 * 0x00000004
  #define spurFreqErr5                                   (*(volatile unsigned int *)spurFreqErr5_adr)
  #define spurFreq6_adr                                  0x0031f908                                                   // modem_adr_new_base + 0x00000042 * 0x00000004
  #define spurFreq6                                      (*(volatile unsigned int *)spurFreq6_adr)
  #define spurFreqErr6_adr                               0x0031f90c                                                   // modem_adr_new_base + 0x00000043 * 0x00000004
  #define spurFreqErr6                                   (*(volatile unsigned int *)spurFreqErr6_adr)
  #define spurFreq7_adr                                  0x0031f910                                                   // modem_adr_new_base + 0x00000044 * 0x00000004
  #define spurFreq7                                      (*(volatile unsigned int *)spurFreq7_adr)
  #define spurFreqErr7_adr                               0x0031f914                                                   // modem_adr_new_base + 0x00000045 * 0x00000004
  #define spurFreqErr7                                   (*(volatile unsigned int *)spurFreqErr7_adr)
  #define bistStatusMsb_adr                              0x0031f918                                                   // modem_adr_new_base + 0x00000046 * 0x00000004
  #define bistStatusMsb                                  (*(volatile unsigned int *)bistStatusMsb_adr)
  #define maBec_magavg_accum0_adr                        0x0031f91c                                                   // modem_adr_new_base + 0x00000047 * 0x00000004
  #define maBec_magavg_accum0                            (*(volatile unsigned int *)maBec_magavg_accum0_adr)
  #define maBec_magavg_accum1_adr                        0x0031f920                                                   // modem_adr_new_base + 0x00000048 * 0x00000004
  #define maBec_magavg_accum1                            (*(volatile unsigned int *)maBec_magavg_accum1_adr)
  #define maBec_mag2avg_accum0_adr                       0x0031f924                                                   // modem_adr_new_base + 0x00000049 * 0x00000004
  #define maBec_mag2avg_accum0                           (*(volatile unsigned int *)maBec_mag2avg_accum0_adr)
  #define maBec_mag2avg_accum1_adr                       0x0031f928                                                   // modem_adr_new_base + 0x0000004a * 0x00000004
  #define maBec_mag2avg_accum1                           (*(volatile unsigned int *)maBec_mag2avg_accum1_adr)
  #define maBec_symbolCnt_adr                            0x0031f92c                                                   // modem_adr_new_base + 0x0000004b * 0x00000004
  #define maBec_symbolCnt                                (*(volatile unsigned int *)maBec_symbolCnt_adr)
  #define maBec_r_spare_adr                              0x0031f930                                                   // modem_adr_new_base + 0x0000004c * 0x00000004
  #define maBec_r_spare                                  (*(volatile unsigned int *)maBec_r_spare_adr)
  #define maBec_rw_spare_adr                             0x0031f934                                                   // modem_adr_new_base + 0x0000004d * 0x00000004
  #define maBec_rw_spare                                 (*(volatile unsigned int *)maBec_rw_spare_adr)
  #define rxTxCtrl_BLE_adr                               0x0031f938                                                   // modem_adr_new_base + 0x0000004e * 0x00000004
  #define rxTxCtrl_BLE                                   (*(volatile unsigned int *)rxTxCtrl_BLE_adr)
  #define txPuCtrl_BLE_adr                               0x0031f93c                                                   // modem_adr_new_base + 0x0000004f * 0x00000004
  #define txPuCtrl_BLE                                   (*(volatile unsigned int *)txPuCtrl_BLE_adr)
  #define rxPuCtrl_BLE_adr                               0x0031f940                                                   // modem_adr_new_base + 0x00000050 * 0x00000004
  #define rxPuCtrl_BLE                                   (*(volatile unsigned int *)rxPuCtrl_BLE_adr)
  #define synthPuCtrl_BLE_adr                            0x0031f944                                                   // modem_adr_new_base + 0x00000051 * 0x00000004
  #define synthPuCtrl_BLE                                (*(volatile unsigned int *)synthPuCtrl_BLE_adr)
  #define paRampCtrl_BLE_adr                             0x0031f948                                                   // modem_adr_new_base + 0x00000052 * 0x00000004
  #define paRampCtrl_BLE                                 (*(volatile unsigned int *)paRampCtrl_BLE_adr)
  #define vcoloPuCtrl_BLE_adr                            0x0031f94c                                                   // modem_adr_new_base + 0x00000053 * 0x00000004
  #define vcoloPuCtrl_BLE                                (*(volatile unsigned int *)vcoloPuCtrl_BLE_adr)
  #define dsadcPuCtrl_BLE_adr                            0x0031f950                                                   // modem_adr_new_base + 0x00000054 * 0x00000004
  #define dsadcPuCtrl_BLE                                (*(volatile unsigned int *)dsadcPuCtrl_BLE_adr)
  #define trPuCtrl_BLE_adr                               0x0031f954                                                   // modem_adr_new_base + 0x00000055 * 0x00000004
  #define trPuCtrl_BLE                                   (*(volatile unsigned int *)trPuCtrl_BLE_adr)
  #define tssiPuCtrl_BLE_adr                             0x0031f958                                                   // modem_adr_new_base + 0x00000056 * 0x00000004
  #define tssiPuCtrl_BLE                                 (*(volatile unsigned int *)tssiPuCtrl_BLE_adr)
  #define ck400PuCtrlRx_BLE_adr                          0x0031f95c                                                   // modem_adr_new_base + 0x00000057 * 0x00000004
  #define ck400PuCtrlRx_BLE                              (*(volatile unsigned int *)ck400PuCtrlRx_BLE_adr)
  #define vcoBGPuCtrl_BLE_adr                            0x0031f960                                                   // modem_adr_new_base + 0x00000058 * 0x00000004
  #define vcoBGPuCtrl_BLE                                (*(volatile unsigned int *)vcoBGPuCtrl_BLE_adr)
  #define agcPuCtrl_BLE_adr                              0x0031f964                                                   // modem_adr_new_base + 0x00000059 * 0x00000004
  #define agcPuCtrl_BLE                                  (*(volatile unsigned int *)agcPuCtrl_BLE_adr)
  #define syncCtrl_BLE_adr                               0x0031f968                                                   // modem_adr_new_base + 0x0000005a * 0x00000004
  #define syncCtrl_BLE                                   (*(volatile unsigned int *)syncCtrl_BLE_adr)
  #define agcCtrl0_BLE_adr                               0x0031f96c                                                   // modem_adr_new_base + 0x0000005b * 0x00000004
  #define agcCtrl0_BLE                                   (*(volatile unsigned int *)agcCtrl0_BLE_adr)
  #define agcCtrl1_BLE_adr                               0x0031f970                                                   // modem_adr_new_base + 0x0000005c * 0x00000004
  #define agcCtrl1_BLE                                   (*(volatile unsigned int *)agcCtrl1_BLE_adr)
  #define ck400PuCtrlTx_adr                              0x0031f974                                                   // modem_adr_new_base + 0x0000005d * 0x00000004
  #define ck400PuCtrlTx                                  (*(volatile unsigned int *)ck400PuCtrlTx_adr)
  #define ck400PuCtrlTx_BLE_adr                          0x0031f978                                                   // modem_adr_new_base + 0x0000005e * 0x00000004
  #define ck400PuCtrlTx_BLE                              (*(volatile unsigned int *)ck400PuCtrlTx_BLE_adr)
  #define weakSymbThresGFSK_adr                          0x0031f980                                                   // modem_adr_new_base + 0x00000060 * 0x00000004
  #define weakSymbThresGFSK                              (*(volatile unsigned int *)weakSymbThresGFSK_adr)
  #define weakSymbThresDQPSK_adr                         0x0031f984                                                   // modem_adr_new_base + 0x00000061 * 0x00000004
  #define weakSymbThresDQPSK                             (*(volatile unsigned int *)weakSymbThresDQPSK_adr)
  #define weakSymbThresD8PSK_adr                         0x0031f988                                                   // modem_adr_new_base + 0x00000062 * 0x00000004
  #define weakSymbThresD8PSK                             (*(volatile unsigned int *)weakSymbThresD8PSK_adr)
  #define rx_pyld_weak_symbol_rd_idx_adr                 0x0031f98c                                                   // modem_adr_new_base + 0x00000063 * 0x00000004
  #define rx_pyld_weak_symbol_rd_idx                     (*(volatile unsigned int *)rx_pyld_weak_symbol_rd_idx_adr)
  #define rx_pyld_weak_symbol_pos_adr                    0x0031f990                                                   // modem_adr_new_base + 0x00000064 * 0x00000004
  #define rx_pyld_weak_symbol_pos                        (*(volatile unsigned int *)rx_pyld_weak_symbol_pos_adr)
  #define bdrmlse1_adr                                   0x0031fa00                                                   // modem_adr_bank7_base + 0x00000000 * 0x00000004
  #define bdrmlse1                                       (*(volatile unsigned int *)bdrmlse1_adr)
  #define aoaEst_01_adr                                  0x0031fa04                                                   // modem_adr_bank7_base + 0x00000001 * 0x00000004
  #define aoaEst_01                                      (*(volatile unsigned int *)aoaEst_01_adr)
  #define aoaEst_02_adr                                  0x0031fa08                                                   // modem_adr_bank7_base + 0x00000002 * 0x00000004
  #define aoaEst_02                                      (*(volatile unsigned int *)aoaEst_02_adr)
  #define aoaEst_03_adr                                  0x0031fa0c                                                   // modem_adr_bank7_base + 0x00000003 * 0x00000004
  #define aoaEst_03                                      (*(volatile unsigned int *)aoaEst_03_adr)
  #define aoaEst_04_adr                                  0x0031fa10                                                   // modem_adr_bank7_base + 0x00000004 * 0x00000004
  #define aoaEst_04                                      (*(volatile unsigned int *)aoaEst_04_adr)
  #define aoaEst_05_adr                                  0x0031fa14                                                   // modem_adr_bank7_base + 0x00000005 * 0x00000004
  #define aoaEst_05                                      (*(volatile unsigned int *)aoaEst_05_adr)
  #define aoaEst_06_adr                                  0x0031fa18                                                   // modem_adr_bank7_base + 0x00000006 * 0x00000004
  #define aoaEst_06                                      (*(volatile unsigned int *)aoaEst_06_adr)
  #define aoaEst_07_adr                                  0x0031fa1c                                                   // modem_adr_bank7_base + 0x00000007 * 0x00000004
  #define aoaEst_07                                      (*(volatile unsigned int *)aoaEst_07_adr)
  #define aoaEst_08_adr                                  0x0031fa20                                                   // modem_adr_bank7_base + 0x00000008 * 0x00000004
  #define aoaEst_08                                      (*(volatile unsigned int *)aoaEst_08_adr)
  #define aoaEst_09_adr                                  0x0031fa24                                                   // modem_adr_bank7_base + 0x00000009 * 0x00000004
  #define aoaEst_09                                      (*(volatile unsigned int *)aoaEst_09_adr)
  #define aoaEst_0a_adr                                  0x0031fa28                                                   // modem_adr_bank7_base + 0x0000000a * 0x00000004
  #define aoaEst_0a                                      (*(volatile unsigned int *)aoaEst_0a_adr)
  #define aoaEst_0b_adr                                  0x0031fa2c                                                   // modem_adr_bank7_base + 0x0000000b * 0x00000004
  #define aoaEst_0b                                      (*(volatile unsigned int *)aoaEst_0b_adr)
  #define aoaEst_0c_adr                                  0x0031fa30                                                   // modem_adr_bank7_base + 0x0000000c * 0x00000004
  #define aoaEst_0c                                      (*(volatile unsigned int *)aoaEst_0c_adr)
  #define aoaEst_0d_adr                                  0x0031fa34                                                   // modem_adr_bank7_base + 0x0000000d * 0x00000004
  #define aoaEst_0d                                      (*(volatile unsigned int *)aoaEst_0d_adr)
  #define aoaEst_0e_adr                                  0x0031fa38                                                   // modem_adr_bank7_base + 0x0000000e * 0x00000004
  #define aoaEst_0e                                      (*(volatile unsigned int *)aoaEst_0e_adr)
  #define aoaEst_0f_adr                                  0x0031fa3c                                                   // modem_adr_bank7_base + 0x0000000f * 0x00000004
  #define aoaEst_0f                                      (*(volatile unsigned int *)aoaEst_0f_adr)
  #define aoaEst_10_adr                                  0x0031fa40                                                   // modem_adr_bank7_base + 0x00000010 * 0x00000004
  #define aoaEst_10                                      (*(volatile unsigned int *)aoaEst_10_adr)
  #define aoaEst_11_adr                                  0x0031fa44                                                   // modem_adr_bank7_base + 0x00000011 * 0x00000004
  #define aoaEst_11                                      (*(volatile unsigned int *)aoaEst_11_adr)
  #define aoaEst_12_adr                                  0x0031fa48                                                   // modem_adr_bank7_base + 0x00000012 * 0x00000004
  #define aoaEst_12                                      (*(volatile unsigned int *)aoaEst_12_adr)
  #define aoaEst_13_adr                                  0x0031fa4c                                                   // modem_adr_bank7_base + 0x00000013 * 0x00000004
  #define aoaEst_13                                      (*(volatile unsigned int *)aoaEst_13_adr)
  #define aoaEst_14_adr                                  0x0031fa50                                                   // modem_adr_bank7_base + 0x00000014 * 0x00000004
  #define aoaEst_14                                      (*(volatile unsigned int *)aoaEst_14_adr)
  #define aoaEst_15_adr                                  0x0031fa54                                                   // modem_adr_bank7_base + 0x00000015 * 0x00000004
  #define aoaEst_15                                      (*(volatile unsigned int *)aoaEst_15_adr)
  #define aoaEst_16_adr                                  0x0031fa58                                                   // modem_adr_bank7_base + 0x00000016 * 0x00000004
  #define aoaEst_16                                      (*(volatile unsigned int *)aoaEst_16_adr)
  #define aoaEst_17_adr                                  0x0031fa5c                                                   // modem_adr_bank7_base + 0x00000017 * 0x00000004
  #define aoaEst_17                                      (*(volatile unsigned int *)aoaEst_17_adr)
  #define bdrmlse2_adr                                   0x0031fa60                                                   // modem_adr_bank7_base + 0x00000018 * 0x00000004
  #define bdrmlse2                                       (*(volatile unsigned int *)bdrmlse2_adr)
  #define bdrmlse3_adr                                   0x0031fa64                                                   // modem_adr_bank7_base + 0x00000019 * 0x00000004
  #define bdrmlse3                                       (*(volatile unsigned int *)bdrmlse3_adr)
  #define bdrmlse4_adr                                   0x0031fa68                                                   // modem_adr_bank7_base + 0x0000001a * 0x00000004
  #define bdrmlse4                                       (*(volatile unsigned int *)bdrmlse4_adr)
  #define modIndEst1_adr                                 0x0031fa6c                                                   // modem_adr_bank7_base + 0x0000001b * 0x00000004
  #define modIndEst1                                     (*(volatile unsigned int *)modIndEst1_adr)
  #define modIndEst2_adr                                 0x0031fa70                                                   // modem_adr_bank7_base + 0x0000001c * 0x00000004
  #define modIndEst2                                     (*(volatile unsigned int *)modIndEst2_adr)
  #define modIndEst3_adr                                 0x0031fa74                                                   // modem_adr_bank7_base + 0x0000001d * 0x00000004
  #define modIndEst3                                     (*(volatile unsigned int *)modIndEst3_adr)
  #define modIndEst4_adr                                 0x0031fa78                                                   // modem_adr_bank7_base + 0x0000001e * 0x00000004
  #define modIndEst4                                     (*(volatile unsigned int *)modIndEst4_adr)
  #define modIndEst5_adr                                 0x0031fa7c                                                   // modem_adr_bank7_base + 0x0000001f * 0x00000004
  #define modIndEst5                                     (*(volatile unsigned int *)modIndEst5_adr)
  #define modIndEst6_adr                                 0x0031fa80                                                   // modem_adr_bank7_base + 0x00000020 * 0x00000004
  #define modIndEst6                                     (*(volatile unsigned int *)modIndEst6_adr)
  #define modIndEst7_adr                                 0x0031fa84                                                   // modem_adr_bank7_base + 0x00000021 * 0x00000004
  #define modIndEst7                                     (*(volatile unsigned int *)modIndEst7_adr)
  #define modIndEst8_adr                                 0x0031fa88                                                   // modem_adr_bank7_base + 0x00000022 * 0x00000004
  #define modIndEst8                                     (*(volatile unsigned int *)modIndEst8_adr)
  #define modIndEst9_adr                                 0x0031fa8c                                                   // modem_adr_bank7_base + 0x00000023 * 0x00000004
  #define modIndEst9                                     (*(volatile unsigned int *)modIndEst9_adr)
  #define modIndEstRead1_adr                             0x0031fa90                                                   // modem_adr_bank7_base + 0x00000024 * 0x00000004
  #define modIndEstRead1                                 (*(volatile unsigned int *)modIndEstRead1_adr)
  #define modIndEstRead2_adr                             0x0031fa94                                                   // modem_adr_bank7_base + 0x00000025 * 0x00000004
  #define modIndEstRead2                                 (*(volatile unsigned int *)modIndEstRead2_adr)
  #define modIndEstRead3_adr                             0x0031fa98                                                   // modem_adr_bank7_base + 0x00000026 * 0x00000004
  #define modIndEstRead3                                 (*(volatile unsigned int *)modIndEstRead3_adr)
  #define modIndEstRead4_adr                             0x0031fa9c                                                   // modem_adr_bank7_base + 0x00000027 * 0x00000004
  #define modIndEstRead4                                 (*(volatile unsigned int *)modIndEstRead4_adr)
  #define modIndEstRead5_adr                             0x0031faa0                                                   // modem_adr_bank7_base + 0x00000028 * 0x00000004
  #define modIndEstRead5                                 (*(volatile unsigned int *)modIndEstRead5_adr)
  #define modIndEstRead6_adr                             0x0031faa4                                                   // modem_adr_bank7_base + 0x00000029 * 0x00000004
  #define modIndEstRead6                                 (*(volatile unsigned int *)modIndEstRead6_adr)
  #define modIndEstRead7_adr                             0x0031faa8                                                   // modem_adr_bank7_base + 0x0000002a * 0x00000004
  #define modIndEstRead7                                 (*(volatile unsigned int *)modIndEstRead7_adr)
  #define modIndEstRead8_adr                             0x0031faac                                                   // modem_adr_bank7_base + 0x0000002b * 0x00000004
  #define modIndEstRead8                                 (*(volatile unsigned int *)modIndEstRead8_adr)
  #define modIndEstRead9_adr                             0x0031fab0                                                   // modem_adr_bank7_base + 0x0000002c * 0x00000004
  #define modIndEstRead9                                 (*(volatile unsigned int *)modIndEstRead9_adr)
  #define modIndEstRead10_adr                            0x0031fab4                                                   // modem_adr_bank7_base + 0x0000002d * 0x00000004
  #define modIndEstRead10                                (*(volatile unsigned int *)modIndEstRead10_adr)
  #define modIndEstRead11_adr                            0x0031fab8                                                   // modem_adr_bank7_base + 0x0000002e * 0x00000004
  #define modIndEstRead11                                (*(volatile unsigned int *)modIndEstRead11_adr)
  #define modIndEstRead12_adr                            0x0031fabc                                                   // modem_adr_bank7_base + 0x0000002f * 0x00000004
  #define modIndEstRead12                                (*(volatile unsigned int *)modIndEstRead12_adr)
  #define modIndEstRead13_adr                            0x0031fac0                                                   // modem_adr_bank7_base + 0x00000030 * 0x00000004
  #define modIndEstRead13                                (*(volatile unsigned int *)modIndEstRead13_adr)
  #define modIndEstRead14_adr                            0x0031fac4                                                   // modem_adr_bank7_base + 0x00000031 * 0x00000004
  #define modIndEstRead14                                (*(volatile unsigned int *)modIndEstRead14_adr)
  #define modIndEstRead15_adr                            0x0031fac8                                                   // modem_adr_bank7_base + 0x00000032 * 0x00000004
  #define modIndEstRead15                                (*(volatile unsigned int *)modIndEstRead15_adr)
  #define modIndEstRead16_adr                            0x0031facc                                                   // modem_adr_bank7_base + 0x00000033 * 0x00000004
  #define modIndEstRead16                                (*(volatile unsigned int *)modIndEstRead16_adr)
  #define modIndEstRead17_adr                            0x0031fad0                                                   // modem_adr_bank7_base + 0x00000034 * 0x00000004
  #define modIndEstRead17                                (*(volatile unsigned int *)modIndEstRead17_adr)
  #define modIndEstRead18_adr                            0x0031fad4                                                   // modem_adr_bank7_base + 0x00000035 * 0x00000004
  #define modIndEstRead18                                (*(volatile unsigned int *)modIndEstRead18_adr)
  #define modIndEstRead19_adr                            0x0031fad8                                                   // modem_adr_bank7_base + 0x00000036 * 0x00000004
  #define modIndEstRead19                                (*(volatile unsigned int *)modIndEstRead19_adr)
  #define modIndEstRead20_adr                            0x0031fadc                                                   // modem_adr_bank7_base + 0x00000037 * 0x00000004
  #define modIndEstRead20                                (*(volatile unsigned int *)modIndEstRead20_adr)
  #define modIndEstRead21_adr                            0x0031fae0                                                   // modem_adr_bank7_base + 0x00000038 * 0x00000004
  #define modIndEstRead21                                (*(volatile unsigned int *)modIndEstRead21_adr)
  #define modIndEstRead22_adr                            0x0031fae4                                                   // modem_adr_bank7_base + 0x00000039 * 0x00000004
  #define modIndEstRead22                                (*(volatile unsigned int *)modIndEstRead22_adr)
  #define modIndEstRead23_adr                            0x0031fae8                                                   // modem_adr_bank7_base + 0x0000003a * 0x00000004
  #define modIndEstRead23                                (*(volatile unsigned int *)modIndEstRead23_adr)
  #define modIndEstRead24_adr                            0x0031faec                                                   // modem_adr_bank7_base + 0x0000003b * 0x00000004
  #define modIndEstRead24                                (*(volatile unsigned int *)modIndEstRead24_adr)
  #define modIndEstRead25_adr                            0x0031faf0                                                   // modem_adr_bank7_base + 0x0000003c * 0x00000004
  #define modIndEstRead25                                (*(volatile unsigned int *)modIndEstRead25_adr)
  #define modIndEstRead26_adr                            0x0031faf4                                                   // modem_adr_bank7_base + 0x0000003d * 0x00000004
  #define modIndEstRead26                                (*(volatile unsigned int *)modIndEstRead26_adr)
  #define modIndEstRead27_adr                            0x0031faf8                                                   // modem_adr_bank7_base + 0x0000003e * 0x00000004
  #define modIndEstRead27                                (*(volatile unsigned int *)modIndEstRead27_adr)
  #define modIndEstRead29_adr                            0x0031fb00                                                   // modem_adr_bank8_base + 0x00000000 * 0x00000004
  #define modIndEstRead29                                (*(volatile unsigned int *)modIndEstRead29_adr)
  #define modIndEstRead30_adr                            0x0031fb04                                                   // modem_adr_bank8_base + 0x00000001 * 0x00000004
  #define modIndEstRead30                                (*(volatile unsigned int *)modIndEstRead30_adr)
  #define modIndEstRead31_adr                            0x0031fb08                                                   // modem_adr_bank8_base + 0x00000002 * 0x00000004
  #define modIndEstRead31                                (*(volatile unsigned int *)modIndEstRead31_adr)
  #define modIndEstRead32_adr                            0x0031fb0c                                                   // modem_adr_bank8_base + 0x00000003 * 0x00000004
  #define modIndEstRead32                                (*(volatile unsigned int *)modIndEstRead32_adr)
  #define modIndEstRead33_adr                            0x0031fb10                                                   // modem_adr_bank8_base + 0x00000004 * 0x00000004
  #define modIndEstRead33                                (*(volatile unsigned int *)modIndEstRead33_adr)
  #define modIndEstRead34_adr                            0x0031fb14                                                   // modem_adr_bank8_base + 0x00000005 * 0x00000004
  #define modIndEstRead34                                (*(volatile unsigned int *)modIndEstRead34_adr)
  #define modIndEstRead35_adr                            0x0031fb18                                                   // modem_adr_bank8_base + 0x00000006 * 0x00000004
  #define modIndEstRead35                                (*(volatile unsigned int *)modIndEstRead35_adr)
  #define aoaEst_47_adr                                  0x0031fb1c                                                   // modem_adr_bank8_base + 0x00000007 * 0x00000004
  #define aoaEst_47                                      (*(volatile unsigned int *)aoaEst_47_adr)
  #define aoaEst_48_adr                                  0x0031fb20                                                   // modem_adr_bank8_base + 0x00000008 * 0x00000004
  #define aoaEst_48                                      (*(volatile unsigned int *)aoaEst_48_adr)
  #define aoaEst_49_adr                                  0x0031fb24                                                   // modem_adr_bank8_base + 0x00000009 * 0x00000004
  #define aoaEst_49                                      (*(volatile unsigned int *)aoaEst_49_adr)
  #define aoaEst_4a_adr                                  0x0031fb28                                                   // modem_adr_bank8_base + 0x0000000a * 0x00000004
  #define aoaEst_4a                                      (*(volatile unsigned int *)aoaEst_4a_adr)
  #define aoaEst_4b_adr                                  0x0031fb2c                                                   // modem_adr_bank8_base + 0x0000000b * 0x00000004
  #define aoaEst_4b                                      (*(volatile unsigned int *)aoaEst_4b_adr)
  #define aoaEst_4c_adr                                  0x0031fb30                                                   // modem_adr_bank8_base + 0x0000000c * 0x00000004
  #define aoaEst_4c                                      (*(volatile unsigned int *)aoaEst_4c_adr)
  #define aoaEst_4d_adr                                  0x0031fb34                                                   // modem_adr_bank8_base + 0x0000000d * 0x00000004
  #define aoaEst_4d                                      (*(volatile unsigned int *)aoaEst_4d_adr)
  #define aoaEst_4e_adr                                  0x0031fb38                                                   // modem_adr_bank8_base + 0x0000000e * 0x00000004
  #define aoaEst_4e                                      (*(volatile unsigned int *)aoaEst_4e_adr)
  #define aoaEst_4f_adr                                  0x0031fb3c                                                   // modem_adr_bank8_base + 0x0000000f * 0x00000004
  #define aoaEst_4f                                      (*(volatile unsigned int *)aoaEst_4f_adr)
  #define le2Ctrl0_adr                                   0x0031fb40                                                   // modem_adr_bank8_base + 0x00000010 * 0x00000004
  #define le2Ctrl0                                       (*(volatile unsigned int *)le2Ctrl0_adr)
  #define syncCtrl_LE2_adr                               0x0031fb44                                                   // modem_adr_bank8_base + 0x00000011 * 0x00000004
  #define syncCtrl_LE2                                   (*(volatile unsigned int *)syncCtrl_LE2_adr)
  #define syncThreshTwoLE2_adr                           0x0031fb48                                                   // modem_adr_bank8_base + 0x00000012 * 0x00000004
  #define syncThreshTwoLE2                               (*(volatile unsigned int *)syncThreshTwoLE2_adr)
  #define txPuCtrl_LE2_adr                               0x0031fb4c                                                   // modem_adr_bank8_base + 0x00000013 * 0x00000004
  #define txPuCtrl_LE2                                   (*(volatile unsigned int *)txPuCtrl_LE2_adr)
  #define rxPuCtrl_LE2_adr                               0x0031fb50                                                   // modem_adr_bank8_base + 0x00000014 * 0x00000004
  #define rxPuCtrl_LE2                                   (*(volatile unsigned int *)rxPuCtrl_LE2_adr)
  #define synthPuCtrl_LE2_adr                            0x0031fb54                                                   // modem_adr_bank8_base + 0x00000015 * 0x00000004
  #define synthPuCtrl_LE2                                (*(volatile unsigned int *)synthPuCtrl_LE2_adr)
  #define paRampCtrl_LE2_adr                             0x0031fb58                                                   // modem_adr_bank8_base + 0x00000016 * 0x00000004
  #define paRampCtrl_LE2                                 (*(volatile unsigned int *)paRampCtrl_LE2_adr)
  #define vcoloPuCtrl_LE2_adr                            0x0031fb5c                                                   // modem_adr_bank8_base + 0x00000017 * 0x00000004
  #define vcoloPuCtrl_LE2                                (*(volatile unsigned int *)vcoloPuCtrl_LE2_adr)
  #define dsadcPuCtrl_LE2_adr                            0x0031fb60                                                   // modem_adr_bank8_base + 0x00000018 * 0x00000004
  #define dsadcPuCtrl_LE2                                (*(volatile unsigned int *)dsadcPuCtrl_LE2_adr)
  #define trPuCtrl_LE2_adr                               0x0031fb64                                                   // modem_adr_bank8_base + 0x00000019 * 0x00000004
  #define trPuCtrl_LE2                                   (*(volatile unsigned int *)trPuCtrl_LE2_adr)
  #define tssiPuCtrl_LE2_adr                             0x0031fb68                                                   // modem_adr_bank8_base + 0x0000001a * 0x00000004
  #define tssiPuCtrl_LE2                                 (*(volatile unsigned int *)tssiPuCtrl_LE2_adr)
  #define ck400PuCtrlRx_LE2_adr                          0x0031fb6c                                                   // modem_adr_bank8_base + 0x0000001b * 0x00000004
  #define ck400PuCtrlRx_LE2                              (*(volatile unsigned int *)ck400PuCtrlRx_LE2_adr)
  #define ck400PuCtrlTx_LE2_adr                          0x0031fb70                                                   // modem_adr_bank8_base + 0x0000001c * 0x00000004
  #define ck400PuCtrlTx_LE2                              (*(volatile unsigned int *)ck400PuCtrlTx_LE2_adr)
  #define vcoBGPuCtrl_LE2_adr                            0x0031fb74                                                   // modem_adr_bank8_base + 0x0000001d * 0x00000004
  #define vcoBGPuCtrl_LE2                                (*(volatile unsigned int *)vcoBGPuCtrl_LE2_adr)
  #define agcPuCtrl_LE2_adr                              0x0031fb78                                                   // modem_adr_bank8_base + 0x0000001e * 0x00000004
  #define agcPuCtrl_LE2                                  (*(volatile unsigned int *)agcPuCtrl_LE2_adr)
  #define agcCtrl0_LE2_adr                               0x0031fb7c                                                   // modem_adr_bank8_base + 0x0000001f * 0x00000004
  #define agcCtrl0_LE2                                   (*(volatile unsigned int *)agcCtrl0_LE2_adr)
  #define agcCtrl1_LE2_adr                               0x0031fb80                                                   // modem_adr_bank8_base + 0x00000020 * 0x00000004
  #define agcCtrl1_LE2                                   (*(volatile unsigned int *)agcCtrl1_LE2_adr)
  #define fastAgcCtrl0_adr                               0x0031fb84                                                   // modem_adr_bank8_base + 0x00000021 * 0x00000004
  #define fastAgcCtrl0                                   (*(volatile unsigned int *)fastAgcCtrl0_adr)
  #define fastAgcCtrl1_adr                               0x0031fb88                                                   // modem_adr_bank8_base + 0x00000022 * 0x00000004
  #define fastAgcCtrl1                                   (*(volatile unsigned int *)fastAgcCtrl1_adr)
  #define fastAgcCtrl2_adr                               0x0031fb8c                                                   // modem_adr_bank8_base + 0x00000023 * 0x00000004
  #define fastAgcCtrl2                                   (*(volatile unsigned int *)fastAgcCtrl2_adr)
  #define fastAgcCtrl3_adr                               0x0031fb90                                                   // modem_adr_bank8_base + 0x00000024 * 0x00000004
  #define fastAgcCtrl3                                   (*(volatile unsigned int *)fastAgcCtrl3_adr)
  #define pll_valZsync_adr                               0x0031fb94                                                   // modem_adr_bank8_base + 0x00000025 * 0x00000004
  #define pll_valZsync                                   (*(volatile unsigned int *)pll_valZsync_adr)
  #define modIndEstRead28_adr                            0x0031fb98                                                   // modem_adr_bank8_base + 0x00000026 * 0x00000004
  #define modIndEstRead28                                (*(volatile unsigned int *)modIndEstRead28_adr)
  #define leMlse1_adr                                    0x0031fb9c                                                   // modem_adr_bank8_base + 0x00000027 * 0x00000004
  #define leMlse1                                        (*(volatile unsigned int *)leMlse1_adr)
  #define leMlse2_adr                                    0x0031fba0                                                   // modem_adr_bank8_base + 0x00000028 * 0x00000004
  #define leMlse2                                        (*(volatile unsigned int *)leMlse2_adr)
  #define leMlse3_adr                                    0x0031fba4                                                   // modem_adr_bank8_base + 0x00000029 * 0x00000004
  #define leMlse3                                        (*(volatile unsigned int *)leMlse3_adr)
  #define leMlse4_adr                                    0x0031fbc0                                                   // modem_adr_bank8_base + 0x00000030 * 0x00000004
  #define leMlse4                                        (*(volatile unsigned int *)leMlse4_adr)
  #define leMlse5_adr                                    0x0031fbc4                                                   // modem_adr_bank8_base + 0x00000031 * 0x00000004
  #define leMlse5                                        (*(volatile unsigned int *)leMlse5_adr)
  #define leMlse6_adr                                    0x0031fbc8                                                   // modem_adr_bank8_base + 0x00000032 * 0x00000004
  #define leMlse6                                        (*(volatile unsigned int *)leMlse6_adr)
  #define leMlse7_adr                                    0x0031fbcc                                                   // modem_adr_bank8_base + 0x00000033 * 0x00000004
  #define leMlse7                                        (*(volatile unsigned int *)leMlse7_adr)
  #define leMlse8_adr                                    0x0031fbd0                                                   // modem_adr_bank8_base + 0x00000034 * 0x00000004
  #define leMlse8                                        (*(volatile unsigned int *)leMlse8_adr)
  #define leMlse9_adr                                    0x0031fbd4                                                   // modem_adr_bank8_base + 0x00000035 * 0x00000004
  #define leMlse9                                        (*(volatile unsigned int *)leMlse9_adr)
  #define leMlse10_adr                                   0x0031fbd8                                                   // modem_adr_bank8_base + 0x00000036 * 0x00000004
  #define leMlse10                                       (*(volatile unsigned int *)leMlse10_adr)
  #define rbg_base                                       0x00314004                                                   // bpl_hclk_base_adr + 0x00000004
  #define rbg_control_adr                                0x00314004                                                   // rbg_base + 0x00000000
  #define rbg_control                                    (*(volatile unsigned int *)rbg_control_adr)
  #define rbg_status_adr                                 0x00314008                                                   // rbg_base + 0x00000004
  #define rbg_status                                     (*(volatile unsigned int *)rbg_status_adr)
  #define rbg_random_num_adr                             0x0031400c                                                   // rbg_base + 0x00000008
  #define rbg_random_num                                 (*(volatile unsigned int *)rbg_random_num_adr)
  #define dc_sri_ist_bit_adr                             0x00314108                                                   // sri_base2 + 0x00000001 * 0x00000004
  #define dc_sri_ist_bit                                 (*(volatile unsigned int *)dc_sri_ist_bit_adr)
  #define dc_sri_ds_bit_adr                              0x0031410c                                                   // sri_base2 + 0x00000002 * 0x00000004
  #define dc_sri_ds_bit                                  (*(volatile unsigned int *)dc_sri_ds_bit_adr)
  #define dc_sri_ist_adr0                                0x00314110                                                   // sri_base2 + 0x00000003 * 0x00000004
  #define dc_sri_ist0                                    (*(volatile unsigned int *)dc_sri_ist_adr0)
  #define dc_sri_ist_adr1                                0x00314114                                                   // sri_base2 + 0x00000004 * 0x00000004
  #define dc_sri_ist1                                    (*(volatile unsigned int *)dc_sri_ist_adr1)
  #define dc_sri_ds_adr0                                 0x00314118                                                   // sri_base2 + 0x00000005 * 0x00000004
  #define dc_sri_ds0                                     (*(volatile unsigned int *)dc_sri_ds_adr0)
  #define dc_sri_ds_adr1                                 0x0031411c                                                   // sri_base2 + 0x00000006 * 0x00000004
  #define dc_sri_ds1                                     (*(volatile unsigned int *)dc_sri_ds_adr1)
  #define dc_sri_ds_adr2                                 0x00314120                                                   // sri_base2 + 0x00000007 * 0x00000004
  #define dc_sri_ds2                                     (*(volatile unsigned int *)dc_sri_ds_adr2)
  #define dc_sri_ds_adr3                                 0x00314124                                                   // sri_base2 + 0x00000008 * 0x00000004
  #define dc_sri_ds3                                     (*(volatile unsigned int *)dc_sri_ds_adr3)
  #define dc_sri_jtag_access_adr                         0x00314128                                                   // sri_base2 + 0x00000009 * 0x00000004
  #define dc_sri_jtag_access                             (*(volatile unsigned int *)dc_sri_jtag_access_adr)
  #define phy_int_base                                   0x0031412c                                                   // sri2_tail + 0x00000000 * 0x00000004
  #define phy_status_adr                                 0x00314130                                                   // phy_int_base + 0x00000001 * 0x00000004
  #define phy_status                                     (*(volatile unsigned int *)phy_status_adr)
  #define phy_status_int_en_adr                          0x00314134                                                   // phy_int_base + 0x00000002 * 0x00000004
  #define phy_status_int_en                              (*(volatile unsigned int *)phy_status_int_en_adr)
  #define sr_status_adr0                                 0x00314138                                                   // phy_int_base + 0x00000003 * 0x00000004
  #define sr_status0                                     (*(volatile unsigned int *)sr_status_adr0)
  #define fsm_intrp_enable_adr                           0x0031413c                                                   // phy_int_base + 0x00000004 * 0x00000004
  #define fsm_intrp_enable                               (*(volatile unsigned int *)fsm_intrp_enable_adr)
  #define eci_status_adr                                 0x00314140                                                   // phy_int_base + 0x00000005 * 0x00000004
  #define eci_status                                     (*(volatile unsigned int *)eci_status_adr)
  #define eci_status_int_en_adr                          0x00314144                                                   // phy_int_base + 0x00000006 * 0x00000004
  #define eci_status_int_en                              (*(volatile unsigned int *)eci_status_int_en_adr)
  #define eci_edgtr_mode_adr                             0x00314148                                                   // phy_int_base + 0x00000007 * 0x00000004
  #define eci_edgtr_mode                                 (*(volatile unsigned int *)eci_edgtr_mode_adr)
  #define eci_dual_edge_adr                              0x0031414c                                                   // phy_int_base + 0x00000008 * 0x00000004
  #define eci_dual_edge                                  (*(volatile unsigned int *)eci_dual_edge_adr)
  #define eci_int_mask_adr                               0x00314150                                                   // phy_int_base + 0x00000009 * 0x00000004
  #define eci_int_mask                                   (*(volatile unsigned int *)eci_int_mask_adr)
  #define phy_other_base                                 0x00314154                                                   // phy_int_tail + 0x00000001 * 0x00000004
  #define rtx_dma_ctl_adr                                0x00314154                                                   // phy_other_base + 0x00000000
  #define rtx_dma_ctl                                    (*(volatile unsigned int *)rtx_dma_ctl_adr)
  #define eci_status_b_adr                               0x00314158                                                   // phy_other_base + 0x00000001 * 0x00000004
  #define eci_status_b                                   (*(volatile unsigned int *)eci_status_b_adr)
  #define eci_status_int_en_b_adr                        0x0031415c                                                   // phy_other_base + 0x00000002 * 0x00000004
  #define eci_status_int_en_b                            (*(volatile unsigned int *)eci_status_int_en_b_adr)
  #define eci_edgtr_mode_b_adr                           0x00314160                                                   // phy_other_base + 0x00000003 * 0x00000004
  #define eci_edgtr_mode_b                               (*(volatile unsigned int *)eci_edgtr_mode_b_adr)
  #define eci_dual_edge_b_adr                            0x00314164                                                   // phy_other_base + 0x00000004 * 0x00000004
  #define eci_dual_edge_b                                (*(volatile unsigned int *)eci_dual_edge_b_adr)
  #define eci_int_mask_b_adr                             0x00314168                                                   // phy_other_base + 0x00000005 * 0x00000004
  #define eci_int_mask_b                                 (*(volatile unsigned int *)eci_int_mask_b_adr)
  #define seci_fifo_data_adr                             0x00314358                                                   // phy_other_base + 0x00000081 * 0x00000004
  #define seci_fifo_data                                 (*(volatile unsigned int *)seci_fifo_data_adr)
  #define seci_uart_status_adr                           0x0031435c                                                   // phy_other_base + 0x00000082 * 0x00000004
  #define seci_uart_status                               (*(volatile unsigned int *)seci_uart_status_adr)
  #define seci_uart_status_int_en_adr                    0x00314360                                                   // phy_other_base + 0x00000083 * 0x00000004
  #define seci_uart_status_int_en                        (*(volatile unsigned int *)seci_uart_status_int_en_adr)
  #define seci_esc_adr                                   0x00314364                                                   // phy_other_base + 0x00000084 * 0x00000004
  #define seci_esc                                       (*(volatile unsigned int *)seci_esc_adr)
  #define seci_lsr_adr                                   0x00314368                                                   // phy_other_base + 0x00000085 * 0x00000004
  #define seci_lsr                                       (*(volatile unsigned int *)seci_lsr_adr)
  #define seci_msr_adr                                   0x0031436c                                                   // phy_other_base + 0x00000086 * 0x00000004
  #define seci_msr                                       (*(volatile unsigned int *)seci_msr_adr)
  #define seci_dhbr_adr                                  0x00314370                                                   // phy_other_base + 0x00000087 * 0x00000004
  #define seci_dhbr                                      (*(volatile unsigned int *)seci_dhbr_adr)
  #define seci_dlbr_adr                                  0x00314374                                                   // phy_other_base + 0x00000088 * 0x00000004
  #define seci_dlbr                                      (*(volatile unsigned int *)seci_dlbr_adr)
  #define seci_fcr_adr                                   0x00314378                                                   // phy_other_base + 0x00000089 * 0x00000004
  #define seci_fcr                                       (*(volatile unsigned int *)seci_fcr_adr)
  #define seci_mcr_adr                                   0x0031437c                                                   // phy_other_base + 0x0000008a * 0x00000004
  #define seci_mcr                                       (*(volatile unsigned int *)seci_mcr_adr)
  #define seci_lcr_adr                                   0x00314380                                                   // phy_other_base + 0x0000008b * 0x00000004
  #define seci_lcr                                       (*(volatile unsigned int *)seci_lcr_adr)
  #define seci_rfl_adr                                   0x00314384                                                   // phy_other_base + 0x0000008c * 0x00000004
  #define seci_rfl                                       (*(volatile unsigned int *)seci_rfl_adr)
  #define seci_tfl_adr                                   0x00314388                                                   // phy_other_base + 0x0000008d * 0x00000004
  #define seci_tfl                                       (*(volatile unsigned int *)seci_tfl_adr)
  #define seci_rfc_adr                                   0x0031438c                                                   // phy_other_base + 0x0000008e * 0x00000004
  #define seci_rfc                                       (*(volatile unsigned int *)seci_rfc_adr)
  #define seci_txdata_lo_adr                             0x00314390                                                   // phy_other_base + 0x0000008f * 0x00000004
  #define seci_txdata_lo                                 (*(volatile unsigned int *)seci_txdata_lo_adr)
  #define seci_txdata_hi_adr                             0x00314394                                                   // phy_other_base + 0x00000090 * 0x00000004
  #define seci_txdata_hi                                 (*(volatile unsigned int *)seci_txdata_hi_adr)
  #define seci_tag_adr                                   0x00314398                                                   // phy_other_base + 0x00000091 * 0x00000004
  #define seci_tag                                       (*(volatile unsigned int *)seci_tag_adr)
  #define seci_rxdata_lo_adr                             0x0031439c                                                   // phy_other_base + 0x00000092 * 0x00000004
  #define seci_rxdata_lo                                 (*(volatile unsigned int *)seci_rxdata_lo_adr)
  #define seci_rxdata_hi_adr                             0x003143a0                                                   // phy_other_base + 0x00000093 * 0x00000004
  #define seci_rxdata_hi                                 (*(volatile unsigned int *)seci_rxdata_hi_adr)
  #define seci_update_rx_nib_adr                         0x003143a4                                                   // phy_other_base + 0x00000094 * 0x00000004
  #define seci_update_rx_nib                             (*(volatile unsigned int *)seci_update_rx_nib_adr)
  #define seci_rxint_mask_adr                            0x003143a8                                                   // phy_other_base + 0x00000095 * 0x00000004
  #define seci_rxint_mask                                (*(volatile unsigned int *)seci_rxint_mask_adr)
  #define seci_status_adr                                0x003143ac                                                   // phy_other_base + 0x00000096 * 0x00000004
  #define seci_status                                    (*(volatile unsigned int *)seci_status_adr)
  #define otp_control_reg_adr                            0x0032e000                                                   // otp_adr_base + 0x00000000
  #define otp_control_reg                                (*(volatile unsigned int *)otp_control_reg_adr)
  #define otp_control_reg_hi_adr                         0x0032e004                                                   // otp_adr_base + 0x00000004
  #define otp_control_reg_hi                             (*(volatile unsigned int *)otp_control_reg_hi_adr)
  #define otp_address_reg_adr                            0x0032e008                                                   // otp_adr_base + 0x00000008
  #define otp_address_reg                                (*(volatile unsigned int *)otp_address_reg_adr)
  #define otp_bitsel_reg_adr                             0x0032e00c                                                   // otp_adr_base + 0x0000000c
  #define otp_bitsel_reg                                 (*(volatile unsigned int *)otp_bitsel_reg_adr)
  #define otp_wr_data_reg_adr                            0x0032e010                                                   // otp_adr_base + 0x00000010
  #define otp_wr_data_reg                                (*(volatile unsigned int *)otp_wr_data_reg_adr)
  #define otp_rd_data_reg_adr                            0x0032e014                                                   // otp_adr_base + 0x00000014
  #define otp_rd_data_reg                                (*(volatile unsigned int *)otp_rd_data_reg_adr)
  #define otp_status_reg_adr                             0x0032e018                                                   // otp_adr_base + 0x00000018
  #define otp_status_reg                                 (*(volatile unsigned int *)otp_status_reg_adr)
  #define otp_cpu_mode_reg_adr                           0x0032e01c                                                   // otp_adr_base + 0x0000001c
  #define otp_cpu_mode_reg                               (*(volatile unsigned int *)otp_cpu_mode_reg_adr)
  #define vco_cal_cal_adr                                0x00327400                                                   // vco_adr_base + 0x00000000
  #define vco_cal_cal                                    (*(volatile unsigned int *)vco_cal_cal_adr)
  #define vco_cal_start_del_adr                          0x00327404                                                   // vco_adr_base + 0x00000004
  #define vco_cal_start_del                              (*(volatile unsigned int *)vco_cal_start_del_adr)
  #define vco_cal_cal_count_adr                          0x00327408                                                   // vco_adr_base + 0x00000008
  #define vco_cal_cal_count                              (*(volatile unsigned int *)vco_cal_cal_count_adr)
  #define vco_cal_ref_timeout_adr                        0x0032740c                                                   // vco_adr_base + 0x0000000c
  #define vco_cal_ref_timeout                            (*(volatile unsigned int *)vco_cal_ref_timeout_adr)
  #define vco_cal_pause_timeout_adr                      0x00327410                                                   // vco_adr_base + 0x00000010
  #define vco_cal_pause_timeout                          (*(volatile unsigned int *)vco_cal_pause_timeout_adr)
  #define vco_cal_caps_sel_adr                           0x00327414                                                   // vco_adr_base + 0x00000014
  #define vco_cal_caps_sel                               (*(volatile unsigned int *)vco_cal_caps_sel_adr)
  #define vco_cal_force_caps_adr                         0x00327418                                                   // vco_adr_base + 0x00000018
  #define vco_cal_force_caps                             (*(volatile unsigned int *)vco_cal_force_caps_adr)
  #define vco_cal_force_caps_val_adr                     0x0032741c                                                   // vco_adr_base + 0x0000001c
  #define vco_cal_force_caps_val                         (*(volatile unsigned int *)vco_cal_force_caps_val_adr)
  #define vco_cal_force_caps_val_lsbs_adr                0x00327420                                                   // vco_adr_base + 0x00000020
  #define vco_cal_force_caps_val_lsbs                    (*(volatile unsigned int *)vco_cal_force_caps_val_lsbs_adr)
  #define vco_cal_hold_vctrl_ovr_adr                     0x00327424                                                   // vco_adr_base + 0x00000024
  #define vco_cal_hold_vctrl_ovr                         (*(volatile unsigned int *)vco_cal_hold_vctrl_ovr_adr)
  #define vco_cal_clk_gate_ovr_adr                       0x00327428                                                   // vco_adr_base + 0x00000028
  #define vco_cal_clk_gate_ovr                           (*(volatile unsigned int *)vco_cal_clk_gate_ovr_adr)
  #define vco_cal_caps_lim_h_adr                         0x0032742c                                                   // vco_adr_base + 0x0000002c
  #define vco_cal_caps_lim_h                             (*(volatile unsigned int *)vco_cal_caps_lim_h_adr)
  #define vco_cal_caps_lim_l_adr                         0x00327430                                                   // vco_adr_base + 0x00000030
  #define vco_cal_caps_lim_l                             (*(volatile unsigned int *)vco_cal_caps_lim_l_adr)
  #define vco_cal_pmu_mode_adr                           0x00327434                                                   // vco_adr_base + 0x00000034
  #define vco_cal_pmu_mode                               (*(volatile unsigned int *)vco_cal_pmu_mode_adr)
  #define vco_cal_rerun_pmu_cnt_adr                      0x00327438                                                   // vco_adr_base + 0x00000038
  #define vco_cal_rerun_pmu_cnt                          (*(volatile unsigned int *)vco_cal_rerun_pmu_cnt_adr)
  #define vco_cal_pmu_done_count_adr                     0x0032743c                                                   // vco_adr_base + 0x0000003c
  #define vco_cal_pmu_done_count                         (*(volatile unsigned int *)vco_cal_pmu_done_count_adr)
  #define vco_cal_vco_counter_adr                        0x00327440                                                   // vco_adr_base + 0x00000040
  #define vco_cal_vco_counter                            (*(volatile unsigned int *)vco_cal_vco_counter_adr)
  #define vco_cal_monitor_adr                            0x00327444                                                   // vco_adr_base + 0x00000044
  #define vco_cal_monitor                                (*(volatile unsigned int *)vco_cal_monitor_adr)
  #define vco_cal_dpll_dco_pwrdn_adr                     0x00327448                                                   // vco_adr_base + 0x00000048
  #define vco_cal_dpll_dco_pwrdn                         (*(volatile unsigned int *)vco_cal_dpll_dco_pwrdn_adr)
  #define iq_config_adr                                  0x00327500                                                   // iq_adr_base + 0x00000000
  #define iq_config                                      (*(volatile unsigned int *)iq_config_adr)
  #define iq_upi_data_adr                                0x00327504                                                   // iq_adr_base + 0x00000004
  #define iq_upi_data                                    (*(volatile unsigned int *)iq_upi_data_adr)
  #define iq_stb_ped_adr                                 0x00327508                                                   // iq_adr_base + 0x00000008
  #define iq_stb_ped                                     (*(volatile unsigned int *)iq_stb_ped_adr)
  #define iq_out_length_adr                              0x0032750c                                                   // iq_adr_base + 0x0000000c
  #define iq_out_length                                  (*(volatile unsigned int *)iq_out_length_adr)
  #define fm_ra_bypass_adr                               0x00327510                                                   // iq_adr_base + 0x00000010
  #define fm_ra_bypass                                   (*(volatile unsigned int *)fm_ra_bypass_adr)
  #define fm_ra_cont0_adr                                0x00327514                                                   // iq_adr_base + 0x00000014
  #define fm_ra_cont0                                    (*(volatile unsigned int *)fm_ra_cont0_adr)
  #define fm_ra_cont1_adr                                0x00327518                                                   // iq_adr_base + 0x00000018
  #define fm_ra_cont1                                    (*(volatile unsigned int *)fm_ra_cont1_adr)
  #define iq_clk_sel_adr                                 0x0032751c                                                   // iq_adr_base + 0x0000001c
  #define iq_clk_sel                                     (*(volatile unsigned int *)iq_clk_sel_adr)
  #define ra_clk_in_sel_adr                              0x00327520                                                   // iq_adr_base + 0x00000020
  #define ra_clk_in_sel                                  (*(volatile unsigned int *)ra_clk_in_sel_adr)
  #define rfdsp_muxout_ctl_adr                           0x00327524                                                   // iq_adr_base + 0x00000024
  #define rfdsp_muxout_ctl                               (*(volatile unsigned int *)rfdsp_muxout_ctl_adr)
  #define fm_rfclk_outen_adr                             0x00327528                                                   // iq_adr_base + 0x00000028
  #define fm_rfclk_outen                                 (*(volatile unsigned int *)fm_rfclk_outen_adr)
  #define fm_clk_sel_adr                                 0x0032752c                                                   // iq_adr_base + 0x0000002c
  #define fm_clk_sel                                     (*(volatile unsigned int *)fm_clk_sel_adr)
  #define btrf_adr_base                                  0x00600000                                                   // rf_adr_base + 0x00000000
  #define btrf_regbank_adr_base                          0x00600400                                                   // rf_adr_base + 0x00000400
  #define rx_adr_base                                    0x00600400                                                   // rf_adr_base + 0x00000400
  #define pll_adr_base                                   0x00600500                                                   // rf_adr_base + 0x00000500
  #define tx_adr_base                                    0x00600600                                                   // rf_adr_base + 0x00000600
  #define misc_adr_base                                  0x00600700                                                   // rf_adr_base + 0x00000700
  #define bs_adr_base                                    0x0060064c                                                   // rf_adr_base + 0x0000064c
  #define btrf_bt_pwrupspare_ovrVal_adr                  0x00600004                                                   // btrf_adr_base + 0x00000004
  #define btrf_bt_pwrupspare_ovrVal                      (*(volatile unsigned int *)btrf_bt_pwrupspare_ovrVal_adr)
  #define btrf_bt_pwrupspare_ovr_adr                     0x00600008                                                   // btrf_adr_base + 0x00000008
  #define btrf_bt_pwrupspare_ovr                         (*(volatile unsigned int *)btrf_bt_pwrupspare_ovr_adr)
  #define btrf_pll_rx_offset_lo_adr                      0x0060000c                                                   // btrf_adr_base + 0x0000000c
  #define btrf_pll_rx_offset_lo                          (*(volatile unsigned int *)btrf_pll_rx_offset_lo_adr)
  #define btrf_pu_ovr_0_adr                              0x00600014                                                   // btrf_adr_base + 0x00000014
  #define btrf_pu_ovr_0                                  (*(volatile unsigned int *)btrf_pu_ovr_0_adr)
  #define btrf_pu_ovr_val_0_adr                          0x00600018                                                   // btrf_adr_base + 0x00000018
  #define btrf_pu_ovr_val_0                              (*(volatile unsigned int *)btrf_pu_ovr_val_0_adr)
  #define btrf_pu_ovr_1_adr                              0x0060001c                                                   // btrf_adr_base + 0x0000001c
  #define btrf_pu_ovr_1                                  (*(volatile unsigned int *)btrf_pu_ovr_1_adr)
  #define btrf_pu_ovr_val_1_adr                          0x00600020                                                   // btrf_adr_base + 0x00000020
  #define btrf_pu_ovr_val_1                              (*(volatile unsigned int *)btrf_pu_ovr_val_1_adr)
  #define btrf_misc_ovr_adr                              0x00600024                                                   // btrf_adr_base + 0x00000024
  #define btrf_misc_ovr                                  (*(volatile unsigned int *)btrf_misc_ovr_adr)
  #define btrf_misc2_ovr_adr                             0x00600028                                                   // btrf_adr_base + 0x00000028
  #define btrf_misc2_ovr                                 (*(volatile unsigned int *)btrf_misc2_ovr_adr)
  #define btrf_misc_ovrVal_adr                           0x0060002c                                                   // btrf_adr_base + 0x0000002c
  #define btrf_misc_ovrVal                               (*(volatile unsigned int *)btrf_misc_ovrVal_adr)
  #define btrf_misc2_ovrVal_adr                          0x00600030                                                   // btrf_adr_base + 0x00000030
  #define btrf_misc2_ovrVal                              (*(volatile unsigned int *)btrf_misc2_ovrVal_adr)
  #define btrf_hi_lo_inv_adr                             0x00600034                                                   // btrf_adr_base + 0x00000034
  #define btrf_hi_lo_inv                                 (*(volatile unsigned int *)btrf_hi_lo_inv_adr)
  #define btrf_btramstby_adr                             0x0060003c                                                   // btrf_adr_base + 0x0000003c
  #define btrf_btramstby                                 (*(volatile unsigned int *)btrf_btramstby_adr)
  #define btrf_rosarito_reset_adr                        0x00600040                                                   // btrf_adr_base + 0x00000040
  #define btrf_rosarito_reset                            (*(volatile unsigned int *)btrf_rosarito_reset_adr)
  #define btrf_rosarito_ck400_pd_adr                     0x00600044                                                   // btrf_adr_base + 0x00000044
  #define btrf_rosarito_ck400_pd                         (*(volatile unsigned int *)btrf_rosarito_ck400_pd_adr)
  #define btrf_reg16_adr                                 0x00600058                                                   // btrf_adr_base + 0x00000016 * 0x00000004
  #define btrf_reg16                                     (*(volatile unsigned int *)btrf_reg16_adr)
  #define btrf_reg17_adr                                 0x0060005c                                                   // btrf_adr_base + 0x00000017 * 0x00000004
  #define btrf_reg17                                     (*(volatile unsigned int *)btrf_reg17_adr)
  #define btrf_reg1f_adr                                 0x0060007c                                                   // btrf_adr_base + 0x0000001f * 0x00000004
  #define btrf_reg1f                                     (*(volatile unsigned int *)btrf_reg1f_adr)
  #define btrf_reg22_adr                                 0x00600088                                                   // btrf_adr_base + 0x00000022 * 0x00000004
  #define btrf_reg22                                     (*(volatile unsigned int *)btrf_reg22_adr)
  #define btrf_reg23_adr                                 0x0060008c                                                   // btrf_adr_base + 0x00000023 * 0x00000004
  #define btrf_reg23                                     (*(volatile unsigned int *)btrf_reg23_adr)
  #define btrf_reg24_adr                                 0x00600090                                                   // btrf_adr_base + 0x00000024 * 0x00000004
  #define btrf_reg24                                     (*(volatile unsigned int *)btrf_reg24_adr)
  #define btrf_reg25_adr                                 0x00600094                                                   // btrf_adr_base + 0x00000025 * 0x00000004
  #define btrf_reg25                                     (*(volatile unsigned int *)btrf_reg25_adr)
  #define btrf_reg28_adr                                 0x006000a0                                                   // btrf_adr_base + 0x00000028 * 0x00000004
  #define btrf_reg28                                     (*(volatile unsigned int *)btrf_reg28_adr)
  #define btrf_reg2d_adr                                 0x006000b4                                                   // btrf_adr_base + 0x0000002d * 0x00000004
  #define btrf_reg2d                                     (*(volatile unsigned int *)btrf_reg2d_adr)
  #define btrf_reg39_adr                                 0x006000e4                                                   // btrf_adr_base + 0x00000039 * 0x00000004
  #define btrf_reg39                                     (*(volatile unsigned int *)btrf_reg39_adr)
  #define btrf_rssi_adr                                  0x00600100                                                   // btrf_adr_base + 0x00000040 * 0x00000004
  #define btrf_rssi                                      (*(volatile unsigned int *)btrf_rssi_adr)
  #define btrf_pll_val_adr                               0x00600104                                                   // btrf_adr_base + 0x00000041 * 0x00000004
  #define btrf_pll_val                                   (*(volatile unsigned int *)btrf_pll_val_adr)
  #define btrf_pwr_cntl_adr                              0x0060010c                                                   // btrf_adr_base + 0x00000043 * 0x00000004
  #define btrf_pwr_cntl                                  (*(volatile unsigned int *)btrf_pwr_cntl_adr)
  #define btrf_rf_pll_tx_base_0_adr                      0x00600124                                                   // btrf_adr_base + 0x00000049 * 0x00000004
  #define btrf_rf_pll_tx_base_0                          (*(volatile unsigned int *)btrf_rf_pll_tx_base_0_adr)
  #define btrf_rf_pll_tx_base_1_adr                      0x00600128                                                   // btrf_adr_base + 0x0000004a * 0x00000004
  #define btrf_rf_pll_tx_base_1                          (*(volatile unsigned int *)btrf_rf_pll_tx_base_1_adr)
  #define btrf_rf_pll_tx_base_2_adr                      0x0060012c                                                   // btrf_adr_base + 0x0000004b * 0x00000004
  #define btrf_rf_pll_tx_base_2                          (*(volatile unsigned int *)btrf_rf_pll_tx_base_2_adr)
  #define btrf_rf_pll_tx_delta_0_adr                     0x00600130                                                   // btrf_adr_base + 0x0000004c * 0x00000004
  #define btrf_rf_pll_tx_delta_0                         (*(volatile unsigned int *)btrf_rf_pll_tx_delta_0_adr)
  #define btrf_rf_pll_tx_delta_1_adr                     0x00600134                                                   // btrf_adr_base + 0x0000004d * 0x00000004
  #define btrf_rf_pll_tx_delta_1                         (*(volatile unsigned int *)btrf_rf_pll_tx_delta_1_adr)
  #define btrf_rf_pll_rx_base_0_adr                      0x00600138                                                   // btrf_adr_base + 0x0000004e * 0x00000004
  #define btrf_rf_pll_rx_base_0                          (*(volatile unsigned int *)btrf_rf_pll_rx_base_0_adr)
  #define btrf_rf_pll_rx_base_1_adr                      0x0060013c                                                   // btrf_adr_base + 0x0000004f * 0x00000004
  #define btrf_rf_pll_rx_base_1                          (*(volatile unsigned int *)btrf_rf_pll_rx_base_1_adr)
  #define btrf_rf_pll_rx_base_2_adr                      0x00600140                                                   // btrf_adr_base + 0x00000050 * 0x00000004
  #define btrf_rf_pll_rx_base_2                          (*(volatile unsigned int *)btrf_rf_pll_rx_base_2_adr)
  #define btrf_rf_pll_rx_delta_0_adr                     0x00600144                                                   // btrf_adr_base + 0x00000051 * 0x00000004
  #define btrf_rf_pll_rx_delta_0                         (*(volatile unsigned int *)btrf_rf_pll_rx_delta_0_adr)
  #define btrf_rf_pll_rx_delta_1_adr                     0x00600148                                                   // btrf_adr_base + 0x00000052 * 0x00000004
  #define btrf_rf_pll_rx_delta_1                         (*(volatile unsigned int *)btrf_rf_pll_rx_delta_1_adr)
  #define btrf_vco_lut_data_out_1_adr                    0x0060015c                                                   // btrf_adr_base + 0x00000057 * 0x00000004
  #define btrf_vco_lut_data_out_1                        (*(volatile unsigned int *)btrf_vco_lut_data_out_1_adr)
  #define btrf_pll_offset_adr                            0x00600160                                                   // btrf_adr_base + 0x00000058 * 0x00000004
  #define btrf_pll_offset                                (*(volatile unsigned int *)btrf_pll_offset_adr)
  #define btrf_pwrRamAdLEV0_adr                          0x00600164                                                   // btrf_adr_base + 0x00000059 * 0x00000004
  #define btrf_pwrRamAdLEV0                              (*(volatile unsigned int *)btrf_pwrRamAdLEV0_adr)
  #define btrf_pwrRamAdLEV1_adr                          0x00600168                                                   // btrf_adr_base + 0x0000005a * 0x00000004
  #define btrf_pwrRamAdLEV1                              (*(volatile unsigned int *)btrf_pwrRamAdLEV1_adr)
  #define btrf_pwrRamAdLEV2_adr                          0x0060016c                                                   // btrf_adr_base + 0x0000005b * 0x00000004
  #define btrf_pwrRamAdLEV2                              (*(volatile unsigned int *)btrf_pwrRamAdLEV2_adr)
  #define btrf_pwrRamAdLEV3_adr                          0x00600170                                                   // btrf_adr_base + 0x0000005c * 0x00000004
  #define btrf_pwrRamAdLEV3                              (*(volatile unsigned int *)btrf_pwrRamAdLEV3_adr)
  #define btrf_pwrRamAdLEV4_adr                          0x00600174                                                   // btrf_adr_base + 0x0000005d * 0x00000004
  #define btrf_pwrRamAdLEV4                              (*(volatile unsigned int *)btrf_pwrRamAdLEV4_adr)
  #define btrf_pwrRamAdLEV5_adr                          0x00600178                                                   // btrf_adr_base + 0x0000005e * 0x00000004
  #define btrf_pwrRamAdLEV5                              (*(volatile unsigned int *)btrf_pwrRamAdLEV5_adr)
  #define btrf_pwrRamAdLEV6_adr                          0x0060017c                                                   // btrf_adr_base + 0x0000005f * 0x00000004
  #define btrf_pwrRamAdLEV6                              (*(volatile unsigned int *)btrf_pwrRamAdLEV6_adr)
  #define btrf_reg60_adr                                 0x00600180                                                   // btrf_adr_base + 0x00000060 * 0x00000004
  #define btrf_reg60                                     (*(volatile unsigned int *)btrf_reg60_adr)
  #define btrf_pwrRamAdLEV7_adr                          0x00600184                                                   // btrf_adr_base + 0x00000061 * 0x00000004
  #define btrf_pwrRamAdLEV7                              (*(volatile unsigned int *)btrf_pwrRamAdLEV7_adr)
  #define btrf_pwrRamAdLEV8_adr                          0x00600188                                                   // btrf_adr_base + 0x00000062 * 0x00000004
  #define btrf_pwrRamAdLEV8                              (*(volatile unsigned int *)btrf_pwrRamAdLEV8_adr)
  #define btrf_pwrRamAdLEV9_adr                          0x0060018c                                                   // btrf_adr_base + 0x00000063 * 0x00000004
  #define btrf_pwrRamAdLEV9                              (*(volatile unsigned int *)btrf_pwrRamAdLEV9_adr)
  #define btrf_pwrRamAdLEV10_adr                         0x00600190                                                   // btrf_adr_base + 0x00000064 * 0x00000004
  #define btrf_pwrRamAdLEV10                             (*(volatile unsigned int *)btrf_pwrRamAdLEV10_adr)
  #define btrf_vco_cal_val_adr                           0x00600194                                                   // btrf_adr_base + 0x00000065 * 0x00000004
  #define btrf_vco_cal_val                               (*(volatile unsigned int *)btrf_vco_cal_val_adr)
  #define btrf_pwrRamAdLEV11_adr                         0x00600198                                                   // btrf_adr_base + 0x00000066 * 0x00000004
  #define btrf_pwrRamAdLEV11                             (*(volatile unsigned int *)btrf_pwrRamAdLEV11_adr)
  #define btrf_pwrRamAdLEV0_BLE_adr                      0x0060019c                                                   // btrf_adr_base + 0x00000067 * 0x00000004
  #define btrf_pwrRamAdLEV0_BLE                          (*(volatile unsigned int *)btrf_pwrRamAdLEV0_BLE_adr)
  #define btrf_reg6a_adr                                 0x006001a8                                                   // btrf_adr_base + 0x0000006a * 0x00000004
  #define btrf_reg6a                                     (*(volatile unsigned int *)btrf_reg6a_adr)
  #define btrf_xtal_bb_gate_adr                          0x006001bc                                                   // btrf_adr_base + 0x000001bc
  #define btrf_xtal_bb_gate                              (*(volatile unsigned int *)btrf_xtal_bb_gate_adr)
  #define btrf_delaystart_lsb_adr                        0x006001c0                                                   // btrf_adr_base + 0x000001c0
  #define btrf_delaystart_lsb                            (*(volatile unsigned int *)btrf_delaystart_lsb_adr)
  #define btrf_delaystart_msb_adr                        0x006001c4                                                   // btrf_adr_base + 0x000001c4
  #define btrf_delaystart_msb                            (*(volatile unsigned int *)btrf_delaystart_msb_adr)
  #define btrf_PauseCnt_lsb_adr                          0x006001c8                                                   // btrf_adr_base + 0x000001c8
  #define btrf_PauseCnt_lsb                              (*(volatile unsigned int *)btrf_PauseCnt_lsb_adr)
  #define btrf_PauseCnt_msb_adr                          0x006001cc                                                   // btrf_adr_base + 0x000001cc
  #define btrf_PauseCnt_msb                              (*(volatile unsigned int *)btrf_PauseCnt_msb_adr)
  #define btrf_XtalCount_lsb_adr                         0x006001d0                                                   // btrf_adr_base + 0x000001d0
  #define btrf_XtalCount_lsb                             (*(volatile unsigned int *)btrf_XtalCount_lsb_adr)
  #define btrf_XtalCount_msb_adr                         0x006001d4                                                   // btrf_adr_base + 0x000001d4
  #define btrf_XtalCount_msb                             (*(volatile unsigned int *)btrf_XtalCount_msb_adr)
  #define btrf_DeltaPllVal_adr                           0x006001d8                                                   // btrf_adr_base + 0x000001d8
  #define btrf_DeltaPllVal                               (*(volatile unsigned int *)btrf_DeltaPllVal_adr)
  #define btrf_TargetCountBase_lsb_adr                   0x006001dc                                                   // btrf_adr_base + 0x000001dc
  #define btrf_TargetCountBase_lsb                       (*(volatile unsigned int *)btrf_TargetCountBase_lsb_adr)
  #define btrf_TargetCountBase_msb_adr                   0x006001e0                                                   // btrf_adr_base + 0x000001e0
  #define btrf_TargetCountBase_msb                       (*(volatile unsigned int *)btrf_TargetCountBase_msb_adr)
  #define btrf_TargetCountCenter_lsb_adr                 0x006001e4                                                   // btrf_adr_base + 0x000001e4
  #define btrf_TargetCountCenter_lsb                     (*(volatile unsigned int *)btrf_TargetCountCenter_lsb_adr)
  #define btrf_TargetCountCenter_msb_adr                 0x006001e8                                                   // btrf_adr_base + 0x000001e8
  #define btrf_TargetCountCenter_msb                     (*(volatile unsigned int *)btrf_TargetCountCenter_msb_adr)
  #define btrf_NormCountLeft_lsb_adr                     0x006001ec                                                   // btrf_adr_base + 0x000001ec
  #define btrf_NormCountLeft_lsb                         (*(volatile unsigned int *)btrf_NormCountLeft_lsb_adr)
  #define btrf_NormCountLeft_msb_adr                     0x006001f0                                                   // btrf_adr_base + 0x000001f0
  #define btrf_NormCountLeft_msb                         (*(volatile unsigned int *)btrf_NormCountLeft_msb_adr)
  #define btrf_NormCountRight_lsb_adr                    0x006001f4                                                   // btrf_adr_base + 0x000001f4
  #define btrf_NormCountRight_lsb                        (*(volatile unsigned int *)btrf_NormCountRight_lsb_adr)
  #define btrf_NormCountRight_msb_adr                    0x006001f8                                                   // btrf_adr_base + 0x000001f8
  #define btrf_NormCountRight_msb                        (*(volatile unsigned int *)btrf_NormCountRight_msb_adr)
  #define btrf_FreqResolution_adr                        0x006001fc                                                   // btrf_adr_base + 0x000001fc
  #define btrf_FreqResolution                            (*(volatile unsigned int *)btrf_FreqResolution_adr)
  #define btrf_InitCapATx_lsb_adr                        0x00600200                                                   // btrf_adr_base + 0x00000200
  #define btrf_InitCapATx_lsb                            (*(volatile unsigned int *)btrf_InitCapATx_lsb_adr)
  #define btrf_InitCapATx_msb_adr                        0x00600204                                                   // btrf_adr_base + 0x00000204
  #define btrf_InitCapATx_msb                            (*(volatile unsigned int *)btrf_InitCapATx_msb_adr)
  #define btrf_InitCapBTx_lsb_adr                        0x00600208                                                   // btrf_adr_base + 0x00000208
  #define btrf_InitCapBTx_lsb                            (*(volatile unsigned int *)btrf_InitCapBTx_lsb_adr)
  #define btrf_InitCapBTx_msb_adr                        0x0060020c                                                   // btrf_adr_base + 0x0000020c
  #define btrf_InitCapBTx_msb                            (*(volatile unsigned int *)btrf_InitCapBTx_msb_adr)
  #define btrf_ThirdMesEn_adr                            0x00600210                                                   // btrf_adr_base + 0x00000210
  #define btrf_ThirdMesEn                                (*(volatile unsigned int *)btrf_ThirdMesEn_adr)
  #define btrf_ErrorThres_adr                            0x00600214                                                   // btrf_adr_base + 0x00000214
  #define btrf_ErrorThres                                (*(volatile unsigned int *)btrf_ErrorThres_adr)
  #define btrf_UpdateSel_adr                             0x00600218                                                   // btrf_adr_base + 0x00000218
  #define btrf_UpdateSel                                 (*(volatile unsigned int *)btrf_UpdateSel_adr)
  #define btrf_VcoloPuOR_adr                             0x0060021c                                                   // btrf_adr_base + 0x0000021c
  #define btrf_VcoloPuOR                                 (*(volatile unsigned int *)btrf_VcoloPuOR_adr)
  #define btrf_TestVcoCnt_adr                            0x00600220                                                   // btrf_adr_base + 0x00000220
  #define btrf_TestVcoCnt                                (*(volatile unsigned int *)btrf_TestVcoCnt_adr)
  #define btrf_CalCapOR_lsb_adr                          0x00600224                                                   // btrf_adr_base + 0x00000224
  #define btrf_CalCapOR_lsb                              (*(volatile unsigned int *)btrf_CalCapOR_lsb_adr)
  #define btrf_CalCapOR_msb_adr                          0x00600228                                                   // btrf_adr_base + 0x00000228
  #define btrf_CalCapOR_msb                              (*(volatile unsigned int *)btrf_CalCapOR_msb_adr)
  #define btrf_ForceVctrlOR_adr                          0x0060022c                                                   // btrf_adr_base + 0x0000022c
  #define btrf_ForceVctrlOR                              (*(volatile unsigned int *)btrf_ForceVctrlOR_adr)
  #define btrf_CalCapRBMode_adr                          0x00600230                                                   // btrf_adr_base + 0x00000230
  #define btrf_CalCapRBMode                              (*(volatile unsigned int *)btrf_CalCapRBMode_adr)
  #define btrf_CalCapRB_lsb_adr                          0x00600234                                                   // btrf_adr_base + 0x00000234
  #define btrf_CalCapRB_lsb                              (*(volatile unsigned int *)btrf_CalCapRB_lsb_adr)
  #define btrf_CalCapRB_msb_adr                          0x00600238                                                   // btrf_adr_base + 0x00000238
  #define btrf_CalCapRB_msb                              (*(volatile unsigned int *)btrf_CalCapRB_msb_adr)
  #define btrf_InitVcoCalFSM_adr                         0x0060027c                                                   // btrf_adr_base + 0x0000027c
  #define btrf_InitVcoCalFSM                             (*(volatile unsigned int *)btrf_InitVcoCalFSM_adr)
  #define btrf_VcoCalDelayEnd_lsb_adr                    0x00600280                                                   // btrf_adr_base + 0x00000280
  #define btrf_VcoCalDelayEnd_lsb                        (*(volatile unsigned int *)btrf_VcoCalDelayEnd_lsb_adr)
  #define btrf_VcoCalDelayEnd_msb_adr                    0x00600284                                                   // btrf_adr_base + 0x00000284
  #define btrf_VcoCalDelayEnd_msb                        (*(volatile unsigned int *)btrf_VcoCalDelayEnd_msb_adr)
  #define btrf_PA_VCASC_gfsk_adr                         0x00600288                                                   // btrf_adr_base + 0x00000288
  #define btrf_PA_VCASC_gfsk                             (*(volatile unsigned int *)btrf_PA_VCASC_gfsk_adr)
  #define btrf_ITRIM_PA_gfsk_adr                         0x0060028c                                                   // btrf_adr_base + 0x0000028c
  #define btrf_ITRIM_PA_gfsk                             (*(volatile unsigned int *)btrf_ITRIM_PA_gfsk_adr)
  #define btrf_TX_IDAC_PA_CASC_gfsk_adr                  0x00600290                                                   // btrf_adr_base + 0x00000290
  #define btrf_TX_IDAC_PA_CASC_gfsk                      (*(volatile unsigned int *)btrf_TX_IDAC_PA_CASC_gfsk_adr)
  #define btrf_TX_IDAC_PA_DRV_CASC_gfsk_adr              0x00600294                                                   // btrf_adr_base + 0x00000294
  #define btrf_TX_IDAC_PA_DRV_CASC_gfsk                  (*(volatile unsigned int *)btrf_TX_IDAC_PA_DRV_CASC_gfsk_adr)
  #define btrf_TX_IDAC_PA_DRV_gfsk_adr                   0x00600298                                                   // btrf_adr_base + 0x00000298
  #define btrf_TX_IDAC_PA_DRV_gfsk                       (*(volatile unsigned int *)btrf_TX_IDAC_PA_DRV_gfsk_adr)
  #define btrf_PA_DRV_GC_BIN1_gfsk_adr                   0x0060029c                                                   // btrf_adr_base + 0x0000029c
  #define btrf_PA_DRV_GC_BIN1_gfsk                       (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN1_gfsk_adr)
  #define btrf_PA_DRV_GC_BIN2_gfsk_adr                   0x006002a0                                                   // btrf_adr_base + 0x000002a0
  #define btrf_PA_DRV_GC_BIN2_gfsk                       (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN2_gfsk_adr)
  #define btrf_PA_DRV_GC_BIN3_gfsk_adr                   0x006002a4                                                   // btrf_adr_base + 0x000002a4
  #define btrf_PA_DRV_GC_BIN3_gfsk                       (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN3_gfsk_adr)
  #define btrf_PA_DRV_GC_BIN4_gfsk_adr                   0x006002a8                                                   // btrf_adr_base + 0x000002a8
  #define btrf_PA_DRV_GC_BIN4_gfsk                       (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN4_gfsk_adr)
  #define btrf_PA_DRV_GC_BIN5_gfsk_adr                   0x006002ac                                                   // btrf_adr_base + 0x000002ac
  #define btrf_PA_DRV_GC_BIN5_gfsk                       (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN5_gfsk_adr)
  #define btrf_TX_BACKUP_REG_gfsk_adr                    0x006002b0                                                   // btrf_adr_base + 0x000002b0
  #define btrf_TX_BACKUP_REG_gfsk                        (*(volatile unsigned int *)btrf_TX_BACKUP_REG_gfsk_adr)
  #define btrf_PA_VCASC_edr_adr                          0x006002b4                                                   // btrf_adr_base + 0x000002b4
  #define btrf_PA_VCASC_edr                              (*(volatile unsigned int *)btrf_PA_VCASC_edr_adr)
  #define btrf_ITRIM_PA_edr_adr                          0x006002b8                                                   // btrf_adr_base + 0x000002b8
  #define btrf_ITRIM_PA_edr                              (*(volatile unsigned int *)btrf_ITRIM_PA_edr_adr)
  #define btrf_TX_IDAC_PA_CASC_edr_adr                   0x006002bc                                                   // btrf_adr_base + 0x000002bc
  #define btrf_TX_IDAC_PA_CASC_edr                       (*(volatile unsigned int *)btrf_TX_IDAC_PA_CASC_edr_adr)
  #define btrf_TX_IDAC_PA_DRV_CASC_edr_adr               0x006002c0                                                   // btrf_adr_base + 0x000002c0
  #define btrf_TX_IDAC_PA_DRV_CASC_edr                   (*(volatile unsigned int *)btrf_TX_IDAC_PA_DRV_CASC_edr_adr)
  #define btrf_TX_IDAC_PA_DRV_edr_adr                    0x006002c4                                                   // btrf_adr_base + 0x000002c4
  #define btrf_TX_IDAC_PA_DRV_edr                        (*(volatile unsigned int *)btrf_TX_IDAC_PA_DRV_edr_adr)
  #define btrf_PA_DRV_GC_BIN1_edr_adr                    0x006002c8                                                   // btrf_adr_base + 0x000002c8
  #define btrf_PA_DRV_GC_BIN1_edr                        (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN1_edr_adr)
  #define btrf_PA_DRV_GC_BIN2_edr_adr                    0x006002cc                                                   // btrf_adr_base + 0x000002cc
  #define btrf_PA_DRV_GC_BIN2_edr                        (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN2_edr_adr)
  #define btrf_PA_DRV_GC_BIN3_edr_adr                    0x006002d0                                                   // btrf_adr_base + 0x000002d0
  #define btrf_PA_DRV_GC_BIN3_edr                        (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN3_edr_adr)
  #define btrf_PA_DRV_GC_BIN4_edr_adr                    0x006002d4                                                   // btrf_adr_base + 0x000002d4
  #define btrf_PA_DRV_GC_BIN4_edr                        (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN4_edr_adr)
  #define btrf_PA_DRV_GC_BIN5_edr_adr                    0x006002d8                                                   // btrf_adr_base + 0x000002d8
  #define btrf_PA_DRV_GC_BIN5_edr                        (*(volatile unsigned int *)btrf_PA_DRV_GC_BIN5_edr_adr)
  #define btrf_TX_BACKUP_REG_edr_adr                     0x006002dc                                                   // btrf_adr_base + 0x000002dc
  #define btrf_TX_BACKUP_REG_edr                         (*(volatile unsigned int *)btrf_TX_BACKUP_REG_edr_adr)
  #define btrf_RX_ADC_MODE_adr                           0x006002e0                                                   // btrf_adr_base + 0x000002e0
  #define btrf_RX_ADC_MODE                               (*(volatile unsigned int *)btrf_RX_ADC_MODE_adr)
  #define btrf_RX_ADC_IDAC3_MODE0_1_adr                  0x006002e4                                                   // btrf_adr_base + 0x000002e4
  #define btrf_RX_ADC_IDAC3_MODE0_1                      (*(volatile unsigned int *)btrf_RX_ADC_IDAC3_MODE0_1_adr)
  #define btrf_RX_ADC_IDAC3_MODE2_adr                    0x006002e8                                                   // btrf_adr_base + 0x000002e8
  #define btrf_RX_ADC_IDAC3_MODE2                        (*(volatile unsigned int *)btrf_RX_ADC_IDAC3_MODE2_adr)
  #define btrf_RX_FIL_MODE_adr                           0x006002ec                                                   // btrf_adr_base + 0x000002ec
  #define btrf_RX_FIL_MODE                               (*(volatile unsigned int *)btrf_RX_FIL_MODE_adr)
  #define btrf_RXTX_FIL_MODE_ovr_adr                     0x006002f0                                                   // btrf_adr_base + 0x000002f0
  #define btrf_RXTX_FIL_MODE_ovr                         (*(volatile unsigned int *)btrf_RXTX_FIL_MODE_ovr_adr)
  #define btrf_PLL_CRYSTAL_TRIM_ovrVal_adr               0x006002f4                                                   // btrf_adr_base + 0x000002f4
  #define btrf_PLL_CRYSTAL_TRIM_ovrVal                   (*(volatile unsigned int *)btrf_PLL_CRYSTAL_TRIM_ovrVal_adr)
  #define btrf_PLL_CRYSTAL_TRIM_ovr_adr                  0x006002f8                                                   // btrf_adr_base + 0x000002f8
  #define btrf_PLL_CRYSTAL_TRIM_ovr                      (*(volatile unsigned int *)btrf_PLL_CRYSTAL_TRIM_ovr_adr)
  #define btrf_btpmu_rcal_pd_adr                         0x006002fc                                                   // btrf_adr_base + 0x000002fc
  #define btrf_btpmu_rcal_pd                             (*(volatile unsigned int *)btrf_btpmu_rcal_pd_adr)
  #define btrf_InitCapARx_lsb_adr                        0x0060023c                                                   // btrf_adr_base + 0x0000023c
  #define btrf_InitCapARx_lsb                            (*(volatile unsigned int *)btrf_InitCapARx_lsb_adr)
  #define btrf_InitCapARx_msb_adr                        0x00600240                                                   // btrf_adr_base + 0x00000240
  #define btrf_InitCapARx_msb                            (*(volatile unsigned int *)btrf_InitCapARx_msb_adr)
  #define btrf_InitCapBRx_lsb_adr                        0x00600244                                                   // btrf_adr_base + 0x00000244
  #define btrf_InitCapBRx_lsb                            (*(volatile unsigned int *)btrf_InitCapBRx_lsb_adr)
  #define btrf_InitCapBRx_msb_adr                        0x00600248                                                   // btrf_adr_base + 0x00000248
  #define btrf_InitCapBRx_msb                            (*(volatile unsigned int *)btrf_InitCapBRx_msb_adr)
  #define btrf_cal_cap_lsb_adr                           0x0060024c                                                   // btrf_adr_base + 0x0000024c
  #define btrf_cal_cap_lsb                               (*(volatile unsigned int *)btrf_cal_cap_lsb_adr)
  #define btrf_cal_cap_msb_adr                           0x00600250                                                   // btrf_adr_base + 0x00000250
  #define btrf_cal_cap_msb                               (*(volatile unsigned int *)btrf_cal_cap_msb_adr)
  #define btrf_offsetTxMon_lsb_adr                       0x00600254                                                   // btrf_adr_base + 0x00000254
  #define btrf_offsetTxMon_lsb                           (*(volatile unsigned int *)btrf_offsetTxMon_lsb_adr)
  #define btrf_offsetTxMon_msb_adr                       0x00600258                                                   // btrf_adr_base + 0x00000258
  #define btrf_offsetTxMon_msb                           (*(volatile unsigned int *)btrf_offsetTxMon_msb_adr)
  #define btrf_offsetRxMon_lsb_adr                       0x0060025c                                                   // btrf_adr_base + 0x0000025c
  #define btrf_offsetRxMon_lsb                           (*(volatile unsigned int *)btrf_offsetRxMon_lsb_adr)
  #define btrf_offsetRxMon_msb_adr                       0x00600260                                                   // btrf_adr_base + 0x00000260
  #define btrf_offsetRxMon_msb                           (*(volatile unsigned int *)btrf_offsetRxMon_msb_adr)
  #define btrf_slopeTxMon_lsb_adr                        0x00600264                                                   // btrf_adr_base + 0x00000264
  #define btrf_slopeTxMon_lsb                            (*(volatile unsigned int *)btrf_slopeTxMon_lsb_adr)
  #define btrf_slopeTxMon_msb_adr                        0x00600268                                                   // btrf_adr_base + 0x00000268
  #define btrf_slopeTxMon_msb                            (*(volatile unsigned int *)btrf_slopeTxMon_msb_adr)
  #define btrf_slopeRxMon_lsb_adr                        0x0060026c                                                   // btrf_adr_base + 0x0000026c
  #define btrf_slopeRxMon_lsb                            (*(volatile unsigned int *)btrf_slopeRxMon_lsb_adr)
  #define btrf_slopeRxMon_msb_adr                        0x00600270                                                   // btrf_adr_base + 0x00000270
  #define btrf_slopeRxMon_msb                            (*(volatile unsigned int *)btrf_slopeRxMon_msb_adr)
  #define btrf_freqCntAMon_lsb_adr                       0x00600300                                                   // btrf_adr_base + 0x00000300
  #define btrf_freqCntAMon_lsb                           (*(volatile unsigned int *)btrf_freqCntAMon_lsb_adr)
  #define btrf_freqCntAMon_msb_adr                       0x00600304                                                   // btrf_adr_base + 0x00000304
  #define btrf_freqCntAMon_msb                           (*(volatile unsigned int *)btrf_freqCntAMon_msb_adr)
  #define btrf_freqCntBMon_lsb_adr                       0x00600308                                                   // btrf_adr_base + 0x00000308
  #define btrf_freqCntBMon_lsb                           (*(volatile unsigned int *)btrf_freqCntBMon_lsb_adr)
  #define btrf_freqCntBMon_msb_adr                       0x0060030c                                                   // btrf_adr_base + 0x0000030c
  #define btrf_freqCntBMon_msb                           (*(volatile unsigned int *)btrf_freqCntBMon_msb_adr)
  #define btrf_targetCountMon_lsb_adr                    0x00600310                                                   // btrf_adr_base + 0x00000310
  #define btrf_targetCountMon_lsb                        (*(volatile unsigned int *)btrf_targetCountMon_lsb_adr)
  #define btrf_targetCountMon_msb_adr                    0x00600314                                                   // btrf_adr_base + 0x00000314
  #define btrf_targetCountMon_msb                        (*(volatile unsigned int *)btrf_targetCountMon_msb_adr)
  #define btrf_regd3_adr                                 0x0060034c                                                   // btrf_adr_base + 0x000000d3 * 0x00000004
  #define btrf_regd3                                     (*(volatile unsigned int *)btrf_regd3_adr)
  #define btrf_regd4_adr                                 0x00600350                                                   // btrf_adr_base + 0x000000d4 * 0x00000004
  #define btrf_regd4                                     (*(volatile unsigned int *)btrf_regd4_adr)
  #define btrf_regd5_adr                                 0x00600354                                                   // btrf_adr_base + 0x000000d5 * 0x00000004
  #define btrf_regd5                                     (*(volatile unsigned int *)btrf_regd5_adr)
  #define btrf_regd6_adr                                 0x00600358                                                   // btrf_adr_base + 0x000000d6 * 0x00000004
  #define btrf_regd6                                     (*(volatile unsigned int *)btrf_regd6_adr)
  #define btrf_regd7_adr                                 0x0060035c                                                   // btrf_adr_base + 0x000000d7 * 0x00000004
  #define btrf_regd7                                     (*(volatile unsigned int *)btrf_regd7_adr)
  #define btrf_regd8_adr                                 0x00600360                                                   // btrf_adr_base + 0x000000d8 * 0x00000004
  #define btrf_regd8                                     (*(volatile unsigned int *)btrf_regd8_adr)
  #define btrf_regd9_adr                                 0x00600364                                                   // btrf_adr_base + 0x000000d9 * 0x00000004
  #define btrf_regd9                                     (*(volatile unsigned int *)btrf_regd9_adr)
  #define btrf_regda_adr                                 0x00600368                                                   // btrf_adr_base + 0x000000da * 0x00000004
  #define btrf_regda                                     (*(volatile unsigned int *)btrf_regda_adr)
  #define btrf_regdb_adr                                 0x0060036c                                                   // btrf_adr_base + 0x000000db * 0x00000004
  #define btrf_regdb                                     (*(volatile unsigned int *)btrf_regdb_adr)
  #define btrf_regdc_adr                                 0x00600370                                                   // btrf_adr_base + 0x000000dc * 0x00000004
  #define btrf_regdc                                     (*(volatile unsigned int *)btrf_regdc_adr)
  #define btrf_regdd_adr                                 0x00600374                                                   // btrf_adr_base + 0x000000dd * 0x00000004
  #define btrf_regdd                                     (*(volatile unsigned int *)btrf_regdd_adr)
  #define btrf_VCO_SWC_BAND_adr                          0x00600378                                                   // btrf_adr_base + 0x000000de * 0x00000004
  #define btrf_VCO_SWC_BAND                              (*(volatile unsigned int *)btrf_VCO_SWC_BAND_adr)
  #define btrf_TIA_ctrl_adr                              0x0060037c                                                   // btrf_adr_base + 0x000000df * 0x00000004
  #define btrf_TIA_ctrl                                  (*(volatile unsigned int *)btrf_TIA_ctrl_adr)
  #define btrf_pa_tune_gfsk_adr                          0x00600380                                                   // btrf_adr_base + 0x000000e0 * 0x00000004
  #define btrf_pa_tune_gfsk                              (*(volatile unsigned int *)btrf_pa_tune_gfsk_adr)
  #define btrf_pa_tune_edr_adr                           0x00600384                                                   // btrf_adr_base + 0x000000e1 * 0x00000004
  #define btrf_pa_tune_edr                               (*(volatile unsigned int *)btrf_pa_tune_edr_adr)
  #define btrf_padrv_mx_tune_BIN1_gfsk_adr               0x00600388                                                   // btrf_adr_base + 0x000000e2 * 0x00000004
  #define btrf_padrv_mx_tune_BIN1_gfsk                   (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN1_gfsk_adr)
  #define btrf_padrv_mx_tune_BIN2_gfsk_adr               0x0060038c                                                   // btrf_adr_base + 0x000000e3 * 0x00000004
  #define btrf_padrv_mx_tune_BIN2_gfsk                   (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN2_gfsk_adr)
  #define btrf_padrv_mx_tune_BIN3_gfsk_adr               0x00600390                                                   // btrf_adr_base + 0x000000e4 * 0x00000004
  #define btrf_padrv_mx_tune_BIN3_gfsk                   (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN3_gfsk_adr)
  #define btrf_padrv_mx_tune_BIN4_gfsk_adr               0x00600394                                                   // btrf_adr_base + 0x000000e5 * 0x00000004
  #define btrf_padrv_mx_tune_BIN4_gfsk                   (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN4_gfsk_adr)
  #define btrf_padrv_mx_tune_BIN5_gfsk_adr               0x00600398                                                   // btrf_adr_base + 0x000000e6 * 0x00000004
  #define btrf_padrv_mx_tune_BIN5_gfsk                   (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN5_gfsk_adr)
  #define btrf_padrv_mx_tune_BIN1_edr_adr                0x0060039c                                                   // btrf_adr_base + 0x000000e7 * 0x00000004
  #define btrf_padrv_mx_tune_BIN1_edr                    (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN1_edr_adr)
  #define btrf_padrv_mx_tune_BIN2_edr_adr                0x006003a0                                                   // btrf_adr_base + 0x000000e8 * 0x00000004
  #define btrf_padrv_mx_tune_BIN2_edr                    (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN2_edr_adr)
  #define btrf_padrv_mx_tune_BIN3_edr_adr                0x006003a4                                                   // btrf_adr_base + 0x000000e9 * 0x00000004
  #define btrf_padrv_mx_tune_BIN3_edr                    (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN3_edr_adr)
  #define btrf_padrv_mx_tune_BIN4_edr_adr                0x006003a8                                                   // btrf_adr_base + 0x000000ea * 0x00000004
  #define btrf_padrv_mx_tune_BIN4_edr                    (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN4_edr_adr)
  #define btrf_padrv_mx_tune_BIN5_edr_adr                0x006003ac                                                   // btrf_adr_base + 0x000000eb * 0x00000004
  #define btrf_padrv_mx_tune_BIN5_edr                    (*(volatile unsigned int *)btrf_padrv_mx_tune_BIN5_edr_adr)
  #define btrf_pllRamAd_adr                              0x006003c8                                                   // btrf_adr_base + 0x000000f2 * 0x00000004
  #define btrf_pllRamAd                                  (*(volatile unsigned int *)btrf_pllRamAd_adr)
  #define btrf_pllRamBo_adr                              0x006003cc                                                   // btrf_adr_base + 0x000000f3 * 0x00000004
  #define btrf_pllRamBo                                  (*(volatile unsigned int *)btrf_pllRamBo_adr)
  #define btrf_pllRamD_adr                               0x006003d0                                                   // btrf_adr_base + 0x000000f4 * 0x00000004
  #define btrf_pllRamD                                   (*(volatile unsigned int *)btrf_pllRamD_adr)
  #define btrf_pwrRamAd_adr                              0x006003e0                                                   // btrf_adr_base + 0x000000f8 * 0x00000004
  #define btrf_pwrRamAd                                  (*(volatile unsigned int *)btrf_pwrRamAd_adr)
  #define btrf_pwrRamBo_adr                              0x006003e4                                                   // btrf_adr_base + 0x000000f9 * 0x00000004
  #define btrf_pwrRamBo                                  (*(volatile unsigned int *)btrf_pwrRamBo_adr)
  #define btrf_pwrRamD_adr                               0x006003e8                                                   // btrf_adr_base + 0x000000fa * 0x00000004
  #define btrf_pwrRamD                                   (*(volatile unsigned int *)btrf_pwrRamD_adr)
  #define btrf_rx_reg3_adr                               0x0060040c                                                   // rx_adr_base + 0x00000003 * 0x00000004
  #define btrf_rx_reg3                                   (*(volatile unsigned int *)btrf_rx_reg3_adr)
  #define btrf_rx_reg4_adr                               0x00600410                                                   // rx_adr_base + 0x00000004 * 0x00000004
  #define btrf_rx_reg4                                   (*(volatile unsigned int *)btrf_rx_reg4_adr)
  #define btrf_rx_reg5_adr                               0x00600414                                                   // rx_adr_base + 0x00000005 * 0x00000004
  #define btrf_rx_reg5                                   (*(volatile unsigned int *)btrf_rx_reg5_adr)
  #define btrf_rx_reg6_adr                               0x00600418                                                   // rx_adr_base + 0x00000006 * 0x00000004
  #define btrf_rx_reg6                                   (*(volatile unsigned int *)btrf_rx_reg6_adr)
  #define btrf_rx_reg7_adr                               0x0060041c                                                   // rx_adr_base + 0x00000007 * 0x00000004
  #define btrf_rx_reg7                                   (*(volatile unsigned int *)btrf_rx_reg7_adr)
  #define btrf_rx_reg8_adr                               0x00600420                                                   // rx_adr_base + 0x00000008 * 0x00000004
  #define btrf_rx_reg8                                   (*(volatile unsigned int *)btrf_rx_reg8_adr)
  #define btrf_rx_reg9_adr                               0x00600424                                                   // rx_adr_base + 0x00000009 * 0x00000004
  #define btrf_rx_reg9                                   (*(volatile unsigned int *)btrf_rx_reg9_adr)
  #define btrf_rx_regA_adr                               0x00600428                                                   // rx_adr_base + 0x0000000a * 0x00000004
  #define btrf_rx_regA                                   (*(volatile unsigned int *)btrf_rx_regA_adr)
  #define btrf_rx_regB_adr                               0x0060042c                                                   // rx_adr_base + 0x0000000b * 0x00000004
  #define btrf_rx_regB                                   (*(volatile unsigned int *)btrf_rx_regB_adr)
  #define btrf_rx_regC_adr                               0x00600430                                                   // rx_adr_base + 0x0000000c * 0x00000004
  #define btrf_rx_regC                                   (*(volatile unsigned int *)btrf_rx_regC_adr)
  #define btrf_rx_regD_adr                               0x00600434                                                   // rx_adr_base + 0x0000000d * 0x00000004
  #define btrf_rx_regD                                   (*(volatile unsigned int *)btrf_rx_regD_adr)
  #define btrf_rx_regE_adr                               0x00600438                                                   // rx_adr_base + 0x0000000e * 0x00000004
  #define btrf_rx_regE                                   (*(volatile unsigned int *)btrf_rx_regE_adr)
  #define btrf_rx_regF_adr                               0x0060043c                                                   // rx_adr_base + 0x0000000f * 0x00000004
  #define btrf_rx_regF                                   (*(volatile unsigned int *)btrf_rx_regF_adr)
  #define btrf_rx_reg10_adr                              0x00600440                                                   // rx_adr_base + 0x00000010 * 0x00000004
  #define btrf_rx_reg10                                  (*(volatile unsigned int *)btrf_rx_reg10_adr)
  #define btrf_rx_reg11_adr                              0x00600444                                                   // rx_adr_base + 0x00000011 * 0x00000004
  #define btrf_rx_reg11                                  (*(volatile unsigned int *)btrf_rx_reg11_adr)
  #define btrf_rx_reg12_adr                              0x00600448                                                   // rx_adr_base + 0x00000012 * 0x00000004
  #define btrf_rx_reg12                                  (*(volatile unsigned int *)btrf_rx_reg12_adr)
  #define btrf_rx_reg13_adr                              0x0060044c                                                   // rx_adr_base + 0x00000013 * 0x00000004
  #define btrf_rx_reg13                                  (*(volatile unsigned int *)btrf_rx_reg13_adr)
  #define btrf_rx_reg14_adr                              0x00600450                                                   // rx_adr_base + 0x00000014 * 0x00000004
  #define btrf_rx_reg14                                  (*(volatile unsigned int *)btrf_rx_reg14_adr)
  #define btrf_rx_reg15_adr                              0x00600454                                                   // rx_adr_base + 0x00000015 * 0x00000004
  #define btrf_rx_reg15                                  (*(volatile unsigned int *)btrf_rx_reg15_adr)
  #define btrf_rx_reg16_adr                              0x00600458                                                   // rx_adr_base + 0x00000016 * 0x00000004
  #define btrf_rx_reg16                                  (*(volatile unsigned int *)btrf_rx_reg16_adr)
  #define btrf_rx_reg17_adr                              0x0060045c                                                   // rx_adr_base + 0x00000017 * 0x00000004
  #define btrf_rx_reg17                                  (*(volatile unsigned int *)btrf_rx_reg17_adr)
  #define btrf_rx_reg18_adr                              0x00600460                                                   // rx_adr_base + 0x00000018 * 0x00000004
  #define btrf_rx_reg18                                  (*(volatile unsigned int *)btrf_rx_reg18_adr)
  #define btrf_rx_reg19_adr                              0x00600464                                                   // rx_adr_base + 0x00000019 * 0x00000004
  #define btrf_rx_reg19                                  (*(volatile unsigned int *)btrf_rx_reg19_adr)
  #define btrf_rx_reg1A_adr                              0x00600468                                                   // rx_adr_base + 0x0000001a * 0x00000004
  #define btrf_rx_reg1A                                  (*(volatile unsigned int *)btrf_rx_reg1A_adr)
  #define btrf_rx_reg1B_adr                              0x0060046c                                                   // rx_adr_base + 0x0000001b * 0x00000004
  #define btrf_rx_reg1B                                  (*(volatile unsigned int *)btrf_rx_reg1B_adr)
  #define btrf_rx_reg1C_adr                              0x00600470                                                   // rx_adr_base + 0x0000001c * 0x00000004
  #define btrf_rx_reg1C                                  (*(volatile unsigned int *)btrf_rx_reg1C_adr)
  #define btrf_rx_reg1D_adr                              0x00600474                                                   // rx_adr_base + 0x0000001d * 0x00000004
  #define btrf_rx_reg1D                                  (*(volatile unsigned int *)btrf_rx_reg1D_adr)
  #define btrf_rx_reg1E_adr                              0x00600478                                                   // rx_adr_base + 0x0000001e * 0x00000004
  #define btrf_rx_reg1E                                  (*(volatile unsigned int *)btrf_rx_reg1E_adr)
  #define btrf_rx_reg1F_adr                              0x0060047c                                                   // rx_adr_base + 0x0000001f * 0x00000004
  #define btrf_rx_reg1F                                  (*(volatile unsigned int *)btrf_rx_reg1F_adr)
  #define btrf_rx_reg20_adr                              0x00600480                                                   // rx_adr_base + 0x00000020 * 0x00000004
  #define btrf_rx_reg20                                  (*(volatile unsigned int *)btrf_rx_reg20_adr)
  #define btrf_rx_reg21_adr                              0x00600484                                                   // rx_adr_base + 0x00000021 * 0x00000004
  #define btrf_rx_reg21                                  (*(volatile unsigned int *)btrf_rx_reg21_adr)
  #define btrf_rx_reg22_adr                              0x00600488                                                   // rx_adr_base + 0x00000022 * 0x00000004
  #define btrf_rx_reg22                                  (*(volatile unsigned int *)btrf_rx_reg22_adr)
  #define btrf_rx_reg23_adr                              0x0060048c                                                   // rx_adr_base + 0x00000023 * 0x00000004
  #define btrf_rx_reg23                                  (*(volatile unsigned int *)btrf_rx_reg23_adr)
  #define btrf_rx_reg24_adr                              0x00600490                                                   // rx_adr_base + 0x00000024 * 0x00000004
  #define btrf_rx_reg24                                  (*(volatile unsigned int *)btrf_rx_reg24_adr)
  #define btrf_rx_reg25_adr                              0x00600494                                                   // rx_adr_base + 0x00000025 * 0x00000004
  #define btrf_rx_reg25                                  (*(volatile unsigned int *)btrf_rx_reg25_adr)
  #define btrf_rx_reg26_adr                              0x00600498                                                   // rx_adr_base + 0x00000026 * 0x00000004
  #define btrf_rx_reg26                                  (*(volatile unsigned int *)btrf_rx_reg26_adr)
  #define btrf_rx_reg27_adr                              0x0060049c                                                   // rx_adr_base + 0x00000027 * 0x00000004
  #define btrf_rx_reg27                                  (*(volatile unsigned int *)btrf_rx_reg27_adr)
  #define btrf_rx_reg28_adr                              0x006004a0                                                   // rx_adr_base + 0x00000028 * 0x00000004
  #define btrf_rx_reg28                                  (*(volatile unsigned int *)btrf_rx_reg28_adr)
  #define btrf_rx_reg29_adr                              0x006004a4                                                   // rx_adr_base + 0x00000029 * 0x00000004
  #define btrf_rx_reg29                                  (*(volatile unsigned int *)btrf_rx_reg29_adr)
  #define btrf_rx_reg2A_adr                              0x006004a8                                                   // rx_adr_base + 0x0000002a * 0x00000004
  #define btrf_rx_reg2A                                  (*(volatile unsigned int *)btrf_rx_reg2A_adr)
  #define btrf_rx_reg2B_adr                              0x006004ac                                                   // rx_adr_base + 0x0000002b * 0x00000004
  #define btrf_rx_reg2B                                  (*(volatile unsigned int *)btrf_rx_reg2B_adr)
  #define btrf_rx_reg2C_adr                              0x006004b0                                                   // rx_adr_base + 0x0000002c * 0x00000004
  #define btrf_rx_reg2C                                  (*(volatile unsigned int *)btrf_rx_reg2C_adr)
  #define btrf_rx_reg2D_adr                              0x006004b4                                                   // rx_adr_base + 0x0000002d * 0x00000004
  #define btrf_rx_reg2D                                  (*(volatile unsigned int *)btrf_rx_reg2D_adr)
  #define btrf_rx_reg2E_adr                              0x006004b8                                                   // rx_adr_base + 0x0000002e * 0x00000004
  #define btrf_rx_reg2E                                  (*(volatile unsigned int *)btrf_rx_reg2E_adr)
  #define btrf_rx_reg2F_adr                              0x006004bc                                                   // rx_adr_base + 0x0000002f * 0x00000004
  #define btrf_rx_reg2F                                  (*(volatile unsigned int *)btrf_rx_reg2F_adr)
  #define btrf_rx_reg30_adr                              0x006004c0                                                   // rx_adr_base + 0x00000030 * 0x00000004
  #define btrf_rx_reg30                                  (*(volatile unsigned int *)btrf_rx_reg30_adr)
  #define btrf_rx_reg31_adr                              0x006004c4                                                   // rx_adr_base + 0x00000031 * 0x00000004
  #define btrf_rx_reg31                                  (*(volatile unsigned int *)btrf_rx_reg31_adr)
  #define btrf_rx_reg32_adr                              0x006004c8                                                   // rx_adr_base + 0x00000032 * 0x00000004
  #define btrf_rx_reg32                                  (*(volatile unsigned int *)btrf_rx_reg32_adr)
  #define btrf_rx_reg33_adr                              0x006004cc                                                   // rx_adr_base + 0x00000033 * 0x00000004
  #define btrf_rx_reg33                                  (*(volatile unsigned int *)btrf_rx_reg33_adr)
  #define btrf_rx_reg34_adr                              0x006004d0                                                   // rx_adr_base + 0x00000034 * 0x00000004
  #define btrf_rx_reg34                                  (*(volatile unsigned int *)btrf_rx_reg34_adr)
  #define btrf_rx_reg35_adr                              0x006004d4                                                   // rx_adr_base + 0x00000035 * 0x00000004
  #define btrf_rx_reg35                                  (*(volatile unsigned int *)btrf_rx_reg35_adr)
  #define btrf_rx_reg36_adr                              0x006004d8                                                   // rx_adr_base + 0x00000036 * 0x00000004
  #define btrf_rx_reg36                                  (*(volatile unsigned int *)btrf_rx_reg36_adr)
  #define btrf_rx_reg37_adr                              0x006004dc                                                   // rx_adr_base + 0x00000037 * 0x00000004
  #define btrf_rx_reg37                                  (*(volatile unsigned int *)btrf_rx_reg37_adr)
  #define btrf_rx_reg38_adr                              0x006004e0                                                   // rx_adr_base + 0x00000038 * 0x00000004
  #define btrf_rx_reg38                                  (*(volatile unsigned int *)btrf_rx_reg38_adr)
  #define btrf_rx_reg39_adr                              0x006004e4                                                   // rx_adr_base + 0x00000039 * 0x00000004
  #define btrf_rx_reg39                                  (*(volatile unsigned int *)btrf_rx_reg39_adr)
  #define btrf_rx_reg3A_adr                              0x006004e8                                                   // rx_adr_base + 0x0000003a * 0x00000004
  #define btrf_rx_reg3A                                  (*(volatile unsigned int *)btrf_rx_reg3A_adr)
  #define btrf_rx_reg3B_adr                              0x006004ec                                                   // rx_adr_base + 0x0000003b * 0x00000004
  #define btrf_rx_reg3B                                  (*(volatile unsigned int *)btrf_rx_reg3B_adr)
  #define btrf_rx_reg3C_adr                              0x006004f0                                                   // rx_adr_base + 0x0000003c * 0x00000004
  #define btrf_rx_reg3C                                  (*(volatile unsigned int *)btrf_rx_reg3C_adr)
  #define btrf_rx_reg3D_adr                              0x006004f4                                                   // rx_adr_base + 0x0000003d * 0x00000004
  #define btrf_rx_reg3D                                  (*(volatile unsigned int *)btrf_rx_reg3D_adr)
  #define btrf_rx_reg3E_adr                              0x006004f8                                                   // rx_adr_base + 0x0000003e * 0x00000004
  #define btrf_rx_reg3E                                  (*(volatile unsigned int *)btrf_rx_reg3E_adr)
  #define btrf_rx_reg3F_adr                              0x006004fc                                                   // rx_adr_base + 0x0000003f * 0x00000004
  #define btrf_rx_reg3F                                  (*(volatile unsigned int *)btrf_rx_reg3F_adr)
  #define btrf_pll_pwr_cntl_adr                          0x0060050c                                                   // pll_adr_base + 0x00000003 * 0x00000004
  #define btrf_pll_pwr_cntl                              (*(volatile unsigned int *)btrf_pll_pwr_cntl_adr)
  #define btrf_pll_reg53_adr                             0x0060054c                                                   // pll_adr_base + 0x00000013 * 0x00000004
  #define btrf_pll_reg53                                 (*(volatile unsigned int *)btrf_pll_reg53_adr)
  #define btrf_pll_reg54_adr                             0x00600550                                                   // pll_adr_base + 0x00000014 * 0x00000004
  #define btrf_pll_reg54                                 (*(volatile unsigned int *)btrf_pll_reg54_adr)
  #define btrf_pll_reg55_adr                             0x00600554                                                   // pll_adr_base + 0x00000015 * 0x00000004
  #define btrf_pll_reg55                                 (*(volatile unsigned int *)btrf_pll_reg55_adr)
  #define btrf_pll_reg56_adr                             0x00600558                                                   // pll_adr_base + 0x00000016 * 0x00000004
  #define btrf_pll_reg56                                 (*(volatile unsigned int *)btrf_pll_reg56_adr)
  #define btrf_pll_reg57_adr                             0x0060055c                                                   // pll_adr_base + 0x00000017 * 0x00000004
  #define btrf_pll_reg57                                 (*(volatile unsigned int *)btrf_pll_reg57_adr)
  #define btrf_pll_reg58_adr                             0x00600560                                                   // pll_adr_base + 0x00000018 * 0x00000004
  #define btrf_pll_reg58                                 (*(volatile unsigned int *)btrf_pll_reg58_adr)
  #define btrf_pll_reg59_adr                             0x00600564                                                   // pll_adr_base + 0x00000019 * 0x00000004
  #define btrf_pll_reg59                                 (*(volatile unsigned int *)btrf_pll_reg59_adr)
  #define btrf_pll_reg5A_adr                             0x00600568                                                   // pll_adr_base + 0x0000001a * 0x00000004
  #define btrf_pll_reg5A                                 (*(volatile unsigned int *)btrf_pll_reg5A_adr)
  #define btrf_pll_reg5B_adr                             0x0060056c                                                   // pll_adr_base + 0x0000001b * 0x00000004
  #define btrf_pll_reg5B                                 (*(volatile unsigned int *)btrf_pll_reg5B_adr)
  #define btrf_pll_reg5C_adr                             0x00600570                                                   // pll_adr_base + 0x0000001c * 0x00000004
  #define btrf_pll_reg5C                                 (*(volatile unsigned int *)btrf_pll_reg5C_adr)
  #define btrf_pll_reg5D_adr                             0x00600574                                                   // pll_adr_base + 0x0000001d * 0x00000004
  #define btrf_pll_reg5D                                 (*(volatile unsigned int *)btrf_pll_reg5D_adr)
  #define btrf_pll_reg5E_adr                             0x00600578                                                   // pll_adr_base + 0x0000001e * 0x00000004
  #define btrf_pll_reg5E                                 (*(volatile unsigned int *)btrf_pll_reg5E_adr)
  #define btrf_pll_reg5F_adr                             0x0060057c                                                   // pll_adr_base + 0x0000001f * 0x00000004
  #define btrf_pll_reg5F                                 (*(volatile unsigned int *)btrf_pll_reg5F_adr)
  #define btrf_pll_reg60_adr                             0x00600580                                                   // pll_adr_base + 0x00000020 * 0x00000004
  #define btrf_pll_reg60                                 (*(volatile unsigned int *)btrf_pll_reg60_adr)
  #define btrf_pll_reg61_adr                             0x00600584                                                   // pll_adr_base + 0x00000021 * 0x00000004
  #define btrf_pll_reg61                                 (*(volatile unsigned int *)btrf_pll_reg61_adr)
  #define btrf_pll_reg62_adr                             0x00600588                                                   // pll_adr_base + 0x00000022 * 0x00000004
  #define btrf_pll_reg62                                 (*(volatile unsigned int *)btrf_pll_reg62_adr)
  #define btrf_pll_reg63_adr                             0x0060058c                                                   // pll_adr_base + 0x00000023 * 0x00000004
  #define btrf_pll_reg63                                 (*(volatile unsigned int *)btrf_pll_reg63_adr)
  #define btrf_pll_reg64_adr                             0x00600590                                                   // pll_adr_base + 0x00000024 * 0x00000004
  #define btrf_pll_reg64                                 (*(volatile unsigned int *)btrf_pll_reg64_adr)
  #define btrf_pll_reg65_adr                             0x00600594                                                   // pll_adr_base + 0x00000025 * 0x00000004
  #define btrf_pll_reg65                                 (*(volatile unsigned int *)btrf_pll_reg65_adr)
  #define btrf_pll_reg66_adr                             0x00600598                                                   // pll_adr_base + 0x00000026 * 0x00000004
  #define btrf_pll_reg66                                 (*(volatile unsigned int *)btrf_pll_reg66_adr)
  #define btrf_pll_reg67_adr                             0x0060059c                                                   // pll_adr_base + 0x00000027 * 0x00000004
  #define btrf_pll_reg67                                 (*(volatile unsigned int *)btrf_pll_reg67_adr)
  #define btrf_pll_reg68_adr                             0x006005a0                                                   // pll_adr_base + 0x00000028 * 0x00000004
  #define btrf_pll_reg68                                 (*(volatile unsigned int *)btrf_pll_reg68_adr)
  #define btrf_pll_reg69_adr                             0x006005a4                                                   // pll_adr_base + 0x00000029 * 0x00000004
  #define btrf_pll_reg69                                 (*(volatile unsigned int *)btrf_pll_reg69_adr)
  #define btrf_pll_reg6A_adr                             0x006005a8                                                   // pll_adr_base + 0x0000002a * 0x00000004
  #define btrf_pll_reg6A                                 (*(volatile unsigned int *)btrf_pll_reg6A_adr)
  #define btrf_pll_reg6B_adr                             0x006005ac                                                   // pll_adr_base + 0x0000002b * 0x00000004
  #define btrf_pll_reg6B                                 (*(volatile unsigned int *)btrf_pll_reg6B_adr)
  #define btrf_pll_reg6C_adr                             0x006005b0                                                   // pll_adr_base + 0x0000002c * 0x00000004
  #define btrf_pll_reg6C                                 (*(volatile unsigned int *)btrf_pll_reg6C_adr)
  #define btrf_pll_reg6D_adr                             0x006005b4                                                   // pll_adr_base + 0x0000002d * 0x00000004
  #define btrf_pll_reg6D                                 (*(volatile unsigned int *)btrf_pll_reg6D_adr)
  #define btrf_pll_reg6E_adr                             0x006005b8                                                   // pll_adr_base + 0x0000002e * 0x00000004
  #define btrf_pll_reg6E                                 (*(volatile unsigned int *)btrf_pll_reg6E_adr)
  #define btrf_pll_reg6F_adr                             0x006005bc                                                   // pll_adr_base + 0x0000002f * 0x00000004
  #define btrf_pll_reg6F                                 (*(volatile unsigned int *)btrf_pll_reg6F_adr)
  #define btrf_pll_reg70_adr                             0x006005c0                                                   // pll_adr_base + 0x00000030 * 0x00000004
  #define btrf_pll_reg70                                 (*(volatile unsigned int *)btrf_pll_reg70_adr)
  #define btrf_pll_reg71_adr                             0x006005c4                                                   // pll_adr_base + 0x00000031 * 0x00000004
  #define btrf_pll_reg71                                 (*(volatile unsigned int *)btrf_pll_reg71_adr)
  #define btrf_pll_reg72_adr                             0x006005c8                                                   // pll_adr_base + 0x00000032 * 0x00000004
  #define btrf_pll_reg72                                 (*(volatile unsigned int *)btrf_pll_reg72_adr)
  #define btrf_pll_reg73_adr                             0x006005cc                                                   // pll_adr_base + 0x00000033 * 0x00000004
  #define btrf_pll_reg73                                 (*(volatile unsigned int *)btrf_pll_reg73_adr)
  #define btrf_pll_reg74_adr                             0x006005d0                                                   // pll_adr_base + 0x00000034 * 0x00000004
  #define btrf_pll_reg74                                 (*(volatile unsigned int *)btrf_pll_reg74_adr)
  #define btrf_pll_reg75_adr                             0x006005d4                                                   // pll_adr_base + 0x00000035 * 0x00000004
  #define btrf_pll_reg75                                 (*(volatile unsigned int *)btrf_pll_reg75_adr)
  #define btrf_pll_reg76_adr                             0x006005d8                                                   // pll_adr_base + 0x00000036 * 0x00000004
  #define btrf_pll_reg76                                 (*(volatile unsigned int *)btrf_pll_reg76_adr)
  #define btrf_pll_reg77_adr                             0x006005dc                                                   // pll_adr_base + 0x00000037 * 0x00000004
  #define btrf_pll_reg77                                 (*(volatile unsigned int *)btrf_pll_reg77_adr)
  #define btrf_pll_reg78_adr                             0x006005e0                                                   // pll_adr_base + 0x00000038 * 0x00000004
  #define btrf_pll_reg78                                 (*(volatile unsigned int *)btrf_pll_reg78_adr)
  #define btrf_pll_reg79_adr                             0x006005e4                                                   // pll_adr_base + 0x00000039 * 0x00000004
  #define btrf_pll_reg79                                 (*(volatile unsigned int *)btrf_pll_reg79_adr)
  #define btrf_pll_reg7A_adr                             0x006005e8                                                   // pll_adr_base + 0x0000003a * 0x00000004
  #define btrf_pll_reg7A                                 (*(volatile unsigned int *)btrf_pll_reg7A_adr)
  #define btrf_pll_reg7B_adr                             0x006005ec                                                   // pll_adr_base + 0x0000003b * 0x00000004
  #define btrf_pll_reg7B                                 (*(volatile unsigned int *)btrf_pll_reg7B_adr)
  #define btrf_pll_reg7C_adr                             0x006005f0                                                   // pll_adr_base + 0x0000003c * 0x00000004
  #define btrf_pll_reg7C                                 (*(volatile unsigned int *)btrf_pll_reg7C_adr)
  #define btrf_pll_reg7D_adr                             0x006005f4                                                   // pll_adr_base + 0x0000003d * 0x00000004
  #define btrf_pll_reg7D                                 (*(volatile unsigned int *)btrf_pll_reg7D_adr)
  #define btrf_pll_reg7E_adr                             0x006005f8                                                   // pll_adr_base + 0x0000003e * 0x00000004
  #define btrf_pll_reg7E                                 (*(volatile unsigned int *)btrf_pll_reg7E_adr)
  #define btrf_pll_reg7F_adr                             0x006005fc                                                   // pll_adr_base + 0x0000003f * 0x00000004
  #define btrf_pll_reg7F                                 (*(volatile unsigned int *)btrf_pll_reg7F_adr)
  #define btrf_tx_reg80_adr                              0x00600600                                                   // tx_adr_base + 0x00000000 * 0x00000004
  #define btrf_tx_reg80                                  (*(volatile unsigned int *)btrf_tx_reg80_adr)
  #define btrf_tx_reg81_adr                              0x00600604                                                   // tx_adr_base + 0x00000001 * 0x00000004
  #define btrf_tx_reg81                                  (*(volatile unsigned int *)btrf_tx_reg81_adr)
  #define btrf_tx_reg82_adr                              0x00600608                                                   // tx_adr_base + 0x00000002 * 0x00000004
  #define btrf_tx_reg82                                  (*(volatile unsigned int *)btrf_tx_reg82_adr)
  #define btrf_tx_reg83_adr                              0x0060060c                                                   // tx_adr_base + 0x00000003 * 0x00000004
  #define btrf_tx_reg83                                  (*(volatile unsigned int *)btrf_tx_reg83_adr)
  #define btrf_tx_reg84_adr                              0x00600610                                                   // tx_adr_base + 0x00000004 * 0x00000004
  #define btrf_tx_reg84                                  (*(volatile unsigned int *)btrf_tx_reg84_adr)
  #define btrf_tx_reg85_adr                              0x00600614                                                   // tx_adr_base + 0x00000005 * 0x00000004
  #define btrf_tx_reg85                                  (*(volatile unsigned int *)btrf_tx_reg85_adr)
  #define btrf_tx_reg86_adr                              0x00600618                                                   // tx_adr_base + 0x00000006 * 0x00000004
  #define btrf_tx_reg86                                  (*(volatile unsigned int *)btrf_tx_reg86_adr)
  #define btrf_tx_reg87_adr                              0x0060061c                                                   // tx_adr_base + 0x00000007 * 0x00000004
  #define btrf_tx_reg87                                  (*(volatile unsigned int *)btrf_tx_reg87_adr)
  #define btrf_tx_reg88_adr                              0x00600620                                                   // tx_adr_base + 0x00000008 * 0x00000004
  #define btrf_tx_reg88                                  (*(volatile unsigned int *)btrf_tx_reg88_adr)
  #define btrf_tx_reg89_adr                              0x00600624                                                   // tx_adr_base + 0x00000009 * 0x00000004
  #define btrf_tx_reg89                                  (*(volatile unsigned int *)btrf_tx_reg89_adr)
  #define btrf_tx_reg8A_adr                              0x00600628                                                   // tx_adr_base + 0x0000000a * 0x00000004
  #define btrf_tx_reg8A                                  (*(volatile unsigned int *)btrf_tx_reg8A_adr)
  #define btrf_tx_reg8B_adr                              0x0060062c                                                   // tx_adr_base + 0x0000000b * 0x00000004
  #define btrf_tx_reg8B                                  (*(volatile unsigned int *)btrf_tx_reg8B_adr)
  #define btrf_tx_reg8C_adr                              0x00600630                                                   // tx_adr_base + 0x0000000c * 0x00000004
  #define btrf_tx_reg8C                                  (*(volatile unsigned int *)btrf_tx_reg8C_adr)
  #define btrf_tx_reg8D_adr                              0x00600634                                                   // tx_adr_base + 0x0000000d * 0x00000004
  #define btrf_tx_reg8D                                  (*(volatile unsigned int *)btrf_tx_reg8D_adr)
  #define btrf_tx_reg8E_adr                              0x00600638                                                   // tx_adr_base + 0x0000000e * 0x00000004
  #define btrf_tx_reg8E                                  (*(volatile unsigned int *)btrf_tx_reg8E_adr)
  #define btrf_tx_reg8F_adr                              0x0060063c                                                   // tx_adr_base + 0x0000000f * 0x00000004
  #define btrf_tx_reg8F                                  (*(volatile unsigned int *)btrf_tx_reg8F_adr)
  #define btrf_tx_reg90_adr                              0x00600640                                                   // tx_adr_base + 0x00000010 * 0x00000004
  #define btrf_tx_reg90                                  (*(volatile unsigned int *)btrf_tx_reg90_adr)
  #define btrf_tx_reg91_adr                              0x00600644                                                   // tx_adr_base + 0x00000011 * 0x00000004
  #define btrf_tx_reg91                                  (*(volatile unsigned int *)btrf_tx_reg91_adr)
  #define btrf_tx_reg92_adr                              0x00600648                                                   // tx_adr_base + 0x00000012 * 0x00000004
  #define btrf_tx_reg92                                  (*(volatile unsigned int *)btrf_tx_reg92_adr)
  #define btrf_tx_reg93_adr                              0x0060064c                                                   // tx_adr_base + 0x00000013 * 0x00000004
  #define btrf_tx_reg93                                  (*(volatile unsigned int *)btrf_tx_reg93_adr)
  #define btrf_misc_regC0_adr                            0x00600700                                                   // misc_adr_base + 0x00000000 * 0x00000004
  #define btrf_misc_regC0                                (*(volatile unsigned int *)btrf_misc_regC0_adr)
  #define btrf_misc_regC1_adr                            0x00600704                                                   // misc_adr_base + 0x00000001 * 0x00000004
  #define btrf_misc_regC1                                (*(volatile unsigned int *)btrf_misc_regC1_adr)
  #define btrf_misc_regC2_adr                            0x00600708                                                   // misc_adr_base + 0x00000002 * 0x00000004
  #define btrf_misc_regC2                                (*(volatile unsigned int *)btrf_misc_regC2_adr)
  #define btrf_misc_regC3_adr                            0x0060070c                                                   // misc_adr_base + 0x00000003 * 0x00000004
  #define btrf_misc_regC3                                (*(volatile unsigned int *)btrf_misc_regC3_adr)
  #define btrf_misc_regC4_adr                            0x00600710                                                   // misc_adr_base + 0x00000004 * 0x00000004
  #define btrf_misc_regC4                                (*(volatile unsigned int *)btrf_misc_regC4_adr)
  #define btrf_misc_regC5_adr                            0x00600714                                                   // misc_adr_base + 0x00000005 * 0x00000004
  #define btrf_misc_regC5                                (*(volatile unsigned int *)btrf_misc_regC5_adr)
  #define btrf_misc_regC6_adr                            0x00600718                                                   // misc_adr_base + 0x00000006 * 0x00000004
  #define btrf_misc_regC6                                (*(volatile unsigned int *)btrf_misc_regC6_adr)
  #define btrf_misc_regC7_adr                            0x0060071c                                                   // misc_adr_base + 0x00000007 * 0x00000004
  #define btrf_misc_regC7                                (*(volatile unsigned int *)btrf_misc_regC7_adr)
  #define btrf_misc_regC8_adr                            0x00600720                                                   // misc_adr_base + 0x00000008 * 0x00000004
  #define btrf_misc_regC8                                (*(volatile unsigned int *)btrf_misc_regC8_adr)
  #define btrf_misc_regC9_adr                            0x00600724                                                   // misc_adr_base + 0x00000009 * 0x00000004
  #define btrf_misc_regC9                                (*(volatile unsigned int *)btrf_misc_regC9_adr)
  #define btrf_misc_regCA_adr                            0x00600728                                                   // misc_adr_base + 0x0000000a * 0x00000004
  #define btrf_misc_regCA                                (*(volatile unsigned int *)btrf_misc_regCA_adr)
  #define btrf_misc_regCB_adr                            0x0060072c                                                   // misc_adr_base + 0x0000000b * 0x00000004
  #define btrf_misc_regCB                                (*(volatile unsigned int *)btrf_misc_regCB_adr)
  #define btrf_misc_regCC_adr                            0x00600730                                                   // misc_adr_base + 0x0000000c * 0x00000004
  #define btrf_misc_regCC                                (*(volatile unsigned int *)btrf_misc_regCC_adr)
  #define btrf_misc_regCD_adr                            0x00600734                                                   // misc_adr_base + 0x0000000d * 0x00000004
  #define btrf_misc_regCD                                (*(volatile unsigned int *)btrf_misc_regCD_adr)
  #define btrf_misc_regCE_adr                            0x00600738                                                   // misc_adr_base + 0x0000000e * 0x00000004
  #define btrf_misc_regCE                                (*(volatile unsigned int *)btrf_misc_regCE_adr)
  #define btrf_misc_regCF_adr                            0x0060073c                                                   // misc_adr_base + 0x0000000f * 0x00000004
  #define btrf_misc_regCF                                (*(volatile unsigned int *)btrf_misc_regCF_adr)
  #define btrf_misc_regD0_adr                            0x00600740                                                   // misc_adr_base + 0x00000010 * 0x00000004
  #define btrf_misc_regD0                                (*(volatile unsigned int *)btrf_misc_regD0_adr)
  #define btrf_misc_regD1_adr                            0x00600744                                                   // misc_adr_base + 0x00000011 * 0x00000004
  #define btrf_misc_regD1                                (*(volatile unsigned int *)btrf_misc_regD1_adr)
  #define btrf_misc_regD2_adr                            0x00600748                                                   // misc_adr_base + 0x00000012 * 0x00000004
  #define btrf_misc_regD2                                (*(volatile unsigned int *)btrf_misc_regD2_adr)
  #define btrf_misc_regD3_adr                            0x0060074c                                                   // misc_adr_base + 0x00000013 * 0x00000004
  #define btrf_misc_regD3                                (*(volatile unsigned int *)btrf_misc_regD3_adr)
  #define btrf_misc_regD4_adr                            0x00600750                                                   // misc_adr_base + 0x00000014 * 0x00000004
  #define btrf_misc_regD4                                (*(volatile unsigned int *)btrf_misc_regD4_adr)
  #define btrf_misc_regD5_adr                            0x00600754                                                   // misc_adr_base + 0x00000015 * 0x00000004
  #define btrf_misc_regD5                                (*(volatile unsigned int *)btrf_misc_regD5_adr)
  #define btrf_misc_regD6_adr                            0x00600758                                                   // misc_adr_base + 0x00000016 * 0x00000004
  #define btrf_misc_regD6                                (*(volatile unsigned int *)btrf_misc_regD6_adr)
  #define btrf_misc_regD7_adr                            0x0060075c                                                   // misc_adr_base + 0x00000017 * 0x00000004
  #define btrf_misc_regD7                                (*(volatile unsigned int *)btrf_misc_regD7_adr)
  #define btrf_misc_regD8_adr                            0x00600760                                                   // misc_adr_base + 0x00000018 * 0x00000004
  #define btrf_misc_regD8                                (*(volatile unsigned int *)btrf_misc_regD8_adr)
  #define btrf_misc_regD9_adr                            0x00600764                                                   // misc_adr_base + 0x00000019 * 0x00000004
  #define btrf_misc_regD9                                (*(volatile unsigned int *)btrf_misc_regD9_adr)
  #define btrf_misc_regDA_adr                            0x00600768                                                   // misc_adr_base + 0x0000001a * 0x00000004
  #define btrf_misc_regDA                                (*(volatile unsigned int *)btrf_misc_regDA_adr)
  #define btrf_misc_regDB_adr                            0x0060076c                                                   // misc_adr_base + 0x0000001b * 0x00000004
  #define btrf_misc_regDB                                (*(volatile unsigned int *)btrf_misc_regDB_adr)
  #define btrf_misc_regDC_adr                            0x00600770                                                   // misc_adr_base + 0x0000001c * 0x00000004
  #define btrf_misc_regDC                                (*(volatile unsigned int *)btrf_misc_regDC_adr)
  #define btrf_misc_regDD_adr                            0x00600774                                                   // misc_adr_base + 0x0000001d * 0x00000004
  #define btrf_misc_regDD                                (*(volatile unsigned int *)btrf_misc_regDD_adr)
  #define btrf_misc_regDE_adr                            0x00600778                                                   // misc_adr_base + 0x0000001e * 0x00000004
  #define btrf_misc_regDE                                (*(volatile unsigned int *)btrf_misc_regDE_adr)
  #define btrf_misc_regDF_adr                            0x0060077c                                                   // misc_adr_base + 0x0000001f * 0x00000004
  #define btrf_misc_regDF                                (*(volatile unsigned int *)btrf_misc_regDF_adr)
  #define btrf_misc_regE0_adr                            0x00600780                                                   // misc_adr_base + 0x00000020 * 0x00000004
  #define btrf_misc_regE0                                (*(volatile unsigned int *)btrf_misc_regE0_adr)
  #define btrf_misc_regE1_adr                            0x00600784                                                   // misc_adr_base + 0x00000021 * 0x00000004
  #define btrf_misc_regE1                                (*(volatile unsigned int *)btrf_misc_regE1_adr)
  #define btrf_misc_regE2_adr                            0x00600788                                                   // misc_adr_base + 0x00000022 * 0x00000004
  #define btrf_misc_regE2                                (*(volatile unsigned int *)btrf_misc_regE2_adr)
  #define btrf_misc_regE3_adr                            0x0060078c                                                   // misc_adr_base + 0x00000023 * 0x00000004
  #define btrf_misc_regE3                                (*(volatile unsigned int *)btrf_misc_regE3_adr)
  #define btrf_misc_regE4_adr                            0x00600790                                                   // misc_adr_base + 0x00000024 * 0x00000004
  #define btrf_misc_regE4                                (*(volatile unsigned int *)btrf_misc_regE4_adr)
  #define btrf_misc_regE5_adr                            0x00600794                                                   // misc_adr_base + 0x00000025 * 0x00000004
  #define btrf_misc_regE5                                (*(volatile unsigned int *)btrf_misc_regE5_adr)
  #define btrf_misc_regE6_adr                            0x00600798                                                   // misc_adr_base + 0x00000026 * 0x00000004
  #define btrf_misc_regE6                                (*(volatile unsigned int *)btrf_misc_regE6_adr)
  #define btrf_misc_regE7_adr                            0x0060079c                                                   // misc_adr_base + 0x00000027 * 0x00000004
  #define btrf_misc_regE7                                (*(volatile unsigned int *)btrf_misc_regE7_adr)
  #define btrf_misc_regE8_adr                            0x006007a0                                                   // misc_adr_base + 0x00000028 * 0x00000004
  #define btrf_misc_regE8                                (*(volatile unsigned int *)btrf_misc_regE8_adr)
  #define btrf_misc_regE9_adr                            0x006007a4                                                   // misc_adr_base + 0x00000029 * 0x00000004
  #define btrf_misc_regE9                                (*(volatile unsigned int *)btrf_misc_regE9_adr)
  #define btrf_misc_regEA_adr                            0x006007a8                                                   // misc_adr_base + 0x0000002a * 0x00000004
  #define btrf_misc_regEA                                (*(volatile unsigned int *)btrf_misc_regEA_adr)
  #define btrf_misc_regEB_adr                            0x006007ac                                                   // misc_adr_base + 0x0000002b * 0x00000004
  #define btrf_misc_regEB                                (*(volatile unsigned int *)btrf_misc_regEB_adr)
  #define btrf_misc_regEC_adr                            0x006007b0                                                   // misc_adr_base + 0x0000002c * 0x00000004
  #define btrf_misc_regEC                                (*(volatile unsigned int *)btrf_misc_regEC_adr)
  #define btrf_misc_regED_adr                            0x006007b4                                                   // misc_adr_base + 0x0000002d * 0x00000004
  #define btrf_misc_regED                                (*(volatile unsigned int *)btrf_misc_regED_adr)
  #define btrf_misc_regEE_adr                            0x006007b8                                                   // misc_adr_base + 0x0000002e * 0x00000004
  #define btrf_misc_regEE                                (*(volatile unsigned int *)btrf_misc_regEE_adr)
  #define btrf_misc_regEF_adr                            0x006007bc                                                   // misc_adr_base + 0x0000002f * 0x00000004
  #define btrf_misc_regEF                                (*(volatile unsigned int *)btrf_misc_regEF_adr)
  #define btrf_misc_regF0_adr                            0x006007c0                                                   // misc_adr_base + 0x00000030 * 0x00000004
  #define btrf_misc_regF0                                (*(volatile unsigned int *)btrf_misc_regF0_adr)
  #define btrf_misc_regF1_adr                            0x006007c4                                                   // misc_adr_base + 0x00000031 * 0x00000004
  #define btrf_misc_regF1                                (*(volatile unsigned int *)btrf_misc_regF1_adr)
  #define btrf_misc_regF2_adr                            0x006007c8                                                   // misc_adr_base + 0x00000032 * 0x00000004
  #define btrf_misc_regF2                                (*(volatile unsigned int *)btrf_misc_regF2_adr)
  #define btrf_misc_regF3_adr                            0x006007cc                                                   // misc_adr_base + 0x00000033 * 0x00000004
  #define btrf_misc_regF3                                (*(volatile unsigned int *)btrf_misc_regF3_adr)
  #define btrf_misc_regF4_adr                            0x006007d0                                                   // misc_adr_base + 0x00000034 * 0x00000004
  #define btrf_misc_regF4                                (*(volatile unsigned int *)btrf_misc_regF4_adr)
  #define btrf_misc_regF5_adr                            0x006007d4                                                   // misc_adr_base + 0x00000035 * 0x00000004
  #define btrf_misc_regF5                                (*(volatile unsigned int *)btrf_misc_regF5_adr)
  #define btrf_misc_regF6_adr                            0x006007d8                                                   // misc_adr_base + 0x00000036 * 0x00000004
  #define btrf_misc_regF6                                (*(volatile unsigned int *)btrf_misc_regF6_adr)
  #define btrf_misc_regF7_adr                            0x006007dc                                                   // misc_adr_base + 0x00000037 * 0x00000004
  #define btrf_misc_regF7                                (*(volatile unsigned int *)btrf_misc_regF7_adr)
  #define btrf_misc_regF8_adr                            0x006007e0                                                   // misc_adr_base + 0x00000038 * 0x00000004
  #define btrf_misc_regF8                                (*(volatile unsigned int *)btrf_misc_regF8_adr)
  #define btrf_misc_regF9_adr                            0x006007e4                                                   // misc_adr_base + 0x00000039 * 0x00000004
  #define btrf_misc_regF9                                (*(volatile unsigned int *)btrf_misc_regF9_adr)
  #define btrf_misc_regFA_adr                            0x006007e8                                                   // misc_adr_base + 0x0000003a * 0x00000004
  #define btrf_misc_regFA                                (*(volatile unsigned int *)btrf_misc_regFA_adr)
  #define btrf_misc_regFB_adr                            0x006007ec                                                   // misc_adr_base + 0x0000003b * 0x00000004
  #define btrf_misc_regFB                                (*(volatile unsigned int *)btrf_misc_regFB_adr)
  #define btrf_misc_regFC_adr                            0x006007f0                                                   // misc_adr_base + 0x0000003c * 0x00000004
  #define btrf_misc_regFC                                (*(volatile unsigned int *)btrf_misc_regFC_adr)
  #define btrf_misc_regFD_adr                            0x006007f4                                                   // misc_adr_base + 0x0000003d * 0x00000004
  #define btrf_misc_regFD                                (*(volatile unsigned int *)btrf_misc_regFD_adr)
  #define btrf_misc_regFE_adr                            0x006007f8                                                   // misc_adr_base + 0x0000003e * 0x00000004
  #define btrf_misc_regFE                                (*(volatile unsigned int *)btrf_misc_regFE_adr)
  #define btrf_misc_regFF_adr                            0x006007fc                                                   // misc_adr_base + 0x0000003f * 0x00000004
  #define btrf_misc_regFF                                (*(volatile unsigned int *)btrf_misc_regFF_adr)
  #define btrf_bs_reg1_adr                               0x00600650                                                   // bs_adr_base + 0x00000001 * 0x00000004
  #define btrf_bs_reg1                                   (*(volatile unsigned int *)btrf_bs_reg1_adr)
  #define btrf_bs_reg2_adr                               0x00600654                                                   // bs_adr_base + 0x00000002 * 0x00000004
  #define btrf_bs_reg2                                   (*(volatile unsigned int *)btrf_bs_reg2_adr)
  #define btrf_bs_reg3_adr                               0x00600658                                                   // bs_adr_base + 0x00000003 * 0x00000004
  #define btrf_bs_reg3                                   (*(volatile unsigned int *)btrf_bs_reg3_adr)
  #define btrf_bs_reg4_adr                               0x0060065c                                                   // bs_adr_base + 0x00000004 * 0x00000004
  #define btrf_bs_reg4                                   (*(volatile unsigned int *)btrf_bs_reg4_adr)
  #define btrf_bs_reg5_adr                               0x00600660                                                   // bs_adr_base + 0x00000005 * 0x00000004
  #define btrf_bs_reg5                                   (*(volatile unsigned int *)btrf_bs_reg5_adr)
  #define btrf_bs_reg6_adr                               0x00600664                                                   // bs_adr_base + 0x00000006 * 0x00000004
  #define btrf_bs_reg6                                   (*(volatile unsigned int *)btrf_bs_reg6_adr)
  #define btrf_bs_reg7_adr                               0x00600668                                                   // bs_adr_base + 0x00000007 * 0x00000004
  #define btrf_bs_reg7                                   (*(volatile unsigned int *)btrf_bs_reg7_adr)
  #define btrf_bs_reg8_adr                               0x0060066c                                                   // bs_adr_base + 0x00000008 * 0x00000004
  #define btrf_bs_reg8                                   (*(volatile unsigned int *)btrf_bs_reg8_adr)
  #define btrf_bs_reg9_adr                               0x00600670                                                   // bs_adr_base + 0x00000009 * 0x00000004
  #define btrf_bs_reg9                                   (*(volatile unsigned int *)btrf_bs_reg9_adr)
  #define btrf_bs_reg10_adr                              0x00600674                                                   // bs_adr_base + 0x0000000a * 0x00000004
  #define btrf_bs_reg10                                  (*(volatile unsigned int *)btrf_bs_reg10_adr)
  #define btrf_bs_reg11_adr                              0x00600678                                                   // bs_adr_base + 0x0000000b * 0x00000004
  #define btrf_bs_reg11                                  (*(volatile unsigned int *)btrf_bs_reg11_adr)
  #define btrf_bs_reg12_adr                              0x0060067c                                                   // bs_adr_base + 0x0000000c * 0x00000004
  #define btrf_bs_reg12                                  (*(volatile unsigned int *)btrf_bs_reg12_adr)
  #define btrf_bs_reg13_adr                              0x00600680                                                   // bs_adr_base + 0x0000000d * 0x00000004
  #define btrf_bs_reg13                                  (*(volatile unsigned int *)btrf_bs_reg13_adr)
  #define btrf_bs_reg14_adr                              0x00600684                                                   // bs_adr_base + 0x0000000e * 0x00000004
  #define btrf_bs_reg14                                  (*(volatile unsigned int *)btrf_bs_reg14_adr)
  #define btrf_bs_reg15_adr                              0x00600688                                                   // bs_adr_base + 0x0000000f * 0x00000004
  #define btrf_bs_reg15                                  (*(volatile unsigned int *)btrf_bs_reg15_adr)
  #define btrf_bs_reg16_adr                              0x0060068c                                                   // bs_adr_base + 0x00000010 * 0x00000004
  #define btrf_bs_reg16                                  (*(volatile unsigned int *)btrf_bs_reg16_adr)
  #define btrf_bs_reg17_adr                              0x00600690                                                   // bs_adr_base + 0x00000011 * 0x00000004
  #define btrf_bs_reg17                                  (*(volatile unsigned int *)btrf_bs_reg17_adr)
  #define btrf_bs_reg18_adr                              0x00600694                                                   // bs_adr_base + 0x00000012 * 0x00000004
  #define btrf_bs_reg18                                  (*(volatile unsigned int *)btrf_bs_reg18_adr)
  #define btrf_bs_reg19_adr                              0x00600698                                                   // bs_adr_base + 0x00000013 * 0x00000004
  #define btrf_bs_reg19                                  (*(volatile unsigned int *)btrf_bs_reg19_adr)
  #define btrf_bs_reg20_adr                              0x0060069c                                                   // bs_adr_base + 0x00000014 * 0x00000004
  #define btrf_bs_reg20                                  (*(volatile unsigned int *)btrf_bs_reg20_adr)
  #define btrf_bs_reg21_adr                              0x006006a0                                                   // bs_adr_base + 0x00000015 * 0x00000004
  #define btrf_bs_reg21                                  (*(volatile unsigned int *)btrf_bs_reg21_adr)
  #define btrf_bs_reg22_adr                              0x006006a4                                                   // bs_adr_base + 0x00000016 * 0x00000004
  #define btrf_bs_reg22                                  (*(volatile unsigned int *)btrf_bs_reg22_adr)
  #define btrf_bs_reg23_adr                              0x006006a8                                                   // bs_adr_base + 0x00000017 * 0x00000004
  #define btrf_bs_reg23                                  (*(volatile unsigned int *)btrf_bs_reg23_adr)
  #define btrf_bs_reg24_adr                              0x006006ac                                                   // bs_adr_base + 0x00000018 * 0x00000004
  #define btrf_bs_reg24                                  (*(volatile unsigned int *)btrf_bs_reg24_adr)
  #define btrf_bs_reg25_adr                              0x006006b0                                                   // bs_adr_base + 0x00000019 * 0x00000004
  #define btrf_bs_reg25                                  (*(volatile unsigned int *)btrf_bs_reg25_adr)
  #define btrf_bs_reg26_adr                              0x006006b4                                                   // bs_adr_base + 0x0000001a * 0x00000004
  #define btrf_bs_reg26                                  (*(volatile unsigned int *)btrf_bs_reg26_adr)
  #define btrf_bs_reg27_adr                              0x006006b8                                                   // bs_adr_base + 0x0000001b * 0x00000004
  #define btrf_bs_reg27                                  (*(volatile unsigned int *)btrf_bs_reg27_adr)
  #define btrf_bs_reg28_adr                              0x006006bc                                                   // bs_adr_base + 0x0000001c * 0x00000004
  #define btrf_bs_reg28                                  (*(volatile unsigned int *)btrf_bs_reg28_adr)
  #define btrf_bs_reg29_adr                              0x006006c0                                                   // bs_adr_base + 0x0000001d * 0x00000004
  #define btrf_bs_reg29                                  (*(volatile unsigned int *)btrf_bs_reg29_adr)
  #define btrf_bs_reg30_adr                              0x006006c4                                                   // bs_adr_base + 0x0000001e * 0x00000004
  #define btrf_bs_reg30                                  (*(volatile unsigned int *)btrf_bs_reg30_adr)
  #define btrf_bs_reg31_adr                              0x006006c8                                                   // bs_adr_base + 0x0000001f * 0x00000004
  #define btrf_bs_reg31                                  (*(volatile unsigned int *)btrf_bs_reg31_adr)
  #define btrf_bs_reg32_adr                              0x006006cc                                                   // bs_adr_base + 0x00000020 * 0x00000004
  #define btrf_bs_reg32                                  (*(volatile unsigned int *)btrf_bs_reg32_adr)
  #define btrf_bs_reg33_adr                              0x006006d0                                                   // bs_adr_base + 0x00000021 * 0x00000004
  #define btrf_bs_reg33                                  (*(volatile unsigned int *)btrf_bs_reg33_adr)
  #define btrf_bs_reg34_adr                              0x006006d4                                                   // bs_adr_base + 0x00000022 * 0x00000004
  #define btrf_bs_reg34                                  (*(volatile unsigned int *)btrf_bs_reg34_adr)
  #define btrf_bs_reg35_adr                              0x006006d8                                                   // bs_adr_base + 0x00000023 * 0x00000004
  #define btrf_bs_reg35                                  (*(volatile unsigned int *)btrf_bs_reg35_adr)
  #define btrf_bs_reg36_adr                              0x006006dc                                                   // bs_adr_base + 0x00000024 * 0x00000004
  #define btrf_bs_reg36                                  (*(volatile unsigned int *)btrf_bs_reg36_adr)
  #define btrf_bs_reg37_adr                              0x006006e0                                                   // bs_adr_base + 0x00000025 * 0x00000004
  #define btrf_bs_reg37                                  (*(volatile unsigned int *)btrf_bs_reg37_adr)
  #define btrf_bs_reg38_adr                              0x006006e4                                                   // bs_adr_base + 0x00000026 * 0x00000004
  #define btrf_bs_reg38                                  (*(volatile unsigned int *)btrf_bs_reg38_adr)
  #define btrf_bs_reg39_adr                              0x006006e8                                                   // bs_adr_base + 0x00000027 * 0x00000004
  #define btrf_bs_reg39                                  (*(volatile unsigned int *)btrf_bs_reg39_adr)
  #define btrf_bs_reg40_adr                              0x006006ec                                                   // bs_adr_base + 0x00000028 * 0x00000004
  #define btrf_bs_reg40                                  (*(volatile unsigned int *)btrf_bs_reg40_adr)
  #define btrf_bs_reg41_adr                              0x006006f0                                                   // bs_adr_base + 0x00000029 * 0x00000004
  #define btrf_bs_reg41                                  (*(volatile unsigned int *)btrf_bs_reg41_adr)
  #define btrf_bs_reg42_adr                              0x006006f4                                                   // bs_adr_base + 0x0000002a * 0x00000004
  #define btrf_bs_reg42                                  (*(volatile unsigned int *)btrf_bs_reg42_adr)
  #define btrf_bs_reg43_adr                              0x006006f8                                                   // bs_adr_base + 0x0000002b * 0x00000004
  #define btrf_bs_reg43                                  (*(volatile unsigned int *)btrf_bs_reg43_adr)
  #define fmrf_rx_adr_base                               0x00327600                                                   // fmrf_adr_base + 0x00000000
  #define fmrf_dpll_adr_base                             0x00327700                                                   // fmrf_adr_base + 0x00000100
  #define fm_adc_reg3_adr                                0x0032760c                                                   // fmrf_rx_adr_base + 0x00000003 * 0x00000004
  #define fm_adc_reg3                                    (*(volatile unsigned int *)fm_adc_reg3_adr)
  #define fm_adc_reg4_adr                                0x00327610                                                   // fmrf_rx_adr_base + 0x00000004 * 0x00000004
  #define fm_adc_reg4                                    (*(volatile unsigned int *)fm_adc_reg4_adr)
  #define fm_adc_reg5_adr                                0x00327614                                                   // fmrf_rx_adr_base + 0x00000005 * 0x00000004
  #define fm_adc_reg5                                    (*(volatile unsigned int *)fm_adc_reg5_adr)
  #define fm_adc_reg6_adr                                0x00327618                                                   // fmrf_rx_adr_base + 0x00000006 * 0x00000004
  #define fm_adc_reg6                                    (*(volatile unsigned int *)fm_adc_reg6_adr)
  #define fm_adc_reg7_adr                                0x0032761c                                                   // fmrf_rx_adr_base + 0x00000007 * 0x00000004
  #define fm_adc_reg7                                    (*(volatile unsigned int *)fm_adc_reg7_adr)
  #define fm_adc_reg8_adr                                0x00327620                                                   // fmrf_rx_adr_base + 0x00000008 * 0x00000004
  #define fm_adc_reg8                                    (*(volatile unsigned int *)fm_adc_reg8_adr)
  #define fm_adc_reg9_adr                                0x00327624                                                   // fmrf_rx_adr_base + 0x00000009 * 0x00000004
  #define fm_adc_reg9                                    (*(volatile unsigned int *)fm_adc_reg9_adr)
  #define fm_adc_regA_adr                                0x00327628                                                   // fmrf_rx_adr_base + 0x0000000a * 0x00000004
  #define fm_adc_regA                                    (*(volatile unsigned int *)fm_adc_regA_adr)
  #define fm_adc_regB_adr                                0x0032762c                                                   // fmrf_rx_adr_base + 0x0000000b * 0x00000004
  #define fm_adc_regB                                    (*(volatile unsigned int *)fm_adc_regB_adr)
  #define fm_adc_regC_adr                                0x00327630                                                   // fmrf_rx_adr_base + 0x0000000c * 0x00000004
  #define fm_adc_regC                                    (*(volatile unsigned int *)fm_adc_regC_adr)
  #define fm_adc_regD_adr                                0x00327634                                                   // fmrf_rx_adr_base + 0x0000000d * 0x00000004
  #define fm_adc_regD                                    (*(volatile unsigned int *)fm_adc_regD_adr)
  #define fm_adc_regE_adr                                0x00327638                                                   // fmrf_rx_adr_base + 0x0000000e * 0x00000004
  #define fm_adc_regE                                    (*(volatile unsigned int *)fm_adc_regE_adr)
  #define fm_adc_regF_adr                                0x0032763c                                                   // fmrf_rx_adr_base + 0x0000000f * 0x00000004
  #define fm_adc_regF                                    (*(volatile unsigned int *)fm_adc_regF_adr)
  #define fm_rf_reg10_adr                                0x00327640                                                   // fmrf_rx_adr_base + 0x00000010 * 0x00000004
  #define fm_rf_reg10                                    (*(volatile unsigned int *)fm_rf_reg10_adr)
  #define fm_rf_reg11_adr                                0x00327644                                                   // fmrf_rx_adr_base + 0x00000011 * 0x00000004
  #define fm_rf_reg11                                    (*(volatile unsigned int *)fm_rf_reg11_adr)
  #define fm_rf_reg12_adr                                0x00327648                                                   // fmrf_rx_adr_base + 0x00000012 * 0x00000004
  #define fm_rf_reg12                                    (*(volatile unsigned int *)fm_rf_reg12_adr)
  #define fm_rf_reg13_adr                                0x0032764c                                                   // fmrf_rx_adr_base + 0x00000013 * 0x00000004
  #define fm_rf_reg13                                    (*(volatile unsigned int *)fm_rf_reg13_adr)
  #define fm_rf_reg14_adr                                0x00327650                                                   // fmrf_rx_adr_base + 0x00000014 * 0x00000004
  #define fm_rf_reg14                                    (*(volatile unsigned int *)fm_rf_reg14_adr)
  #define fm_rssi_lna_reg15_adr                          0x00327654                                                   // fmrf_rx_adr_base + 0x00000015 * 0x00000004
  #define fm_rssi_lna_reg15                              (*(volatile unsigned int *)fm_rssi_lna_reg15_adr)
  #define fm_rssi_lna_reg16_adr                          0x00327658                                                   // fmrf_rx_adr_base + 0x00000016 * 0x00000004
  #define fm_rssi_lna_reg16                              (*(volatile unsigned int *)fm_rssi_lna_reg16_adr)
  #define fm_rssi_lna_reg17_adr                          0x0032765c                                                   // fmrf_rx_adr_base + 0x00000017 * 0x00000004
  #define fm_rssi_lna_reg17                              (*(volatile unsigned int *)fm_rssi_lna_reg17_adr)
  #define fm_rssi_lna_reg18_adr                          0x00327660                                                   // fmrf_rx_adr_base + 0x00000018 * 0x00000004
  #define fm_rssi_lna_reg18                              (*(volatile unsigned int *)fm_rssi_lna_reg18_adr)
  #define fm_rssi_lna_reg19_adr                          0x00327664                                                   // fmrf_rx_adr_base + 0x00000019 * 0x00000004
  #define fm_rssi_lna_reg19                              (*(volatile unsigned int *)fm_rssi_lna_reg19_adr)
  #define fm_rssi_tia_reg1A_adr                          0x00327668                                                   // fmrf_rx_adr_base + 0x0000001a * 0x00000004
  #define fm_rssi_tia_reg1A                              (*(volatile unsigned int *)fm_rssi_tia_reg1A_adr)
  #define fm_rssi_tia_reg1B_adr                          0x0032766c                                                   // fmrf_rx_adr_base + 0x0000001b * 0x00000004
  #define fm_rssi_tia_reg1B                              (*(volatile unsigned int *)fm_rssi_tia_reg1B_adr)
  #define fm_rssi_tia_reg1C_adr                          0x00327670                                                   // fmrf_rx_adr_base + 0x0000001c * 0x00000004
  #define fm_rssi_tia_reg1C                              (*(volatile unsigned int *)fm_rssi_tia_reg1C_adr)
  #define fm_rssi_tia_reg1D_adr                          0x00327674                                                   // fmrf_rx_adr_base + 0x0000001d * 0x00000004
  #define fm_rssi_tia_reg1D                              (*(volatile unsigned int *)fm_rssi_tia_reg1D_adr)
  #define fm_rssi_tia_reg1E_adr                          0x00327678                                                   // fmrf_rx_adr_base + 0x0000001e * 0x00000004
  #define fm_rssi_tia_reg1E                              (*(volatile unsigned int *)fm_rssi_tia_reg1E_adr)
  #define fm_bg_reg1F_adr                                0x0032767c                                                   // fmrf_rx_adr_base + 0x0000001f * 0x00000004
  #define fm_bg_reg1F                                    (*(volatile unsigned int *)fm_bg_reg1F_adr)
  #define fm_bg_reg20_adr                                0x00327680                                                   // fmrf_rx_adr_base + 0x00000020 * 0x00000004
  #define fm_bg_reg20                                    (*(volatile unsigned int *)fm_bg_reg20_adr)
  #define fm_bg_reg21_adr                                0x00327684                                                   // fmrf_rx_adr_base + 0x00000021 * 0x00000004
  #define fm_bg_reg21                                    (*(volatile unsigned int *)fm_bg_reg21_adr)
  #define fm_bg_reg22_adr                                0x00327688                                                   // fmrf_rx_adr_base + 0x00000022 * 0x00000004
  #define fm_bg_reg22                                    (*(volatile unsigned int *)fm_bg_reg22_adr)
  #define fm_bg_reg23_adr                                0x0032768c                                                   // fmrf_rx_adr_base + 0x00000023 * 0x00000004
  #define fm_bg_reg23                                    (*(volatile unsigned int *)fm_bg_reg23_adr)
  #define fm_bg_reg24_adr                                0x00327690                                                   // fmrf_rx_adr_base + 0x00000024 * 0x00000004
  #define fm_bg_reg24                                    (*(volatile unsigned int *)fm_bg_reg24_adr)
  #define fm_bg_reg27_adr                                0x0032769c                                                   // fmrf_rx_adr_base + 0x00000027 * 0x00000004
  #define fm_bg_reg27                                    (*(volatile unsigned int *)fm_bg_reg27_adr)
  #define fm_tiabuf_reg25_adr                            0x00327694                                                   // fmrf_rx_adr_base + 0x00000025 * 0x00000004
  #define fm_tiabuf_reg25                                (*(volatile unsigned int *)fm_tiabuf_reg25_adr)
  #define fm_tiabuf_reg26_adr                            0x00327698                                                   // fmrf_rx_adr_base + 0x00000026 * 0x00000004
  #define fm_tiabuf_reg26                                (*(volatile unsigned int *)fm_tiabuf_reg26_adr)
  #define fm_adc_reg28_adr                               0x003276a0                                                   // fmrf_rx_adr_base + 0x00000028 * 0x00000004
  #define fm_adc_reg28                                   (*(volatile unsigned int *)fm_adc_reg28_adr)
  #define fm_adc_reg29_adr                               0x003276a4                                                   // fmrf_rx_adr_base + 0x00000029 * 0x00000004
  #define fm_adc_reg29                                   (*(volatile unsigned int *)fm_adc_reg29_adr)
  #define fm_adc_reg2A_adr                               0x003276a8                                                   // fmrf_rx_adr_base + 0x0000002a * 0x00000004
  #define fm_adc_reg2A                                   (*(volatile unsigned int *)fm_adc_reg2A_adr)
  #define fm_adc_reg2B_adr                               0x003276ac                                                   // fmrf_rx_adr_base + 0x0000002b * 0x00000004
  #define fm_adc_reg2B                                   (*(volatile unsigned int *)fm_adc_reg2B_adr)
  #define fm_adc_reg2C_adr                               0x003276b0                                                   // fmrf_rx_adr_base + 0x0000002c * 0x00000004
  #define fm_adc_reg2C                                   (*(volatile unsigned int *)fm_adc_reg2C_adr)
  #define fm_adc_reg2D_adr                               0x003276b4                                                   // fmrf_rx_adr_base + 0x0000002d * 0x00000004
  #define fm_adc_reg2D                                   (*(volatile unsigned int *)fm_adc_reg2D_adr)
  #define fm_adc_reg2E_adr                               0x003276b8                                                   // fmrf_rx_adr_base + 0x0000002e * 0x00000004
  #define fm_adc_reg2E                                   (*(volatile unsigned int *)fm_adc_reg2E_adr)
  #define fm_adc_reg2F_adr                               0x003276bc                                                   // fmrf_rx_adr_base + 0x0000002f * 0x00000004
  #define fm_adc_reg2F                                   (*(volatile unsigned int *)fm_adc_reg2F_adr)
  #define fm_adc_reg30_adr                               0x003276c0                                                   // fmrf_rx_adr_base + 0x00000030 * 0x00000004
  #define fm_adc_reg30                                   (*(volatile unsigned int *)fm_adc_reg30_adr)
  #define fm_adc_reg31_adr                               0x003276c4                                                   // fmrf_rx_adr_base + 0x00000031 * 0x00000004
  #define fm_adc_reg31                                   (*(volatile unsigned int *)fm_adc_reg31_adr)
  #define fm_adc_reg32_adr                               0x003276c8                                                   // fmrf_rx_adr_base + 0x00000032 * 0x00000004
  #define fm_adc_reg32                                   (*(volatile unsigned int *)fm_adc_reg32_adr)
  #define fm_adc_reg33_adr                               0x003276cc                                                   // fmrf_rx_adr_base + 0x00000033 * 0x00000004
  #define fm_adc_reg33                                   (*(volatile unsigned int *)fm_adc_reg33_adr)
  #define fm_adc_reg34_adr                               0x003276d0                                                   // fmrf_rx_adr_base + 0x00000034 * 0x00000004
  #define fm_adc_reg34                                   (*(volatile unsigned int *)fm_adc_reg34_adr)
  #define fm_adc_reg35_adr                               0x003276d4                                                   // fmrf_rx_adr_base + 0x00000035 * 0x00000004
  #define fm_adc_reg35                                   (*(volatile unsigned int *)fm_adc_reg35_adr)
  #define fm_adc_reg36_adr                               0x003276d8                                                   // fmrf_rx_adr_base + 0x00000036 * 0x00000004
  #define fm_adc_reg36                                   (*(volatile unsigned int *)fm_adc_reg36_adr)
  #define fm_adc_reg37_adr                               0x003276dc                                                   // fmrf_rx_adr_base + 0x00000037 * 0x00000004
  #define fm_adc_reg37                                   (*(volatile unsigned int *)fm_adc_reg37_adr)
  #define fm_adc_reg38_adr                               0x003276e0                                                   // fmrf_rx_adr_base + 0x00000038 * 0x00000004
  #define fm_adc_reg38                                   (*(volatile unsigned int *)fm_adc_reg38_adr)
  #define fm_adc_reg39_adr                               0x003276e4                                                   // fmrf_rx_adr_base + 0x00000039 * 0x00000004
  #define fm_adc_reg39                                   (*(volatile unsigned int *)fm_adc_reg39_adr)
  #define fm_adc_reg3A_adr                               0x003276e8                                                   // fmrf_rx_adr_base + 0x0000003a * 0x00000004
  #define fm_adc_reg3A                                   (*(volatile unsigned int *)fm_adc_reg3A_adr)
  #define fm_adc_reg3B_adr                               0x003276ec                                                   // fmrf_rx_adr_base + 0x0000003b * 0x00000004
  #define fm_adc_reg3B                                   (*(volatile unsigned int *)fm_adc_reg3B_adr)
  #define fm_adc_reg3C_adr                               0x003276f0                                                   // fmrf_rx_adr_base + 0x0000003c * 0x00000004
  #define fm_adc_reg3C                                   (*(volatile unsigned int *)fm_adc_reg3C_adr)
  #define fm_adc_reg3D_adr                               0x003276f4                                                   // fmrf_rx_adr_base + 0x0000003d * 0x00000004
  #define fm_adc_reg3D                                   (*(volatile unsigned int *)fm_adc_reg3D_adr)
  #define fm_adc_reg3E_adr                               0x003276f8                                                   // fmrf_rx_adr_base + 0x0000003e * 0x00000004
  #define fm_adc_reg3E                                   (*(volatile unsigned int *)fm_adc_reg3E_adr)
  #define fm_adc_reg3F_adr                               0x003276fc                                                   // fmrf_rx_adr_base + 0x0000003f * 0x00000004
  #define fm_adc_reg3F                                   (*(volatile unsigned int *)fm_adc_reg3F_adr)
  #define fm_dpll_reg40_adr                              0x00327700                                                   // fmrf_dpll_adr_base + 0x00000000 * 0x00000004
  #define fm_dpll_reg40                                  (*(volatile unsigned int *)fm_dpll_reg40_adr)
  #define fm_dpll_reg41_adr                              0x00327704                                                   // fmrf_dpll_adr_base + 0x00000001 * 0x00000004
  #define fm_dpll_reg41                                  (*(volatile unsigned int *)fm_dpll_reg41_adr)
  #define fm_dpll_reg42_adr                              0x00327708                                                   // fmrf_dpll_adr_base + 0x00000002 * 0x00000004
  #define fm_dpll_reg42                                  (*(volatile unsigned int *)fm_dpll_reg42_adr)
  #define fm_dpll_reg43_adr                              0x0032770c                                                   // fmrf_dpll_adr_base + 0x00000003 * 0x00000004
  #define fm_dpll_reg43                                  (*(volatile unsigned int *)fm_dpll_reg43_adr)
  #define fm_dpll_reg44_adr                              0x00327710                                                   // fmrf_dpll_adr_base + 0x00000004 * 0x00000004
  #define fm_dpll_reg44                                  (*(volatile unsigned int *)fm_dpll_reg44_adr)
  #define fm_dpll_reg45_adr                              0x00327714                                                   // fmrf_dpll_adr_base + 0x00000005 * 0x00000004
  #define fm_dpll_reg45                                  (*(volatile unsigned int *)fm_dpll_reg45_adr)
  #define fm_dpll_reg46_adr                              0x00327718                                                   // fmrf_dpll_adr_base + 0x00000006 * 0x00000004
  #define fm_dpll_reg46                                  (*(volatile unsigned int *)fm_dpll_reg46_adr)
  #define fm_dpll_reg47_adr                              0x0032771c                                                   // fmrf_dpll_adr_base + 0x00000007 * 0x00000004
  #define fm_dpll_reg47                                  (*(volatile unsigned int *)fm_dpll_reg47_adr)
  #define fm_dpll_reg48_adr                              0x00327720                                                   // fmrf_dpll_adr_base + 0x00000008 * 0x00000004
  #define fm_dpll_reg48                                  (*(volatile unsigned int *)fm_dpll_reg48_adr)
  #define fm_dpll_reg49_adr                              0x00327724                                                   // fmrf_dpll_adr_base + 0x00000009 * 0x00000004
  #define fm_dpll_reg49                                  (*(volatile unsigned int *)fm_dpll_reg49_adr)
  #define fm_dpll_reg4A_adr                              0x00327728                                                   // fmrf_dpll_adr_base + 0x0000000a * 0x00000004
  #define fm_dpll_reg4A                                  (*(volatile unsigned int *)fm_dpll_reg4A_adr)
  #define fm_dpll_reg4B_adr                              0x0032772c                                                   // fmrf_dpll_adr_base + 0x0000000b * 0x00000004
  #define fm_dpll_reg4B                                  (*(volatile unsigned int *)fm_dpll_reg4B_adr)
  #define fm_dpll_reg4C_adr                              0x00327730                                                   // fmrf_dpll_adr_base + 0x0000000c * 0x00000004
  #define fm_dpll_reg4C                                  (*(volatile unsigned int *)fm_dpll_reg4C_adr)
  #define fm_dpll_reg4D_adr                              0x00327734                                                   // fmrf_dpll_adr_base + 0x0000000d * 0x00000004
  #define fm_dpll_reg4D                                  (*(volatile unsigned int *)fm_dpll_reg4D_adr)
  #define fm_dpll_reg4E_adr                              0x00327738                                                   // fmrf_dpll_adr_base + 0x0000000e * 0x00000004
  #define fm_dpll_reg4E                                  (*(volatile unsigned int *)fm_dpll_reg4E_adr)
  #define fm_dpll_reg4F_adr                              0x0032773c                                                   // fmrf_dpll_adr_base + 0x0000000f * 0x00000004
  #define fm_dpll_reg4F                                  (*(volatile unsigned int *)fm_dpll_reg4F_adr)
  #define fm_dpll_reg50_adr                              0x00327740                                                   // fmrf_dpll_adr_base + 0x00000010 * 0x00000004
  #define fm_dpll_reg50                                  (*(volatile unsigned int *)fm_dpll_reg50_adr)
  #define fm_dpll_reg51_adr                              0x00327744                                                   // fmrf_dpll_adr_base + 0x00000011 * 0x00000004
  #define fm_dpll_reg51                                  (*(volatile unsigned int *)fm_dpll_reg51_adr)
  #define fm_dpll_reg52_adr                              0x00327748                                                   // fmrf_dpll_adr_base + 0x00000012 * 0x00000004
  #define fm_dpll_reg52                                  (*(volatile unsigned int *)fm_dpll_reg52_adr)
  #define fm_dpll_reg53_adr                              0x0032774c                                                   // fmrf_dpll_adr_base + 0x00000013 * 0x00000004
  #define fm_dpll_reg53                                  (*(volatile unsigned int *)fm_dpll_reg53_adr)
  #define fm_dpll_reg54_adr                              0x00327750                                                   // fmrf_dpll_adr_base + 0x00000014 * 0x00000004
  #define fm_dpll_reg54                                  (*(volatile unsigned int *)fm_dpll_reg54_adr)
  #define fm_dpll_reg55_adr                              0x00327754                                                   // fmrf_dpll_adr_base + 0x00000015 * 0x00000004
  #define fm_dpll_reg55                                  (*(volatile unsigned int *)fm_dpll_reg55_adr)
  #define fm_dpll_reg56_adr                              0x00327758                                                   // fmrf_dpll_adr_base + 0x00000016 * 0x00000004
  #define fm_dpll_reg56                                  (*(volatile unsigned int *)fm_dpll_reg56_adr)
  #define fm_dpll_reg57_adr                              0x0032775c                                                   // fmrf_dpll_adr_base + 0x00000017 * 0x00000004
  #define fm_dpll_reg57                                  (*(volatile unsigned int *)fm_dpll_reg57_adr)
  #define fm_dpll_reg58_adr                              0x00327760                                                   // fmrf_dpll_adr_base + 0x00000018 * 0x00000004
  #define fm_dpll_reg58                                  (*(volatile unsigned int *)fm_dpll_reg58_adr)
  #define fm_dpll_reg59_adr                              0x00327764                                                   // fmrf_dpll_adr_base + 0x00000019 * 0x00000004
  #define fm_dpll_reg59                                  (*(volatile unsigned int *)fm_dpll_reg59_adr)
  #define fm_dpll_reg5A_adr                              0x00327768                                                   // fmrf_dpll_adr_base + 0x0000001a * 0x00000004
  #define fm_dpll_reg5A                                  (*(volatile unsigned int *)fm_dpll_reg5A_adr)
  #define fm_dpll_reg5B_adr                              0x0032776c                                                   // fmrf_dpll_adr_base + 0x0000001b * 0x00000004
  #define fm_dpll_reg5B                                  (*(volatile unsigned int *)fm_dpll_reg5B_adr)
  #define fm_dpll_reg5C_adr                              0x00327770                                                   // fmrf_dpll_adr_base + 0x0000001c * 0x00000004
  #define fm_dpll_reg5C                                  (*(volatile unsigned int *)fm_dpll_reg5C_adr)
  #define fm_dpll_reg5D_adr                              0x00327774                                                   // fmrf_dpll_adr_base + 0x0000001d * 0x00000004
  #define fm_dpll_reg5D                                  (*(volatile unsigned int *)fm_dpll_reg5D_adr)
  #define fm_dpll_reg5E_adr                              0x00327778                                                   // fmrf_dpll_adr_base + 0x0000001e * 0x00000004
  #define fm_dpll_reg5E                                  (*(volatile unsigned int *)fm_dpll_reg5E_adr)
  #define fm_dpll_reg5F_adr                              0x0032777c                                                   // fmrf_dpll_adr_base + 0x0000001f * 0x00000004
  #define fm_dpll_reg5F                                  (*(volatile unsigned int *)fm_dpll_reg5F_adr)
  #define fm_dpll_reg60_adr                              0x00327780                                                   // fmrf_dpll_adr_base + 0x00000020 * 0x00000004
  #define fm_dpll_reg60                                  (*(volatile unsigned int *)fm_dpll_reg60_adr)
  #define fm_dpll_reg61_adr                              0x00327784                                                   // fmrf_dpll_adr_base + 0x00000021 * 0x00000004
  #define fm_dpll_reg61                                  (*(volatile unsigned int *)fm_dpll_reg61_adr)
  #define fm_dpll_reg62_adr                              0x00327788                                                   // fmrf_dpll_adr_base + 0x00000022 * 0x00000004
  #define fm_dpll_reg62                                  (*(volatile unsigned int *)fm_dpll_reg62_adr)
  #define fm_dpll_reg63_adr                              0x0032778c                                                   // fmrf_dpll_adr_base + 0x00000023 * 0x00000004
  #define fm_dpll_reg63                                  (*(volatile unsigned int *)fm_dpll_reg63_adr)
  #define fm_dpll_reg64_adr                              0x00327790                                                   // fmrf_dpll_adr_base + 0x00000024 * 0x00000004
  #define fm_dpll_reg64                                  (*(volatile unsigned int *)fm_dpll_reg64_adr)
  #define fm_dpll_reg65_adr                              0x00327794                                                   // fmrf_dpll_adr_base + 0x00000025 * 0x00000004
  #define fm_dpll_reg65                                  (*(volatile unsigned int *)fm_dpll_reg65_adr)
  #define fm_dpll_reg66_adr                              0x00327798                                                   // fmrf_dpll_adr_base + 0x00000026 * 0x00000004
  #define fm_dpll_reg66                                  (*(volatile unsigned int *)fm_dpll_reg66_adr)
  #define fm_dpll_reg67_adr                              0x0032779c                                                   // fmrf_dpll_adr_base + 0x00000027 * 0x00000004
  #define fm_dpll_reg67                                  (*(volatile unsigned int *)fm_dpll_reg67_adr)
  #define fm_dpll_reg68_adr                              0x003277a0                                                   // fmrf_dpll_adr_base + 0x00000028 * 0x00000004
  #define fm_dpll_reg68                                  (*(volatile unsigned int *)fm_dpll_reg68_adr)
  #define fm_dpll_reg69_adr                              0x003277a4                                                   // fmrf_dpll_adr_base + 0x00000029 * 0x00000004
  #define fm_dpll_reg69                                  (*(volatile unsigned int *)fm_dpll_reg69_adr)
  #define fm_dpll_reg6A_adr                              0x003277a8                                                   // fmrf_dpll_adr_base + 0x0000002a * 0x00000004
  #define fm_dpll_reg6A                                  (*(volatile unsigned int *)fm_dpll_reg6A_adr)
  #define fm_dpll_reg6B_adr                              0x003277ac                                                   // fmrf_dpll_adr_base + 0x0000002b * 0x00000004
  #define fm_dpll_reg6B                                  (*(volatile unsigned int *)fm_dpll_reg6B_adr)
  #define fm_dpll_reg6C_adr                              0x003277b0                                                   // fmrf_dpll_adr_base + 0x0000002c * 0x00000004
  #define fm_dpll_reg6C                                  (*(volatile unsigned int *)fm_dpll_reg6C_adr)
  #define fm_dpll_reg6D_adr                              0x003277b4                                                   // fmrf_dpll_adr_base + 0x0000002d * 0x00000004
  #define fm_dpll_reg6D                                  (*(volatile unsigned int *)fm_dpll_reg6D_adr)
  #define fm_dpll_reg6E_adr                              0x003277b8                                                   // fmrf_dpll_adr_base + 0x0000002e * 0x00000004
  #define fm_dpll_reg6E                                  (*(volatile unsigned int *)fm_dpll_reg6E_adr)
  #define fm_dpll_reg6F_adr                              0x003277bc                                                   // fmrf_dpll_adr_base + 0x0000002f * 0x00000004
  #define fm_dpll_reg6F                                  (*(volatile unsigned int *)fm_dpll_reg6F_adr)
  #define fm_dpll_reg70_adr                              0x003277c0                                                   // fmrf_dpll_adr_base + 0x00000030 * 0x00000004
  #define fm_dpll_reg70                                  (*(volatile unsigned int *)fm_dpll_reg70_adr)
  #define fm_dpll_reg71_adr                              0x003277c4                                                   // fmrf_dpll_adr_base + 0x00000031 * 0x00000004
  #define fm_dpll_reg71                                  (*(volatile unsigned int *)fm_dpll_reg71_adr)
  #define fm_dpll_reg72_adr                              0x003277c8                                                   // fmrf_dpll_adr_base + 0x00000032 * 0x00000004
  #define fm_dpll_reg72                                  (*(volatile unsigned int *)fm_dpll_reg72_adr)
  #define fm_dpll_reg73_adr                              0x003277cc                                                   // fmrf_dpll_adr_base + 0x00000033 * 0x00000004
  #define fm_dpll_reg73                                  (*(volatile unsigned int *)fm_dpll_reg73_adr)
  #define fm_dpll_reg74_adr                              0x003277d0                                                   // fmrf_dpll_adr_base + 0x00000034 * 0x00000004
  #define fm_dpll_reg74                                  (*(volatile unsigned int *)fm_dpll_reg74_adr)
  #define fm_dpll_reg75_adr                              0x003277d4                                                   // fmrf_dpll_adr_base + 0x00000035 * 0x00000004
  #define fm_dpll_reg75                                  (*(volatile unsigned int *)fm_dpll_reg75_adr)
  #define fm_dpll_reg76_adr                              0x003277d8                                                   // fmrf_dpll_adr_base + 0x00000036 * 0x00000004
  #define fm_dpll_reg76                                  (*(volatile unsigned int *)fm_dpll_reg76_adr)
  #define fm_dpll_reg77_adr                              0x003277dc                                                   // fmrf_dpll_adr_base + 0x00000037 * 0x00000004
  #define fm_dpll_reg77                                  (*(volatile unsigned int *)fm_dpll_reg77_adr)
  #define fm_dpll_reg78_adr                              0x003277e0                                                   // fmrf_dpll_adr_base + 0x00000038 * 0x00000004
  #define fm_dpll_reg78                                  (*(volatile unsigned int *)fm_dpll_reg78_adr)
  #define fm_dpll_reg79_adr                              0x003277e4                                                   // fmrf_dpll_adr_base + 0x00000039 * 0x00000004
  #define fm_dpll_reg79                                  (*(volatile unsigned int *)fm_dpll_reg79_adr)
  #define fm_dpll_reg7A_adr                              0x003277e8                                                   // fmrf_dpll_adr_base + 0x0000003a * 0x00000004
  #define fm_dpll_reg7A                                  (*(volatile unsigned int *)fm_dpll_reg7A_adr)
  #define fm_dpll_reg7B_adr                              0x003277ec                                                   // fmrf_dpll_adr_base + 0x0000003b * 0x00000004
  #define fm_dpll_reg7B                                  (*(volatile unsigned int *)fm_dpll_reg7B_adr)
  #define fm_dpll_reg7C_adr                              0x003277f0                                                   // fmrf_dpll_adr_base + 0x0000003c * 0x00000004
  #define fm_dpll_reg7C                                  (*(volatile unsigned int *)fm_dpll_reg7C_adr)
  #define fm_dpll_reg7D_adr                              0x003277f4                                                   // fmrf_dpll_adr_base + 0x0000003d * 0x00000004
  #define fm_dpll_reg7D                                  (*(volatile unsigned int *)fm_dpll_reg7D_adr)
  #define fm_dpll_reg7E_adr                              0x003277f8                                                   // fmrf_dpll_adr_base + 0x0000003e * 0x00000004
  #define fm_dpll_reg7E                                  (*(volatile unsigned int *)fm_dpll_reg7E_adr)
  #define fm_dpll_reg7F_adr                              0x003277fc                                                   // fmrf_dpll_adr_base + 0x0000003f * 0x00000004
  #define fm_dpll_reg7F                                  (*(volatile unsigned int *)fm_dpll_reg7F_adr)
  #define swp_ctl_pwr_adr                                0x0032d640                                                   // swp_adr_base + ctl_pwr
  #define swp_ctl_pwr                                    (*(volatile unsigned int *)swp_ctl_pwr_adr)
  #define swp_sta_pwr_adr                                0x0032d644                                                   // swp_adr_base + sta_pwr
  #define swp_sta_pwr                                    (*(volatile unsigned int *)swp_sta_pwr_adr)
  #define swp_timer_div_lb_adr                           0x0032d660                                                   // swp_adr_base + timer_div_lb
  #define swp_timer_div_lb                               (*(volatile unsigned int *)swp_timer_div_lb_adr)
  #define swp_timer_div_hb_adr                           0x0032d664                                                   // swp_adr_base + timer_div_hb
  #define swp_timer_div_hb                               (*(volatile unsigned int *)swp_timer_div_hb_adr)
  #define swp_timer_prescl_adr                           0x0032d668                                                   // swp_adr_base + timer_prescl
  #define swp_timer_prescl                               (*(volatile unsigned int *)swp_timer_prescl_adr)
  #define swp_ctl_adr                                    0x0032d680                                                   // swp_adr_base + ctl
  #define swp_ctl                                        (*(volatile unsigned int *)swp_ctl_adr)
  #define swp_baud_adr                                   0x0032d684                                                   // swp_adr_base + baud
  #define swp_baud                                       (*(volatile unsigned int *)swp_baud_adr)
  #define swp_mgt_adr                                    0x0032d688                                                   // swp_adr_base + mgt
  #define swp_mgt                                        (*(volatile unsigned int *)swp_mgt_adr)
  #define swp_dat_tx0_adr                                0x0032d68c                                                   // swp_adr_base + dat_tx0
  #define swp_dat_tx0                                    (*(volatile unsigned int *)swp_dat_tx0_adr)
  #define swp_dat_tx1_adr                                0x0032d690                                                   // swp_adr_base + dat_tx1
  #define swp_dat_tx1                                    (*(volatile unsigned int *)swp_dat_tx1_adr)
  #define swp_dat_rx0_adr                                0x0032d694                                                   // swp_adr_base + dat_rx0
  #define swp_dat_rx0                                    (*(volatile unsigned int *)swp_dat_rx0_adr)
  #define swp_dat_rx1_adr                                0x0032d698                                                   // swp_adr_base + dat_rx1
  #define swp_dat_rx1                                    (*(volatile unsigned int *)swp_dat_rx1_adr)
  #define swp_sta_tx0_adr                                0x0032d69c                                                   // swp_adr_base + sta_tx0
  #define swp_sta_tx0                                    (*(volatile unsigned int *)swp_sta_tx0_adr)
  #define swp_sta_tx1_adr                                0x0032d6a0                                                   // swp_adr_base + sta_tx1
  #define swp_sta_tx1                                    (*(volatile unsigned int *)swp_sta_tx1_adr)
  #define swp_sta_rx0_adr                                0x0032d6a4                                                   // swp_adr_base + sta_rx0
  #define swp_sta_rx0                                    (*(volatile unsigned int *)swp_sta_rx0_adr)
  #define swp_sta_rx1_adr                                0x0032d6a8                                                   // swp_adr_base + sta_rx1
  #define swp_sta_rx1                                    (*(volatile unsigned int *)swp_sta_rx1_adr)
  #define swp_sta_lnk_adr                                0x0032d6ac                                                   // swp_adr_base + sta_lnk
  #define swp_sta_lnk                                    (*(volatile unsigned int *)swp_sta_lnk_adr)
  #define swp_irq_adr                                    0x0032d6b0                                                   // swp_adr_base + irq
  #define swp_irq                                        (*(volatile unsigned int *)swp_irq_adr)
  #define swp_msk_adr                                    0x0032d6b4                                                   // swp_adr_base + msk
  #define swp_msk                                        (*(volatile unsigned int *)swp_msk_adr)
  #define swp_irw_adr                                    0x0032d6b8                                                   // swp_adr_base + irw
  #define swp_irw                                        (*(volatile unsigned int *)swp_irw_adr)
  #define swp_timer_adr                                  0x0032d6bc                                                   // swp_adr_base + timer
  #define swp_timer                                      (*(volatile unsigned int *)swp_timer_adr)
  #define spiffy_cfg_adr                                 0x00360600                                                   // spi_base + 0x00000000
  #define spiffy_cfg                                     (*(volatile unsigned int *)spiffy_cfg_adr)
  #define spiffy_TransmissionLength_adr                  0x00360604                                                   // spi_base + 0x00000004
  #define spiffy_TransmissionLength                      (*(volatile unsigned int *)spiffy_TransmissionLength_adr)
  #define spiffy_TxFIFOLevel_adr                         0x00360608                                                   // spi_base + 0x00000008
  #define spiffy_TxFIFOLevel                             (*(volatile unsigned int *)spiffy_TxFIFOLevel_adr)
  #define spiffy_TxAELevel_adr                           0x0036060c                                                   // spi_base + 0x0000000c
  #define spiffy_TxAELevel                               (*(volatile unsigned int *)spiffy_TxAELevel_adr)
  #define spiffy_TxDMALength_adr                         0x00360610                                                   // spi_base + 0x00000010
  #define spiffy_TxDMALength                             (*(volatile unsigned int *)spiffy_TxDMALength_adr)
  #define spiffy_RxLength_adr                            0x00360614                                                   // spi_base + 0x00000014
  #define spiffy_RxLength                                (*(volatile unsigned int *)spiffy_RxLength_adr)
  #define spiffy_RxFIFOLevel_adr                         0x00360618                                                   // spi_base + 0x00000018
  #define spiffy_RxFIFOLevel                             (*(volatile unsigned int *)spiffy_RxFIFOLevel_adr)
  #define spiffy_RxAFLevel_adr                           0x0036061c                                                   // spi_base + 0x0000001c
  #define spiffy_RxAFLevel                               (*(volatile unsigned int *)spiffy_RxAFLevel_adr)
  #define spiffy_RxDMALength_adr                         0x00360620                                                   // spi_base + 0x00000020
  #define spiffy_RxDMALength                             (*(volatile unsigned int *)spiffy_RxDMALength_adr)
  #define spiffy_IntStatus_adr                           0x00360624                                                   // spi_base + 0x00000024
  #define spiffy_IntStatus                               (*(volatile unsigned int *)spiffy_IntStatus_adr)
  #define spiffy_IntEnable_adr                           0x00360628                                                   // spi_base + 0x00000028
  #define spiffy_IntEnable                               (*(volatile unsigned int *)spiffy_IntEnable_adr)
  #define spiffy_Status_adr                              0x0036062c                                                   // spi_base + 0x0000002c
  #define spiffy_Status                                  (*(volatile unsigned int *)spiffy_Status_adr)
  #define spiffy_ClockCfg_adr                            0x00360630                                                   // spi_base + 0x00000030
  #define spiffy_ClockCfg                                (*(volatile unsigned int *)spiffy_ClockCfg_adr)
  #define spiffy_RxFIFO0_adr                             0x00360680                                                   // spi_base + 0x00000080
  #define spiffy_RxFIFO0                                 (*(volatile unsigned int *)spiffy_RxFIFO0_adr)
  #define spiffy_RxFIFO1_adr                             0x00360684                                                   // spi_base + 0x00000084
  #define spiffy_RxFIFO1                                 (*(volatile unsigned int *)spiffy_RxFIFO1_adr)
  #define spiffy_RxFIFO2_adr                             0x00360688                                                   // spi_base + 0x00000088
  #define spiffy_RxFIFO2                                 (*(volatile unsigned int *)spiffy_RxFIFO2_adr)
  #define spiffy_RxFIFO3_adr                             0x0036068c                                                   // spi_base + 0x0000008c
  #define spiffy_RxFIFO3                                 (*(volatile unsigned int *)spiffy_RxFIFO3_adr)
  #define spiffy_RxFIFO4_adr                             0x00360690                                                   // spi_base + 0x00000090
  #define spiffy_RxFIFO4                                 (*(volatile unsigned int *)spiffy_RxFIFO4_adr)
  #define spiffy_RxFIFO5_adr                             0x00360694                                                   // spi_base + 0x00000094
  #define spiffy_RxFIFO5                                 (*(volatile unsigned int *)spiffy_RxFIFO5_adr)
  #define spiffy_RxFIFO6_adr                             0x00360698                                                   // spi_base + 0x00000098
  #define spiffy_RxFIFO6                                 (*(volatile unsigned int *)spiffy_RxFIFO6_adr)
  #define spiffy_RxFIFO7_adr                             0x0036069c                                                   // spi_base + 0x0000009c
  #define spiffy_RxFIFO7                                 (*(volatile unsigned int *)spiffy_RxFIFO7_adr)
  #define spiffy_RxFIFO8_adr                             0x003606a0                                                   // spi_base + 0x000000a0
  #define spiffy_RxFIFO8                                 (*(volatile unsigned int *)spiffy_RxFIFO8_adr)
  #define spiffy_RxFIFO9_adr                             0x003606a4                                                   // spi_base + 0x000000a4
  #define spiffy_RxFIFO9                                 (*(volatile unsigned int *)spiffy_RxFIFO9_adr)
  #define spiffy_RxFIFO10_adr                            0x003606a8                                                   // spi_base + 0x000000a8
  #define spiffy_RxFIFO10                                (*(volatile unsigned int *)spiffy_RxFIFO10_adr)
  #define spiffy_RxFIFO11_adr                            0x003606ac                                                   // spi_base + 0x000000ac
  #define spiffy_RxFIFO11                                (*(volatile unsigned int *)spiffy_RxFIFO11_adr)
  #define spiffy_RxFIFO12_adr                            0x003606b0                                                   // spi_base + 0x000000b0
  #define spiffy_RxFIFO12                                (*(volatile unsigned int *)spiffy_RxFIFO12_adr)
  #define spiffy_RxFIFO13_adr                            0x003606b4                                                   // spi_base + 0x000000b4
  #define spiffy_RxFIFO13                                (*(volatile unsigned int *)spiffy_RxFIFO13_adr)
  #define spiffy_RxFIFO14_adr                            0x003606b8                                                   // spi_base + 0x000000b8
  #define spiffy_RxFIFO14                                (*(volatile unsigned int *)spiffy_RxFIFO14_adr)
  #define spiffy_RxFIFO15_adr                            0x003606bc                                                   // spi_base + 0x000000bc
  #define spiffy_RxFIFO15                                (*(volatile unsigned int *)spiffy_RxFIFO15_adr)
  #define spiffy_TxFIFO0_adr                             0x003606c0                                                   // spi_base + 0x000000c0
  #define spiffy_TxFIFO0                                 (*(volatile unsigned int *)spiffy_TxFIFO0_adr)
  #define spiffy_TxFIFO1_adr                             0x003606c4                                                   // spi_base + 0x000000c4
  #define spiffy_TxFIFO1                                 (*(volatile unsigned int *)spiffy_TxFIFO1_adr)
  #define spiffy_TxFIFO2_adr                             0x003606c8                                                   // spi_base + 0x000000c8
  #define spiffy_TxFIFO2                                 (*(volatile unsigned int *)spiffy_TxFIFO2_adr)
  #define spiffy_TxFIFO3_adr                             0x003606cc                                                   // spi_base + 0x000000cc
  #define spiffy_TxFIFO3                                 (*(volatile unsigned int *)spiffy_TxFIFO3_adr)
  #define spiffy_TxFIFO4_adr                             0x003606d0                                                   // spi_base + 0x000000d0
  #define spiffy_TxFIFO4                                 (*(volatile unsigned int *)spiffy_TxFIFO4_adr)
  #define spiffy_TxFIFO5_adr                             0x003606d4                                                   // spi_base + 0x000000d4
  #define spiffy_TxFIFO5                                 (*(volatile unsigned int *)spiffy_TxFIFO5_adr)
  #define spiffy_TxFIFO6_adr                             0x003606d8                                                   // spi_base + 0x000000d8
  #define spiffy_TxFIFO6                                 (*(volatile unsigned int *)spiffy_TxFIFO6_adr)
  #define spiffy_TxFIFO7_adr                             0x003606dc                                                   // spi_base + 0x000000dc
  #define spiffy_TxFIFO7                                 (*(volatile unsigned int *)spiffy_TxFIFO7_adr)
  #define spiffy_TxFIFO8_adr                             0x003606e0                                                   // spi_base + 0x000000e0
  #define spiffy_TxFIFO8                                 (*(volatile unsigned int *)spiffy_TxFIFO8_adr)
  #define spiffy_TxFIFO9_adr                             0x003606e4                                                   // spi_base + 0x000000e4
  #define spiffy_TxFIFO9                                 (*(volatile unsigned int *)spiffy_TxFIFO9_adr)
  #define spiffy_TxFIFO10_adr                            0x003606e8                                                   // spi_base + 0x000000e8
  #define spiffy_TxFIFO10                                (*(volatile unsigned int *)spiffy_TxFIFO10_adr)
  #define spiffy_TxFIFO11_adr                            0x003606ec                                                   // spi_base + 0x000000ec
  #define spiffy_TxFIFO11                                (*(volatile unsigned int *)spiffy_TxFIFO11_adr)
  #define spiffy_TxFIFO12_adr                            0x003606f0                                                   // spi_base + 0x000000f0
  #define spiffy_TxFIFO12                                (*(volatile unsigned int *)spiffy_TxFIFO12_adr)
  #define spiffy_TxFIFO13_adr                            0x003606f4                                                   // spi_base + 0x000000f4
  #define spiffy_TxFIFO13                                (*(volatile unsigned int *)spiffy_TxFIFO13_adr)
  #define spiffy_TxFIFO14_adr                            0x003606f8                                                   // spi_base + 0x000000f8
  #define spiffy_TxFIFO14                                (*(volatile unsigned int *)spiffy_TxFIFO14_adr)
  #define spiffy_TxFIFO15_adr                            0x003606fc                                                   // spi_base + 0x000000fc
  #define spiffy_TxFIFO15                                (*(volatile unsigned int *)spiffy_TxFIFO15_adr)
  #define spiffy_RxFIFO_adr                              0x00360700                                                   // spi_base + 0x00000100
  #define spiffy_RxFIFO                                  (*(volatile unsigned int *)spiffy_RxFIFO_adr)
  #define spiffy_TxFIFO_adr                              0x00360704                                                   // spi_base + 0x00000104
  #define spiffy_TxFIFO                                  (*(volatile unsigned int *)spiffy_TxFIFO_adr)
  #define spiffy2_spiffy_cfg_adr                         0x00352400                                                   // spiffy2_base + 0x00000000
  #define spiffy2_spiffy_cfg                             (*(volatile unsigned int *)spiffy2_spiffy_cfg_adr)
  #define spiffy2_spiffy_TransmissionLength_adr          0x00352404                                                   // spiffy2_base + 0x00000004
  #define spiffy2_spiffy_TransmissionLength              (*(volatile unsigned int *)spiffy2_spiffy_TransmissionLength_adr)
  #define spiffy2_spiffy_TxFIFOLevel_adr                 0x00352408                                                   // spiffy2_base + 0x00000008
  #define spiffy2_spiffy_TxFIFOLevel                     (*(volatile unsigned int *)spiffy2_spiffy_TxFIFOLevel_adr)
  #define spiffy2_spiffy_TxAELevel_adr                   0x0035240c                                                   // spiffy2_base + 0x0000000c
  #define spiffy2_spiffy_TxAELevel                       (*(volatile unsigned int *)spiffy2_spiffy_TxAELevel_adr)
  #define spiffy2_spiffy_TxDMALength_adr                 0x00352410                                                   // spiffy2_base + 0x00000010
  #define spiffy2_spiffy_TxDMALength                     (*(volatile unsigned int *)spiffy2_spiffy_TxDMALength_adr)
  #define spiffy2_spiffy_RxLength_adr                    0x00352414                                                   // spiffy2_base + 0x00000014
  #define spiffy2_spiffy_RxLength                        (*(volatile unsigned int *)spiffy2_spiffy_RxLength_adr)
  #define spiffy2_spiffy_RxFIFOLevel_adr                 0x00352418                                                   // spiffy2_base + 0x00000018
  #define spiffy2_spiffy_RxFIFOLevel                     (*(volatile unsigned int *)spiffy2_spiffy_RxFIFOLevel_adr)
  #define spiffy2_spiffy_RxAFLevel_adr                   0x0035241c                                                   // spiffy2_base + 0x0000001c
  #define spiffy2_spiffy_RxAFLevel                       (*(volatile unsigned int *)spiffy2_spiffy_RxAFLevel_adr)
  #define spiffy2_spiffy_RxDMALength_adr                 0x00352420                                                   // spiffy2_base + 0x00000020
  #define spiffy2_spiffy_RxDMALength                     (*(volatile unsigned int *)spiffy2_spiffy_RxDMALength_adr)
  #define spiffy2_spiffy_IntStatus_adr                   0x00352424                                                   // spiffy2_base + 0x00000024
  #define spiffy2_spiffy_IntStatus                       (*(volatile unsigned int *)spiffy2_spiffy_IntStatus_adr)
  #define spiffy2_spiffy_IntEnable_adr                   0x00352428                                                   // spiffy2_base + 0x00000028
  #define spiffy2_spiffy_IntEnable                       (*(volatile unsigned int *)spiffy2_spiffy_IntEnable_adr)
  #define spiffy2_spiffy_Status_adr                      0x0035242c                                                   // spiffy2_base + 0x0000002c
  #define spiffy2_spiffy_Status                          (*(volatile unsigned int *)spiffy2_spiffy_Status_adr)
  #define spiffy2_spiffy_ClockCfg_adr                    0x00352430                                                   // spiffy2_base + 0x00000030
  #define spiffy2_spiffy_ClockCfg                        (*(volatile unsigned int *)spiffy2_spiffy_ClockCfg_adr)
  #define spiffy2_spiffy_RxFIFO0_adr                     0x00352480                                                   // spiffy2_base + 0x00000080
  #define spiffy2_spiffy_RxFIFO0                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO0_adr)
  #define spiffy2_spiffy_RxFIFO1_adr                     0x00352484                                                   // spiffy2_base + 0x00000084
  #define spiffy2_spiffy_RxFIFO1                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO1_adr)
  #define spiffy2_spiffy_RxFIFO2_adr                     0x00352488                                                   // spiffy2_base + 0x00000088
  #define spiffy2_spiffy_RxFIFO2                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO2_adr)
  #define spiffy2_spiffy_RxFIFO3_adr                     0x0035248c                                                   // spiffy2_base + 0x0000008c
  #define spiffy2_spiffy_RxFIFO3                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO3_adr)
  #define spiffy2_spiffy_RxFIFO4_adr                     0x00352490                                                   // spiffy2_base + 0x00000090
  #define spiffy2_spiffy_RxFIFO4                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO4_adr)
  #define spiffy2_spiffy_RxFIFO5_adr                     0x00352494                                                   // spiffy2_base + 0x00000094
  #define spiffy2_spiffy_RxFIFO5                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO5_adr)
  #define spiffy2_spiffy_RxFIFO6_adr                     0x00352498                                                   // spiffy2_base + 0x00000098
  #define spiffy2_spiffy_RxFIFO6                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO6_adr)
  #define spiffy2_spiffy_RxFIFO7_adr                     0x0035249c                                                   // spiffy2_base + 0x0000009c
  #define spiffy2_spiffy_RxFIFO7                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO7_adr)
  #define spiffy2_spiffy_RxFIFO8_adr                     0x003524a0                                                   // spiffy2_base + 0x000000a0
  #define spiffy2_spiffy_RxFIFO8                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO8_adr)
  #define spiffy2_spiffy_RxFIFO9_adr                     0x003524a4                                                   // spiffy2_base + 0x000000a4
  #define spiffy2_spiffy_RxFIFO9                         (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO9_adr)
  #define spiffy2_spiffy_RxFIFO10_adr                    0x003524a8                                                   // spiffy2_base + 0x000000a8
  #define spiffy2_spiffy_RxFIFO10                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO10_adr)
  #define spiffy2_spiffy_RxFIFO11_adr                    0x003524ac                                                   // spiffy2_base + 0x000000ac
  #define spiffy2_spiffy_RxFIFO11                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO11_adr)
  #define spiffy2_spiffy_RxFIFO12_adr                    0x003524b0                                                   // spiffy2_base + 0x000000b0
  #define spiffy2_spiffy_RxFIFO12                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO12_adr)
  #define spiffy2_spiffy_RxFIFO13_adr                    0x003524b4                                                   // spiffy2_base + 0x000000b4
  #define spiffy2_spiffy_RxFIFO13                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO13_adr)
  #define spiffy2_spiffy_RxFIFO14_adr                    0x003524b8                                                   // spiffy2_base + 0x000000b8
  #define spiffy2_spiffy_RxFIFO14                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO14_adr)
  #define spiffy2_spiffy_RxFIFO15_adr                    0x003524bc                                                   // spiffy2_base + 0x000000bc
  #define spiffy2_spiffy_RxFIFO15                        (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO15_adr)
  #define spiffy2_spiffy_TxFIFO0_adr                     0x003524c0                                                   // spiffy2_base + 0x000000c0
  #define spiffy2_spiffy_TxFIFO0                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO0_adr)
  #define spiffy2_spiffy_TxFIFO1_adr                     0x003524c4                                                   // spiffy2_base + 0x000000c4
  #define spiffy2_spiffy_TxFIFO1                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO1_adr)
  #define spiffy2_spiffy_TxFIFO2_adr                     0x003524c8                                                   // spiffy2_base + 0x000000c8
  #define spiffy2_spiffy_TxFIFO2                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO2_adr)
  #define spiffy2_spiffy_TxFIFO3_adr                     0x003524cc                                                   // spiffy2_base + 0x000000cc
  #define spiffy2_spiffy_TxFIFO3                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO3_adr)
  #define spiffy2_spiffy_TxFIFO4_adr                     0x003524d0                                                   // spiffy2_base + 0x000000d0
  #define spiffy2_spiffy_TxFIFO4                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO4_adr)
  #define spiffy2_spiffy_TxFIFO5_adr                     0x003524d4                                                   // spiffy2_base + 0x000000d4
  #define spiffy2_spiffy_TxFIFO5                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO5_adr)
  #define spiffy2_spiffy_TxFIFO6_adr                     0x003524d8                                                   // spiffy2_base + 0x000000d8
  #define spiffy2_spiffy_TxFIFO6                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO6_adr)
  #define spiffy2_spiffy_TxFIFO7_adr                     0x003524dc                                                   // spiffy2_base + 0x000000dc
  #define spiffy2_spiffy_TxFIFO7                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO7_adr)
  #define spiffy2_spiffy_TxFIFO8_adr                     0x003524e0                                                   // spiffy2_base + 0x000000e0
  #define spiffy2_spiffy_TxFIFO8                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO8_adr)
  #define spiffy2_spiffy_TxFIFO9_adr                     0x003524e4                                                   // spiffy2_base + 0x000000e4
  #define spiffy2_spiffy_TxFIFO9                         (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO9_adr)
  #define spiffy2_spiffy_TxFIFO10_adr                    0x003524e8                                                   // spiffy2_base + 0x000000e8
  #define spiffy2_spiffy_TxFIFO10                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO10_adr)
  #define spiffy2_spiffy_TxFIFO11_adr                    0x003524ec                                                   // spiffy2_base + 0x000000ec
  #define spiffy2_spiffy_TxFIFO11                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO11_adr)
  #define spiffy2_spiffy_TxFIFO12_adr                    0x003524f0                                                   // spiffy2_base + 0x000000f0
  #define spiffy2_spiffy_TxFIFO12                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO12_adr)
  #define spiffy2_spiffy_TxFIFO13_adr                    0x003524f4                                                   // spiffy2_base + 0x000000f4
  #define spiffy2_spiffy_TxFIFO13                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO13_adr)
  #define spiffy2_spiffy_TxFIFO14_adr                    0x003524f8                                                   // spiffy2_base + 0x000000f8
  #define spiffy2_spiffy_TxFIFO14                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO14_adr)
  #define spiffy2_spiffy_TxFIFO15_adr                    0x003524fc                                                   // spiffy2_base + 0x000000fc
  #define spiffy2_spiffy_TxFIFO15                        (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO15_adr)
  #define spiffy2_spiffy_RxFIFO_adr                      0x00352500                                                   // spiffy2_base + 0x00000100
  #define spiffy2_spiffy_RxFIFO                          (*(volatile unsigned int *)spiffy2_spiffy_RxFIFO_adr)
  #define spiffy2_spiffy_TxFIFO_adr                      0x00352504                                                   // spiffy2_base + 0x00000104
  #define spiffy2_spiffy_TxFIFO                          (*(volatile unsigned int *)spiffy2_spiffy_TxFIFO_adr)
  #define aburst_ctrl_adr                                0x00352000                                                   // aburst_base + 0x00000000
  #define aburst_ctrl                                    (*(volatile unsigned int *)aburst_ctrl_adr)
  #define aburst_fifo_adr                                0x00352004                                                   // aburst_base + 0x00000004
  #define aburst_fifo                                    (*(volatile unsigned int *)aburst_fifo_adr)
  #define aburst_lli_size_adr                            0x00352008                                                   // aburst_base + 0x00000008
  #define aburst_lli_size                                (*(volatile unsigned int *)aburst_lli_size_adr)
  #define aburst_lli_length_remaining_adr                0x0035200c                                                   // aburst_base + 0x0000000c
  #define aburst_lli_length_remaining                    (*(volatile unsigned int *)aburst_lli_length_remaining_adr)
  #define aburst_int_status_adr                          0x00352010                                                   // aburst_base + 0x00000010
  #define aburst_int_status                              (*(volatile unsigned int *)aburst_int_status_adr)
  #define aburst_int_enable_adr                          0x00352014                                                   // aburst_base + 0x00000014
  #define aburst_int_enable                              (*(volatile unsigned int *)aburst_int_enable_adr)
  #define pcm2_config_adr                                0x00352100                                                   // pcm2_base + 0x00000000
  #define pcm2_config                                    (*(volatile unsigned int *)pcm2_config_adr)
  #define pcm2_bank_settings_adr                         0x00352104                                                   // pcm2_base + 0x00000004
  #define pcm2_bank_settings                             (*(volatile unsigned int *)pcm2_bank_settings_adr)
  #define pcm2_ch_config_adr                             0x00352108                                                   // pcm2_base + 0x00000008
  #define pcm2_ch_config                                 (*(volatile unsigned int *)pcm2_ch_config_adr)
  #define pcm2_ch_period_adr                             0x0035210c                                                   // pcm2_base + 0x0000000c
  #define pcm2_ch_period                                 (*(volatile unsigned int *)pcm2_ch_period_adr)
  #define hub0_hc_cfg_adr                                0x00362000                                                   // hub_base + 0x00000000
  #define hub0_hc_cfg                                    (*(volatile unsigned int *)hub0_hc_cfg_adr)
  #define hub0_hc_info_adr                               0x00362004                                                   // hub_base + 0x00000004
  #define hub0_hc_info                                   (*(volatile unsigned int *)hub0_hc_info_adr)
  #define hub0_hc_stringbuf2_adr                         0x00362008                                                   // hub_base + 0x00000008
  #define hub0_hc_stringbuf2                             (*(volatile unsigned int *)hub0_hc_stringbuf2_adr)
  #define hub0_hub_rw_duration_adr                       0x0036200c                                                   // hub_base + 0x0000000c
  #define hub0_hub_rw_duration                           (*(volatile unsigned int *)hub0_hub_rw_duration_adr)
  #define hub0_hub_xcvr_tm_cfg_adr                       0x00362010                                                   // hub_base + 0x00000010
  #define hub0_hub_xcvr_tm_cfg                           (*(volatile unsigned int *)hub0_hub_xcvr_tm_cfg_adr)
  #define hub0_hub_xcvr_tm_dp_xmit_adr                   0x00362014                                                   // hub_base + 0x00000014
  #define hub0_hub_xcvr_tm_dp_xmit                       (*(volatile unsigned int *)hub0_hub_xcvr_tm_dp_xmit_adr)
  #define hub0_hub_xcvr_tm_dm_xmit_adr                   0x00362018                                                   // hub_base + 0x00000018
  #define hub0_hub_xcvr_tm_dm_xmit                       (*(volatile unsigned int *)hub0_hub_xcvr_tm_dm_xmit_adr)
  #define hub0_hub_ECO_USBD_adr                          0x003620fc                                                   // hub_base + 0x000000fc
  #define hub0_hub_ECO_USBD                              (*(volatile unsigned int *)hub0_hub_ECO_USBD_adr)
  #define hub0_cfg_adr                                   0x00362100                                                   // hub_base + 0x00000100
  #define hub0_cfg                                       (*(volatile unsigned int *)hub0_cfg_adr)
  #define hub0_port_cfg_adr                              0x00362104                                                   // hub_base + 0x00000104
  #define hub0_port_cfg                                  (*(volatile unsigned int *)hub0_port_cfg_adr)
  #define hub0_hub_ECO_ARMD_adr                          0x0036217c                                                   // hub_base + 0x0000017c
  #define hub0_hub_ECO_ARMD                              (*(volatile unsigned int *)hub0_hub_ECO_ARMD_adr)
  #define hub0_hub_int_status_adr                        0x00362180                                                   // hub_base + 0x00000180
  #define hub0_hub_int_status                            (*(volatile unsigned int *)hub0_hub_int_status_adr)
  #define hub0_hub_int_en_adr                            0x003621c0                                                   // hub_base + 0x000001c0
  #define hub0_hub_int_en                                (*(volatile unsigned int *)hub0_hub_int_en_adr)
  #define hub0_hub_desc_ram_base_adr                     0x00362200                                                   // hub_base + 0x00000200
  #define hub0_hub_desc_ram_base                         (*(volatile unsigned int *)hub0_hub_desc_ram_base_adr)
  #define usb0_cfg_adr                                   0x00363000                                                   // usb0_usb_base + 0x00000000
  #define usb0_cfg                                       (*(volatile unsigned int *)usb0_cfg_adr)
  #define usb0_interfaceval_adr                          0x00363004                                                   // usb0_usb_base + 0x00000004
  #define usb0_interfaceval                              (*(volatile unsigned int *)usb0_interfaceval_adr)
  #define usb0_tran_ctrl_adr                             0x00363008                                                   // usb0_usb_base + 0x00000008
  #define usb0_tran_ctrl                                 (*(volatile unsigned int *)usb0_tran_ctrl_adr)
  #define usb0_cfgnum_adr                                0x0036300c                                                   // usb0_usb_base + 0x0000000c
  #define usb0_cfgnum                                    (*(volatile unsigned int *)usb0_cfgnum_adr)
  #define usb0_bmrt_adr                                  0x00363010                                                   // usb0_usb_base + 0x00000010
  #define usb0_bmrt                                      (*(volatile unsigned int *)usb0_bmrt_adr)
  #define usb0_brequest_adr                              0x00363014                                                   // usb0_usb_base + 0x00000014
  #define usb0_brequest                                  (*(volatile unsigned int *)usb0_brequest_adr)
  #define usb0_wvaluel_adr                               0x00363018                                                   // usb0_usb_base + 0x00000018
  #define usb0_wvaluel                                   (*(volatile unsigned int *)usb0_wvaluel_adr)
  #define usb0_wvalueh_adr                               0x0036301c                                                   // usb0_usb_base + 0x0000001c
  #define usb0_wvalueh                                   (*(volatile unsigned int *)usb0_wvalueh_adr)
  #define usb0_windexl_adr                               0x00363020                                                   // usb0_usb_base + 0x00000020
  #define usb0_windexl                                   (*(volatile unsigned int *)usb0_windexl_adr)
  #define usb0_windexh_adr                               0x00363024                                                   // usb0_usb_base + 0x00000024
  #define usb0_windexh                                   (*(volatile unsigned int *)usb0_windexh_adr)
  #define usb0_wlengthl_adr                              0x00363028                                                   // usb0_usb_base + 0x00000028
  #define usb0_wlengthl                                  (*(volatile unsigned int *)usb0_wlengthl_adr)
  #define usb0_wlengthh_adr                              0x0036302c                                                   // usb0_usb_base + 0x0000002c
  #define usb0_wlengthh                                  (*(volatile unsigned int *)usb0_wlengthh_adr)
  #define usb0_rw_duration_adr                           0x00363030                                                   // usb0_usb_base + 0x00000030
  #define usb0_rw_duration                               (*(volatile unsigned int *)usb0_rw_duration_adr)
  #define usb0_num_intaltset_in_cfg1_adr                 0x00363034                                                   // usb0_usb_base + 0x00000034
  #define usb0_num_intaltset_in_cfg1                     (*(volatile unsigned int *)usb0_num_intaltset_in_cfg1_adr)
  #define usb0_xcvr_tm_cfg_adr                           0x00363038                                                   // usb0_usb_base + 0x00000038
  #define usb0_xcvr_tm_cfg                               (*(volatile unsigned int *)usb0_xcvr_tm_cfg_adr)
  #define usb0_xcvr_tm_dp_xmit_adr                       0x0036303c                                                   // usb0_usb_base + 0x0000003c
  #define usb0_xcvr_tm_dp_xmit                           (*(volatile unsigned int *)usb0_xcvr_tm_dp_xmit_adr)
  #define usb0_xcvr_tm_dm_xmit_adr                       0x00363040                                                   // usb0_usb_base + 0x00000040
  #define usb0_xcvr_tm_dm_xmit                           (*(volatile unsigned int *)usb0_xcvr_tm_dm_xmit_adr)
  #define usb0_usbd_ECO_USBD_adr                         0x003630fc                                                   // usb0_usb_base + 0x000000fc
  #define usb0_usbd_ECO_USBD                             (*(volatile unsigned int *)usb0_usbd_ECO_USBD_adr)
  #define usb0_ep0_data_adr                              0x00363100                                                   // usb0_usb_base + 0x00000100
  #define usb0_ep0_data                                  (*(volatile unsigned int *)usb0_ep0_data_adr)
  #define usb0_ep1_data_adr                              0x00363140                                                   // usb0_usb_base + 0x00000140
  #define usb0_ep1_data                                  (*(volatile unsigned int *)usb0_ep1_data_adr)
  #define usb0_ep2_data_adr                              0x00363180                                                   // usb0_usb_base + 0x00000180
  #define usb0_ep2_data                                  (*(volatile unsigned int *)usb0_ep2_data_adr)
  #define usb0_ep3_data_adr                              0x003631c0                                                   // usb0_usb_base + 0x000001c0
  #define usb0_ep3_data                                  (*(volatile unsigned int *)usb0_ep3_data_adr)
  #define usb0_ep4_data_adr                              0x00363200                                                   // usb0_usb_base + 0x00000200
  #define usb0_ep4_data                                  (*(volatile unsigned int *)usb0_ep4_data_adr)
  #define usb0_epi_trg_adr                               0x00363300                                                   // usb0_usb_base + 0x00000300
  #define usb0_epi_trg                                   (*(volatile unsigned int *)usb0_epi_trg_adr)
  #define usb0_epi_0ln_trg_adr                           0x00363304                                                   // usb0_usb_base + 0x00000304
  #define usb0_epi_0ln_trg                               (*(volatile unsigned int *)usb0_epi_0ln_trg_adr)
  #define usb0_usb_flush_fifo_adr                        0x00363308                                                   // usb0_usb_base + 0x00000308
  #define usb0_usb_flush_fifo                            (*(volatile unsigned int *)usb0_usb_flush_fifo_adr)
  #define usb0_ep2_dma_cfg_adr                           0x0036330c                                                   // usb0_usb_base + 0x0000030c
  #define usb0_ep2_dma_cfg                               (*(volatile unsigned int *)usb0_ep2_dma_cfg_adr)
  #define usb0_ep2i_hci_pkglen_adr                       0x00363310                                                   // usb0_usb_base + 0x00000310
  #define usb0_ep2i_hci_pkglen                           (*(volatile unsigned int *)usb0_ep2i_hci_pkglen_adr)
  #define usb0_ep2o_hci_pkglen_adr                       0x00363314                                                   // usb0_usb_base + 0x00000314
  #define usb0_ep2o_hci_pkglen                           (*(volatile unsigned int *)usb0_ep2o_hci_pkglen_adr)
  #define usb0_ep3i_bytes_in_fifo_adr                    0x00363318                                                   // usb0_usb_base + 0x00000318
  #define usb0_ep3i_bytes_in_fifo                        (*(volatile unsigned int *)usb0_ep3i_bytes_in_fifo_adr)
  #define usb0_ep3i_empty_watermark_adr                  0x0036331c                                                   // usb0_usb_base + 0x0000031c
  #define usb0_ep3i_empty_watermark                      (*(volatile unsigned int *)usb0_ep3i_empty_watermark_adr)
  #define usb0_ep3i_pkt_size_adr                         0x00363320                                                   // usb0_usb_base + 0x00000320
  #define usb0_ep3i_pkt_size                             (*(volatile unsigned int *)usb0_ep3i_pkt_size_adr)
  #define usb0_ep3o_bytes_in_fifo_adr                    0x00363324                                                   // usb0_usb_base + 0x00000324
  #define usb0_ep3o_bytes_in_fifo                        (*(volatile unsigned int *)usb0_ep3o_bytes_in_fifo_adr)
  #define usb0_ep3o_full_watermark_adr                   0x00363328                                                   // usb0_usb_base + 0x00000328
  #define usb0_ep3o_full_watermark                       (*(volatile unsigned int *)usb0_ep3o_full_watermark_adr)
  #define usb0_ep0o_pklen_adr                            0x00363330                                                   // usb0_usb_base + 0x00000330
  #define usb0_ep0o_pklen                                (*(volatile unsigned int *)usb0_ep0o_pklen_adr)
  #define usb0_ep2o_pklen_adr                            0x00363338                                                   // usb0_usb_base + 0x00000338
  #define usb0_ep2o_pklen                                (*(volatile unsigned int *)usb0_ep2o_pklen_adr)
  #define usb0_ep3o_pklen_adr                            0x0036333c                                                   // usb0_usb_base + 0x0000033c
  #define usb0_ep3o_pklen                                (*(volatile unsigned int *)usb0_ep3o_pklen_adr)
  #define usb0_ep4o_pklen_adr                            0x00363340                                                   // usb0_usb_base + 0x00000340
  #define usb0_ep4o_pklen                                (*(volatile unsigned int *)usb0_ep4o_pklen_adr)
  #define usb0_usbd_ECO_ARMD_adr                         0x0036337c                                                   // usb0_usb_base + 0x0000037c
  #define usb0_usbd_ECO_ARMD                             (*(volatile unsigned int *)usb0_usbd_ECO_ARMD_adr)
  #define usb0_epi_empty_int_status_adr                  0x00363380                                                   // usb0_usb_base + 0x00000380
  #define usb0_epi_empty_int_status                      (*(volatile unsigned int *)usb0_epi_empty_int_status_adr)
  #define usb0_epo_ready_int_status_adr                  0x00363384                                                   // usb0_usb_base + 0x00000384
  #define usb0_epo_ready_int_status                      (*(volatile unsigned int *)usb0_epo_ready_int_status_adr)
  #define usb0_device_int_status_adr                     0x00363388                                                   // usb0_usb_base + 0x00000388
  #define usb0_device_int_status                         (*(volatile unsigned int *)usb0_device_int_status_adr)
  #define usb0_epi_0ln_done_int_status_adr               0x0036338c                                                   // usb0_usb_base + 0x0000038c
  #define usb0_epi_0ln_done_int_status                   (*(volatile unsigned int *)usb0_epi_0ln_done_int_status_adr)
  #define usb0_epi_empty_int_en_adr                      0x003633c0                                                   // usb0_usb_base + 0x000003c0
  #define usb0_epi_empty_int_en                          (*(volatile unsigned int *)usb0_epi_empty_int_en_adr)
  #define usb0_epo_ready_int_en_adr                      0x003633c4                                                   // usb0_usb_base + 0x000003c4
  #define usb0_epo_ready_int_en                          (*(volatile unsigned int *)usb0_epo_ready_int_en_adr)
  #define usb0_device_int_en_adr                         0x003633c8                                                   // usb0_usb_base + 0x000003c8
  #define usb0_device_int_en                             (*(volatile unsigned int *)usb0_device_int_en_adr)
  #define usb0_epi_0ln_done_int_en_adr                   0x003633cc                                                   // usb0_usb_base + 0x000003cc
  #define usb0_epi_0ln_done_int_en                       (*(volatile unsigned int *)usb0_epi_0ln_done_int_en_adr)
  #define usb0_device_int_cfg_adr                        0x003633d0                                                   // usb0_usb_base + 0x000003d0
  #define usb0_device_int_cfg                            (*(volatile unsigned int *)usb0_device_int_cfg_adr)
  #define usb0_ctrl_adr                                  0x003633d4                                                   // usb0_usb_base + 0x000003d4
  #define usb0_ctrl                                      (*(volatile unsigned int *)usb0_ctrl_adr)
  #define usb1_cfg_adr                                   0x00363400                                                   // usb1_usb_base + 0x00000000
  #define usb1_cfg                                       (*(volatile unsigned int *)usb1_cfg_adr)
  #define usb1_interfaceval_adr                          0x00363404                                                   // usb1_usb_base + 0x00000004
  #define usb1_interfaceval                              (*(volatile unsigned int *)usb1_interfaceval_adr)
  #define usb1_tran_ctrl_adr                             0x00363408                                                   // usb1_usb_base + 0x00000008
  #define usb1_tran_ctrl                                 (*(volatile unsigned int *)usb1_tran_ctrl_adr)
  #define usb1_cfgnum_adr                                0x0036340c                                                   // usb1_usb_base + 0x0000000c
  #define usb1_cfgnum                                    (*(volatile unsigned int *)usb1_cfgnum_adr)
  #define usb1_bmrt_adr                                  0x00363410                                                   // usb1_usb_base + 0x00000010
  #define usb1_bmrt                                      (*(volatile unsigned int *)usb1_bmrt_adr)
  #define usb1_brequest_adr                              0x00363414                                                   // usb1_usb_base + 0x00000014
  #define usb1_brequest                                  (*(volatile unsigned int *)usb1_brequest_adr)
  #define usb1_wvaluel_adr                               0x00363418                                                   // usb1_usb_base + 0x00000018
  #define usb1_wvaluel                                   (*(volatile unsigned int *)usb1_wvaluel_adr)
  #define usb1_wvalueh_adr                               0x0036341c                                                   // usb1_usb_base + 0x0000001c
  #define usb1_wvalueh                                   (*(volatile unsigned int *)usb1_wvalueh_adr)
  #define usb1_windexl_adr                               0x00363420                                                   // usb1_usb_base + 0x00000020
  #define usb1_windexl                                   (*(volatile unsigned int *)usb1_windexl_adr)
  #define usb1_windexh_adr                               0x00363424                                                   // usb1_usb_base + 0x00000024
  #define usb1_windexh                                   (*(volatile unsigned int *)usb1_windexh_adr)
  #define usb1_wlengthl_adr                              0x00363428                                                   // usb1_usb_base + 0x00000028
  #define usb1_wlengthl                                  (*(volatile unsigned int *)usb1_wlengthl_adr)
  #define usb1_wlengthh_adr                              0x0036342c                                                   // usb1_usb_base + 0x0000002c
  #define usb1_wlengthh                                  (*(volatile unsigned int *)usb1_wlengthh_adr)
  #define usb1_rw_duration_adr                           0x00363430                                                   // usb1_usb_base + 0x00000030
  #define usb1_rw_duration                               (*(volatile unsigned int *)usb1_rw_duration_adr)
  #define usb1_num_intaltset_in_cfg1_adr                 0x00363434                                                   // usb1_usb_base + 0x00000034
  #define usb1_num_intaltset_in_cfg1                     (*(volatile unsigned int *)usb1_num_intaltset_in_cfg1_adr)
  #define usb1_xcvr_tm_cfg_adr                           0x00363438                                                   // usb1_usb_base + 0x00000038
  #define usb1_xcvr_tm_cfg                               (*(volatile unsigned int *)usb1_xcvr_tm_cfg_adr)
  #define usb1_xcvr_tm_dp_xmit_adr                       0x0036343c                                                   // usb1_usb_base + 0x0000003c
  #define usb1_xcvr_tm_dp_xmit                           (*(volatile unsigned int *)usb1_xcvr_tm_dp_xmit_adr)
  #define usb1_xcvr_tm_dm_xmit_adr                       0x00363440                                                   // usb1_usb_base + 0x00000040
  #define usb1_xcvr_tm_dm_xmit                           (*(volatile unsigned int *)usb1_xcvr_tm_dm_xmit_adr)
  #define usb1_usbd_ECO_USBD_adr                         0x003634fc                                                   // usb1_usb_base + 0x000000fc
  #define usb1_usbd_ECO_USBD                             (*(volatile unsigned int *)usb1_usbd_ECO_USBD_adr)
  #define usb1_ep0_data_adr                              0x00363500                                                   // usb1_usb_base + 0x00000100
  #define usb1_ep0_data                                  (*(volatile unsigned int *)usb1_ep0_data_adr)
  #define usb1_ep1_data_adr                              0x00363540                                                   // usb1_usb_base + 0x00000140
  #define usb1_ep1_data                                  (*(volatile unsigned int *)usb1_ep1_data_adr)
  #define usb1_ep2_data_adr                              0x00363580                                                   // usb1_usb_base + 0x00000180
  #define usb1_ep2_data                                  (*(volatile unsigned int *)usb1_ep2_data_adr)
  #define usb1_ep3_data_adr                              0x003635c0                                                   // usb1_usb_base + 0x000001c0
  #define usb1_ep3_data                                  (*(volatile unsigned int *)usb1_ep3_data_adr)
  #define usb1_ep4_data_adr                              0x00363600                                                   // usb1_usb_base + 0x00000200
  #define usb1_ep4_data                                  (*(volatile unsigned int *)usb1_ep4_data_adr)
  #define usb1_epi_trg_adr                               0x00363700                                                   // usb1_usb_base + 0x00000300
  #define usb1_epi_trg                                   (*(volatile unsigned int *)usb1_epi_trg_adr)
  #define usb1_epi_0ln_trg_adr                           0x00363704                                                   // usb1_usb_base + 0x00000304
  #define usb1_epi_0ln_trg                               (*(volatile unsigned int *)usb1_epi_0ln_trg_adr)
  #define usb1_usb_flush_fifo_adr                        0x00363708                                                   // usb1_usb_base + 0x00000308
  #define usb1_usb_flush_fifo                            (*(volatile unsigned int *)usb1_usb_flush_fifo_adr)
  #define usb1_ep2_dma_cfg_adr                           0x0036370c                                                   // usb1_usb_base + 0x0000030c
  #define usb1_ep2_dma_cfg                               (*(volatile unsigned int *)usb1_ep2_dma_cfg_adr)
  #define usb1_ep2i_hci_pkglen_adr                       0x00363710                                                   // usb1_usb_base + 0x00000310
  #define usb1_ep2i_hci_pkglen                           (*(volatile unsigned int *)usb1_ep2i_hci_pkglen_adr)
  #define usb1_ep2o_hci_pkglen_adr                       0x00363714                                                   // usb1_usb_base + 0x00000314
  #define usb1_ep2o_hci_pkglen                           (*(volatile unsigned int *)usb1_ep2o_hci_pkglen_adr)
  #define usb1_ep3i_bytes_in_fifo_adr                    0x00363718                                                   // usb1_usb_base + 0x00000318
  #define usb1_ep3i_bytes_in_fifo                        (*(volatile unsigned int *)usb1_ep3i_bytes_in_fifo_adr)
  #define usb1_ep3i_empty_watermark_adr                  0x0036371c                                                   // usb1_usb_base + 0x0000031c
  #define usb1_ep3i_empty_watermark                      (*(volatile unsigned int *)usb1_ep3i_empty_watermark_adr)
  #define usb1_ep3i_pkt_size_adr                         0x00363720                                                   // usb1_usb_base + 0x00000320
  #define usb1_ep3i_pkt_size                             (*(volatile unsigned int *)usb1_ep3i_pkt_size_adr)
  #define usb1_ep3o_bytes_in_fifo_adr                    0x00363724                                                   // usb1_usb_base + 0x00000324
  #define usb1_ep3o_bytes_in_fifo                        (*(volatile unsigned int *)usb1_ep3o_bytes_in_fifo_adr)
  #define usb1_ep3o_full_watermark_adr                   0x00363728                                                   // usb1_usb_base + 0x00000328
  #define usb1_ep3o_full_watermark                       (*(volatile unsigned int *)usb1_ep3o_full_watermark_adr)
  #define usb1_ep0o_pklen_adr                            0x00363730                                                   // usb1_usb_base + 0x00000330
  #define usb1_ep0o_pklen                                (*(volatile unsigned int *)usb1_ep0o_pklen_adr)
  #define usb1_ep2o_pklen_adr                            0x00363738                                                   // usb1_usb_base + 0x00000338
  #define usb1_ep2o_pklen                                (*(volatile unsigned int *)usb1_ep2o_pklen_adr)
  #define usb1_ep3o_pklen_adr                            0x0036373c                                                   // usb1_usb_base + 0x0000033c
  #define usb1_ep3o_pklen                                (*(volatile unsigned int *)usb1_ep3o_pklen_adr)
  #define usb1_ep4o_pklen_adr                            0x00363740                                                   // usb1_usb_base + 0x00000340
  #define usb1_ep4o_pklen                                (*(volatile unsigned int *)usb1_ep4o_pklen_adr)
  #define usb1_usbd_ECO_ARMD_adr                         0x0036377c                                                   // usb1_usb_base + 0x0000037c
  #define usb1_usbd_ECO_ARMD                             (*(volatile unsigned int *)usb1_usbd_ECO_ARMD_adr)
  #define usb1_epi_empty_int_status_adr                  0x00363780                                                   // usb1_usb_base + 0x00000380
  #define usb1_epi_empty_int_status                      (*(volatile unsigned int *)usb1_epi_empty_int_status_adr)
  #define usb1_epo_ready_int_status_adr                  0x00363784                                                   // usb1_usb_base + 0x00000384
  #define usb1_epo_ready_int_status                      (*(volatile unsigned int *)usb1_epo_ready_int_status_adr)
  #define usb1_device_int_status_adr                     0x00363788                                                   // usb1_usb_base + 0x00000388
  #define usb1_device_int_status                         (*(volatile unsigned int *)usb1_device_int_status_adr)
  #define usb1_epi_0ln_done_int_status_adr               0x0036378c                                                   // usb1_usb_base + 0x0000038c
  #define usb1_epi_0ln_done_int_status                   (*(volatile unsigned int *)usb1_epi_0ln_done_int_status_adr)
  #define usb1_epi_empty_int_en_adr                      0x003637c0                                                   // usb1_usb_base + 0x000003c0
  #define usb1_epi_empty_int_en                          (*(volatile unsigned int *)usb1_epi_empty_int_en_adr)
  #define usb1_epo_ready_int_en_adr                      0x003637c4                                                   // usb1_usb_base + 0x000003c4
  #define usb1_epo_ready_int_en                          (*(volatile unsigned int *)usb1_epo_ready_int_en_adr)
  #define usb1_device_int_en_adr                         0x003637c8                                                   // usb1_usb_base + 0x000003c8
  #define usb1_device_int_en                             (*(volatile unsigned int *)usb1_device_int_en_adr)
  #define usb1_epi_0ln_done_int_en_adr                   0x003637cc                                                   // usb1_usb_base + 0x000003cc
  #define usb1_epi_0ln_done_int_en                       (*(volatile unsigned int *)usb1_epi_0ln_done_int_en_adr)
  #define usb1_device_int_cfg_adr                        0x003637d0                                                   // usb1_usb_base + 0x000003d0
  #define usb1_device_int_cfg                            (*(volatile unsigned int *)usb1_device_int_cfg_adr)
  #define usb1_ctrl_adr                                  0x003637d4                                                   // usb1_usb_base + 0x000003d4
  #define usb1_ctrl                                      (*(volatile unsigned int *)usb1_ctrl_adr)
  #define usb2_cfg_adr                                   0x00363800                                                   // usb2_usb_base + 0x00000000
  #define usb2_cfg                                       (*(volatile unsigned int *)usb2_cfg_adr)
  #define usb2_interfaceval_adr                          0x00363804                                                   // usb2_usb_base + 0x00000004
  #define usb2_interfaceval                              (*(volatile unsigned int *)usb2_interfaceval_adr)
  #define usb2_tran_ctrl_adr                             0x00363808                                                   // usb2_usb_base + 0x00000008
  #define usb2_tran_ctrl                                 (*(volatile unsigned int *)usb2_tran_ctrl_adr)
  #define usb2_cfgnum_adr                                0x0036380c                                                   // usb2_usb_base + 0x0000000c
  #define usb2_cfgnum                                    (*(volatile unsigned int *)usb2_cfgnum_adr)
  #define usb2_bmrt_adr                                  0x00363810                                                   // usb2_usb_base + 0x00000010
  #define usb2_bmrt                                      (*(volatile unsigned int *)usb2_bmrt_adr)
  #define usb2_brequest_adr                              0x00363814                                                   // usb2_usb_base + 0x00000014
  #define usb2_brequest                                  (*(volatile unsigned int *)usb2_brequest_adr)
  #define usb2_wvaluel_adr                               0x00363818                                                   // usb2_usb_base + 0x00000018
  #define usb2_wvaluel                                   (*(volatile unsigned int *)usb2_wvaluel_adr)
  #define usb2_wvalueh_adr                               0x0036381c                                                   // usb2_usb_base + 0x0000001c
  #define usb2_wvalueh                                   (*(volatile unsigned int *)usb2_wvalueh_adr)
  #define usb2_windexl_adr                               0x00363820                                                   // usb2_usb_base + 0x00000020
  #define usb2_windexl                                   (*(volatile unsigned int *)usb2_windexl_adr)
  #define usb2_windexh_adr                               0x00363824                                                   // usb2_usb_base + 0x00000024
  #define usb2_windexh                                   (*(volatile unsigned int *)usb2_windexh_adr)
  #define usb2_wlengthl_adr                              0x00363828                                                   // usb2_usb_base + 0x00000028
  #define usb2_wlengthl                                  (*(volatile unsigned int *)usb2_wlengthl_adr)
  #define usb2_wlengthh_adr                              0x0036382c                                                   // usb2_usb_base + 0x0000002c
  #define usb2_wlengthh                                  (*(volatile unsigned int *)usb2_wlengthh_adr)
  #define usb2_rw_duration_adr                           0x00363830                                                   // usb2_usb_base + 0x00000030
  #define usb2_rw_duration                               (*(volatile unsigned int *)usb2_rw_duration_adr)
  #define usb2_num_intaltset_in_cfg1_adr                 0x00363834                                                   // usb2_usb_base + 0x00000034
  #define usb2_num_intaltset_in_cfg1                     (*(volatile unsigned int *)usb2_num_intaltset_in_cfg1_adr)
  #define usb2_xcvr_tm_cfg_adr                           0x00363838                                                   // usb2_usb_base + 0x00000038
  #define usb2_xcvr_tm_cfg                               (*(volatile unsigned int *)usb2_xcvr_tm_cfg_adr)
  #define usb2_xcvr_tm_dp_xmit_adr                       0x0036383c                                                   // usb2_usb_base + 0x0000003c
  #define usb2_xcvr_tm_dp_xmit                           (*(volatile unsigned int *)usb2_xcvr_tm_dp_xmit_adr)
  #define usb2_xcvr_tm_dm_xmit_adr                       0x00363840                                                   // usb2_usb_base + 0x00000040
  #define usb2_xcvr_tm_dm_xmit                           (*(volatile unsigned int *)usb2_xcvr_tm_dm_xmit_adr)
  #define usb2_usbd_ECO_USBD_adr                         0x003638fc                                                   // usb2_usb_base + 0x000000fc
  #define usb2_usbd_ECO_USBD                             (*(volatile unsigned int *)usb2_usbd_ECO_USBD_adr)
  #define usb2_ep0_data_adr                              0x00363900                                                   // usb2_usb_base + 0x00000100
  #define usb2_ep0_data                                  (*(volatile unsigned int *)usb2_ep0_data_adr)
  #define usb2_ep1_data_adr                              0x00363940                                                   // usb2_usb_base + 0x00000140
  #define usb2_ep1_data                                  (*(volatile unsigned int *)usb2_ep1_data_adr)
  #define usb2_ep2_data_adr                              0x00363980                                                   // usb2_usb_base + 0x00000180
  #define usb2_ep2_data                                  (*(volatile unsigned int *)usb2_ep2_data_adr)
  #define usb2_ep3_data_adr                              0x003639c0                                                   // usb2_usb_base + 0x000001c0
  #define usb2_ep3_data                                  (*(volatile unsigned int *)usb2_ep3_data_adr)
  #define usb2_ep4_data_adr                              0x00363a00                                                   // usb2_usb_base + 0x00000200
  #define usb2_ep4_data                                  (*(volatile unsigned int *)usb2_ep4_data_adr)
  #define usb2_epi_trg_adr                               0x00363b00                                                   // usb2_usb_base + 0x00000300
  #define usb2_epi_trg                                   (*(volatile unsigned int *)usb2_epi_trg_adr)
  #define usb2_epi_0ln_trg_adr                           0x00363b04                                                   // usb2_usb_base + 0x00000304
  #define usb2_epi_0ln_trg                               (*(volatile unsigned int *)usb2_epi_0ln_trg_adr)
  #define usb2_usb_flush_fifo_adr                        0x00363b08                                                   // usb2_usb_base + 0x00000308
  #define usb2_usb_flush_fifo                            (*(volatile unsigned int *)usb2_usb_flush_fifo_adr)
  #define usb2_ep2_dma_cfg_adr                           0x00363b0c                                                   // usb2_usb_base + 0x0000030c
  #define usb2_ep2_dma_cfg                               (*(volatile unsigned int *)usb2_ep2_dma_cfg_adr)
  #define usb2_ep2i_hci_pkglen_adr                       0x00363b10                                                   // usb2_usb_base + 0x00000310
  #define usb2_ep2i_hci_pkglen                           (*(volatile unsigned int *)usb2_ep2i_hci_pkglen_adr)
  #define usb2_ep2o_hci_pkglen_adr                       0x00363b14                                                   // usb2_usb_base + 0x00000314
  #define usb2_ep2o_hci_pkglen                           (*(volatile unsigned int *)usb2_ep2o_hci_pkglen_adr)
  #define usb2_ep3i_bytes_in_fifo_adr                    0x00363b18                                                   // usb2_usb_base + 0x00000318
  #define usb2_ep3i_bytes_in_fifo                        (*(volatile unsigned int *)usb2_ep3i_bytes_in_fifo_adr)
  #define usb2_ep3i_empty_watermark_adr                  0x00363b1c                                                   // usb2_usb_base + 0x0000031c
  #define usb2_ep3i_empty_watermark                      (*(volatile unsigned int *)usb2_ep3i_empty_watermark_adr)
  #define usb2_ep3i_pkt_size_adr                         0x00363b20                                                   // usb2_usb_base + 0x00000320
  #define usb2_ep3i_pkt_size                             (*(volatile unsigned int *)usb2_ep3i_pkt_size_adr)
  #define usb2_ep3o_bytes_in_fifo_adr                    0x00363b24                                                   // usb2_usb_base + 0x00000324
  #define usb2_ep3o_bytes_in_fifo                        (*(volatile unsigned int *)usb2_ep3o_bytes_in_fifo_adr)
  #define usb2_ep3o_full_watermark_adr                   0x00363b28                                                   // usb2_usb_base + 0x00000328
  #define usb2_ep3o_full_watermark                       (*(volatile unsigned int *)usb2_ep3o_full_watermark_adr)
  #define usb2_ep0o_pklen_adr                            0x00363b30                                                   // usb2_usb_base + 0x00000330
  #define usb2_ep0o_pklen                                (*(volatile unsigned int *)usb2_ep0o_pklen_adr)
  #define usb2_ep2o_pklen_adr                            0x00363b38                                                   // usb2_usb_base + 0x00000338
  #define usb2_ep2o_pklen                                (*(volatile unsigned int *)usb2_ep2o_pklen_adr)
  #define usb2_ep3o_pklen_adr                            0x00363b3c                                                   // usb2_usb_base + 0x0000033c
  #define usb2_ep3o_pklen                                (*(volatile unsigned int *)usb2_ep3o_pklen_adr)
  #define usb2_ep4o_pklen_adr                            0x00363b40                                                   // usb2_usb_base + 0x00000340
  #define usb2_ep4o_pklen                                (*(volatile unsigned int *)usb2_ep4o_pklen_adr)
  #define usb2_usbd_ECO_ARMD_adr                         0x00363b7c                                                   // usb2_usb_base + 0x0000037c
  #define usb2_usbd_ECO_ARMD                             (*(volatile unsigned int *)usb2_usbd_ECO_ARMD_adr)
  #define usb2_epi_empty_int_status_adr                  0x00363b80                                                   // usb2_usb_base + 0x00000380
  #define usb2_epi_empty_int_status                      (*(volatile unsigned int *)usb2_epi_empty_int_status_adr)
  #define usb2_epo_ready_int_status_adr                  0x00363b84                                                   // usb2_usb_base + 0x00000384
  #define usb2_epo_ready_int_status                      (*(volatile unsigned int *)usb2_epo_ready_int_status_adr)
  #define usb2_device_int_status_adr                     0x00363b88                                                   // usb2_usb_base + 0x00000388
  #define usb2_device_int_status                         (*(volatile unsigned int *)usb2_device_int_status_adr)
  #define usb2_epi_0ln_done_int_status_adr               0x00363b8c                                                   // usb2_usb_base + 0x0000038c
  #define usb2_epi_0ln_done_int_status                   (*(volatile unsigned int *)usb2_epi_0ln_done_int_status_adr)
  #define usb2_epi_empty_int_en_adr                      0x00363bc0                                                   // usb2_usb_base + 0x000003c0
  #define usb2_epi_empty_int_en                          (*(volatile unsigned int *)usb2_epi_empty_int_en_adr)
  #define usb2_epo_ready_int_en_adr                      0x00363bc4                                                   // usb2_usb_base + 0x000003c4
  #define usb2_epo_ready_int_en                          (*(volatile unsigned int *)usb2_epo_ready_int_en_adr)
  #define usb2_device_int_en_adr                         0x00363bc8                                                   // usb2_usb_base + 0x000003c8
  #define usb2_device_int_en                             (*(volatile unsigned int *)usb2_device_int_en_adr)
  #define usb2_epi_0ln_done_int_en_adr                   0x00363bcc                                                   // usb2_usb_base + 0x000003cc
  #define usb2_epi_0ln_done_int_en                       (*(volatile unsigned int *)usb2_epi_0ln_done_int_en_adr)
  #define usb2_device_int_cfg_adr                        0x00363bd0                                                   // usb2_usb_base + 0x000003d0
  #define usb2_device_int_cfg                            (*(volatile unsigned int *)usb2_device_int_cfg_adr)
  #define usb2_ctrl_adr                                  0x00363bd4                                                   // usb2_usb_base + 0x000003d4
  #define usb2_ctrl                                      (*(volatile unsigned int *)usb2_ctrl_adr)
  #define gpio_o_val_port0_adr                           0x00336110                                                   // lhl_adr_base + 0x00000110
  #define gpio_o_val_port0                               (*(volatile unsigned int *)gpio_o_val_port0_adr)
  #define gpio_o_val_port1_adr                           0x00336114                                                   // lhl_adr_base + 0x00000114
  #define gpio_o_val_port1                               (*(volatile unsigned int *)gpio_o_val_port1_adr)
  #define gpio_o_val_port2_adr                           0x00336118                                                   // lhl_adr_base + 0x00000118
  #define gpio_o_val_port2                               (*(volatile unsigned int *)gpio_o_val_port2_adr)
  #define gpio_int_st_port0_adr                          0x00336120                                                   // lhl_adr_base + 0x00000120
  #define gpio_int_st_port0                              (*(volatile unsigned int *)gpio_int_st_port0_adr)
  #define gpio_int_st_port1_adr                          0x00336124                                                   // lhl_adr_base + 0x00000124
  #define gpio_int_st_port1                              (*(volatile unsigned int *)gpio_int_st_port1_adr)
  #define gpio_int_st_port2_adr                          0x00336128                                                   // lhl_adr_base + 0x00000128
  #define gpio_int_st_port2                              (*(volatile unsigned int *)gpio_int_st_port2_adr)
  #define lhl_ctl_adr                                    0x00336130                                                   // lhl_adr_base + 0x00000130
  #define lhl_ctl                                        (*(volatile unsigned int *)lhl_ctl_adr)
  #define lhl_status_adr                                 0x00336134                                                   // lhl_adr_base + 0x00000134
  #define lhl_status                                     (*(volatile unsigned int *)lhl_status_adr)
  #define hidoff_keepstate0_adr                          0x00336138                                                   // lhl_adr_base + 0x00000138
  #define hidoff_keepstate0                              (*(volatile unsigned int *)hidoff_keepstate0_adr)
  #define hidoff_keepstate1_adr                          0x0033613c                                                   // lhl_adr_base + 0x0000013c
  #define hidoff_keepstate1                              (*(volatile unsigned int *)hidoff_keepstate1_adr)
  #define hidoff_cnt0_adr                                0x00336140                                                   // lhl_adr_base + 0x00000140
  #define hidoff_cnt0                                    (*(volatile unsigned int *)hidoff_cnt0_adr)
  #define hidoff_cnt1_adr                                0x00336144                                                   // lhl_adr_base + 0x00000144
  #define hidoff_cnt1                                    (*(volatile unsigned int *)hidoff_cnt1_adr)
  #define lpo_ctl_adr                                    0x00336148                                                   // lhl_adr_base + 0x00000148
  #define lpo_ctl                                        (*(volatile unsigned int *)lpo_ctl_adr)
  #define ldo_ctl0_adr                                   0x0033614c                                                   // lhl_adr_base + 0x0000014c
  #define ldo_ctl0                                       (*(volatile unsigned int *)ldo_ctl0_adr)
  #define ldo_ctl1_adr                                   0x00336150                                                   // lhl_adr_base + 0x00000150
  #define ldo_ctl1                                       (*(volatile unsigned int *)ldo_ctl1_adr)
  #define lhl_adc_ctl_adr                                0x00336154                                                   // lhl_adr_base + 0x00000154
  #define lhl_adc_ctl                                    (*(volatile unsigned int *)lhl_adc_ctl_adr)
  #define ldo_ctl_en_adr                                 0x0033615c                                                   // lhl_adr_base + 0x0000015c
  #define ldo_ctl_en                                     (*(volatile unsigned int *)ldo_ctl_en_adr)
  #define qdxyz_in_dly_adr                               0x00336164                                                   // lhl_adr_base + 0x00000164
  #define qdxyz_in_dly                                   (*(volatile unsigned int *)qdxyz_in_dly_adr)
  #define ch_sel_cfg_adr                                 0x00336168                                                   // lhl_adr_base + 0x00000168
  #define ch_sel_cfg                                     (*(volatile unsigned int *)ch_sel_cfg_adr)
  #define optctl_adr                                     0x0033619c                                                   // lhl_adr_base + 0x0000019c
  #define optctl                                         (*(volatile unsigned int *)optctl_adr)
  #define realtimeclk1_adr                               0x003361a0                                                   // lhl_adr_base + 0x000001a0
  #define realtimeclk1                                   (*(volatile unsigned int *)realtimeclk1_adr)
  #define realtimeclk2_adr                               0x003361a4                                                   // lhl_adr_base + 0x000001a4
  #define realtimeclk2                                   (*(volatile unsigned int *)realtimeclk2_adr)
  #define realtimeclk3_adr                               0x003361a8                                                   // lhl_adr_base + 0x000001a8
  #define realtimeclk3                                   (*(volatile unsigned int *)realtimeclk3_adr)
  #define iocfg_premux_adr                               0x003361fc                                                   // lhl_adr_base + 0x000001fc
  #define iocfg_premux                                   (*(volatile unsigned int *)iocfg_premux_adr)
  #define iocfg_p0_adr                                   0x00336200                                                   // lhl_adr_base + 0x00000200
  #define iocfg_p0                                       (*(volatile unsigned int *)iocfg_p0_adr)
  #define iocfg_p1_adr                                   0x00336204                                                   // lhl_adr_base + 0x00000204
  #define iocfg_p1                                       (*(volatile unsigned int *)iocfg_p1_adr)
  #define iocfg_p2_adr                                   0x00336208                                                   // lhl_adr_base + 0x00000208
  #define iocfg_p2                                       (*(volatile unsigned int *)iocfg_p2_adr)
  #define iocfg_p3_adr                                   0x0033620c                                                   // lhl_adr_base + 0x0000020c
  #define iocfg_p3                                       (*(volatile unsigned int *)iocfg_p3_adr)
  #define iocfg_p4_adr                                   0x00336210                                                   // lhl_adr_base + 0x00000210
  #define iocfg_p4                                       (*(volatile unsigned int *)iocfg_p4_adr)
  #define iocfg_p5_adr                                   0x00336214                                                   // lhl_adr_base + 0x00000214
  #define iocfg_p5                                       (*(volatile unsigned int *)iocfg_p5_adr)
  #define iocfg_p6_adr                                   0x00336218                                                   // lhl_adr_base + 0x00000218
  #define iocfg_p6                                       (*(volatile unsigned int *)iocfg_p6_adr)
  #define iocfg_p7_adr                                   0x0033621c                                                   // lhl_adr_base + 0x0000021c
  #define iocfg_p7                                       (*(volatile unsigned int *)iocfg_p7_adr)
  #define iocfg_p8_adr                                   0x00336220                                                   // lhl_adr_base + 0x00000220
  #define iocfg_p8                                       (*(volatile unsigned int *)iocfg_p8_adr)
  #define iocfg_p9_adr                                   0x00336224                                                   // lhl_adr_base + 0x00000224
  #define iocfg_p9                                       (*(volatile unsigned int *)iocfg_p9_adr)
  #define iocfg_p10_adr                                  0x00336228                                                   // lhl_adr_base + 0x00000228
  #define iocfg_p10                                      (*(volatile unsigned int *)iocfg_p10_adr)
  #define iocfg_p11_adr                                  0x0033622c                                                   // lhl_adr_base + 0x0000022c
  #define iocfg_p11                                      (*(volatile unsigned int *)iocfg_p11_adr)
  #define iocfg_p12_adr                                  0x00336230                                                   // lhl_adr_base + 0x00000230
  #define iocfg_p12                                      (*(volatile unsigned int *)iocfg_p12_adr)
  #define iocfg_p13_adr                                  0x00336234                                                   // lhl_adr_base + 0x00000234
  #define iocfg_p13                                      (*(volatile unsigned int *)iocfg_p13_adr)
  #define iocfg_p14_adr                                  0x00336238                                                   // lhl_adr_base + 0x00000238
  #define iocfg_p14                                      (*(volatile unsigned int *)iocfg_p14_adr)
  #define iocfg_p15_adr                                  0x0033623c                                                   // lhl_adr_base + 0x0000023c
  #define iocfg_p15                                      (*(volatile unsigned int *)iocfg_p15_adr)
  #define iocfg_p16_adr                                  0x00336240                                                   // lhl_adr_base + 0x00000240
  #define iocfg_p16                                      (*(volatile unsigned int *)iocfg_p16_adr)
  #define iocfg_p17_adr                                  0x00336244                                                   // lhl_adr_base + 0x00000244
  #define iocfg_p17                                      (*(volatile unsigned int *)iocfg_p17_adr)
  #define iocfg_p18_adr                                  0x00336248                                                   // lhl_adr_base + 0x00000248
  #define iocfg_p18                                      (*(volatile unsigned int *)iocfg_p18_adr)
  #define iocfg_p19_adr                                  0x0033624c                                                   // lhl_adr_base + 0x0000024c
  #define iocfg_p19                                      (*(volatile unsigned int *)iocfg_p19_adr)
  #define iocfg_p20_adr                                  0x00336250                                                   // lhl_adr_base + 0x00000250
  #define iocfg_p20                                      (*(volatile unsigned int *)iocfg_p20_adr)
  #define iocfg_p21_adr                                  0x00336254                                                   // lhl_adr_base + 0x00000254
  #define iocfg_p21                                      (*(volatile unsigned int *)iocfg_p21_adr)
  #define iocfg_p22_adr                                  0x00336258                                                   // lhl_adr_base + 0x00000258
  #define iocfg_p22                                      (*(volatile unsigned int *)iocfg_p22_adr)
  #define iocfg_p23_adr                                  0x0033625c                                                   // lhl_adr_base + 0x0000025c
  #define iocfg_p23                                      (*(volatile unsigned int *)iocfg_p23_adr)
  #define iocfg_p24_adr                                  0x00336260                                                   // lhl_adr_base + 0x00000260
  #define iocfg_p24                                      (*(volatile unsigned int *)iocfg_p24_adr)
  #define iocfg_p25_adr                                  0x00336264                                                   // lhl_adr_base + 0x00000264
  #define iocfg_p25                                      (*(volatile unsigned int *)iocfg_p25_adr)
  #define iocfg_p26_adr                                  0x00336268                                                   // lhl_adr_base + 0x00000268
  #define iocfg_p26                                      (*(volatile unsigned int *)iocfg_p26_adr)
  #define iocfg_p27_adr                                  0x0033626c                                                   // lhl_adr_base + 0x0000026c
  #define iocfg_p27                                      (*(volatile unsigned int *)iocfg_p27_adr)
  #define iocfg_p28_adr                                  0x00336270                                                   // lhl_adr_base + 0x00000270
  #define iocfg_p28                                      (*(volatile unsigned int *)iocfg_p28_adr)
  #define iocfg_p29_adr                                  0x00336274                                                   // lhl_adr_base + 0x00000274
  #define iocfg_p29                                      (*(volatile unsigned int *)iocfg_p29_adr)
  #define iocfg_p30_adr                                  0x00336278                                                   // lhl_adr_base + 0x00000278
  #define iocfg_p30                                      (*(volatile unsigned int *)iocfg_p30_adr)
  #define iocfg_p31_adr                                  0x0033627c                                                   // lhl_adr_base + 0x0000027c
  #define iocfg_p31                                      (*(volatile unsigned int *)iocfg_p31_adr)
  #define iocfg_p32_adr                                  0x00336280                                                   // lhl_adr_base + 0x00000280
  #define iocfg_p32                                      (*(volatile unsigned int *)iocfg_p32_adr)
  #define iocfg_p33_adr                                  0x00336284                                                   // lhl_adr_base + 0x00000284
  #define iocfg_p33                                      (*(volatile unsigned int *)iocfg_p33_adr)
  #define iocfg_p34_adr                                  0x00336288                                                   // lhl_adr_base + 0x00000288
  #define iocfg_p34                                      (*(volatile unsigned int *)iocfg_p34_adr)
  #define iocfg_p35_adr                                  0x0033628c                                                   // lhl_adr_base + 0x0000028c
  #define iocfg_p35                                      (*(volatile unsigned int *)iocfg_p35_adr)
  #define iocfg_p36_adr                                  0x00336290                                                   // lhl_adr_base + 0x00000290
  #define iocfg_p36                                      (*(volatile unsigned int *)iocfg_p36_adr)
  #define iocfg_p37_adr                                  0x00336294                                                   // lhl_adr_base + 0x00000294
  #define iocfg_p37                                      (*(volatile unsigned int *)iocfg_p37_adr)
  #define iocfg_p38_adr                                  0x00336298                                                   // lhl_adr_base + 0x00000298
  #define iocfg_p38                                      (*(volatile unsigned int *)iocfg_p38_adr)
  #define iocfg_p39_adr                                  0x0033629c                                                   // lhl_adr_base + 0x0000029c
  #define iocfg_p39                                      (*(volatile unsigned int *)iocfg_p39_adr)
  #define scanp_cntr_init_val_adr                        0x003362b0                                                   // lhl_adr_base + 0x000002b0
  #define scanp_cntr_init_val                            (*(volatile unsigned int *)scanp_cntr_init_val_adr)
  #define opt0_togg_val_adr                              0x003362b4                                                   // lhl_adr_base + 0x000002b4
  #define opt0_togg_val                                  (*(volatile unsigned int *)opt0_togg_val_adr)
  #define opt1_togg_val_adr                              0x003362b8                                                   // lhl_adr_base + 0x000002b8
  #define opt1_togg_val                                  (*(volatile unsigned int *)opt1_togg_val_adr)
  #define opt2_togg_val_adr                              0x003362bc                                                   // lhl_adr_base + 0x000002bc
  #define opt2_togg_val                                  (*(volatile unsigned int *)opt2_togg_val_adr)
  #define opt3_togg_val_adr                              0x003362c0                                                   // lhl_adr_base + 0x000002c0
  #define opt3_togg_val                                  (*(volatile unsigned int *)opt3_togg_val_adr)
  #define optx_smp_val_adr                               0x003362cc                                                   // lhl_adr_base + 0x000002cc
  #define optx_smp_val                                   (*(volatile unsigned int *)optx_smp_val_adr)
  #define opty_smp_val_adr                               0x003362d0                                                   // lhl_adr_base + 0x000002d0
  #define opty_smp_val                                   (*(volatile unsigned int *)opty_smp_val_adr)
  #define optz_smp_val_adr                               0x003362d4                                                   // lhl_adr_base + 0x000002d4
  #define optz_smp_val                                   (*(volatile unsigned int *)optz_smp_val_adr)
  #define hidoff_keepstate2_adr                          0x003362d8                                                   // lhl_adr_base + 0x000002d8
  #define hidoff_keepstate2                              (*(volatile unsigned int *)hidoff_keepstate2_adr)
  #define keyscan_ctl_adr                                0x00334000                                                   // mia_adr_base + 0x00000000
  #define keyscan_ctl                                    (*(volatile unsigned int *)keyscan_ctl_adr)
  #define debounce_adr                                   0x00334004                                                   // mia_adr_base + 0x00000004
  #define debounce                                       (*(volatile unsigned int *)debounce_adr)
  #define keyfifo_cnt_adr                                0x00334008                                                   // mia_adr_base + 0x00000008
  #define keyfifo_cnt                                    (*(volatile unsigned int *)keyfifo_cnt_adr)
  #define keyfifo_adr                                    0x0033400c                                                   // mia_adr_base + 0x0000000c
  #define keyfifo                                        (*(volatile unsigned int *)keyfifo_adr)
  #define mia_irq_cfg_adr                                0x00334010                                                   // mia_adr_base + 0x00000010
  #define mia_irq_cfg                                    (*(volatile unsigned int *)mia_irq_cfg_adr)
  #define mia_ctl_adr                                    0x00334014                                                   // mia_adr_base + 0x00000014
  #define mia_ctl                                        (*(volatile unsigned int *)mia_ctl_adr)
  #define mia_status_adr                                 0x00334018                                                   // mia_adr_base + 0x00000018
  #define mia_status                                     (*(volatile unsigned int *)mia_status_adr)
  #define mia_dbg_adr                                    0x0033401c                                                   // mia_adr_base + 0x0000001c
  #define mia_dbg                                        (*(volatile unsigned int *)mia_dbg_adr)
  #define qctl_adr                                       0x00334020                                                   // mia_adr_base + 0x00000020
  #define qctl                                           (*(volatile unsigned int *)qctl_adr)
  #define qd_ch_en_adr                                   0x00334024                                                   // mia_adr_base + 0x00000024
  #define qd_ch_en                                       (*(volatile unsigned int *)qd_ch_en_adr)
  #define qdx_cnt_adr                                    0x00334028                                                   // mia_adr_base + 0x00000028
  #define qdx_cnt                                        (*(volatile unsigned int *)qdx_cnt_adr)
  #define qdy_cnt_adr                                    0x0033402c                                                   // mia_adr_base + 0x0000002c
  #define qdy_cnt                                        (*(volatile unsigned int *)qdy_cnt_adr)
  #define qdz_cnt_adr                                    0x00334030                                                   // mia_adr_base + 0x00000030
  #define qdz_cnt                                        (*(volatile unsigned int *)qdz_cnt_adr)
  #define qflag_adr                                      0x00334034                                                   // mia_adr_base + 0x00000034
  #define qflag                                          (*(volatile unsigned int *)qflag_adr)
  #define aclk_ctl_adr                                   0x00334038                                                   // mia_adr_base + 0x00000038
  #define aclk_ctl                                       (*(volatile unsigned int *)aclk_ctl_adr)
  #define reserved42_adr                                 0x0033403c                                                   // mia_adr_base + 0x0000003c
  #define reserved42                                     (*(volatile unsigned int *)reserved42_adr)
  #define mia_lpo_sel_adr                                0x00334040                                                   // mia_adr_base + 0x00000040
  #define mia_lpo_sel                                    (*(volatile unsigned int *)mia_lpo_sel_adr)
  #define mia_adc_intf_ctl_adr                           0x00334044                                                   // mia_adr_base + 0x00000044
  #define mia_adc_intf_ctl                               (*(volatile unsigned int *)mia_adc_intf_ctl_adr)
  #define mia_adc_dat_adr                                0x00334048                                                   // mia_adr_base + 0x00000048
  #define mia_adc_dat                                    (*(volatile unsigned int *)mia_adc_dat_adr)
  #define mia_ir_buf_ctl_adr                             0x0033404c                                                   // mia_adr_base + 0x0000004c
  #define mia_ir_buf_ctl                                 (*(volatile unsigned int *)mia_ir_buf_ctl_adr)
  #define mia_ir_cmd0_adr                                0x00334050                                                   // mia_adr_base + 0x00000050
  #define mia_ir_cmd0                                    (*(volatile unsigned int *)mia_ir_cmd0_adr)
  #define mia_ir_cmd1_adr                                0x00334054                                                   // mia_adr_base + 0x00000054
  #define mia_ir_cmd1                                    (*(volatile unsigned int *)mia_ir_cmd1_adr)
  #define mia_ir_cmd2_adr                                0x00334058                                                   // mia_adr_base + 0x00000058
  #define mia_ir_cmd2                                    (*(volatile unsigned int *)mia_ir_cmd2_adr)
  #define mia_ir_cmd3_adr                                0x0033405c                                                   // mia_adr_base + 0x0000005c
  #define mia_ir_cmd3                                    (*(volatile unsigned int *)mia_ir_cmd3_adr)
  #define mia_ir_cmd4_adr                                0x00334060                                                   // mia_adr_base + 0x00000060
  #define mia_ir_cmd4                                    (*(volatile unsigned int *)mia_ir_cmd4_adr)
  #define mia_ir_cmd5_adr                                0x00334064                                                   // mia_adr_base + 0x00000064
  #define mia_ir_cmd5                                    (*(volatile unsigned int *)mia_ir_cmd5_adr)
  #define mia_ir_cmd6_adr                                0x00334068                                                   // mia_adr_base + 0x00000068
  #define mia_ir_cmd6                                    (*(volatile unsigned int *)mia_ir_cmd6_adr)
  #define mia_ir_cmd7_adr                                0x0033406c                                                   // mia_adr_base + 0x0000006c
  #define mia_ir_cmd7                                    (*(volatile unsigned int *)mia_ir_cmd7_adr)
  #define mia_ir_ctl_adr                                 0x00334070                                                   // mia_adr_base + 0x00000070
  #define mia_ir_ctl                                     (*(volatile unsigned int *)mia_ir_ctl_adr)
  #define mia_irl_ctl_adr                                0x00334074                                                   // mia_adr_base + 0x00000074
  #define mia_irl_ctl                                    (*(volatile unsigned int *)mia_irl_ctl_adr)
  #define mia_irl_period_adr                             0x00334078                                                   // mia_adr_base + 0x00000078
  #define mia_irl_period                                 (*(volatile unsigned int *)mia_irl_period_adr)
  #define mia_irl_status_adr                             0x0033407c                                                   // mia_adr_base + 0x0000007c
  #define mia_irl_status                                 (*(volatile unsigned int *)mia_irl_status_adr)
  #define main60hz_ctl_adr                               0x00334080                                                   // mia_adr_base + 0x00000080
  #define main60hz_ctl                                   (*(volatile unsigned int *)main60hz_ctl_adr)
  #define triac_on_val1_adr                              0x00334084                                                   // mia_adr_base + 0x00000084
  #define triac_on_val1                                  (*(volatile unsigned int *)triac_on_val1_adr)
  #define triac_off_val1_adr                             0x00334088                                                   // mia_adr_base + 0x00000088
  #define triac_off_val1                                 (*(volatile unsigned int *)triac_off_val1_adr)
  #define triac_on_val2_adr                              0x0033408c                                                   // mia_adr_base + 0x0000008c
  #define triac_on_val2                                  (*(volatile unsigned int *)triac_on_val2_adr)
  #define triac_off_val2_adr                             0x00334090                                                   // mia_adr_base + 0x00000090
  #define triac_off_val2                                 (*(volatile unsigned int *)triac_off_val2_adr)
  #define main_debounce_val_adr                          0x00334094                                                   // mia_adr_base + 0x00000094
  #define main_debounce_val                              (*(volatile unsigned int *)main_debounce_val_adr)
  #define touch_measure_ctl_adr                          0x00334098                                                   // mia_adr_base + 0x00000098
  #define touch_measure_ctl                              (*(volatile unsigned int *)touch_measure_ctl_adr)
  #define touch_in_ctr_adr                               0x0033409c                                                   // mia_adr_base + 0x0000009c
  #define touch_in_ctr                                   (*(volatile unsigned int *)touch_in_ctr_adr)
  #define mia_adc_ctl0_adr                               0x003340a0                                                   // mia_adr_base + 0x000000a0
  #define mia_adc_ctl0                                   (*(volatile unsigned int *)mia_adc_ctl0_adr)
  #define mia_adc_ctl1_adr                               0x003340a4                                                   // mia_adr_base + 0x000000a4
  #define mia_adc_ctl1                                   (*(volatile unsigned int *)mia_adc_ctl1_adr)
  #define mia_adc_ctl2_adr                               0x003340a8                                                   // mia_adr_base + 0x000000a8
  #define mia_adc_ctl2                                   (*(volatile unsigned int *)mia_adc_ctl2_adr)
  #define triac_on_val3_adr                              0x003340b0                                                   // mia_adr_base + 0x000000b0
  #define triac_on_val3                                  (*(volatile unsigned int *)triac_on_val3_adr)
  #define triac_off_val3_adr                             0x003340b4                                                   // mia_adr_base + 0x000000b4
  #define triac_off_val3                                 (*(volatile unsigned int *)triac_off_val3_adr)
  #define triac_on_val4_adr                              0x003340b8                                                   // mia_adr_base + 0x000000b8
  #define triac_on_val4                                  (*(volatile unsigned int *)triac_on_val4_adr)
  #define triac_off_val4_adr                             0x003340bc                                                   // mia_adr_base + 0x000000bc
  #define triac_off_val4                                 (*(volatile unsigned int *)triac_off_val4_adr)
  #define pwm_cfg_adr                                    0x003340c0                                                   // mia_adr_base + 0x000000c0
  #define pwm_cfg                                        (*(volatile unsigned int *)pwm_cfg_adr)
  #define pwm0_init_val_adr                              0x003340c4                                                   // mia_adr_base + 0x000000c4
  #define pwm0_init_val                                  (*(volatile unsigned int *)pwm0_init_val_adr)
  #define pwm0_togg_val_adr                              0x003340c8                                                   // mia_adr_base + 0x000000c8
  #define pwm0_togg_val                                  (*(volatile unsigned int *)pwm0_togg_val_adr)
  #define pwm1_init_val_adr                              0x003340cc                                                   // mia_adr_base + 0x000000cc
  #define pwm1_init_val                                  (*(volatile unsigned int *)pwm1_init_val_adr)
  #define pwm1_togg_val_adr                              0x003340d0                                                   // mia_adr_base + 0x000000d0
  #define pwm1_togg_val                                  (*(volatile unsigned int *)pwm1_togg_val_adr)
  #define pwm2_init_val_adr                              0x003340d4                                                   // mia_adr_base + 0x000000d4
  #define pwm2_init_val                                  (*(volatile unsigned int *)pwm2_init_val_adr)
  #define pwm2_togg_val_adr                              0x003340d8                                                   // mia_adr_base + 0x000000d8
  #define pwm2_togg_val                                  (*(volatile unsigned int *)pwm2_togg_val_adr)
  #define pwm3_init_val_adr                              0x003340dc                                                   // mia_adr_base + 0x000000dc
  #define pwm3_init_val                                  (*(volatile unsigned int *)pwm3_init_val_adr)
  #define pwm3_togg_val_adr                              0x003340e0                                                   // mia_adr_base + 0x000000e0
  #define pwm3_togg_val                                  (*(volatile unsigned int *)pwm3_togg_val_adr)
  #define pwm0_cntr_adr                                  0x003340e4                                                   // mia_adr_base + 0x000000e4
  #define pwm0_cntr                                      (*(volatile unsigned int *)pwm0_cntr_adr)
  #define pwm1_cntr_adr                                  0x003340e8                                                   // mia_adr_base + 0x000000e8
  #define pwm1_cntr                                      (*(volatile unsigned int *)pwm1_cntr_adr)
  #define pwm2_cntr_adr                                  0x003340ec                                                   // mia_adr_base + 0x000000ec
  #define pwm2_cntr                                      (*(volatile unsigned int *)pwm2_cntr_adr)
  #define pwm3_cntr_adr                                  0x003340f0                                                   // mia_adr_base + 0x000000f0
  #define pwm3_cntr                                      (*(volatile unsigned int *)pwm3_cntr_adr)
  #define mia_ir_status_adr                              0x003340f4                                                   // mia_adr_base + 0x000000f4
  #define mia_ir_status                                  (*(volatile unsigned int *)mia_ir_status_adr)
  #define mia_ir_ctl_extend_adr                          0x003340f8                                                   // mia_adr_base + 0x000000f8
  #define mia_ir_ctl_extend                              (*(volatile unsigned int *)mia_ir_ctl_extend_adr)
  #define adc_dma_ctl0_adr                               0x003342e0                                                   // mia_adr_base + 0x000002e0
  #define adc_dma_ctl0                                   (*(volatile unsigned int *)adc_dma_ctl0_adr)
  #define adc_dma_ctl1_adr                               0x003342e4                                                   // mia_adr_base + 0x000002e4
  #define adc_dma_ctl1                                   (*(volatile unsigned int *)adc_dma_ctl1_adr)
  #define adc_dma_ctl2_adr                               0x003342e8                                                   // mia_adr_base + 0x000002e8
  #define adc_dma_ctl2                                   (*(volatile unsigned int *)adc_dma_ctl2_adr)
  #define adc_dma_data_adr                               0x003342ec                                                   // mia_adr_base + 0x000002ec
  #define adc_dma_data                                   (*(volatile unsigned int *)adc_dma_data_adr)
  #define adc_dma_status_adr                             0x003342f0                                                   // mia_adr_base + 0x000002f0
  #define adc_dma_status                                 (*(volatile unsigned int *)adc_dma_status_adr)
  #define mia_adc_intf_ctl2_adr                          0x003342fc                                                   // mia_adr_base + 0x000002fc
  #define mia_adc_intf_ctl2                              (*(volatile unsigned int *)mia_adc_intf_ctl2_adr)
  #define adc_filter_ctl0_adr                            0x00334300                                                   // mia_adr_base + 0x00000300
  #define adc_filter_ctl0                                (*(volatile unsigned int *)adc_filter_ctl0_adr)
  #define adc_filter_ctl1_adr                            0x00334304                                                   // mia_adr_base + 0x00000304
  #define adc_filter_ctl1                                (*(volatile unsigned int *)adc_filter_ctl1_adr)
  #define adc_filter_ctl2_adr                            0x00334308                                                   // mia_adr_base + 0x00000308
  #define adc_filter_ctl2                                (*(volatile unsigned int *)adc_filter_ctl2_adr)
  #define adc_filter_ctl3_adr                            0x0033430c                                                   // mia_adr_base + 0x0000030c
  #define adc_filter_ctl3                                (*(volatile unsigned int *)adc_filter_ctl3_adr)
  #define adc_filter_ctl4_adr                            0x00334310                                                   // mia_adr_base + 0x00000310
  #define adc_filter_ctl4                                (*(volatile unsigned int *)adc_filter_ctl4_adr)
  #define adc_filter_ctl5_adr                            0x00334314                                                   // mia_adr_base + 0x00000314
  #define adc_filter_ctl5                                (*(volatile unsigned int *)adc_filter_ctl5_adr)
  #define adc_filter_ctl6_adr                            0x00334318                                                   // mia_adr_base + 0x00000318
  #define adc_filter_ctl6                                (*(volatile unsigned int *)adc_filter_ctl6_adr)
  #define adc_filter_ctl7_adr                            0x0033431c                                                   // mia_adr_base + 0x0000031c
  #define adc_filter_ctl7                                (*(volatile unsigned int *)adc_filter_ctl7_adr)
  #define adc_filter_ctl8_adr                            0x00334320                                                   // mia_adr_base + 0x00000320
  #define adc_filter_ctl8                                (*(volatile unsigned int *)adc_filter_ctl8_adr)
  #define adc_filter_ctl9_adr                            0x00334324                                                   // mia_adr_base + 0x00000324
  #define adc_filter_ctl9                                (*(volatile unsigned int *)adc_filter_ctl9_adr)
  #define adc_filter_ctlA_adr                            0x00334328                                                   // mia_adr_base + 0x00000328
  #define adc_filter_ctlA                                (*(volatile unsigned int *)adc_filter_ctlA_adr)
  #define adc_filter_ctlB_adr                            0x0033432c                                                   // mia_adr_base + 0x0000032c
  #define adc_filter_ctlB                                (*(volatile unsigned int *)adc_filter_ctlB_adr)
  #define adc_filter_ctlC_adr                            0x00334330                                                   // mia_adr_base + 0x00000330
  #define adc_filter_ctlC                                (*(volatile unsigned int *)adc_filter_ctlC_adr)
  #define adc_filter_ctlD_adr                            0x00334334                                                   // mia_adr_base + 0x00000334
  #define adc_filter_ctlD                                (*(volatile unsigned int *)adc_filter_ctlD_adr)
  #define adc_filter_ctlE_adr                            0x00334338                                                   // mia_adr_base + 0x00000338
  #define adc_filter_ctlE                                (*(volatile unsigned int *)adc_filter_ctlE_adr)
  #define adc_filter_ctlF_adr                            0x0033433c                                                   // mia_adr_base + 0x0000033c
  #define adc_filter_ctlF                                (*(volatile unsigned int *)adc_filter_ctlF_adr)
  #define adc_api_ctl0_adr                               0x00334340                                                   // mia_adr_base + 0x00000340
  #define adc_api_ctl0                                   (*(volatile unsigned int *)adc_api_ctl0_adr)
  #define adc_api_ctl1_adr                               0x00334344                                                   // mia_adr_base + 0x00000344
  #define adc_api_ctl1                                   (*(volatile unsigned int *)adc_api_ctl1_adr)
  #define adc_api_ctl2_adr                               0x00334348                                                   // mia_adr_base + 0x00000348
  #define adc_api_ctl2                                   (*(volatile unsigned int *)adc_api_ctl2_adr)
  #define adc_api_ctl3_adr                               0x0033434c                                                   // mia_adr_base + 0x0000034c
  #define adc_api_ctl3                                   (*(volatile unsigned int *)adc_api_ctl3_adr)
  #define adc_api_ctl4_adr                               0x00334350                                                   // mia_adr_base + 0x00000350
  #define adc_api_ctl4                                   (*(volatile unsigned int *)adc_api_ctl4_adr)
  #define adc_ro_spare_adr                               0x00334360                                                   // mia_adr_base + 0x00000360
  #define adc_ro_spare                                   (*(volatile unsigned int *)adc_ro_spare_adr)
  #define gpio_i_st_port0_adr                            0x00334364                                                   // mia_adr_base + 0x00000364
  #define gpio_i_st_port0                                (*(volatile unsigned int *)gpio_i_st_port0_adr)
  #define gpio_i_st_port1_adr                            0x00334368                                                   // mia_adr_base + 0x00000368
  #define gpio_i_st_port1                                (*(volatile unsigned int *)gpio_i_st_port1_adr)
  #define gpio_i_st_port2_adr                            0x0033436c                                                   // mia_adr_base + 0x0000036c
  #define gpio_i_st_port2                                (*(volatile unsigned int *)gpio_i_st_port2_adr)
  #define usb30d_shim_dev_control_adr                    0x00331000                                                   // SHIM_BASE + 0x00001000
  #define usb30d_shim_dev_control                        (*(volatile unsigned int *)usb30d_shim_dev_control_adr)
  #define usb30d_shim_dev_status_adr                     0x00331004                                                   // SHIM_BASE + 0x00001004
  #define usb30d_shim_dev_status                         (*(volatile unsigned int *)usb30d_shim_dev_status_adr)
  #define usb30d_shim_intr_status_adr                    0x00331008                                                   // SHIM_BASE + 0x00001008
  #define usb30d_shim_intr_status                        (*(volatile unsigned int *)usb30d_shim_intr_status_adr)
  #define usb30d_shim_intr_ena_adr                       0x0033100c                                                   // SHIM_BASE + 0x0000100c
  #define usb30d_shim_intr_ena                           (*(volatile unsigned int *)usb30d_shim_intr_ena_adr)
  #define usb30d_shim_intr_mode_adr                      0x00331010                                                   // SHIM_BASE + 0x00001010
  #define usb30d_shim_intr_mode                          (*(volatile unsigned int *)usb30d_shim_intr_mode_adr)
  #define usb30d_shim_mfi_count_adr                      0x00331014                                                   // SHIM_BASE + 0x00001014
  #define usb30d_shim_mfi_count                          (*(volatile unsigned int *)usb30d_shim_mfi_count_adr)
  #define usb30d_shim_debug_sel_adr                      0x00331018                                                   // SHIM_BASE + 0x00001018
  #define usb30d_shim_debug_sel                          (*(volatile unsigned int *)usb30d_shim_debug_sel_adr)
  #define usb30d_shim_gpio_adr                           0x0033101c                                                   // SHIM_BASE + 0x0000101c
  #define usb30d_shim_gpio                               (*(volatile unsigned int *)usb30d_shim_gpio_adr)
  #define usb30d_shim_ctrl_adr                           0x00331020                                                   // SHIM_BASE + 0x00001020
  #define usb30d_shim_ctrl                               (*(volatile unsigned int *)usb30d_shim_ctrl_adr)
  #define usb30d_shim_pds_usb3_adr                       0x00331024                                                   // SHIM_BASE + 0x00001024
  #define usb30d_shim_pds_usb3                           (*(volatile unsigned int *)usb30d_shim_pds_usb3_adr)
  #define UBDC_BDCCFG0_adr                               0x00330000                                                   // UBDC_BASE + 0x00000000
  #define UBDC_BDCCFG0                                   (*(volatile unsigned int *)UBDC_BDCCFG0_adr)
  #define UBDC_BDCCFG1_adr                               0x00330004                                                   // UBDC_BASE + 0x00000004
  #define UBDC_BDCCFG1                                   (*(volatile unsigned int *)UBDC_BDCCFG1_adr)
  #define UBDC_BDCCAP0_adr                               0x00330008                                                   // UBDC_BASE + 0x00000008
  #define UBDC_BDCCAP0                                   (*(volatile unsigned int *)UBDC_BDCCAP0_adr)
  #define UBDC_BDCCAP1_adr                               0x0033000c                                                   // UBDC_BASE + 0x0000000c
  #define UBDC_BDCCAP1                                   (*(volatile unsigned int *)UBDC_BDCCAP1_adr)
  #define UBDC_CMDPAR0_adr                               0x00330010                                                   // UBDC_BASE + 0x00000010
  #define UBDC_CMDPAR0                                   (*(volatile unsigned int *)UBDC_CMDPAR0_adr)
  #define UBDC_CMDPAR1_adr                               0x00330014                                                   // UBDC_BASE + 0x00000014
  #define UBDC_CMDPAR1                                   (*(volatile unsigned int *)UBDC_CMDPAR1_adr)
  #define UBDC_CMDPAR2_adr                               0x00330018                                                   // UBDC_BASE + 0x00000018
  #define UBDC_CMDPAR2                                   (*(volatile unsigned int *)UBDC_CMDPAR2_adr)
  #define UBDC_CMDSC_adr                                 0x0033001c                                                   // UBDC_BASE + 0x0000001c
  #define UBDC_CMDSC                                     (*(volatile unsigned int *)UBDC_CMDSC_adr)
  #define UBDC_USPSC_adr                                 0x00330020                                                   // UBDC_BASE + 0x00000020
  #define UBDC_USPSC                                     (*(volatile unsigned int *)UBDC_USPSC_adr)
  #define UBDC_USPPM2_adr                                0x0033002c                                                   // UBDC_BASE + 0x0000002c
  #define UBDC_USPPM2                                    (*(volatile unsigned int *)UBDC_USPPM2_adr)
  #define UBDC_EXCPBA_adr                                0x00330030                                                   // UBDC_BASE + 0x00000030
  #define UBDC_EXCPBA                                    (*(volatile unsigned int *)UBDC_EXCPBA_adr)
  #define UBDC_SPBBAL_adr                                0x00330038                                                   // UBDC_BASE + 0x00000038
  #define UBDC_SPBBAL                                    (*(volatile unsigned int *)UBDC_SPBBAL_adr)
  #define UBDC_SPBBAH_adr                                0x0033003c                                                   // UBDC_BASE + 0x0000003c
  #define UBDC_SPBBAH                                    (*(volatile unsigned int *)UBDC_SPBBAH_adr)
  #define UBDC_BDCSC_adr                                 0x00330040                                                   // UBDC_BASE + 0x00000040
  #define UBDC_BDCSC                                     (*(volatile unsigned int *)UBDC_BDCSC_adr)
  #define UBDC_MFNUM_adr                                 0x00330048                                                   // UBDC_BASE + 0x00000048
  #define UBDC_MFNUM                                     (*(volatile unsigned int *)UBDC_MFNUM_adr)
  #define UBDC_XSFNTF_adr                                0x0033004c                                                   // UBDC_BASE + 0x0000004c
  #define UBDC_XSFNTF                                    (*(volatile unsigned int *)UBDC_XSFNTF_adr)
  #define UBDC_DEVICESTSA_adr                            0x00330058                                                   // UBDC_BASE + 0x00000058
  #define UBDC_DEVICESTSA                                (*(volatile unsigned int *)UBDC_DEVICESTSA_adr)
  #define UBDC_DEVICESTSB_adr                            0x0033005c                                                   // UBDC_BASE + 0x0000005c
  #define UBDC_DEVICESTSB                                (*(volatile unsigned int *)UBDC_DEVICESTSB_adr)
  #define UBDC_EPS0_adr                                  0x00330060                                                   // UBDC_BASE + 0x00000060
  #define UBDC_EPS0                                      (*(volatile unsigned int *)UBDC_EPS0_adr)
  #define UBDC_EPS1_adr                                  0x00330064                                                   // UBDC_BASE + 0x00000064
  #define UBDC_EPS1                                      (*(volatile unsigned int *)UBDC_EPS1_adr)
  #define UBDC_EPS2_adr                                  0x00330068                                                   // UBDC_BASE + 0x00000068
  #define UBDC_EPS2                                      (*(volatile unsigned int *)UBDC_EPS2_adr)
  #define UBDC_EPS3_adr                                  0x0033006c                                                   // UBDC_BASE + 0x0000006c
  #define UBDC_EPS3                                      (*(volatile unsigned int *)UBDC_EPS3_adr)
  #define UBDC_EPS4_adr                                  0x00330070                                                   // UBDC_BASE + 0x00000070
  #define UBDC_EPS4                                      (*(volatile unsigned int *)UBDC_EPS4_adr)
  #define UBDC_EPS5_adr                                  0x00330074                                                   // UBDC_BASE + 0x00000074
  #define UBDC_EPS5                                      (*(volatile unsigned int *)UBDC_EPS5_adr)
  #define UBDC_EPS6_adr                                  0x00330078                                                   // UBDC_BASE + 0x00000078
  #define UBDC_EPS6                                      (*(volatile unsigned int *)UBDC_EPS6_adr)
  #define UBDC_EPS7_adr                                  0x0033007c                                                   // UBDC_BASE + 0x0000007c
  #define UBDC_EPS7                                      (*(volatile unsigned int *)UBDC_EPS7_adr)
  #define UBDC_SRRBAL0_adr                               0x00330200                                                   // UBDC_BASE + 0x00000200
  #define UBDC_SRRBAL0                                   (*(volatile unsigned int *)UBDC_SRRBAL0_adr)
  #define UBDC_SRRBAH0_adr                               0x00330204                                                   // UBDC_BASE + 0x00000204
  #define UBDC_SRRBAH0                                   (*(volatile unsigned int *)UBDC_SRRBAH0_adr)
  #define UBDC_SRRINT0_adr                               0x00330208                                                   // UBDC_BASE + 0x00000208
  #define UBDC_SRRINT0                                   (*(volatile unsigned int *)UBDC_SRRINT0_adr)
  #define UBDC_INTCLS0_adr                               0x0033020c                                                   // UBDC_BASE + 0x0000020c
  #define UBDC_INTCLS0                                   (*(volatile unsigned int *)UBDC_INTCLS0_adr)
  #define UBDC_SRRBAL1_adr                               0x00330210                                                   // UBDC_BASE + 0x00000210
  #define UBDC_SRRBAL1                                   (*(volatile unsigned int *)UBDC_SRRBAL1_adr)
  #define UBDC_SRRBAH1_adr                               0x00330214                                                   // UBDC_BASE + 0x00000214
  #define UBDC_SRRBAH1                                   (*(volatile unsigned int *)UBDC_SRRBAH1_adr)
  #define UBDC_SRRINT1_adr                               0x00330218                                                   // UBDC_BASE + 0x00000218
  #define UBDC_SRRINT1                                   (*(volatile unsigned int *)UBDC_SRRINT1_adr)
  #define UBDC_INTCLS1_adr                               0x0033021c                                                   // UBDC_BASE + 0x0000021c
  #define UBDC_INTCLS1                                   (*(volatile unsigned int *)UBDC_INTCLS1_adr)

#endif // REGISTER_H
