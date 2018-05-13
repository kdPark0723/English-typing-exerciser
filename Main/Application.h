#pragma once

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"

struct _Application
{
    // ���α׷� ���� ����
    int isRunning;

    // ���� ���� ����
    int progress;
    int numOfTypo;
    int accuracy;

    int currentTypingCount;
    int highestTypingCount;
    
    // �ð�
    clock_t startTime;
    clock_t finshTime;

    // ���� �ý��۵�
    struct _MessageSystem* messageSystem;
    struct _WindowSystem* windowSystem;
    struct _IOSystem* ioSystem;

    // ���α׷� ����
    int(*Run)(struct _Application* _this);
    // ���α׷� ������Ʈ
    int(*Update)(struct _Application* _this);
};

// ���丮 �Լ�
struct _Application* CreateApplication();

int _Application_Run(struct _Application* _this);
int _Application_Update(struct _Application* _this);

typedef struct _Application Application;