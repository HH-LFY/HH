#include <iostream>
#include <cstdio>
#include <malloc.h>
using namespace std;

#define maxn 50
typedef char Elemtype;
typedef struct
{
    Elemtype data[maxn];
    int length;
}Sqlist;

void Initlist(Sqlist *&L)
{
    L =(Sqlist *)malloc(sizeof(Sqlist));
    L->length = 0;
}

bool ListInsert(Sqlist *&L, int x, char c)
{
    int j;
    if(x<1 || x>L->length+1)
        return false;
    x--;
    for(j = L->length; j>x ; --j)
    {
        L->data[j] = L->data[j-1];
    }
    L->data[x] = c;
    L->length++;
    return true;
}

bool ListEmpty(Sqlist *L)
{
    return (L->length==0);
}

void DispList(Sqlist *L)
{
    int i;
    if(ListEmpty(L)) return ;
    for(i = 0;i < L->length; ++i)
    {
        printf("%c",L->data[i]);
    }
    printf("\n");
}

int ListLength(Sqlist *L)
{
    return L->length;
}

bool GetElem(Sqlist *L,int x,Elemtype &c)
{
    if(x<1 || x>L->length)
        return false;
    c = L->data[x-1];
    return true;
}

int LocateElem(Sqlist *L,Elemtype e)
{
    int i = 0;
    while(i<L->length && L->data[i]!=e)
        i++;
    if(i==L->length)
        return 0;
    else
        return i+1;
}

bool ListDelete(Sqlist *&L,int x,Elemtype &e)
{
    int j;
    if(x<1 ||x >L->length + 1)
        return false;
    x--;
    e = L->data[x];
    for(j = x;j < L->length-1; ++j)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

void DestroyList(Sqlist *L)
{
    free(L);
}

int main( )
{
    Sqlist *p;
    Elemtype e;
    printf("(1)初始化顺序表p\n");
    Initlist(p);
    printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(p,1,'a');
    ListInsert(p,2,'b');
    ListInsert(p,3,'c');
    ListInsert(p,4,'d');
    ListInsert(p,5,'e');
    printf("(3)输出顺序表p:");
	DispList(p);
	printf("(4)顺序表p长度=%d\n",ListLength(p));
	printf("(5)顺序表p为%s\n",(ListEmpty(p)?"空":"非空"));
	GetElem(p,3,e);
	printf("(6)顺序表p的第3个元素=%c\n",e);
	printf("(7)元素a的位置=%d\n",LocateElem(p,'a'));
	printf("(8)在第4个元素位置上插入f元素\n");
	ListInsert(p,4,'f');
	printf("(9)输出顺序表p:");
	DispList(p);
	printf("(10)删除p的第3个元素\n");
    ListDelete(p,3,e);
	printf("(11)输出顺序表p:");
	DispList(p);
	printf("(12)释放顺序表p\n");
	DestroyList(p);
    return 0;
}
