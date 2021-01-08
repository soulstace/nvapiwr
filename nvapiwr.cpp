// nvapiwr.cpp : Defines the exported functions for the DLL application.
//


#include "stdafx.h"
#include "nvapiwr.h"

#include <iostream>
#include <cstdlib>

//using namespace std;


// This is an example of an exported variable
//NVAPIWR_API int nnvapiwr=0;

//This is an example of an exported function.
NVAPIWR_API NvAPI_Status fnnvapiwr(NvU32 settingId, NvU32 currentValue)
{

	//int i = 0;
	//unsigned long cnt;

	NvAPI_Status status;
	NvDisplayHandle hDisplay_a[NVAPI_MAX_PHYSICAL_GPUS * 2] = {0};
	//NvPhysicalGpuHandle nvGPUHandle;
	//-----------------------------------------------------

	status = NvAPI_Initialize();
	if (status != NVAPI_OK)
	{
		NvAPI_ShortString string;
		NvAPI_GetErrorMessage(status, string);
		//printf("NVAPI NvAPI_Initialize: %s\n", string);
		return NVAPI_ERROR;
	}

	////-----------------------------------------------------

	//NV_DISPLAY_DRIVER_VERSION version = {0};
	//version.version = NV_DISPLAY_DRIVER_VERSION_VER;
	//status = NvAPI_GetDisplayDriverVersion(NVAPI_DEFAULT_HANDLE, &version);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	//printf("NVAPI NvAPI_GetDisplayDriverVersion: %s\n", string);
	//	return NVAPI_ERROR;
	//}
	//else
	//{	
	//	printf("NVAPI Version: %u\n",version.drvVersion);
	//}

	//status = NvAPI_EnumNvidiaDisplayHandle(i, &hDisplay_a[i]);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	//printf("NVAPI NvAPI_EnumNvidiaDisplayHandle: %s\n", string);
	//	return NVAPI_ERROR;
	//}

	////-----------------------------------------------------

	//status = NvAPI_GetPhysicalGPUsFromDisplay(hDisplay_a[0], &nvGPUHandle, &cnt);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	//printf("NVAPI NvAPI_GetPhysicalGPUsFromDisplay: %s\n", string);
	//	return NVAPI_ERROR;
	//}

	//-----------------------------------------------------


	//NV_GPU_THERMAL_SETTINGS set = {0};
	//set.version = NV_GPU_THERMAL_SETTINGS_VER;
	//set.count = 0;
	//set.sensor[0].controller = NVAPI_THERMAL_CONTROLLER_UNKNOWN;
	//set.sensor[0].target = NVAPI_THERMAL_TARGET_GPU;

	//status = NvAPI_GPU_GetThermalSettings(nvGPUHandle, 0 ,&set);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	//printf("NVAPI NvAPI_GPU_GetThermalSettings: %s\n", string);
	//	return NVAPI_ERROR;
	//}
	//else 
	//{
	//	//printf("NVAPI Current Temp: %u C\n",set.sensor[0].currentTemp);
	//	//printf("NVAPI GPU Handle: %u\n",nvGPUHandle);
	//}

	NvDRSSessionHandle hSession = 0;
	status = NvAPI_DRS_CreateSession(&hSession);
	status = NvAPI_DRS_LoadSettings(hSession);
	NvDRSProfileHandle hProfile = 0;
	status = NvAPI_DRS_GetBaseProfile(hSession, &hProfile);
	
	NVDRS_SETTING drsSetting = {0};
	drsSetting.version = NVDRS_SETTING_VER;
	drsSetting.settingId = settingId;
	drsSetting.settingType = NVDRS_DWORD_TYPE;
	drsSetting.u32CurrentValue = currentValue;
	status = NvAPI_DRS_SetSetting(hSession, hProfile, &drsSetting);

	//printf("version: %u\n",drsSetting.version);
	//printf("settingName: %u\n",drsSetting.settingName);
	//printf("settingId: %u\n",drsSetting.settingId);
	//printf("settingType: %u\n",drsSetting.settingType);
	//printf("settingLocation: %u\n",drsSetting.settingLocation);
	//printf("isCurrentPredefined: %u\n",drsSetting.isCurrentPredefined);
	//printf("isPredefinedValid: %u\n",drsSetting.isPredefinedValid);

	//printf("u32PredefinedValue: %u\n",drsSetting.u32PredefinedValue);
	//printf("binaryPredefinedValue: %u\n",drsSetting.binaryPredefinedValue);
	//printf("wszPredefinedValue: %u\n",drsSetting.wszPredefinedValue);
	//printf("u32CurrentValue: %u\n",drsSetting.u32CurrentValue);
	//printf("binaryCurrentValue: %u\n",drsSetting.binaryCurrentValue);
	//printf("binaryPredefinedValue: %u\n",drsSetting.binaryPredefinedValue);
	//printf("wszCurrentValue: %u\n",drsSetting.wszCurrentValue);

	status = NvAPI_DRS_SaveSettings(hSession);
	status = NvAPI_DRS_DestroySession(hSession);
	hSession = 0;

	//system("PAUSE");
	//Then you can use provided API functions to query the # of logical and physical GPUs:


	//// enumerate logical gpus
	//status = NvAPI_EnumLogicalGPUs(logicalGPUs, &logicalGPUCount);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	printf("NVAPI Error: %s\n", string);
	//	return false;
	//}
	//// enumerate physical gpus
	//status = NvAPI_EnumPhysicalGPUs(physicalGPUs, &physicalGPUCount);
	//if (status != NVAPI_OK)
	//{
	//	NvAPI_ShortString string;
	//	NvAPI_GetErrorMessage(status, string);
	//	printf("NVAPI Error: %s\n", string);
	//	return false;
	//}

	status = NvAPI_Unload();
	return NVAPI_OK;
}

//extern "C" __declspec(dllexport) NvAPI_Status __stdcall GetChipSetInfo(NV_CHIPSET_INFO *pChipSetInfo)
//{
//	return NvAPI_SYS_GetChipSetInfo(pChipSetInfo);
//}

//extern "C" __declspec(dllexport) NvAPI_Status __stdcall GetInterfaceVersionString(NvAPI_ShortString szDesc)
//{
//	return NvAPI_GetInterfaceVersionString(szDesc);
//}

// This is the constructor of a class that has been exported.
// see nvapiwr.h for the class definition
//Cnvapiwr::Cnvapiwr()
//{
//	return;
//}

//NVAPIWR_API void NvAPI_Initialize()
//{
//	NvAPI_Initialize();
//}
//NVAPIWR_API void NvAPI_GetDisplayDriverVersion()
//{
//	NvAPI_GetDisplayDriverVersion();
//}