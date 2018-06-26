#include<stdio.h>

int sort_dec(int *a,int n)
{int i,j,t;
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]<a[j])
{t=a[i];
a[i]=a[j];
a[j]=t;
}
return 0;
}


int main()
{ 
int n,i,a[100],b[100],c=0,d=0;
scanf("%d",&n);
getchar();
for(i=0;i<n;i++)
a[i]=getchar();
for(i=0;i<n;i++)
b[i]=getchar();
sort_dec(a,n);
sort_dec(b,n);
for(i=0;i<n;i++)
if(a[i]>b[i])
c++;
else if(a[i]<b[i])
d++;
if((c>d?c:d)==n)
printf("YES");
else
printf("NO");
return 0;
}