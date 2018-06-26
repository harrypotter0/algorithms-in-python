#include<stdio.h>
#include<string.h>
int main (){int i,j,k,count=1,n,l,end=0;    char primary[110];
scanf("%d\n",&n);gets(primary);    for(i=0;i<n;i++){if(primary[i]=='0')
{    end=1;break;}        else count++;
}if(end!=1)count=count-1;printf("%d\n",count);return 0;}