#include<iostream>
#include<string>
using namespace std;

class people
{
private:
    string name;
    string nation;
    int height;
    int weight;
public:
    void set( );
    void show( );
};

void people::set( )
{
    cout<<"������������Ϣ��"<<endl;
    cin>>name>>nation>>height>>weight;
}

void people::show( )
{
    cout<<"������"<<name<<endl;
    cout<<"������"<<nation<<endl;
    cout<<"��ߣ�"<<height<<endl;
    cout<<"���أ�"<<weight<<endl;
}

int main( )
{
    people a;
    a.set( );
    a.show( );
    return 0;
}
