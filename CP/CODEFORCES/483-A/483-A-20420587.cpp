#include<stdio.h>
int main()
{
	long long int l,r;
	scanf("%I64d %I64d",&l,&r);
	int t=l%2;
	if(l+2+t<=r)
	{
		printf("%I64d %I64d %I64d",l+t,l+1+t,l+2+t);
	}
	else printf("-1");
	return 0;
}