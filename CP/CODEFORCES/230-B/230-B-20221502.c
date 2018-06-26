#include<stdio.h>
#include<math.h>
int main()
{
	long long i, n, a, b;
	scanf("%I64d", &n);
	while( n-- )
	{
		scanf("%I64d", &a);
		b = sqrt(a*1.0);
		for( i = 2; i*i <= b; i++)
		{
			if( b%i ==0)
				break;
		}
		if(i*i>b && b*b==a && a>1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}