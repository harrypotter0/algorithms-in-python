#include<stdio.h>
int main ()
{
    int n,i=0,count=0,rem,p=0,flag=0;
    scanf("%d",&n);
    p=n;
    while(n>0)
    {
        rem =n%10;
        if(!(rem==4||rem==7))
        {
            flag=1;
        }
        n=n/10;
    }
    if(p%4==0 || p%7==0|| flag==0||p%47==0||p%74==0)
    {
                printf("YES");
        }
        else{
            printf("NO");
        }
    
    return 0 ;
}