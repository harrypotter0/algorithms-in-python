#include<cstdio>
using namespace std;
char ch,s[1<<19];
int n,m,p,a,i;
int main(){scanf("%d%d\n%s",&n,&m,s+1);for(i=1;i<=n;i++)a+=(s[i]=='.'&&s[i-1]=='.');
for(i=0;i<m;i++){scanf("%d %c",&p,&ch);
 if (s[p]!='.' && ch=='.')a+=(s[p-1]=='.')+(s[p+1]=='.');
 if (s[p]=='.' && ch!='.')a-=(s[p-1]=='.')+(s[p+1]=='.');
 s[p]=ch;printf("%d\n",a);}
}