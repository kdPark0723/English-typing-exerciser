#include "TextView.h"

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

int _TextView_Draw(TextView * _this)
{
    return printf(_this->contents);
}
