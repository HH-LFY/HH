#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

map<int,string> p;

int main()
{
    double vis[20];
    vis[0] = 23651/202500;
    vis[1] = 92531/202500;
    vis[2] = 104334/202500;
    vis[3] = 108562/202500;
    vis[4] = 115289/202500;
    vis[5] = 114340/202500;
    vis[6] = 26138/202500;
    vis[7] = 145424/202500;
    vis[8] = 150214/202500;
    vis[9] = 116240/202500;
    vis[10] = 91667/202500;
    vis[11] = 0.172100;



    p[0] = "Baekhyun";
    p[1] = "Chanyeol";
    p[2] = "Chen";
    p[3] = "D.O";
    p[4] = "Kai";
    p[5] = "Kris";
    p[6] = "Lay";
    p[7] = "Luhan";
    p[8] = "Sehun";
    p[9] = "Suho";
    p[10] = "Tao";
    p[11] = "Xiumin";

    int T;
    cin>>T;
    while(T--){
        double n;
        cin>>n;
        int m;
        scanf("%d",&m);
        double sum = 0;
        int x;
        for(int i = 0;i < m; ++i){
            scanf("%d",&x);
            if(i%2)sum += x;
        }

        double kx = (double)sum/(n*n);

        for(int i = 0;i < m; ++i){
            if((kx - 0.0005)<=vis[i] &&vis[i] <= (kx + 0.0005) ){
                cout<<p[i]<<endl;
                break;
            }
        }

    }
    return 0;
}
