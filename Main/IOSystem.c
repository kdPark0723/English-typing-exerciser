#include "IOSystem.h"

IOSystem* CreateIOSystem(Application* _own)
{
    int i;
    IOSystem* system;

    system = (IOSystem*)malloc(sizeof(IOSystem));

    system->own = _own;
    for (i = 0; i < INPUT_MAX; ++i)
        system->input[i] = 0;
    system->output = 0;
    system->count = 0;

    system->Get = _IOSystem_Get;
}

int _IOSystem_Get(IOSystem* _this)
{
    char ch;

    ch = getchar();

    if (ch == '\0x1B')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_EXIT, ch });
    else if (ch == '\0x7F')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_DEL, ch });
    else if (ch == '\0x0D')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_ENTER, ch });
    else
    {
        _this->count++;
        _this->input[_this->count] = ch;
    }

    return 0;
}
