#include "Application.h"

int main(void)
{
    Application* app;

    app = CreateApplication();

    app->Run(app);

    DestroyApplication(app);

    return 0;
}