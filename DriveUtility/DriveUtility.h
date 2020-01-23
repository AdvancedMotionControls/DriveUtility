#pragma once
#include <string>

struct CommunicationSettings
{
   enum FieldBusTypes
   {
      RS_232,
      RS_485,
      CAN,
      EtherNet,
      USB
   };

   FieldBusTypes FieldBusType;
   unsigned int address;
   std::string communication_port;
   std::string baud_rate;
};

enum FIRMWARE_BURN_CODES{
   NO_ERROR,
   INVALID_FILE,
   NOT_CONNECTED_TO_DRIVE,
   FILE_NAME_NOT_SET,
   UNABLE_TO_OPEN_FILE,
   NO_CONTROLBOARD_NAME,
   INVALID_FILE_TYPE,
   ALTERED_FILE_FORMAT,
   UNKNOWN_FILE_FORMAT,
   UNKNOWN_SEGMENT_TYPE,
   UNEXPECTED_END_OF_SEGMENT,
   UNEXPECTED_END_OF_FILE,
   SEGMENT_BOOTLOADER_REQ_NOT_MET,
   READING_SEGMENT_DATA,
   READING_BOOTLOADER_SEGMENT_DATA,
   READING_MAIN_SEGMENT_DATA,
   READING_DRIVER_SEGMENT_DATA,
   READING_FPGA_SEGMENT_DATA,
   READING_CORE_SEGMENT_DATA,
   SOFTWARE_VERSION_MISMATCH,
   MISSING_BOOTLOADER_SEGMENT,
   INCOMPATIBLE_BOOTLOADERS,
   NO_COMPATIBLE_MAIN_TO_CONTROLBOARD,
   NO_COMPATIBLE_DRIVER_TO_CONTROLBOARD,
   NO_COMPATIBLE_FPGA_TO_CONTROLBOARD,
   NO_COMPATIBLE_CORE_TO_CONTROLBOARD,
   NO_COMPATIBLE_BOOTLOADER_TO_CONTROLBOARD,
   FILE_NOT_COMPATIBLE_TO_CONTROLBOARD,
   INVALID_OPERATION_MODE,
   UNABLE_TO_DISABLE_DRIVE,
   UNABLE_TO_CHANGE_DRIVE_MODE,
   UNABLE_TO_SEND_CHANGEDRIVEMODE_MESSAGE,
   UNABLE_ERASE_NON_VOLATILE_MEMORY,
   UNABLE_COMPLETE_FIRMWARE_BURN,
   CHECKSUM_FAILED,
   NO_COMPATIBLE_DOWNGRADE_SEGMENT,
   UNABLE_TO_PROCESS_FILE,
   UNABLE_TO_RECONNECT,
   UNABLE_TO_GET_FLASHKEY,
   UNABLE_TO_SEND_GET_FLASHKEY_MESSAGE,
   LOST_COMMUNICATION,
   NO_RESPONSE_ON_REBOOT_REQUEST,
   UNABLE_TO_SAVE_PROJECT,
   CONNECTED_IN_BOOT_MODE,
   COULD_NOT_WRITE_PROJECT,
   MISSING_CURRENT_FIRMWARE_FILE,
   MAX_FIRMWARE_CODE
};

// Initializes the communication port with the settings.
// Must be call first.
// Return values:
//  1 -> Communication port initialized.
// -1 -> Could not change field bus.
// -2 -> Could not set the communication port.
// -3 -> Could not set the baud rate.
// -4 -> Could not communication with a drive at these settings.
//
int InitializeCommunicationPort(CommunicationSettings CommSettings);

// Closes the communication port.
// Must be called before exiting the application.
// Return values:
//  1 -> Communication port closed.
// -1 -> Closed the communication port before all messages were sent to the drive.
//
int CloseCommunicationPort();

// Writes the project files to the drive.
// Return values:
//  1 -> Project was written to the drive.
// -1 -> Communication port not initialized.
// -2 -> Not connected to a drive.
// -3 -> Could not gain exclusive write access.
// -4 -> Could not open project file.
// -5 -> Could not convert user units.
// -6 -> The drive's firmware version is no supported.
// -7 -> Project file is not compatible with drive. The project file's feedback type does not match the drive's feedback type.
// -8 -> Project file's control name does not match the drive's control board name.
// -9 -> Project file's power board name does not match the drive's power board name.
// -10 -> The drive's control board name is empty.
// -11 -> The drive's power board name is empty.
//
int WriteProjectToDrive(std::string ProjectFileName);

// Save the project file from the drive into the file.
// Return values:
//  1 -> Project file saved.
// -1 -> Communication port not initialized.
// -2 -> Parameter failed CRC.
// -3 -> The drive's firmware version is not supported.
// 
int SaveProjectFileFromDrive(std::string ProjectFileName);

// Starts the firmware download procedure.
// Return values:
//  1 -> Firmware file download has started.
// -1 -> Communication port not initialized.
// -2 -> Could not get exclusive write access.
// -3 -> Could not start firmware file download. Check ErrorCode for cause.
//
int DownloadFirmwareFile(const std::string& FirmwareFile, FIRMWARE_BURN_CODES& ErrorCode);

// Returns the firmware burn progress. The firmware burn progress is only the firmware burn progress.
// There is some time before the progress changes when the memory is being erased. If progress is zero and ErrorCode is NoError then memory is being erased.
// When progress get to 100 the burn process is complete.
// Return values:
//  1 -> No errors.
// -1 -> Communication port not initialized.
// -2 -> Could not burn firmware. Check ErrorCode for cause.
//
int GetFirmwareBurnProgress(unsigned int& Progress, FIRMWARE_BURN_CODES& ErrorCode);

// Gets the last error string.
std::string GetLastErrorString();