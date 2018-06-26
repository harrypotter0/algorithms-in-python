#include<stdio.h>
#include <stdlib.h>
int main ()
{
    int a[5][5],i,j,l=0,m=0,sum=0,sum1=0,sum2=0;
    for(i=0;i<5;i++)
      {
          for(j=0;j<5;j++)
          {
              scanf("%d",&a[i][j]);
          }
      }
      for(i=0;i<5;i++)
      {
          for(j=0;j<5;j++)
          {
              if(a[i][j]==1)
              {
                  l=i;m=j;
              }
          }
      }
      sum1=abs(l-2);
      sum2=abs(m-2);
      printf("%d\n",sum1+sum2);
      return 0;
      }