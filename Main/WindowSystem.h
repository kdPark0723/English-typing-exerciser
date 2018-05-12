#pragma once

#include "Application.h"
#include "Window.h"

typedef struct _WindowSystem
{
    Application* own;
    Window* windows;
    int type;

    int(*Clear)(struct _WindowSystem* _this);
    int(*Draw)(struct _WindowSystem* _this);
    int(*ChangeWindow)(struct _WindowSystem* _this, int _type);
} WindowSystem;

WindowSystem* CreateWindowSystem(Application* _own);

int _WindowSystem_Clear(WindowSystem* _this);
int _WindowSystem_Draw(WindowSystem* _this);
int _WindowSystem_ChangeWindow(WindowSystem* _this, int _type);

