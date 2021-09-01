#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void menu()
{
	printf("********************************************\n");
	printf("**********1. add          2. del************\n");
	printf("**********3. search       4. modify*********\n");
	printf("**********5. show         6. sort***********\n");
	printf("**********0. exit           ****************\n");
	printf("********************************************\n");
}

int main()
{
	int input = 0;
	struct contact con;
	Initcontact(&con);

	do
	{
		int ret = 0;
		menu();
		printf("Please input： ");
		ret = scanf("%d" , &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			Destroycontact(&con);
			printf("Exit\n");
			break;
		default:
			printf("wrong input!\n");
		}
		
	} while (input);
	
	return 0;
}