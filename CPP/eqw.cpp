#include <iostream>
#include <fstream>
using namespace std;

class a
{
	int num;
public:
	friend void display(a &p);
	a(a &l)
	{
	num = l.num;
	}
	a operator + (a &k);
	friend istream & operator>>(istream &,a &);
	a();
public:
	void kk();
public:
	static int k;
};


void a::kk()
{
	cout<<k<<endl;
}

void display(a &p)
{
	cout<<p.k<<endl;
}

int a::k=10;

a::a()
{
	k++;
}

int main( )
{
//	char a[100];
//	gets(a);
//	fstream out("enen.txt",ios::out);
//	out<<a<<endl;
	a p[5];
	p[1].kk();
	p[1].k++;
	display(p[1]);
    return 0;
}
