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
	MessageBox(NULL,TEXT("��ʵ�ⲻ��Ӣ�����ˡ�"),TEXT(""),MB_OK);
	int a=MessageBox(NULL,TEXT("�о������ˣ�"),TEXT(""),MB_YESNO|MB_ICONQUESTION);
	if(a==IDYES)
	{
		int b=MessageBox(NULL,TEXT("��ȷ����"),TEXT(""),MB_YESNO|MB_ICONQUESTION);
		if(b==IDNO)
		{
			if(MessageBox(NULL,TEXT("��ʼ��ʽ����C���̣�"),TEXT(""),MB_RETRYCANCEL|MB_ICONHAND)==IDRETRY)
				hehe();
		}
		else
		{
			if(MessageBox(NULL,TEXT("������Ϸ,OK��"),TEXT(""),MB_YESNO)==IDYES)
				fun();
		}
	}
	else
	{
		MessageBox(NULL,TEXT("�ú���!"),TEXT(""),MB_OK);
	}
	return 0;
}

void fun()
{
	int k=MessageBox(NULL,TEXT("������Ϸ,OK��"),TEXT(""),MB_YESNO|MB_ICONHAND);
	fun();
}

void hehe()
{

	int k=MessageBox(NULL,TEXT("������Ϸ,OK��"),TEXT(""),MB_YESNO|MB_ICONHAND);
	if(k==IDYES)
	{
		MessageBox(NULL,TEXT("���ͣ�Ŭ�����飡"),TEXT(""),MB_OK);
	}
	else
	{
		hehe();
	}
}