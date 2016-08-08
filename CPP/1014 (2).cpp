#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int gcb(int a,int b)
{
    if(b==0)return a;
    else return gcb(b,a%b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(gcb(a,b)==1) {printf("%10d%10d",a,b);printf("    Good Choice\n");}
        else {printf("%10d%10d",a,b);printf("    Bad Choice\n");}
        printf("\n");
    }
    return 0;
}
