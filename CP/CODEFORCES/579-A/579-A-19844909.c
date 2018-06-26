#include <stdio.h>
int d,t;
int main()
{
	scanf("%d",&d);
	while(d){ if ((d)%2) t++; d>>=1; };
	printf("%d", t);
}