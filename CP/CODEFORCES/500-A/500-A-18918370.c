#include<stdio.h>
main()
{
	int n,t,a[100009],i;
	scanf("%d%d",&n,&t);
	for(i=1;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<t;)
		i+=a[i];
	printf("%s\n",i==t?"YES":"NO");
	return 0;
}