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

    app->startTime = clock();
    app->finshTime = clock();

    app->messageSystem = CreateMessageSystem(app);
    app->ioSystem = CreateIOSystem(app);
    app->ioSystem->output = "Testing Message";
    app->windowSystem = CreateWindowSystem(app);

    app->Run = _Application_Run;
    app->Update = _Application_InitWindow_Update;

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

int _Application_InitWindow_Update(Application* _this)
{
    _this->messageSystem->AddMessage(_this->messageSystem, (Message) { MESSAGE_CHANGE, _this->ioSystem->input[0] });
    return 0;
}
int _Application_SeatPracticeWindow_Update(Application* _this)
{
    return 0;
}
int _Application_WordPracticeWindow_Update(Application* _this)
{
    return 0;
}
int _Application_ShortSentencePracticeWindow_Update(Application* _this)
{
    return 0;
}
