#include<iostream>
using namespace std;
int main()
{
    int swap(int &a,int &b);
    int i=3,j=5;
    swap(i,j);
    cout<<"i="<<i<<",j="<<j<<endl;
    return 0;

}
int swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
    return 0;
}
