#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 301*101;
int first[maxn],next[maxn],v[maxn];///头结点，下一点，和边的终点（即学生编号）
bool vis[maxn];    ///记录是否访问过
int link [maxn];///记录与之匹配的点
int p , n ;
bool find ( int k )
{
    int i ;
    for ( i = first[k] ; i != -1 ;  i =next [i] )
    {///寻找与k连接的点
        if ( !vis [v[i]] )
        {///如果没访问过，则访问并标记
            vis [ v[i]] =true ;
            if ( link [v[i]] == 0 || find ( link [v[i]] ) )
            {///如果该学生还未匹配课堂或存在增广路
                link [v[i]] = k ;///与之匹配
                return true ;
            }
        }
    }
    return false;
}
int main()
{
    int t ;
    scanf("%d",&t) ;
    while ( t -- )
    {
        scanf("%d%d",&p,&n) ;
        if ( p > n ) ///如果学生人数都少于课堂数，明显不可能达到匹配
            cout <<"NO"<<endl;
        else
        {
            int i , j ;
            memset ( first , -1 , sizeof ( first ) );    ///初/始化表头
            memset ( link , 0 , sizeof ( link ) ) ;        ///初始化
            int e = 0 ;

            for ( i = 0 ; i < p ; i ++ )
            {
                int a ;
                scanf("%d",&a);
                for ( j = 0 ; j < a ; j ++ , e ++ )
                {
                    scanf("%d",&v[e]);
                    next [e] = first [i+1];    ///插入链表，从头端插入
                    first [i+1] = e ;        ///记录链表头结点
                }
            }
            bool ans = 0 ;
            for ( i = 0 ; i < p ; i ++ )
            {
                memset ( vis , 0 , sizeof ( vis ) ) ;
                if ( !find ( i + 1 ) )
                {///如果找不到与改点匹配的点，则答案就为NO
                    ans =true;
                    break;
                }
            }
            if ( ans )
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}
