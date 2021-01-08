// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NVAPIWR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NVAPIWR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NVAPIWR_EXPORTS
#define NVAPIWR_API extern "C" __declspec(dllexport)
#else
#define NVAPIWR_API __declspec(dllimport)
#endif

//// This class is exported from the nvapiwr.dll
//class NVAPIWR_API Cnvapiwr {
//public:
//	Cnvapiwr(void);
//	// TODO: add your methods here.
//};

//extern NVAPIWR_API int nnvapiwr;

NVAPIWR_API NvAPI_Status fnnvapiwr(NvU32 settingId, NvU32 currentValue);

//extern "C" NVAPIWR_API void NvAPI_Initialize();
//extern "C" __declspec(dllexport) NvAPI_Status __stdcall GetChipSetInfo(NV_CHIPSET_INFO *pChipSetInfo);
//extern "C" __declspec(dllexport) NvAPI_Status __stdcall GetInterfaceVersionString(NvAPI_ShortString szDesc);