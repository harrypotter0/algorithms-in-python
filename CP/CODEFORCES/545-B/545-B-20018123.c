#include <stdio.h>

int main()
{
	int a, b;
	char ZA[100001], ZB[100001], ZC[100001];

	scanf("%s%s", ZA, ZB);
	a = 0;
	for (b = 0; ZA[b]; ++b)
		if (ZA[b] == ZB[b])
			ZC[b] = ZA[b];
		else {
			a += 1;
			if (a % 2)
				ZC[b] = ZB[b];
			else
				ZC[b] = ZA[b];
		}
	if (a % 2)
		printf("impossible\n");
	else {
		ZC[b] = 0;
		printf("%s\n", ZC);
	}

	return 0;
}