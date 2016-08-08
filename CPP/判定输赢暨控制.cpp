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
 int judge(int x, int y);

 for (i=0; i<21; i++)
 {
  for (j=0; j<21; j++)
  {
   if (array[i][j] != 0)
   {
    if(judge(i, j) == 1)
    {
     return 1;
    }
   }
  }
 }
 return 0;

}

int judge(int x, int y)
{
 int horizontal(int x, int y);
 int vertical(int x, int y);
 int minus_diagonal(int x, int y);
 int plus_diagonal(int x, int y);

 if (horizontal(x, y) == 1)
 {
  return 1;
 }
 if (vertical(x, y) == 1)
 {
  return 1;
 }
 if (minus_diagonal(x, y) == 1)
 {
  return 1;
 }
 if (plus_diagonal(x, y) == 1)
 {
  return 1;
 }
 return 0;
}

int horizontal(int x, int y)
{
 int i, chess;
 chess = 1;

 if (y <= 16)
 {
  for (i=1; i<5; i++)
  {
   if (array[x][y] == array[x][y+i])
   {
    chess++;
   }
  }
 }

 if (chess >= 5)
 {
  winner = array[x][y];
  return 1;
 }
 return 0;
}

int vertical(int x, int y)
{
 int i, chess;
 chess = 1;

 if (x <= 16)
 {
  for (i=1; i<5; i++)
  {
   if (array[x][y] == array[x+i][y])
   {
    chess++;
   }
  }
 }

 if (chess >= 5)
 {
  winner = array[x][y];
  return 1;
 }
 return 0;
}

int minus_diagonal(int x, int y)
{
 int i, chess;
 chess = 1;

 if (x<=16 && y<=16)
 {
  for (i=1; i<5; i++)
  {
   if (array[x][y] == array[x+i][y+i])
   {
    chess++;
   }
  }
 }

 if (chess >= 5)
 {
  winner = array[x][y];
  return 1;
 }
 return 0;
}

int plus_diagonal(int x, int y)
{
 int i, chess;
 chess = 1;

 if (x>=4 && y<=16)
 {
  for (i=1; i<5; i++)
  {
   if (array[x][y] == array[x-i][y+i])
   {
    chess++;
   }
  }
 }

 if (chess >= 5)
 {
  winner = array[x][y];
  return 1;
 }
 return 0;
}
