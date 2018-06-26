#include <stdio.h>

int main()
{
    int n,v,q,w,a=1,s=1;
    scanf("%d%d",&n,&v);
    q=w=v;
    while(--n)
    {
        scanf("%d",&v);
        if(q==v) a++;
        else if(q>v) q=v,a=1;
        if(w==v) s++;
        else if(w<v) w=v,s=1;
    }
    printf("%d %I64d\n",w-q,q==w?(1LL*(a-1)*a)>>1:1LL*s*a);
    return 0;
}