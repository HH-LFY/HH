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
    cout<<"�Ըö���ĵ��ý�����"<<endl;
}

void rectangle::set(double x,double y)
{
    a = x;
    b = y;
}

void rectangle::show( )
{
    cout<<"���γ���"<<a<<endl;
    cout<<"���ο�"<<b<<endl;
}

void rectangle::getarea()
{
    double s;
    s=a*b;
    cout<<"���������"<<s<<endl;
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
