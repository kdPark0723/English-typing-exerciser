#ifndef __IOSYSTEM_H__
#define __IOSYSTEM_H__

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000

struct _IOSystem
{
    // 소유 프로그램
    struct _Application* own;

    // 출력할 값 - 윈도우 시스템에서 참고함
    char* output;
    // 입력된 값
    char input[INPUT_MAX];
    // 입력된 값의 수
    int count;
    // 입력될수 있는 문자의 수
    int size;

    // 키보드 입력값 받기
    int(*Update)(struct _IOSystem* _this);
    // 입력 버퍼 초기화
    int(*InputBufferClear)(struct _IOSystem* _this);
    // 출력 버퍼 초기화
    int(*OutputBufferClear)(struct _IOSystem* _this);
    // 출력 버퍼 초기화
    int(*SetOutput)(struct _IOSystem* _this, char* _buffer);
};

struct _IOSystem* CreateIOSystem(struct _Application* _own);
int DestroyIOSystem(struct _IOSystem* _ioSystem);

int _IOSystem_Update(struct _IOSystem* _this);
int _IOSystem_InputBufferClear(struct _IOSystem* _this);
int _IOSystem_OutputBufferClear(struct _IOSystem* _this);

int _IOSystem_SetOutput(struct _IOSystem* _this, char* _buffer);

typedef struct _IOSystem IOSystem;

#endif