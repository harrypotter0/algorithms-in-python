#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
u N[111111],r,s;
int main()
{
	u n,i=-1,j,k;
	for(scanf("%u",&n);++i<n;scanf("%u",N+i));
	qsort(N,n,sizeof(u),F);
	for(i=-1;++i<n;)if(s<=N[i])++r,s+=N[i];
	printf("%u\n",r);
	return 0;
}