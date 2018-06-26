#include <stdio.h>

typedef long long LL_t;
LL_t Sum;

int main()
{
	int N,M,pre,now;
	scanf("%d %d %d",&N,&M,&pre);
	Sum=pre-1;
	while(--M)
	{
		scanf("%d",&now);
		if(now>=pre)
		{
			Sum+=now-pre;
		}
		else
		{
			Sum+=(now+N)-pre;
		}
		pre=now;
	}
	printf("%I64d\n",Sum);
	return 0;
}