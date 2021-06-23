#include <stdio.h>

#define PRINT(X) printf("The value of "#X" is %d\n",X)
int main()
{
int a = 10;
int b = 20;
PRINT(5+5);
PRINT(b);
return 0;
}
