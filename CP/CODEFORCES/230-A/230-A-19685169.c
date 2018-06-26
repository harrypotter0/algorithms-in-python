#include<stdio.h>
struct d{
    int x,y;
}t;
int main ()
{
    int n,i,j;
    long long q;
    struct d z[1003];
    scanf("%I64d%d",&q,&n);
    for(i=0;i<n;i++) scanf("%d%d",&z[i].x,&z[i].y);
	for(i=0;i<n;i++) for(j=i;j<n;j++) if(z[j].x<z[i].x){t=z[j];z[j]=z[i];z[i]=t;}
	for(i=0;i<n;i++) if(z[i].x<q) q+=z[i].y; else break;
	puts(i<n?"NO":"YES");
}