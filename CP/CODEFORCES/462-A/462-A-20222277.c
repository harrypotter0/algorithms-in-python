#include<stdio.h>
typedef unsigned u;
char D[111][111];
int main()
{
	u n,i,j,k;
	scanf("%u",&n);
	for(i=0;i++<n;)scanf("%s",D[i]+1);
	for(i=0;i++<n;)
	{
		for(j=0;j++<n;)
		{
			if(((D[i+1][j]=='o')^(D[i-1][j]=='o')^(D[i][j+1]=='o')^(D[i][j-1]=='o'))&1)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}