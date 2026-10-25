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

void CAN_FIX_SendHighPriortyNodeAlarm()
{

}
void CAN_FIX_SendNodeSpecificMessage()
{

}
void CAN_FIX_SendTwoWayCommunication(uint8_t channel, int8_t sender, uint8_t* data)
{

}


/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityNodeAlarm(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityPilotControlInput(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityMeasuredPosition(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityFlightData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityNavigationData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityEngineAircraftData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleHighPriorityAuxiliaryData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityPilotControlInput(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityMeasuredPosition(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityFlightData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityNavigationData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityEngineAircraftData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNormalPriorityAuxiliaryData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleTwoWayConnectionChannelData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}

/* Define the default function with __weak attribute */
__weak void CAN_FIX_HandleNodeSpecificMessage(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
    // Default empty implementation or basic logic
}
