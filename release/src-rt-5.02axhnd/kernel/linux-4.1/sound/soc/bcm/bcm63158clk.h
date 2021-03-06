/*********************************************************************
 * bcm63158clk.h -- ALSA SoC clock driver header file for 63138/63148 platform 
 *
 * Author: Kevin Li <kevin-ke.li@broadcom.com>
 * 
 * Copyright (c) 2018 Broadcom Corporation
 * All Rights Reserved
 *
 * <:label-BRCM:2018:DUAL/GPL:standard
 * 
 * Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed
 * to you under the terms of the GNU General Public License version 2
 * (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 * with the following added to such license:
 * 
 *    As a special exception, the copyright holders of this software give
 *    you permission to link this software with independent modules, and
 *    to copy and distribute the resulting executable under terms of your
 *    choice, provided that you also meet, for each linked independent
 *    module, the terms and conditions of the license of that module.
 *    An independent module is a module which is not derived from this
 *    software.  The special exception does not apply to any modifications
 *    of the software.
 * 
 * Not withstanding the above, under no circumstances may you combine
 * this software in any way with any other Broadcom software provided
 * under a license other than the GPL, without Broadcom's express prior
 * written consent.
 * 
 * :>
*********************************************************************/
#ifndef __BCM63158CLK_H
#define __BCM63158CLK_H

#define MAX_PCM_FORMAT SNDRV_PCM_FORMAT_S32_LE+1
#define MAX_SAMPLE_RATE            11

#define NTR_CLK_PRG_SWCH_OFFSET    0x340

#define CLK_DIV_RST_N              ( 1 << 1 )    
#define NTR_RST_N                  ( 1 << 0 ) 
#define CLK_SEL_250MHZ_SYNCE_PLL   ( 0x0000 )
#define CLK_SEL_PON_SERDES         1
#define CLK_SEL_DSL_RDP            2       
#define CLK_SEL_SGPHY_UBUS         3       
#define CLK_SEL_LAN_SERDES         4
#define CLK_SEL_50MHZ_XTAL         5
#define CLK_SEL_PON_SERDES_DIV11   6
#define CLK_SEL_SHIFT              29
#define CLK_DIV_MASK               0x0FFFFFFF
#define CLK_DENOM_MASK             0x0000FFFF
#define CLK_SEL_MASK               0xE0000000

#define NTR_REET_REG               ( 0x0000 )
#define NTR_REET_REG_MAX           NTR_REET_REG

#define NTR_CLK_I2S_PRGDIVCFG1     ( 0x0000 )
#define NTR_CLK_I2S_PRGDIVCFG2     ( 0x0004 )
#define NTR_CLK_I2S_PRGDIVCFG1_MAX NTR_CLK_I2S_PRGDIVCFG2

#define NTR_CLK_SEL_MASK (7 << CLK_SEL_SHIFT )

struct i2s_pllclk_freq_map
{
   unsigned int freq;               /* Desired sampling frequency */
   unsigned int mclk_rate;          /* mclk/2*bclk = mclk_rate */
   unsigned int prg_clk_div;        /* Programmable clock divider cfg */ 
   unsigned int prg_clk_denom;      /* Programmable clock divider cfg */ 
   unsigned int prg_clk_sel;        /* Programmable clock divider cfg */ 
};

int set_i2s_clk(int fmtid, int freq);
struct i2s_pllclk_freq_map *get_i2s_pll_freq_map( int fmtid, unsigned int frequency );
int set_i2s_prg_clk_div( struct i2s_pllclk_freq_map *freq_map_ptr );

#endif
