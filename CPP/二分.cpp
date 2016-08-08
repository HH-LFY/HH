#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int erfen_search(int a[],int n,int key){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(a[mid] == key){
            return mid;
        }else if(a[mid] > key){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}

int main( )
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d \n",erfen_search(a,10,3));
    return 0;
}
