#include <stdio.h>

int main()
{
	int a = 0;
	char c = 'r';
	char* p = &c;
	int arr[10] = {0};
	printf("%ld\n",sizeof(a));
	printf("%ld\n",sizeof(int));
	printf("%ld\n",sizeof(c));
	printf("%ld\n",sizeof(char));
	printf("%ld\n",sizeof(p));
	printf("%ld\n",sizeof(int*));
	printf("%ld\n",sizeof(arr));
	printf("%ld\n",sizeof(int[10]));
	printf("%ld\n",sizeof(int[5]));
	printf("%ld\n",sizeof(int[1]));
	return 0;
}
