#pragma once

#define MESSAGE_MAX 10

#define MESSAGE_EMTY 0
#define MESSAGE_EXIT 1
#define MESSAGE_DEL 2
#define MESSAGE_ENTER 3
#define MESSAGE_CHANGE 4
#define MESSAGE_INPUT 5

struct _Message
{
    // �޼��� �̸�
    int name;

    // ����
    char content;
};

typedef struct _Message Message;