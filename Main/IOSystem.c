#include "IOSystem.h"
#include "Platform.h"

#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
#include <conio.h>
#elif (_PLATFORM_TYPE == _PLATFORM_LINUX)
#include <termio.h>
int _getch(void)
{
    int ch;

    struct termios _old;
    struct termios _new;

    tcgetattr(0, &_old);

    _new = _old;
    _new.c_lflag &= ~(ICANON | ECHO);
    _new.c_cc[VMIN] = 1;
    _new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &_new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &_old);

    return ch;
}
#endif


IOSystem * CreateIOSystem(Application * _own)
{
    int i;
    IOSystem* ioSystem;

    ioSystem = (IOSystem*)malloc(sizeof(IOSystem));

    ioSystem->own = _own;
    for (i = 0; i < INPUT_MAX; ++i)
        ioSystem->input[i] = 0;
    ioSystem->output = " ";
    ioSystem->count = 0;

    ioSystem->Get = _IOSystem_Get;
    ioSystem->Init = _IOSystem_Init;
}

int DestroyIOSystem(IOSystem* _ioSystem)
{
    free(_ioSystem);

    return 0;
}

int _IOSystem_Get(IOSystem * _this)
{
    char ch;

    ch = _getch();

    if (ch == '\x1B')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_EXIT, ch });
    else if (ch == '\x7F' || ch == '\x8')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_DEL, ch });
    else if (ch == '\x0D' || ch == '\x0A')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_ENTER, ch });
    else
    {
        _this->input[_this->count] = ch;
        _this->count++;
    }

    return 0;
}

int _IOSystem_Init(IOSystem * _this)
{
    int i;

    for (i = 0; i < INPUT_MAX; ++i)
        _this->input[i] = 0;
    _this->count = 0;

    return 0;
}
