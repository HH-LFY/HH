//student.h
#include<string>
using namesapce std;
class student
{
public:
    void display();
private:
    int num;
    string name;
    char sex;
};
//student.cpp
#include<iostream>
#include"student.h"
void student::display()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
}
