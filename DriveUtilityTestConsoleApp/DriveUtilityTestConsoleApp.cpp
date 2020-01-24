// DriveUtilityTestConsoleApp.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <thread>
#include "../DriveUtility/DriveUtility.h"

using namespace std::chrono_literals;

int main()
{
   CommunicationSettings comm_settings;
   comm_settings.FieldBusType = CommunicationSettings::RS_232;
   comm_settings.communication_port = "COM4";
   comm_settings.baud_rate = "115200";
   comm_settings.address = 63;

   int result = InitializeCommunicationPort(comm_settings);

//   std::string save_project_file_name = "SavedCR362EEB.adf";
//   std::remove(save_project_file_name.c_str());
//   result = SaveProjectFileFromDrive(save_project_file_name);

//   result = WriteProjectToDrive(save_project_file_name);
   const std::string firmware_file = "c:\\AFFfiles\\DPRANIE-7.4.0.9.aff";
   FIRMWARE_BURN_CODES error_code = NO_ERROR;
   result = DownloadFirmwareFile(firmware_file, error_code);

   bool wait = true;
   unsigned int firmware_burn_progress = 0;

   while(wait)
   {
      std::this_thread::sleep_for(2s);
      GetFirmwareBurnProgress(firmware_burn_progress, error_code);
      if(error_code != 0 ||
         firmware_burn_progress >= 100)
      {
         wait = false;
         std::cout << "firmware burn error = " << error_code << std::endl;
      }
      std::cout << "firmware burn progress = " << firmware_burn_progress << std::endl;
   }
   
   std::cout << "firmware burn completed!" << firmware_burn_progress << std::endl;
   
   CloseCommunicationPort();

   std::cout << "Last error string = " << GetLastErrorString() << std::endl;

   return 0;
}

