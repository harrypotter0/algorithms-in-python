#include <algorithm>
#include <cstdio>
int a[1000000],i,t;
long long x,y;
char c;
int main()
{
	for (scanf("%d\n",&t);t--;)
	{
		scanf("%c %I64d\n",&c,&x);y=0;
		for (i=1;i<=18;++i,x/=10) y=y*2+(x&1);
		if (c=='+') a[y]++;
		else if (c=='-') a[y]--;
		else printf("%d\n",a[y]);
	}
}