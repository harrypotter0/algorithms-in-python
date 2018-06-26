#include<stdio.h>
int main() 
{
	int n,m=0,i,j;
	char a[110];
	int b[100]={0};
	scanf("%d",&n);
	scanf("%s",a+1);
	for(i=1;i<=n;)
	{
		if(a[i]=='W')
		{
			i++;
			continue;
		}
		m++;
	
		while(a[i]=='B')
		{
			b[m]++;
			i++;
		}
	}
	printf("%d\n",m);
	for(i=1;i<=m;i++)
		printf("%d ",b[i]);
	return 0;
}