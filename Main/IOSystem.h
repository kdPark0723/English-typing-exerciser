#pragma once

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000

typedef struct _IOSystem
{
    // ���� ���α׷�
    Application* own;

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
} IOSystem;

IOSystem* CreateIOSystem(Application* _own);

int _IOSystem_Get(IOSystem* _this);
int _IOSystem_Init(IOSystem* _this);