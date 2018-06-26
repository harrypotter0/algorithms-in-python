#include<stdio.h>
int main()
{
int a,b,k,m,i,j,t=0;
scanf("%d%d%d%d",&a,&b,&k,&m);
int c[a],d[b];
for(i=0;i<a;i++)
scanf("%d",&c[i]);
for(i=0;i<b;i++)
scanf("%d",&d[i]);
if(c[k-1]<d[b-m])
printf("YES");
else
printf("NO");
}