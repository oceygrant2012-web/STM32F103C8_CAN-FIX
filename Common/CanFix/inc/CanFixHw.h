/*
 * StmCanFixHw.h
 * This header file should work no matter which implementation is
 * applied to the project
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */

#ifndef APPLICATION_USER_CORE_CANFIXHW_H_
#define APPLICATION_USER_CORE_CANFIXHW_H_
#include <CanFix.h>
//This was included to get the definitions of basic data types only
#include "main.h"

void CanFixHw_SendMessage(CAN_FIX_TxHeaderTypeDef* txHeader, uint8_t* txData);
void CanFixHw_Initialize();
void CanFixHw_SetHardwareMask(uint16_t mask);
void CanFixHw_PeriodicCheck(void);

#endif /* APPLICATION_USER_CORE_CANFIXHW_H_ */
