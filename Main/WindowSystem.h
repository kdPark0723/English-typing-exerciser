#ifndef __WINDOWSYSTEM_H_
#define __WINDOWSYSTEM_H_

#include "Application.h"

typedef struct _WindowSystem
{
    Application* own;

    int(*Clear)();
    int(*Draw)();
}WindowSystem;

WindowSystem* CreatWindowSystem(Application* _own);


#endif
