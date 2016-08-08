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
#include <set>
#define PI 3.141592653
using namespace std;

int main( )
{
    set<int>p;
    p.insert(2);
    int x;
    cin>>x;
    p.insert(x);
    set<int>::iterator q;
    q=p.begin();
    cout<<*q<<endl;
    q++;
    cout<<*q<<endl;
    cout<<p.count(100)<<endl;
    return 0;
}
