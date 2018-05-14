#include "TextView.h"

TextView * CreateTextView(Window * _own)
{
    TextView* view;

    view = (TextView*)malloc(sizeof(TextView));

    view->own = _own;
    view->contents = 0;
    view->p_contents = 0;

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
int DestroryTextView(TextView* _view)
{
    //if (_view->contents)
    //    free(_view->contents);
    free(_view);

    return 0;
}

int DestroryTextViewLinkedList(TextViewLinkedList* _list)
{
    if (_list->contents)
        DestroryTextView(_list->contents);
    if (_list->next)
        DestroryTextViewLinkedList(_list->next);
    free(_list);

    return 0;
}

int _TextView_Draw(TextView * _this)
{
    if (_this->p_contents)
        return printf(*(_this->p_contents));
    else if (_this->contents)
        return printf(_this->contents);
    return 0;
}
