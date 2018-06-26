#include<stdio.h>
char s[100001];
int t[100000];
int main()
{
scanf("%s",s);
int n,i,j,c,a,b,x=0;
for(i=0;s[i];i++)
{
t[i]=x;
if(s[i]==s[i+1])
x++;
}
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d%d",&a,&b);
printf("%d\n",t[b-1]-t[a-1]);
}
}