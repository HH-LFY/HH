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
 int i, j;
 printf("游戏提示：\nwsad为上下左右，每个操作需按Enter确认(比如上要按w再按Enter)，走棋为k\n");

 for (i=0; i<21; i++)
 {
  for (j=0; j<21; j++)
  {
   if (i==2&&j==2)
   {
    printf("\b[%d] ", array[i][j]);
   }
   else
   {
    printf("%-3d", array[i][j]);
   }
  }
  printf("\n");
 }
 if (winner == 0)
 {
  if (player1 == 1)
  {
   printf("Player1: ");
  }
  else
  {
   printf("Player2: ");
  }
 }
 return 0;
}
