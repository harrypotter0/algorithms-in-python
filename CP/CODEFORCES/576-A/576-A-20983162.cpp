#include <cstdio>

int n;
int m,q[1009];

int main()
{
	scanf("%d",&n);

	for (int i=2;i<=n;++i)
	{
		int a=i;
		for (int j=2;j<=a;++j) if (a%j==0)
		{
			while (a%j==0) a/=j;
			break;
		}
		if (a==1) q[m++]=i;
	}
	printf("%d\n",m);
	while (m--) printf("%d%c",q[m]," \n"[m==0]);
	return 0;
}