#include<stdio.h>
int main()
{
	char str[100][100];
	int n,count=0,ans=0;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	scanf("%s",str[i]);
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(str[i][j]=='C')
			count++;
		}
		ans+=count*(count-1)/2;
	}
	for(j=0;j<n;j++)
	{
		count=0;
		for(i=0;i<n;i++)
		{
			if(str[i][j]=='C')
			count++;
		}
		ans+=count*(count-1)/2;
	}
	printf("%d\n",ans);
	return 0;
}