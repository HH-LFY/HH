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
 for (i=0; i<21; i++)
 {
  for (j=0; j<21; j++)
  {
   array[i][j] = 0;
  }
 }
 player1 = 1;
 player2 = 0;
 focus_x = 10;
 focus_y = 10;
}
