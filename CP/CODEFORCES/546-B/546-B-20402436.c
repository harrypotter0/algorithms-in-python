#include<stdio.h>

int a[7003];

int main()
{
		int n;
		int ans=0;
		scanf("%d",&n);
		while(n--)
		{

				int x;
				scanf("%d",&x);
				while( a[x]==1 )
				{
						x++;
						ans++;
				}
				a[x]=1;
		}
		printf("%d\n",ans);

		return 0;
}