#include<stdio.h>
int n,k,s,i,a,top;
int main()
{
	scanf("%d %d",&n,&k);
	for(i=0; i<n; i++)
	{
		s=0;
		scanf("%d",&a);
		while(a){if(a%10==4 || a%10==7)s++;a/=10;}
		if (s<=k)top++;
	}
	printf("%d",top);
return 0;
}