#include<stdio.h>
int main()
{
int n,i,j;
char t,s[101];
scanf("%s",s);
for(n=0;s[n]!='\0';n++);
for(i=0;i<n-2;i=i+2)
for(j=i+2;j<n;j=j+2)
if(s[i]>s[j])
{t=s[j];s[j]=s[i];s[i]=t;}
printf("%s",s);
return 0;
}