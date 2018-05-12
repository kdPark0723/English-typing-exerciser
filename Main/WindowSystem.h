#pragma once

#include "Application.h"
#include "Window.h"

#define WINDOW_NUM 4

typedef struct _WindowSystem
{
    // 소유 프로그램
    Application* own;
    // 가지고 있는 윈도우들 (미리 지정된 순서대로 들어가 있음)
    Window* windows[WINDOW_NUM];
    // 출력할 윈도우 타입 (windows의 index값과 동일)
    int type;
    
    // 정보 업데이트
    int(*Update)(struct _WindowSystem* _this);
    // 화면 지우기 system함수로 구현
    int(*Clear)(struct _WindowSystem* _this);
    // 화면 그리기
    int(*Draw)(struct _WindowSystem* _this);
    // 화면 바꾸기 (맴버 type에 직접 접근해서 바꿔도 차이없을듯 삭제 생각 중)
    int(*ChangeWindow)(struct _WindowSystem* _this, int _type);
} WindowSystem;

// 펙토리 함수
WindowSystem* CreateWindowSystem(Application* _own);

int _WindowSystem_Update(WindowSystem* _this);
int _WindowSystem_Clear(WindowSystem* _this);
int _WindowSystem_Draw(WindowSystem* _this);
int _WindowSystem_ChangeWindow(WindowSystem* _this, int _type);

