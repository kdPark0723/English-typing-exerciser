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

    app->count = -1;

    app->startTime = clock();
    app->finshTime = clock();

    app->_alphabets = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

    app->messageSystem = CreateMessageSystem(app);
    app->ioSystem = CreateIOSystem(app);

    app->windowSystem = CreateWindowSystem(app);

    app->Run = _Application_Run;

    app->messageSystem->AddMessage(app->messageSystem, (Message) { MESSAGE_CHANGE, '0' });
    app->messageSystem->CheckMessage(app->messageSystem);

    srand(time(NULL));

    return app;
}

int DestroyApplication(Application * _app)
{
    DestroyMessageSystem(_app->messageSystem);
    DestroyIOSystem(_app->ioSystem);
    DestroyWindowSystem(_app->windowSystem);

    free(_app);

    return 0;
}

int _Application_Run(Application * _this)
{
    while (_this->isRunning)
    {
        _this->windowSystem->Clear(_this->windowSystem);
        _this->windowSystem->Draw(_this->windowSystem);
        _this->ioSystem->Get(_this->ioSystem);
        _this->messageSystem->CheckMessage(_this->messageSystem);
    }

    return 0;
}

int _Application_InitWindow_Check(Application * _this)
{
    if (_this->count == -1)
    {
        _this->count = 0;
        _this->ioSystem->size = 1;
    }
    return 0;
}

int _Application_SeatPracticeWindow_Check(Application * _this)
{
    // ÃÊ±âÈ­
    if (_this->count == -1)
    {
        _this->count = 0;
        _this->ioSystem->size = 1;
        _this->ioSystem->output[0] = _this->_alphabets[rand() % 52];
    }
    else if (_this->progress < 100)
    {
        if (_this->ioSystem->output[0] == _this->ioSystem->input[0])
        {
            _this->ioSystem->output[0] = _this->_alphabets[rand() % 52];
            _this->ioSystem->input[0] = 0;
            _this->ioSystem->count = 0;
            
            _this->progress += 5;
        }
        else
        {
            _this->numOfTypo += 1;
        }

        _this->count++;
        _this->accuracy = 100 - _this->numOfTypo * 100 / _this->count;
    }

    if (_this->progress == 100)
        _this->ioSystem->output[0] = 0;

    return 0;
}

int _Application_WordPracticeWindow_Check(Application * _this)
{
    return 0;
}

int _Application_ShortSentencePracticeWindow_Check(Application * _this)
{
    return 0;
}

int _Application_LongSentencePracticeWindow_Check(Application * _this)
{
    return 0;
}

int _Application_InitWindow_Update(Application* _this)
{
    _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, _this->ioSystem->input[0] });
    return 0;
}

int _Application_SeatPracticeWindow_Update(Application* _this)
{
    if (_this->progress == 100)
        _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, '0' });

    return 0;
}

int _Application_WordPracticeWindow_Update(Application* _this)
{
    int i;

    if (_this->ioSystem->count == 3)
    {
        for (i = 0; i < _this->ioSystem->count; ++i)
            if (_this->ioSystem->input[i] != '#')
                break;
        if (i == _this->ioSystem->count)
            _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, '0' });
    }

    return 0;
}

int _Application_ShortSentencePracticeWindow_Update(Application* _this)
{
    return 0;
}

int _Application_LongSentencePracticeWindow_Update(Application* _this)
{
    return 0;
}