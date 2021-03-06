#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <time.h>
#include <stdlib.h>

#include "MessageSystem.h"
#include "WindowSystem.h"
#include "IOSystem.h"
#include "ResourceSystem.h"

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

    // 현재까지 입력한 개수
    int count;

    // 시간
    clock_t startTime;
    clock_t finshTime;

    // 각종 시스템들
    struct _MessageSystem* messageSystem;
    struct _WindowSystem* windowSystem;
    struct _IOSystem* ioSystem;
    struct _ResourceSystem* resourceSystem;

    // 프로그램 실행
    int(*Run)(struct _Application* _this);
    // 키보드 입력
    int(*InputKeyboard)(struct _Application* _this, char _input);
    // 엔터키가 입력 되었을 때 실행
    int(*InputKeyboardEnter)(struct _Application* _this);
    // 벡스페이스키가 입력 되었을 때 실행
    int(*InputKeyboardBackSpace)(struct _Application* _this);
};

// 펙토리 함수
struct _Application* CreateApplication();
int DestroyApplication(struct _Application* _app);

int _Application_Run(struct _Application* _this);

int _Application_InitWindow_InputKeyboard(struct _Application* _this, char _input);
int _Application_SeatPracticeWindow_InputKeyboard(struct _Application* _this, char _input);
int _Application_WordPracticeWindow_InputKeyboard(struct _Application* _this, char _input);
int _Application_ShortSentencePracticeWindow_InputKeyboard(struct _Application* _this, char _input);
int _Application_LongSentencePracticeWindow_InputKeyboard(struct _Application* _this, char _input);

int _Application_InitWindow_InputKeyboardEnter(struct _Application* _this);
int _Application_SeatPracticeWindow_InputKeyboardEnter(struct _Application* _this);
int _Application_WordPracticeWindow_InputKeyboardEnter(struct _Application* _this);
int _Application_ShortSentencePracticeWindow_InputKeyboardEnter(struct _Application* _this);
int _Application_LongSentencePracticeWindow_InputKeyboardEnter(struct _Application* _this);

int _Application_InitWindow_InputKeyboardBackSpace(struct _Application* _this);
int _Application_SeatPracticeWindow_InputKeyboardBackSpace(struct _Application* _this);
int _Application_WordPracticeWindow_InputKeyboardBackSpace(struct _Application* _this);
int _Application_ShortSentencePracticeWindow_InputKeyboardBackSpace(struct _Application* _this);
int _Application_LongSentencePracticeWindow_InputKeyboardBackSpace(struct _Application* _this);

typedef struct _Application Application;

#endif