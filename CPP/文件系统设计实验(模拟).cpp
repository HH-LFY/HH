#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <conio.h>
#include <map>
#include <set>
#include <vector>
#include <windows.h>
#define pause system("pause")
using namespace std;

struct file{
    string name;
    int len;
    int flag;
};
struct UFD{
    int kcount;
    file p[100];
    int vis[100];
}user[3];
map<int,string> MDF;
string now;


void init(){
    MDF[0] = "huang";MDF[1] = "song";MDF[2] = "seng";
    for(int i = 0;i < 3; ++i){
        user[i].kcount = 0;
    }
}

void show_User_Name(){
    for(int i = 0;i < 3; ++i)cout<<MDF[i]<<" ";
    puts("");
}

int find_file(string name,int uid){
    for(int i = 0;i < user[uid].kcount;++i){
        if(user[uid].vis[i]&&name == user[uid].p[i].name){
            return i;
        }
    }
    return -1;
}

void show_User_file(int uid){
    if(user[uid].kcount == 0){
        printf("���û�Ŀ¼�ļ�����û���ļ���\n");
        return ;
    }
    for(int i = 0;i < user[uid].kcount; ++i){
        if(user[uid].vis[i]){
            cout<<"�ļ���:"<<user[uid].p[i].name<<" ��д���:";
            if(user[uid].p[i].flag)cout<<"�ɶ�д";
            else cout<<"���ɶ�д";
            cout<<" �ļ����ȣ�"<<user[uid].p[i].len<<endl;
            }
    }
    puts("");
}


int main( ){
    init();
ls5:
    printf("���ļ�ϵͳ���������û���\n");
    show_User_Name();
    printf("��ѡ����Ҫ�������û��ļ��С�");
ls1:
    printf("������ȷ���û����������ѡ��");
    cin>>now;
    int know;
    if(now == "huang"){
        know = 0;
    }else if(now == "song"){
        know = 1;
    }else if(now == "peng"){
        know = 2;
    }else{
        printf("�û�������������������룡��\n");
        goto ls1;
    }
    ls6:
    show_User_file(know);
    printf("��ѡ����Ҫ���еĲ�����\n");
    printf("1.����һ���ļ�\n");
    printf("2.ɾ��һ���ļ�\n");
    printf("3.�򿪲���д�ļ�\n");
    printf("4.����\n");
    char cc = getch();
    if(cc == '1'){
        file temp;
        printf("��������Ҫ�������ļ����ļ�����");
        cin>>temp.name;
    ls2:
        printf("�����ø��ļ��Ķ�д����(1����ɽ��ж�д��0�����ɶ�д)��");
        cin>>temp.flag;
        if(temp.flag != 1 && temp.flag != 0){
            printf("����������1����0��");
            goto ls2;
        }
        printf("�������ļ��ĳ���(������)��");
        cin>>temp.len;
        user[know].vis[user[know].kcount] = 1;
        user[know].p[user[know].kcount++] = temp;
    }else if(cc == '2'){
        ls3:
        printf("��������Ҫɾ�����ļ����ļ�����");
        string kname;
        cin>>kname;
        int del = find_file(kname,know);
        if(del == -1){
            printf("���ļ������ڣ���������ȷ���ļ���������\n");
            goto ls3;
        }
        user[know].vis[del] = 0;
        cout<<"�ļ�"<<kname<<"ɾ���ɹ���"<<endl;
    }else if(cc == '3'){
        ls4:
        printf("��������Ҫ�򿪵��ļ����ļ�����");
        string kname;
        cin>>kname;
        int change = find_file(kname,know);
        if(change == -1){
            printf("���ļ������ڣ���������ȷ���ļ���������\n");
            goto ls4;
        }
        if(user[know].p[change].flag){
            printf("�ɹ��򿪸��ļ���\n");
        }else{
            printf("�򿪸��ļ�ʧ�ܣ����ļ��������û����ж�д��\n");
        }
    }else if(cc == '4'){
        goto ls5;
    }else{
        printf("���������������������룡��\n");
        goto ls6;
    }
    goto ls6;
    return 0;
}
