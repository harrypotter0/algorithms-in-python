#include<iostream>
#define f(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;
using namespace std;
ll a,b,ans;
main(){
	scanf("%I64d%I64d",&a,&b);
	f(i,1,63) f(j,0,i-1) {
		ll c=(1ll<<i)-(1ll<<j)-1;
		 if (a<=c&&c<=b) ans++;
	}
	printf("%d\n",ans);
}