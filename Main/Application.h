#pragma once

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"

typedef struct _Application
{
    int isRunning;

    int progress;
    int numOfTypo;
    int accuracy;

    clock_t startTime;
    clock_t finshTime;

    MessageSystem* messageSystem;
    WindowSystem* windowSystem;
    IOSystem* ioSystem;

    int(*Run)(struct _Application* _this);
    int(*Update)(struct _Application* _this);
} Application;

Application* CreateApplication();

int _Application_Run(Application* _this);
int _Application_Update(Application* _this);