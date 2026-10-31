/*
 * CanFix.h
 *
 *  Created on: Oct 24, 2026
 *      Author: oceyg
 */

#ifndef APPLICATION_USER_CORE_CANFIX_H_
#define APPLICATION_USER_CORE_CANFIX_H_
#include "main.h"
typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_identifier_type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

  FunctionalState TransmitGlobalTime; /*!< Specifies whether the timestamp counter value captured on start
                          of frame transmission, is sent in DATA6 and DATA7 replacing pData[6] and pData[7].
                          @note: Time Triggered Communication Mode must be enabled.
                          @note: DLC must be programmed as 8 bytes, in order these 2 bytes are sent.
                          This parameter can be set to ENABLE or DISABLE. */

} CAN_FIX_TxHeaderTypeDef;

/**
  * @brief  CAN Rx message header structure definition
  */
typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_identifier_type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

  uint32_t Timestamp; /*!< Specifies the timestamp counter value captured on start of frame reception.
                          @note: Time Triggered Communication Mode must be enabled.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFFFF. */

  uint32_t FilterMatchIndex; /*!< Specifies the index of matching acceptance filter element.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF. */

} CAN_FIX_RxHeaderTypeDef;

//Create the Hardware Mask.
//Standard CAN ID is 11-bits
void CAN_FIX_HandleCanRxMessage(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);
void CAN_FIX_Initialize(uint32_t canId);
void CAN_FIX_PeriodicCheck(void);
//TODO:  This will need to have correct parameters

//Send the type of data to CAN
void CAN_FIX_SendHighPriortyNodeAlarm(uint16_t alarm, uint8_t* alarmData, uint8_t alarmDataLength);
//void CAN_FIX_SendNodeSpecificMessage();
//void CAN_FIX_SendTwoWayCommunication(uint8_t channel, int8_t sender, uint8_t* data);


//Handle Incoming data.  Override the function that is neccessary for the specific need
/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityNodeAlarm(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityPilotControlInput(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityMeasuredPosition(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityFlightData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityNavigationData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityEngineAircraftData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleHighPriorityAuxiliaryData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityPilotControlInput(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityMeasuredPosition(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityFlightData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityNavigationData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityEngineAircraftData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNormalPriorityAuxiliaryData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleTwoWayConnectionChannelData(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

/* Define the default function with __weak attribute */
void CAN_FIX_HandleNodeSpecificMessage(CAN_FIX_RxHeaderTypeDef* rxHeader, uint8_t* rxData);

typedef enum
{
	Pilot,
	CoPilot
}PilotLocationTypedef;





///////////////////////////////////////////////////////////////////////////////////////////////////////////#define CanFix_Switch_0 0x01
#define CanFix_Switch_1 0x02
#define CanFix_Switch_2 0x04
#define CanFix_Switch_3 0x08
#define CanFix_Switch_4 0x10
#define CanFix_Switch_5 0x20
#define CanFix_Switch_6 0x40
#define CanFix_Switch_7 0x80



typedef enum {
	Angle_Min = 1,
	Angle_Max = 2
}AttitudeAngleTypedef;

typedef enum {
	FlapPosition_Up = 0x01,
	FlapPosition_Down = 0x02,
	FlapPosition_1 = 0x04,
	FlapPosition_2 = 0x08,
	FlapPosition_3 = 0x10,
	FlapPosition_4 = 0x20,
	FlapPosition_5 = 0x40,
	FlapPosition_6 = 0x80
} FlapPositionTypedef;

typedef enum {
	TrimPosition_PitchUp = 0x0001,
	TrimPosition_PitchDown = 0x0002,
	TrimPosition_PitchCenter = 0x0004,
	TrimPosition_RollLeft = 0x0008,
	TrimPosition_RollRight = 0x0010,
	TrimPosition_RollCenter = 0x0020,
	TrimPosition_YawLeft = 0x0040,
	TrimPosition_YawRight = 0x0080,
	TrimPosition_YawCenter = 0x0100,
	TrimPosition_CollectiveUp = 0x0200,
	TrimPosition_CollectiveDown = 0x0400,
	TrimPosition_AtPedalsLeft = 0x0800,
	TrimPosition_AtPedalsRight = 0x1000,
	TrimPosition_AtPedalsCenter = 0x2000
} TrimPositionTypedef;



typedef enum{
	AutoPilot_Engage = 0x01,
	AutoPilot_Disengage = 0x02,
	AutoPilot_VSMode = 0x04,
	AutoPilot_AltHoldMode = 0x08,
	AutoPilot_AltSelectMode = 0x10,
	AutoPilot_HeadingIncrement = 0x20,
	AutoPilot_HeadingDecrement = 0x40
} AutopilotTypedef;



typedef enum{
	VHF_PTT = 0x01,
	VHF_Swap = 0x02,
	VHF_Next = 0x04,
	VHF_Last = 0x08
} VHFTypedef;



typedef enum{
	Transponder_Ident = 0x01,
	Transponder_Alt1 = 0x02,
	Transponder_Stby = 0x04,
	Transponder_Alt2 = 0x08,
	Transponder_VFR = 0x10,
	Transponder_OFF = 0x20,
	Transponder_Squat = 0x40
} TransponderTypedef;



typedef enum{
	LandingGear_Down  = 0,
	LandingGear_Up = 1,
	LandingGear_Nose = 0x01,
	LandingGear_Left = 0x02,
	LandingGear_Right = 0x04
} LandingGearTypedef;

typedef enum{
	ControlSurfaceControl_Pitch,
	ControlSurfaceControl_Roll,
	ControlSurfaceControl_Yaw,
	ControlSurfaceControl_Collective,
	ControlSurfaceControl_AntiTorquePedals,
	ControlSurfaceControl_Flaps
}ControlSurfaceControlsTypedef;

typedef enum{
	ControlLever_LeftBrake,
	ControlLever_RightBrake,
	ControlLever_EngineThrottle,
	ControlLever_EngineProp,
	ControlLever_EngineMixture,
}ControlLeverTypedef;

typedef enum{
	ControlSurfaceMeasurement_Flaps,
	ControlSurfaceMeasurement_Elevator,
	ControlSurfaceMeasurement_Aileron,
	ControlSurfaceMeasurement_Rudder,
	ControlSurfaceMeasurement_Collective,
	ControlSurfaceMeasurement_TailRotor
}ControlSurfaceMeasurementsTypedef;

#define LandingGear_NoseUpFlag 0x0001
#define LandingGear_NoseDownFlag 0x0002
#define LandingGear_LeftUpFlag 0x0004
#define LandingGear_LeftDownFlag 0x0008
#define LandingGear_RightUpFlag 0x0010
#define LandingGear_RightDownFlag 0x0020
#define LandingGear_NoseNotDown 0x0040
#define LandingGear_LeftNotDown 0x0080

typedef enum {
	Attitude_Pitch,
	Attitude_Roll
}AttitudeTypedef;

typedef enum {
	Aoa_Min = 0b0001,
	Aoa_Max = 0b0010,
	Aoa_0g = 0b0111,
	Aoa_Warn = 0b1000,
	Aoa_Stall = 0b1001

}AngleOfAttackTypedef;

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

typedef enum
{
	FlapControlSwitches,      //100
	TrimControlSwitches,      //102
	ElectricalBusControlSwitches, //104
	LightingControlSwitches,  //106
	FuelPumpControlSwitches,//108
	FuelValveControlSwitches, //10A
	AutoPilotControlSwitches,     //10C
	VhfControlSwitches,    //10E
	TransponderControlSwitches,   //110
	StarterMagnetoControlSwitches, //112
	LandingGearControlSwitches,    //114
	GenericControlSwitches,       //118

} ControlSwitchTypedef;

typedef enum
{
	LandingGearPositionIndicatorSwitch, //146
	FuelPressureIndicatorSwitch, //218
	OilPressureIndicatorSwitch, //21C
	OilTemperatureIndicatorSwitch, //220
	CoolantTemperatureIndicatorSwitch, //224
	FuelQuantityIndicatorSwitch, //228
	OilQuantityIndicatorSwitch, //22C
	CoolantQuantityIndicatorSwitch //230

} IndicatorSwitchTypedef;

typedef enum
{
	FuelPressureSwitch,
	OilPressureSwitch,
	OilTempSwitch,
	CoolantTempSwitch,
	FuelQuantitySwitch,
	OilQuantitySwitch,
	CoolantQuantitySwitch,
	SystemMaxValue
} EngineFluidSwitchTypedef;


typedef enum int8_t
{
	Normal = 0,
	High = 1,
	Low = -1
}SwitchValueTypedef;

void CAN_FIX_SendHighPriortyNodeAlarm(uint16_t alarm, uint8_t* alarmData, uint8_t alarmDataLength);
void CAN_FIX_SendHighPriorityKeyPress( PilotLocationTypedef pilot, uint8_t index, uint8_t functionCode, uint8_t key, uint8_t altFunction);
void CAN_FIX_SendHighPriorityFlapControlSwitch(PilotLocationTypedef device, FlapPositionTypedef button);
void CAN_FIX_SendHighPriorityTrimControlSwitch(PilotLocationTypedef device, TrimPositionTypedef button);
void CAN_FIX_SendAutopilotControl(PilotLocationTypedef device, AutopilotTypedef button);
void CAN_FIX_SendVHFControl(PilotLocationTypedef device, VHFTypedef button);
void CAN_FIX_SendTransponderControl(PilotLocationTypedef device, TransponderTypedef button);
void CAN_FIX_SendLandingGearControl(PilotLocationTypedef device, LandingGearTypedef button);
void CAN_FIX_SendSwitchControl(ControlSwitchTypedef surface, uint8_t index, uint8_t button);
void CAN_FIX_SendControlSurfaceControlPosition(ControlSurfaceControlsTypedef surface, float position );
void CAN_FIX_SendControlLeverPosition(ControlLeverTypedef lever, uint8_t element, float position, uint8_t index );
void CAN_FIX_SendControlAngle(ControlSurfaceMeasurementsTypedef surface, float angle, uint8_t index, AttitudeAngleTypedef metaData );
//NOte:  for a specified gear neither down nor up, both the respective flags
// are to be set to zero.
void CAN_FIX_SendLandingGearPosition(uint8_t flags, uint8_t index , AirspeedMetadataTypedef metaData );
void CAN_FIX_SendAttitude (AttitudeTypedef attitude, float angle, uint8_t index, AttitudeAngleTypedef metaData );
void CAN_FIX_SendAngleOfAttack(float aoa, uint8_t index, AngleOfAttackTypedef metaData );
void CAN_FIX_SendIndicatedAirspeed(float airspeed, uint8_t index, AirspeedMetadataTypedef metaData );
void CAN_FIX_SendIndicatedAltitude(float altitude, uint8_t index, AirspeedMetadataTypedef metaData );
void CAN_FIX_SendIndicatedHeading(float heading, uint8_t index, AirspeedMetadataTypedef metaData );
void CAN_FIX_SendVerticalSpeed(float vsi, uint8_t index, AttitudeAngleTypedef metadata );
void CAN_FIX_SendVariometerVerticalSpeed(float vsi, uint8_t index, AttitudeAngleTypedef metadata );
void CAN_FIX_SendRadarAltitude(float altitude, uint8_t index, AttitudeAngleTypedef metadata  );
void CAN_FIX_SendYawMeasurement(float yaw, uint8_t index, AttitudeAngleTypedef metadata );
void CAN_FIX_SendNormalAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata  );
void CAN_FIX_SendLateralAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata  );
void CAN_FIX_SendLongitudinalAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata );
void CAN_FIX_SendTrueAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData );
void CAN_FIX_SendCalibratedAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData );
void CAN_FIX_SendMachAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData );
void CAN_FIX_SendAltimeterSetting(float alt, uint8_t index, AttitudeAngleTypedef metaData );
void CAN_FIX_SendPressureAltitude(float presAlt, uint8_t index, AttitudeAngleTypedef metaData );
#endif /* APPLICATION_USER_CORE_CANFIX_H_ */
