#include <stdio.h>

int main()
{
	int i = 0;
	int mid = 0;
	for(i=0;i<=100;i++)
	{
		mid = i % 2;
		if(1 == mid)
			printf("%d ",i);
	}
	
	return 0;
}
