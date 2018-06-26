#include<stdio.h>
int main()
{
	int n,f=0;
	scanf("%d",&n);
	while(n>0)
	{
		if(n%10!=1 && n%100!=14 && n%1000!=144)
			f=1;
		n=n/10;
	}
	if(f==1)
		printf("NO");
	else
		printf("YES");
	return 0;
}