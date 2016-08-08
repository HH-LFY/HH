#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main( )
{
    int t,k;
    double t1,t2;
    int v;
    int h,m,s;
    cin>>t;
    while(t--)
    {
        cin>>h>>m>>s;
  ///      for(h=0;h<=24;h++)
 ///       {
  ///          for(m=0;m<=60;m++)
///            {
  ///              for(s=0;s<=60;s++)
  ///              {
 ///                 if(h>24) h-=12;
 //                 double result;
 //                 result = ( h + m/60.0 + s/3600.0 )*30 -( m + s/60.0 )*6 ;
 ///                 result = fabs(result);
 /////                 if(result>180)  k=(int)(360.0-result);
 ////                 else k=(int)result;
 /////                 t1 = ( h + m/60.0 + s/3600.0 )*30 ;
/////                 t2 = ( m + s/60.0 )*6 ;
  ///////                v=fabs(t1-t2) > 180 ? 360 - fabs(t1-t2) :fabs(t1-t2);
  /////              }
  /////          }
 //////       }

		t1 = ( h%12 + m/60.0 + s/3600.0 )*30 ;
		t2 = ( m + s/60.0 )*6 ;
		v=fabs(t1-t2) > 180 ? 360 - fabs(t1-t2) :fabs(t1-t2);
		cout<<v<<endl;
    }
    return 0;
}
