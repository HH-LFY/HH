#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int i = 1;
void move(int n,char s,char e){
    printf("��%d��������%d�����Ӵ� %c �Ƶ� %c ��\n",i++,n,s,e);
}
void hanoi(int n,char a,char b,char c){
    if(n == 1){
        move(n,a,b);
    }else{
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
int main(){
    hanoi(2,'a','b','c');
    return 0;
}
