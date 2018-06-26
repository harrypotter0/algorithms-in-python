#include<stdio.h>
main () {
int x=0,n=0,s=0,i,j,y,z,t;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d %d %d %d",&x,&y,&z,&t);	
s+=(z-x+1)*(t-y+1);}
printf("%d",s);
}