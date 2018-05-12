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

    window->title = ">> 영문 타자 연습 프로그램 <<";

    window->views = (TextViewLinkedList*)malloc(sizeof(TextViewLinkedList));
    window->views->contents = CreateTextView(window);
    window->views->contents->contents = "1.자리 연습         2.낱말 연습 \n3. 짧은 글 연습     4. 긴 글 연습 \n5. 프로그램 종료\n번호를 입력하세요: ";

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

    window->title = ">> 영문 타자 연습 프로그램 : 자리연습 <<";

    view = CreateTextView(window);
    view->contents = "진행도 : %d%%   오타수 : %d    정확도 : %d%%\n\n";
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
