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

//These are declared with the Hardwre as the implementation is hardware dependent.
//The bytes must be little-endien.  Depending on the microprocessor endienness,
//The implementation may need to change.
void ConvertInt16ToBytes(int16_t data, uint8_t* bytes);
int16_t ConvertBytesToInt16(uint8_t* bytes);
void ConvertUInt16ToBytes(uint16_t data, uint8_t* bytes);
uint16_t ConvertBytesToUint16(uint8_t* bytes);
void ConvertInt32ToBytes(int32_t data, uint8_t* bytes);
int32_t ConvertBytesToInt32(uint8_t* bytes);
void ConvertUInt32ToBytes(uint32_t data, uint8_t* bytes);
uint32_t ConvertBytesToUint32(uint8_t* bytes);
void ConvertFloatToBytes(float data, uint8_t* bytes);
float ConvertBytesToFloat(uint8_t* bytes);

#endif /* APPLICATION_USER_CORE_CANFIXHW_H_ */
