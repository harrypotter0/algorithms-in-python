#include<stdio.h>
int main()
{
    int a[100],b[100];
    int i,j,n,temp=0,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=i;
    }
   
    for(j=1;j<=n;j++)
    {   for(k=1;k<=n;k++)
    {
        if(j==a[k])
        {
            printf("%d\t",b[k]);
            k++;
        }
    }
        
    }
    return 0;
}