// CEST.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	void fun();
	void hehe();
 	// TODO: Place code here.
	MessageBox(NULL,TEXT("其实这不是英雄联盟。"),TEXT(""),MB_OK);
	int a=MessageBox(NULL,TEXT("感觉被逗了？"),TEXT(""),MB_YESNO|MB_ICONQUESTION);
	if(a==IDYES)
	{
		int b=MessageBox(NULL,TEXT("你确定？"),TEXT(""),MB_YESNO|MB_ICONQUESTION);
		if(b==IDNO)
		{
			if(MessageBox(NULL,TEXT("开始格式化【C】盘！"),TEXT(""),MB_RETRYCANCEL|MB_ICONHAND)==IDRETRY)
				hehe();
		}
		else
		{
			if(MessageBox(NULL,TEXT("别玩游戏,OK？"),TEXT(""),MB_YESNO)==IDYES)
				fun();
		}
	}
	else
	{
		MessageBox(NULL,TEXT("好孩子!"),TEXT(""),MB_OK);
	}
	return 0;
}

void fun()
{
	int k=MessageBox(NULL,TEXT("别玩游戏,OK？"),TEXT(""),MB_YESNO|MB_ICONHAND);
	fun();
}

void hehe()
{

	int k=MessageBox(NULL,TEXT("别玩游戏,OK？"),TEXT(""),MB_YESNO|MB_ICONHAND);
	if(k==IDYES)
	{
		MessageBox(NULL,TEXT("加油，努力读书！"),TEXT(""),MB_OK);
	}
	else
	{
		hehe();
	}
}