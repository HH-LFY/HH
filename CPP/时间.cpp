#include <iostream.h>
#include <windows.h>
#include <stdio.h>

void time()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	printf("%4d��%3d��%3d��   %3dʱ%3d��\n",s.wYear,s.wMonth,s.wDay,s.wHour,s.wMinute);
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