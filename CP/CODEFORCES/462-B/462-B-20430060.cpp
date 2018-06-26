#include<stdio.h>
#include<math.h>

int main(){
	int n,k,i,d;
	long long c=0;
	char s[100001];
	int a[28]={0};
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	for(i=0;i<n;i++){
		d=s[i]-'A';
		a[d]++;
	}
	for(;k>0;){
		d=0;
		for(i=0;i<28;i++) d=(a[i]>a[d])?i:d;
		c+=a[d]<k?pow(a[d],2):pow(k,2);
		k-=a[d];
		a[d]=0;
	}
	printf("%lld",c);
	return 0;
}