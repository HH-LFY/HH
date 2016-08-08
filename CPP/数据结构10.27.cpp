#include <iostream>
#include <cstdio>
#include <malloc.h>
#include "algo-2.h"
using namespace std;

void CreateListR(Sqlist *&L,Elemtype e[],int n)
{
    Initlist(L);
    int i;
    ListInsert(L,1,e[0]);
    for(i = 1;i < n; ++i)
    {
        if(!LocateElem(L,e[i]))
            ListInsert(L,i+1,e[i]);
    }
}

void sort(Sqlist *&L)
{
    int i, j;
    for(i = 0;i < L->length; ++i)
    {
        for(j = 0;j < L->length; ++j)
        {
            if(L->data[i] < L->data[j])
            {
                char t = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = t;
            }
        }
    }
}

void Union(Sqlist *a,Sqlist *b,Sqlist *&c)
{
    Initlist(c);
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while(i<a->length && j<b->length)
    {
        if(a->data[i] < b->data[j])
        {
            ListInsert(c,k+1,a->data[i]);
            k++;
            i++;
        }
        else if(a->data[i] == b->data[j])
        {
            ListInsert(c,k+1,a->data[i]);
            k++;
            i++;
            j++;
        }
        else
        {
            ListInsert(c,k+1,b->data[j]);
            k++;
            j++;
        }
    }
    while(i<a->length)
    {
        ListInsert(c,k+1,a->data[i]);
        i++;
        k++;
    }
    while(j<b->length)
    {
        ListInsert(c,k+1,b->data[j]);
        j++;
        k++;
    }
}

void InsterSect(Sqlist *a,Sqlist *b,Sqlist *&c)
{
    DestroyList(c);
    Initlist(c);
    int i ,k;
    for(i = 0,k = 0;i < a->length; ++i)
    {
        if(LocateElem(b,a->data[i]))
        {
            ListInsert(c,k+1,a->data[i]);
            k++;
        }
    }
}

void Subs(Sqlist *a,Sqlist *b,Sqlist *&c)
{
    DestroyList(c);
    Initlist(c);
    int i ,k;
    for(i = 0,k = 0;i < a->length; ++i)
    {
        if(!LocateElem(b,a->data[i]))
        {
            ListInsert(c,k+1,a->data[i]);
            k++;
        }
    }
}

int main( )
{
    Sqlist *ha, *hb, *hc;
    Elemtype a[]={'c','a','e','h'};
    Elemtype b[]={'f','h','b','g','d','a'};
    printf("集合的运算如下\n");
    CreateListR(ha,a,4);
    CreateListR(hb,b,6);
    printf("原 集 合 A:"); DispList(ha);
    printf("原 集 合 B:"); DispList(hb);
    sort(ha);
    sort(hb);
    printf("有序集合A："); DispList(ha);
    printf("有序集合B："); DispList(hb);
    Union(ha,hb,hc);
    printf("集合的并C："); DispList(hc);
    InsterSect(ha,hb,hc);
    printf("集合的交C："); DispList(hc);
    Subs(ha,hb,hc);
    printf("集合的差C："); DispList(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}
