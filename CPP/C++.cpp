#include<iostream>
using namespace std;

class rectangle
{
public:
    rectangle(double x=0,double y=0);
    ~rectangle( );
    void set(double x,double y);
    void show( );
    void getarea( );
private:
    double a;
    double b;
};

rectangle::rectangle(double x,double y)
{
    a = x;
    b = y;
}

rectangle::~rectangle()
{
    cout<<"对该对象的调用结束！"<<endl;
}

void rectangle::set(double x,double y)
{
    a = x;
    b = y;
}

void rectangle::show( )
{
    cout<<"矩形长："<<a<<endl;
    cout<<"矩形宽："<<b<<endl;
}

void rectangle::getarea()
{
    double s;
    s=a*b;
    cout<<"矩形面积："<<s<<endl;
}

int main()
{
    rectangle k;
    k.show();
    k.getarea();
    k.set(2,9);
    k.show();
    k.getarea();
    return 0;
}
