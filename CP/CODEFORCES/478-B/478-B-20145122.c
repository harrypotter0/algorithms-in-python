#include<stdio.h>
int main()
{
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%I64d %I64d\n",(b*(a/b)*(a/b-1))/2+(a%b)*(a/b),((a-b+1)*(a-b))/2);
	return 0;
}