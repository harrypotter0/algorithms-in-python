#include<cstdio>
#include<cstring>
using namespace std;
int a1[2050],a2[2050];
int main()
{
    int a,b,c=0,d=0,o=0;
    scanf("%d%d",&a,&a);
    for(int i=0;i<a;++i)scanf("%d",a1+i);
    scanf("%d",&b);
    for(int i=0;i<b;++i)scanf("%d",a2+i);
    for(;o<110;++o)
    {
        if(c==a||d==b)
        {printf("%d %d\n",o,(c==a)+1);return 0;}
        if(a1[c]>a2[d])a1[a++]=a2[d++],a1[a++]=a1[c++];
        else a2[b++]=a1[c++],a2[b++]=a2[d++];
    }
    puts("-1");
}