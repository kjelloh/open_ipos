//---------------------------------------------------------------------------

#ifndef APIFiniteStateMachineH
#define APIFiniteStateMachineH
//---------------------------------------------------------------------------
#include <memory> // std::unique_ptr
#include <map>
#include "iPOSApiImpl.h"
//---------------------------------------------------------------------------

struct E_ipos_Init {
//    E_ipos_Init(HWND Handle,unsigned int Message,TOnEvent Callback)
//        : m_Handle(Handle),m_Message(Message),m_Callback(Callback) {}
    HWND m_Handle;
    unsigned int m_Message;
    TOnEvent m_Callback;
};

struct E_ipos_Conf {
    std::string sConfigString;
};

struct E_ipos_Read {
    unsigned char *pData;
    int MaxLen;
    int *pDataLen;
};

struct E_ipos_Close {
};

class c_APIFSM {
public:

    c_APIFSM();
    ~c_APIFSM();

    template <typename Event>
    int actOnEvent(const Event& event) {
        // Not yet implemented
        return 0;
    }

private:
    struct impl;
    std::unique_ptr<impl> pimpl;
};

typedef std::map<int,c_APIFSM> c_APIFSMs;

#endif
