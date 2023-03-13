/****************************************************************************
 *
 * Copyright (c) 2014 - 2022 Samsung Electronics Co., Ltd. All rights reserved
 *
 ****************************************************************************/
#ifndef _PMU_CAL_H_
#define _PMU_CAL_H_

#ifdef CONFIG_SOC_S5E5515
#include "platform_mif_s5e5515.h"
#include "mif_reg_S5E5515.h"
#endif
#ifdef CONFIG_SOC_S5E8825
#include "platform_mif_s5e8825.h"
#include "mif_reg_S5E8825.h"
#endif
#ifdef CONFIG_SOC_S5E8535
#include "platform_mif_s5e8535.h"
#include "mif_reg_S5E8535.h"
#endif
#ifdef CONFIG_SOC_S5E8835
#include "platform_mif_s5e8835.h"
#include "mif_reg_S5E8835.h"
#endif

#include "linux/regmap.h"

#define MAX_NAME_SIZE 20

struct pmucal {
	struct pmucal_data *init;
	struct pmucal_data *reset_assert;
	struct pmucal_data *reset_release;
	int init_size;
	int reset_assert_size;
	int reset_release_size;
};
struct pmucal_data {
	int accesstype;
	bool bypass;
	bool pmureg;
	int sfr;
	int field;
	int value;
};

enum WLBT_PMUCAL_ACCESS_TYPE {
	WLBT_PMUCAL_WRITE,
	WLBT_PMUCAL_DELAY,
	WLBT_PMUCAL_READ,
	WLBT_PMUCAL_ATOMIC,
	WLBT_PMUCAL_CLEAR,
};

extern struct pmucal pmucal_wlbt;
int pmu_cal_progress(struct platform_mif *platform,
		     struct pmucal_data *pmu_data, int pmucal_data_size);

#endif
