#include <cstdio>
#include <algorithm>
using namespace std;
int n,t=0,ou=1,ans1=0,ans2;
char c;
int main(){
	scanf("%d",&n);
	c=getchar();
	for(int i=1;i<=n;i++){
		c=getchar();
		if(c=='('){ou=t=0;continue;}
		if(c==')'){ou=1;t=0;continue;}
		if(c=='_'){t=0;continue;}
		if(ou){t++;ans1=max(ans1,t);}
		else{if(t==0)ans2++;t++;}
	}printf("%d %d\n",ans1,ans2);
	return 0;
}