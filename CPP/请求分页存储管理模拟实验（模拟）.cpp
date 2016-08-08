#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#include <map>
#include <set>
using namespace std;

map<int,int> p; ///ҳ��IDӳ����������λ��
set<int> all_page;///����ҳ���
set<int>::iterator it;///��ʱ������
int MAXN;///���������Դ洢��ҳ��
int count_page; ///��Ҫװ���ҳ������
int id_page[10000];///ҳ���ҳ������ô�ID
int throw_page;///ҳ�涪ʧ��

void init_pagee(){
    int ppp[]={1, 2, 1, 3, 1, 2, 4, 5, 1, 3};
    int randd[]={12,23,52,1,5,42,52,52,52,45};
    printf("���������ָ���ַ����Ϊ��");
    for(int i = 0;i < 10; ++i){
        printf("%dB ",ppp[i]*1024 + randd[i]);
    }
    puts("");
    printf("ҳ��ߴ�Ϊ1KB \n");
}

void display(){
    printf("��ǰ�����д��ڵ�ҳ�����£�");
    for(it = all_page.begin(); it != all_page.end(); ++it)
        printf("%d ",*it);
    printf("\n");
}

void page_insert(int address,int id){
    if(MAXN<=0){
        throw "page count is min!!!";
        ///printf("�����СΪ0���޷����в��룡����\n");
        return ;
    }
    if(all_page.find(id) != all_page.end()){
        printf("��ҳ��%d����������������룡\n",id);
        p[id]=address;
    }else if(all_page.size()<MAXN){///����δ����ֱ�Ӳ���
        printf("����δ����ҳ��%d����ֱ�Ӳ��룡\n",id);
        all_page.insert(id);
        p[id]=address;
        throw_page++;
    }else{
        int taotai_id;
        int taotai_min;
        for(it=all_page.begin(),taotai_id=*it,taotai_min=p[taotai_id];it!=all_page.end(); ++it){
            if(p[*it]<taotai_min){
                taotai_min = p[*it];
                taotai_id = *it;
            }
        }
        printf("ҳ��%d������δ��ʹ�ã�����̭��\n",taotai_id);
        printf("ҳ��%d������������У�\n",id);
        all_page.erase(taotai_id);
        all_page.insert(id);
        p[id]=address;
        throw_page++;
    }
}

int main( ){
    init_pagee();
    printf("�����СΪ��");
    cin>>MAXN;
    printf("��Ҫװ���ҳ������");
    cin>>count_page;
    throw_page = 0;
    printf("%d��ҳ���ҳ������ô�����������ʾ����\n",count_page);
    for(int i = 1;i <= count_page; ++i){
        cin>>id_page[i];
    }
    printf("����LRU�㷨��\n");
    for(int i = 1;i <= count_page; ++i){
        //printf("\n���ڳ��Խ�ҳ���Ϊ%d��ҳ����������.....\n",id_page[i]);
        page_insert(i,id_page[i]);
        display();
        //system("pause");
    }
    printf("\nһ����ʧ%d��ҳ��\n",throw_page );
    printf("ȱҳ��Ϊ��%.6f\n",(double)((double)(throw_page*1.0)/(double)(count_page*1.0)));
    return 0;
}
/**
1 2 1 3 1 2 4 5 1 3


7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
