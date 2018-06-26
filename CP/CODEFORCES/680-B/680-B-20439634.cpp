#include <cstdio>
int t[101];
int main(){
	int n,a,ans=0;
	scanf("%d %d",&n,&a);
	for(int i=1;i<=n;++i){scanf("%d",&t[i]);ans+=t[i];}
	for(int l=a-1,r=a+1;1<=l && r<=n;--l,++r)ans-=t[l]^t[r];
	printf("%d",ans);
	return 0;
}