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
    cout<<"请输入人物信息："<<endl;
    cin>>name>>nation>>height>>weight;
}

void people::show( )
{
    cout<<"姓名："<<name<<endl;
    cout<<"国籍："<<nation<<endl;
    cout<<"身高："<<height<<endl;
    cout<<"体重："<<weight<<endl;
}

int main( )
{
    people a;
    a.set( );
    a.show( );
    return 0;
}
