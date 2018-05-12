#pragma once

#include <stdio.h>

#include "Application.h"

typedef struct _Input
{
    char content;

    struct _Input* pre;
    struct _Input* next;
} Input;

typedef struct _IOSystem
{
    Application* own;

    char* output;
    Input* input;
    int count;

    int(*Get)(struct _IOSystem* _this);
} IOSystem;

IOSystem* CreateIOSystem(Application* _own);
Input* CreateInput(char _content, Input* _pre);

int _IOSystem_Get(IOSystem* _this);