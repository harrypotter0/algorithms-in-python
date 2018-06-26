#include<stdio.h>
typedef unsigned u;
int main()
{
	u m,c,t,M=0,C=0;
	for(scanf("%u",&t);t--;)
	{
		scanf("%u%u",&m,&c);
		M+=m>c;
		C+=c>m;
	}
	printf(M>=C?M==C?"Friendship is magic!^^":"Mishka":"Chris");
	return 0;
}