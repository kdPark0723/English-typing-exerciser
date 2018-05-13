#ifndef __RESOURCESYSTEM_H__
#define __RESOURCESYSTEM_H__

#include <stdio.h>
#include <string.h>

#include "Application.h"

struct _Resource
{
    // 읽을 수 있는 최대 문자열의 수
    int size;
    //버퍼
    char* buffer[100];

    int(*Get)(struct _Resource* _this);
};

struct _ResourceSystem
{
    // 소유 프로그램
    struct _Application* own;
    struct _Resource* resource[5];

    int(*Get)(struct _ResourceSystem* _this, int _type);
};

// 펙토리 함수
struct _Resource* CreateResource(int _size, char* _fileName);
int DestroyResource(struct _Resource* _resource);

struct _ResourceSystem* CreateResourceSystem(struct _Application* _own);
int DestroyResourceSystem(struct _ResourceSystem* _resourceSystem);

char* _Resource_Get(struct _Resource* _this);
char* _ResourceSystem_Get(struct _ResourceSystem* _this, int _type);

typedef struct _Resource Resource;
typedef struct _ResourceSystem ResourceSystem;

#endif