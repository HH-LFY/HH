#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 301*101;
int first[maxn],next[maxn],v[maxn];///ͷ��㣬��һ�㣬�ͱߵ��յ㣨��ѧ����ţ�
bool vis[maxn];    ///��¼�Ƿ���ʹ�
int link [maxn];///��¼��֮ƥ��ĵ�
int p , n ;
bool find ( int k )
{
    int i ;
    for ( i = first[k] ; i != -1 ;  i =next [i] )
    {///Ѱ����k���ӵĵ�
        if ( !vis [v[i]] )
        {///���û���ʹ�������ʲ����
            vis [ v[i]] =true ;
            if ( link [v[i]] == 0 || find ( link [v[i]] ) )
            {///�����ѧ����δƥ����û��������·
                link [v[i]] = k ;///��֮ƥ��
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
        if ( p > n ) ///���ѧ�����������ڿ����������Բ����ܴﵽƥ��
            cout <<"NO"<<endl;
        else
        {
            int i , j ;
            memset ( first , -1 , sizeof ( first ) );    ///��/ʼ����ͷ
            memset ( link , 0 , sizeof ( link ) ) ;        ///��ʼ��
            int e = 0 ;

            for ( i = 0 ; i < p ; i ++ )
            {
                int a ;
                scanf("%d",&a);
                for ( j = 0 ; j < a ; j ++ , e ++ )
                {
                    scanf("%d",&v[e]);
                    next [e] = first [i+1];    ///����������ͷ�˲���
                    first [i+1] = e ;        ///��¼����ͷ���
                }
            }
            bool ans = 0 ;
            for ( i = 0 ; i < p ; i ++ )
            {
                memset ( vis , 0 , sizeof ( vis ) ) ;
                if ( !find ( i + 1 ) )
                {///����Ҳ�����ĵ�ƥ��ĵ㣬��𰸾�ΪNO
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
