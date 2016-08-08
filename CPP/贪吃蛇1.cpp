#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
//游戏窗口
#define FrameX 4   //游戏窗口左上角的X轴坐标
#define FrameY 4   //游戏窗口左上角的Y轴坐标
#define Frame_height  20 //游戏窗口的高度
#define Frame_width   20 //游戏窗口的宽度
//定义全局变量
int i,j;
int a[2];     //用于记住蛇尾坐标，其中a[0]、a[1]分别表示横、竖坐标
//声明蛇的结构体
struct Snake
{
 int x[100];    //蛇的横坐标，其中x[0]表示蛇尾的横坐标，x[N-1]表示蛇头的横坐标
 int y[100];    //蛇的竖坐标，其中y[0]表示蛇尾的竖坐标，y[N-1]表示蛇头的竖坐标
 int count;    //蛇吃食物的个数
 int length;    //蛇的长度
 int speed;    //蛇的速度
};
//声明食物的结构体
struct Food
{
 int x;     //食物的横坐标
 int y;     //食物的竖坐标
};
int main()
{
 void start_game();
 void over_game();
 system("color 0D");  //设置文本为粉红色
 start_game();   //开始游戏
 over_game();   //结束游戏
}
/******光标移到指定位置**************************************************************/
void gotoxy(HANDLE hOut, int x, int y)
{
 COORD pos;
 pos.X = x;  //横坐标
 pos.Y = y;  //纵坐标
 SetConsoleCursorPosition(hOut, pos);
}
/******设置文本为绿色*****************************************************************/
void Set_TextColor_Green (void)
{
 HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

 SetConsoleTextAttribute(Handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
}
/******制作游戏窗口******************************************************************/
void make_frame()
{
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //定义显示器句柄变量
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+13);  //打印选择菜单
 printf("Esc 退出游戏");
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+15);
 printf("长按方向键：加速");
 gotoxy(hOut,FrameX,FrameY);       //打印框角
 printf("╔");
 gotoxy(hOut,FrameX+2*Frame_width-2,FrameY);
 printf("╗");
 gotoxy(hOut,FrameX,FrameY+Frame_height);
 printf("╚");
 gotoxy(hOut,FrameX+2*Frame_width-2,FrameY+Frame_height);
 printf("╝");
 for(i=2;i<2*Frame_width-2;i+=2)
 {
  gotoxy(hOut,FrameX+i,FrameY);
  printf("═");         //打印上横框
 }
 for(i=2;i<2*Frame_width-2;i+=2)
 {
  gotoxy(hOut,FrameX+i,FrameY+Frame_height);
  printf("═");         //打印下横框
 }
 for(i=1;i<Frame_height;i++)
 {
  gotoxy(hOut,FrameX,FrameY+i);
  printf("║");         //打印左竖框
 }
 for(i=1;i<Frame_height;i++)
 {
  gotoxy(hOut,FrameX+2*Frame_width-2,FrameY+i);
  printf("║");         //打印右竖框
 }
 gotoxy(hOut,FrameX+Frame_width-5,FrameY-2);   //打印游戏名称
 Set_TextColor_Green ();        //设置蛇为绿色
 printf("贪吃蛇游戏");
}
/******结束菜单*******************************************************************/
void over_game()
{
 system("cls");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t游戏结束\n\n\n");
 Sleep(2000);
 getch();
}
/******菜单信息***************************************************************/
print_information(HANDLE hOut,struct Snake *snake,struct Food *food)
{
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+1);
 printf("level : %d",snake->count/5+1);    //打印游戏等级
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+3);
 printf("score : %d",10*snake->count);    //打印游戏得分
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+5);
 printf("eat food : %d",snake->count);    //打印产生食物个数
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+7);
 printf("speed : %dms",snake->speed);    //打印游戏速度
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+9);
 printf("foodX : %d",food->x);      //打印食物的横坐标
 gotoxy(hOut,FrameX+2*Frame_width+3,FrameY+11);
 printf("foodY : %d",food->y);      //打印食物的竖坐标
}
/******初始化蛇**********************************************************************/
void init_snake(struct Snake *snake)
{
 snake->x[0]=FrameX+2;     //初始化蛇的横坐标
 snake->y[0]=FrameY+Frame_height/2;  //初始化蛇的竖坐标
 snake->speed=300;      //初始化蛇的速度为300ms
 snake->length=3;      //初始化蛇的长度为3节
 snake->count=0;       //初始化蛇吃的个数为0
 for(i=1;i<snake->length;i++)
 {/* 依次得到蛇身、蛇头的坐标 */
  snake->x[i]=snake->x[i-1]+2;
  snake->y[i]=snake->y[i-1];
 }
}
/******移动蛇*************************************************************************/
void move_snake(HANDLE hOut,struct Snake *snake)
{
 gotoxy(hOut,snake->x[0],snake->y[0]);
 printf("  ");       /* 清除蛇尾*/
 for(i=1;i<snake->length;i++)
 {/* 后一节的坐标依次取代前一节的坐标 */
  snake->x[i-1]=snake->x[i];
  snake->y[i-1]=snake->y[i];
 }
}
/******打印蛇*************************************************************************/
void print_snake(HANDLE hOut,struct Snake *snake)
{
 for(i=0;i<snake->length;i++)
 {
  gotoxy(hOut,snake->x[i],snake->y[i]);
  if(i==0)
  {
   printf("○");       //打印蛇尾
  }
  else if(i==snake->length-1)
  {
   printf("¤");       //打印蛇头
  }
  else
  {
   printf("⊙");       //打印蛇身
  }
 }
}
/******随机产生食物*******************************************************************/
void get_food(HANDLE hOut,struct Snake *snake,struct Food *food)
{
 srand((unsigned)time(NULL));       //初始化随机数
 while(1)
 {/* 产生食物的条件：1.在游戏窗口内 2.不在蛇的身上 */
  food->x = rand() % (Frame_width-1);
  food->y = rand() % Frame_height;
  if( food->x==0 || food->y==0 )
  {
   continue;
  }
  food->x = 2*food->x + FrameX;      //得到食物的横坐标
  food->y+=FrameY;         //得到食物的竖坐标
  for(i=0;i<snake->length;i++)
  {/* 判断食物是否在蛇的身上，如果在蛇身上，则重新产生；否则，打印蛇身 */
   if( food->x==snake->x[i] && food->y==snake->y[i] )
   {
    break;
   }
  }
  if(i==snake->length)
  {
   gotoxy(hOut,food->x,food->y);
   printf("⊙");
   break;
  }
 }
}
/******吃食物***************************************************************************/
void eat_food(HANDLE hOut,struct Snake *snake,struct Food *food)
{
 if( snake->x[snake->length-1]==food->x && snake->y[snake->length-1]==food->y )
 {/* 如果蛇头位置与食物位置相同，吃食物 */
  snake->length++;      //吃一个食物，蛇身增长一节
  for(i=snake->length-1;i>=1;i--)
  {/* 蛇后节坐标依次赋值给蛇前一节的坐标，依次得到蛇身及蛇头的坐标 */
   snake->x[i]=snake->x[i-1];
   snake->y[i]=snake->y[i-1];
  }
  snake->x[0]=a[0];      //得到蛇尾移动前的横坐标
  snake->y[0]=a[1];      //得到蛇尾移动前的竖坐标
  get_food(hOut,snake,food);    //重新产生食物
  snake->count++;       //食物的个数增1
  if( snake->count%5==0 )
  {/* 当蛇吃Up_level个食物时，速度加快Up_speed毫秒并且升一级 */
   snake->speed-=50;
  }
 }
}
/******穿墙**********************************************************************************/
void through_wall(HANDLE hOut,struct Snake *snake,char ch)
{
 if( ch==72 && snake->y[snake->length-1]==FrameY)
 {
  snake->y[snake->length-1] = FrameY+Frame_height-1; //如果蛇在上框且向上移动，穿墙
 }
 if( ch==80 && snake->y[snake->length-1]==FrameY+Frame_height )
 {
  snake->y[snake->length-1] = FrameY+1;    //如果蛇在下框且向下移动，穿墙
 }
 if( ch==75 && snake->x[snake->length-1]==FrameX )
 {
  snake->x[snake->length-1] = FrameX+2*Frame_width-4; //如果蛇在左框且向左移动，穿墙
 }
 if( ch==77 && snake->x[snake->length-1]==FrameX+2*Frame_width-2 )
 {
  snake->x[snake->length-1] = FrameX+2;    //如果蛇在右框且向右移动，穿墙
 }
}
/******判断蛇是否死**************************************************************************/
int if_die(struct Snake *snake)
{/* 当蛇头碰到自身时，蛇死 ，返回值为0 */
 for(i=0;i<snake->length-1;i++)
 {
  if( snake->x[snake->length-1]==snake->x[i] && snake->y[snake->length-1]==snake->y[i] )
  {
   return 0;
  }
 }
 return 1;
}
/******开始游戏*******************************************************************************/
void start_game()
{
 unsigned char ch=77;        //定义用于接收键盘输入的字符变量
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //定义显示器句柄变量
 struct Snake s,*snake=&s;      //定义蛇的结构体指针并指向蛇的结构体
 struct Food f,*food=&f;       //定义食物的结构体指针并指向食物的结构体

 make_frame();         //制作游戏窗口
 init_snake(snake);        //初始化蛇
 get_food(hOut,snake,food);      //随机产生食物
 while(1)
 {
  print_information(hOut,snake,food);   //打印菜单信息
  a[0]=snake->x[0];       //记住蛇尾的横坐标
  a[1]=snake->y[0];       //记住蛇尾的竖坐标
  j=0;
  if(kbhit())
  {/* 判断是否按下键盘，如果按下，ch接收键盘输入 */
   ch=getch();
   if(kbhit())
   {/* 如果长按键盘，则加速 */
    Sleep(20);
    j=1;
   }
  }
  switch(ch)
  {
   case 72:
    {/* 向上移动 */
     move_snake(hOut,snake);   //移动蛇
     snake->y[snake->length-1]-=1; //蛇头的竖坐标向上移，即减1
     break;
    }
   case 80:
    {/* 向下移动 */
     move_snake(hOut,snake);   //移动蛇
     snake->y[snake->length-1]+=1; //蛇头的竖坐标向下移，即加1
     break;
    }
   case 75:
    {/* 向左移动 */
     move_snake(hOut,snake);   //移动蛇
     snake->x[snake->length-1]-=2; //蛇头的横坐标向左移，即减2
     break;
    }
   case 77:
    {/* 向右移动 */
     move_snake(hOut,snake);   //移动蛇
     snake->x[snake->length-1]+=2; //蛇头的横坐标向右移，即加2
     break;
    }
  }
  through_wall(hOut,snake,ch);    //穿墙
  eat_food(hOut,snake,food);     //吃食物
  print_snake(hOut,snake);     //打印蛇
  if( if_die(snake)==0 || ch==27 || snake->speed==50 )
  {/* 游戏结束条件：1.蛇碰到自身 2.按Esc键 3.速度为50ms */
   gotoxy(hOut,FrameX+Frame_width-2,FrameY+Frame_height/2-1);
   printf("Game Over");
   Sleep(2000);
   break;
  }
  if(j==0)
  {
   Sleep(snake->speed);      //延迟时间
  }
  else
  {
   Sleep(10);
  }
 }
}
