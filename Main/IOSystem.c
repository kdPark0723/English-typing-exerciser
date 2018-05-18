#include "IOSystem.h"
#include "Platform.h"

#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
#include <conio.h>
#elif (_PLATFORM_TYPE == _PLATFORM_LINUX || _PLATFORM_TYPE == _PLATFORM_UNIX)
#include <termio.h>
int _getche(void)
{
    int ch;

    struct termios _old;
    struct termios _new;

    tcgetattr(0, &_old);

    _new = _old;
    _new.c_lflag |= (ICANON | ECHO);
    _new.c_cc[VMIN] = 1;
    _new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &_new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &_old);

    return ch;
}
int _getch(void)
{
    int ch;

    struct termios _old;
    struct termios _new;

    tcgetattr(0, &_old);

    _new = _old;
    _new.c_lflag |= (ICANON | ECHO);
    _new.c_cc[VMIN] = 1;
    _new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &_new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &_old);

    return ch;
}
#endif

 Pipe* CreatePipe()
 {
     Pipe* pipe;

     pipe = (Pipe*)malloc(sizeof(Pipe));

     pipe->Synchronization = _Pipe_Synchronization;
     pipe->input = 0;
     pipe->output = 0;
     pipe->poutput = 0;

     return pipe;
 }

int DestroyPipe(Pipe* _pipe)
{
    if (_pipe->output)
        free(_pipe->output);
    free(_pipe);

    return 0;
}

int _Pipe_Synchronization(Pipe* _this)
{
    int i, n, tmp;

    tmp = *_this->input;
    n = 1;

    while (tmp /= 10)
        ++n;

    if (_this->output && strlen(_this->output) < n)
    {
        free(_this->output);
        _this->output = 0;
    }
        
    if (!_this->output)
        _this->output = (char*)malloc(sizeof(char) * n + 1);

    for (i = 0; i < n + 1; ++i)
        _this->output[i] = 0;

    tmp = *_this->input;

    for (i = n - 1; i >= 0; --i)
    {
        _this->output[i] = (tmp - tmp / 10 * 10) + '0';

        tmp /= 10;
    }

    *_this->poutput = _this->output;

    return 0;
}

IOSystem * CreateIOSystem(Application * _own)
{
    int i;
    IOSystem* ioSystem;

    ioSystem = (IOSystem*)malloc(sizeof(IOSystem));

    ioSystem->own = _own;
    for (i = 0; i < INPUT_MAX; ++i)
        ioSystem->input[i] = 0;
    ioSystem->output = 0;

    for (i = 0; i < PIPE_MAX; ++i)
        ioSystem->pipes[i] = 0;
    ioSystem->pipeSize = 0;
        
    ioSystem->count = 0;
    ioSystem->size = 0;

    ioSystem->Update = _IOSystem_Update;
    ioSystem->LinkPipe = _IOSystem_LinkPipe;
    ioSystem->CheckKeyboard = _IOSystem_CheckKeyboard;
    ioSystem->InputBufferClear = _IOSystem_InputBufferClear;
    ioSystem->OutputBufferClear = _IOSystem_OutputBufferClear;

    return ioSystem;
}

int DestroyIOSystem(IOSystem* _ioSystem)
{
    int i;

    for (i = 0; i < _ioSystem->pipeSize; ++i)
        DestroyPipe(_ioSystem->pipes[i]);
    free(_ioSystem);

    return 0;
}

int _IOSystem_CheckKeyboard(IOSystem * _this)
{
    char ch;

    if (_this->size > _this->count)
        ch = _getche();
    else
        ch = _getch();

    if (ch == '\x1B')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_EXIT, ch });
    else if (ch == '\x7F' || ch == '\x8')
    {
        if (_this->count > 0)
        {
            _this->count--;
            _this->input[_this->count] = 0;
        }
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_DEL, ch });
    }
    else if (ch == '\x0D' || ch == '\x0A')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_ENTER, ch });
    else
    {
        if (_this->size > _this->count)
        {
            _this->input[_this->count] = ch;
            _this->count++;

            _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_INPUT, ch });
        }
    }

    return 0;
}

int _IOSystem_Update(IOSystem* _this)
{
    int i;

    for (i = 0; i < _this->pipeSize; ++i)
        _this->pipes[i]->Synchronization(_this->pipes[i]);

    return 0;
}

int _IOSystem_InputBufferClear(IOSystem * _this)
{
    int i = 0;

    while (_this->input[i] && i < _this->count)
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

    while (_this->output[i] && i < INPUT_MAX)
    {
    _this->output[i] = 0;
    ++i;
    }

    return 0;
}

int _IOSystem_LinkPipe(IOSystem* _this, int* _input, char** _output)
{
    Pipe* pipe;

    pipe = CreatePipe();

    pipe->input = _input;
    pipe->poutput = _output;
    pipe->Synchronization(pipe);

    _this->pipes[_this->pipeSize] = pipe;
    ++_this->pipeSize;

    return 0;
}
