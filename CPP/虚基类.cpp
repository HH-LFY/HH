#include <iostream>
using namespace std;

class graph
{
public:
	virtual void mianji();
};

void graph :: mianji()
{
	cerr<<"请指向正确的对象地址！！"<<endl;
}
//**********************************割***********************************//
//**********************************矩形类***********************************//
class juxing:  public graph
{
public:
	juxing (int a=0,int b=0):chang(a),kuan(b){}
	void mianji();
private:
	int chang;
	int kuan;
};
void juxing::mianji()
{
	cout<<"矩形的面积是："<<chang*kuan<<endl;
}
//**********************************割***********************************//
class yuan:virtual public graph
{
public:
	yuan (double a):r(a){}
	void mianji();
private:
	double r;
};


void yuan::mianji()
{
	cout<<"圆形的面积是："<<3.14*r*r<<endl;
}
//**********************************割***********************************//

int main( )
{
	graph a;

	graph *p=&a;
	p->mianji();

	juxing b(8,9);
	p=&b;
	p->mianji();

	yuan c(8);
	p=&c;
	p->mianji();

	return 0;

}