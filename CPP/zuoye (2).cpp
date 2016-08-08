#include <iostream>
#include <string>
using namespace std;

class people
{
public:
	void set();
	void show();
private:
	string name;
	string sex;
};

void people::set()
{
	cin>>name>>sex;
}

void people::show()
{
	cout<<"������"<<name<<endl<<"�Ա�"<<sex;
}

class student: public people
{
public:
    void set( );
    void show( );
	friend ostream & operator<<(ostream&,student&);
	friend istream & operator>>(istream&,student&);
private:
	int banji;
	int xuehao;
};
void student::show( )
{
    people::show( );
    cout<<" ѧ�ţ�"<<xuehao<<endl<<" �༶��"<<banji<<endl;
}

void student::set( )
{
    cout<<"������ѧ����Ϣ���������Ա�ѧ�ţ��༶���� "<<endl;
    people::set( );
    cin>>xuehao>>banji;
}

ostream&  operator << (ostream& put,student& c)
{
    c.people::show( );
    put<<endl;
    put<<"ѧ��:"<<c.xuehao<<endl;
    put<<"�༶��"<<c.banji<<endl;
	return put;
}
istream& operator >> (istream&cin,student& c)
{
    c.set( );
    return cin;
}

int main( )
{
    student a;
    cin>>a;
    cout<<a<<endl;
    return 0;
}
