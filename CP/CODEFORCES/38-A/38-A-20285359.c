#include <stdio.h>
main()
{int i,s=0,k,l,n,a[101];
scanf("%d",&n);
for(i=1;i<n;i++)
scanf("%d",&a[i]);
scanf("%d%d",&k,&l);
for(i=k;i<l;i++)
s+=a[i];
printf("%d",s);
return 0;}