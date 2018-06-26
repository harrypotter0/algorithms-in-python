#include<stdio.h>
#include<string.h>
int main ()
{
    char str[100];
    int i,j,n,count=0;
    scanf("%d\n",&n);
    gets(str);
    for(i=0;i<n;i++)
    {
        if(str[i]==str[i+1])
        { 
            count++;
    } 
        
    }
    printf("%d\n",count);
    return 0 ;
}