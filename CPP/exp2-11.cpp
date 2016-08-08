#include <stdio.h>
#include <malloc.h>
#include "algo2-11.h"

extern void InitList(SqList *&L);  //��̬�����ڴ�
extern void DestroyList(SqList *L);  //��̬�ͷ��ڴ�
extern int ListEmpty(SqList *L); //�ж�˳����Ƿ�Ϊ��
extern int ListLength(SqList *L);  //���˳���ĳ���
extern void DispList(SqList L);  //���˳���
extern int GetElem(SqList *L,int i,ElemType &e); //��ȡ�� I ��Ԫ��
extern int LocateElem(SqList *L, ElemType e);  //��λԪ�� e ��λ��
extern int ListInsert(SqList *L,int i,ElemType e); //����Ԫ�� e ���� I ��λ��
extern int ListDelete(SqList *L,int i,ElemType &e); //ɾ���� I ��λ�õ�Ԫ��

int main()
{
	SqList L;
	ElemType e;
	printf("(1)��ʼ��˳���L\n");
	L.length=0;  //��ʼ������Ϊ 0
	printf("(2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(&L,1,'a');
	ListInsert(&L,2,'b');
	ListInsert(&L,3,'c');
	ListInsert(&L,4,'d');
	ListInsert(&L,5,'e');
	printf("(3)���˳���L:");
	DispList(L);
	printf("(4)˳���L����=%d\n",ListLength(&L));
	printf("(5)˳���LΪ%s\n",(ListEmpty(&L)?"��":"�ǿ�"));
	GetElem(&L,3,e);
	printf("(6)˳���L�ĵ�3��Ԫ��=%c\n",e);
	printf("(7)Ԫ��a��λ��=%d\n",LocateElem(&L,'a'));
	printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(&L,4,'f');
	printf("(9)���˳���L:");
	DispList(L);
	printf("(10)ɾ��L�ĵ�3��Ԫ��\n");
    ListDelete(&L,3,e);
	printf("(11)���˳���L:");
	DispList(L);
	printf("(12)�ͷ�˳���L\n");
//	DestroyList(&L);  //��Ϊ L ��������Ǿ�̬�ڴ棬�������н�����̬�ڴ潫�Զ��ͷţ����� DestroyList()
	return 0;
}
