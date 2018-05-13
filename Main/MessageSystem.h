#ifndef __MessageSystem_H_
#define __MessageSystem_H_

#include <stdlib.h>

#include "Application.h"
#include "Message.h"

struct _MessageSystem
{
    // 소유 프로그램
    struct _Application* own;

    // 메세지 저장 공간
    struct _Message message[MESSAGE_MAX];
    // 최근 메세지 위치
    int index;

    // 메세지 추가
    int(*AddMessage)(struct _MessageSystem* _this, struct _Message _message);
    // 메세지 확인
    int(*CheckMessage)(struct _MessageSystem* _this);
};

// 펙토리 함수
struct _MessageSystem* CreateMessageSystem(struct _Application* _own);
int DestroyMessageSystem(struct _MessageSystem* _messageSystem);

int _MessageSystem_AddMessage(struct _MessageSystem* _this, struct _Message _message);
int _MessageSystem_CheckMessage(struct _MessageSystem* _this);

typedef struct _MessageSystem MessageSystem;

#endif
