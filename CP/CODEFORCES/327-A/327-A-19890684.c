#include<stdio.h>
int main(){
	int i,n,a,x,y,mx;
	scanf("%d",&n);
	for(mx=x=y=i=0;i<n;i++){
		scanf("%d",&a);
		if(a) y++;
		if(!a) x++,mx=x>mx?x:mx;
		else if(x>0) x--;
	}
	if(!mx) mx--;
	printf("%d",y+mx);
	return 0;
}