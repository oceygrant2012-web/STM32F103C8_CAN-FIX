/*
 * CanFix.c
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */
#include <CanFix.h>
#include <CanFixHw.h>

uint16_t CanId = 0;
CAN_FIX_TxHeaderTypeDef CAN_FIX_TxHeader;

void CAN_FIX_Initialize(uint32_t canId)
{
	CAN_FIX_TxHeader.StdId = 0;    /*!< Specifies the standard identifier.
	                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

	CAN_FIX_TxHeader.ExtId = 0;    /*!< Specifies the extended identifier.
	                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

	CAN_FIX_TxHeader.IDE = CAN_ID_STD;      /*!< Specifies the type of identifier for the message that will be transmitted.
	                          This parameter can be a value of @ref CAN_identifier_type */

	CAN_FIX_TxHeader.RTR = CAN_RTR_DATA;      /*!< Specifies the type of frame for the message that will be transmitted.
	                          This parameter can be a value of @ref CAN_remote_transmission_request */

	CAN_FIX_TxHeader.DLC=0;      /*!< Specifies the length of the frame that will be transmitted.
	                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

	CAN_FIX_TxHeader.TransmitGlobalTime = ENABLE; /*!< Specifies whether the timestamp counter value captured on start
	                          of frame transmission, is sent in DATA6 and DATA7 replacing pData[6] and pData[7].
	                          @note: Time Triggered Communication Mode must be enabled.
	                          @note: DLC must be programmed as 8 bytes, in order these 2 bytes are sent.
	                          This parameter can be set to ENABLE or DISABLE. */
	  CanId = canId;
	CanFixHw_Initialize(canId);
	//CAN_FIX does not give good options for hardware masks.
	//Disable the masks.
	CanFixHw_SetHardwareMask(0x0000);

}




void CAN_FIX_HandleCanRxMessage(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData)
{
	CAN_FIX_HandleHighPriorityNodeAlarm(rxHeader, rxData);
}

void CAN_FIX_PeriodicCheck(void)
{
	CanFixHw_PeriodicCheck();
}

void CAN_FIX_SendHighPriortyNodeAlarm(uint8_t alarm, uint8_t* alarmData, uint8_t alarmLength)
{
	CAN_FIX_TxHeader.DLC = alarmLength;
	CAN_FIX_TxHeader.StdId = CanId;
	CanFixHw_SendMessage(&CAN_FIX_TxHeader,alarmData);
}

void CAN_FIX_SendNodeSpecificMessage(void)
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
