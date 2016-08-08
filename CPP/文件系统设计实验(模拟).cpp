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
        printf("该用户目录文件夹下没有文件！\n");
        return ;
    }
    for(int i = 0;i < user[uid].kcount; ++i){
        if(user[uid].vis[i]){
            cout<<"文件名:"<<user[uid].p[i].name<<" 读写情况:";
            if(user[uid].p[i].flag)cout<<"可读写";
            else cout<<"不可读写";
            cout<<" 文件长度："<<user[uid].p[i].len<<endl;
            }
    }
    puts("");
}


int main( ){
    init();
ls5:
    printf("该文件系统中有如下用户：\n");
    show_User_Name();
    printf("请选择您要操作的用户文件夹。");
ls1:
    printf("输入正确的用户名即可完成选择：");
    cin>>now;
    int know;
    if(now == "huang"){
        know = 0;
    }else if(now == "song"){
        know = 1;
    }else if(now == "peng"){
        know = 2;
    }else{
        printf("用户名输入错误！请重新输入！！\n");
        goto ls1;
    }
    ls6:
    show_User_file(know);
    printf("请选择你要进行的操作：\n");
    printf("1.创建一个文件\n");
    printf("2.删除一个文件\n");
    printf("3.打开并读写文件\n");
    printf("4.后退\n");
    char cc = getch();
    if(cc == '1'){
        file temp;
        printf("请输入你要创建的文件的文件名：");
        cin>>temp.name;
    ls2:
        printf("请设置该文件的读写限制(1代表可进行读写，0代表不可读写)：");
        cin>>temp.flag;
        if(temp.flag != 1 && temp.flag != 0){
            printf("请输入数字1或者0：");
            goto ls2;
        }
        printf("请设置文件的长度(正整数)：");
        cin>>temp.len;
        user[know].vis[user[know].kcount] = 1;
        user[know].p[user[know].kcount++] = temp;
    }else if(cc == '2'){
        ls3:
        printf("请输入你要删除的文件的文件名：");
        string kname;
        cin>>kname;
        int del = find_file(kname,know);
        if(del == -1){
            printf("该文件不存在！请输入正确的文件名！！！\n");
            goto ls3;
        }
        user[know].vis[del] = 0;
        cout<<"文件"<<kname<<"删除成功！"<<endl;
    }else if(cc == '3'){
        ls4:
        printf("请输入你要打开的文件的文件名：");
        string kname;
        cin>>kname;
        int change = find_file(kname,know);
        if(change == -1){
            printf("该文件不存在！请输入正确的文件名！！！\n");
            goto ls4;
        }
        if(user[know].p[change].flag){
            printf("成功打开该文件！\n");
        }else{
            printf("打开该文件失败！该文件不允许用户进行读写！\n");
        }
    }else if(cc == '4'){
        goto ls5;
    }else{
        printf("您的输入有误，请重新输入！！\n");
        goto ls6;
    }
    goto ls6;
    return 0;
}
