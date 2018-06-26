#include<stdio.h>
long long int a[500001],s=0,j=0,c=0,t=0;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		s+=a[i];
	}
	if(s%3==0)
	{
		s=s/3;
		for(i=0;i<n-1;i++)
		{
			t+=a[i];
			if(t==2*s)j+=c;
			if(t==s)c++;
		}
		printf("%lld",j);
	}
	else
		printf("0");
	return 0;
}