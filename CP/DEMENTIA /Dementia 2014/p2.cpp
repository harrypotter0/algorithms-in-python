#include<cstdio>
#define s(n) scanf("%d",&n)
int main()
{
	int n,m,i,j,ans,t,px,py,qx,qy;
	s(n);
	s(m);
	int a[n+1][m+1],sum[n+1][m+1];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			s(a[i][j]);
	sum[0][0] = 0;
	for (i=1;i<=n;i++)
		sum[i][0] = 0;
	for (i=1;i<=m;i++)
		sum[0][i] = 0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
	s(t);
	while(t--)
	{
		s(px);
		s(py);
		s(qx);
		s(qy);
		ans = sum[qx][qy] - sum[qx][py-1] - sum[px-1][qy] + sum[px-1][py-1];
// 		ans = sum[qx][qy] -  sum[px-1][py-1];

		printf("%d\n",ans);
	}
	return 0;
}
