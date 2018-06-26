#include<stdio.h>
# define max(a,b) a>b?a:b
long long int n,i,j,c[100005],f[100005];
int main(){
	scanf("%I64d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d",&j);
		c[j]++;
	}
	for(f[0]=0,f[1]=c[1],i=2;i<100001;i++){
		f[i]=max(f[i-1],f[i-2]+c[i]*i);
	}
	printf("%I64d",f[100000]);
}