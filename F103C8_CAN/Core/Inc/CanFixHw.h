/*
 * StmCanFixHw.h
 * This header file should work no matter which implementation is
 * applied to the project
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */

#ifndef APPLICATION_USER_CORE_CANFIXHW_H_
#define APPLICATION_USER_CORE_CANFIXHW_H_
#include "stm32f4xx_hal.h"

void CanFixHw_Initialize(void);
void CanFixHw_SetHardwareMask(uint16_t mask);
void CanFixHw_ConfigureFilter(void);
void CanFixHw_PeriodicCheck(void);

#endif /* APPLICATION_USER_CORE_CANFIXHW_H_ */
