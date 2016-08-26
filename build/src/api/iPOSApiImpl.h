//---------------------------------------------------------------------------

#ifndef iPOSApiImplH
#define iPOSApiImplH
//---------------------------------------------------------------------------
#include <windows.h> // HWND...
//---------------------------------------------------------------------------
/**
  * Defines and implements the iPOS API
  */

/** Design inspired by https://msdn.microsoft.com/en-us/library/ms235636.aspx
  * to enable this header file to be used to define both external and internal
  * access to the DLL Interface.
  */
#ifdef IPOS_API_EXPORTS
    #define IPOS_API extern "C" __declspec(dllexport)  // Export version of IPOS_API item
#else
    #define IPOS_API extern "C" __declspec(dllimport) // Import version of IPOS_API item
#endif

// Also see http://stackoverflow.com/questions/20613890/what-is-the-number-in-the-dumpbin-exports-output
// BEGIN iPOS API

/*
	MSVS will decorate these member names as 

	1    0 00002BCB _ipos_Close@4 = @ILT+7110(_ipos_Close@4)
	2    1 00001721 _ipos_Conf@8 = @ILT+1820(_ipos_Conf@8)
	3    2 000016A4 _ipos_GetVersion@4 = @ILT+1695(_ipos_GetVersion@4)
	4    3 00003477 _ipos_Init@16 = @ILT+9330(_ipos_Init@16)
	5    4 00002C93 _ipos_Read@16 = @ILT+7310(_ipos_Read@16)
	6    5 00001668 _ipos_Write@12 = @ILT+1635(_ipos_Write@12)

*/

typedef int (_stdcall *TOnEvent) (unsigned int wParam, unsigned int lParam);
IPOS_API int _stdcall ipos_Init(HWND Handle,unsigned int Message,TOnEvent Callback, int Id);
IPOS_API int _stdcall ipos_Conf(char* szConfigString, int Id);
IPOS_API int _stdcall ipos_Write(unsigned char *Data, int DataLen, int Id);
IPOS_API int _stdcall ipos_Read(unsigned char *Data, int MaxLen, int *DataLen, int Id);
IPOS_API int _stdcall ipos_Close(int Id);
typedef struct {
    DWORD DLLVersionMajor;
    DWORD DLLVersionMinor;
    DWORD IsDebugVersion;
    char Name[64];
    char Manufacturer[64];
    char Copyright[64];
} IPOS_VERSIONINFO;
IPOS_API int _stdcall ipos_GetVersion(IPOS_VERSIONINFO* versionInfo);

// END iPOS API

#endif
