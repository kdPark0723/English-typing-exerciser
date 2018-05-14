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
    // 소유 시스템
    struct _WindowSystem* own;
    // 타이틀
    char* title;

    // 가지고 있는 뷰들
    struct _TextViewLinkedList* views;

    //윈도우 초기화
    int(*Init)(struct _Window* _this);
    // 그리기
    int(*Draw)(struct _Window* _this);
    // 뷰 추가
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

