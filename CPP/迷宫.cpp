#include<cstdio>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#define M 4
#define N 4
#define MAX 100
using namespace std;
int x,y;
int mg[M+2][N+2]= {{1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},{1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}};

struct
{
    int i,j;
    int di;
} Stack[MAX],path[MAX], kis[MAX][MAX];

int ks[MAX];
int top=-1;
int count=1;
int minlen=MAX;

void show()
{
    int i, j;
    printf("程序正在为您搜索出迷宫的路径.....\n");
    for(i = 0; i < M+2; ++i)
    {
        for(j = 0; j< N + 2; ++j)
        {
            if(mg[i][j] == 1)
            {
                printf("#");
            }
            else if(mg[i][j] == 0)
            {
                printf(" ");
            }
            else if(mg[i][j] == -1)
            {
                printf("S");
            }
            else if(i == M && j == N)
            {
                printf("D");
            }
            else if(mg[i][j] == 2)
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

void mgpath(int xi,int yi,int xe,int ye)
{
    int i,j,di,find,k;
    top++;
    Stack[top].i=xi;
    Stack[top].j=yi;
    Stack[top].di=-1;
    mg[xi][yi]=-1;
    while(top>-1)
    {
        i=Stack[top].i;
        j=Stack[top].j;
        di=Stack[top].di;

        if(i==xe&&j==ye)
        {
            printf("成功找出第 %d 条路径: ",count++);
            for(k=0; k<=top; k++)
            {
                printf(" ( %d,%d ) ",Stack[k].i,Stack[k].j);
                kis[count][k].i = Stack[k].i;
                kis[count][k].j = Stack[k].j;
                if((k+1)%5==0)
                    printf("\n\t");
            }
            ks[count] = top;
            printf("\n");
            system("pause");
            system("cls");
            if(top+1<minlen)
            {
                for(k=0; k<=top; k++)
                    path[k]=Stack[k];
                minlen=top+1;
            }
            mg[Stack[top].i][Stack[top].j]=0;
            top--;
            i=Stack[top].i;
            j=Stack[top].j;
            di=Stack[top].di;
        }

        find=0;

        while(di<4&&find==0)
        {
            di++;
            switch(di)
            {
            case 0:
                i=Stack[top].i-1;
                j=Stack[top].j;
                break;
            case 1:
                i=Stack[top].i;
                j=Stack[top].j+1;
                break;
            case 2:
                i=Stack[top].i+1;
                j=Stack[top].j;
                break;
            case 3:
                i=Stack[top].i;
                j=Stack[top].j-1;
                break;
            }
            if(mg[i][j]==0)
                find=1;
        }

        if(find==1)
        {
            Stack[top].di=di;
            top++;
            Stack[top].i=i;
            Stack[top].j=j;
            Stack[top].di=-1;
            mg[i][j]=2;
            show();
            Sleep(1000);
            system("cls");
        }
        else
        {
            mg[Stack[top].i][Stack[top].j]=0;
            top--;
        }

    }
    printf("迷宫所有路径如下：\n");
    for(i = 2;i <= count; ++i)
    {
        printf("  %4d: ",i - 1);
        for(j = 0;j <= ks[count]; ++j)
        {
            printf(" ( %d,%d ) ",kis[i][j].i,kis[i][j].j);
            if((j+1)%5==0)
                printf("\n\t");
        }
        printf("\n");
    }
    printf("最短路径如下：\n");
    printf("长度:  %d\n",minlen);
    printf("路径    ");
    for(k=0; k<minlen; k++)
    {
        printf(" ( %d,%d ) ",path[k].i,path[k].j);
        if((k+1)%5==0)
            printf("\n\t");
    }
    printf("\n");
}

int main()
{
    ///printf("迷宫所有路径如下：\n");
    ///show();
    mgpath(1,1,M,N);
    return 0;
}
