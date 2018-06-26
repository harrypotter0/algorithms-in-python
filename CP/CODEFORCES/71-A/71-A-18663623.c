#include<stdio.h>
#include<string.h>
int main ()
{
    int l,n,i;
    char a[1000];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(a);
        if(strlen(a)>10)
        printf("%c%d%c\n",a[0],strlen(a)-2,a[strlen(a)-1]);
        else
        puts(a);
    }
  
    return 0 ;
}