#include "IOSystem.h"

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

int _IOSystem_Get(IOSystem * _this)
{
    char ch;

    ch = getchar();

    if (ch == '\x1B')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_EXIT, ch });
    else if (ch == '\x7F')
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
