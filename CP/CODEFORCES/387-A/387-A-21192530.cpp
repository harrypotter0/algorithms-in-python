#include<cstdio>
main()
{
    int a,b,c,d;
    scanf("%d:%d%d:%d",&a,&b,&c,&d);
    printf("%02d:%02d",(a-c-(d>b)+24)%24,(b-d+60)%60);
}