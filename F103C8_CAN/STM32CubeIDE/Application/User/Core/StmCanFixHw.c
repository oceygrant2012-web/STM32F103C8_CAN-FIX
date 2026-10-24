/*
 * StmCanFixHw.c
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */

#include <CanFixHw.h>
#include "stm32f1xx_hal.h"

//Implementation in Main.c
void Error_Handler();
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

CAN_HandleTypeDef hcan;
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;

uint8_t TxData[8];
uint8_t RxData[8];

uint32_t TxMailbox;
uint32_t RxMailbox;
int dataCheck = 0;

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void StmCanFixHw_Init(void)
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
  CanFixHw_ConfigureFilter();

  /* USER CODE END CAN1_Init 2 */

}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO1,&RxHeader, RxData);
	if(RxHeader.DLC == 2)
	{
		dataCheck =  1;
	}
}

void CanFixHw_SetHardwareMask(uint16_t mask)
{
	  CAN_FilterTypeDef canFilterConfig;

	  canFilterConfig.FilterActivation = CAN_FILTER_ENABLE; //Enable or disable the filters
	  canFilterConfig.FilterBank = 10; // 0.. SlaveStartFilterBank per Spec Sheet where device only has 1 CAN element
	  canFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO1;
	  canFilterConfig.FilterIdHigh = 0x446<<5; //32-bit ID/mask.  Shift 5 to place in correct location (Get past Exid 13-17).
	  canFilterConfig.FilterIdLow = 0;
	  canFilterConfig.FilterMaskIdHigh = 0x446<<5;//32-bit ID/mask.  Shift 5 to place in correct location (Get past Exid 13-17).
	  canFilterConfig.FilterMaskIdLow = 0x0000; //This is possibly wrong.
	  canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	  canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	  canFilterConfig.SlaveStartFilterBank = 13; //Doesn't matter with uProc with only one CAN (1 CAN 0..13, 2 CAN 0..27)

	  HAL_CAN_ConfigFilter(&hcan, &canFilterConfig);
}


void CanFixHw_Initialize()
{
	  MX_CAN_Init();
	  /* USER CODE BEGIN 2 */

	  HAL_CAN_Start(&hcan);
	  //Activate Notification
	  HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO1_MSG_PENDING);

	  TxHeader.DLC = 2; // 2 data bytes
	  TxHeader.IDE = CAN_ID_STD; //Standard length ID (11 Bit) vs Extended length ID (29 Bit)
	  TxHeader.RTR = CAN_RTR_DATA;
	  TxHeader.StdId = 0x103; //Sender ID (this 103 device) Min_Data = 0 and Max_Data = 0x7FF
	  //TxHeader.ExtId = 0; //Min_Data = 0 and Max_Data = 0x1FFFFFFF
	  TxHeader.TransmitGlobalTime = DISABLE; //Disable sending time-stamp

		TxData[0] = 50; //Delay 100ms Example indicates Byte 0 represents delay
		TxData[1] = 20; // Number of times to Blink
}

void CanFixHw_PeriodicCheck(void)
{
	  if(dataCheck == 1)
	  {
		  for(int i = 0; i < RxData[1]; i++)
		  {
			  //BSP_LED_Toggle(LED2);
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			  HAL_Delay(RxData[0]);
		  }
		  dataCheck = 0;
	  }

	  HAL_CAN_AddTxMessage(&hcan,&TxHeader, TxData, &TxMailbox);
}

void CanFixHw_ConfigureFilter(void)
{
	CanFixHw_SetHardwareMask(0x0103);
}
