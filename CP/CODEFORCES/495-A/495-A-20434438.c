#include<stdio.h>
int c[10]={2,7,2,3,3,4,2,5,1,2};
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",c[n/10]*c[n%10]);
	return 0;
}