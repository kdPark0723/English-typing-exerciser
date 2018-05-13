#ifndef __TextView_H_
#define __TextView_H_

#include "Window.h"

struct _TextView
{
    // ���� ������
    struct _Window* own;
    // ����
    char* contents;

    // �׸���
    int(*Draw)(struct _TextView* _this);
};

// �ý�Ʈ �ο� �����Ұ��� �����.
struct _TextViewLinkedList
{
    // ������ �ִ� ���
    struct _TextView* contents;

    //������ ��µ� ��
    struct _TextViewLinkedList* pre;
    // ���� ��µ� ��
    struct _TextViewLinkedList* next;

};

// ���丮 �Լ�
struct _TextView* CreateTextView(struct _Window* _own);
struct _TextViewLinkedList* CreateTextViewLinkedList();

int DestroryTextView(struct _TextView* _view);
int DestroryTextViewLinkedList(struct _TextViewLinkedList* _list);

int _TextView_Draw(struct _TextView* _this);

typedef struct _TextView TextView;
typedef struct _TextViewLinkedList TextViewLinkedList;

#endif