#include <stdio.h>

int main()
{
	int n = 0;
	int counter = 0;
	scanf("%d",&n);
	while(n)
	{
		n = n & (n-1);
		counter++;
	}
	printf("%d\n",counter);
	return 0;
}
