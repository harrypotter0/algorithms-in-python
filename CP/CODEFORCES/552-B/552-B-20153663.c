#include<stdio.h>
int main(){
	int n,t;
	long long ans=0;
	scanf("%d",&n);
	for(t=1;t<=n;t*=10){
		ans+=n-t+1;
	}
	printf("%I64d\n",ans);
	return 0;
}