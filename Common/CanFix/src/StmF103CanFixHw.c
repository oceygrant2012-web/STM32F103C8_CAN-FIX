/*
 * StmCanFixHw.c
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */

#include <CanFixHw.h>
#include "stm32f1xx_hal.h"
#include "string.h"

//Implementation in Main.c
void Error_Handler();
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
CAN_TxHeaderTypeDef TxHeader;
uint8_t RxData[8];

CAN_HandleTypeDef hcan1;

CAN_RxHeaderTypeDef RxHeader;

uint8_t TxData[8];
uint32_t TxMailbox;
uint32_t RxMailbox;
int dataCheck = 0;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0,&RxHeader, RxData);
	if(RxHeader.DLC == 2)
	{
		dataCheck =  1;
	}
}

void CanFixHw_SetHardwareMask(uint16_t mask)
{
	  CAN_FilterTypeDef canFilterConfig;

	  canFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
	  canFilterConfig.FilterBank = 18;
	  canFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	  canFilterConfig.FilterIdHigh = mask<<5; //32-bit ID/mask.  Shift 5 to place in correct location (Get past Exid 13-17).
	  canFilterConfig.FilterIdLow = 0;
	  canFilterConfig.FilterMaskIdHigh = mask<<5;//32-bit ID/mask.  Shift 5 to place in correct location (Get past Exid 13-17).
	  canFilterConfig.FilterMaskIdLow = 0x0000; //This is possibly wrong.
	  canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	  canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	  canFilterConfig.SlaveStartFilterBank = 20;

	  HAL_CAN_ConfigFilter(&hcan1, &canFilterConfig);
}

void CanFixHw_SendMessage(CAN_FIX_TxHeaderTypeDef* header, uint8_t* txData)
{
	TxHeader.DLC = header->DLC;
	TxHeader.ExtId = header->ExtId;
	TxHeader.IDE = header->IDE;
	TxHeader.RTR = header->RTR;
	TxHeader.StdId = header->StdId;
	TxHeader.TransmitGlobalTime = header->TransmitGlobalTime;
	memcpy(TxData,txData,TxHeader.DLC);
	HAL_CAN_AddTxMessage(&hcan1,&TxHeader, TxData, &TxMailbox);
}

void CanFixHw_Initialize(uint32_t canId)
{
	  /* USER CODE BEGIN CAN1_Init 0 */

	  /* USER CODE END CAN1_Init 0 */

	  /* USER CODE BEGIN CAN1_Init 1 */

	  /* USER CODE END CAN1_Init 1 */
	  hcan1.Instance = CAN1;
	  hcan1.Init.Prescaler = 18;
	  hcan1.Init.Mode = CAN_MODE_NORMAL;
	  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
	  hcan1.Init.TimeSeg1 = CAN_BS1_2TQ;
	  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
	  hcan1.Init.TimeTriggeredMode = DISABLE;
	  hcan1.Init.AutoBusOff = DISABLE;
	  hcan1.Init.AutoWakeUp = DISABLE;
	  hcan1.Init.AutoRetransmission = DISABLE;
	  hcan1.Init.ReceiveFifoLocked = DISABLE;
	  hcan1.Init.TransmitFifoPriority = DISABLE;
	  if (HAL_CAN_Init(&hcan1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN CAN1_Init 2 */
	  CanFixHw_SetHardwareMask(0x0000);

	  /* USER CODE END CAN1_Init 2 */
	  /* USER CODE BEGIN 2 */
	  HAL_CAN_Start(&hcan1);
	  //Activate Notification
	  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);

	  TxHeader.DLC = 2; // 2 data bytes
	  TxHeader.IDE = CAN_ID_STD;
	  TxHeader.RTR = CAN_RTR_DATA;
	  TxHeader.StdId = canId; //Sender ID (this 446 device)
}

void CanFixHw_PeriodicCheck(void)
{
	  if(dataCheck == 1)
	  {
		  for(int i = 0; i < RxData[1]; i++)
		  {
			  //BSP_LED_Toggle(LED2);
			  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			  HAL_Delay(RxData[0]);
		  }
		  dataCheck = 0;
	  }
}
