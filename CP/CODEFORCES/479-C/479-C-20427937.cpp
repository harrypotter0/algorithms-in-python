#include <stdio.h>
#include <stdlib.h>
int n,ans,lst[5010][2];
int comp(const void *a, const void *b)
{
	int x = ((int*)a)[0] - ((int*)b)[0];
	if(x) return x;
	return ((int*)a)[1] - ((int*)b)[1];
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&lst[i][0],&lst[i][1]);
	qsort(lst+1,n,sizeof(lst[0]),comp);
	for(i=1;i<=n;i++)
	{
		if(lst[i][1]>=ans) ans = lst[i][1];
		else ans = lst[i][0];
	}
	printf("%d",ans);
	return 0;
}