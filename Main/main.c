#include "Application.h"

int main(void)
{
    Application* app;

    app = CreateApplication();

    app->Run(app);

    return 0;
}