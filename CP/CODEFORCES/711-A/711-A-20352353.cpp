#include<stdio.h>
int main ()
{
char str[1000][5];
int n,i,j,f=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%s",&str[i]);
for(j=1;j<5;j++)
{

if((str[i][j]=='O')&&(str[i][j-1]=='O')&&(f==0))
{
f=1;
str[i][j]='+';
str[i][j-1]='+';
break;
}
}
}
if(f==0)
{
printf("NO \n");
}
if(f==1)
{
printf("YES \n");
for(i=0;i<n;i++)
{
for(j=0;j<5;j++)
printf("%c",str[i][j]);
printf("\n");
}

}
return 0;
}