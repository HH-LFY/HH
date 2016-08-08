#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 40000 + 10;
char str1[maxx*2], str2[maxx*2];
int n;
int T;

int work1(){
    int i = 0, j = 1, k;
    while(i<n && j<n){
        if(str1[i] < str1[j]){
            i = j;
            j = i + 1;
        }else if(str1[i] > str1[j]){
            j++;
        }else{
            k = 0;
            while(k < n){
                if(str1[i+k] > str1[j+k]){
                    j = j+k;
                    break;
                }else if(str1[i+k] < str1[j+k]){
                    i = j;
                    j = j+k;
                    break;
                }
                k++;
            }
            if(k == n){
                return i;
            }
        }
    }
    return i;
}

int work2(){
    int i = 0, j = 1, k;
    while(i<n && j<n){
        if(str2[i] < str2[j]){
            i = j;
            j = i + 1;
        }else if(str2[i] > str2[j]){
            j++;
        }else{
            k = 0;
            while(k < n){
                if(str2[i+k] > str2[j+k]){
                    j = j+k;
                    break;
                }else if(str2[i+k] < str2[j+k]){
                    i = j;
                    j = j+k;
                    break;
                }
                k++;
            }
            if(k == n){
                i = j;
                j = i+1;
            }
        }
    }
    return i;
}

int main( ){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        scanf("%s",str1);
        for(int i = 0;i < n; ++i){
            str1[i+n] = str1[i];
        }
        str1[n*2] = '\0';
        for(int i = 0;i < 2*n; ++i){
            str2[i] = str1[2*n-i-1];
        }
        str2[n*2] = '\0';

        int m1 = work1();
        int m2 = work2();


        int judge = 0;
        for(int i = 0; i < n; ++i){
            if(str1[m1+i]<str2[m2+i]){
                judge = 1;
                break;
            }else if(str1[m1+i]>str2[m2+i]){
                judge = -1;
                break;
            }
        }

        m1 = m1+1;
        m2 = n-m2;
        ///printf("%d %d\n",m1,m2);


        if(judge == 1){
            printf("%d 1\n",m2);
        }else if(judge == -1){
            printf("%d 0\n",m1);
        }else{
            if(m1 <= m2){
                printf("%d 0\n",m1);
            }else{
                printf("%d 1\n",m2);
            }
        }
    }
    return 0;
}

/**
5
4
cbbc
6
abcabc


*/
