#include<iostream>
using namespace std;

const double p = 3.1415926;

class cirlce
{
public:
    cirlce(double x=0,double y=0,double z=0);
    ~cirlce( );
    void set(double x,double y,double z);
    void show( );
    void getarea( );
private:
    double a;
    double b;
    double r;
};

cirlce::cirlce(double x,double y,double z)
{
    a = x;
    b = y;
    r = z;
}

cirlce::~cirlce()
{
    cout<<"对该圆对象的调用结束！"<<endl;
}

void cirlce::set(double x,double y,double z)
{
    a = x;
    b = y;
    r = z;
}

void cirlce::show( )
{
    cout<<"圆心坐标：（"<<a<<"，"<<b<<"）"<<endl;
    cout<<"圆的直径："<<2*r<<endl;
    cout<<"圆的周长："<<2*p*r<<endl;
    cout<<"圆的面积："<<p*r*r<<endl;
}

void cirlce::getarea()
{
    double s;
    s=p*r*r;
    cout<<"圆的面积："<<s<<endl;
}

int main()
{
    cirlce k;
    k.show();
    k.getarea();
    k.set(20,30,5);
    k.show();
    k.getarea();
    return 0;
}
