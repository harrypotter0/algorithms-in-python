#include<stdio.h>
int a[2005],n,i,j,c,x;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		for(j=i,c=0;j!=-1;j=a[j],c++);
		if(x<c) x=c;
	}
	printf("%d",x);
}