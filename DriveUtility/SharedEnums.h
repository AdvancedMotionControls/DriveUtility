
#pragma once

#ifdef STATIC_DRIVE_MANAGER
#define DM_ENUM enum
#define DM_STRUCT struct
#define DM_TYPEDEF_STRUCT typedef struct
#else
#define DM_ENUM [export] enum
#define DM_STRUCT [export] struct
#define DM_TYPEDEF_STRUCT [export] typedef struct
#endif

#include <string>

#include "DriveConfigEnums.h"

namespace amc_se { 

DM_ENUM PVT_STATE {
    ACCELERATING,
    DECELERATING,
    CONSTANT_VELOCITY,
    END_POINT,
    REPEAT,
    DATA_POINT,
    MAX_PVT_STATES
};

DM_ENUM COMMAND_SOURCE_INPUT { 
    Zero = 0,
    WaveformGenerator = 1, 
    Theta, 
    VelocityLoopOutput,
    EncoderResolverVelocity,
    CommandProfilerOutput,
    PositionLoopOutput = 6, 
    EncoderResolverPosition = 7, 
    CommandAnalogInput5,
    CommandAnalogInput6,
    CommandAnalogInput7,
    CommandAnalogInput8,
    ProgrammableInput1FirstDifference, 
    ProgrammableInput2FirstDifference, 
    ProgrammableInput3FirstDifference, 
    ProgrammableInput4FirstDifference, 
    PwmInput = 16,
    PwmAndDirection = 17,
    Quad = 18,
    PVTInput,
    ProgrammableInput1 = 20, 
    ProgrammableInput2, 
    ProgrammableInput3, 
    ProgrammableInput4, 
    CommandAnalogInput1, 
    CommandAnalogInput2,
    CommandAnalogInput3, 
    CommandAnalogInput4,    
    InternalCommandedInput,
    HallVelocity = 29, 
    StepAndDirection,
    FieldWeakeningOutput,
    S_CurveProfilerOutput,
    DeadBandOutput,
    VoltageModeVelocity,
    HostSuppliedIqOffset,
    CommChannelSuppliedIqOffset,
    CommChannelSuppliedVelocityOffset,
    UndefinedInput
};

///
/// DRIVE_CONTROL_LOOP_MODES enumerations.
///
  DM_ENUM DRIVE_CONTROL_LOOP_MODES {VelocityMode = 0x0001,///< Velocity Mode.
                                          TorqueMode = 0x0002,///< Torque Mode.
                                          PositionMode = 0x0004,///< Position Mode.
                                          PositionAndVelocityMode = 0x0005,///< Position and velocity mode.
                                          ProfileMode = 0x0008,///< Profiler mode.
                                          PvtMode = 0x0010,///< PVT mode.
                                          SCurveMode = 0x0020,///< S-Curve Mode.
                                          DeadBand = 0x0040,///<Dead band.
                                          Camming = 0x0080,///<Camming.
                                          Gearing = 0x0100,///<Gearing.
                                          SummationNode = 0x0200,///<SummationNode.
                                          CyclicSync = 0x0400,///<Cyclic Sync.
                                          PvtModePositionAndVelocity = PvtMode | PositionMode | VelocityMode,///<PVT mode with position around velocity.
                                          PvtModePosition = PvtMode | PositionMode,///< PVT mode with position around torque.
                                          ProfileVelocityMode = ProfileMode | VelocityMode,///< Profile mode with velocity.
                                          ProfilePositionAndVelocityMode = ProfileMode | PositionAndVelocityMode,///< Profile with position around velocity.
                                          ProfilePositionAndTorqueMode = ProfileMode | PositionMode | TorqueMode,///< Profile with position around torque.
                                          ProfileTorqueMode = ProfileMode | TorqueMode,///< Profile torque mode.
                                          SCurvePositionAndVelocityMode = SCurveMode | PositionAndVelocityMode,///< S-Curve with position around velocity.
                                          SCurvePositionAndTorqueMode = SCurveMode | PositionMode | TorqueMode,///< S-Curve Position around torque.
                                          DeadBandAndProfileVelocityMode = ProfileMode | VelocityMode | DeadBand,///< Dead band and profile with velocity.
                                          DeadBandAndProfilePositionAndVelocityMode = ProfileMode | PositionAndVelocityMode | DeadBand,///< Dead band and profile with position around velocity.
                                          DeadBandAndProfilePositionAndTorqueMode = ProfileMode | PositionMode | TorqueMode | DeadBand,///< Dead band and profile with position around torque.
                                          DeadBandAndProfileTorqueMode = ProfileMode | TorqueMode | DeadBand,///< Dead band and profile torque mode.
                                          DeadBandAndPositionMode = PositionMode | DeadBand,///< Dead band with position around torque.
                                          DeadBandAndVelocityMode = VelocityMode | DeadBand,///< Dead band with velocity.
                                          DeadBandAndPositionAndVelocityMode = PositionAndVelocityMode | DeadBand,///< Dead band with position around velocity.
                                          DeadBandAndPositionAndTorqueMode = PositionMode | TorqueMode | DeadBand,///< Dead band with position around torque.
                                          DeadBandAndTorqueMode = TorqueMode | DeadBand,///< Dead band torque mode.
                                          DeadBandAndSCurvePositionAndVelocityMode = SCurveMode | PositionAndVelocityMode | DeadBand,///< Dead band and S-Curve with position around velocity.
                                          DeadBandAndSCurvePositionAndTorqueMode = SCurveMode | PositionMode | TorqueMode | DeadBand,///< Dead band and S-Curve with position around torque.
                                          CammingAndPositionMode = PositionMode | Camming,///< Camming with position around torque.
                                          CammingAndPositionAndVelocityMode = PositionAndVelocityMode | Camming,///< Camming with position around torque.
                                          CammingAndPositionAndTorqueMode = PositionMode | TorqueMode | Camming,///< Camming with position around torque.
                                          CammingDeadBandAndPositionMode = PositionMode | Camming | DeadBand,///< Camming and dead band with position around torque.
                                          CammingDeadBandAndPositionAndVelocityMode = PositionAndVelocityMode | Camming | DeadBand,///< Camming and dead band with position around velocity.
                                          CammingDeadBandAndPositionAndTorqueMode = PositionMode | TorqueMode | Camming | DeadBand,///< Camming and dead band with position around torque.
                                          GearingAndPositionMode = PositionMode | Gearing,///< Gearing with position around torque.
                                          GearingAndPositionAndVelocityMode = PositionAndVelocityMode | Gearing,///< Gearing with position around velocity.
                                          GearingAndPositionAndTorqueMode = PositionMode | TorqueMode | Gearing,///< Gearing with position around torque.
                                          GearingDeadBandAndPositionMode = PositionMode | Gearing | DeadBand,///< Gearing and dead band with position around torque.
                                          GearingDeadBandAndPositionAndVelocityMode = PositionAndVelocityMode | Gearing | DeadBand,///< Gearing and dead band with position around velocity.
                                          GearingDeadBandAndPositionAndTorqueMode = PositionMode | TorqueMode | Gearing | DeadBand,///< Gearing and dead band with position around torque.
                                          GearingAndProfilerPositionMode = PositionMode | Gearing | ProfileMode,///< Gearing and profile with position around torque.
                                          GearingAndProfilerPositionAndVelocityMode = PositionAndVelocityMode | Gearing | ProfileMode,///< Gearing and profile with position around velocity.
                                          GearingAndProfilerPositionAndTorqueMode = PositionMode | TorqueMode | Gearing | ProfileMode,///< Gearing and profile with position around torque.
                                          GearingDeadBandAndProfilerPositionMode = PositionMode | Gearing | ProfileMode,///< Gearing and profile with position around torque.
                                          GearingDeadBandAndProfilerPositionAndVelocityMode = PositionAndVelocityMode | Gearing | ProfileMode,///< Gearing and profile with position around velocity.
                                          GearingDeadBandAndProfilerPositionAndTorqueMode = PositionMode | TorqueMode | Gearing | ProfileMode,///< Gearing and profile with position around torque.
                                          GearingAndSCurvePositionMode = PositionMode | Gearing | SCurveMode,///< Gearing and S-Curve with position around torque.
                                          GearingAndSCurvePositionAndVelocityMode = PositionAndVelocityMode | Gearing | SCurveMode,///< Gearing and S-Curve with position around velocity.
                                          GearingAndSCurvePositionAndTorqueMode = PositionMode | TorqueMode | Gearing | SCurveMode,///< Gearing and S-Curve with position around torque.
                                          GearingDeadBandAndSCurvePositionMode = PositionMode | Gearing | SCurveMode | DeadBand,///< Gearing and S-Curve with position around torque.
                                          GearingDeadBandAndSCurvePositionAndVelocityMode = PositionAndVelocityMode | Gearing | SCurveMode | DeadBand,///< Gearing and S-Curve with position around velocity.
                                          GearingDeadBandAndSCurvePositionAndTorqueMode = PositionMode | TorqueMode | Gearing | SCurveMode | DeadBand,///< Gearing and S-Curve with position around torque.
                                          GearingAndTorqueMode = TorqueMode | Gearing,///< Gearing torque mode.
                                          GearingAndVelocityMode = VelocityMode | Gearing,///< Gearing velocity mode.
                                          GearingDeadBandAndTorqueMode = TorqueMode | Gearing | DeadBand,///< Gearing and dead band torque mode.
                                          GearingDeadBandAndVelocityMode = VelocityMode | Gearing | DeadBand,///< Gearing and dead band with velocity around torque.
                                          GearingAndProfileTorqueMode = TorqueMode | Gearing | ProfileMode,///< Gearing and profile with torque mode.
                                          GearingAndProfileVelocityMode = VelocityMode | Gearing | ProfileMode,///< Gearing and dead band with velocity around torque.
                                          GearingDeadBandAndProfileTorqueMode = TorqueMode | Gearing | DeadBand | ProfileMode,///< Gearing, dead band and profile with velocity around torque.
                                          GearingDeadBandAndProfileVelocityMode = VelocityMode | Gearing | DeadBand | ProfileMode,///< Gearing, dead band and profile with velocity around torque.
                                          SummationNodeAndTorqueMode = SummationNode |TorqueMode,///< Summation node with torque mode.
                                          DeadBandSummationNodeAndTorqueMode = SummationNode | DeadBand |TorqueMode,///< Summation node and dead band with torque mode.
                                          SummationNodeRateLimiterAndTorqueMode = SummationNode | ProfileMode | TorqueMode,///< Summation node and profile with torque mode.
                                          SummationNodeS_CurveAndTorqueMode = SummationNode | SCurveMode | TorqueMode,///< Summation node and S-Curve with torque mode.
                                          DeadBandSummationNodeS_CurveTorqueMode = DeadBand | SummationNode | SCurveMode | TorqueMode,///< Dead band, Summation Node and S-Curve with torque mode.
                                          SummationNodeCammingAndTorqueMode = SummationNode | Camming | TorqueMode,///< Summation node and camming with torque mode.
                                          DeadBandSummationNodeAndCammingAndTorqueMode = DeadBand | SummationNode | Camming | TorqueMode,///< Dead band, summation node and Camming with torque mode.
                                          SummationNodeGearingAndTorqueMode = SummationNode | Gearing | TorqueMode,///< Summation node and gearing with torque mode.
                                          DeadBandSummationNodeGearingAndTorqueMode = DeadBand | SummationNode | Gearing | TorqueMode,///< Dead band, summation node and gearing with torque mode.
                                          SummationNodeGearingRateLimiterAndTorqueMode = SummationNode | Gearing | ProfileMode | TorqueMode,///< Summation node, gearing and profile with torque mode.
                                          DeadBandSummationNodeGearingRateLimiterAndTorqueMode = DeadBand | SummationNode | Gearing | ProfileMode | TorqueMode,///< Dead band, summation node, gearing and profile with torque mode.
                                          SummationNodeGearingCammingAndTorqueMode = SummationNode | Gearing | Camming | TorqueMode,///< Summation node, gearing and camming with torque mode.
                                          SummationNodeAndVelocityMode = SummationNode |VelocityMode,///< Summation node with velocity around torque.
                                          DeadBandSummationNodeAndVelocityMode = SummationNode | DeadBand |VelocityMode,///< Summation node and dead band with velocity around torque.
                                          SummationNodeRateLimiterAndVelocityMode = SummationNode | ProfileMode | VelocityMode,///< Summation node and profile with velocity around torque.
                                          SummationNodeS_CurveAndVelocityMode = SummationNode | SCurveMode | VelocityMode,///< Summation node, S-Curve with velocity around torque.
                                          DeadBandSummationNodeS_CurveVelocityMode = DeadBand | SummationNode | SCurveMode | VelocityMode,///< Dead band, summation node and S-Curve with velocity around torque.
                                          SummationNodeCammingAndVelocityMode = SummationNode | Camming | VelocityMode,///< Summation node and camming with velocity around torque.
                                          DeadBandSummationNodeCammingAndVelocityMode = DeadBand | SummationNode | Camming | VelocityMode,///< Dead band, summation node and camming with velocity around torque.
                                          SummationNodeGearingAndVelocityMode = SummationNode | Gearing | VelocityMode,///< Summation node and gearing with velocity around torque.
                                          DeadBandSummationNodeGearingAndVelocityMode = DeadBand | SummationNode | Gearing | VelocityMode,///< Dead band, summation node and gearing with velocity around torque.
                                          SummationNodeGearingRateLimiterAndVelocityMode = SummationNode | Gearing | ProfileMode | VelocityMode,///< Summation node, gearing and profile with velocity around torque.
                                          DeadBandSummationNodeGearingRateLimiterAndVelocityMode = DeadBand | SummationNode | Gearing | ProfileMode | VelocityMode,///< Dead band, summation node, gearing and profile with velocity around torque.
                                          SummationNodeGearingCammingAndVelocityMode = SummationNode | Gearing | Camming | VelocityMode,///< Summation node, gearing and camming with velocity around torque.
                                          SummationNodeAndPositionMode = SummationNode |PositionMode,///< Summation node with position around torque.
                                          DeadBandSummationNodeAndPositionMode = SummationNode | DeadBand |PositionMode,///< Summation node and dead band with position around torque.
                                          SummationNodeRateLimiterAndPositionMode = SummationNode | ProfileMode | PositionMode,///< Summation node and profile with position around torque.
                                          SummationNodeS_CurveAndPositionMode = SummationNode | SCurveMode | PositionMode,///< Summation node and S-Curve with position around torque.
                                          DeadBandSummationNodeS_CurvePositionMode = DeadBand | SummationNode | SCurveMode | PositionMode,///< Dead band, summation node and S-Curve with position around torque.
                                          SummationNodeCammingAndPositionMode = SummationNode | Camming | PositionMode,///< Summation node and camming with position around torque.
                                          DeadBandSummationNodeCammingAndPositionMode = DeadBand | SummationNode | Camming | PositionMode,///< Dead band, summation node and camming with position around torque.
                                          SummationNodeGearingAndPositionMode = SummationNode | Gearing | PositionMode,///< Summation node and gearing with position around torque.
                                          DeadBandSummationNodeGearingAndPositionMode = DeadBand | SummationNode | Gearing | PositionMode,///< Dead band, summation node and gearing with position around torque.
                                          SummationNodeGearingRateLimiterAndPositionMode = SummationNode | Gearing | ProfileMode | PositionMode,///< Summation node, gearing and profile with position around torque.
                                          DeadBandSummationNodeGearingRateLimiterAndPositionMode = DeadBand | SummationNode | Gearing | ProfileMode | PositionMode,///< Dead band, summation node, gearing and profile with position around torque.
                                          SummationNodeGearingCammingAndPositionMode = SummationNode | Gearing | Camming | PositionMode,///< Summation node, gearing and camming with position around torque.
                                          SummationNodeAndPositionAndTorqueMode = SummationNode |PositionMode | TorqueMode,///< Summation node with position around torque.
                                          DeadBandSummationNodeAndPositionAndTorqueMode = SummationNode | DeadBand |PositionMode  | TorqueMode,///< Summation node and dead band with position around torque.
                                          SummationNodeRateLimiterAndPositionAndTorqueMode = SummationNode | ProfileMode | PositionMode  | TorqueMode,///< Summation node and profile with position around torque.
                                          SummationNodeS_CurveAndPositionAndTorqueMode = SummationNode | SCurveMode | PositionMode  | TorqueMode,///< Summation node and S-Curve with position around torque.
                                          DeadBandSummationNodeS_CurvePositionAndTorqueMode = DeadBand | SummationNode | SCurveMode | PositionMode  | TorqueMode,///< Dead band, summation node, and S-Curve with position around torque.
                                          SummationNodeCammingAndPositionAndTorqueMode = SummationNode | Camming | PositionMode | TorqueMode,///< Summation node and camming with position around torque.
                                          DeadBandSummationNodeCammingAndPositionAndTorqueMode = DeadBand | SummationNode | Camming | PositionMode  | TorqueMode,///< Dead band, summation node and camming with position around torque.
                                          SummationNodeGearingAndPositionAndTorqueMode = SummationNode | Gearing | PositionMode  | TorqueMode,///< Summation node and gearing with position around torque.
                                          DeadBandSummationNodeGearingAndPositionAndTorqueMode = DeadBand | SummationNode | Gearing | PositionMode  | TorqueMode,///< Dead band, summation node and profile with position around torque.
                                          SummationNodeGearingRateLimiterAndPositionAndTorqueMode = SummationNode | Gearing | ProfileMode | PositionMode  | TorqueMode,///< Summation node, gearing and profile with position around torque.
                                          DeadBandSummationNodeGearingRateLimiterAndPositionAndTorqueMode = DeadBand | SummationNode | Gearing | ProfileMode | PositionMode  | TorqueMode,///< Dead band, summation node, gearing and profile with position around torque.
                                          SummationNodeGearingCammingAndPositionAndTorqueMode = SummationNode | Gearing | Camming | PositionMode  | TorqueMode,///< Summation node, gearing and camming with position around torque.
                                          SummationNodeAndPositionAndVelocityMode = SummationNode |PositionAndVelocityMode,///< Summation node with position around velocity.
                                          DeadBandSummationNodeAndPositionAndVelocityMode = SummationNode | DeadBand |PositionAndVelocityMode,///< Summation node and dead band with position around velocity.
                                          SummationNodeRateLimiterAndPositionAndVelocityMode = SummationNode | ProfileMode | PositionAndVelocityMode,///< Summation node and profile with position around velocity.
                                          SummationNodeS_CurveAndPositionAndVelocityMode = SummationNode | SCurveMode | PositionAndVelocityMode,///< Summation node and S-Curve with position around velocity.
                                          DeadBandSummationNodeS_CurvePositionAndVelocityMode = DeadBand | SummationNode | SCurveMode | PositionAndVelocityMode,///< Dead band, summation node and S-Curve with position around velocity.
                                          SummationNodeCammingAndPositionAndVelocityMode = SummationNode | Camming | PositionAndVelocityMode,///< Summation node and camming with position around velocity.
                                          DeadBandSummationNodeCammingAndPositionAndVelocityMode = DeadBand | SummationNode | Camming | PositionAndVelocityMode,///< Dead band, summation node and camming with position around velocity.
                                          SummationNodeGearingAndPositionAndVelocityMode = SummationNode | Gearing | PositionAndVelocityMode,///< Summation node and gearing with position around velocity.
                                          DeadBandSummationNodeGearingAndPositionAndVelocityMode = DeadBand | SummationNode | Gearing | PositionAndVelocityMode,///< Dead band, summation node and gearing with position around velocity.
                                          SummationNodeGearingRateLimiterAndPositionAndVelocityMode = SummationNode | Gearing | ProfileMode | PositionAndVelocityMode,///< Summation node, gearing and profile with position around velocity.
                                          DeadBandSummationNodeGearingRateLimiterAndPositionAndVelocityMode = DeadBand | SummationNode | Gearing | ProfileMode | PositionAndVelocityMode,///< Dead band, summation node, gearing and profile with position around velocity. 
                                          SummationNodeGearingCammingAndPositionAndVelocityMode = SummationNode | Gearing | Camming | PositionAndVelocityMode,///< Summation node, gearing and camming with position around velocity.
                                          CyclicSyncPositionMode = CyclicSync | PositionMode | VelocityMode,///< Cyclic synchronization with position around velocity.
                                          CyclicSyncVelocityMode = CyclicSync | VelocityMode,///< Cyclic synchronization with velocity around torque.
                                          CyclicSyncTorqueMode = CyclicSync | TorqueMode,///< Cyclic synchronization with torque mode.
                                          MAX_MODE};///< Maximum modes. 


DM_ENUM DRIVE_MANAGER_INTERFACE_ERRORS{INTERFACE_OK,
                                       READ_MESSAGE_FAILED, 
                                       WRITE_MESSAGE_FAILED, 
				                           NO_COMM_PORT_INITIALIZED,
                                       INTERFACE_NOT_SELECTED,
                                       PURGE_QUEUE_FAILED,
                                 		SET_TIMEOUT_FAILED, 
                                       UNABLE_TO_OPEN_COMM_PORT, 
                                       CONFIGURING_SERIAL_PORT_FAILED,
				                           SETTING_UP_QUEUE_FOR_SERIAL_PORT_FAILED,
                                       FUNCTION_NOT_AVAILABLE, 
                                       UNINITIALIZED_POINTER,
				                           MESSAGE_CRC_FAILED,
                                       RX_MESSAGE_WRONG_SIZE,
                                       NODE_UNAVAILABLE,
                                       COULD_NOT_CONNECT_TO_DRIVE,
                                       MAX_INTERFACE_ERROR
                                 	};

///
/// CaptureState enumerations. Enumeration of the capture states.
///
DM_ENUM CaptureState
{ 
   CaptureEnable,///<Capture enable.
   CaptureDisable///<Capture disable.
};

///
/// Auxiliary encoder index state enumerations. Enumeration of the auxiliary encoder index state.
///
DM_ENUM AuxiliaryEncoderIndexStates{ 
   AuxiliaryEncoderIndexEnable,///< Auxiliary encoder index enable.
   AuxiliaryEncoderIndexDisable///< Auxiliary encoder index disable.
};

///
/// Capture states structure. 
///
DM_TYPEDEF_STRUCT
{
   CaptureState CaptureOne;///< Capture one's state.
   CaptureState CaptureTwo;///< Capture two's state.
   CaptureState CaptureThree;///< Capture three's state.
} CaptureStates;

///
/// Auxiliary encoder index state structure.
///

DM_STRUCT AuxEncoderIndexState
{
   AuxiliaryEncoderIndexStates AuxiliaryEncoderIndex;///<Auxiliary encoder index state.
};

DM_STRUCT EnableBiquadStage
{
   BiquadStates Biquad1;
   BiquadStates Biquad2;
   BiquadStates Biquad3;
   BiquadStates Biquad4;
   BiquadStates Biquad5;
   BiquadStates Biquad6;
};

DM_STRUCT Stored_Drive_Mode
{
   ControlLoopConfigurations ActiveModeSelect;
   CommandProfilerSelect CommandProfilerSelection;
   SourceModifierSelect SourceModifierSelection;
   int MapGainSet1;
   int MapProfilerParameterSet1;
   int MapSourceModifierParameterSet1;
};

DM_TYPEDEF_STRUCT
{
   Stored_Drive_Mode StoredDriveMode;
   COMMAND_SOURCE_INPUT MotorOverTemperatureSource;
   COMMAND_SOURCE_INPUT DQCurrentLimitScalingSource;
   COMMAND_SOURCE_INPUT VelocityFeedbackSource;
   COMMAND_SOURCE_INPUT PositionFeedbackSource; 
   COMMAND_SOURCE_INPUT CommandSource;
   EnableBiquadStage VelocityFeedbackFilterSelect;
   EnableBiquadStage PositionFeedbackFilterSelect;
   EnableBiquadStage CommandSourceFilterSelect;
   EnableBiquadStage CurentLoopInputFilter;
   EnableBiquadStage VelocityLoopInputFilter;
   EnableBiquadStage PositionLoopInputFilter;
   COMMAND_SOURCE_INPUT SummationNodeOffsetSource;
   COMMAND_SOURCE_INPUT TorqueCurrentLoopOffsetSource;
   COMMAND_SOURCE_INPUT VelocityLoopOffsetSource;
   COMMAND_SOURCE_INPUT PositionLoopOffsetSource;
}DriveModeConfiguration;


DM_ENUM PwmInputStates
{
   PwmInputDisable,
   PwmInputEnable,
};

DM_ENUM PwmDirectionStates
{
   PwmDirectionDisable,
   PwmDirectionEnable,
};

  DM_ENUM DRIVE_MANAGER_COMMUNICATION_INTERFACES{RS_232, 
                                                 SYNQ_NET,
                                                 COMM_GATEWAY,
                                                 CAN_KVASER,
                                                 ETHERNET,
                                                 POWER_LINK,
                                                 RS_485,
                                                 USB,
                                                 VIRTUAL_DRIVE,
                                                 MAX_INTERFACE};

  enum COMMUNICATION_INTERFACE_PROTOCOLS{SerialProtocol,
                                         CanProtocol, 
                                         MaxProtocol
                                        };


  DM_ENUM PARAMETER_ERRORS{PARAMETER_OK,
                                 OUT_OF_RANGE,
                                 INVALID_PARAMETER,
                                 PARAMETER_DATA_CRC_FAILED,
                                 MAX_PARAMETER_ERROR
                                };

  DM_ENUM PVT_SPOOLER_ERRORS{SPOOLER_OK,
                                   BUFFER_UNDERFLOW,
                                   PVT_POINTS_SPACING_ERROR,
                                   MAX_SPOOLER_ERROR
                                  };

  DM_ENUM BURN_FIRMWARE_CODES{ 
                                    ERRORS_NO_ERROR,
                                    ERRORS_INVALID_FILE, 
                                    ERRORS_NOT_CONNECTED_TO_DRIVE, 
                                    ERRORS_FILE_NAME_NOT_SET,
	                                 ERRORS_UNABLE_TO_OPEN_FILE, 
                                    ERRORS_NO_CONTROLBOARD_NAME, 
                                    ERRORS_INVALID_FILE_TYPE, 
         								   ERRORS_ALTERED_FILE_FORMAT, 
                                    ERRORS_UNKNOWN_FILE_FORMAT, 
                                    ERRORS_UNKNOWN_SEGMENT_TYPE,
									         ERRORS_UNEXPECTED_END_OF_SEGMENT, 
                                    ERRORS_UNEXPECTED_END_OF_FILE, 
                                    ERRORS_SEGMENT_BOOTLOADER_REQ_NOT_MET,
									         ERRORS_READING_SEGMENT_DATA, 
                                    ERRORS_READING_BOOTLOADER_SEGMENT_DATA, 
                                    ERRORS_READING_MAIN_SEGMENT_DATA,
									         ERRORS_READING_DRIVER_SEGMENT_DATA, 
                                    ERRORS_READING_FPGA_SEGMENT_DATA, 
                                    ERRORS_READING_CORE_SEGMENT_DATA,
									         ERRORS_SOFTWARE_VERSION_MISMATCH, 
                                    ERRORS_MISSING_BOOTLOADER_SEGMENT, 
                                    ERRORS_INCOMPATIBLE_BOOTLOADERS,
									         ERRORS_NO_COMPATIBLE_MAIN_TO_CONTROLBOARD, 
                                    ERRORS_NO_COMPATIBLE_DRIVER_TO_CONTROLBOARD,
	         								ERRORS_NO_COMPATIBLE_FPGA_TO_CONTROLBOARD, 
                                    ERRORS_NO_COMPATIBLE_CORE_TO_CONTROLBOARD, 
				         					ERRORS_NO_COMPATIBLE_BOOTLOADER_TO_CONTROLBOARD, 
                                    ERRORS_FILE_NOT_COMPATIBLE_TO_CONTROLBOARD, 
							         		ERRORS_INVALID_OPERATION_MODE, 
                                    ERRORS_UNABLE_TO_DISABLE_DRIVE, 
                                    ERRORS_UNABLE_TO_CHANGE_DRIVE_MODE, 
									         ERRORS_UNABLE_TO_SEND_CHANGEDRIVEMODE_MESSAGE, 
                                    ERRORS_UNABLE_ERASE_NON_VOLATILE_MEMORY, 
									         ERRORS_UNABLE_COMPLETE_FIRMWARE_BURN, 
                                    ERRORS_CHECKSUM_FAILED,
                                    ERRORS_NO_COMPATIBLE_DOWNGRADE_SEGMENT,
                                    ERRORS_UNABLE_TO_PROCESS_FILE, 
                                    ERRORS_UNABLE_TO_RECONNECT,
                                    ERRORS_UNABLE_TO_GET_FLASHKEY,
                                    ERRORS_UNABLE_TO_SEND_GET_FLASHKEY_MESSAGE,
                                    ERRORS_LOST_COMMUNICATION,
                                    ERRORS_NO_RESPONSE_ON_REBOOT_REQUEST,
                                    WARNING_UNABLE_TO_SAVE_PROJECT,
                                    WARNING_CONNECTED_IN_BOOT_MODE,
                                    WARNING_COULD_NOT_WRITE_PROJECT, 
                                    ERRORS_MISSING_CURRENT_FIRMWARE_FILE,
                                    MAX_FIRMWARE_CODE
                                   };

  DM_ENUM ERROR_EVENTS{UNABLE_TO_OPEN_FILE_EVENT, 
                       COMM_ERROR_DATA_MISMATCH_EVENT,
                       MESSAGE_WRONG_SIZE_EVENT, 
                       RX_MESSAGE_CRC_ERROR_EVENT, 
                       STATUS_ERROR_EVENT,
                       COMMUNICATION_ERROR_EVENT,
                       PARAMETER_DATA_CRC_FAILED_EVENT,
                       WRITE_ATTEMPTED_WITHOUT_WRITE_ACCESS,
                       FILE_IS_NOT_A_PROJECT_FILE_EVENT, 
                       PROJECT_IS_NOT_COMPATIBLE_WITH_DRIVE,
                       DRIVE_FIRMWARE_IS_NOT_SUPPORTED,
                       FILE_IS_NOT_COMPATIBLE_FEEDBACK_SENSORS_DIFFER,
                       FILE_IS_NOT_COMPATIBLE_CONTROL_BOARD_NAMES_DIFFER,
                       FILE_IS_NOT_COMPATIBLE_POWER_BOARD_NAMES_DIFFER,
                       FILE_IS_NOT_COMPATIBLE_NO_CONTROL_BOARD_NAME,
                       FILE_IS_NOT_COMPATIBLE_NO_POWER_BOARD_NAME,
                       MAX_ERROR_EVENT
                       };

  DM_ENUM PVT_ARM_WARNINGS{PVT_ARMED,
                           FIRMWARE_DOES_NOT_SUPPORT_PVT_ARM,   
                           MAX_PVT_ARM_WARNINGS
                          };

DM_ENUM PVT_INPUT_MODES{ABSOLUTE_WITHOUT_ARMING,
                        INCREMENTAL_WITHOUT_ARMING,
                        ABSOLUTE_WITH_ARMING,
                        INCREMENTAL_WITH_ARMING,
                        MAX_PVT_INPUT_MODES
                       };

  DM_ENUM PVT_STATUS{PVT_OK,
                     PVT_BUFFER_ERROR, 
                     PVT_PARAMETER_INVALID, 
                     ERROR_SENDING_POINTS,
                     ERROR_READ_NUMBER_OF_POINTS,
                     MAX_PVT_STATUS
                    };

  DM_ENUM PVT_ACTIONS{START_MOTION,
                      CLEAR_BUFFER,
                      CLEAR_POINTS,
                      ADD_POINT,
                      INITIALIZE_PVT = 5,
                      ARM_PVT_GENERATOR,
                      MAX_PVT_ACTIONS
                     };

  DM_ENUM SerialEncoderCommands{SerialEncoderCommandReadModel = 1,
                                      SerialEncoderCommandReadSerialNumber,
                                      SerialEncoderCommandReadSignalPeriod,
                                      SerialEncoderCommandReadAbsoluteNumberOfRevs,
                                      SerialEncoderCommandReadAbsoluteNumberOfTurns,
                                      SerialEncoderCommandFormatMemory = 65532,
                                      SerialEncoderCommandReadMemorySize,
                                      SerialEncoderCommandReadMemory,
                                      SerialEncoderCommandWriteMemory,
                                     };


  DM_ENUM PdoTransmissionTypes{SyncAcyclic,
                                     SyncCyclic,
                                     SyncRTR,
                                     Async,
                                    };

  DM_ENUM PdoMappingIDs{EmptyMappingID,
                        ActualCurrentMappingID,
                        TargetCurrentMappingID,
                        DemandCurrentMappingID,
                        CurrentOffsetMappingID,
                        ActualVelocityMappingID,
                        TargetVelocityMappingID,
                        VelocityErrorMappingID,
                        VelocityDemandMappingID,
                        ActualPositionMappingID,
                        TargetPositionMappingID,
                        PositionErrorMappingID,
                        DCBusVoltageMappingID,  
                        AnalogInput1ValueMappingID,
                        AnalogInput2ValueMappingID,
                        AnalogInput3ValueMappingID,
                        AnalogInput4ValueMappingID,
                        AnalogInput5ValueMappingID,
                        AnalogOutput1ValueMappingID,
                        AnalogOutput2ValueMappingID,
                        ExternalThermalSenseValueMappingID,
                        ThermistorResistanceMappingID,
                        DigitalInputValuesMappingID,
                        StatusWordMappingID,
                        ControlWordMappingID,
                        ModesOfOperationMappingID,
                        ModesOfOperationDisplayMappingID,
                        PVTStatusValuesMappingID,
                        DriveBridgeStatusMappingID,
                        DriveProtectionStatusMappingID,
                        SystemProtectionStatusMappingID,
                        DriveSystemStatus1MappingID,
                        DriveSystemStatus2MappingID,
                        DriveSystemStatus3MappingID,
                        DriveBridgeStatusHistoryMappingID,
                        DriveProtectionStatusHistoryMappingID,
                        SystemProtectionStatusHistoryMappingID,
                        DriveSystemStatus1HistoryMappingID,
                        DriveSystemStatus2HistoryMappingID,
                        DriveSystemStatus3HistoryMappingID,
                        CaptureAMappingID,
                        CaptureBMappingID,
                        CaptureCMappingID,
                        UserBitsMappingID,
                        PvtBufferMappingID,
                        VelocityOffsetMappingID,
                        PvtBufferPositionMappingID,
                        PositionDemandMappingID,
                        TorqueSummationInputID,
                        TorqueSummationOffsetID,
                        VelocitySummationInputID,
                        VelocitySummationOffsetID,
                        PositionSummationInputID,
                        PositionSummationOffsetID,
                        PositionCaptureValueID,
                        AuxiliaryEncoderCaptureCountID,
                        AuxiliaryEncoderCountID,
                        UserDefinedMappingID,
                        NetworkDigitalInputValue0ID,
                        NetworkDigitalInputValue1ID,
                        NetworkDigitalInputValue2ID,
                        NetworkDigitalInputValue3ID,
                        NetworkAdcRawValue0ID,
                        NetworkAdcRawValue1ID,
                        NetworkAdcRawValue2ID,
                        NetworkAdcRawValue3ID,
                        NetworkAdcRawValue4ID,
                        NetworkAdcRawValue5ID,
                        NetworkAdcRawValue6ID,
                        NetworkAdcRawValue7ID,
                        NetworkDigitalOutputValue0ID,
                        NetworkDigitalOutputValue1ID,
                        NetworkDigitalOutputValue2ID,
                        NetworkDigitalOutputValue3ID,
                        NetworkAnalogOutputValue0ID,
                        NetworkAnalogOutputValue1ID,
                        NetworkAnalogOutputValue2ID,
                        NetworkAnalogOutputValue3ID,
                        RawADCInput1ValueID,
                        RawADCInput2ValueID,
                        RawADCInput3ValueID,
                        RawADCInput4ValueID,
                        CommandProfilerSCurveMaxVelocityValueID,
                        CommandProfilerSCurveMaxAccelerationValueID,
                        CommandProfilerSCurveMaxDecelerationValueID,
                        };

  DM_ENUM PdoTypes{Transmit,
                         Receive,
                        };

  DM_ENUM DataTypes{U_S_INTEGER,
                          INTEGER,
                          U_INTEGER,
                          D_INTEGER,
                          U_LONG_INTEGER,
                         };

  DM_ENUM CanObjectTypes{ReservedType = 0,
                               TransmitMappable = 1,   
                               ReceiveMappable = 2,
                               PdoEventBitObserved = 4,
                               ValueChangedObserved = 8,
                               ValueReachedObserved = 16,
                              };

  
 DM_TYPEDEF_STRUCT PvtDataStruct{
     double Position_Rel;
     double Position_Abs;
     double Velocity;
     double Time;
     double Accel;
     PVT_STATE PvtState;
     int SequenceNumber;
     unsigned int AppilcationIdenitier;
  }PvtDataStructure;

DM_STRUCT PdoCommParameters{
    unsigned char ParametersValid;
    unsigned char RemoteTransmitRequest;
    unsigned char Enabled;
    unsigned int CobID;
    PdoTransmissionTypes TransmissionType;
    unsigned int Period;
 };

DM_STRUCT ObjectMappingData{
   PdoMappingIDs PdoMappingID;
   unsigned int Index;
   unsigned int SubIndex;
   DataTypes DataType;   
};

DM_STRUCT PdoMappingParameters{
    unsigned int NameLength;
    char Name[8];
    unsigned int NumberOfObjectMappings;
    ObjectMappingData ObjectMappings[16];
    unsigned int SizeOfMapping;
    unsigned char Configurable;
    PdoCommParameters PdoCommunicationParameters;
    
 };

 DM_STRUCT TpdoTimer{
    unsigned int CycleTime;
    unsigned int AssignedTpdos;
 };

 DM_STRUCT ValueChanged{
    PdoMappingIDs ObjectID;
    unsigned int DeltaValue;
    unsigned int AssignedTpdos;
    unsigned int ObjectIdValue;
 };

 DM_STRUCT ValueReached{
    PdoMappingIDs ObjectID;
    unsigned int AssignedTpdos;
    unsigned int Reached;
    unsigned int Direction;
    unsigned int ObjectIdValue;
 };

 DM_STRUCT BitChanged{
    PdoMappingIDs ObjectID;
    unsigned int ObjectBitMask;
    unsigned int AssignedTpdos;
    unsigned int ObjectIdValue;
 };

 DM_STRUCT AsynchronousTransmissionParameters{
    unsigned char ParametersValid;
    TpdoTimer TpdoTimerOne;
    TpdoTimer TpdoTimerTwo;
    ValueChanged TpdoValueChanged;
    ValueReached TpdoValueReached;
    BitChanged TpdoBitChangedOne;
    BitChanged TpdoBitChangedTwo;
 };

 DM_TYPEDEF_STRUCT PdoConfiguration{
    unsigned int NumberOfPdoMappings;
    PdoMappingParameters* PdoMappings;
    AsynchronousTransmissionParameters AsynchTransmissionParameters;
 }PdoConfigurationStruct;

struct MAPPING_IDS_AMC_ENUM_INDEX_INFO
{
   PdoMappingIDs MappingID;
   unsigned int AmcEnum;
   unsigned int IndexSubIndexDataType;
   unsigned int Access;
   std::string Name;
   DataTypes DataType;
};

 DM_TYPEDEF_STRUCT CanObject{
    unsigned int NameLength;
    char Name[35];
    unsigned int Index;
    unsigned int SubIndex;
    DataTypes DataType;
    PdoMappingIDs ObjectID;
 }CanObjectStruct;

DM_ENUM StorageTypes
{
   UserStorage,
   MotionEngineStorage,
   DynamicOpCodeStorage
};   


DM_ENUM ProjectVersions
{ 
   ProjectVersion_7_0,
   ProjectVersion_7_1,
   ProjectVersion_7_2,
   ProjectVersion_7_3,
   ProjectVersionLatest
};


 }
