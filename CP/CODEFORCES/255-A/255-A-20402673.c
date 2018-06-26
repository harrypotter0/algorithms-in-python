#include<stdio.h>
char f[3][7]={"chest","biceps","back"};
int n,i,h[3],a;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		h[i%3]+=a;
	}
	a=0;
	for(i=1;i<3;i++)
		if(h[i]>h[a])
			a=i;
	printf("%s",f[a]);
	return 0;
}