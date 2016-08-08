 #include <iostream>
 using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void swap(double &a, double &b)
{
    double t=a;
    a=b;
    b=t;
}
 class s
 {
     int num;
     int score;
 public:
    void set( );
    void display( );
 protected:
    void hehe( );
public:
    void en( );
 };

 void s::set( )
 {
     cin>>num>>score;
 }

 void s::display( )
 {
     cout<<num<<" --- "<<score<<endl;;
 }

 void s::hehe( )
 {
     cout<<"hehehe!"<<endl;
 }

 void s::en( )
 {
     cout<<"en"<<endl;
 }

class k:public s
{
};

int main( )
 {

     int a=1,cout,printf;
     int b=9;
     swap(a,b);
     double c=1.1;
     double d=2.2;
 //    swap(c,d);

     k  p;
//     p.en();
//     p.set( );
//     p.display( );
//    cout<<c<<" "<<d<<endl;
//     cout<<a<<" "<<b<<endl;
//     s k;
//     k.set( );
//     k.display( );
//     k.en( );
return 0;
 }
