#include "game.h"

void InitBoard(char (*Board)[COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < col;j++)
			Board[i][j] = ' ';
	}
}

void DisplayBoard(char Board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < col;j++)
		{
			printf(" %c ",Board[i][j]);
			if(j < col-1)
				printf("|");
		}
		printf("\n");
		if(i < row-1)
		{	
			for(j = 0;j < col;j++)
			{
				printf("---");
				if(j < col-1)
					printf("|");
			}
		printf("\n");
		}
	}
}

void Player(char Board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("Input coordenate:\n");
		scanf("%d%d",&x,&y);
		if(1 <= x && x <= row && 1 <= y && y <= col)
		{
			if(Board[x-1][y-1] == ' ')
			{
				Board[x-1][y-1] = '*';
				break;
			}
			else
				printf("Already chessed!\n");
		}
		else
			printf("Wrong coordinate input again!\n");
	}
}

void Computer(char Board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("Computer chess:\n");
	while(1)
	{
		x = rand() % row;
		y = rand() % col;
		if(Board[x][y] == ' ')
		{
			Board[x][y] = '@';
			break;
		}
	}
}
