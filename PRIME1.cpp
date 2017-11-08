#include <stdio.h>
#include <math.h>
 
int main()
{
	int t;
	int m, n;
	int i, j, k, mult;
	double sq;
	char v[32001];
 
	for ( i = 2; i <= 32000; i++ )
		v[i] = 1;
 
	for ( i = 2; i <= 32000; i++ ) {
		if ( v[i] == 1 ) {
			j = 3;
			mult = i * 2;
			while ( mult <= 32000 ) {
				v[mult] = 0;
				mult = i * j;
				j++;
			}
		}
	}
	  
	scanf( "%d", &t );
 
	while ( t-- ) {
		scanf( "%d", &m );
		scanf( "%d", &n );
	
		char p[n-m+1];
 
		sq = sqrt( n );
       		k = sq;
		k++;
 
		while ( v[k] != 1 ) {  // searching for prime
			k++;
		}
 
		for ( i = 1; i <= n-m+1; i++ ) {
			p[i] = 1;
		}
 
		for ( i = 2; i <= k; i++ ) {
			if ( v[i] == 1 ) {
				j = 2;
				mult = i * 2;
				if ( i < m ) {
					if ( m % i == 0 ) {
						mult = m;
						j = m/i;
					} else {
						mult = i * (m/i + 1 );
						j = m/i + 1;
					}
				}
				
				while ( mult <= n ) {
					p[mult-m+1] = 0;
					j++;
					mult = j * i;
				}
			}
		}
 
		if ( m == 1 )
			i = m + 1;
		else 
			i = m;
 
		while ( i <= n ){  
			if ( p[i-m+1] == 1 )
				printf( "%d\n", i );
			i++;
		}
 
		printf( "\n");
	}
 
	return 0;
}
