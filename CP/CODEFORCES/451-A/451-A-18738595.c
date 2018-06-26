#include<stdio.h>
int main ()
{
 int a,b,count=0;
 scanf("%d%d",&a,&b);
 while(a>0 && b>0)
 {
  a--;
  b--;
  count++;
 }
 if(count%2==0)
 {
 printf("Malvika");
 }
 else
 {
 printf("Akshat");
 }
 return 0;
 
}