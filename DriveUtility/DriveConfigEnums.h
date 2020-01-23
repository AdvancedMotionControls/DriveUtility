#pragma once

namespace amc_se {

/*=============================================================================
 ===== Current drive state.
 ============================================================================*/

#ifndef STATIC_DRIVE_MANAGER
[export] enum LoopConfigurations
#else
enum LoopConfigurations
#endif
{
   Configuration0,
   Configuration1
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum ControlLoopConfigurations
#else
enum ControlLoopConfigurations
#endif
{
   UseControlLoopsInConfiguration,
   TorqueOnly,
   VelocityAroundTorque,
   PositionAroundTorque,
   PositionAroundVelocityAroundTorque,
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum CommandProfilerSelect
#else
enum CommandProfilerSelect
#endif
{
   UseCommandProfilerInConfiguration,
   CommandProfilerSelectNone,
   CommandProfilerSelectFirstDiffRateLimiter,
   CommandProfilerSelectLinearInterpolation,
   CommandProfilerSelectAccelDecel,
   CommandProfilerSelectCamming,
   
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum SourceModifierSelect
#else
enum SourceModifierSelect
#endif
{
   SourceModifierUseSelectedConfiguration,
   SourceModifierNone,
   SourceModifierDeadBand,
   SourceModifierGearing,
   SourceModifierDeadIntoGearing,
   SourceModifierSummationNodeOnly,
   SourceModifierDeadbandIntoSummationNode,
   SourceModifierGearingIntoSummationNode,
   SourceModifierDeadbandIntoGearingIntoSummationNode,
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum LoopOffsetSourceSelect
#else
enum LoopOffsetSourceSelect
#endif
{
   LoopOffsetSourceSelectedInConfiguration,
   LoopOffsetAllNotConnected,
   LoopOffsetSuppliedByCommuncationChannel,
   LoopOffsetStandAloneConfiguration,
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum CommandSourceControls
#else
enum CommandSourceControls
#endif
{
   UseCommandSourceInConfiguration,
   UseDrivesWaveformGenerator,
   UseCommunicationChannelSuppliedCommand,
   UseInterpolatedCommandGenerator,
   UseInternallyGeneratedTimeBase,
   UseFluxReferenceTuningSourceConfiguration = 14,
   UseAutoCommSourceConfiguration,
   HomingModuleOutput,
   MotionEngineOutput,
   JogModuleOutput,
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum ActiveModeStatuses
#else
enum ActiveModeStatuses
#endif
{
   StandByMode,
   HomingModeActive,
   JogModeActive,
   MotionEngineModeActive,
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum ActiveConfigurationStatuses
#else
enum ActiveConfigurationStatuses
#endif
{
   ZeroActive,
   OneActive,
};

#ifndef STATIC_DRIVE_MANAGER
[export] typedef struct
#else
typedef struct
#endif
{
   LoopConfigurations LoopConfiguration;
   ControlLoopConfigurations ControlLoopConfiguration;
   CommandProfilerSelect CommandProfilerSelection;
   SourceModifierSelect SourceModifierSelection;
   LoopOffsetSourceSelect LoopOffsetSourceSelection;
   CommandSourceControls CommandSourceControl;
   ActiveModeStatuses ActiveModeStatus;
   ActiveConfigurationStatuses GainSet;
   ActiveConfigurationStatuses ProfilerParameterSet;
   ActiveConfigurationStatuses SourceModifierParameterSet;
}ActiveDriveMode;

#ifndef STATIC_DRIVE_MANAGER
[export] enum DriveUpdateOptions
#else
enum DriveUpdateOptions
#endif
{
   UseCurrentValues,
   ReadValuesFromTheDrive,
   WriteValuesToTheDrive,
   UseCurrentValuesAndRefresh,
   WriteValuesToTheDriveDoNotVerify,
};

/*=============================================================================
 ===== Motion parameters.
 ============================================================================*/

#ifndef STATIC_DRIVE_MANAGER
 [export] enum JogDirections
#else
enum JogDirections
#endif
{
    JogStop,
    JogPlus,
    JogMinus
 };

#ifndef STATIC_DRIVE_MANAGER
[export] enum EnterModes
#else
enum EnterModes
#endif
{
    EnterJoggingMode,
    EnterHomingMode,
    EnterMotionEngineMode,
    EnterPVTMode,
};

/*=============================================================================
 ===== Biquad parameters.
 ============================================================================*/

enum Biquads
{
    Bq_Filter1,
    Bq_Filter2,
    Bq_Filter3,
    Bq_Filter4,
    Bq_Filter5,
    Bq_Filter6,
    Bq_Count
};

enum BiquadStages
{
    BqSt_None,
    BqSt_VelocityFeedback,
    BqSt_PositionFeedback,
    BqSt_CommandSource,
    BqSt_CurrentInput,
    BqSt_VelocityInput,
    BqSt_PositionInput,
    BqSt_Count
};

#ifndef STATIC_DRIVE_MANAGER
[export] enum BiquadStates
#else
enum BiquadStates
#endif
{
   DisableBiquad,
   EnableBiquad
};

}