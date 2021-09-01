#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  ROW  3
#define  COL  3

void InitBoard(char(*Board)[COL],int,int);
void DisplayBoard(char Board[ROW][COL],int,int);
void Player(char Board[ROW][COL],int,int);
void Computer(char Board[ROW][COL],int,int);
