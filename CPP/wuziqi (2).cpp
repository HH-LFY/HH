#include<student.h>
#include<graphics.h>
#define LEFT 0x4b00 /*光标左键值*/
#define RIGHT 0x4d00 /*光标右键值*/
#define DOWN 0x5000 /*光标下键值*/
#define UP 0x4800 /*光标上键值*/
#define ESC 0x011b /* ESC键值*/
#define ENTER 0x1c0d /* 回车键值*/
int a[8][8]={0},key,score1,score2;/*具体分数以及按键与存放棋子的变量*/
char playone[3],playtwo[3];/*两个人的得分转换成字符串输出*/
void playtoplay(void);/*人人对战函数*/
void DrawQp(void);/*画棋盘函数*/
void SetPlayColor(int x);/*设置棋子第一次的颜色*/
void MoveColor(int x,int y);/*恢复原来棋盘状态*/
int QpChange(int x,int y,int z);/*判断棋盘的变化*/
void DoScore(void);/*处理分数*/
void PrintScore(int n);/*输出成绩*/
void playWin(void);/*输出胜利者信息*/
/******主函数*********/
void main(void)
{
int gd=DETECT,gr;
initgraph(&gd,&gr,"c:\\tc"); /*初始化图形系统*/
DrawQp();/*画棋盘*/
playtoplay();/*人人对战*/
getch()();
closegraph();/*关闭图形系统*/
}
void DrawQp()/*画棋盘*/
{
int i,j;
score1=score2=0;/*棋手一开始得分都为0*/
setbkcolor(BLUE);
for(i=100;i<=420;i+=40)
{
line(100,i,420,i);/*画水平线*/
line(i,100,i,420); /*画垂直线*/
}
setcolor(0);/*取消圆周围的一圈东西*/
setfillstyle(SOLID_FILL,15);/*白色实体填充模式*/
fillellipse(500,200,15,15); /*在显示得分的位置画棋*/
setfillstyle(SOLID_FILL,8); /*黑色实体填充模式*/
fillellipse(500,300,15,15);
a[3][3]=a[4][4]=1;/*初始两个黑棋*/
a[3][4]=a[4][3]=2;/*初始两个白棋*/
setfillstyle(SOLID_FILL,WHITE);
fillellipse(120+3*40,120+3*40,15,15);
fillellipse(120+4*40,120+4*40,15,15);
setfillstyle(SOLID_FILL,8);
fillellipse(120+3*40,120+4*40,15,15);
fillellipse(120+4*40,120+3*40,15,15);
score1=score2=2; /*有棋后改变分数*/
DoScore();/*输出开始分数*/
}
void playtoplay()/*人人对战*/
{
int x,y,t=1,i,j,cc=0;
while(1)/*换棋手走棋*/
{
x=120,y=80;/*每次棋子一开始出来的坐标,x为行坐标,y为列坐标*/
while(1) /*具体一个棋手走棋的过程*/
{
PrintScore(1);/*输出棋手1的成绩*/
PrintScore(2);/*输出棋手2的成绩*/
SetPlayColor(t);/*t变量是用来判断棋手所执棋子的颜色*/
fillellipse(x,y,15,15);
key=bioskey(0);/*接收按键*/
if(key==ESC)/*跳出游戏*/
break;
else
if(key==ENTER)/*如果按键确定就可以跳出循环*/
{
if(y!=80&&a[(x-120)/40][(y-120)/40]!=1
&&a[(x-120)/40][(y-120)/40]!=2)/*如果落子位置没有棋子*/
{
if(t%2==1)/*如果是棋手1移动*/
a[(x-120)/40][(y-120)/40]=1;
else/*否则棋手2移动*/
a[(x-120)/40][(y-120)/40]=2;
if(!QpChange(x,y,t))/*落子后判断棋盘的变化*/
{
a[(x-120)/40][(y-120)/40]=0;/*恢复空格状态*/
cc++;/*开始统计尝试次数*/
if(cc>=64-score1-score2) /*如果尝试超过空格数则停步*/
{
MoveColor(x,y);
fillellipse(x,y,15,15);
break;
}
else
continue;/*如果按键无效*/
}
DoScore();/*分数的改变*/
break;/*棋盘变化了，则轮对方走棋*/
}
else/*已经有棋子就继续按键*/
continue;
}
else /*四个方向按键的判断*/
if(key==LEFT&&x>120)/*左方向键*/
{
MoveColor(x,y);
fillellipse(x,y,15,15);
SetPlayColor(t);
x-=40;
fillellipse(x,y,15,15);
}
else
if(key==RIGHT&&x<400&&y>80)/*右方向键*/
{
MoveColor(x,y);
fillellipse(x,y,15,15);
SetPlayColor(t);
x+=40;
fillellipse(x,y,15,15);
}
else
if(key==UP&&y>120)/*上方向键*/
{
MoveColor(x,y);
fillellipse(x,y,15,15);
SetPlayColor(t);
y-=40;
fillellipse(x,y,15,15);
}
else
if(key==DOWN&&y<400)/*下方向键*/
{
MoveColor(x,y);
fillellipse(x,y,15,15);
SetPlayColor(t);
y+=40;
fillellipse(x,y,15,15);
}
}
if(key==ESC)/*结束游戏*/
break;
if((score1+score2)==64||score1==0||score2==0)/*格子已经占满或一方棋子为0判断胜负*/
{
playWin();/*输出最后结果*/
break;
}
t=t%2+1; /*一方走后，改变棋子颜色即轮对方走*/
cc=0; /*计数值恢复为0*/
} /*endwhile*/
}
void SetPlayColor(int t)/*设置棋子颜色*/
{
if(t%2==1)
setfillstyle(SOLID_FILL,15);/*白色*/
else
setfillstyle(SOLID_FILL,8);/*灰色*/
}
void MoveColor(int x,int y)/*走了一步后恢复原来格子的状态*/
{
if(y<100)/*如果是从起点出发就恢复蓝色*/
setfillstyle(SOLID_FILL,BLUE);
else/*其他情况如果是1就恢复白色棋子,2恢复黑色棋子,或恢复蓝色棋盘*/
switch(a[(x-120)/40][(y-120)/40])
{
case 1:
setfillstyle(SOLID_FILL,15);break; /*白色*/
case 2:
setfillstyle(SOLID_FILL,8);break; /*黑色*/
default:
setfillstyle(SOLID_FILL,BLUE); /*蓝色*/
}
}
int QpChange(int x,int y,int t)/*判断棋盘的变化*/
{
int i,j,k,kk,ii,jj,yes;
yes=0;
i=(x-120)/40; /*计算数组元素的行下标*/
j=(y-120)/40; /*计算数组元素的列下标*/
SetPlayColor(t);/*设置棋子变化的颜色*/
/*开始往8个方向判断变化*/
if(j<6)/*往右边*/
{
for(k=j+1;k<8;k++)
if(a[i][k]==a[i][j]||a[i][k]==0)/*遇到自己的棋子或空格结束*/
break;
if(a[i][k]!=0&&k<8)
{
for(kk=j+1;kk<k&&k<8;kk++)/*判断右边*/
{
a[i][kk]=a[i][j]; /*改变棋子颜色*/
fillellipse(120+i*40,120+kk*40,15,15);
}
if(kk!=j+1) /*条件成立则有棋子改变过颜色*/
yes=1;
}
}
if(j>1)/*判断左边*/
{
for(k=j-1;k>=0;k--)
if(a[i][k]==a[i][j]||!a[i][k])
break;
if(a[i][k]!=0&&k>=0)
{
for(kk=j-1;kk>k&&k>=0;kk--)
{
a[i][kk]=a[i][j];
fillellipse(120+i*40,120+kk*40,15,15);
}
if(kk!=j-1)
yes=1;
}
}
if(i<6)/*判断下边*/
{
for(k=i+1;k<8;k++)
if(a[k][j]==a[i][j]||!a[k][j])
break;
if(a[k][j]!=0&&k<8)
{
for(kk=i+1;kk<k&&k<8;kk++)
{
a[kk][j]=a[i][j];
fillellipse(120+kk*40,120+j*40,15,15);
}
if(kk!=i+1)
yes=1;
}
}
if(i>1)/*判断上边*/
{
for(k=i-1;k>=0;k--)
if(a[k][j]==a[i][j]||!a[k][j])
break;
if(a[k][j]!=0&&k>=0)
{
for(kk=i-1;kk>k&&k>=0;kk--)
{
a[kk][j]=a[i][j];
fillellipse(120+kk*40,120+j*40,15,15);
}
if(kk!=i-1)
yes=1;
}
}
if(i>1&&j<6)/*右上*/
{
for(k=i-1,kk=j+1;k>=0&&kk<8;k--,kk++)
if(a[k][kk]==a[i][j]||!a[k][kk])
break;
if(a[k][kk]&&k>=0&&kk<8)
{
for(ii=i-1,jj=j+1;ii>k&&k>=0;ii--,jj++)
{
a[ii][jj]=a[i][j];
fillellipse(120+ii*40,120+jj*40,15,15);
}
if(ii!=i-1)
yes=1;
}
}
if(i<6&&j>1)/*左下*/
{
for(k=i+1,kk=j-1;k<8&&kk>=0;k++,kk--)
if(a[k][kk]==a[i][j]||!a[k][kk])
break;
if(a[k][kk]!=0&&k<8&&kk>=0)
{
for(ii=i+1,jj=j-1;ii<k&&k<8;ii++,jj--)
{
a[ii][jj]=a[i][j];
fillellipse(120+ii*40,120+jj*40,15,15);
}
if(ii!=i+1)
yes=1;
}
}
if(i>1&&j>1)/*左上*/
{
for(k=i-1,kk=j-1;k>=0&&kk>=0;k--,kk--)
if(a[k][kk]==a[i][j]||!a[k][kk])
break;
if(a[k][kk]!=0&&k>=0&&kk>=0)
{
for(ii=i-1,jj=j-1;ii>k&&k>=0;ii--,jj--)
{
a[ii][jj]=a[i][j];
fillellipse(120+ii*40,120+jj*40,15,15);
}
if(ii!=i-1)
yes=1;
}
}
if(i<6&&j<6)/* 右下*/
{
for(k=i+1,kk=j+1;kk<8&&kk<8;k++,kk++)
if(a[k][kk]==a[i][j]||!a[k][kk])
break;
if(a[k][kk]!=0&&kk<8&&k<8)
{
for(ii=i+1,jj=j+1;ii<k&&k<8;ii++,jj++)
{
a[ii][jj]=a[i][j];
fillellipse(120+ii*40,120+jj*40,15,15);
}
if(ii!=i+1)
yes=1;
}
}
return yes;/*返回是否改变过棋子颜色的标记*/
}
void DoScore()/*处理分数*/
{
int i,j;
score1=score2=0;/*重新开始计分数*/
for(i=0;i<8;i++)
for(j=0;j<8;j++)
if(a[i][j]==1)/*分别统计两个人的分数*/
score1++;
else
if(a[i][j]==2)
score2++;
}
void PrintScore(int playnum)/*输出成绩*/
{
if(playnum==1)/*清除以前的成绩*/
{
setfillstyle(SOLID_FILL,BLUE);
bar(550,100,640,400);
}
setcolor(RED);
settextstyle(0,0,4);/*设置文本输出样式*/
if(playnum==1)/*判断输出哪个棋手的分,在不同的位置输出*/
{
sprintf(playone,"%d",score1);
outtextxy(550,200,playone);
}
else
{
sprintf(playtwo,"%d",score2);
outtextxy(550,300,playtwo);
}
setcolor(0);
}
void playWin()/*输出最后的胜利者结果*/
{
settextstyle(0,0,4);
setcolor(12);
if(score2>score1)/*开始判断最后的结果*/
outtextxy(100,50,"black win!");
else
if(score2<score1)
outtextxy(100,50,"white win!");
else
outtextxy(60,50,"you all win!");
}
