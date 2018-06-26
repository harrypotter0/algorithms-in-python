#include<bits/stdc++.h>
#define MAXN 200000
char s[MAXN+5];
int main()
{
	int n,t,i,z=0;
	scanf("%d%d%s",&n,&t,s);
	for(i=0;i<n;i++)if(s[i]=='.')break;
	for(i++;i<n;i++)if(s[i]>'4')break;
	if(i<n)
		for(;t&&s[i]>'4';i--,t--)
			if(s[i-1]=='.'){s[i-2]++;z=1;break;}
			else s[i-1]++;
	else i--;
	if(z)
	{
		for(i-=2;i&&s[i]>'9';i--)
		{
			s[i]='0';
			s[i-1]++;
		}
		if(!i)if(s[0]>'9'){printf("1");s[0]='0';}
		for(i=0;s[i]!='.';i++)printf("%c",s[i]);
	}
	else for(z=0;z<=i;z++)printf("%c",s[z]);
}