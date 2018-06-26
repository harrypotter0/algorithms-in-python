#include<stdio.h>
int main()
{int n,h,i,j,c=0;
scanf("%d%d",&n,&h);
for(i=0;i<n;i++){
scanf("%d",&j);
j>h?c+=2:c++;}
printf("%d",c);}