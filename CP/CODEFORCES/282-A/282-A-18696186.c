#include<stdio.h>
int main ()
{
 int n,x,i,j;
 scanf("%d",&n);
 x=0;
 for(i=1;i<=n;i++)
 {   
     char a[10];
         scanf("%s",a);
     if(a[1]=='+')
     {
     x++;
         
     }
     else
     {
     x--;
     }
 }
 printf("%d",x);
 return 0 ;
}