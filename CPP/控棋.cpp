#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[21][21];
int focus_x;
int focus_y;
int player1;
int player2;
int winner;
int main()
{
 void up();
 void down();
 void left();
 void right();
 void go();

 char input;
 input = getchar();

 if (input == 'w')
 {
  up();
 }
 if (input == 's')
 {
  down();
 }
 if (input == 'a')
 {
  left();
 }
 if (input == 'd')
 {
  right();
 }
 if (input == 'k')
 {
  go();
 }
 return 0;
}

void up()
{
 if (focus_x <= 0)
 {
  focus_x = 0;
 }
 else
 {
  focus_x--;
 }
}

void down()
{
 if (focus_x >= 20)
 {
  focus_x = 20;
 }
 else
 {
  focus_x++;
 }
}

void left()
{
 if (focus_y <= 0)
 {
  focus_y = 0;
 }
 else
 {
  focus_y--;
 }
}

void right()
{
 if (focus_y >= 20)
 {
  focus_y = 20;
 }
 else
 {
  focus_y++;
 }
}

void go()
{
 int chessman = array[focus_x][focus_y];
 if (chessman == 0)
 {
  if (player1 == 1)
  {
   array[focus_x][focus_y] = 1;
   player1 = 0;
   player2 = 1;
  }
  else
  {
   array[focus_x][focus_y] = 2;
   player1 = 1;
   player2 = 0;
  }
 }
}
