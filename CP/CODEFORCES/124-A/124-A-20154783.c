#include <stdio.h>
main()
{int a,b,n;
scanf("%d%d%d",&n,&a,&b);
while(a>n-b-1)
b--;
printf("%d",b+1);
return 0;}