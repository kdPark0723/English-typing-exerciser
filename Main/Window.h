#pragma once

#include "Application.h"
#include "WindowSystem.h"

#define WINDOWTYPE_INIT 0
#define WINDOWTYPE_SEATPRACTICE 1
#define WINDOWTYPE_WORDPRACTICE 2
#define WINDOWTYPE_SHORTSENTENCEPRACTICE 3

typedef struct _Window
{
    WindowSystem* own;
    char* title;
    char* contents;

    int(*Draw)(struct _Window* _this);
} Window;

Window* CreateInitWindow(WindowSystem* _own);
Window* CreateSeatPracticeWindow(WindowSystem* _own);
Window* CreateWordPracticeWindow(WindowSystem* _own);
Window* CreateShortSentencePracticeWindow(WindowSystem* _own);

int _InitWindow_Draw(Window* _this);
int _SeatPracticeWindow_Draw(Window* _this);
int _WordPracticeWindow_Draw(Window* _this);
int _ShortSentencePracticeWindow_Draw(Window* _this);

