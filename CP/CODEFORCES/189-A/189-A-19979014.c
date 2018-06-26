#include<stdio.h>
int main()
{
	int n,a,b,c,i,j,k,ans=1;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	for(i=0;i*a<=n;i++)
	{
		for(j=0;a*i+j*b<=n;j++)
		{
			k=(n-a*i-b*j)/c;
			if(a*i+b*j+c*k==n&&i+j+k>ans)
			ans=i+j+k;
		}
	}
	printf("%d",ans);
	return 0;
}