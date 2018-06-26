#include<bits/stdc++.h>
using namespace std;
int i,n,r=2e9,a[200005];
char s[200005];
int main()
{
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++)
		if(s[i]=='R'&&s[i+1]=='L')
			r=min(r,a[i+1]-a[i]);
	printf("%d",r<2e9?r/2:-1);
}