#include <bits/stdc++.h>
using namespace std;
int n,c,p,r;
int main() {
	for (scanf("%d",&n);n--;) {
		scanf("%d",&c);
		if (c) r+=2-p;
		p=c;
	}
	printf("%d\n",max(r-1,0));
}