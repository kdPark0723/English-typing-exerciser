#include "WindowSystem.h"
#include "Platform.h"

WindowSystem * CreateWindowSystem(Application * _own)
{
    WindowSystem* windowSystem;

    windowSystem = (WindowSystem*)malloc(sizeof(WindowSystem));

    windowSystem->own = _own;
    windowSystem->type = WINDOWTYPE_INIT;
    windowSystem->windows[WINDOWTYPE_INIT] = CreateInitWindow(windowSystem);
    windowSystem->windows[WINDOWTYPE_SEATPRACTICE] = CreateSeatPracticeWindow(windowSystem);
    windowSystem->windows[WINDOWTYPE_WORDPRACTICE] = CreateWordPracticeWindow(windowSystem);
    windowSystem->windows[WINDOWTYPE_SHORTSENTENCEPRACTICE] = CreateShortSentencePracticeWindow(windowSystem);
    windowSystem->windows[WINDOWTYPE_LONGSENTENCEPRACTICE] = CreateLongSentencePracticeWindow(windowSystem);

    windowSystem->ChangeWindow = _WindowSystem_ChangeWindow;
    windowSystem->Clear = _WindowSystem_Clear;
    windowSystem->Draw = _WindowSystem_Draw;
    windowSystem->InitWindow = _WindowSystem_InitWindow;

    windowSystem->InitWindow(windowSystem);

    return windowSystem;
}

int DestroyWindowSystem(WindowSystem * _windowSystem)
{
    DestroyWindow(_windowSystem->windows[WINDOWTYPE_INIT]);
    DestroyWindow(_windowSystem->windows[WINDOWTYPE_SEATPRACTICE]);
    DestroyWindow(_windowSystem->windows[WINDOWTYPE_WORDPRACTICE]);
    DestroyWindow(_windowSystem->windows[WINDOWTYPE_SHORTSENTENCEPRACTICE]);
    DestroyWindow(_windowSystem->windows[WINDOWTYPE_LONGSENTENCEPRACTICE]);

    free(_windowSystem);

    return 0;
}

int _WindowSystem_InitWindow(WindowSystem * _this)
{
    _this->windows[_this->type]->Init(_this->windows[_this->type]);

    return 0;
}

int _WindowSystem_Clear(WindowSystem * _this)
{
#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
    return system("CLS");
#elif (_PLATFORM_TYPE == _PLATFORM_LINUX)
    return system("clear");
#endif
}

int _WindowSystem_Draw(WindowSystem * _this)
{
    return _this->windows[_this->type]->Draw(_this->windows[_this->type]);
}

int _WindowSystem_ChangeWindow(WindowSystem * _this, int _type)
{
    return _this->type = _type;
}
