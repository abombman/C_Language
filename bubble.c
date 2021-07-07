#include <stdio.h>


void bubble_sort(int arr[],int sz)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for(i = 0;i < sz;i++)
		printf("%d ",arr[i]);
	printf("\ninside bubble %d \n",sz);
	for(i = 0;i < sz-1;i++)
	{
		for(j = 0;j < (sz-1-i);j++)
		{	
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = {5,6,7,8,1,2,3,5,8,0};
	int size = (int)sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for(i = 0;i < size;i++)
	{
		printf("%d ",arr[i]);
	}
		printf("\n%d\n",size);
	bubble_sort(arr,size);
	for(i = 0;i < size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
