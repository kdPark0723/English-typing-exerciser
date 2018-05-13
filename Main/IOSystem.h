#pragma once

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

    // Ű���� �Է°� �ޱ�
    int(*Get)(struct _IOSystem* _this);
    // �Է� ��� ���� �ʱ�ȭ
    int(*Init)(struct _IOSystem* _this);
};

struct _IOSystem* CreateIOSystem(struct _Application* _own);

int _IOSystem_Get(struct _IOSystem* _this);
int _IOSystem_Init(struct _IOSystem* _this);

typedef struct _IOSystem IOSystem;