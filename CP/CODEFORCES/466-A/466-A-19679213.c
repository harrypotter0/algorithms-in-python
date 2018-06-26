#include<stdio.h>

int main()
{
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	int cost, rem;
	if( a*m > b )
	{
		cost = n/m * b;
		rem = n%m;
		if(rem*a > b)
			cost+=b;
		else
			cost = cost + rem*a;
	}
	else
		cost = a*n;
	printf("%d\n", cost);
	return 0;
}