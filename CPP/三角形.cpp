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
    cout<<"�Ը�Բ����ĵ��ý�����"<<endl;
}

void cirlce::set(double x,double y,double z)
{
    a = x;
    b = y;
    r = z;
}

void cirlce::show( )
{
    cout<<"Բ�����꣺��"<<a<<"��"<<b<<"��"<<endl;
    cout<<"Բ��ֱ����"<<2*r<<endl;
    cout<<"Բ���ܳ���"<<2*p*r<<endl;
    cout<<"Բ�������"<<p*r*r<<endl;
}

void cirlce::getarea()
{
    double s;
    s=p*r*r;
    cout<<"Բ�������"<<s<<endl;
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
