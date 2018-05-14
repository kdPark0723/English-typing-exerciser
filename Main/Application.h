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
    // ���α׷� ���� ����
    int isRunning;

    // ���� ���� ����
    int progress;
    int numOfTypo;
    int accuracy;

    int currentTypingCount;
    int highestTypingCount;

    // ������� �Է��� ����
    int count;

    // �ð�
    clock_t startTime;
    clock_t finshTime;

    // ���� �ý��۵�
    struct _MessageSystem* messageSystem;
    struct _WindowSystem* windowSystem;
    struct _IOSystem* ioSystem;
    struct _ResourceSystem* resourceSystem;

    // ���α׷� ����
    int(*Run)(struct _Application* _this);
    // Ű���� �Է�
    int(*InputKeyboard)(struct _Application* _this, char _input);
    // ����Ű�� �Է� �Ǿ��� �� ����
    int(*InputKeyboardEnter)(struct _Application* _this);
    // �������̽�Ű�� �Է� �Ǿ��� �� ����
    int(*InputKeyboardBackSpace)(struct _Application* _this);
};

// ���丮 �Լ�
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