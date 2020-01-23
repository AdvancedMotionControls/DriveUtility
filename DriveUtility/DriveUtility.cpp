#include "stdafx.h"
#include "DriveUtility.h"
#include "Windows.h"
#include <DriveUtility/DriveManagerLib.h>
#include <utility>

// Write project file
// Read project file
// Burn firmware
// Need progress of firmware burn
// Communication settings - could be a structure
// 

void* drive_manager_ptr = nullptr;
std::string error_str = "";

int InitializeCommunicationPort(CommunicationSettings CommSettings)
{
   if(drive_manager_ptr == nullptr)
   {
      drive_manager_ptr = CreateDriveManager();
   }

   if (GetConnectionStatus(drive_manager_ptr) == 1)
   {
      Disconnect(drive_manager_ptr);
   }

   DRIVE_MANAGER_COMMUNICATION_INTERFACES comm_interface = DRIVE_MANAGER_COMMUNICATION_INTERFACES::RS_232;

   switch (CommSettings.FieldBusType)
   {
   case CommunicationSettings::FieldBusTypes::RS_232:
   case CommunicationSettings::FieldBusTypes::RS_485:
      comm_interface = RS_232;
      break;
   case CommunicationSettings::CAN:
      comm_interface = CAN_KVASER;
      break;
   case CommunicationSettings::EtherNet:
      comm_interface = ETHERNET;
      break;
   case CommunicationSettings::USB:
      comm_interface = USB;
      break;

   }
   DRIVE_MANAGER_INTERFACE_ERRORS err = SetDriveCommunicationInterface(drive_manager_ptr, comm_interface);
   if(err != INTERFACE_OK)
   {
      return -1;
   }
   
   err = SetComPort(drive_manager_ptr, CommSettings.communication_port);
   if(err != INTERFACE_OK)
   {
      return -2;
   }

   SetDriveAddress(drive_manager_ptr, CommSettings.address);

   err = SetBaudRate(drive_manager_ptr, CommSettings.baud_rate);
   if (err != INTERFACE_OK)
   {
      return -3;
   }

   AttemptToConnect(drive_manager_ptr);

   if(GetConnectionStatus(drive_manager_ptr) != 1)
   {
      error_str = "Could not connect to drive.";
      DeleteDriveManager(drive_manager_ptr);
      drive_manager_ptr = nullptr;
      return -4;
   }

   return 1;
}

int WriteProjectToDrive(std::string ProjectFileName)
{
   if(drive_manager_ptr == nullptr)
   {
      error_str = "InitializeCommunicationPort has not been called.";
      return -1;
   }

   if(!GetConnectionStatus(drive_manager_ptr))
   {
      error_str = "Not connected to a drive. Call InitializeCommunicationPort.";
      return -2;
   }

   // Get write access.
   int exclusive_access_parameter_enum = 4521984;
   SetParameterValueInt(drive_manager_ptr, exclusive_access_parameter_enum, 0xFF);
   BOOL parameter_written = WriteParameterToDrive(drive_manager_ptr, exclusive_access_parameter_enum);
   if(!parameter_written)
   {
      return -3;
   }

   int result = OpenProject(drive_manager_ptr, ProjectFileName);

   if(result != 1)
   {
      error_str = "Could not open project file.";
      return -4;
   }

   result = WriteProjectToDrive(drive_manager_ptr);
   if(result == 8) // Could not convert user units.
   {
      return -5;
   }

   if(result == 10) // Drive firmware not supported.
   {
      return -6;
   }

   if(result == 11) // Project file is not compatible with drive. The project file's feedback type does not match the drive's feedback type.
   {
      return -7;
   }

   if(result == 12) // Project file's control name does not match the drive's control board name.
   {
      return -8;
   }

   if(result == 13) // Project file's power board name does not match the drive's power board name.
   {
      return -9;
   }

   if(result == 14) // The drive's control board name is empty.
   {
      return -10;
   }

   if(result == 15) // The drive's power board name is empty.
   {
      return - 11;
   }

   return 1;
}

int SaveProjectFileFromDrive(std::string ProjectFileName)
{
   if(drive_manager_ptr == nullptr)
   {
      error_str = "InitializeCommunicationPort has not been called.";
      return -1;
   }
   int result = ReadProjectFromDrive(drive_manager_ptr);
   if(result == 3) // Parameter failed CRC.
   {
      return -2;
   }

   if(result == 10) // The drive's firmware version is not supported.
   {
      return -3;
   }

   SaveProject(drive_manager_ptr, ProjectFileName, true);

   return 1;
}

int DownloadFirmwareFile(const std::string& FirmwareFile, FIRMWARE_BURN_CODES& ErrorCode)
{
   if(drive_manager_ptr == nullptr)
   {
      error_str = "InitializeCommunicationPort has not been called.";
      return -1;
   }

   // Get write access.
   int exclusive_access_parameter_enum = 4521984;
   SetParameterValueInt(drive_manager_ptr, exclusive_access_parameter_enum, 0xFF);
   auto param_written = WriteParameterToDrive(drive_manager_ptr, exclusive_access_parameter_enum);
   if(!param_written) 
   {
      return -2;
   }
   BURN_FIRMWARE_CODES burn_error_code = ERRORS_NO_ERROR;
   DRIVE_MANAGER_INTERFACE_ERRORS interface_error = BurnFirmwareFile(drive_manager_ptr, FirmwareFile, FirmwareFile, 3, &burn_error_code);
   ErrorCode = static_cast<FIRMWARE_BURN_CODES>(burn_error_code);
   if(burn_error_code != ERRORS_NO_ERROR)
   {
      error_str = "Could not burn firmware file";
      return -3;
   }

   return (interface_error == INTERFACE_OK);
}

int GetFirmwareBurnProgress(unsigned int& Progress, FIRMWARE_BURN_CODES& ErrorCode)
{
   if(drive_manager_ptr == nullptr)
   {
      error_str = "InitializeCommunicationPort has not been called.";
      return -1;
   }

   int error_code = 0;
   std::string error_string;

   Progress = GetFirmwareBurnProgress(drive_manager_ptr, &error_code, &error_string);

   ErrorCode = static_cast<FIRMWARE_BURN_CODES>(error_code);
   if (ErrorCode != NO_ERROR)
   {
      error_str = error_string;
      return -2;
   }

   return 1;
}

int CloseCommunicationPort()
{
   if (drive_manager_ptr != nullptr)
   {
      int disconnected = Disconnect(drive_manager_ptr);
      DeleteDriveManager(drive_manager_ptr);
      drive_manager_ptr = nullptr;
      if(!disconnected)
      {
         return -1;
      }
   }
   error_str.clear();
   return 1;
}

std::string GetLastErrorString()
{
   return error_str;
}