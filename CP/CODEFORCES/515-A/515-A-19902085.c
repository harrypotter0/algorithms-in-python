#include<stdio.h>
#include<math.h>
int main()
{
int a,b,s;
scanf("%d%d%d",&a,&b,&s);
if(s>=(abs(a)+abs(b))&&(s-(abs(a)+abs(b)))%2==0)
printf("Yes");
else
printf("No");
}