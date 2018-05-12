#pragma once

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"

typedef struct _Application
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
    MessageSystem* messageSystem;
    WindowSystem* windowSystem;
    IOSystem* ioSystem;

    // ���α׷� ����
    int(*Run)(struct _Application* _this);
    // ���α׷� ������Ʈ
    int(*Update)(struct _Application* _this);
} Application;

// ���丮 �Լ�
Application* CreateApplication();

int _Application_Run(Application* _this);
int _Application_Update(Application* _this);