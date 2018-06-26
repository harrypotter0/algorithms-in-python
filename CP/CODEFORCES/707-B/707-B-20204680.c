#include<stdio.h>
int main()
{
	int n,m,k,i,j,t,u,v,l,edg[100001][3],in[100001],min=1000000007;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		in[i]=-1;
	for(i=0;i<m;i++)
		scanf("%d%d%d",&edg[i][0],&edg[i][1],&edg[i][2]);
	for(i=0;i<k;i++)
	{
		scanf("%d",&t);
		in[t]=0;
	}
	
	for(i=0;i<m;i++)
	{
		if(edg[i][2]<min &&( (in[edg[i][0]]==0 && in[edg[i][1]]==-1) || (in[edg[i][0]]==-1 && in[edg[i][1]]==0) ))
			min=edg[i][2];
	}
	if(min==1000000007)
		printf("-1\n");
	else
		printf("%d\n",min);
	return 0;
}