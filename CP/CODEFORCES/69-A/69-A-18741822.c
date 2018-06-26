#include<stdio.h>
int main()
{int i,j,n,a1=0,b1=0,c1=0,a,b,c;
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d %d %d",&a,&b,&c);
a1+=a;
b1+=b;c1+=c;
}
if(a1==0&&b1==0&&c1==0)
printf("YES");
else
printf("NO");
return 0;
}