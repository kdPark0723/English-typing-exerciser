#ifndef __MessageSystem_H_
#define __MessageSystem_H_

#include <stdlib.h>

#include "Application.h"
#include "Message.h"

struct _MessageSystem
{
    // ���� ���α׷�
    struct _Application* own;

    // �޼��� ���� ����
    struct _Message message[MESSAGE_MAX];
    // �ֱ� �޼��� ��ġ
    int index;

    // �޼��� �߰�
    int(*AddMessage)(struct _MessageSystem* _this, struct _Message _message);
    // �޼��� Ȯ��
    int(*CheckMessage)(struct _MessageSystem* _this);
};

// ���丮 �Լ�
struct _MessageSystem* CreateMessageSystem(struct _Application* _own);
int DestroyMessageSystem(struct _MessageSystem* _messageSystem);

int _MessageSystem_AddMessage(struct _MessageSystem* _this, struct _Message _message);
int _MessageSystem_CheckMessage(struct _MessageSystem* _this);

typedef struct _MessageSystem MessageSystem;

#endif
