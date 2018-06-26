#include<stdio.h>
int main()
{
int n,v,ki,si[100],i,c=0,f=0,a[100],j=0,m=0;
scanf("%d%d",&n,&v);
while(n--){
m++;
scanf("%d",&ki);
f=0;
for(i=0;i<ki;i++){
scanf("%d",&si[i]);
if(si[i]<v)
f=1;
}
if(f){
a[j++]=m;
c++;
}
}
printf("%d\n",c);
for(i=0;i<j;i++)
printf("%d ",a[i]);
return 0;
}