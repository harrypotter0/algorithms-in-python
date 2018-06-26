#include<stdio.h>
int main()
{
    int n,a[100000],i,count=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++)
    {
        if(a[j]==10 && a[j+1]==01)
        {
            count++;
        }
        if(a[j]==01 && a[j+1]==10)
        {
            count++;
        }
    }
    printf("%d\n",count+1);
    return 0;
}