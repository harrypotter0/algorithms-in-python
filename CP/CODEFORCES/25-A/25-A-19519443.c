#include<stdio.h>
int main()
{
    short n,a[100],i,c=0;
    scanf("%hd",&n);
    for(i=0;i<n;i++)
    {
        scanf("%hd",&a[i]);
        if(a[i]%2==0)
            c++;
    }
    if(c==1)
         for(i=0;i<n;i++)
         {
            if(a[i]%2==0)
            {
                printf("%hd",i+1);
                break;
            }
         }
    else
         for(i=0;i<n;i++)
         {
            if(a[i]%2!=0)
            {
                printf("%hd",i+1);
                break;
            }

         }


    return(0);
}