#include<cstdio>
int main()
{
	int n,a=2,i;
	scanf("%d",&n);
	puts("2");
	for(i=2;i<=n;i++)printf("%I64d\n",(long long)(i+1)*(i+1)*i-i+1);
}