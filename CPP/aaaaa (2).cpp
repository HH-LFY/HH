#include<iostream>
using namespace std;
class student
{
public :
    void s1();
     double zscode;
    int number;
private:
    double scode1;
    double scode2;
    double scode3;
    double scode4;

};
student a[6];
void student::s1()
{
    cin>>scode1>>scode2>>scode3>>scode4;
}
int main()
{
    int i;
    for(i=0;i<5;i++)
        a[i].s1();
    for(i=0;i<5;i++)
    {
 ///       a[i].zscode=a[i].scode1+a[i].scode2+a[i].scode3+a[i].scode4;
    }
    a[5].zscode=0;
    for(i=0;i<4;i++)
    {
        if(a[i].zscode>a[i+1].zscode)
        a[5]=a[i];
    else
         a[5]=a[i+1];
    }
    cout<<"number"<<a[5].number<<endl<<"zscode"<<a[5].zscode<<endl;
    return(0);


}
