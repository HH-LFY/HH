#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
    { 
    string b[100],s,m;  //姓名   
    string d[3];//课程名
    int c[100];//学号
    int a[100][3];//学生分数 100表示学生数  3表示课程数
int n,i,j,w,t,k,t1,n1;
ofstream outfile("f1.dat",ios::out);
if(!outfile)
{
	cerr<<"open error!"<<endl;
}
b[0]="系"   ;outfile<< b[0]<<" ";
c[0]=01;   outfile<< c[0]<<" ";  ;
a[0][0]=12; outfile<<a[0][0] <<" "; ;
a[0][1]=76; outfile<<a[0][1] <<" ";;
a[0][2]=56; outfile<<a[0][2] <<" ";;
b[1]="跃" ; outfile<< b[1]<<" ";;
c[1]=02     ; outfile<< c[1]<<" ";;
a[1][0]=86 ;outfile<<a[1][0] <<" ";;
a[1][1]=64; outfile<<a[1][1] <<" ";;
a[1][2]=43; outfile<<a[1][2]<<" ";;
d[1]="语文" ;
d[2]="数学"; 
d[0]="英语" ; 
b[2]="达" ;  outfile<< b[2]<<" ";;
c[2]=03    ; outfile<< c[2]<<" ";;
a[2][0]=  91; outfile<<a[2][0] <<" "; ;
a[2][1]=  23; outfile<<a[2][1] <<" ";;
a[2][2]=  38; outfile<<a[2][2] <<" ";;
cout<<" 增加学生信息 请输入1 "<<endl;
cout<<" 删除学生信息 请输入2 "<<endl;
cout<<" 根据姓名查询 请输入3"<<endl;
cout<<" 根据学号查询 请输入4 "<<endl;
cout<<" 输入任意一个课程名和一个分数段（如：60 70）统计出此分数段学生信息 请输入 5"<<endl;
cout<<" 输入课程名，按升序排列学生信息  请输入 6"<<endl;
while(cin>>w)
{
if(w==1)
{
cout<<"请输入要增加的学生数";
cout<<endl;
cin>>n;
cout<<"请依次输入姓名，学号，语文分数，数学分数，英语分数";
cout<<endl;
for(i=3;i<n+3;i++)
{
{
cin>>b[i] ;outfile<< b[i]<<" ";;
cin>>c[i]; outfile<< c[i]<<" ";;
}
for(j=0;j<3;j++)
{
cin>>a[i][j] ;outfile<< a[i][j]<<" ";;
}
}
cout<<"姓名    学号       语文    数学     英语 :";
cout<<endl;
for(i=0;i<n+3;i++)
{
 {
cout<<b[i];
cout<<"         ";
cout<<c[i];
cout<<"         ";
}
for(j=0;j<3;j++)
{
cout<<a[i][j];
cout<<"     ";}
cout<<endl;
}
outfile.close();
}
if(w==2)
{   cout<<" 请输入需要删除学生的学号"<<endl ;
	cin>>n;
	for(i=0;i<3;i++)
	{
		if (c[i]==n)
		{
		for(j=i;j<3;j++)
		{
		{
			t=c[j];c[j]=c[j+1];c[j+1]=t;
			s=b[j];b[j]=b[j+1];b[j+1]=s;
		}	
		for(k=0;k<3;k++)
		{
			 t1=a[j][k];a[j][k]=a[j+1][k];a[j+1][k]=t1;
		}
    	}
		}
	}
	outfile<<"修改后"<<" ";
	for(i=0;i<2;i++)
	
	{
		{
        cout<<b[i];outfile<< b[i]<<" ";
        cout<<"     ";
         cout<<c[i];outfile<< c[i]<<" ";
         cout<<"     ";
        }
         for(j=0;j<3;j++)
          {
           cout<<a[i][j];outfile<< a[i][j]<<" ";
           cout<<"     ";}
          cout<<endl;
         }
        outfile.close();
	
}
if(w==3)
{
	cout<<"请输入姓名"<<endl;
	cin>>m;
	outfile<< " 查询结果 "<<" ";
	for(i=0;i<3;i++)
{
		if(b[i]==m)
		{
			cout<<c[i]<<"      ";
			outfile<< c[i]<<" ";
			for(j=0;j<3;j++)
			{
				cout<<a[i][j]<<"    ";
				outfile<< a[i][j]<<" ";
			}
		}
} 
	outfile.close(); 
}

if(w==4)
{
	cout<<"请输入学号"<<endl;
	cin>>n;
	outfile<< " 查询结果 "<<" ";
	for(i=0;i<3;i++)
{
		if(c[i]==n)
		{
			cout<<b[i]<<"      ";
			outfile<< b[i]<<" ";
			for(j=0;j<3;j++)
			{
				cout<<a[i][j]<<"    ";
				outfile<< a[i][j]<<" ";
			}
		}
} 
	outfile.close(); 
}
if(w==5)
{
	cout<<"请输入课程名和一个分数段";
	cout<<endl;
	cin>>m;
	cout<<endl;
	cin>>t;
	cin>>t1;
	cout<<endl;
	outfile<< " 查询结果 "<<" ";
	for(i=0;i<3;i++)
	{
		if(d[i]==m)
		{
		for(j=0;j<3;j++)
	{
	if(a[j][i]<t1&&a[j][i]>t)
	{cout<<b[j]<<"   ";outfile<< b[j]<<" ";
	cout<<c[j]<<"   ";outfile<< c[j]<<" ";
	for(i=0;i<3;i++)
	cout<<a[j][i]<<endl;outfile<< a[j][i]<<" ";
	}
	
	}
	}
}
}
if(w==6)
{
	cout<<"请输入课程名";
	cout<<endl;
	cin>>m;
	for(i=0;i<3;i++)
	{
		if(d[i]==m)
		{
		for(k=0;k<2;k++)
		{
		for(j=0;j<2-k;j++)
		{ 
		if(a[j][i]>a[j+1][i])
		{
			t=a[j][i];a[j][i]=a[j+1][i];a[j+1][i]=t;
		}
		} 
		} 
		 } 
		 } 
		for(j=0;j<3;j++)

		{
			cout<<b[j]<<"   ";
			outfile<<b[i]<<" ";
			cout<<c[j]<<"    ";
			outfile<<c[i]<<" ";
			for(i=0;i<3;i++)      
		{
		cout<<a[j][i]<<"    ";
		outfile<<a[j][i]<<" ";
		} 
		cout<<endl;
		}
	
 
} 
 } 
}
