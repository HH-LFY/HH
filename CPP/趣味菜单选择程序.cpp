#include <iostream>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <conio.h>
using namespace std;

#define qj printf("系统正在为您求解");for(int i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;
#define jz printf("程序正在启动");for(int i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;system("cls");
#define cz printf("系统正在为您计算出圈顺序");for( i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;system("cls");

int menu_select()
 {
      char s[2];
      int cn;
      system("color 01");
      cout<<endl<<endl<<endl<<endl;
      cout<<"  =========================================================================="<<endl;
      cout<<"  ==                     1.解一元二次方程                                 =="<<endl;
      cout<<"  ==                     2.出圈游戏                                       =="<<endl;
      cout<<"  ==                     3.退出程序                                       =="<<endl;
      cout<<"  =========================================================================="<<endl;
   for(; ;)
   {
       cout<<"请输入1-3："<<endl;
        gets(s);
       cn=atoi(s); // 是为了使输入的字符串转变为数字
      if(cn<1||cn>3)
         printf("\n\t输入错误,重选1-3:");
      else
           break;
   }
    return cn;
 }

void FindIt()
{
    system("cls");
    double a,b,c;
    system("color 02");
    cout<<"本程序是一个求 a*x^2 + b*x + c = 0 的解的程序。"<<endl;
    cout<<"请输入系数a：";
    cin>>a;
    cout<<"请输入系数b：";
    cin>>b;
    cout<<"请输入系数c：";
    cin>>c;
    system("cls");
    printf("您输入的方程为 %.0lf*x^2 + %.0lf*x + %.0lf = c\n",a,b,c);
    qj;
    double d=b*b-4*a*c;
    if(d < 0)
    {
        cout<<"该方程无解！请确认您输入的系数是否正确。"<<endl;
    }
    else if(0==d)
    {
        double x=-b/(2*a);
        cout<<"该方程只有一个解，其解为："<<endl<<" X = "<<x<<endl;
    }
    else if(d > 0)
    {
        d=sqrt(d);
        double x1=( -b + d )/(2 * a);
        double x2=( -b - d )/(2 * a);
        cout<<"该方程只有两个解，其解为："<<endl;
        cout<<"X1 = "<<x1<<endl;
        cout<<"X2 = "<<x2<<endl;
    }
    system("pause");
    system("cls");
    getchar();
}

void game()
{
    system("cls");
    system("color 03");
    cout<<"请输入参与出圈游戏的人数 (输入-1查看帮助): ";
    int n,i,m,a[100];
    bool vis[100];
    cin>>n;
    if(n==-1)
    {
        cout<<"　　 出圈游戏的规则是，假设有人数为n个人的一个小组，他"<<endl;
        cout<<"们按顺时针方向周围坐一圈。一开始任选一个正整数作为报数"<<endl;
        cout<<"上限值m，从第一个人开始按顺时针方向自1开始顺序报数，报"<<endl;
        cout<<"到m时停止报数。报数m的人出列，然后从他原来所在的,顺时。"<<endl;
        cout<<"针方向的下一个人开始重新从1报数，报到m时停止报数并出列"<<endl;
        cout<<"如此下去，直至所有人全部出列为止。要求按他们出列的顺序"<<endl;
        cout<<"输出他们的名字。"<<endl;
        system("pause");
        system("cls");
        cout<<"请输入参与出圈游戏的人数：";
        cin>>n;
    }
    cout<<"请输入报数的上限值m： ";
    cin>>m;
    char str[100][20];
    for(i = 1;i <= n; i++)
    {
        vis[i] = 1;
        a[i] = i;
        printf("第%d个人的名字:",i);
        cin>>str[i];
        getchar( );
//       cout<<str[i]<<endl;
    }
    cz;
    int judge = 0;
    int km=0;
    i = 1;
    while(1)
    {
        if(judge==n) break;
        if(vis[i]==1&&km<m)
        {
            km++;
        }
        if(vis[i]==1&&km==m)
        {
            judge++;
            printf("第%d个出圈的人为：%s\n",judge,str[i]);
            km=0;
            vis[i]=0;
        }
        if(i==n)i=1;
        else i++;
    }
    system("pause");
    system("cls");
}

int main( )
{
    jz;
  while(1)
  {
    switch(menu_select())//调用菜单选择函数
    {
    case 1:
       FindIt();//求解一元二次方程
        break;
    case 2:
       game();//出圈游戏
       break;
    case 3:
      cout<<"\t再见!\n";
      return 0;
	}
  }
  return 0;
}
