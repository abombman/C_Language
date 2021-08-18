#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include<string.h>

int main()
{
	char arr[] = "192.168.1.1.999";
	char* p = ".";
	char buf[255] = { '0' };

	strcpy(buf, arr);
	char* ret = strtok(buf, p);

	while (ret != NULL)
	{   
		printf("%s\n", ret);
		ret = strtok(NULL, p);
		
	}
	return 0;
}