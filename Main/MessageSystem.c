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
                _this->own->messageSystem->AddMessage(_this->own->messageSystem, (Message) { MESSAGE_CHANGE, WINDOWTYPE_INIT });

            break;
        case MESSAGE_ENTER:
            _this->own->InputKeyboardEnter(_this->own);
            break;
        case MESSAGE_CHANGE:
            if (_this->message[i].content < 0 || _this->message[i].content >= 6)
                break;
         
            if (_this->message[i].content == 5)
            {
                _this->own->isRunning = 0;
                break;
            }
                
            _this->own->windowSystem->type = _this->message[i].content;

            switch (_this->own->windowSystem->type)
            {
            case WINDOWTYPE_INIT:
                _this->own->InputKeyboardEnter = _Application_InitWindow_InputKeyboardEnter;
                _this->own->InputKeyboard = _Application_InitWindow_InputKeyboard;
                _this->own->InputKeyboardBackSpace = _Application_InitWindow_InputKeyboardBackSpace;
                break;
            case WINDOWTYPE_SEATPRACTICE:
                _this->own->InputKeyboardEnter = _Application_SeatPracticeWindow_InputKeyboardEnter;
                _this->own->InputKeyboard = _Application_SeatPracticeWindow_InputKeyboard;
                _this->own->InputKeyboard = _Application_SeatPracticeWindow_InputKeyboard;
                break;
            case WINDOWTYPE_WORDPRACTICE:
                _this->own->InputKeyboardEnter = _Application_WordPracticeWindow_InputKeyboardEnter;
                _this->own->InputKeyboard = _Application_WordPracticeWindow_InputKeyboard;
                _this->own->InputKeyboardBackSpace = _Application_WordPracticeWindow_InputKeyboardBackSpace;
                break;
            case WINDOWTYPE_SHORTSENTENCEPRACTICE:
                _this->own->InputKeyboardEnter = _Application_ShortSentencePracticeWindow_InputKeyboardEnter;
                _this->own->InputKeyboard = _Application_ShortSentencePracticeWindow_InputKeyboard;
                _this->own->InputKeyboardBackSpace = _Application_ShortSentencePracticeWindow_InputKeyboardBackSpace;
                break;
            case WINDOWTYPE_LONGSENTENCEPRACTICE:
                _this->own->InputKeyboardEnter = _Application_LongSentencePracticeWindow_InputKeyboardEnter;
                _this->own->InputKeyboard = _Application_LongSentencePracticeWindow_InputKeyboard;
                _this->own->InputKeyboardBackSpace = _Application_LongSentencePracticeWindow_InputKeyboardBackSpace;
                break;
            default:
                break;
            }

            _this->own->progress = 0;
            _this->own->numOfTypo = 0;
            _this->own->accuracy = 0;
            _this->own->currentTypingCount = 0;
            _this->own->highestTypingCount = 0;

            _this->own->count = 0;

            _this->own->windowSystem->InitWindow(_this->own->windowSystem);

            _this->own->ioSystem->InputBufferClear(_this->own->ioSystem);

            break;
        case MESSAGE_DEL:
            
            break;
        case MESSAGE_INPUT:
            _this->own->InputKeyboard(_this->own, _this->message[i].content);
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
