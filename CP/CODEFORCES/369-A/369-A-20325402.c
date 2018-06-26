#include<stdio.h>
#include<string.h>
int main(){
	int a,x,y,w,i,s=0;

	scanf("%d %d %d",&a,&x,&y);

	for(i=1;i<=a;i++)
   {
	   scanf("%d",&w);

	   if(w==2 && y>0)     y--;
	   else if(x>0)        x--;
	   else s++;
   }

	printf("%d",s);
   
	return 0;
}