#include<stdio.h>
int main ()
{
    long int  n;
    int i,j,k,n2,flag=0;
    scanf("%ld",&n);
    for(i=2;i<n;i++)
    {
        
                    if(flag==1)
                    {
                        return 0;
                    }
        for(j=2;j<i;j++)
        {
            
                    if(flag==1)
                    {
                        return 0;
                    }
            if(i%j==0)
            {
                n2=n-i;
                for(k=2;k<n2;k++)
                {
                    if(flag==1)
                    {
                        return 0;
                    }
                    if(n2%k==0)
                    {
                        printf("%d\t%d",i,n2);
                        flag=1;
                    }
                }
            }
        }
    }
    return 0 ;
}