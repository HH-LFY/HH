#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

int main( )
{
    ofstream ko("cs.txt",ios::in|ios::out);
    string a,b;
  ///  ko.open("cs.txt",ios::in|ios::out);
    cin>>a;
    ko<<a<<endl;
    return 0;
}
