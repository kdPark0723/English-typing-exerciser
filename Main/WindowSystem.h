#pragma once

#include "Application.h"
#include "Window.h"

#define WINDOW_NUM 4

typedef struct _WindowSystem
{
    // ���� ���α׷�
    Application* own;
    // ������ �ִ� ������� (�̸� ������ ������� �� ����)
    Window* windows[WINDOW_NUM];
    // ����� ������ Ÿ�� (windows�� index���� ����)
    int type;
    
    // ���� ������Ʈ
    int(*Update)(struct _WindowSystem* _this);
    // ȭ�� ����� system�Լ��� ����
    int(*Clear)(struct _WindowSystem* _this);
    // ȭ�� �׸���
    int(*Draw)(struct _WindowSystem* _this);
    // ȭ�� �ٲٱ� (�ɹ� type�� ���� �����ؼ� �ٲ㵵 ���̾����� ���� ���� ��)
    int(*ChangeWindow)(struct _WindowSystem* _this, int _type);
} WindowSystem;

// ���丮 �Լ�
WindowSystem* CreateWindowSystem(Application* _own);

int _WindowSystem_Update(WindowSystem* _this);
int _WindowSystem_Clear(WindowSystem* _this);
int _WindowSystem_Draw(WindowSystem* _this);
int _WindowSystem_ChangeWindow(WindowSystem* _this, int _type);

