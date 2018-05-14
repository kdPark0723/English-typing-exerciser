#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "WindowSystem.h"
#include "TextView.h"

#define WINDOWTYPE_INIT 0
#define WINDOWTYPE_SEATPRACTICE 1
#define WINDOWTYPE_WORDPRACTICE 2
#define WINDOWTYPE_SHORTSENTENCEPRACTICE 3
#define WINDOWTYPE_LONGSENTENCEPRACTICE 4

struct _Window
{
    // ���� �ý���
    struct _WindowSystem* own;
    // Ÿ��Ʋ
    char* title;

    // ������ �ִ� ���
    struct _TextViewLinkedList* views;

    //������ �ʱ�ȭ
    int(*Init)(struct _Window* _this);
    // �׸���
    int(*Draw)(struct _Window* _this);
    // �� �߰�
    int(*AddView)(struct _Window* _this, struct _TextView* _view);
};

struct _Window* CreateInitWindow(struct _WindowSystem* _own);
struct _Window* CreateSeatPracticeWindow(struct _WindowSystem* _own);
struct _Window* CreateWordPracticeWindow(struct _WindowSystem* _own);
struct _Window* CreateShortSentencePracticeWindow(struct _WindowSystem* _own);
struct _Window* CreateLongSentencePracticeWindow(struct _WindowSystem* _own);

int DestroyWindow(struct _Window* _window);

int _InitWindow_Init(struct _Window* _this);
int _SeatPracticeWindow_Init(struct _Window* _this);
int _WordPracticeWindow_Init(struct _Window* _this);
int _ShortSentencePracticeWindow_Init(struct _Window* _this);
int _LongSentencePracticeWindow_Init(struct _Window* _this);

int _Window_Draw(struct _Window* _this);
int _Window_AddView(struct _Window* _this, struct _TextView* _view);

typedef struct _Window Window;

#endif

