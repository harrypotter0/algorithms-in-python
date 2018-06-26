#include<stdio.h>
int main()
{int i,j,k,n,c;
char a[100];
while(scanf("%s",a)!=EOF)
{for(i=0;a[i]!='\0';i++);
for(j=0;j<=i;j++)
for(k=j,n=0;k<=i;k++)
if(a[j]<a[k])
{c=a[j];
a[j]=a[k];
a[k]=c;}
for(j=0,k=0;j<=i-1;j++)
if(a[j]!=a[j+1])
k++;
if(k%2==0)
printf("CHAT WITH HER!\n");
else
printf("IGNORE HIM!\n");}
return 0;
}