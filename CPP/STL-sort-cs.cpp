#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <istream>
#include <fstream>
#define PI 3.141592653
using namespace std;

struct node
{
    int x;
    int y;
};

ostream &operator << (ostream &out,const node &a)
{
    out<<"x-> "<<a.x<<" y->"<<a.y<<endl;
    return out;
}

int cmd(node a,node b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main( )
{
    node a[10];
    for(int i = 0;i < 10; i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+10,cmd);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i];
    }
    return 0;
}
