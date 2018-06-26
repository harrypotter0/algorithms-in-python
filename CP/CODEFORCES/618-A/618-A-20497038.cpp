#include <cstdio>

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 20; i >= 0; i--) if (n >> i & 1) printf("%d ", i + 1);
}