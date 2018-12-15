#include <stdio.h>

int factorial(int n) \\用递归求解阶乘
{
	if (n == 0)
		return 1;
	else {
		int recurse = factorial(n-1);
		int result = n * recurse;
		return result;
	}
}

int main()
{
	int a;
	a=factorial(5);
	printf("%d",a);
	getchar();
	return 0;
}
