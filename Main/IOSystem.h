#ifndef __IOSYSTEM_H__
#define __IOSYSTEM_H__

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000

struct _IOSystem
{
    // ���� ���α׷�
    struct _Application* own;

    // ����� �� - ������ �ý��ۿ��� ������
    char* output;
    // �Էµ� ��
    char input[INPUT_MAX];
    // �Էµ� ���� ��
    int count;
    // �Էµɼ� �ִ� ������ ��
    int size;

    // Ű���� �Է°� �ޱ�
    int(*Update)(struct _IOSystem* _this);
    // �Է� ���� �ʱ�ȭ
    int(*InputBufferClear)(struct _IOSystem* _this);
    // ��� ���� �ʱ�ȭ
    int(*OutputBufferClear)(struct _IOSystem* _this);
    // ��� ���� �ʱ�ȭ
    int(*SetOutput)(struct _IOSystem* _this, char* _buffer);
};

struct _IOSystem* CreateIOSystem(struct _Application* _own);
int DestroyIOSystem(struct _IOSystem* _ioSystem);

int _IOSystem_Update(struct _IOSystem* _this);
int _IOSystem_InputBufferClear(struct _IOSystem* _this);
int _IOSystem_OutputBufferClear(struct _IOSystem* _this);

int _IOSystem_SetOutput(struct _IOSystem* _this, char* _buffer);

typedef struct _IOSystem IOSystem;

#endif