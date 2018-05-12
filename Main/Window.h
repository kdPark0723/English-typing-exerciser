#pragma once

#include "Application.h"
#include "WindowSystem.h"

#define WINDOWTYPE_INIT 0
#define WINDOWTYPE_SEATPRACTICE 1
#define WINDOWTYPE_WORDPRACTICE 2
#define WINDOWTYPE_SHORTSENTENCEPRACTICE 3

#define WINDOW_NUM 4

typedef struct _TextView
{
    // 소유 윈도우
    Window* own;
    // 내용
    char* contents;

    // 그리기
    int(*Draw)(struct _TextView* _this);
} TextView;

// 택스트 부와 통합할건지 고민중.
typedef struct _TextViewLinkedList
{
    // 가지고 있는 뷰들
    TextView* contents;

    //그전에 출력될 뷰
    struct _TextViewLinkedList* pre;
    // 그후 출력될 뷰
    struct _TextViewLinkedList* next;

} TextViewLinkedList;

typedef struct _Window
{
    // 소유 시스템
    WindowSystem* own;
    // 타이틀
    char* title;

    // 가지고 있는 뷰들
    TextViewLinkedList* views;

    // 그리기
    int(*Draw)(struct _Window* _this);
    // 뷰 추가
    int(*AddView)(struct _Window* _this, TextView* _view);
} Window;

// 펙토리 함수
TextView* CreateTextView(Window* _own);

Window* CreateInitWindow(WindowSystem* _own);
Window* CreateSeatPracticeWindow(WindowSystem* _own);
Window* CreateWordPracticeWindow(WindowSystem* _own);
Window* CreateShortSentencePracticeWindow(WindowSystem* _own);

int _TextView_Draw(TextView* _this);

int _Window_Draw(Window* _this);
int _Window_AddView(Window* _this, TextView* _view);


