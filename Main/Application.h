#ifndef __Application_H_
#define __Application_H_

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"

struct _Application
{
    // 프로그램 실행 여부
    int isRunning;

    // 각종 측정 값들
    int progress;
    int numOfTypo;
    int accuracy;

    int currentTypingCount;
    int highestTypingCount;
    
    // 시간
    clock_t startTime;
    clock_t finshTime;

    // 각종 시스템들
    struct _MessageSystem* messageSystem;
    struct _WindowSystem* windowSystem;
    struct _IOSystem* ioSystem;

    // 프로그램 실행
    int(*Run)(struct _Application* _this);
    // 프로그램 업데이트
    int(*Update)(struct _Application* _this);
};

// 펙토리 함수
struct _Application* CreateApplication();
int DestroyApplication(struct _Application* _app);

int _Application_Run(struct _Application* _this);

int _Application_InitWindow_Update(struct _Application* _this);
int _Application_SeatPracticeWindow_Update(struct _Application* _this);
int _Application_WordPracticeWindow_Update(struct _Application* _this);
int _Application_ShortSentencePracticeWindow_Update(struct _Application* _this);

typedef struct _Application Application;

#endif