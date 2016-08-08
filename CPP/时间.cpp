#include <iostream.h>
#include <windows.h>
#include <stdio.h>

void time()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	printf("%4d年%3d月%3d日   %3d时%3d分\n",s.wYear,s.wMonth,s.wDay,s.wHour,s.wMinute);
}

int main()
{
	while(1)
	{
		printf("\n\n");
		printf("----------------------------------------------\n");
		time();
		printf("----------------------------------------------\n");
		system("cls");
	}
	return 0;
}