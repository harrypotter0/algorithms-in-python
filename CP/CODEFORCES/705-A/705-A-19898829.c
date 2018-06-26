#include<stdio.h>
#include<conio.h>
int main ()
{
    int n ,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if(i%2==0 && i<n-1)
        printf("I hate that ");
        if(i%2==1 && i<n-1)
        printf("I love that ");
        if(i%2==0 && i==n-1)
        printf("I hate ");
        if(i%2==1 && i==n-1)
        printf("I love ");
    }
    printf("it");
    return 0;
}