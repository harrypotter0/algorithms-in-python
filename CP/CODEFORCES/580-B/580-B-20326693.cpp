#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
u N[111111],M[111111],S[111111];
int F(const void*x,const void*y)
{
	if(M[*(u*)x]>M[*(u*)y])return 1;
	if(M[*(u*)x]<M[*(u*)y])return-1;
	return 0;
}
int main()
{
	u n,d,i=-1,j;llu r=0,f=0;
	for(scanf("%u%u",&n,&d);++i<n;N[i]=i)scanf("%u%u",M+i,S+i);
	qsort(N,n,sizeof(u),F);
	for(i=-1,j=0;++i<n;)
	{
		for(f+=S[N[i]];M[N[i]]-M[N[j]]>=d&&i!=j;f-=S[N[j++]]);
		if(r<f)r=f;
	}
	printf("%I64u\n",r);
	return 0;
}