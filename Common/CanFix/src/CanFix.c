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

//These are used by CAN_FIX_SendHighPriorityControlSwitch

//High Priority Pilot Control Inputs
#define HighPriorityFlapControlSwitchCanId_0 0x100
#define HighPriorityTrimControlSwitchCanId_0 0x102
#define HighPriorityElectricalControlSwitchCanId_0 0x104
#define HighPriorityLightingControlSwitchCanId_0 0x106
#define HighPriorityFuelPumpControlSwitchCanId_0 0x108
#define HighPriorityFuelValveControlSwitchCanId_0 0x10A
#define HighPriorityAutoPilotControlSwitchCanId_0 0x10C
#define HighPriorityVHFControlSwitchCanId_0 0x10E
#define HighPriorityTransponderControlSwitchCanId_0 0x110
#define HighPriorityStarterMagsControlSwitchCanId_0 0x112
#define HighPriorityLandingGearControlSwitchCanId_0 0x114
#define HighPriorityKeypadKeyControlCanId_0 0x116
#define HighPriorityGenericControlSwitchCanId_0 0x118

// These are set by CAN_FIX_SendHighPriorityControlPositionInt
//High Priority Measured Positions
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
#define HighPriorityEnginePropControlCanId_0 0x126
#define HighPriorityEngineMixtureControlCanId_0 0x12A

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
#define HighPriorityIndicatedAirspeedMeasurementCanId 0x183
#define HighPriorityIndicatedAltitudeMeasurementCanId 0x184
#define HighPriorityHeadingMeasurementCanId 0x185
#define HighPriorityVsiMeasurementCanId 0x186
#define HighPriorityVariometerVerticalSpeedMeasurementCanId 0x187
#define HighPriorityRadarAltitudeMeasurementCanId 0x188
#define HighPriorityYawMeasurementCanId 0x189
#define HighPriorityNormalAccelerationMeasurementCanId 0x18A
#define HighPriorityLateralAccelerationMeasurementCanId 0x18B
#define HighPriorityLongitudinalAccelerationMeasurementCanId 0x18C
#define HighPriorityTrueAirspeedMeasurementCanId 0x18D
#define HighPriorityCalibratedAirspeedMeasurementCanId 0x18E
#define HighPriorityMachAirspeedMeasurementCanId 0x18F
#define HighPriorityAltemeterSettingCanId 0x190
#define HighPriorityPressureAltitudeMeasurementCanId 0x191

#define HighPriorityILSDeviationCanId 0x1C0
#define HighPriorityGlideslopeDeviationCanId 0x1C1
#define HighPriorityPositionLatitudeCanId 0x1C2
#define HighPriorityPositionLongitudeCanId 0x1C3
#define HighPriorityGroundSpeedCanId 0x1C4
#define HighPriorityTrueGroundTrackCanId 0x1C5
#define HighPriorityMagneticGroundTrackCanId 0x1C6


#define HighPriorityADSBStatusCanId 0x1D6
#define HighPriorityADSBIdentificationCanId 0x1D7
#define HighPriorityADSBTypeCanId 0x1D8

#define HighPriorityADSBAirborneVelocityCanId 0x1D9
#define HighPriorityADSBAirborneBearingCanId 0x1DA

#define HighPriorityADSBAirborneRateOfClimbCanId 0x1DB
#define HighPriorityADSBEmergencyPriorityCanId 0x1DC
#define HighPriorityADSBCurrentTrajectoryChangePointCanId 0x1DD
#define HighPriorityADSBNextTrajectoryChangePointCanId 0x1DE
#define HighPriorityADSBOperationCoordMessageCanId 0x1DF
#define HighPriorityADSBOperationalStatusCanId 0x1E0



#define HighPriorityEngineRPMCanId_0 0x200
#define HighPriorityEngineRPMCanId_1 0x201
#define HighPriorityEngineRPMCanId_2 0x202
#define HighPriorityEngineRPMCanId_3 0x203

#define HighPriorityPropRPMCanId_0 0x204
#define HighPriorityPropRPMCanId_1 0x205
#define HighPriorityPropRPMCanId_2 0x206
#define HighPriorityPropRPMCanId_3 0x207

#define HighPriorityTorqueCanId_0 0x208
#define HighPriorityTorqueCanId_1 0x209
#define HighPriorityTorqueCanId_2 0x20A
#define HighPriorityTorqueCanId_3 0x20B

#define HighPriorityTurbineInletTempCanId_0 0x20C
#define HighPriorityTurbineInletTempCanId_1 0x20D
#define HighPriorityTurbineInletTempCanId_2 0x20E
#define HighPriorityTurbineInletTempCanId_3 0x20F

#define HighPriorityTurbineInterTempCanId_0 0x210
#define HighPriorityTurbineInterTempCanId_1 0x211
#define HighPriorityTurbineInterTempCanId_2 0x212
#define HighPriorityTurbineInterTempCanId_3 0x213

#define HighPriorityTurbineOutletTempCanId_0 0x214
#define HighPriorityTurbineOutletTempCanId_1 0x215
#define HighPriorityTurbineOutletTempCanId_2 0x216
#define HighPriorityTurbineOutletTempCanId_3 0x217

#define HighPriorityFuelPressureSwitchCanId_0 0x218

#define HighPriorityOilPressureSwitchCanId_0 0x21C
#define HighPriorityOilTemperatureSwitchCanId_0 0x220
#define HighPriorityCoolantTemperatureSwitchCanId_0 0x224
#define HighPriorityFuelQuantitySwitchCanId_0 0x228
#define HighPriorityOilQuantitySwitchCanId_0 0x22C
#define HighPriorityCoolantQuantitySwitchCanId_0 0x230

//Base CanID for SendEngineSensorReading
#define HighPriorityFuelFlowCanId_0 0x234
//Final value for SendEngineSensorReading
#define HighPriorityMainBatCharge_3 0x267


struct CAN_FIX_Comms
{
	uint16_t StdId;
	uint8_t Count;
	char Description[50];
	char DataType[7];
	uint8_t Precision;
	float LowLimit;
	float HighLimit;
	char UnitOfMeasure[10];
};

const struct CAN_FIX_Comms CAN_FIX_Commands[] = {
		{HighPriorityFlapControlSwitchCanId_0, 2, "Flap Control Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityTrimControlSwitchCanId_0, 2, "Trim Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityElectricalControlSwitchCanId_0, 2, "Electrical Bus Control Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityLightingControlSwitchCanId_0, 2, "Lighting Control Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityFuelPumpControlSwitchCanId_0, 2, "Fuel Pump System Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityFuelValveControlSwitchCanId_0, 2, "Fuel Valve System Switches", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityAutoPilotControlSwitchCanId_0, 2, "AutoPilot Commands", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityVHFControlSwitchCanId_0, 2, "VHF Control Commands", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityTransponderControlSwitchCanId_0, 2, "Transponder Commands", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityStarterMagsControlSwitchCanId_0, 2, "Starter / Magneto Commands", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityLandingGearControlSwitchCanId_0, 2, "Landing Gear Control Position", "BYTE", 0, 0, 0, "NONE"},
		{HighPriorityKeypadKeyControlCanId_0, 2, "Keypad Input", "WORD", 0, 0, 0, "NONE"},
		{HighPriorityGenericControlSwitchCanId_0, 2, "Generic Switches", "BYTE", 0, 0, 0, "NONE"},

		{HighPriorityPitchControlCanId, 1, "Pitch Control Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityRollControlCanId, 1, "Roll Control Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityYawControlCanId, 1, "Yaw Control Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityCollectiveControlCanId, 1, "Collective Control Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityAntiTorqueControlCanId, 1, "Anti-Torque Pedals Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityFlapControlCanId, 1, "Flap Control Position", "INT", 2, -100.0, 100.0, "%"},
		{HighPriorityLeftBrakeControlCanId, 1, "Left Brake Control Position", "UINT", 2, 0.0, 100.0, "%"},
		{HighPriorityRightBrakeControlCanId, 1, "Right Brake Control Position", "UINT", 2, 0.0, 100.0, "%"},
		{HighPriorityEngineThrottleControlCanId_0, 4, "Engine Throttle Control Position", "UINT", 2, 0.0, 100.0, "%"},
		{HighPriorityEnginePropControlCanId_0, 4, "Engine Prop Control Position", "UINT", 2, 0.0, 100.0, "%"},
		{HighPriorityEngineMixtureControlCanId_0, 4, "Engine Mixture Control Position", "UINT", 2, 0.0, 100.0, "%"},
		{HighPriorityElevatorMeasurementCanId, 1, "Elevator Position", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityAileronMeasurementCanId, 1, "Aileron Position", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityRudderMeasurementCanId, 1, "Rudder Position", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityCollectiveMeasurementCanId, 1, "Collective Position", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityTailRotorMeasurementCanId, 1, "Tail Rotor Angle", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityFlapMeasurementCanId, 1, "Flap Position", "INT", 2, -90.0, 90.0, "°"},
		{HighPriorityLandingGearPositionSwCanId, 1, "Landing Gear Position Switches", "BYTE", 0, 0.0, 0, "NONE"},
		{HighPriorityPitchAngleMeasurementCanId, 1, "Pitch Angle", "INT", 2, -180.0, 180.0, "°"},
		{HighPriorityRollAngleMeasurementCanId, 1, "Roll Angle", "INT", 2, -180.0, 180.0, "°"},
		{HighPriorityAngleOfAttackMeasurementCanId, 1, "Angle of Attack", "INT", 2, -180.0, 180.0, "°"},
		{HighPriorityIndicatedAirspeedMeasurementCanId, 1, "Indicated Airspeed", "UINT", 1, 0, 999.9, "knots"},
		{HighPriorityIndicatedAltitudeMeasurementCanId, 1, "Indicated Altitude", "DINT", 0, -1000.0, 60000.0, "ft"},
		{HighPriorityHeadingMeasurementCanId, 1, "Heading", "UINT", 1, 0.0, 359.9, "°"},
		{HighPriorityVsiMeasurementCanId, 1, "Vertical Speed", "INT", 0, -30000.0, 30000.0, "ft/min"},
		{HighPriorityVariometerVerticalSpeedMeasurementCanId, 1, "TE Variometer Vertical Speed", "INT", 2, -300.0, 300.0, "knots"},
		{HighPriorityRadarAltitudeMeasurementCanId, 1, "Radar Altitude", "UINT", 0, 0.0, 60000.0, "ft"},
		{HighPriorityYawMeasurementCanId, 1, "Yaw Angle", "INT", 2, -180.0, 180.0, "°"},
		{HighPriorityNormalAccelerationMeasurementCanId, 1, "Normal Acceleration", "INT", 3, -30.0, 30.0, "g"},
		{HighPriorityLateralAccelerationMeasurementCanId, 1, "Lateral Acceleration", "INT", 3, -30.0, 30.0, "g"},
		{HighPriorityLongitudinalAccelerationMeasurementCanId, 1, "Longitudinal Acceleration", "INT", 3, -30.0, 30.0, "g"},
		{HighPriorityTrueAirspeedMeasurementCanId, 1, "True Airspeed", "UINT", 1, 0.0, 2000.0, "knots"},
		{HighPriorityCalibratedAirspeedMeasurementCanId, 1, "Calibrated Airspeed", "UINT", 1, 0.0, 2000.0, "knots"},
		{HighPriorityMachAirspeedMeasurementCanId, 1, "Mach Number", "UINT", 2, 0.0, 100.0, "Mach"},
		{HighPriorityAltemeterSettingCanId, 1, "Altimeter Setting", "UINT", 1, 0.0, 35.0, "inHg"},
		{HighPriorityPressureAltitudeMeasurementCanId, 1, "Pressure Altitude", "DINT", 1, -1000.0, 60000.0, "ft"},
		{0x192, 1, "Mach Number", "UINT", 2, 0.0, 100.0, "Mach"},
//#define HighPriorityILSDeviationCanId 0x1C0
//#define HighPriorityGlideslopeDeviationCanId 0x1C1
//#define HighPriorityPositionLatitudeCanId 0x1C2
//#define HighPriorityPositionLongitudeCanId 0x1C3
//#define HighPriorityGroundSpeedCanId 0x1C4
//#define HighPriorityTrueGroundTrackCanId 0x1C5
//#define HighPriorityMagneticGroundTrackCanId 0x1C6
		{HighPriorityILSDeviationCanId, 1, "ILS Deviation", "UINT", 1, 0.0, 359.9, "°"},
		{HighPriorityGlideslopeDeviationCanId, 1, "Glideslope Deviation", "UINT", 2, 0.0, 45, "°"},
		{HighPriorityPositionLatitudeCanId, 1, "Aircraft Position Latitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1C3, 1, "Aircraft Position Longitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1C4, 1, "Groundspeed", "UINT", 1, 0.0, 2000.0, "knots"},
		{0x1C5, 1, "True Ground Track", "UINT", 1, 0.0, 359.9, "°"},
		{0x1C6, 1, "Magnetic Ground Track", "UINT", 1, 0.0, 359.9, "°"},
		{0x1C7, 1, "Cross Track Error", "INT", 2, -1e99, 1e99, "nm"},
		{0x1C8, 1, "Selected Course", "UINT", 1, 0.0, 359.9, "°"},
		{0x1C9, 1, "Selected VOR Radial", "UINT", 1, 0.0, 359.9, "°"},
		{0x1CA, 1, "Selected Glidepath Angle", "UINT", 1, 0.0, 90, "°"},
		{0x1CB, 1, "Selected Vertical Speed", "INT", 0, -30000.0, 330000.0, "ft/min"},
		{0x1CC, 1, "Selected Altitude", "DINT", 0, -1000.0, 60000.0, "ft"},
		{0x1CD, 1, "RAIM Status", "USHORT", 0, 0.0, 100, "NONE"},
		{0x1CE, 1, "RAIM Horizontal Error", "UINT", 0, 0, 1e99, "ft"},
		{0x1CF, 1, "RAIM Vertical Error", "UINT", 0, 0, 1e99, "ft"},
		{0x1D0, 1, "ADS-B ES Airborne Position Latitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1D1, 1, "ADS-B ES Airborne Position Longitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1D2, 1, "ADS-B ES Airborne Position Altitude", "DINT", 0, -1000, 60000, "ft"},
		{0x1D3, 1, "ADS-B ES Surface Position Latitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1D4, 1, "ADS-B ES Surface Position Longitude", "FLOAT", 0, -1e99, 1e99, "°"},
		{0x1D5, 1, "ADS-B ES Surface Position Altitude", "DINT", 0, -1000, 60000, "ft"},
		{0x1D9, 1, "ADS-B ES Airborne Velocity", "UINT", 1, 0, 2000, "knots"},
		{0x1DA, 1, "ADS-B ES Airborne Bearing", "UINT", 1, 0.0, 359.9, "°"},
		{0x1DB, 1, "ADS-B ES Airborne Rate of Climb", "INT", 0, -30000.0, 330000.0, "ft/min"},

		{0x200, 4, "Engine RPM", "UINT", 0, 0, 1e99, "RPM"},
		{0x204, 4, "Prop/Rotor RPM", "UINT", 0, 0, 1e99, "RPM"},
		{0x208, 4, "Torque", "INT", 0, -1e99, 1e99, ""},
		{0x20C, 4, "Turbine Inlet Temperature", "UINT", 1, 0, 1e99, "°C"},
		{0x210, 4, "Inter-turbine Temperature", "UINT", 1, 0, 1e99, "°C"},
		{0x214, 4, "Turbine Outlet Temperature", "UINT", 1, 0, 1e99, "°C"},
		{0x218, 4, "Fuel Pressure Switch", "SHORT", 1, -10, 10, ""},
		{0x21C, 4, "Oil Pressure Switch", "SHORT", 1, -10, 10, ""},
		{0x220, 4, "Oil Temp Switch", "SHORT", 1, -10, 10, ""},
		{0x224, 4, "Coolant Temp Switch", "SHORT", 1, -10, 10, ""},
		{0x228, 4, "Fuel Quantity Switch", "SHORT", 1, -10, 10, ""},
		{0x22C, 4, "Oil Quantity Switch", "SHORT", 1, -10, 10, ""},
		{0x230, 4, "Coolant Quantity Switch", "SHORT", 1, -10, 10, ""},
		{0x234, 4, "Fuel Flow", "UINT", 2, -1000, 1000, "gal/hr"},
		{0x238, 4, "Fuel Pressure", "UINT", 2, -1000, 1000, "psi"},
		{0x23C, 4, "Manifold Pressure", "UINT", 2, -1000, 1000, "inHg"},
		{0x240, 4, "Oil Pressure", "UINT", 2, -1000, 1000, "psi"},
		{0x244, 4, "Oil Temp", "UINT", 1, -1000, 1000, "°C"},
		{0x248, 4, "Coolant Temp", "UINT", 1, -1000, 1000, "°C"},
		{0x24C, 4, "Fuel Quantity", "UINT", 2, -1000, 1000, "gal"},
		{0x250, 4, "Fuel Pump Pressure", "UINT", 2, -1000, 1000, "psi"},
		{0x254, 4, "Oil Quantity", "UINT", 2, -1000, 1000, "gal"},
		{0x258, 4, "Coolant Quantity", "UINT", 2, -1000, 1000, "gal"},
		{0x262, 2, "Main Battery Current", "INT", 0, -1000, 1000, "A"},
		{0x264, 2, "Main Battery Temp", "UINT", 1, 0, 1000, "°C"},
		{0x266, 2, "Main Battery Charge", "UINT", 1, 0, 100, "%"},

		{0x300, 1, "Speedbrake Control Position", "UINT", 2, 0, 100, "%"},
		{0x301, 1, "Cowl Flaps Control Position", "UINT", 2, 0, 100, "%"},
		{0x302, 1, "Pitch Trim Control Position", "INT", 2, -100, 100, "%"},
		{0x303, 1, "Roll Trim Control Position", "INT", 2, -100, 100, "%"},
		{0x304, 1, "Yaw Trim Control Position", "INT", 2, -100, 100, "%"},
		{0x305, 1, "Collective Trim Control Position", "INT", 2, -100, 100, "%"},
		{0x306, 1, "AntiTorque Trim Control Position", "INT", 2, -100, 100, "%"},

		{0x380, 1, "Speedbrake Position", "INT", 2, -90, 90, "°"},
		{0x381, 1, "Cowl Flaps Position", "UINT", 2, 0, 100, "%"},
		{0x382, 1, "Pitch Trim Position", "INT", 2, -90, 90, "°"},
		{0x383, 1, "Roll Trim Position", "INT", 2, -90, 90, "°"},
		{0x384, 1, "Yaw Trim Position", "INT", 2, -90, 90, "°"},

		{0x385, 1, "Pitch Trim Motor Speed", "INT", 2, -100, 100, "%"},
		{0x386, 1, "Roll Trim Motor Speed", "INT", 2, -100, 100, "%"},
		{0x387, 1, "Yaw Trim Motor Speed", "INT", 2, -100, 100, "%"},
		{0x388, 1, "Collective Trim Motor Speed", "INT", 2, -100, 100, "%"},
		{0x389, 1, "AntiTorque Trim Motor Speed", "INT", 2, -100, 100, "%"},

		{0x38A, 1, "Light Status", "BYTE", 0, 0, 0, "NONE"},
		{0x38B, 1, "Fuel Pump Status", "BYTE", 0, 0, 0, "NONE"},
		{0x38C, 1, "Fuel Valve Status", "BYTE", 0, 0, 0, "NONE"},

		{0x400, 1, "Pitch Rate", "INT", 1, -3000, 3000, "°"},
		{0x401, 1, "Roll Rate", "INT", 1, -3000, 3000, "°"},
		{0x402, 1, "Yaw Rate", "INT", 1, -3000, 3000, "°"},
		{0x403, 1, "Turn Rate", "INT", 1, -3000, 3000, "°"},
		{0x404, 1, "Static Pressure", "INT", 1, -3e99, 3e99, "inHg"},
		{0x405, 1, "Pitot Pressure", "INT", 1, -3e99, 3e99, "inHg"},
		{0x406, 1, "Total Air Temperature", "INT", 2, -300, 300, "°C"},
		{0x407, 1, "Static Air Temperature", "INT", 2, -300, 300, "°C"},
		{0x408, 1, "Density Altitude", "DINT", 0, -1000, 60000, "ft"},
		{0x409, 1, "True Altitude", "DINT", 0, -1000, 60000, "ft"},

		{0x40A, 1, "Wind Speed", "UINT", 1, 0, 2000, "knots"},
		{0x40B, 1, "Wind Direction", "UINT", 2, 0, 360, "°"},
};

const struct CAN_FIX_Comms CAN_FIX_NullCommand = {0xFFFF, 0, "Bad", "Bad", 0,0,0,"Bad"};

struct CAN_FIX_Comms FindCanFixComms(uint16_t canId)
{
	int length = sizeof(CAN_FIX_Commands) / sizeof(CAN_FIX_Commands[0]);
	int i;
	for(i = 0; i < length; i++ )
	{
		if(CAN_FIX_Commands[i].StdId == canId)
			break;
	}
	if(i >= length)
		return CAN_FIX_NullCommand;
	return CAN_FIX_Commands[i];
}
void CAN_FIX_SendHighPriortyNodeAlarm(uint16_t alarm, uint8_t* alarmData, uint8_t alarmDataLength)
{
	if(alarmDataLength > 6)
		return;
	CAN_FIX_TxHeader.DLC = 2 + alarmDataLength;
	CAN_FIX_TxHeader.StdId = NodeId;
	ConvertUInt16ToBytes(alarm, CanFixTxData);
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

void CAN_FIX_SendHighPriorityKeyPress( PilotLocationTypedef pilot, uint8_t index, uint8_t functionCode, uint8_t key, uint8_t altFunction)
{
	uint16_t canId = HighPriorityKeypadKeyControlCanId_0;
	struct CAN_FIX_Comms comms = FindCanFixComms(canId);
	//Verify comms did not return null: StdId = 0xFFFF
	if(comms.StdId == 0xFFFF)
		return;
	//Verify the element argument is not greater than the possible
	//elements
	if(pilot >= comms.Count)
		return;
	canId += pilot;

	uint8_t data[2];
	data[0] = key;
	data[1] = altFunction;
	CAN_FIX_SendDataMessage(canId, index, functionCode, data, 2);
}

void CAN_FIX_SendMeasurement(uint16_t canId, uint8_t index, uint8_t functionCode, float floatData, uint8_t decimalPlaces)
{
	uint8_t data[2];
	int exp = 10^decimalPlaces;
	int16_t updatedPosition = (int16_t)(floatData * exp);
	ConvertInt16ToBytes(updatedPosition, data);
	CAN_FIX_SendDataMessage(canId, index, functionCode, data, 2);
}

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

//NOte:  for a specified gear neither down nor up, both the respective flags
// are to be set to zero.
void CAN_FIX_SendLandingGearPosition(uint8_t flags, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(flags < -180 || flags > 180)
		return;
	CAN_FIX_SendDataMessage(HighPriorityLandingGearPositionSwCanId, index, metaData, &flags, 1);
}

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

void CAN_FIX_SendAngleOfAttack(float aoa, uint8_t index, AngleOfAttackTypedef metaData )
{
	if(aoa < -180 || aoa > 180)
		return;
	CAN_FIX_SendMeasurement(HighPriorityAngleOfAttackMeasurementCanId, index, metaData, aoa, 2);
}

void CAN_FIX_SendIndicatedAirspeed(float airspeed, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(airspeed < 0 || airspeed > 999.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityIndicatedAirspeedMeasurementCanId, index, metaData, airspeed, 1);
}

void CAN_FIX_SendIndicatedAltitude(float altitude, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(altitude < -1000 || altitude > 60000)
		return;

	uint8_t data[4];
	ConvertInt32ToBytes((int32_t)altitude,data);
	CAN_FIX_SendDataMessage(HighPriorityIndicatedAltitudeMeasurementCanId, index, metaData, data, sizeof(int32_t));
}

void CAN_FIX_SendIndicatedHeading(float heading, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(heading < 0 || heading > 359.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityHeadingMeasurementCanId, index, metaData, heading, 1);
}

void CAN_FIX_SendVerticalSpeed(float vsi, uint8_t index, AttitudeAngleTypedef metadata )
{
	if(vsi < -30000 || vsi > 30000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityVsiMeasurementCanId, index, metadata, vsi, 0);
}

void CAN_FIX_SendVariometerVerticalSpeed(float vsi, uint8_t index, AttitudeAngleTypedef metadata )
{
	if(vsi < -300 || vsi > 300)
		return;
	CAN_FIX_SendMeasurement(HighPriorityVariometerVerticalSpeedMeasurementCanId, index, metadata, vsi, 2);
}

void CAN_FIX_SendRadarAltitude(float altitude, uint8_t index, AttitudeAngleTypedef metadata  )
{
	if(altitude < 0 || altitude > 60000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityRadarAltitudeMeasurementCanId, index, metadata, altitude, 0);
}

void CAN_FIX_SendYawMeasurement(float yaw, uint8_t index, AttitudeAngleTypedef metadata )
{
	if(yaw < -180 || yaw > 180)
		return;
	CAN_FIX_SendMeasurement(HighPriorityYawMeasurementCanId, index, metadata, yaw, 2);
}

void CAN_FIX_SendNormalAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata  )
{
	if(acceleration < -30 || acceleration > 30)
		return;
	CAN_FIX_SendMeasurement(HighPriorityNormalAccelerationMeasurementCanId, index, metadata, acceleration, 3);
}

void CAN_FIX_SendLateralAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata  )
{
	if(acceleration < -30 || acceleration > 30)
		return;
	CAN_FIX_SendMeasurement(HighPriorityLateralAccelerationMeasurementCanId, index, metadata, acceleration, 3);
}

void CAN_FIX_SendLongitudinalAcceleration(float acceleration, uint8_t index, AttitudeAngleTypedef metadata  )
{
	if(acceleration < -30 || acceleration > 30)
		return;
	CAN_FIX_SendMeasurement(HighPriorityLongitudinalAccelerationMeasurementCanId, index, metadata, acceleration, 3);
}

void CAN_FIX_SendTrueAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(airspeed < 0 || airspeed > 2000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityTrueAirspeedMeasurementCanId, index, metaData, airspeed, 1);
}

void CAN_FIX_SendCalibratedAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(airspeed < 0 || airspeed >2000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityCalibratedAirspeedMeasurementCanId, index, metaData, airspeed, 1);
}

void CAN_FIX_SendMachAirspeed(float airspeed, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(airspeed < 0 || airspeed >100)
		return;
	CAN_FIX_SendMeasurement(HighPriorityMachAirspeedMeasurementCanId, index, metaData, airspeed, 2);
}

void CAN_FIX_SendAltimeterSetting(float alt, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(alt < 0 || alt >35)
		return;
	CAN_FIX_SendMeasurement(HighPriorityAltemeterSettingCanId, index, metaData, alt, 3);
}

void CAN_FIX_SendPressureAltitude(float presAlt, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(presAlt < 0 || presAlt >60000)
		return;

	uint8_t data[4];
	ConvertInt32ToBytes((int32_t)presAlt,data);
	CAN_FIX_SendDataMessage(HighPriorityPressureAltitudeMeasurementCanId, index, metaData, data, sizeof(int32_t));
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void CAN_FIX_SendILSDeviation(float deviation, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(deviation < 0 || deviation >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityILSDeviationCanId, index, metaData, deviation, 1);

}



void CAN_FIX_SendGlideslopeDeviation(float deviation, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(deviation < 0 || deviation >45)
		return;
	CAN_FIX_SendMeasurement(HighPriorityGlideslopeDeviationCanId, index, metaData, deviation, 2);
}


void CAN_FIX_SendPositionLatitude(float deviation, uint8_t index, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(deviation, data);
	CAN_FIX_SendDataMessage(HighPriorityPositionLatitudeCanId, index, metaData, data, 4);
}


void CAN_FIX_SendPositionLongitude(float deviation, uint8_t index, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(deviation, data);
	CAN_FIX_SendDataMessage(HighPriorityPositionLongitudeCanId, index, metaData, data, 4);
}



void CAN_FIX_SendGroundSpeed(float groundSpeed, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(groundSpeed < 0 || groundSpeed >2000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityGroundSpeedCanId, index, metaData, groundSpeed, 1);
}



void CAN_FIX_SendTrueGroundTrack(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityTrueGroundTrackCanId, index, metaData, track, 1);
}



void CAN_FIX_SendMagneticGroundTrack(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityMagneticGroundTrackCanId, index, metaData, track, 1);
}

#define HighPriorityGroundTrackErrorCanId 0x1C7

void CAN_FIX_SendCrossTrackError(float error, uint8_t index, AttitudeAngleTypedef metaData )
{

	CAN_FIX_SendMeasurement(HighPriorityGroundTrackErrorCanId, index, metaData, error, 2);
}

#define HighPrioritySelectedCourseCanId 0x1C8

void CAN_FIX_SendSelectedCourse(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPrioritySelectedCourseCanId, index, metaData, track, 1);
}

#define HighPrioritySelectedVORRadialCanId 0x1C9

void CAN_FIX_SendSelectedVORRadial(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPrioritySelectedVORRadialCanId, index, metaData, track, 1);
}

#define HighPrioritySelectedGlidePathAngleCanId 0x1CA

void CAN_FIX_SendSelectedGlidePathAngle(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >90)
		return;
	CAN_FIX_SendMeasurement(HighPrioritySelectedGlidePathAngleCanId, index, metaData, track, 1);
}

#define HighPrioritySelectedVerticalSpeedCanId 0x1CB

void CAN_FIX_SendSelectedVerticalSpeed(float track, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(track < -30000 || track >30000)
		return;
	CAN_FIX_SendMeasurement(HighPrioritySelectedVerticalSpeedCanId, index, metaData, track, 0);
}

#define HighPrioritySelectedAltitudeCanId 0x1CC

void CAN_FIX_SendSelectedAltitude(float altitude, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(altitude < -1000 || altitude >60000)
		return;

	uint8_t data[4];
	ConvertInt32ToBytes((int32_t)altitude, data);
	CAN_FIX_SendDataMessage(HighPrioritySelectedAltitudeCanId, index, metaData, data, 4);
}

#define HighPriorityRAIMStatusCanId 0x1CD

void CAN_FIX_SendRAIMStatus(uint16_t status, uint8_t index, AttitudeAngleTypedef metaData )
{
	uint8_t data[2];
	ConvertUInt16ToBytes(status, data);
	CAN_FIX_SendDataMessage(HighPriorityRAIMStatusCanId, index, metaData, data, 4);
}

#define HighPriorityRAIMHorizontalErrorCanId 0x1CE

void CAN_FIX_SendRAIMHorizontalError(uint16_t status, uint8_t index, AttitudeAngleTypedef metaData )
{
	uint8_t data[2];
	ConvertUInt16ToBytes(status, data);
	CAN_FIX_SendDataMessage(HighPriorityRAIMHorizontalErrorCanId, index, metaData, data, 4);
}

#define HighPriorityRAIMVerticalErrorCanId 0x1CF

void CAN_FIX_SendRAIMVerticalError(uint16_t status, uint8_t index, AttitudeAngleTypedef metaData )
{
	uint8_t data[2];
	ConvertUInt16ToBytes(status, data);
	CAN_FIX_SendDataMessage(HighPriorityRAIMVerticalErrorCanId, index, metaData, data, 4);
}

#define HighPriorityADSBAirbornePositionLatitudeCanId 0x1D0

void CAN_FIX_SendADSBAirbornePositionLatitude(float position, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(position, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBAirbornePositionLatitudeCanId, aircraft, metaData, data, 4);
}
#define HighPriorityADSBAirbornePositionLongitudeCanId 0x1D1

void CAN_FIX_SendADSBAirbornePositionLongitude(float position, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(position, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBAirbornePositionLongitudeCanId, aircraft, metaData, data, 4);
}

#define HighPriorityADSBAirbornePositionAltitudeCanId 0x1D2

void CAN_FIX_SendADSBAirbornePositionAltitude(float altitude, uint8_t index, AttitudeAngleTypedef metaData )
{
	if(altitude < -1000 || altitude >60000)
		return;

	uint8_t data[4];
	ConvertInt32ToBytes((int32_t)altitude, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBAirbornePositionAltitudeCanId, index, metaData, data, 4);
}

#define HighPriorityADSBSurfacePositionLatitudeCanId 0x1D3

void CAN_FIX_SendADSBSurfacePositionLatitude(float position, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(position, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBSurfacePositionLatitudeCanId, aircraft, metaData, data, 4);
}
#define HighPriorityADSBSurfacePositionLongitudeCanId 0x1D4

void CAN_FIX_SendADSBSurfacePositionLongitude(float position, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	uint8_t data[4];
	ConvertFloatToBytes(position, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBSurfacePositionLongitudeCanId, aircraft, metaData, data, 4);
}

#define HighPriorityADSBSurfacePositionAltitudeCanId 0x1D5

void CAN_FIX_SendADSBSurfacePositionAltitude(float altitude, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	if(altitude < -1000 || altitude >60000)
		return;

	uint8_t data[4];
	ConvertInt32ToBytes((int32_t)altitude, data);
	CAN_FIX_SendDataMessage(HighPriorityADSBSurfacePositionAltitudeCanId, aircraft, metaData, data, 4);
}



void CAN_FIX_SendADSBAirborneVelocity(float velocity, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	if(velocity < 0 || velocity >2000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityADSBAirborneVelocityCanId, aircraft, metaData, velocity, 1);
}



void CAN_FIX_SendADSBAirborneBearing(float track, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	if(track < 0 || track >359.9)
		return;
	CAN_FIX_SendMeasurement(HighPriorityADSBAirborneBearingCanId, aircraft, metaData, track, 1);
}



void CAN_FIX_SendADSBAirborneRateOfClimb(float rate, uint8_t aircraft, AttitudeAngleTypedef metaData )
{
	if(rate < -30000 || rate >30000)
		return;
	CAN_FIX_SendMeasurement(HighPriorityADSBAirborneRateOfClimbCanId, aircraft, metaData, rate, 1);
}



typedef enum
{
	EngineRpm_0,
	EngineRpm_1,
	EngineRpm_2,
	EngineRpm_3,
	PropRpm_0,
	PropRpm_1,
	PropRpm_2,
	PropRpm_3
} RpmTypedef;

typedef enum{
	Min = 0b0001,
	Max = 0b0010,
	LowWarn = 0b0100,
	LowAlarm = 0b0101,
	HighWarn = 0b0110,
	HIghAlarm = 0b0111,
}RpmMetadataTypedef;

void CAN_FIX_SendHighPriorityRPM (RpmTypedef device, float rpm, uint8_t index, RpmMetadataTypedef metaData )
{
	uint16_t canId;
	switch(device)
	{
	case EngineRpm_0:
		canId = HighPriorityEngineRPMCanId_0;
		break;
	case EngineRpm_1:
		canId = HighPriorityEngineRPMCanId_1;
		break;
	case EngineRpm_2:
		canId = HighPriorityEngineRPMCanId_2;
		break;
	case EngineRpm_3:
		canId = HighPriorityEngineRPMCanId_3;
		break;
	case PropRpm_0:
		canId = HighPriorityPropRPMCanId_0;
		break;
	case PropRpm_1:
		canId = HighPriorityPropRPMCanId_1;
		break;
	case PropRpm_2:
		canId = HighPriorityPropRPMCanId_2;
		break;
	case PropRpm_3:
		canId = HighPriorityPropRPMCanId_3;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, metaData, rpm, 2);
}



typedef enum
{
	Torque_0,
	Torque_1,
	Torque_2,
	Torque_3
} TorqueTypedef;

void CAN_FIX_SendHighPriorityTorque (TorqueTypedef device, float torque, uint8_t index, RpmMetadataTypedef metaData )
{

	uint16_t canId;
	switch(device)
	{
	case Torque_0:
		canId = HighPriorityTorqueCanId_0;
		break;
	case Torque_1:
		canId = HighPriorityTorqueCanId_1;
		break;
	case Torque_2:
		canId = HighPriorityTorqueCanId_2;
		break;
	case Torque_3:
		canId = HighPriorityTorqueCanId_3;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, metaData, torque, 0);
}



typedef enum
{
	InletTemp_0,
	InletTemp_1,
	InletTemp_2,
	InletTemp_3,
	InterTemp_0,
	InterTemp_1,
	InterTemp_2,
	InterTemp_3,
	OutletTemp_0,
	OutletTemp_1,
	OutletTemp_2,
	OutletTemp_3
} TurbineTempTypedef;


void CAN_FIX_SendHighPriorityTurbineTemp (TurbineTempTypedef device, float temp, uint8_t index, RpmMetadataTypedef metaData )
{
	uint16_t canId;
	switch(device)
	{
	case InletTemp_0:
		canId = HighPriorityTurbineInletTempCanId_0;
		break;
	case InletTemp_1:
		canId = HighPriorityTurbineInletTempCanId_1;
		break;
	case InletTemp_2:
		canId = HighPriorityTurbineInletTempCanId_2;
		break;
	case InletTemp_3:
		canId = HighPriorityTurbineInletTempCanId_3;
		break;
	case InterTemp_0:
		canId = HighPriorityTurbineInterTempCanId_0;
		break;
	case InterTemp_1:
		canId = HighPriorityTurbineInterTempCanId_1;
		break;
	case InterTemp_2:
		canId = HighPriorityTurbineInterTempCanId_2;
		break;
	case InterTemp_3:
		canId = HighPriorityTurbineInterTempCanId_3;
		break;
	case OutletTemp_0:
		canId = HighPriorityTurbineOutletTempCanId_0;
		break;
	case OutletTemp_1:
		canId = HighPriorityTurbineOutletTempCanId_1;
		break;
	case OutletTemp_2:
		canId = HighPriorityTurbineOutletTempCanId_2;
		break;
	case OutletTemp_3:
		canId = HighPriorityTurbineOutletTempCanId_3;
		break;
	default:
		return;
	}
	CAN_FIX_SendMeasurement(canId, index, metaData, temp, 2);
}




void CAN_FIX_SendHighPriorityPressureSwitch (EngineFluidSwitchTypedef sensor,uint8_t subset, SwitchValueTypedef value, uint8_t index, uint8_t metaData )
{
	if(sensor < 0 || sensor >= SystemMaxValue)
		return;
	if(subset < 0 || subset > 3)
		return;
	uint16_t canId = sensor * 4 + subset +  HighPriorityFuelPressureSwitchCanId_0;

	uint8_t data;
	memcpy(&data,&value,sizeof(int8_t));
	CAN_FIX_SendDataMessage(canId, index, metaData, &data, sizeof(int8_t));
}



uint8_t CAN_FIX_sensorPrecision[15] = {2,2,2,2,1,1,2,2,2,2,0,1,0,1,1};
typedef enum
{
	FuelFlow,
	FuelPressure, //4
	ManifoldPressure, //8
	OilPressure, //12
	OilTemp, //16
	CoolantTemp, //20
	FuelQuanity, //24
	FuelPumpPressure, //28
	OilQuantity, //32
	CoolantQuantity, //36
	ElectPropMotorCurrent, //40
	MainPropBusCurrent, //44
	MainBatCurrent, //48
	MainBatTemp, //52
	MainBatCharge, //56
	SystemSensorMaxValue //60

} SystemSensorTypedef;

//
//Subset is a number between 0 and 3 corresponding to the number of systems on the aircraft
void CAN_FIX_SendHighPrioritySensorReading (SystemSensorTypedef sensor, uint8_t subset, float value, uint8_t index, RpmMetadataTypedef metaData )
{
	if(sensor < 0 || sensor >= SystemSensorMaxValue)
		return;
	if(subset < 0 || subset > 3)
		return;
	uint16_t canId = sensor * 4 + subset + HighPriorityFuelFlowCanId_0;
	uint8_t precision = CAN_FIX_sensorPrecision[sensor];

	CAN_FIX_SendMeasurement(canId, index, metaData, value, precision);
}

#define HighPriorityCabinPressureCanId 0x280

void CAN_FIX_SendCabinPressure(float pressure, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(pressure < 0 || pressure > 35)
		return;

	CAN_FIX_SendMeasurement(HighPriorityCabinPressureCanId, index, metaData, pressure, 3);
}

#define HighPriorityCabinAltitudeCanId 0x281

void CAN_FIX_SendCabinAltitude(float altitude, uint8_t index, AirspeedMetadataTypedef metaData )
{
	if(altitude < -1000 || altitude > 30000)
		return;

	CAN_FIX_SendMeasurement(HighPriorityCabinAltitudeCanId, index, metaData, altitude, 0);
}

#define NormalPrioritySpeedBrakeControlCanId 0x300

typedef enum
{
	SpeedBrakeControl,
	CowlFlapsControl,
	PitchTrimControl,
	RollTrimControl,
	YawTrimControl,
	PilotControlMaxValue

} PilotControlInputTypedef;

//
void CAN_FIX_SendNormalPilotControlInput (PilotControlInputTypedef sensor, float value, uint8_t index, RpmMetadataTypedef metaData )
{
	if(sensor < 0 || sensor >= PilotControlMaxValue)
		return;
	if(value < -100 || value > 100)
		return;
	uint16_t canId = sensor + NormalPrioritySpeedBrakeControlCanId;

	CAN_FIX_SendMeasurement(canId, index, metaData, value, 2);
}

#define NormalPrioritySpeedBrakePositionCanId 0x380
typedef enum
{
	SpeedBrakePosition,
	CowlFlapsPosition,
	PitchTrimPosition,
	RollTrimPosition,
	YawTrimPosition,
	PitchTrimMotorSpeed,
	RollTrimMotorSpeed,
	YawTrimMotorSpeed,
	CollectiveTrimMotorSpeed,
	AntiTorqueTrimMotorSpeed,
	MesuredPositionsMaxValue

} NormalPositionMeasurementsTypedef;

//
//Subset is a number between 0 and 3 corresponding to the number of systems on the aircraft
void CAN_FIX_SendNormalMeasuredPositions(NormalPositionMeasurementsTypedef sensor, float value, uint8_t index, RpmMetadataTypedef metaData )
{
	if(sensor < 0 || sensor >= MesuredPositionsMaxValue)
		return;
	if(value < -100 || value > 100)
		return;
	uint16_t canId = sensor + NormalPrioritySpeedBrakePositionCanId;

	CAN_FIX_SendMeasurement(canId, index, metaData, value, 2);
}
#define NormalPriorityLightStatusCanId 0x38A
typedef enum
{
	LightStatus,
	FuelPumpStatus,
	FuelValveStatus,
	NormalStatusMaxValue
} NormalStatusTypedef;

void CAN_FIX_SendNormalStatus (NormalStatusTypedef sensor, uint8_t value, uint8_t index, uint8_t metaData )
{
	if(sensor < 0 || sensor >= NormalStatusMaxValue)
		return;

	uint16_t canId = sensor +  NormalPriorityLightStatusCanId;

	CAN_FIX_SendDataMessage(canId, index, metaData, &value, sizeof(uint8_t));
}






void CAN_FIX_SendControlSwitch(ControlSwitchTypedef control, PilotLocationTypedef location,  uint8_t index, uint8_t functionCode, uint8_t button)
{
	uint16_t canId;
	switch(control)
	{
	case FlapControlSwitches: //100
		canId = HighPriorityFlapControlSwitchCanId_0;
		break;
	case TrimControlSwitches: //102
		canId = HighPriorityTrimControlSwitchCanId_0;
		break;
	case ElectricalBusControlSwitches: //104
		canId = HighPriorityElectricalControlSwitchCanId_0;
	    break;
	case LightingControlSwitches:  //106
		canId = HighPriorityLightingControlSwitchCanId_0;
		break;
	case FuelPumpControlSwitches: //108
		canId = HighPriorityFuelPumpControlSwitchCanId_0;
		break;
	case FuelValveControlSwitches: //10A
		canId = HighPriorityFuelValveControlSwitchCanId_0;
		break;
	case AutoPilotControlSwitches:     //10C
		canId = HighPriorityAutoPilotControlSwitchCanId_0;
		break;
	case VhfControlSwitches:    //10E
		canId = HighPriorityVHFControlSwitchCanId_0;
		break;
	case TransponderControlSwitches:   //110
		canId = HighPriorityTransponderControlSwitchCanId_0;
		break;
	case StarterMagnetoControlSwitches:  //112
		canId = HighPriorityStarterMagsControlSwitchCanId_0;
		break;
	case LandingGearControlSwitches:    //114
		canId = HighPriorityLandingGearControlSwitchCanId_0;
		break;
	case GenericControlSwitches:       //118
		canId = HighPriorityGenericControlSwitchCanId_0;
		break;
	}


	CAN_FIX_SendDataMessage(canId, index, functionCode, &button, 1);
}




void CAN_FIX_SendIndicatorSwitch(IndicatorSwitchTypedef indicator, PilotLocationTypedef location,  uint8_t index, uint8_t functionCode, uint8_t button)
{
	uint16_t canId;
	switch(indicator)
	{
	case LandingGearPositionIndicatorSwitch:
		canId = HighPriorityLandingGearPositionSwCanId;
		break;
	case FuelPressureIndicatorSwitch: //218
		canId = HighPriorityFuelPressureSwitchCanId_0;
		break;
	case OilPressureIndicatorSwitch: //21C
		canId = HighPriorityOilPressureSwitchCanId_0;
		break;
	case OilTemperatureIndicatorSwitch: //220
		canId = HighPriorityOilTemperatureSwitchCanId_0;
		break;
	case CoolantTemperatureIndicatorSwitch: //224
		canId = HighPriorityCoolantTemperatureSwitchCanId_0;
		break;
	case FuelQuantityIndicatorSwitch: //228
		canId = HighPriorityFuelQuantitySwitchCanId_0;
		break;
	case OilQuantityIndicatorSwitch: //22C
		canId = HighPriorityOilQuantitySwitchCanId_0;
		break;
	case CoolantQuantityIndicatorSwitch: //230
		canId = HighPriorityCoolantQuantitySwitchCanId_0;
		break;
	}


	CAN_FIX_SendDataMessage(canId, index, functionCode, &button, 1);
}

void CAN_FIX_SendControlLeverPosition(ControlLeverTypedef lever, uint8_t element, float position, uint8_t index )
{
	uint16_t canId;
	switch(lever)
	{
	case ControlLever_LeftBrake:
		canId = HighPriorityLeftBrakeControlCanId;
		break;
	case ControlLever_RightBrake:
		canId = HighPriorityRightBrakeControlCanId;
		break;
	case ControlLever_EngineThrottle:
		canId = HighPriorityEngineThrottleControlCanId_0;
		break;
	case ControlLever_EngineProp:
		canId = HighPriorityEnginePropControlCanId_0;
		break;
	case ControlLever_EngineMixture:
		canId = HighPriorityEngineMixtureControlCanId_0;
		break;
	default:
		return;
	}
	struct CAN_FIX_Comms comms = FindCanFixComms(canId);
	//Verify comms did not return null: StdId = 0xFFFF
	if(comms.StdId == 0xFFFF)
		return;
	//Verify the element argument is not greater than the possible
	//elements
	if(element >= comms.Count)
		return;
	canId += element;
	CAN_FIX_SendMeasurement(canId, index, 0, position, 2);
}

void CAN_FIX_SendLandingGearControl(PilotLocationTypedef device, LandingGearTypedef button)
{
	uint16_t canId = HighPriorityLandingGearControlSwitchCanId_0;
	struct CAN_FIX_Comms comms = FindCanFixComms(canId);
	//Verify comms did not return null: StdId = 0xFFFF
	if(comms.StdId == 0xFFFF)
		return;
	//Verify the element argument is not greater than the possible
	//elements
	if(device >= comms.Count)
		return;
	canId += device;
	CAN_FIX_SendDataMessage(canId, 0, 0, &button, 1);
}

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
