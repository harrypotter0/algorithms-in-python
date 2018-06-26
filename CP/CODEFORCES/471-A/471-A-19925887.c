#include<stdio.h>
int f,a,h[10],i,p[2],e;
int main ()
{
	for(i=0; i<6; i++){scanf("%d",&a);h[a]++;if (h[a]==4)f=1,h[a]=0;}
	for(i=0; i<10; i++)if (h[i])p[e++]=h[i];
	puts((!f)?"Alien":((p[0] != p[1])?"Elephant":"Bear"));
}