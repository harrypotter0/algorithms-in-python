#include <stdio.h>
int main(void)
{
    long long num,a;
    int luckydigit=0;
    
    scanf("%I64d",&num);
    while(1)
    {
       if( num%10==4 || num%10==7 )
          luckydigit++;
       if(num<10)
          break;
       num=num/10;       
    }
    if( luckydigit==4 || luckydigit==7 )
       printf("YES");
    else
       printf("NO");
    
    return 0;
}