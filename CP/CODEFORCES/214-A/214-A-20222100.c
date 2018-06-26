#include<stdio.h>
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	int c=0;
	for(a=0;a*a<=n;a++)
	{
		b=n- a*a;
		if((b*b)==(m-a))
			c++;
	}
	printf("%d",c);
	return 0;
}