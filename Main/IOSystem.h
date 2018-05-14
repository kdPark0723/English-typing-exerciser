#ifndef __IOSYSTEM_H__
#define __IOSYSTEM_H__

#include <stdio.h>

#include "Application.h"

#define INPUT_MAX 1000
#define PIPE_MAX 100

struct _Pipe
{
    int* input;
    char* output;

    char** poutput;

    int(*Synchronization)(struct _Pipe* _this);
};

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
    // ���� ���ڿ� ����� ��������
    struct _Pipe* pipes[PIPE_MAX];
    int pipeSize;

    // Update
    int(*Update)(struct _IOSystem* _this);
    // Ű���� �Է°� �ޱ�
    int(*CheckKeyboard)(struct _IOSystem* _this);
    // �Է� ���� �ʱ�ȭ
    int(*InputBufferClear)(struct _IOSystem* _this);
    // ��� ���� �ʱ�ȭ
    int(*OutputBufferClear)(struct _IOSystem* _this);
    // ��� ���� ����
    int(*SetOutput)(struct _IOSystem* _this, char* _buffer);
    // ������ ����
    int(*LinkPipe)(struct _IOSystem* _this, int* _input, char** _output);
};

struct _Pipe* CreatePipe();
int DestroyPipe(struct _Pipe* _pipe);

int _Pipe_Synchronization(struct _Pipe* _this);

struct _IOSystem* CreateIOSystem(struct _Application* _own);
int DestroyIOSystem(struct _IOSystem* _ioSystem);

int _IOSystem_CheckKeyboard(struct _IOSystem* _this);
int _IOSystem_Update(struct _IOSystem* _this);
int _IOSystem_InputBufferClear(struct _IOSystem* _this);
int _IOSystem_OutputBufferClear(struct _IOSystem* _this);

int _IOSystem_SetOutput(struct _IOSystem* _this, char* _buffer);
int _IOSystem_LinkPipe(struct _IOSystem* _this, int* _input, char** _output);

typedef struct _Pipe Pipe;

typedef struct _IOSystem IOSystem;

#endif