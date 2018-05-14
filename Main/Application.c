#include "Application.h"

Application * CreateApplication()
{
    Application* app;

    app = (Application*)malloc(sizeof(Application));

    app->isRunning = 1;
    app->progress = 0;
    app->numOfTypo = 0;
    app->accuracy = 0;
    app->currentTypingCount = 0;
    app->highestTypingCount = 0;

    app->count = 0;

    app->startTime = clock();
    app->finshTime = clock();

    app->resourceSystem = CreateResourceSystem(app);
    app->ioSystem = CreateIOSystem(app);
    app->messageSystem = CreateMessageSystem(app);
    app->windowSystem = CreateWindowSystem(app);

    app->Run = _Application_Run;

    app->messageSystem->AddMessage(app->messageSystem, (Message) { MESSAGE_CHANGE, WINDOWTYPE_INIT});
    app->messageSystem->CheckMessage(app->messageSystem);

    srand(time(NULL));

    return app;
}

int DestroyApplication(Application * _app)
{
    DestroyMessageSystem(_app->messageSystem);
    DestroyIOSystem(_app->ioSystem);
    DestroyWindowSystem(_app->windowSystem);
    DestroyResourceSystem(_app->resourceSystem);

    free(_app);

    return 0;
}

int _Application_Run(Application * _this)
{
    while (_this->isRunning)
    {
        _this->ioSystem->Update(_this->ioSystem);
        _this->windowSystem->Clear(_this->windowSystem);
        _this->windowSystem->Draw(_this->windowSystem);
        _this->ioSystem->CheckKeyboard(_this->ioSystem);
        _this->messageSystem->CheckMessage(_this->messageSystem);
    }

    return 0;
}

int _Application_InitWindow_InputKeyboard(Application * _this, char _input)
{

    return 0;
}

int _Application_SeatPracticeWindow_InputKeyboard(Application * _this, char _input)
{

    if (_this->progress < 100 && _this->ioSystem->output)
    {
        if (_this->ioSystem->output[0] == _input)
        {
            _this->progress += 5;
            _this->windowSystem->InitWindow(_this->windowSystem);
        }
        else
            _this->numOfTypo += 1;

        _this->count++;
        _this->accuracy = 100 - _this->numOfTypo * 100 / _this->count;
    }

    if (_this->progress == 100)
        _this->ioSystem->OutputBufferClear(_this->ioSystem);

    return 0;
}

int _Application_WordPracticeWindow_InputKeyboard(Application * _this, char _input)
{
    return 0;
}

int _Application_ShortSentencePracticeWindow_InputKeyboard(Application * _this, char _input)
{
    return 0;
}

int _Application_LongSentencePracticeWindow_InputKeyboard(Application * _this, char _input)
{
    return 0;
}

int _Application_InitWindow_InputKeyboardEnter(Application* _this)
{
    _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, _this->ioSystem->input[0] - '0' });
    return 0;
}

int _Application_SeatPracticeWindow_InputKeyboardEnter(Application* _this)
{
    if (_this->progress == 100)
        _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, WINDOWTYPE_INIT });

    return 0;
}

int _Application_WordPracticeWindow_InputKeyboardEnter(Application* _this)
{
    int i;

    if (_this->ioSystem->count == 3)
    {
        for (i = 0; i < _this->ioSystem->count; ++i)
            if (_this->ioSystem->input[i] != '#')
                break;
        if (i == _this->ioSystem->count)
            _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, WINDOWTYPE_INIT });
    }

    return 0;
}

int _Application_ShortSentencePracticeWindow_InputKeyboardEnter(Application* _this)
{
    return 0;
}

int _Application_LongSentencePracticeWindow_InputKeyboardEnter(Application* _this)
{
    return 0;
}

int _Application_InitWindow_InputKeyboardBackSpace(Application* _this)
{
    return 0;
}

int _Application_SeatPracticeWindow_InputKeyboardBackSpace(Application* _this)
{
    return 0;
}

int _Application_WordPracticeWindow_InputKeyboardBackSpace(Application* _this)
{

    return 0;
}

int _Application_ShortSentencePracticeWindow_InputKeyboardBackSpace(Application* _this)
{
    return 0;
}

int _Application_LongSentencePracticeWindow_InputKeyboardBackSpace(Application* _this)
{
    return 0;
}