#include "MessageSystem.h"

MessageSystem * CreateMessageSystem(Application * _own)
{
    MessageSystem* messageSystem;

    messageSystem = (MessageSystem*)malloc(sizeof(MessageSystem));

    messageSystem->own = _own;
    messageSystem->index = -1;

    messageSystem->AddMessage = _MessageSystem_AddMessage;
    messageSystem->CheckMessage = _MessageSystem_CheckMessage;

    return messageSystem;
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
    int i, j, re;

    re = 0;

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
            else
                re = 1;

            break;
        case MESSAGE_CHANGE:
            if (_this->message[i].content > '0' && _this->message[i].content < '6')
            {
                i = _this->message[i].content - '0';
                if (i == 5)
                    _this->own->isRunning = 0;
                else
                    _this->own->windowSystem->type = i;
            }

            break;
        case MESSAGE_DEL:
            switch (_this->own->windowSystem->type)
            {
            case WINDOWTYPE_INIT:
                if (_this->own->ioSystem->count > 0)
                {
                    _this->own->ioSystem->count--;
                    _this->own->ioSystem->input[_this->own->ioSystem->count] = 0;
                }

                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    return re;
}
