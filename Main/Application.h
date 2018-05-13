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
    // ���α׷� ����
    int(*Check)(struct _Application* _this);
    // ���α׷� ������Ʈ ����Ű�� �Է� �Ǿ��� �� ����
    int(*Update)(struct _Application* _this);
};

// ���丮 �Լ�
struct _Application* CreateApplication();
int DestroyApplication(struct _Application* _app);

int _Application_Run(struct _Application* _this);

int _Application_InitWindow_Check(struct _Application* _this);
int _Application_SeatPracticeWindow_Check(struct _Application* _this);
int _Application_WordPracticeWindow_Check(struct _Application* _this);
int _Application_ShortSentencePracticeWindow_Check(struct _Application* _this);
int _Application_LongSentencePracticeWindow_Check(struct _Application* _this);

int _Application_InitWindow_Update(struct _Application* _this);
int _Application_SeatPracticeWindow_Update(struct _Application* _this);
int _Application_WordPracticeWindow_Update(struct _Application* _this);
int _Application_ShortSentencePracticeWindow_Update(struct _Application* _this);
int _Application_LongSentencePracticeWindow_Update(struct _Application* _this);

typedef struct _Application Application;

#endif