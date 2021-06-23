
#include <stdio.h>

int bisection_search(int* arr,int size,int key)
{
	int left = 0;
	int right = size-1;
	int midow = 0;
	while(left <= right-1)
	{
		midow = (left+right)/2;
		if(arr[midow] < key)
			left = midow;
		else if(arr[midow] > key) 
			right = midow;
		else
			return midow;
	}
	return -1;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int key = 0;
	printf("Please input: ");
	scanf("%d",&key);
	int sz = sizeof(arr)/sizeof(arr[0]);
	printf("size = %d\n",sz);
	int ret = bisection_search(arr,sz,key);
	if(ret == -1)
	{
		printf("Can't find the number!\n");
	}
	else
		printf("The element is %d\n",ret);
	return 0;
}
