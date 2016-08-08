#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1010],b[1010];
int lena,lenb;

int getLcs(int i,int j)
{
    if(i>=lena || j>=lenb)
        return 0;
    if(a[i]==b[j])
        return 1+getLcs(i+1,j+1);
    int temp1 = getLcs(i+1,j);
    int temp2 = getLcs(i,j+1);
    return max(temp1,temp2);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        scanf("%s%s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        printf("%d\n",getLcs(0,0));
    }
    return 0;
}

