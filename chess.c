#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("******** 1.play	  0.exit *********\n");
	printf("**********************************\n");
}

void game()
{
	char Board[ROW][COL] = {'0'};
	InitBoard(Board,ROW,COL);
	DisplayBoard(Board,ROW,COL);
	while(1)
	{
		//playermove
		Player(Board,ROW,COL);
		DisplayBoard(Board,ROW,COL);
		//Computermove
		Computer(Board,ROW,COL);
		DisplayBoard(Board,ROW,COL);
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose(1/0):");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("Chess game\n");
				game();
				break;
			case 0:
				printf("Exit game\n");
				break;
			default:
				printf("Please rechoose\n");
				break;
		}
	}while(input);
}

int main()	
{
	
	test();
	return 0;
}
