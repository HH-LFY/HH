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
 void startGame();
 startGame();
 return 0;
}
void init()
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

void startGame()
{
 void init();
 void printChessBoard();
 void control();
 int checkGameOver();

 init();
 while (winner == 0)
 {
  printChessBoard();
  control();
  checkGameOver();
 }
 printChessBoard();
 printf("\nPlayer%d is the winner!\n\n", winner);
 system("pause");
}

void printChessBoard()
{
 int i, j;

 system("cls");

 printf("游戏提示：\nwsad为上下左右，每个操作需按Enter确认(比如上要按w再按Enter)，走棋为k\n");

 for (i=0; i<21; i++)
 {
  for (j=0; j<21; j++)
  {
   if (i==focus_x && j==focus_y)
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
}


void control()
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



int checkGameOver()
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
