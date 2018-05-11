#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "MessageSystem.h"

typedef struct _Application
{
    int condition;

    MessageSystem* messageSystem;

    int* (*Run)();
}Application;

Application* CreatApplication();
int* _Run();

#endif