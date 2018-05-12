#pragma once

#include <stdlib.h>

#include "Application.h"

#define MESSAGE_MAX 10

#define MESSAGE_EXIT 0
#define MESSAGE_DEL 1
#define MESSAGE_ENTER 2
#define MESSAGE_CHANGE 3
#define MESSAGE_INPUT 4

typedef struct _Message
{
    // 메세지 이름
    int name;

    // 내용
    char content;
} Message;

typedef struct _MessageSystem
{
    // 소유 프로그램
    Application* own;

    // 메세지 저장 공간
    Message message[MESSAGE_MAX];
    // 최근 메세지 위치
    int index;

    // 메세지 추가
    int(*AddMessage)(struct _MessageSystem* _this, Message _message);
    // 메세지 확인
    int(*CheckMessage)(struct _MessageSystem* _this);
} MessageSystem;

// 펙토리 함수
MessageSystem* CreateMessageSystem(Application* _own);

int _MessageSystem_AddMessage(MessageSystem* _this, Message _message);
int _MessageSystem_CheckMessage(MessageSystem* _this);


