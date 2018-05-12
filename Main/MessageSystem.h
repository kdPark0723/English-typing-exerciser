#pragma once

#include "Application.h"

#define MESSAGE_MAX 10

#define MESSAGE_EXIT 0
#define MESSAGE_DEL 1
#define MESSAGE_ENTER 2
#define MESSAGE_INPUT 3

typedef struct _Message
{
    int name;

    char content;
} Message;

typedef struct _MessageSystem
{
    Application* own;

    Message message[MESSAGE_MAX];
    int index;

    int(*AddMessage)(struct _MessageSystem* _this, Message _message);
    int(*CheckMessage)(struct _MessageSystem* _this);
} MessageSystem;

MessageSystem* CreateMessageSystem(Application* _own);

int _MessageSystem_AddMessage(MessageSystem* _this, Message _message);
int _MessageSystem_CheckMessage(MessageSystem* _this);


