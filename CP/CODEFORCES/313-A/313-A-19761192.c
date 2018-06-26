#include<stdio.h>
#include<conio.h>
int max(int x,int y)
{
   return x>y?x:y;
}
int main()
{
    int rev1,rev2,n,s;
    scanf("%d",&n);
    if(n>0)
    printf("%d",n);
    else
    {
    rev1= n/10;
    rev2 = (n/100)*10+n%10;
    printf("%d\n",max(rev1,rev2));}
    return 0;
}