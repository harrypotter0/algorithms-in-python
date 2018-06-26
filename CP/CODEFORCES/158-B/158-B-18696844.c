#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,total=0,g1=0,g2=0,g3=0,g4=0,i;
    int s;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s);
        switch(s)
        {
            case 1 :
                g1++;break;
            case 2 :
                g2++;break;
            case 3 :
                g3++;break;
            case 4 :
                g4++;break;
        }
    }
    total=g4;
    if (g3>g1)
    {
        total+=g3;
        g1=0;
    }
    else
    {
        total+=g3;
        g1-=g3;
    }
    if (g2%2==0)
        total=total+(g2/2);
    else
        {
            total=(total+(g2/2))+1;
            g1=g1-2;
        }
    if (g1>0)
    {
    if (g1<=4)
    {
        total++;
    }
    else
    {
        if (g1%4==0)
            total=(total+(g1/4));
        else
            total=(total+(g1/4))+1;
    }
    }
    printf("%I64d",total);
    return 0;
}