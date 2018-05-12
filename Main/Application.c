#include "Application.h"

Application* CreateApplication()
{
    Application* app;

    app = (Application*)malloc(sizeof(Application));

    app->isRunning = 1;
    app->progress = 0;
    app->numOfTypo = 0;
    app->accuracy = 0;

    app->startTime = clock();
    app->finshTime = clock();

    app->messageSystem = CreateMessageSystem(app);
    app->windowSystem = CreateWindowSystem(app);
    app->ioSystem = CreateIOSystem(app);

    app->Run = _Application_Run;
    app->Update = _Application_Update;

    return app;
}

int _Application_Run(Application* _this)
{
    while (_this->isRunning)
    {
        _this->windowSystem->Draw(_this->windowSystem);
        _this->ioSystem->Get(_this->ioSystem);
        _this->messageSystem->CheckMessage(_this->messageSystem);

        _this->Update(_this);
    }
}

int _Application_Update(Application* _this)
{
    _this->finshTime = clock();
}