#include<cstdio>
int main()
{
	long int n;
	scanf("%ld",&n);
	int i,j;
	for(i=0;i<=n;i+=1234567)
	{
		for(j=0;j<=n-i;j+=123456)
			if((n-i-j)%1234==0)
			{
				printf("YES\n");
				return 0;
			}
	}
	printf("NO\n");
	return 0;
}