#ifndef __TextView_H_
#define __TextView_H_

#include "Window.h"

struct _TextView
{
    // 소유 윈도우
    struct _Window* own;
    // 내용
    char* contents;

    // 그리기
    int(*Draw)(struct _TextView* _this);
};

// 택스트 부와 통합할건지 고민중.
struct _TextViewLinkedList
{
    // 가지고 있는 뷰들
    struct _TextView* contents;

    //그전에 출력될 뷰
    struct _TextViewLinkedList* pre;
    // 그후 출력될 뷰
    struct _TextViewLinkedList* next;

};

// 펙토리 함수
struct _TextView* CreateTextView(struct _Window* _own);
struct _TextViewLinkedList* CreateTextViewLinkedList();

int DestroryTextView(struct _TextView* _view);
int DestroryTextViewLinkedList(struct _TextViewLinkedList* _list);

int _TextView_Draw(struct _TextView* _this);

typedef struct _TextView TextView;
typedef struct _TextViewLinkedList TextViewLinkedList;

#endif