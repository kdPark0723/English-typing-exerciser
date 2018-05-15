#ifndef __WINDOWSYSTEM_H__
#define __WINDOWSYSTEM_H__

#include "Application.h"
#include "Window.h"

#define WINDOW_NUM 5

struct _WindowSystem
{
    // 소유 프로그램
    struct _Application* own;
    // 가지고 있는 윈도우들 (미리 지정된 순서대로 들어가 있음)
    struct _Window* windows[WINDOW_NUM];
    // 출력할 윈도우 타입 (windows의 index값과 동일)
    int type;
    
    // 윈도우 초기화
    int(*InitWindow)(struct _WindowSystem* _this);
    // 화면 지우기 system함수로 구현
    int(*Clear)(struct _WindowSystem* _this);
    // 화면 그리기
    int(*Draw)(struct _WindowSystem* _this);
    // 화면 바꾸기 (맴버 type에 직접 접근해서 바꿔도 차이없을듯 삭제 생각 중)
    int(*ChangeWindow)(struct _WindowSystem* _this, int _type);
};

// 펙토리 함수
struct _WindowSystem* CreateWindowSystem(struct _Application* _own);

int DestroyWindowSystem(struct _WindowSystem* _windowSystem);

int _WindowSystem_Update(struct _WindowSystem* _this);
int _WindowSystem_Clear(struct _WindowSystem* _this);
int _WindowSystem_Draw(struct _WindowSystem* _this);
int _WindowSystem_ChangeWindow(struct _WindowSystem* _this, int _type);

int _WindowSystem_InitWindow(struct _WindowSystem* _this);

typedef struct _WindowSystem WindowSystem;

#endif
