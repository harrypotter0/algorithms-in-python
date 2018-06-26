#include<stdio.h>
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	int a=1,b=1+k;
	while(a<b) printf("%i %i ",a++,b--);
	if(a==b) printf("%i ",a);
	for(int i=2+k;i<=n;i++) printf("%i ",i);
	return 0;
}