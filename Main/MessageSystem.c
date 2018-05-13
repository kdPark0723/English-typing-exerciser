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

int DestroyMessageSystem(MessageSystem* _messageSystem)
{
    free(_messageSystem);

    return 0;
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
                _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_CHANGE, '0' });

            break;
        case MESSAGE_ENTER:
            _this->own->Update(_this->own);
            break;
        case MESSAGE_CHANGE:
            if (_this->message[i].content >= '0' && _this->message[i].content < '6')
            {
                j = _this->message[i].content - '0';
                if (j == 5)
                    _this->own->isRunning = 0;
                else
                {
                    _this->own->windowSystem->type = j;

                    switch (_this->own->windowSystem->type)
                    {
                    case WINDOWTYPE_INIT:
                        _this->own->Update = _Application_InitWindow_Update;
                        _this->own->Check = _Application_InitWindow_Check;
                        break;
                    case WINDOWTYPE_SEATPRACTICE:
                        _this->own->Update = _Application_SeatPracticeWindow_Update;
                        _this->own->Check = _Application_SeatPracticeWindow_Check;
                        break;
                    case WINDOWTYPE_WORDPRACTICE:
                        _this->own->Update = _Application_WordPracticeWindow_Update;
                        _this->own->Check = _Application_WordPracticeWindow_Check;
                        break;
                    case WINDOWTYPE_SHORTSENTENCEPRACTICE:
                        _this->own->Update = _Application_ShortSentencePracticeWindow_Update;
                        _this->own->Check = _Application_ShortSentencePracticeWindow_Check;
                        break;
                    case WINDOWTYPE_LONGSENTENCEPRACTICE:
                        _this->own->Update = _Application_LongSentencePracticeWindow_Update;
                        _this->own->Check = _Application_LongSentencePracticeWindow_Check;
                        break;
                    default:
                        break;
                    }

                    _this->own->progress = 0;
                    _this->own->numOfTypo = 0;
                    _this->own->accuracy = 0;
                    _this->own->currentTypingCount = 0;
                    _this->own->highestTypingCount = 0;

                    _this->own->count = -1;

                    _this->own->Check(_this->own);
                }
            }
            _this->own->ioSystem->InputBufferClear(_this->own->ioSystem);

            break;
        case MESSAGE_DEL:
            if (_this->own->ioSystem->count > 0)
            {
                _this->own->ioSystem->count--;
                _this->own->ioSystem->input[_this->own->ioSystem->count] = 0;
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
