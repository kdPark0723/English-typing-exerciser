#pragma once

#include "Application.h"
#include "WindowSystem.h"

#define WINDOWTYPE_INIT 0
#define WINDOWTYPE_SEATPRACTICE 1
#define WINDOWTYPE_WORDPRACTICE 2
#define WINDOWTYPE_SHORTSENTENCEPRACTICE 3

typedef struct _TextView
{
    Window* own;
    char* contents;

    int(*Draw)(struct _TextView* _this);
} TextView;

typedef struct _TextViewLinkedList
{
    TextView* contents;

    struct _TextViewLinkedList* pre;
    struct _TextViewLinkedList* next;

} TextViewLinkedList;

typedef struct _Window
{
    WindowSystem* own;
    char* title;

    TextViewLinkedList* views;

    int(*Draw)(struct _Window* _this);
    int(*AddView)(struct _Window* _this, TextView* _view);
} Window;

TextView* CreateTextView(Window* _own);

Window* CreateInitWindow(WindowSystem* _own);
Window* CreateSeatPracticeWindow(WindowSystem* _own);
Window* CreateWordPracticeWindow(WindowSystem* _own);
Window* CreateShortSentencePracticeWindow(WindowSystem* _own);

int _TextView_Draw(TextView* _this);

int _Window_Draw(Window* _this);
int _Window_AddView(Window* _this, TextView* _view);


