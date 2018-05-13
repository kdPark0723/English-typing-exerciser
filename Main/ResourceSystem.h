#ifndef __RESOURCESYSTEM_H__
#define __RESOURCESYSTEM_H__

#include <stdio.h>
#include <string.h>

#include "Application.h"

struct _Resource
{
    // ���� �� �ִ� �ִ� ���ڿ��� ��
    int size;
    //����
    char* buffer[100];

    int(*Get)(struct _Resource* _this);
};

struct _ResourceSystem
{
    // ���� ���α׷�
    struct _Application* own;
    struct _Resource* resource[5];

    int(*Get)(struct _ResourceSystem* _this, int _type);
};

// ���丮 �Լ�
struct _Resource* CreateResource(int _size, char* _fileName);
int DestroyResource(struct _Resource* _resource);

struct _ResourceSystem* CreateResourceSystem(struct _Application* _own);
int DestroyResourceSystem(struct _ResourceSystem* _resourceSystem);

char* _Resource_Get(struct _Resource* _this);
char* _ResourceSystem_Get(struct _ResourceSystem* _this, int _type);

typedef struct _Resource Resource;
typedef struct _ResourceSystem ResourceSystem;

#endif