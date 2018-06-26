#include<stdio.h>
#include<math.h>
int main()
{
int n,i,a,b,c,d,v;
double m=1000000000.0;
scanf("%d%d%d",&a,&b,&n);
for(i=0;i<n;i++)
{
scanf("%d%d%d",&c,&d,&v);
double f=sqrt(pow(c-a,2)+pow(d-b,2));
if((double)f/v<m)
m=f/v;
}
printf("%.15lf",m);
}