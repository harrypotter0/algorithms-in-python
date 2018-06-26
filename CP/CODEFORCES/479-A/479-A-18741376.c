#include<stdio.h>
int main ()
{
    int a,b,c,d=0,e=0,f=0,g=0;
    scanf("%d%d%d",&a,&b,&c);
    d=(a+b)*c;
    e=a*(b+c);
    f=a*b*c;
    g=a+b+c;
    while(1)
    {
    if(d>=e &&d>=f && d>=g)
    {
        printf("%d",d);break;
    }
    if(e>=f &&e>=d &&e>=g)
    {
        printf("%d",e);break;
    }
    if(f>=e &&f>=d && f>=g)
    {
        printf("%d",f);break;
    }
    if(g>=e &&g>=d&& g>=f)
    {
        printf("%d",g);break;
    }
    }
    return 0;
}