#include <stdio.h>
#include <string.h>

void reverse(char* ar)
{
	size_t len = strlen(ar);
	char* left = ar;
	char* right = ar + len - 1;
	char tmp;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
    }
}

int main()
{
	char arr[100] = { 0 };
	gets_s(arr,100);
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}
