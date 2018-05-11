#ifndef __MESSAGESYSTEM_H_
#define __MESSAGESYSTEM_H_

#include "Application.h"

typedef int Message;

typedef struct _MessageSystem
{
    Application* own;

    Message message;

    Message(*AddMessage)(Message _message);
    Message(*CheckMessage)();
}MessageSystem;

MessageSystem* CreatMessageSystem(Application* _own);
Message _AddMessage(Message _message);
Message _CheckMessage();

#endif

