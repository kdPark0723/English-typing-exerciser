#include "Window.h"

TextView * CreateTextView(Window * _own)
{
    TextView* view;

    view = (TextView*)malloc(sizeof(TextView));

    view->own = _own;
    view->contents = 0;

    view->Draw = _TextView_Draw;

    return NULL;
}

Window* CreateInitWindow(WindowSystem* _own)
{
    Window* window;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;

    window->title = ">> ���� Ÿ�� ���� ���α׷� <<";

    window->views = (TextViewLinkedList*)malloc(sizeof(TextViewLinkedList));
    window->views->contents = CreateTextView(window);
    window->views->contents->contents = "1.�ڸ� ����         2.���� ���� \n3. ª�� �� ����     4. �� �� ���� \n5. ���α׷� ����\n��ȣ�� �Է��ϼ���: ";

    return window;
}

Window * CreateSeatPracticeWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : �ڸ����� <<";

    view = CreateTextView(window);
    view->contents = "���൵ : %d%%   ��Ÿ�� : %d    ��Ȯ�� : %d%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->ioSystem->output;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->ioSystem->input;
    window->AddView(window, view);

    return window;
}
