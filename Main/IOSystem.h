#pragma once

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000

typedef struct _IOSystem
{
    Application* own;

    char* output;
    char input[INPUT_MAX];
    int count;

    int(*Get)(struct _IOSystem* _this);
} IOSystem;

IOSystem* CreateIOSystem(Application* _own);

int _IOSystem_Get(IOSystem* _this);