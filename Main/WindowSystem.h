#ifndef __WINDOWSYSTEM_H__
#define __WINDOWSYSTEM_H__

#include "Application.h"
#include "Window.h"

#define WINDOW_NUM 5

struct _WindowSystem
{
    // ���� ���α׷�
    struct _Application* own;
    // ������ �ִ� ������� (�̸� ������ ������� �� ����)
    struct _Window* windows[WINDOW_NUM];
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
};

// ���丮 �Լ�
struct _WindowSystem* CreateWindowSystem(struct _Application* _own);

int DestroyWindowSystem(struct _WindowSystem* _windowSystem);

int _WindowSystem_Update(struct _WindowSystem* _this);
int _WindowSystem_Clear(struct _WindowSystem* _this);
int _WindowSystem_Draw(struct _WindowSystem* _this);
int _WindowSystem_ChangeWindow(struct _WindowSystem* _this, int _type);

typedef struct _WindowSystem WindowSystem;

#endif