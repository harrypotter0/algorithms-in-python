#include<stdio.h>
main()
{
	int n,m,i,d;
	long long s=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		d=(m+i)/5-i/5;
		s+=d;
	}
	printf("%I64d",s);
}