#include <iostream>
#include <cstdio>
#include <algorithm>
#include <conio.h>
#include <map>
#include <set>
using namespace std;

map<int,int> p; ///页面ID映射的最近出现位置
set<int> all_page;///主存页面池
set<int>::iterator it;///临时迭代器
int MAXN;///主存最大可以存储的页面
int count_page; ///需要装入的页面数量
int id_page[10000];///页面的页面号引用串ID
int throw_page;///页面丢失数

void init_pagee(){
    int ppp[]={1, 2, 1, 3, 1, 2, 4, 5, 1, 3};
    int randd[]={12,23,52,1,5,42,52,52,52,45};
    printf("随机产生的指令地址流如为：");
    for(int i = 0;i < 10; ++i){
        printf("%dB ",ppp[i]*1024 + randd[i]);
    }
    puts("");
    printf("页面尺寸为1KB \n");
}

void display(){
    printf("当前主存中存在的页面如下：");
    for(it = all_page.begin(); it != all_page.end(); ++it)
        printf("%d ",*it);
    printf("\n");
}

void page_insert(int address,int id){
    if(MAXN<=0){
        throw "page count is min!!!";
        ///printf("主存大小为0！无法进行插入！！！\n");
        return ;
    }
    if(all_page.find(id) != all_page.end()){
        printf("该页面%d已在主存中无需插入！\n",id);
        p[id]=address;
    }else if(all_page.size()<MAXN){///主存未满，直接插入
        printf("主存未满，页面%d可以直接插入！\n",id);
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
        printf("页面%d最近最久未被使用，被淘汰！\n",taotai_id);
        printf("页面%d被插入进主存中！\n",id);
        all_page.erase(taotai_id);
        all_page.insert(id);
        p[id]=address;
        throw_page++;
    }
}

int main( ){
    init_pagee();
    printf("主存大小为：");
    cin>>MAXN;
    printf("需要装入的页面数：");
    cin>>count_page;
    throw_page = 0;
    printf("%d个页面的页面号引用串（用整数表示）：\n",count_page);
    for(int i = 1;i <= count_page; ++i){
        cin>>id_page[i];
    }
    printf("调用LRU算法：\n");
    for(int i = 1;i <= count_page; ++i){
        //printf("\n正在尝试将页面号为%d的页面置入主存.....\n",id_page[i]);
        page_insert(i,id_page[i]);
        display();
        //system("pause");
    }
    printf("\n一共丢失%d个页面\n",throw_page );
    printf("缺页率为：%.6f\n",(double)((double)(throw_page*1.0)/(double)(count_page*1.0)));
    return 0;
}
/**
1 2 1 3 1 2 4 5 1 3


7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
