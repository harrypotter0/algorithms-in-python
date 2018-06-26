#include<cstdio>
int x,i,n,s,ns,y,S[100010],b[100010];
char ch;
int main(){
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++){
		scanf("%c",&ch);
		while(ch=='\n')
		scanf("%c",&ch);
		scanf("%d%d",&x,&y);
		if(ch=='S')S[x]+=y;
		else b[x]+=y;
	}
	for(i=0;i<=100000&&ns<s;i++)
		if(S[i])ns++;
	for(;i>=0;i--)
		if(S[i])printf("S %d %d\n",i,S[i]);
	for(i=100000;i>=0&&s;i--)
		if(b[i]){
			s--;
			printf("B %d %d\n",i,b[i]);
		}
}