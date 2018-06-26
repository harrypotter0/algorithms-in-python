#include<stdio.h>
typedef unsigned u;
u M[444],F[444];
int main()
{
	u i,j,k=0,n;char c;
	for(scanf("%u",&n);n--;)
	{
		while((c=getchar())<'A');
		scanf("%u%u",&i,&j);
		if(c=='M')for(;i<=j;++i)++M[i];
		if(c=='F')for(;i<=j;++i)++F[i];
	}
	for(i=-1;++i<444;)
	{
		if(k<(j=M[i]>F[i]?F[i]:M[i]))k=j;
	}
	printf("%u\n",k<<1);
	return 0;
}