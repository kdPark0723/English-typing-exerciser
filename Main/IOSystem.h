#pragma once

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000

typedef struct _IOSystem
{
    // 소유 프로그램
    Application* own;

    // 출력할 값 - 윈도우 시스템에서 참고함
    char* output;
    // 입력된 값
    char input[INPUT_MAX];
    // 입력된 값의 수
    int count;

    // 키보드 입력값 받기
    int(*Get)(struct _IOSystem* _this);
    // 입력 출력 버퍼 초기화
    int(*Init)(struct _IOSystem* _this);
} IOSystem;

IOSystem* CreateIOSystem(Application* _own);

int _IOSystem_Get(IOSystem* _this);
int _IOSystem_Init(IOSystem* _this);