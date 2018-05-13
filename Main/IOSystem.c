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
        
    ioSystem->count = 0;
    ioSystem->size = 0;

    ioSystem->Update = _IOSystem_Update;
    ioSystem->InputBufferClear = _IOSystem_InputBufferClear;
    ioSystem->OutputBufferClear = _IOSystem_OutputBufferClear;

    return ioSystem;
}

int DestroyIOSystem(IOSystem* _ioSystem)
{
    free(_ioSystem);

    return 0;
}

int _IOSystem_Update(IOSystem * _this)
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
        if (_this->size > _this->count)
        {
            _this->input[_this->count] = ch;
            _this->count++;

            _this->own->Check(_this->own);
        }
    }

    return 0;
}

int _IOSystem_InputBufferClear(IOSystem * _this)
{
    int i = 0;

    while (_this->input[i] && i < INPUT_MAX)
    {
        _this->input[i] = 0;
        ++i;
    }
    _this->count = 0;

    return 0;
}

int _IOSystem_OutputBufferClear(IOSystem * _this)
{
    int i = 0;

    /*
    while (_this->output[i] && i < INPUT_MAX)
    {
    _this->output[i] = 0;
    ++i;
    }
    */

    return 0;
}
