#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct CNode
{
    int k;  ///端点
    int w; ///权值，或k到已经求出最短路的那些点的最短距离
};
bool operator < ( const CNode & d1, const CNode & d2 )
{
    return d1.w > d2.w;   ///priority_queue总是将最大的元素出列
}
int aDist[30010];
priority_queue<CNode> pq;
bool bUsed[30010]= {0};
///vector<CNode> v[30010];  error,如果用这个，则在poj会超时。说明vector对象的初始化，也是需要可观时间的
vector<vector<CNode> > v;
const unsigned int INFINITE = 100000000;
int main()
{
    int N,M,a,b,c;
    int i,j,k;

    CNode p, q;

    scanf("%d%d", & N, & M );

    v.clear();
    v.resize(N+1);

    memset( bUsed,0,sizeof(bUsed));
    for( i = 1; i <= M; i ++ )
    {

        scanf("%d%d%d", & a, & b, & c);
        p.k = b;
        p.w = c;
        v[a].push_back( p);
    }
    p.k = 1;
    p.w = 0;
    pq.push ( p);
    while( !pq.empty ())
    {
        p = pq.top ();
        pq.pop();
        if( bUsed[p.k])  ///已经求出了最短路
            continue;
        bUsed[p.k] = true;
        if( p.k == N )
            break;

        for( i = 0, j = v[p.k].size(); i < j; i ++ )
        {
            q.k = v[p.k][i].k;
            if( bUsed[q.k] )
                continue;
            q.w = p.w + v[p.k][i].w ;
            pq.push ( q); ///队列里面已经有q.k点也没关系
        }
    }
    printf("%d", p.w ) ;
    return 0;
}
