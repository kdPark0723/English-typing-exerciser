#include "Window.h"
#include "WindowSystem.h"
#include "Platform.h"


char* intToString(int _value, char* _buffer, int _bufferSize, int _radix)
{
#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
    return _itoa_s(_value, _buffer, _bufferSize, _radix);
#else
    if (_radix == 10)
        sprintf(_buffer, "%d", _value);
    else if (_radix==8)
        sprintf(_buffer, "%#o", _value);
    else if(_radix == 16)
        sprintf(_buffer, "%#x", _value);

    return NULL;
#endif
}


Window * CreateInitWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Init = _InitWindow_Init;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "1. �ڸ� ����         2. ���� ���� \n3. ª�� �� ����      4. �� �� ���� \n5. ���α׷� ����\n\n��ȣ�� �Է��ϼ���: ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->ioSystem->input;
    window->AddView(window, view);
    
    return window;
}

Window * CreateSeatPracticeWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Init = _SeatPracticeWindow_Init;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : �ڸ����� <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &(_own->own->progress), &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &(_own->own->numOfTypo), &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->accuracy, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->p_contents = &(_own->own->ioSystem->output);
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
    window->Init = _WordPracticeWindow_Init;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ���� ���� <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->progress, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ��Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &(_own->own->numOfTypo), &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->accuracy, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->p_contents = &(_own->own->ioSystem->output);
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
    window->Init = _ShortSentencePracticeWindow_Init;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : ª�� �� ���� <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "���൵ : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->progress, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ����Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->currentTypingCount, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "   �ְ�Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->highestTypingCount, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    ��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->accuracy, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->p_contents = &(_own->own->ioSystem->output);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->ioSystem->input;
    window->AddView(window, view);

    return window;
}

Window * CreateLongSentencePracticeWindow(WindowSystem * _own)
{
    Window* window;
    TextView* view;

    window = (Window*)malloc(sizeof(Window));

    window->own = _own;
    window->Draw = _Window_Draw;
    window->Init = _LongSentencePracticeWindow_Init;
    window->AddView = _Window_AddView;

    window->title = ">> ���� Ÿ�� ���� ���α׷� : �� �� ���� <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "��Ȯ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->accuracy, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   ����Ÿ�� : ";
    window->AddView(window, view);

    view = CreateTextView(window);

    _own->own->ioSystem->LinkPipe(_own->own->ioSystem, &_own->own->currentTypingCount, &(view->contents));
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->p_contents = &(_own->own->ioSystem->output);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = _own->own->ioSystem->input;
    window->AddView(window, view);

    return window;
}

int DestroyWindow(Window* _window)
{
    DestroryTextViewLinkedList(_window->views);
    free(_window);
    
    return 0;
}

int _InitWindow_Init(Window* _this)
{
    _this->own->own->ioSystem->size = 1;

    return 0;
}

int _SeatPracticeWindow_Init(Window* _this)
{
    if (_this->own->own->ioSystem->output = _this->own->own->resourceSystem->Get(_this->own->own->resourceSystem, _this->own->own->windowSystem->type))
        _this->own->own->ioSystem->size = strlen(_this->own->own->ioSystem->output);
    _this->own->own->ioSystem->InputBufferClear(_this->own->own->ioSystem);
}

int _WordPracticeWindow_Init(Window* _this)
{

}

int _ShortSentencePracticeWindow_Init(Window* _this)
{

}

int _LongSentencePracticeWindow_Init(Window* _this)
{

}


int _Window_Draw(Window * _this)
{
    TextViewLinkedList* view;
    view = _this->views;

    printf(_this->title);
    printf("\n");
    
    while (view && view->contents)
    {
        view->contents->Draw(view->contents);

        view = view->next;
    }

    return 0;
}

int _Window_AddView(Window * _this, TextView * _view)
{
    TextViewLinkedList* view;

    if (_this->views == 0)
    {
        _this->views = CreateTextViewLinkedList();
        _this->views->contents = _view;
    }
    else
    {
        view = _this->views;

        while (view->next)
            view = view->next;

        view->next = CreateTextViewLinkedList();
        view->next->pre = view;

        view->next->contents = _view;
    }

    return 0;
}
