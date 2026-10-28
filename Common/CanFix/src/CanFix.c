/*
 * CanFix.c
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */
#include <CanFix.h>
#include <CanFixHw.h>
#include <string.h>

/**
  * @brief  The ID of the node (can device number) sending or receiving the data
  */
uint16_t NodeId = 0;
CAN_FIX_TxHeaderTypeDef CAN_FIX_TxHeader;
uint8_t CanFixTxData[8];

/**
  * @brief  Initialize the CAN-FIX software.  Must be called before performing any other commands
  * nodeId: The ID of the node (can device number) sending or receiving the data (1.255)
  * nodeId should be issued either by the EFIS or stored in an eeprom
  */
void CAN_FIX_Initialize(uint32_t nodeId)
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
	  NodeId = nodeId;
	CanFixHw_Initialize(nodeId);
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

void ConvertToBytesInt(int16_t data, uint8_t* bytes)
{
	bytes[0] = data & 0xFF; //lsb first
	bytes[1] = (data >> 8) & 0xFF; //msb
}

void ConvertToBytesUInt(uint16_t data, uint8_t* bytes)
{
	bytes[0] = data & 0xFF; //lsb first
	bytes[1] = (data >> 8) & 0xFF; //msb
}

//These are used by CAN_FIX_SendHighPriorityTrimControlSwitch
#define HighPriorityTrimControlSwitchCanId_0 0x102
#define HighPriorityTrimControlSwitchCanId_1 0x103

#define TrimPosition_PitchUp 0x0001
#define TrimPosition_PitchDown 0x0002
#define TrimPosition_PitchCenter 0x0004
#define TrimPosition_RollLeft 0x0008
#define TrimPosition_RollRight 0x0010
#define TrimPosition_RollCenter 0x0020
#define TrimPosition_YawLeft 0x0040
#define TrimPosition_YawRight 0x0080
#define TrimPosition_YawCenter 0x0100
#define TrimPosition_CollectiveUp 0x0200
#define TrimPosition_CollectiveDown 0x0400
#define TrimPosition_AtPedalsLeft 0x0800
#define TrimPosition_AtPedalsRight 0x1000
#define TrimPosition_AtPedalsCenter 0x2000


//These are used by CAN_FIX_SendHighPriorityControlSwitch
#define FlapPosition_Up 0x01
#define FlapPosition_Down 0x02
#define FlapPosition_1 0x04
#define FlapPosition_2 0x08
#define FlapPosition_3 0x10
#define FlapPosition_4 0x20
#define FlapPosition_5 0x40
#define FlapPosition_6 0x80

#define CanFix_Switch_0 0x01
#define CanFix_Switch_1 0x02
#define CanFix_Switch_2 0x04
#define CanFix_Switch_3 0x08
#define CanFix_Switch_4 0x10
#define CanFix_Switch_5 0x20
#define CanFix_Switch_6 0x40
#define CanFix_Switch_7 0x80

#define AutoPilot_Engage 0x01
#define AutoPilot_Disengage 0x02
#define AutoPilot_VSMode 0x04
#define AutoPilot_AltHoldMode 0x08
#define AutoPilot_AltSelectMode 0x10
#define AutoPilot_HeadingIncrement 0x20
#define AutoPilot_HeadingDecrement 0x40

#define VHF_PTT 0x01
#define VHF_Swap 0x02
#define VHF_Next 0x04
#define VHF_Last 0x08

#define Transponder_Ident 0x01
#define Transponder_Alt1 0x02
#define Transponder_Stby 0x04
#define Transponder_Alt2 0x08
#define Transponder_VFR 0x10
#define Transponder_OFF 0x20
#define Transponder_Squat 0x40

#define LandingGear_Down 0
#define LandingGear_Up 1
#define LandingGear_Nose 0x01
#define LandingGear_Left 0x02
#define LandingGear_Right 0x04

#define HighPriorityFlapControlSwitchCanId_0 0x100
#define HighPriorityFlapControlSwitchCanId_1 0x101

#define HighPriorityElectricalControlSwitchCanId_0 0x104
#define HighPriorityElectricalControlSwitchCanId_1 0x105
#define HighPriorityLightingControlSwitchCanId_0 0x106
#define HighPriorityLightingControlSwitchCanId_1 0x107
#define HighPriorityFuelPumpControlSwitchCanId_0 0x108
#define HighPriorityFuelPumpControlSwitchCanId_1 0x109
#define HighPriorityFuelValveControlSwitchCanId_0 0x10A
#define HighPriorityFuelValveControlSwitchCanId_1 0x10B
#define HighPriorityAutoPilotControlSwitchCanId_0 0x10C
#define HighPriorityAutoPilotControlSwitchCanId_1 0x10D
#define HighPriorityVHFControlSwitchCanId_0 0x10E
#define HighPriorityVHFControlSwitchCanId_1 0x10F
#define HighPriorityTransponderControlSwitchCanId_0 0x110
#define HighPriorityTransponderControlSwitchCanId_1 0x111
#define HighPriorityStarterMagsControlSwitchCanId_0 0x112
#define HighPriorityStarterMagsControlSwitchCanId_1 0x113
#define HighPriorityLandingGearControlSwitchCanId_0 0x114
#define HighPriorityLandingGearControlSwitchCanId_1 0x115
#define HighPriorityGenericControlSwitchCanId_0 0x118
#define HighPriorityGenericControlSwitchCanId_1 0x119

//These are used by CAN_FIX_SendHighPriorityKeyPress
#define HighPriorityKeypadKeyControlCanId_0 0x116
#define HighPriorityKeypadKeyControlCanId_1 0x117

// These are set by CAN_FIX_SendHighPriorityControlPositionInt
#define HighPriorityPitchControlCanId 0x11A
#define HighPriorityRollControlCanId 0x11B
#define HighPriorityYawControlCanId 0x11C
#define HighPriorityCollectiveControlCanId 0x11D
#define HighPriorityAntiTorqueControlCanId 0x11E
#define HighPriorityFlapControlCanId 0x11F

//High Priority Controls
#define HighPriorityLeftBrakeControlCanId 0x120
#define HighPriorityRightBrakeControlCanId 0x121
#define HighPriorityEngineThrottleControlCanId_0 0x122
#define HighPriorityEngineThrottleControlCanId_1 0x123
#define HighPriorityEngineThrottleControlCanId_2 0x124
#define HighPriorityEngineThrottleControlCanId_3 0x125
#define HighPriorityEnginePropControlCanId_0 0x126
#define HighPriorityEnginePropControlCanId_1 0x127
#define HighPriorityEnginePropControlCanId_2 0x128
#define HighPriorityEnginePropControlCanId_3 0x129
#define HighPriorityEngineMixtureControlCanId_0 0x12A
#define HighPriorityEngineMixtureControlCanId_1 0x12B
#define HighPriorityEngineMixtureControlCanId_2 0x12C
#define HighPriorityEngineMixtureControlCanId_3 0x12D

//High Priority Measurements
#define HighPriorityElevatorMeasurementCanId 0x140
#define HighPriorityAileronMeasurementCanId 0x141
#define HighPriorityRudderMeasurementCanId 0x142
#define HighPriorityCollectiveMeasurementCanId 0x143
#define HighPriorityTailRotorMeasurementCanId 0x144
#define HighPriorityFlapMeasurementCanId 0x145
#define HighPriorityLandingGearPositionSwCanId 0x146

#define HighPriorityPitchAngleMeasurementCanId 0x180
#define HighPriorityRollAngleMeasurementCanId 0x181
#define HighPriorityAngleOfAttackMeasurementCanId 0x182
#define HighPriorityAirspeedMeasurementCanId 0x183

typedef enum {
	Angle_Min = 1,
	Angle_Max = 2
}AttitudeAngleTypedef;



void CAN_FIX_SendHighPriortyNodeAlarm(uint16_t alarm, uint8_t* alarmData, uint8_t alarmDataLength)
{
	if(alarmDataLength > 6)
		return;
	CAN_FIX_TxHeader.DLC = 2 + alarmDataLength;
	CAN_FIX_TxHeader.StdId = NodeId;
	ConvertToBytesUInt(alarm, CanFixTxData);
	memcpy(&CanFixTxData[2], alarmData, alarmDataLength);
	CanFixHw_SendMessage(&CAN_FIX_TxHeader,CanFixTxData);
}

void CAN_FIX_SendDataMessage(uint16_t canId, uint8_t index, uint8_t functionCode, uint8_t* messageData, uint8_t dataLength)
{
	//Must be less than 11 bits
	if(canId & 0xf800)
		return;
	//Message Data cannot be greater than 5
	if(dataLength > 5)
		return;
	CAN_FIX_TxHeader.StdId = canId;
	CAN_FIX_TxHeader.DLC = 3 + dataLength;
	CanFixTxData[0] = NodeId;
	CanFixTxData[1] = index;
	CanFixTxData[2] = functionCode;
	memcpy(&CanFixTxData[3], messageData, dataLength);
	CanFixHw_SendMessage(&CAN_FIX_TxHeader,CanFixTxData);
}

void CAN_FIX_SendHighPriorityControlSwitch(uint16_t canId, uint8_t index, uint8_t functionCode, uint8_t button)
{
	if((canId < HighPriorityFlapControlSwitchCanId_0) ||
	   (canId > HighPriorityGenericControlSwitchCanId_1) ||
	   (canId == HighPriorityTrimControlSwitchCanId_0) ||
	   (canId == HighPriorityTrimControlSwitchCanId_1) ||
	   (canId == HighPriorityKeypadKeyControlCanId_0) ||
	   (canId == HighPriorityKeypadKeyControlCanId_1))
		return;

	CAN_FIX_SendDataMessage(canId, index, functionCode, &button, 1);
}

void CAN_FIX_SendHighPriorityTrimControlSwitch(uint16_t canId, uint8_t index, uint8_t functionCode, uint16_t position)
{
	if((canId != HighPriorityTrimControlSwitchCanId_0) &&
	   (canId != HighPriorityTrimControlSwitchCanId_1))
		return;
	uint8_t data[2];
	ConvertToBytesUInt(position, data);
	CAN_FIX_SendDataMessage(canId, index, functionCode, data, 2);
}

void CAN_FIX_SendHighPriorityKeyPress(uint16_t canId, uint8_t index, uint8_t functionCode, uint8_t key, uint8_t altFunction)
{
	if((canId < HighPriorityKeypadKeyControlCanId_0) ||
	   (canId > HighPriorityKeypadKeyControlCanId_1))
		return;

	uint8_t data[2];
	data[0] = key;
	data[1] = altFunction;
	CAN_FIX_SendDataMessage(canId, index, functionCode, data, 2);
}




//////////Start///////////////////////////////////////////////////////////////////

void CAN_FIX_SendMeasurement(uint16_t canId, uint8_t index, uint8_t functionCode, float floatData, uint8_t decimalPlaces)
{
	uint8_t data[2];
	int exp = 10^decimalPlaces;
	int16_t updatedPosition = (int16_t)(floatData * exp);
	ConvertToBytesInt(updatedPosition, data);
	CAN_FIX_SendDataMessage(canId, index, functionCode, data, 2);
}


//////End/////////////////////////////////////////////////////////////////
typedef enum{
	ControlSurfaceControl_Pitch,
	ControlSurfaceControl_Roll,
	ControlSurfaceControl_Yaw,
	ControlSurfaceControl_Collective,
	ControlSurfaceControl_AntiTorquePedals,
	ControlSurfaceControl_Flaps
}ControlSurfaceControlsTypedef;

#define HighPriorityPitchControlCanId 0x11A
#define HighPriorityRollControlCanId 0x11B
#define HighPriorityYawControlCanId 0x11C
#define HighPriorityCollectiveControlCanId 0x11D
#define HighPriorityAntiTorqueControlCanId 0x11E
#define HighPriorityFlapControlCanId 0x11F

void CAN_FIX_SendControlSurfaceControlPosition(ControlSurfaceControlsTypedef surface, float position )
{
	if(position < -100 || position > 100)
		return;

	uint16_t canId;
	switch(surface)
	{
	case ControlSurfaceControl_Pitch:
		canId = HighPriorityPitchControlCanId;
		break;
	case ControlSurfaceControl_Roll:
		canId = HighPriorityRollControlCanId;
		break;
	case ControlSurfaceControl_Yaw:
		canId = HighPriorityYawControlCanId;
		break;
	case ControlSurfaceControl_Collective:
		canId = HighPriorityCollectiveControlCanId;
		break;
	case ControlSurfaceControl_AntiTorquePedals:
		canId = HighPriorityAntiTorqueControlCanId;
		break;
	case ControlSurfaceControl_Flaps:
		canId = HighPriorityFlapControlCanId;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, 0, 0, position, 2);
}

typedef enum{
	ControlLever_LeftBrake,
	ControlLever_RightBrake,
	ControlLever_EngineThrottle_0,
	ControlLever_EngineThrottle_1,
	ControlLever_EngineThrottle_2,
	ControlLever_EngineThrottle_3,
	ControlLever_EngineProp_0,
	ControlLever_EngineProp_1,
	ControlLever_EngineProp_2,
	ControlLever_EngineProp_3,
	ControlLever_EngineMixture_0,
	ControlLever_EngineMixture_1,
	ControlLever_EngineMixture_2,
	ControlLever_EngineMixture_3
}ControlLeverTypedef;

void CAN_FIX_SendControlLeverPosition(ControlLeverTypedef lever, float position, uint8_t index )
{
	if(position < 0 || position > 100)
		return;

	uint16_t canId;
	switch(lever)
	{
	case ControlLever_LeftBrake:
		canId = HighPriorityLeftBrakeControlCanId;
		break;
	case ControlLever_RightBrake:
		canId = HighPriorityRightBrakeControlCanId;
		break;
	case ControlLever_EngineThrottle_0:
		canId = HighPriorityEngineThrottleControlCanId_0;
		break;
	case ControlLever_EngineThrottle_1:
		canId = HighPriorityEngineThrottleControlCanId_1;
		break;
	case ControlLever_EngineThrottle_2:
		canId = HighPriorityEngineThrottleControlCanId_2;
		break;
	case ControlLever_EngineThrottle_3:
		canId = HighPriorityEngineThrottleControlCanId_3;
		break;
	case ControlLever_EngineProp_0:
		canId = HighPriorityEnginePropControlCanId_0;
		break;
	case ControlLever_EngineProp_1:
		canId = HighPriorityEnginePropControlCanId_1;
		break;
	case ControlLever_EngineProp_2:
		canId = HighPriorityEnginePropControlCanId_2;
		break;
	case ControlLever_EngineProp_3:
		canId = HighPriorityEnginePropControlCanId_3;
		break;
	case ControlLever_EngineMixture_0:
		canId = HighPriorityEngineMixtureControlCanId_0;
		break;
	case ControlLever_EngineMixture_1:
		canId = HighPriorityEngineMixtureControlCanId_1;
		break;
	case ControlLever_EngineMixture_2:
		canId = HighPriorityEngineMixtureControlCanId_2;
		break;
	case ControlLever_EngineMixture_3:
		canId = HighPriorityEngineMixtureControlCanId_3;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, 0, position, 2);
}

typedef enum{
	ControlSurfaceMeasurement_Flaps,
	ControlSurfaceMeasurement_Elevator,
	ControlSurfaceMeasurement_Aileron,
	ControlSurfaceMeasurement_Rudder,
	ControlSurfaceMeasurement_Collective,
	ControlSurfaceMeasurement_TailRotor
}ControlSurfaceMeasurementsTypedef;

void CAN_FIX_SendControlAngle(ControlSurfaceMeasurementsTypedef surface, float angle, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(angle < -90 || angle > 90)
		return;

	uint16_t canId;
	switch(surface)
	{
	case ControlSurfaceMeasurement_Elevator:
		canId = HighPriorityElevatorMeasurementCanId;
		break;
	case ControlSurfaceMeasurement_Aileron:
		canId = HighPriorityAileronMeasurementCanId;
		break;
	case ControlSurfaceMeasurement_Rudder:
		canId = HighPriorityRudderMeasurementCanId;
		break;
	case ControlSurfaceMeasurement_Collective:
		canId = HighPriorityCollectiveMeasurementCanId;
		break;
	case ControlSurfaceMeasurement_TailRotor:
		canId = HighPriorityTailRotorMeasurementCanId;
		break;
	case ControlSurfaceMeasurement_Flaps:
		canId = HighPriorityFlapMeasurementCanId;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, metaData, angle, 2);
}

#define LandingGear_NoseUpFlag 0x0001
#define LandingGear_NoseDownFlag 0x0002
#define LandingGear_LeftUpFlag 0x0004
#define LandingGear_LeftDownFlag 0x0008
#define LandingGear_RightUpFlag 0x0010
#define LandingGear_RightDownFlag 0x0020
#define LandingGear_NoseNotDown 0x0040
#define LandingGear_LeftNotDown 0x0080

//NOte:  for a specified gear neither down nor up, both the respective flags
// are to be set to zero.
void CAN_FIX_SendLandingGearPosition(uint8_t flags, uint8_t index )
{
	if(flags < -180 || flags > 180)
		return;
	CAN_FIX_SendDataMessage(HighPriorityLandingGearPositionSwCanId, index, 0, &flags, 1);
}

typedef enum {
	Attitude_Pitch,
	Attitude_Roll
}AttitudeTypedef;



void CAN_FIX_SendAttitude (AttitudeTypedef attitude, float angle, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(angle < -180 || angle > 180)
		return;
	uint16_t canId;
	switch(attitude)
	{
	case Attitude_Pitch:
		canId = HighPriorityPitchAngleMeasurementCanId;
		break;
	case Attitude_Roll:
		canId = HighPriorityRollAngleMeasurementCanId;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, metaData, angle, 2);
}

typedef enum {
	Aoa_Min = 0b0001,
	Aoa_Max = 0b0010,
	Aoa_0g = 0b0111,
	Aoa_Warn = 0b1000,
	Aoa_Stall = 0b1001

}AngleOfAttackTypedef;

void CAN_FIX_SendAngleOfAttack(float aoa, uint8_t index, AngleOfAttackTypedef metaData )
{
	if(aoa < -180 || aoa > 180)
		return;
	CAN_FIX_SendMeasurement(HighPriorityAngleOfAttackMeasurementCanId, index, metaData, aoa, 2);
}

typedef enum  {
	Airspeed_Min = 0b0001,
	Airspeed_Max = 0b0010,
	Airspeed_V1 = 0b0011,
	Airspeed_V2 = 0b0100,
	Airspeed_Vne = 0b0101,
	Airspeed_Vfe = 0b0110,
	Airspeed_Vmc = 0b0111,
	Airspeed_Va = 0b1000,
	Airspeed_Vno = 0b1001,
	Airspeed_Vs = 0b1010,
	Airspeed_Vs0 = 0b1011,
	Airspeed_Vx = 0b1110,
	Airspeed_Vy = 0b1111
} AirspeedMetadataTypedef;

void CAN_FIX_SendIndicatedAirspeed(float airspeed, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(airspeed < 0 || airspeed > 999.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityAirspeedMeasurementCanId, index, metaData, airspeed, 1);
}

