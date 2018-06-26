#include <stdio.h>
int main()
{
   int n,m,a;
   scanf("%d%d%d",&m,&n,&a);
   printf("%I64d",(long long)(--m/a+1)*(--n/a+1));
   return 0;
}