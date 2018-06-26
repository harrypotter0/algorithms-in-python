#include "stdio.h"

int a, b, n, k, i;

int main()
{
	scanf( "%d%d", &n, &k );
	while(1)
	{
		i++;
		if( i > n ) break;
		scanf( "%d", &a );
		if( a <= 0 ) break;
		if( i > k && a < b ) break;
		if( i == k ) b = a;
	}
	printf( "%d\n", i - 1 );
	return 0;
}