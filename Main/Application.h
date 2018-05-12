#pragma once

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"

typedef struct _Application
{
    // 프로그램 실행 여부
    int isRunning;

    // 각종 측정 값들
    int progress;
    int numOfTypo;
    int accuracy;

    int currentTypingCount;
    int highestTypingCount;

    // 출력용 타입 변환
    char* p_progress;
    char* p_numOfTypo;
    char* p_accuracy;

    char* p_currentTypingCount;
    char* p_highestTypingCount;
    
    // 시간
    clock_t startTime;
    clock_t finshTime;

    // 각종 시스템들
    MessageSystem* messageSystem;
    WindowSystem* windowSystem;
    IOSystem* ioSystem;

    // 프로그램 실행
    int(*Run)(struct _Application* _this);
    // 프로그램 업데이트
    int(*Update)(struct _Application* _this);
} Application;

// 펙토리 함수
Application* CreateApplication();

int _Application_Run(Application* _this);
int _Application_Update(Application* _this);