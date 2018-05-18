#include "Platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
#include <conio.h>
#elif (_PLATFORM_TYPE == _PLATFORM_LINUX || _PLATFORM_TYPE == _PLATFORM_UNIX)
#include <termio.h>
int _getche(void);
int _getch(void);
#endif

#define TYPE_MENU 0
#define TYPE_SEATPRACTICE 1
#define TYPE_WORDPRACTICE 2
#define TYPE_SHORTSENTENCEPRACTICE 3
#define TYPE_LONGSENTENCEPRACTICE 4

#define RESOURCE_SIZE_SEATPRACTICE 52

#define INPUT_MAX 1000

int run(void);

int check_keyboard(void);

int screen_clear(void);

int screen_change(int _type);

int screen_draw(void);

int menu_draw(void);
int seat_practice_draw(void);
int word_practice_draw(void);
int short_sentence_practice_draw(void);
int long_sentence_practice_draw(void);

int input_keyboard(char _input);

int menu_input_keyboard(char _input);
int seat_practice_input_keyboard(char _input);
int word_practice_input_keyboard(char _input);
int short_sentence_practice_input_keyboard(char _input);
int long_sentence_practice_input_keyboard(char _input);

int input_keyboard_enter(void);

int menu_input_keyboard_enter(void);
int seat_practice_input_keyboard_enter(void);
int word_practice_input_keyboard_enter(void);
int short_sentence_practice_input_keyboard_enter(void);
int long_sentence_practice_input_keyboard_enter(void);

int input_keyboard_backspace(void);

int menu_input_keyboard_backspace(void);
int seat_practice_input_keyboard_backspace(void);
int word_practice_input_keyboard_backspace(void);
int short_sentence_practice_input_keyboard_backspace(void);
int long_sentence_practice_input_keyboard_backspace(void);

char* get_resource(void);

int is_running = 0;

int progress = 0;
int num_of_typo = 0;
int accuracy = 0;

int current_typing_count = 0;
int highest_typing_count = 0;

// ������� �Է��� ����
int typing_count = 0;

// �ð�
clock_t start_time = 0;
clock_t finsh_time = 0;

int window_type = 0;

// ����� ��
char* output_buffer = 0;
// �Էµ� ��
char input_buffer[INPUT_MAX] = { 0 };
// �Էµ� ���� ��
int input_num = 0;
// �Էµɼ� �ִ� ������ ��
int input_max = 0;;

char* resorce_seat_practice[RESOURCE_SIZE_SEATPRACTICE] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

int main(void)
{
    is_running = 1;

    srand(time(NULL));
    run();

    return 0;
}

int run(void)
{
    input_max = 1;

    while (is_running)
    {
        screen_clear();
        screen_draw();
        check_keyboard();
    }

    return 0;
}

int check_keyboard(void)
{
    char ch;

    if (input_max > input_num)
        ch = _getche();
    else
        ch = _getch();

    if (ch == '\x1B')
    {
        if (window_type)
            screen_change(TYPE_MENU);
    }
    else if (ch == '\x7F' || ch == '\x8')
    {
        if (input_num > 0)
        {
            input_num--;
            input_buffer[input_num] = 0;
        }
        input_keyboard_backspace();
    }
    else if (ch == '\x0D' || ch == '\x0A')
    {
        input_keyboard_enter();
    }
    else
    {
        if (input_max > input_num)
        {
            input_buffer[input_num] = ch;
            input_num++;
        }

        input_keyboard(ch);
    }

    return 0;
}

int screen_clear(void)
{
#if (_PLATFORM_TYPE == _PLATFORM_WIN32)
    return system("CLS");
#elif (_PLATFORM_TYPE == _PLATFORM_LINUX || _PLATFORM_TYPE == _PLATFORM_UNIX)
    return system("clear");
#endif
}

int screen_change(int _type)
{

    if (_type == 5)
    {
        is_running = 0;

        return _type;
    }

    window_type = _type;

    progress = 0;
    num_of_typo = 0;
    accuracy = 0;

    current_typing_count = 0;
    highest_typing_count = 0;

    typing_count = 0;

    start_time = clock();
    finsh_time = 0;

    output_buffer = get_resource();

    for (; input_num > 0; --input_num)
        input_buffer[input_num-1] = 0;

    switch (window_type)
    {
    case TYPE_MENU:
        input_max = 1;
        break;
    case TYPE_SEATPRACTICE:
        input_max = strlen(output_buffer);
        break;
    case TYPE_WORDPRACTICE:

        break;
    case TYPE_SHORTSENTENCEPRACTICE:

        break;
    case TYPE_LONGSENTENCEPRACTICE:

        break;
    default:
        break;
    }


    return _type;
}
int screen_draw(void)
{
    switch (window_type)
    {
    case TYPE_MENU:
        menu_draw();
        break;
    case TYPE_SEATPRACTICE:
        seat_practice_draw();
        break;
    case TYPE_WORDPRACTICE:
        word_practice_draw();
        break;
    case TYPE_SHORTSENTENCEPRACTICE:
        short_sentence_practice_draw();
        break;
    case TYPE_LONGSENTENCEPRACTICE:
        long_sentence_practice_draw();
        break;
    default:
        break;
    }

    return 0;
}

int input_keyboard(char _input)
{
    switch (window_type)
    {
    case TYPE_MENU:
        menu_input_keyboard(_input);
        break;
    case TYPE_SEATPRACTICE:
        seat_practice_input_keyboard(_input);
        break;
    case TYPE_WORDPRACTICE:
        word_practice_input_keyboard(_input);
        break;
    case TYPE_SHORTSENTENCEPRACTICE:
        short_sentence_practice_input_keyboard(_input);
        break;
    case TYPE_LONGSENTENCEPRACTICE:
        long_sentence_practice_input_keyboard(_input);
        break;
    default:
        break;
    }

    return 0;
}

int menu_input_keyboard(char _input)
{
    return 0;
}
int seat_practice_input_keyboard(char _input)
{
    if (progress < 100 && output_buffer)
    {
        if (output_buffer[input_num - 1] == _input)
        {
            progress += 5;

            output_buffer = get_resource();
            for (; input_num > 0; --input_num)
                input_buffer[input_num - 1] = 0;
        }
        else
            num_of_typo += 1;

        typing_count++;
        accuracy = 100 - num_of_typo * 100 / typing_count;
    }

    if (progress == 100)
        output_buffer = 0;

    return 0;
}
int word_practice_input_keyboard(char _input)
{
    return 0;
}
int short_sentence_practice_input_keyboard(char _input)
{
    return 0;
}
int long_sentence_practice_input_keyboard(char _input)
{
    return 0;
}

int input_keyboard_enter(void)
{
    switch (window_type)
    {
    case TYPE_MENU:
        menu_input_keyboard_enter();
        break;
    case TYPE_SEATPRACTICE:
        seat_practice_input_keyboard_enter();
        break;
    case TYPE_WORDPRACTICE:
        word_practice_input_keyboard_enter();
        break;
    case TYPE_SHORTSENTENCEPRACTICE:
        short_sentence_practice_input_keyboard_enter();
        break;
    case TYPE_LONGSENTENCEPRACTICE:
        long_sentence_practice_input_keyboard_enter();
        break;
    default:
        break;
    }

    return 0;
}

int menu_input_keyboard_enter(void)
{
    if (input_num > 0 && input_buffer[input_num - 1])
        screen_change(input_buffer[input_num - 1] - '0');

    return 0;
}

int seat_practice_input_keyboard_enter(void)
{
    if (progress == 100)
        screen_change(TYPE_MENU);

    return 0;
}

int word_practice_input_keyboard_enter(void)
{
    return 0;
}

int short_sentence_practice_input_keyboard_enter(void)
{
    return 0;
}

int long_sentence_practice_input_keyboard_enter(void)
{
    return 0;
}

int input_keyboard_backspace(void)
{
    switch (window_type)
    {
    case TYPE_MENU:
        menu_input_keyboard_backspace();
        break;
    case TYPE_SEATPRACTICE:
        seat_practice_input_keyboard_backspace();
        break;
    case TYPE_WORDPRACTICE:
        word_practice_input_keyboard_backspace();
        break;
    case TYPE_SHORTSENTENCEPRACTICE:
        short_sentence_practice_input_keyboard_backspace();
        break;
    case TYPE_LONGSENTENCEPRACTICE:
        long_sentence_practice_input_keyboard_backspace();
        break;
    default:
        break;
    }

    return 0;
}

int menu_input_keyboard_backspace(void)
{
    return 0;
}
int seat_practice_input_keyboard_backspace(void)
{
    return 0;
}
int word_practice_input_keyboard_backspace(void)
{
    return 0;
}
int short_sentence_practice_input_keyboard_backspace(void)
{
    return 0;
}
int long_sentence_practice_input_keyboard_backspace(void)
{
    return 0;
}

int menu_draw(void)
{
    printf(">> ���� Ÿ�� ���� ���α׷� <<\n");
    printf("1. �ڸ� ����         2. ���� ����\n");
    printf("3. ª�� �� ����      4. �� �� ���� \n");
    printf("5. ���α׷� ����\n\n");
    printf("��ȣ�� �Է��ϼ���: %s", input_buffer);

    return 0;
}

int seat_practice_draw(void)
{
    printf(">> ���� Ÿ�� ���� ���α׷� : �ڸ����� <<\n");
    printf("���൵ : %d    ��Ÿ�� : %d    ��Ȯ�� : %d%%\n\n", progress, num_of_typo, accuracy);
    if (output_buffer)
        printf("%s\n", output_buffer);
    printf("%s", input_buffer);

    return 0;
}

int word_practice_draw(void)
{
    return 0;
}

int short_sentence_practice_draw(void)
{
    return 0;
}

int long_sentence_practice_draw(void)
{
    return 0;
}

char* get_resource(void)
{
    char* ch = 0;

    switch (window_type)
    {
    case TYPE_MENU:
        break;
    case TYPE_SEATPRACTICE:
        ch = resorce_seat_practice[rand() % RESOURCE_SIZE_SEATPRACTICE];
        break;
    case TYPE_WORDPRACTICE:

        break;
    case TYPE_SHORTSENTENCEPRACTICE:

        break;
    case TYPE_LONGSENTENCEPRACTICE:

        break;
    default:
        break;
    }

    return ch;
}

#if (_PLATFORM_TYPE == _PLATFORM_LINUX || _PLATFORM_TYPE == _PLATFORM_UNIX)
int _getche(void)
{
    int ch;

    struct termios _old;
    struct termios _new;

    tcgetattr(0, &_old);

    _new = _old;
    _new.c_lflag |= (ICANON | ECHO);
    _new.c_cc[VMIN] = 1;
    _new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &_new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &_old);

    return ch;
}
int _getch(void)
{
    int ch;

    struct termios _old;
    struct termios _new;

    tcgetattr(0, &_old);

    _new = _old;
    _new.c_lflag |= (ICANON | ECHO);
    _new.c_cc[VMIN] = 1;
    _new.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &_new);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &_old);

    return ch;
}
#endif