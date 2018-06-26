#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,temp,sum=0,sum1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
     sum1+=a[i];
         if(sum1>(sum-sum1))
         {
         printf("%d",i+1);
         return 0;
         }
    }
}