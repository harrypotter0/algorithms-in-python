#include<stdio.h>
#include<conio.h>
int main()
{
    int n,m,o,max,min,count=0,i;
    scanf("%d",&n);
    scanf("%d",&m);
    max=m;
    min=m;
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&o);
        if(min>o)
        {
            min=o;
            count++;
        }
        if(max<o)
        {
            max=o;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}