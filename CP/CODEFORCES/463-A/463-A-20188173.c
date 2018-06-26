#include <stdio.h>

int main()
{
   int n, s; // n types of sugar, s dollars
   int i;
   int d, c;
   int max = -1;
   scanf("%d %d", &n, &s);
   
   for(i=0; i<n; i++)
   {
      scanf("%d %d", &d, &c);
      
      if(d<s || (d==s && c==0))//can buy
      {
         if( (100-c)%100 > max)
            max = (100-c)%100;
      }
   }
   
   printf("%d", max);
   return 0;
}