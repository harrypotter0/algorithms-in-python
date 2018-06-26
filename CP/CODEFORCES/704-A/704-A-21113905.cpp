#include<bits/stdc++.h>
using namespace std;
int n,i,x,q,t,ans,j,a[300010],num[300010],z[300010],c;
int main() {
  scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d",&t,&x);
		if (t == 1)z[++c]=x,num[x]++,ans++;
		else if (t == 2)ans -= num[x],num[x] = 0,a[x] = c;
		else while(i<=x){
				if (i > a[z[i]])ans--,num[z[i]]--;
				i++;
      }
		printf("%d\n",ans);
	}
	return 0;
}