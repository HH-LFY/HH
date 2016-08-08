#include <iostream>
#include <fstream>
using namespace std;

class a
{
	static int k;
public:
	a();
	void kk();
};
void a::kk()
{
	cout<<k<<endl;
}

a::a()
{
	k++;
}

int main( )
{
	a p;
	p.kk();
    return 0;
}
