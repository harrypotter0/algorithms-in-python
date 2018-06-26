#include<stdio.h>
int main ()
{
    long long int n,i,a[1000000],count =0,max=0;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<=a[i+1])
        {
            count++;
            if(count>max)
            {
                max=count;
            }
        }
        else
        {
        count =0;
    }}
    printf("%I64d",max+1);
    return 0;
}