#include<stdio.h>
#include<string.h>
char a[100000][33],b[33];
int h[100000];
int main()
{
int i,n,j,s=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%s",b);
for(j=0;j<s;j++)
if(strcmp(b,a[j])==0)
break;
if(j==s)
{
printf("OK\n");
strcpy(a[s++],b);
}
else
{
h[j]++;
printf("%s%d\n",b,h[j]);
}
}
return 0;
}