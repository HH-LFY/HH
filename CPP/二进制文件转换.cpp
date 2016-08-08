#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
	char c;
	int k = 0;
	ofstream out("file.dat",ios::binary);
	while((c=getchar())!='#')
	{
		if(((c>='a')&&(c<='v'))||((c>='A')&&(c<='V')))
			c=c+4;
		else if(((c>='W')&&(c<='Z'))||((c>='w')&&(c<='z')))
			c=c-22;
		out.write(&c,sizeof(c));
		k++;
	}
	out.close();
	ifstream in("file.dat",ios::binary);
	while(k--)
	{
		in.read(&c,sizeof(c));
		if(((c>='e')&&(c<='z'))||((c>='E')&&(c<='Z')))
			c=c-4;
		else if(((c>='A')&&(c<='D'))||((c>='a')&&(c<='d')))
			c=c+22;
		cout<<c;
	}
	cout<<endl;
	in.close();
	return  0;
}