#include "Window.h"

TextView * CreateTextView(Window * _own)
{
    TextView* view;

    view = (TextView*)malloc(sizeof(TextView));

    view->own = _own;
    view->contents = 0;

    view->Draw = _TextView_Draw;

    return view;
}

TextViewLinkedList * CreateTextViewLinkedList()
{
    TextViewLinkedList* list;

    list = (TextViewLinkedList*)malloc(sizeof(TextViewLinkedList));

    list->contents = 0;
    list->next = 0;
    list->pre = 0;

    return list;
}

Window * CreateInitWindow(WindowSystem * _own)
{
    Window* window;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Update = _InitWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� <<";

    window->views = CreateTextViewLinkedList();
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
    window->Update = _SeatPracticeWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : �ڸ����� <<";
    window->views = CreateTextViewLinkedList();

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->progress, view->contents,10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->numOfTypo, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->accuracy, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
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

Window * CreateWordPracticeWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Update = _WordPracticeWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ���� ���� <<";
    window->views = CreateTextViewLinkedList();

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->progress, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->numOfTypo, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->accuracy, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
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

Window * CreateShortSentencePracticeWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Update = _ShortSentencePracticeWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ª�� �� ���� <<";
    window->views = CreateTextViewLinkedList();

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->progress, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ����Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->currentTypingCount, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "   �ְ�Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->highestTypingCount, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    itoa(_own->own->accuracy, view->contents, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
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

int _TextView_Draw(TextView * _this)
{
    return printf(_this->contents);
}

int _InitWindow_Update(Window * _this)
{
    return 0;
}

int _SeatPracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    itoa(_this->own->own->progress, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->numOfTypo, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->accuracy, view->contents->contents, 10);

    return 0;
}

int _WordPracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    itoa(_this->own->own->progress, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->numOfTypo, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->accuracy, view->contents->contents, 10);

    return 0;
}

int _ShortSentencePracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    itoa(_this->own->own->progress, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->currentTypingCount, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->highestTypingCount, view->contents->contents, 10);
    view = view->next->next;

    itoa(_this->own->own->accuracy, view->contents->contents, 10);

    return 0;
}

int _Window_Draw(Window * _this)
{
    TextViewLinkedList* view;
    view = _this->views;

    printf(_this->title);
    printf("\n");
    
    while (view->contents)
    {
        view->contents->Draw(view->contents);

        view = view->next;
    }

    return 0;
}

int _Window_AddView(Window * _this, TextView * _view)
{
    TextViewLinkedList* view;
    view = _this->views;

    while (view->next)
        view = view->next;

    view->next = CreateTextViewLinkedList();
    view->next->pre = view;

    view->next->contents = _view;

    return 0;
}
