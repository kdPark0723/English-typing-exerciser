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

Window * CreateInitWindow(WindowSystem * _own)
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
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_progress;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_numOfTypo;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_accuracy;
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
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ���� ���� <<";

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_progress;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_numOfTypo;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_accuracy;
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
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ª�� �� ���� <<";

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_progress;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ����Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_currentTypingCount;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "   �ְ�Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_highestTypingCount;
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->p_accuracy;
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
