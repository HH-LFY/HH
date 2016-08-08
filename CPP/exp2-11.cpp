#include <stdio.h>
#include <malloc.h>
#include "algo2-11.h"

extern void InitList(SqList *&L);  //动态分配内存
extern void DestroyList(SqList *L);  //动态释放内存
extern int ListEmpty(SqList *L); //判断顺序表是否为空
extern int ListLength(SqList *L);  //输出顺序表的长度
extern void DispList(SqList L);  //输出顺序表
extern int GetElem(SqList *L,int i,ElemType &e); //获取第 I 个元素
extern int LocateElem(SqList *L, ElemType e);  //定位元素 e 的位置
extern int ListInsert(SqList *L,int i,ElemType e); //插入元素 e 到第 I 个位置
extern int ListDelete(SqList *L,int i,ElemType &e); //删除第 I 个位置的元素

int main()
{
	SqList L;
	ElemType e;
	printf("(1)初始化顺序表L\n");
	L.length=0;  //初始化长度为 0
	printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(&L,1,'a');
	ListInsert(&L,2,'b');
	ListInsert(&L,3,'c');
	ListInsert(&L,4,'d');
	ListInsert(&L,5,'e');
	printf("(3)输出顺序表L:");
	DispList(L);
	printf("(4)顺序表L长度=%d\n",ListLength(&L));
	printf("(5)顺序表L为%s\n",(ListEmpty(&L)?"空":"非空"));
	GetElem(&L,3,e);
	printf("(6)顺序表L的第3个元素=%c\n",e);
	printf("(7)元素a的位置=%d\n",LocateElem(&L,'a'));
	printf("(8)在第4个元素位置上插入f元素\n");
	ListInsert(&L,4,'f');
	printf("(9)输出顺序表L:");
	DispList(L);
	printf("(10)删除L的第3个元素\n");
    ListDelete(&L,3,e);
	printf("(11)输出顺序表L:");
	DispList(L);
	printf("(12)释放顺序表L\n");
//	DestroyList(&L);  //因为 L 被分配的是静态内存，程序运行结束后静态内存将自动释放，无需 DestroyList()
	return 0;
}
