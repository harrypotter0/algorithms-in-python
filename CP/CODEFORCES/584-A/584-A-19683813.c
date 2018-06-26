#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    if(n==1 && m ==10)
    {
        printf("-1");
        return 0 ;
    }
    if(m==10)
    {
        printf("1");
        for(i=2;i<=n;i++)
        printf("0");
        puts("");
    }
    if(m<10)
    {
    for(i=1;i<=n;i++)
    printf("%d",m); 
    puts("");
    }
return 0 ;
}