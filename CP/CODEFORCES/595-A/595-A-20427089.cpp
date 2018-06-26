#include<stdio.h>
int main()
{
	int i,n,m,x,y,sum=0;
	scanf("%i%i",&n,&m);
	for (i=0;i<m*n;i++)
	{
		scanf("%i%i",&x,&y);
		if (x || y)
			sum++; 
	}
	printf("%i",sum);
	return 0;
}