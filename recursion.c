#include <stdio.h>

int stringlenth(char* str)
{
	if(*str != '\0')
		return 1+stringlenth(++str);
	else
		return 0;
}


int main()
{
	int len = 0;
	char str[]="lenth";
	len = stringlenth(str);
	printf("%d\n",len);
	return 0;
}
