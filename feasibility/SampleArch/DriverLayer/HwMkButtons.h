/*
 * HwMkButtons.h
 *
 *  Created on: Jul 12, 2024
 *      Author: John
 */

#ifndef DRIVERLAYER_HWMKBUTTONS_H_
#define DRIVERLAYER_HWMKBUTTONS_H_

#include "DomainLayer/LogicLevel_e.h"

/*
 * TODO- initializes mkii buttons.
 */
void HwMkButtons_init(void);

/*
 * TODO- get S1 button value.
 */
LogicLevel_e HwMkButtons_readS1(void);

/*
 * TODO- get S2 button value.
 */
LogicLevel_e HwMkButtons_readS2(void);

#endif /* DRIVERLAYER_HWMKBUTTONS_H_ */
