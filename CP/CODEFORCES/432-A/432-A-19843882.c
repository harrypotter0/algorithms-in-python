#include<stdio.h>
#include<conio.h>
int main ()
{
    int n,m,arr,i,count=0; 
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr);
        if(arr<=5-m)
            count++;
    }
    printf("%d",count/3);
    return 0 ;
}