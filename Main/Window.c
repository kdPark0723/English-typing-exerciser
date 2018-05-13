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
    window->Update = _InitWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> 영문 타자 연습 프로그램 <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "1. 자리 연습         2. 낱말 연습 \n3. 짧은 글 연습      4. 긴 글 연습 \n5. 프로그램 종료\n\n번호를 입력하세요: ";
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
    window->Update = _SeatPracticeWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> 영문 타자 연습 프로그램 : 자리연습 <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "진행도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->progress, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   오타수 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->numOfTypo, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    정확도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->accuracy, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    if (_own->own->ioSystem && _own->own->ioSystem->output)
        view->contents = _own->own->ioSystem->output;
    else
        view->contents = "\0";
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

    window->title = ">> 영문 타자 연습 프로그램 : 낱말 연습 <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "진행도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->progress, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   오타수 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->numOfTypo, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    정확도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->accuracy, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    if (_own->own->ioSystem &&_own->own->ioSystem->output)
        view->contents = _own->own->ioSystem->output;
    else
        view->contents = "\0";
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

    window->title = ">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "진행도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->progress, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   현재타수 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->currentTypingCount, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "   최고타수 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->highestTypingCount, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "    정확도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->accuracy, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    if (_own->own->ioSystem &&_own->own->ioSystem->output)
        view->contents = _own->own->ioSystem->output;
    else
        view->contents = "\0";
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
    window->Update = _LongSentencePracticeWindow_Update;
    window->AddView = _Window_AddView;

    window->title = ">> 영문 타자 연습 프로그램 : 긴 글 연습 <<";
    window->views = 0;

    view = CreateTextView(window);
    view->contents = "정확도 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->accuracy, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "%%   현재타수 : ";
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = (char*)malloc(sizeof(char) * 4);
    intToString(_own->own->currentTypingCount, view->contents, 4, 10);
    window->AddView(window, view);

    view = CreateTextView(window);
    view->contents = "\n\n";
    window->AddView(window, view);

    view = CreateTextView(window);
    if (_own->own->ioSystem &&_own->own->ioSystem->output)
        view->contents = _own->own->ioSystem->output;
    else
        view->contents = "\0";
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

int _InitWindow_Update(Window * _this)
{
    return 0;
}

int _SeatPracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    intToString(_this->own->own->progress, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->numOfTypo, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->accuracy, view->contents->contents, 4, 10);
    view = view->next->next;

    if (_this->own->own->ioSystem && _this->own->own->ioSystem->output)
        view->contents->contents = _this->own->own->ioSystem->output;
    else
        view->contents->contents = "\0";

    return 0;
}

int _WordPracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    intToString(_this->own->own->progress, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->numOfTypo, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->accuracy, view->contents->contents, 4, 10);

    return 0;
}

int _ShortSentencePracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    intToString(_this->own->own->progress, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->currentTypingCount, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->highestTypingCount, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->accuracy, view->contents->contents, 4, 10);

    return 0;
}

int _LongSentencePracticeWindow_Update(Window * _this)
{
    TextViewLinkedList* view;

    view = _this->views->next;

    intToString(_this->own->own->accuracy, view->contents->contents, 4, 10);
    view = view->next->next;

    intToString(_this->own->own->currentTypingCount, view->contents->contents, 4, 10);

    return 0;
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
