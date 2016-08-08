#include<iostream>
using namespace std;

class a
{
public:
    a();
    a(double r,double l):real(r),image(l){}
    friend a operator  -(a &l,a &k);
private:
    double real;
    double image;
};

a::a()
{
    real=0;
    image=0;
}

a operator -(a &k,a &l)
{
    a c;
    c.real=k.real-l.real;
    c.image=k.image-l.image;
    return c;
}
