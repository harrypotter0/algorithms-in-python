#include<stdio.h>
typedef unsigned u;
u A[111];
int main()
{
    u n,q,i,j,k,h;
    for(scanf("%u%u",&n,&q);q--;++A[j])
    for(i=-1,h=j=0;++i<n;)
    {
        scanf("%u",&k);
        if(k>h){h=k;j=i;}
    }
    for(i=-1,q=j=0;++i<n;)if(A[i]>q)q=A[j=i];
    printf("%u\n",j+1);
    return 0;
}