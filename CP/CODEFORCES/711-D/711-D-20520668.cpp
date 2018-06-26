#include<bits/stdc++.h> 
#define mod 1000000007
#define N 200010
using namespace std;
int n,i,ans,nn,a[N],f[N],vis[N],j,now,cnt;
int main() {
	scanf("%d",&n);
	nn=n;ans=1;f[0]=1;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		f[i]=f[i-1]*2%mod;
	}
	for(i=1;i<=n;i++) if(!vis[i]) {
		now=cnt;
		for(j=i;!vis[j];j=a[j]) vis[j]=++cnt;
		if(vis[j]>now) {
			nn-=cnt-vis[j]+1;
			ans=1ll*ans*(f[cnt-vis[j]+1]-2)%mod;
			if(ans<0)ans+=mod;
		}
	}
	ans=1ll*ans*f[nn]%mod;
	printf("%d\n",ans);
}