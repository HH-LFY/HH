#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int maxx = 15000 + 10;
int a[maxx], n;
int R[maxx],L[maxx];
stack<int> p;
void R_max_stack(){ ///�����Iλ�ÿ�ʼ��a[i]Ϊ���ֵ��������Ӱ���λ����������i��
    p.push(-1);
    for(int i = 0;i < n; ++i){
        while(p.top()!=-1 && a[i]>a[p.top()]){
            R[p.top()] = i - p.top();
            p.pop();
        }
        p.push(i);
    }
    while(!p.empty()){
        if(p.top() == -1){
            p.pop(); break;
        }
        R[p.top()] = n - p.top();
        p.pop();
    }
}
void L_max_stack(){///�����Iλ�ÿ�ʼ��a[i]Ϊ���ֵ��������Ӱ���λ����������i��
    p.push(-1);
    for(int i = n-1;i >= 0; --i){
        while(p.top()!=-1 && a[i]>a[p.top()]){
            L[p.top()] = p.top() - i;
            p.pop();
        }
        p.push(i);
    }
    while(!p.empty()){
        if(p.top() == -1){
            p.pop(); break;
        }
        L[p.top()] = p.top()+1;
        p.pop();
    }
}
void R_min_stack(){/// I ->  ��Ϊ��Сֵ��Ӱ��ķ�Χ
    p.push(-1);
    for(int i = 0;i < n; ++i){
        while(p.top()!=-1 && a[i]<a[p.top()]){
            R[p.top()] = i - p.top();
            p.pop();
        }
        p.push(i);
    }
    while(!p.empty()){
        if(p.top() == -1){
            p.pop();break;
        }
        R[p.top()] = n - p.top();
        p.pop();
    }
}
void L_min_stack(){/// <- I  ��Ϊ��Сֵ��Ӱ��ķ�Χ
    p.push(-1);
    for(int i = n-1;i >= 0; --i){
        while(p.top()!=-1 && a[i]<a[p.top()]){
            L[p.top()] = p.top() - i;
            p.pop();
        }
        p.push(i);
    }
    while(!p.empty()){
        if(p.top() == -1){
            p.pop();break;
        }
        L[p.top()] = p.top() + 1;
        p.pop();
    }
}

int main( ){

    while(cin>>n){
        for(int i = 0;i < n; ++i){
            scanf("%d",&a[i]);
        }

        ///L_max_stack();
        ///R_max_stack();

        L_min_stack();
        R_min_stack();

        long long ans = 0;

        for(int i = 0;i < n; ++i){
            printf("%d ",R[i]);
        }
        printf("\n");
        for(int i = 0;i < n; ++i){
            printf("%d ",L[i]);
        }
        printf("\n%lld\n",ans);
    }
    return 0;
}

/**

5
5 4 3 2 1

5
1 2 3 4 5

5
2 1 3 5 9

*/
