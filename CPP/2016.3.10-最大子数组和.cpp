#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main( ){
    int a[] = {1,-2,3,10,-4,7,2,-5};
    int ans = a[0]; ///��¼��
    int temp = a[0];///��¼��ǰֵ
    for(int i = 1;i < 8; ++i){
        temp = max(a[i],temp+a[i]);
        if(ans<temp){
            ans = temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
