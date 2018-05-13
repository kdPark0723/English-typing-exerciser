#pragma once

#include "WindowSystem.h"
#include "TextView.h"

#define WINDOWTYPE_INIT 0
#define WINDOWTYPE_SEATPRACTICE 1
#define WINDOWTYPE_WORDPRACTICE 2
#define WINDOWTYPE_SHORTSENTENCEPRACTICE 3

struct _Window
{
    // ���� �ý���
    struct _WindowSystem* own;
    // Ÿ��Ʋ
    char* title;

    // ������ �ִ� ���
    struct _TextViewLinkedList* views;

    // ���� ������Ʈ
    int(*Update)(struct _Window* _this);
    // �׸���
    int(*Draw)(struct _Window* _this);
    // �� �߰�
    int(*AddView)(struct _Window* _this, struct _TextView* _view);
};

struct _Window* CreateInitWindow(struct _WindowSystem* _own);
struct _Window* CreateSeatPracticeWindow(struct _WindowSystem* _own);
struct _Window* CreateWordPracticeWindow(struct _WindowSystem* _own);
struct _Window* CreateShortSentencePracticeWindow(struct _WindowSystem* _own);

int DestroyWindow(struct _Window* _window);

int _InitWindow_Update(struct _Window* _this);
int _SeatPracticeWindow_Update(struct _Window* _this);
int _WordPracticeWindow_Update(struct _Window* _this);
int _ShortSentencePracticeWindow_Update(struct _Window* _this);

int _Window_Draw(struct _Window* _this);
int _Window_AddView(struct _Window* _this, struct _TextView* _view);

typedef struct _Window Window;


