/*
 * CanFix.c
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */
#include <CanFix.h>
#include <CanFixHw.h>

void CAN_FIX_Initialize()
{
	CanFixHw_Initialize();
	//CAN_FIX does not give good options for hardware masks.
	//Disable the masks.
	CanFixHw_SetHardwareMask(0x0000);

}

void CAN_FIX_SendAlarm()
{
	CanFixHw_SendMessage(NULL,NULL);
}

void CAN_FIX_HandleCanRxMessage(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{

}

void CAN_FIX_PeriodicCheck(void)
{
	CanFixHw_PeriodicCheck();
}
