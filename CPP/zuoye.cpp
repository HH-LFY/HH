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
	cout<<"姓名："<<name<<endl<<"性别："<<sex;
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
    cout<<" 学号："<<xuehao<<endl<<" 班级："<<banji<<endl;
}

void student::set( )
{
    cout<<"请输入学生信息（姓名，性别，学号，班级）： "<<endl;
    people::set( );
    cin>>xuehao>>banji;
}

ostream&  operator << (ostream& put,student& c)
{
    c.people::show( );
    put<<endl;
    put<<"学号:"<<c.xuehao<<endl;
    put<<"班级："<<c.banji<<endl;
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
