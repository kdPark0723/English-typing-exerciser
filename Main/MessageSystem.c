#include "MessageSystem.h"

MessageSystem * CreateMessageSystem(Application * _own)
{
    int i;
    MessageSystem* messageSystem;

    messageSystem = (MessageSystem*)malloc(sizeof(MessageSystem));

    messageSystem->own = _own;
    messageSystem->index = -1;
    for (i = 0; i < MESSAGE_MAX; ++i)
    {
        messageSystem->message[i].content = MESSAGE_EMTY;
        messageSystem->message[i].name = MESSAGE_EMTY;
    }

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
            if (_this->own->windowSystem->type != WINDOWTYPE_INIT)
                _this->own->windowSystem->ChangeWindow(_this->own->windowSystem, WINDOWTYPE_INIT);
            break;
        case MESSAGE_ENTER:
            switch (_this->own->windowSystem->type)
            {
            case WINDOWTYPE_INIT:
                _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_CHANGE, _this->own->ioSystem->input[0] });

                _this->own->ioSystem->Init(_this->own->ioSystem);
                break;
            case WINDOWTYPE_WORDPRACTICE:
                if (_this->own->ioSystem->count == 4)
                {
                    for (j = 0; j < _this->own->ioSystem->count; ++j)
                        if (_this->own->ioSystem->input[j] != '#')
                            break;
                    if (j == _this->own->ioSystem->count)
                        _this->own->windowSystem->ChangeWindow(_this->own->windowSystem, WINDOWTYPE_INIT);
                }
                break;
            default:
                break;
            }

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
        _this->message[i].name = MESSAGE_EMTY;
        _this->message[i].content = MESSAGE_EMTY;
    }
    _this->index = -1;

    return re;
}
