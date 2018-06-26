#include<stdio.h>
int n,m,j,s,d,u,i,t,a[100005],h[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=n-1;i>-1;i--)
	{if(!h[a[i]]) t++;h[a[i]]=1;a[i]=t;}
	for(i=0;i<m;i++)
	{scanf("%d",&s);printf("%d\n",a[s-1]);}
	return 0;
}