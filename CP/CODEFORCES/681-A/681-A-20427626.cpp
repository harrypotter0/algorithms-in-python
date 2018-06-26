#include<stdio.h>
int main()
{
int i,n,a,b;
char s[11];
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%s%d%d",s,&a,&b);
if(a>=2400 &&(b-a)>0)
{
printf("YES");
return 0;
}
}
printf("NO");
}