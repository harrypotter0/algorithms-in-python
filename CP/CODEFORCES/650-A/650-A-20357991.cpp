#include <stdio.h>
#include <stdlib.h>
int n,pos[200010][2];
long long ans;
int comp1(const void *a,const void *b)
{
	int ret = ((int*)a)[0] - ((int*)b)[0];
	return ret?ret:((int*)a)[1] - ((int*)b)[1];
}
int comp2(const void *a,const void *b)
{
	int ret = ((int*)a)[1] - ((int*)b)[1];
	return ret?ret:((int*)a)[0] - ((int*)b)[0];
}
int main()
{
	int i;
	long long cnt,same;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&pos[i][0],&pos[i][1]);
	qsort(pos+1,n,sizeof(pos[0]),comp1);
	for(i=2,cnt=1,same=1;i<=n;i++)
	{
		if(pos[i][0] == pos[i-1][0]) cnt++;
		else { ans += cnt*(cnt-1)/2; cnt = 1;}
		if(pos[i][0] == pos[i-1][0] && pos[i][1] == pos[i-1][1]) same++;
		else { ans -= same*(same-1)/2; same = 1;}
	}
	ans += cnt*(cnt-1)/2; ans -= same*(same-1)/2;
	qsort(pos+1,n,sizeof(pos[0]),comp2);
	for(i=2,cnt=1;i<=n;i++)
	{
		if(pos[i][1] == pos[i-1][1]) cnt++;
		else { ans += cnt*(cnt-1)/2; cnt = 1;}
	}
	ans += cnt*(cnt-1)/2;
	printf("%I64d",ans);
	return 0;
}