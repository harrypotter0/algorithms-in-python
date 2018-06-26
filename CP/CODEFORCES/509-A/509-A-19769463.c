#include <stdio.h>

int f(int, int);
int f(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;
	return f(a - 1, b) + f(a, b - 1);
}

int main(void)
{
	int i;
	scanf("%d", &i);
	printf("%d\n", f(i, i));

	return 0;
}