//---------------------------------------------------------------------------
#define IPOS_API_EXPORTS
#include "iPOSApiImpl.h"
#undef IPOS_API_EXPORTS
//---------------------------------------------------------------------------
#include "ZeposApiCore.h"
#include "APIFiniteStateMachine.h"
//---------------------------------------------------------------------------

// ZeposApiCore m_Core;
c_APIFSMs api_fsms;

// BEGIN iPOS API

int _stdcall ipos_Init(HWND Handle,unsigned int Message,TOnEvent Callback, int Id) {
    return api_fsms[Id].actOnEvent(E_ipos_Init{Handle,Message,Callback});
}

int _stdcall ipos_Conf(char* szConfigString, int Id) {
//    szConfigString:
//      null terminated ascii character string containing property values to configure the api.
//        * The string shall be formatted as
//          <property> <separator> <property> <separator> <property>
//        * Each property shall be formatted as
//          <property name> = <property value>.
//          For example “TERMINAL_IP_AND_PORT =192.168.0.7:47”.
//        * <Separator> shall be one of or a combination of control chars
//          of Tab (Decimal value 09), Carrige return (Decimal value 13) or line feed (decimal 10).
//
//      Id: Access id of terminal
//
//      Reserved property names are (property names shall not be case sensitive):
//      Property name         Value description
//      TERMINAL_IP_AND_PORT  The value shall define the IP and port of the terminal
//                            in the form <IP>:<Port>.
//                            For example “192.168.0.3:47”. Value
//
//      COM_PORT              The value shall define the RS232-port of the terminal
    return api_fsms[Id].actOnEvent(E_ipos_Conf{szConfigString});
}
int _stdcall ipos_Write(unsigned char *Data, int DataLen, int Id) {
    return 0;
}
int _stdcall ipos_Read(unsigned char *Data, int MaxLen, int *DataLen, int Id) {
    return api_fsms[Id].actOnEvent(E_ipos_Read{Data,MaxLen,DataLen});
}
int _stdcall ipos_Close(int Id) {
    return api_fsms[Id].actOnEvent(E_ipos_Close{});
}

template <typename S,size_t N>
void safe_string_copy(const std::string& s,S (&sz)[N]) {
    for (int i = 0; i < N; ++i) {
        sz[i] = (i < s.length())?s[i]:0;
    }
}

int _stdcall ipos_GetVersion(IPOS_VERSIONINFO* versionInfo) {
//    DWORD DLLVersionMajor;
//    DWORD DLLVersionMinor;
//    DWORD IsDebugVersion;
//    char Name[64];
//    char Manufacturer[64];
//    char Copyright[64];

    versionInfo->DLLVersionMajor = 1;
    versionInfo->DLLVersionMinor = 0;
    versionInfo->IsDebugVersion = false;
    // Todo 160212, Consider to apply CPP Core Guidlines for string copy (https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
    //              E.g., https://github.com/Microsoft/GSL/blob/master/include/string_span.h?
    safe_string_copy(std::string("zepos_api"),versionInfo->Name);
    safe_string_copy(std::string("Swedbank AB"),versionInfo->Manufacturer);
    safe_string_copy(std::string("Swedbank AB"),versionInfo->Copyright);

    return 0;
}

// END iPOS API
