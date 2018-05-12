#include "MessageSystem.h"

MessageSystem * CreateMessageSystem(Application * _own)
{
    MessageSystem* system;

    system = (MessageSystem*)malloc(sizeof(MessageSystem));

    system->own = _own;
    system->index = -1;

    system->AddMessage = _MessageSystem_AddMessage;
    system->CheckMessage = _MessageSystem_CheckMessage;

    return system;
}

int _MessageSystem_AddMessage(MessageSystem * _this, Message _message)
{
    if (_this->index >= MESSAGE_MAX)
        return 1;

    _this->index++;
    _this->message[_this->index] = _message;

    return 0;
}

int _MessageSystem_CheckMessage(MessageSystem * _this)
{
    int i, j;

    for (i = 0; i <= _this->index; ++i)
    {
        switch (_this->message[i].name)
        {
        case MESSAGE_EXIT:
            _this->own->windowSystem->ChangeWindow(_this->own->windowSystem, WINDOWTYPE_INIT);
            break;
        case MESSAGE_ENTER:
            if (_this->own->windowSystem->type == WINDOWTYPE_WORDPRACTICE && _this->own->ioSystem->count == 4)
            {
                for (j = 0; j < _this->own->ioSystem->count; ++j)
                    if (_this->own->ioSystem->input[j] != '#')
                        break;
                if (j == _this->own->ioSystem->count)
                    _this->own->windowSystem->ChangeWindow(_this->own->windowSystem, WINDOWTYPE_INIT);
            }
            break;
        case MESSAGE_CHANGE:
            i = atoi(_this->message[i].content);
            if (i == 5)
                _this->own->isRunning = 0;
            else
                _this->own->windowSystem->type = i;
            break;
        default:
            break;
        }
    }

    return 0;
}
