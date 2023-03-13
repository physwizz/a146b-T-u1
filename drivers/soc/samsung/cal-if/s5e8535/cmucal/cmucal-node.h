#ifndef __CMUCAL_NODE_H__
#define __CMUCAL_NODE_H__

#include "../../cmucal.h"

enum clk_id {

    PLL_SHARED0 = PLL_TYPE,
    PLL_SHARED1,
    PLL_G3D,
    PLL_MMC,
    PLL_AUD,
    PLL_MIF_MAIN_MIF0,
    PLL_MIF_SUB_MIF0,
    PLL_MIF_MAIN_MIF1,
    PLL_MIF_SUB_MIF1,
    PLL_CPUCL0,
    PLL_MIF_S2D,
    PLL_CPUCL1,
    PLL_DSU,
    end_of_pll,
    num_of_pll = (end_of_pll - PLL_TYPE & MASK_OF_ID),

    MUX_CLKCMU_AUD_CPU = MUX_TYPE,
    MUX_CLKCMU_AUD_NOC,
    MUX_CLKCMU_CPUCL0_SWITCH,
    MUX_CLKCMU_CPUCL0_NOCP,
    MUX_CLKCMU_CPUCL0_DBG_NOC,
    MUX_CLKCMU_DSU_SWITCH,
    MUX_CLKCMU_CPUCL1_SWITCH,
    MUX_CLKCMU_CIS_CLK0,
    MUX_CLKCMU_CIS_CLK1,
    MUX_CLKCMU_CIS_CLK2,
    MUX_CLKCMU_CIS_CLK3,
    MUX_CLKCMU_CIS_CLK4,
    MUX_CLKCMU_CIS_CLK5,
    MUX_CLKCMU_CMU_BOOST_TOP,
    MUX_CLKCMU_CMU_BOOST,
    MUX_CLKCMU_CMU_BOOST_CPU,
    MUX_CLKCMU_CMU_BOOST_MIF,
    MUX_CLKCMU_CSIS_NOC,
    MUX_CLKCMU_CSTAT_NOC,
    MUX_CLKCMU_CSTAT_BYRP,
    MUX_CLKCMU_DPU_NOC,
    MUX_CLKCMU_DPU_DSIM,
    MUX_CLKCMU_G3D_NOC,
    MUX_CLKCMU_G3D_SWITCH,
    MUX_CLKCMU_HSI_NOC,
    MUX_CLKCMU_HSI_UFS_EMBD,
    MUX_CLKCMU_M2M_NOC,
    MUX_CLKCMU_M2M_JPEG,
    MUX_CLKCMU_M2M_GDC,
    MUX_CLKCMU_M2M_LME,
    MUX_CLKCMU_M2M_VRA,
    MUX_CLKCMU_MFC_NOC,
    MUX_CLKCMU_MIF_SWITCH,
    MUX_CLKCMU_MIF_NOCP,
    MUX_CLKCMU_NOCL0_NOC,
    MUX_CLKCMU_NOCL0_SC,
    MUX_CLKCMU_NOCL1A_NOC,
    MUX_CLKCMU_PERI_NOC,
    MUX_CLKCMU_PERI_MMC_CARD,
    MUX_CLKCMU_PERI_IP,
    MUX_CLKCMU_RGBP_NOC,
    MUX_CLKCMU_USB_NOC,
    MUX_CLKCMU_USB_USB20DRD,
    MUX_CLKCMU_YUVP_NOC,
    MUX_CLKCMU_ALIVE_NOC,
    MUX_CLKCMU_CSIS_DCPHY,
    MUX_CLKCMU_ICPU_NOCD_0,
    MUX_CLKCMU_ICPU_NOCD_1,
    MUX_CLKCMU_NOCL1A_NOCL0,
    MUX_CLKCMU_ICPU_NOC_0,
    CMU_CUSTOM_TOP_MUX_CMUREF,
    MUX_CLK_ALIVE_OSCCLK_RCO_CMGP,
    MUX_CLK_ALIVE_OSCCLK_RCO_CHUB,
    MUX_CLK_ALIVE_OSCCLK_RCO_PMU,
    MUX_CLK_ALIVE_OSCCLK_RCO_CMU,
    MUX_CLK_ALIVE_OSCCLK_RCO_SPMI,
    MUX_REFCLK_OSC,
    MUX_CLKCMU_AP2GNSS,
    MUX_CLKCMU_CMGP_PERI,
    MUX_CLKCMU_CMGP_NOC,
    MUX_CLK_ALIVE_NOC,
    MUX_CLKCMU_CHUB_NOC,
    MUX_CLK_ALIVE_PMU_SUB,
    MUX_CLK_ALIVE_I2C0,
    MUX_CLK_ALIVE_DBGCORE_UART,
    MUX_CLK_ALIVE_USI0,
    MUX_CLK_ALIVE_SPMI,
    MUX_CLKCMU_DBGCORE_NOC,
    MUX_CLK_AUD_CPU,
    MUX_HCHGEN_CLK_AUD_CPU,
    MUX_CLK_AUD_CPU_PLL,
    MUX_CLK_AUD_NOC_PLL,
    MUX_CLK_AUD_NOC,
    MUX_CLK_AUD_AUDIF,
    MUX_CLK_AUD_UAIF0,
    MUX_CLK_AUD_UAIF1,
    MUX_CLK_AUD_UAIF2,
    MUX_CLK_AUD_UAIF3,
    MUX_CLK_AUD_UAIF4,
    MUX_CLK_AUD_UAIF5,
    MUX_CLK_AUD_UAIF6,
    MUX_CLK_AUD_DSIF,
    MUX_CLK_AUD_PCMC,
    MUX_CLK_AUD_FM,
    MUX_CLK_CHUB_USI0,
    MUX_CLK_CHUB_USI1,
    MUX_CLK_CHUB_I2C1,
    MUX_CLK_CHUB_NOC,
    MUX_CLK_CHUB_USI2,
    MUX_CLK_CHUB_TIMER,
    MUX_CLK_CHUB_I2C2,
    MUX_CLK_CHUB_I3C,
    MUX_MIF_CMUREF_MIF0,
    MUX_MIF_CMUREF_MIF1,
    MUX_NOCL0_CMUREF,
    MUX_CLKCMU_NOCL0_GIC,
    MUX_NOCL1A_CMUREF,
    MUX_CLK_PERI_USI00,
    MUX_CLK_PERI_USI01,
    MUX_CLK_PERI_USI02,
    MUX_CLK_PERI_USI03,
    MUX_CLK_PERI_USI04,
    MUX_CLK_PERI_USI05,
    MUX_CLK_PERI_USI06,
    MUX_CLK_PERI_UART_DBG,
    MUX_CLK_PERI_I2C,
    MUX_CLK_USB_NOC,
    MUX_CLK_USB_USB20DRD,
    MUX_CLK_CSIS_DCPHY,
    MUX_CLK_CMGP_NOC,
    MUX_CLK_CMGP_USI0,
    MUX_CLK_CMGP_USI1,
    MUX_CLK_CMGP_USI2,
    MUX_CLK_CMGP_USI3,
    MUX_CLK_CMGP_USI4,
    MUX_CLK_CMGP_I2C,
    MUX_CLK_CMGP_I3C,
    MUX_CLK_DBGCORE_NOC,
    MUX_CLK_CPUCL0_PLL,
    MUX_CPUCL0_CMUREF,
    CLKMUX_MIF_DDRPHY2X_S2D,
    MUX_CLK_S2D_CORE,
    MUX_CLK_CPUCL1_PLL,
    MUX_CLK_CPUCL1_HTU,
    MUX_CPUCL1_CMUREF,
    MUX_CLK_DSU_PLL,
    MUX_DSU_CMUREF,
    MUX_CLK_RCO_ALIVE_USER = ((MASK_OF_ID & MUX_DSU_CMUREF) | USER_MUX_TYPE) + 1,
    MUX_CLKCMU_ALIVE_NOC_USER,
    MUX_CLK_ALIVE_TIMER_USER,
    MUX_CLK_RCO_ALIVE_I3C_PMIC_USER,
    MUX_CLKCMU_DSU_SWITCH_USER,
    MUX_CLKCMU_AUD_CPU_USER,
    MUX_CLKCMU_AUD_NOC_USER,
    MUX_CP_PCMC_CLK_USER,
    MUX_CLKCMU_CHUB_RCO_USER,
    MUX_CLKCMU_CHUB_NOC_USER,
    MUX_CLKCMU_DPU_NOC_USER,
    MUX_CLKCMU_DPU_DSIM_USER,
    MUX_CLKCMU_G3D_NOC_USER,
    MUX_CLKCMU_HSI_UFS_EMBD_USER,
    MUX_CLKCMU_HSI_NOC_USER,
    MUX_CLKCMU_MFC_NOC_USER,
    MUX_CLKCMU_MIF_NOCP_USER_MIF0,
    MUX_CLKCMU_MIF_NOCP_USER_MIF1,
    CLKMUX_MIF_DDRPHY2X_MIF0,
    CLKMUX_MIF_DDRPHY2X_MIF1,
    MUX_CLKCMU_NOCL0_SC_USER,
    MUX_CLKCMU_NOCL0_NOC_USER,
    MUX_CLKCMU_NOCL1A_NOC_USER,
    MUX_CLKCMU_NOCL1A_NOCL0_USER,
    MUX_CLKCMU_PERI_MMC_CARD_USER,
    MUX_CLKCMU_PERI_IP_USER,
    MUX_CLKCMU_PERI_NOCP_USER,
    MUX_CLKCMU_RGBP_NOC_USER,
    MUX_CLKCMU_USB_NOC_USER,
    MUX_CLKCMU_USB_USB20DRD_USER,
    MUX_CLKAUD_USB_NOC_USER,
    MUX_CLKCMU_YUVP_NOC_USER,
    MUX_CLKCMU_CSIS_NOC_USER,
    MUX_CLKCMU_CSIS_DCPHY_USER,
    MUX_CLKCMU_CSTAT_BYRP_USER,
    MUX_CLKCMU_CSTAT_NOC_USER,
    MUX_CLKCMU_M2M_NOC_USER,
    MUX_CLKCMU_M2M_JPEG_USER,
    MUX_CLKCMU_M2M_GDC_USER,
    MUX_CLKCMU_M2M_LME_USER,
    MUX_CLKCMU_M2M_VRA_USER,
    MUX_CLKCMU_CMGP_NOC_USER,
    MUX_CLKCMU_CMGP_RCO_USER,
    MUX_CLKCMU_CMGP_PERI_USER,
    MUX_CLKCMU_DBGCORE_USER,
    MUX_CLKCMU_ICPU_NOC_0_USER,
    MUX_CLKCMU_ICPU_NOCD_1_USER,
    MUX_CLKCMU_CPUCL0_SWITCH_USER,
    MUX_CLKCMU_CPUCL1_SWITCH_USER,
    MUX_CLKCMU_CPUCL0_DBG_NOC_USER,
    MUX_CLKCMU_CPUCL0_NOCP_USER,
    end_of_mux,
    num_of_mux = (end_of_mux - MUX_TYPE & MASK_OF_ID),

    DIV_CLKCMU_AUD_CPU = DIV_TYPE,
    DIV_CLKCMU_AUD_NOC,
    DIV_CLKCMU_CPUCL0_SWITCH,
    DIV_CLKCMU_CPUCL0_NOCP,
    DIV_CLKCMU_CPUCL0_DBG_NOC,
    DIV_CLKCMU_DSU_SWITCH,
    DIV_CLKCMU_CPUCL1_SWITCH,
    DIV_CLKCMU_CIS_CLK0,
    DIV_CLKCMU_CIS_CLK1,
    DIV_CLKCMU_CIS_CLK2,
    DIV_CLKCMU_CIS_CLK3,
    DIV_CLKCMU_CIS_CLK4,
    DIV_CLKCMU_CIS_CLK5,
    DIV_CLKCMU_CMU_BOOST_TOP,
    DIV_CLKCMU_CMU_BOOST,
    DIV_CLKCMU_CSIS_NOC,
    DIV_CLKCMU_CMU_BOOST_CPU,
    DIV_CLKCMU_CMU_BOOST_MIF,
    DIV_CLKCMU_CSTAT_NOC,
    DIV_CLKCMU_CSTAT_BYRP,
    DIV_CLKCMU_DPU_NOC,
    DIV_CLKCMU_DPU_DSIM,
    DIV_CLKCMU_G3D_SWITCH,
    DIV_CLKCMU_HSI_NOC,
    DIV_CLKCMU_HSI_UFS_EMBD,
    DIV_CLKCMU_M2M_NOC,
    DIV_CLKCMU_M2M_JPEG,
    DIV_CLKCMU_M2M_GDC,
    DIV_CLKCMU_M2M_LME,
    DIV_CLKCMU_M2M_VRA,
    DIV_CLKCMU_MFC_NOC,
    DIV_CLKCMU_MIF_NOCP,
    DIV_CLKCMU_NOCL0_NOC,
    DIV_CLKCMU_NOCL0_SC,
    DIV_CLKCMU_NOCL1A_NOC,
    DIV_CLKCMU_PERI_NOC,
    DIV_CLKCMU_PERI_MMC_CARD,
    DIV_CLKCMU_PERI_IP,
    DIV_CLKCMU_RGBP_NOC,
    DIV_CLKCMU_USB_NOC,
    DIV_CLKCMU_USB_USB20DRD,
    DIV_CLKCMU_YUVP_NOC,
    DIV_CLKCMU_ALIVE_NOC,
    DIV_CLKCMU_CSIS_DCPHY,
    DIV_CLKCMU_ICPU_NOCD_0,
    DIV_CLKCMU_ICPU_NOCD_1,
    DIV_CLKCMU_NOCL1A_NOCL0,
    DIV_CLK_ALIVE_OSCCLK_MIF,
    DIV_CLK_ALIVE_OSCCLK_SOC,
    DIV_CLK_ALIVE_OSCCLK_RCO_CMGP,
    DIV_CLK_ALIVE_OSCCLK_RCO_CHUB,
    DIV_CLK_ALIVE_OSCCLK_RCO_PMU,
    DIV_CLK_ALIVE_OSCCLK_RCO_CMU,
    DIV_CLK_ALIVE_OSCCLK_RCO_SPMI,
    DIV_CLK_ALIVE_OSCCLK_CLKOUT,
    DIV_CLK_ALIVE_OSCCLK_USB_LINK,
    DIV_CLK_ALIVE_OSCCLK_WLBT,
    DIV_CLK_ALIVE_NOC,
    DIV_CLK_ALIVE_CMGP_PERI_ALIVE,
    DIV_CLK_ALIVE_CMGP_NOC,
    DIV_CLK_ALIVE_DBGCORE_UART,
    DIV_CLK_ALIVE_CHUB_NOC,
    DIV_CLK_ALIVE_SPMI,
    DIV_CLK_PMU_SUB,
    DIV_CLK_ALIVE_I2C0,
    DIV_CLK_ALIVE_USI0,
    DIV_CLK_ALIVE_DBGCORE_NOC,
    DIV_CLK_ALIVE_ECU,
    DIV_CLK_AUD_USB_NOC,
    DIV_CLK_AUD_CPU_ACP,
    DIV_CLK_AUD_CPU_PCLKDBG,
    DIV_CLK_AUD_NOCP,
    DIV_CLK_AUD_SERIAL_LIF_CORE,
    DIV_CLK_AUD_SERIAL_LIF,
    DIV_CLK_AUD_DMIC_SYS,
    DIV_CLK_AUD_DMIC,
    DIV_CLK_AUD_CNT,
    DIV_CLK_AUD_AUDIF,
    DIV_CLK_AUD_UAIF0,
    DIV_CLK_AUD_UAIF1,
    DIV_CLK_AUD_UAIF2,
    DIV_CLK_AUD_UAIF3,
    DIV_CLK_AUD_UAIF4,
    DIV_CLK_AUD_UAIF5,
    DIV_CLK_AUD_UAIF6,
    DIV_CLK_AUD_DSIF,
    DIV_CLK_AUD_PCMC,
    DIV_CLK_AUD_ACLK,
    DIV_CLK_AUD_CPU,
    DIV_CLK_AUD_NOCD,
    DIV_CLK_AUD_MCLK,
    DIV_CLK_AUD_FM_SPDY,
    DIV_CLK_AUD_FM,
    DIV_CLK_AUD_ECU,
    DIV_CLK_CHUB_I2C1,
    DIV_CLK_CHUB_USI1,
    DIV_CLK_CHUB_USI0,
    DIV_CLK_CHUB_NOC,
    DIV_CLK_CHUB_USI2,
    DIV_CLK_CHUB_I2C2,
    DIV_CLK_CHUB_I3C,
    DIV_CLK_CHUB_ECU,
    DIV_CLK_DPU_NOCP,
    DIV_CLK_DPU_ECU,
    DIV_CLK_G3D_NOCP,
    DIV_CLK_G3D_ECU,
    DIV_CLK_HSI_ECU,
    DIV_CLK_MFC_NOCP,
    DIV_CLK_MFC_ECU,
    DIV_CLK_MIF_NOCD_MIF0,
    DIV_CLK_MIF_ECU_MIF0,
    DIV_CLK_MIF_NOCD_MIF1,
    DIV_CLK_MIF_ECU_MIF1,
    DIV_CLK_NOCL0_NOCP,
    DIV_CLK_NOCL0_ECU,
    DIV_CLK_NOCL1A_NOCP,
    DIV_CLK_NOCL1A_ECU,
    DIV_CLK_PERI_USI_I2C,
    DIV_CLK_PERI_UART_DBG,
    DIV_CLK_PERI_USI06_USI,
    DIV_CLK_PERI_USI05_USI,
    DIV_CLK_PERI_USI04_USI,
    DIV_CLK_PERI_USI03_USI,
    DIV_CLK_PERI_USI02_USI,
    DIV_CLK_PERI_USI01_USI,
    DIV_CLK_PERI_USI00_USI,
    DIV_CLKCMU_OTP,
    DIV_CLK_RGBP_NOCP,
    DIV_CLK_YUVP_NOCP,
    DIV_CLK_CSIS_NOCP,
    DIV_CLK_CSIS_DCPHY,
    DIV_CLK_CSTAT_NOCP,
    DIV_CLK_M2M_NOCP,
    DIV_CLK_CMGP_USI00_USI,
    DIV_CLK_CMGP_USI01_USI,
    DIV_CLK_CMGP_USI02_USI,
    DIV_CLK_CMGP_USI03_USI,
    DIV_CLK_CMGP_USI04_USI,
    DIV_CLK_CMGP_USI_I2C,
    DIV_CLK_CMGP_USI_I3C,
    DIV_CLK_ICPU_NOCP,
    DIV_CLK_ICPU_PCLKDBG,
    DIV_CLK_CPUCL0_SHORTSTOP,
    DIV_CLK_MIF_NOCD_S2D,
    DIV_CLK_CPUCL1_SHORTSTOP,
    DIV_CLK_CPUCL0_DBG_PCLKDBG,
    DIV_CLK_CPUCL0_GLB_ECU,
    DIV_CLK_DSU_SHORTSTOP,
    DIV_CLK_CLUSTER_ACLK,
    DIV_CLK_CLUSTER_ATCLK,
    DIV_CLK_CLUSTER_PCLK,
    DIV_CLK_CLUSTER_PERIPHCLK,
    end_of_div,
    num_of_div = (end_of_div - DIV_TYPE & MASK_OF_ID),

    GATE_CLKCMU_AUD_CPU = GATE_TYPE,
    GATE_CLKCMU_CHUB_NOC,
    GATE_CLKCMU_AUD_NOC,
    GATE_CLKCMU_CPUCL0_SWITCH,
    GATE_CLKCMU_CPUCL0_NOCP,
    GATE_CLKCMU_CPUCL0_DBG_NOC,
    GATE_CLKCMU_DSU_SWITCH,
    GATE_CLKCMU_CPUCL1_SWITCH,
    GATE_CLKCMU_CIS_CLK0,
    GATE_CLKCMU_CIS_CLK1,
    GATE_CLKCMU_CIS_CLK2,
    GATE_CLKCMU_CIS_CLK3,
    GATE_CLKCMU_CIS_CLK4,
    GATE_CLKCMU_CIS_CLK5,
    GATE_CLKCMU_CMU_BOOST_TOP,
    GATE_CLKCMU_CMU_BOOST,
    GATE_CLKCMU_CMU_BOOST_CPU,
    GATE_CLKCMU_CMU_BOOST_MIF,
    GATE_CLKCMU_CSIS_NOC,
    GATE_CLKCMU_CSTAT_NOC,
    GATE_CLKCMU_CSTAT_BYRP,
    GATE_CLKCMU_DPU_NOC,
    GATE_CLKCMU_DPU_DSIM,
    GATE_CLKCMU_G3D_SWITCH,
    GATE_CLKCMU_HSI_NOC,
    GATE_CLKCMU_HSI_UFS_EMBD,
    GATE_CLKCMU_M2M_NOC,
    GATE_CLKCMU_M2M_JPEG,
    GATE_CLKCMU_M2M_GDC,
    GATE_CLKCMU_M2M_LME,
    GATE_CLKCMU_M2M_VRA,
    GATE_CLKCMU_MFC_NOC,
    GATE_CLKCMU_MIF_SWITCH,
    GATE_CLKCMU_MIF_NOCP,
    GATE_CLKCMU_NOCL0_NOC,
    GATE_CLKCMU_NOCL0_SC,
    GATE_CLKCMU_NOCL1A_NOC,
    GATE_CLKCMU_PERI_NOC,
    GATE_CLKCMU_PERI_MMC_CARD,
    GATE_CLKCMU_PERI_IP,
    GATE_CLKCMU_RGBP_NOC,
    GATE_CLKCMU_USB_NOC,
    GATE_CLKCMU_USB_USB20DRD,
    GATE_CLKCMU_YUVP_NOC,
    GATE_CLKCMU_ALIVE_NOC,
    GATE_CLKCMU_CSIS_DCPHY,
    AP2CP_SHARED0_CLK,
    AP2CP_SHARED1_CLK,
    AP2CP_SHARED2_CLK,
    AP2CP_HISPEEDY_CLK,
    GATE_CLKCMU_G3D_NOC,
    GATE_CLKCMU_ICPU_NOCD_0,
    GATE_CLKCMU_ICPU_NOCD_1,
    GATE_CLKCMU_NOCL1A_NOCL0,
    GATE_CLKCMU_ICPU_NOC_0_ALT,
    end_of_gate,
    num_of_gate = (end_of_gate - GATE_TYPE & MASK_OF_ID),

    PLL_SHARED0_D1 = FIXED_FACTOR_TYPE,
    PLL_SHARED0_D2,
    PLL_SHARED0_D3,
    PLL_SHARED0_D4,
    PLL_SHARED1_D1,
    PLL_SHARED1_D2,
    PLL_SHARED1_D3,
    PLL_SHARED1_D4,
    PLL_G3D_D1,
    PLL_G3D_D2,
    PLL_G3D_D3,
    PLL_G3D_D4,
    PLL_MMC_D1,
    PLL_MMC_D2,
    PLL_MMC_D3,
    PLL_MMC_D4,
    PLL_AUD_D1,
    PLL_AUD_D2,
    PLL_AUD_D3,
    PLL_AUD_D4,
    PLL_CPUCL0_D1,
    PLL_CPUCL0_D2,
    PLL_CPUCL0_D3,
    PLL_CPUCL0_D4,
    PLL_CPUCL1_D1,
    PLL_CPUCL1_D2,
    PLL_CPUCL1_D3,
    PLL_CPUCL1_D4,
    PLL_DSU_D1,
    PLL_DSU_D2,
    PLL_DSU_D3,
    PLL_DSU_D4,
    end_of_fixed_factor,
    num_of_fixed_factor = (end_of_fixed_factor - FIXED_FACTOR_TYPE & MASK_OF_ID),

    OSCCLK_CMU = FIXED_RATE_TYPE,
    OSCCLK_CMU__ALO,
    I_STABLE_CLK_52,
    RCO,
    CLK_ALIVE_OSCCLK_RCO,
    DFT_CLKMUX__CLK_ALIVE_OSCCLK_RCO,
    OSCCLK_ALIVE,
    OSCCLK_RCO_ALIVE,
    OSCCLK_RCO_SPMI,
    RCO_400,
    OSCCLK_RCO_ALIVE_TOP,
    OSCCLK_AUD,
    OSCCLK_RCO_CHUB,
    O_CLK_CHUB_OSCCLK_RCO,
    CLK_CHUB_FREE_OSCCLK,
    DFT_CLKMUX_CLK_CHUB_OSCCLK_RCO,
    FREE_OSCCLK_CHUB,
    OSCCLK_RCO_CHUB__ALV,
    OSCCLK_DPU,
    DFTMUX_CLK_DPU_OSCCLK,
    CLK_DPU_OSCCLK,
    FREE_OSCCLK_DPU,
    OSCCLK_DPU__ALO,
    OSCCLK_G3D,
    DFTMUX_CLK_G3D_OSCCLK,
    CLK_G3D_OSCCLK,
    OSCCLK_G3D__ALO,
    OSCCLK_HSI,
    DFTMUX_CLK_HSI_OSCCLK,
    CLK_HSI_OSCCLK,
    OSCCLK_HSI__ALO,
    DFTMUX_CLK_MFC_OSCCLK,
    O_CLK_MFC_OSCCLK,
    CLK_MFC_OSCCLK,
    OSCCLK_MFC,
    FREE_OSCCLK_MFC,
    OSCCLK_MFC__ALO,
    DFTMUX_CLK_MIF_OSCCLK_MIF0,
    CLK_MIF_FREE_OSCCLK_MIF0,
    FREE_OSCCLK_MIF_MIF0,
    OSCCLK_MIF_MIF0,
    OSCCLK_MIF__ALO_MIF0,
    DFTMUX_CLK_MIF_OSCCLK_MIF1,
    CLK_MIF_FREE_OSCCLK_MIF1,
    FREE_OSCCLK_MIF_MIF1,
    OSCCLK_MIF_MIF1,
    OSCCLK_MIF__ALO_MIF1,
    OSCCLK_NOCL0,
    DFTMUX_CLK_NOCL0_OSCCLK,
    CLK_NOCL0_OSCCLK,
    DFT_CLKMUX__DFT_BIST_CLK_NOCL0_OSCCLK,
    DFT_CLKGAT__BIST_CLK_NOCL0_OSCCLK,
    BIST_CLK_NOCL0_OSCCLK,
    OSCCLK_NOCL0__ALO,
    OSCCLK_NOCL1A,
    DFTMUX_CLK_NOCL1A_OSCCLK,
    O_CLK_NOCL1A_OSCCLK,
    CLK_NOCL1A_OSCCLK,
    OSCCLK_NOCL1A__ALO,
    OSCCLK_PERI,
    DFTMUX_CLK_PERI_OSCCLK,
    CLK_PERI_OSCCLK,
    OSCCLK_PERI__ALO,
    DFTMUX_CLK_RGBP_OSCCLK,
    O_CLK_RGBP_OSCCLK,
    CLK_RGBP_OSCCLK,
    OSCCLK_RGBP,
    FREE_OSCCLK_RGBP,
    OSCCLK_RGBP__ALO,
    OSCCLK_USB,
    DFTMUX_CLK_USB_OSCCLK,
    O_CLK_USB_OSCCLK,
    CLK_USB_OSCCLK,
    DFT_CLKOCC__OCC_CLK_USB_OSCCLK_USB1,
    DFT_CLKOCC__OCC_CLK_USB_OSCCLK_USB2,
    DFT_CLKOCC__OCC_CLK_USB_OSCCLK_USB4,
    DFT_CLKOCC__OCC_CLK_USB_OSCCLK_USB3,
    DFT_CLKOCC__OCC_CLK_USB_OSCCLK_USB5,
    DFTMUX_CLK_YUVP_OSCCLK,
    O_CLK_YUVP_OSCCLK,
    CLK_YUVP_OSCCLK,
    OSCCLK_YUVP,
    FREE_OSCCLK_YUVP,
    OSCCLK_YUVP__ALO,
    DFTMUX_CLK_CSIS_OSCCLK,
    O_CLK_CSIS_OSCCLK,
    CLK_CSIS_OSCCLK,
    OSCCLK_CSIS,
    CLK_CSIS_FREE_OSCCLK,
    OSCCLK_CSIS__ALO,
    OSCCLK_CSTAT,
    DFTMUX_CLK_CSTAT_OSCCLK,
    O_CLK_CSTAT_OSCCLK,
    CLK_CSTAT_OSCCLK,
    FREE_OSCCLK_CSTAT,
    OSCCLK_CSTAT__ALO,
    OSCCLK_M2M,
    DFTMUX_CLK_M2M_OSCCLK,
    O_CLK_M2M_OSCCLK,
    CLK_M2M_OSCCLK,
    FREE_OSCCLK_M2M,
    OSCCLK_M2M__ALO,
    OSCCLK_RCO_CMGP,
    DFTMUX_CLK_CMGP_OSCCLK_RCO,
    CLK_CMGP_OSCCLK_RCO,
    OSCCLK_RCO_CMGP__ALV,
    OSCCLK_DBGCORE,
    DFTMUX_CLK_DBGCORE_OSCCLK,
    CLK_DBGCORE_FREE_OSCCLK,
    FREE_OSCCLK_DBGCORE,
    MUX_FREE_OSCCLK_DBGCORE,
    OSCCLK_DBGCORE__ALO,
    OSCCLK_ICPU,
    DFTMUX_CLK_ICPU_OSCCLK,
    FREE_OSCCLK_ICPU,
    CLK_ICPU_FREE_OSCCLK,
    OSCCLK_ICPU__ALO,
    OSCCLK_CPUCL0,
    CLK_CPUCL0_OSCCLK,
    DFTMUX_CLK_CPUCL0_OSCCLK,
    OSCCLK_CPUCL0__ALO,
    DFTMUX_CLK_S2D_OSCCLK,
    CLK_S2D_OSCCLK,
    FREE_OSCCLK_S2D,
    OSCCLK_S2D,
    OSCCLK_S2D__ALO,
    OSCCLK_CPUCL1,
    CLK_CPUCL1_OSCCLK,
    DFTMUX_CLK_CPUCL1_OSCCLK,
    CLK_CPUCL0_GLB_OSCCLK,
    DFTMUX_CLK_CPUCL0_GLB_OSCCLK,
    OSCCLK_DSU,
    DFTMUX_CLK_DSU_OSCCLK,
    CLK_DSU_OSCCLK,
    end_of_fixed_rate,
    num_of_fixed_rate = (end_of_fixed_rate - FIXED_RATE_TYPE & MASK_OF_ID),
};
#endif
