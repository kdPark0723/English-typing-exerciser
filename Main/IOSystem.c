#include "IOSystem.h"

IOSystem* CreateIOSystem(Application* _own)
{
    IOSystem* system;

    system = (IOSystem*)malloc(sizeof(IOSystem));

    system->own = _own;
    system->input = NULL;
    system->output = 0;
    system->count = 0;

    system->Get = _IOSystem_Get;
}

Input* CreateInput(char _content, Input* _pre)
{
    Input* input;

    input = (Input*)malloc(sizeof(Input));

    input->content = _content;
    input->next = NULL;
    input->pre = _pre;

    return input;
}

int _IOSystem_Get(IOSystem* _this)
{
    char ch;
    Input* tmp;

    ch = getchar();
    tmp = _this->input;

    if (ch == '\0x1B')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_EXIT, ch });
    else if (ch == '\0x7F')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_DEL, ch });
    else if (ch == '\0x0D')
        _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_ENTER, ch });
    else
    {
        _this->count++;

        if (!tmp)
            tmp = CreateInput(ch, NULL);
        else
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = CreateInput(ch, tmp);
        }
    }

    return 0;
}
