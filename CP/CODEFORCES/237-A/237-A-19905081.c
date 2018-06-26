#include<stdio.h>
#include<conio.h>
int main ()
{
    int n , i ,count =1,a,b,c,d,max=1; 
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    c=a;d=b;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a==c && b==d){
            count++;
            if(count>max)
            max=count;
        }else {count=1;}
    c=a;d=b;    
    }
    printf("%d\n",max);
    return 0;
}