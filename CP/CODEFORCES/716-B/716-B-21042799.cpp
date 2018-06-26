#include<cstdio>
#include<cstring>
#define MAXL 50000
char s[MAXL+5];
int main(){
	scanf("%s",s);
	int l,i,j,k,t[26],o;
	for(l=0;s[l];l++);
	for(i=0;i+25<l;i++){
		memset(t,0,sizeof(t));o=1;
		for(j=0;j<26;j++)
			if(s[i+j]!='?'&&t[s[i+j]-'A']++)
				o=0;
		if(o){
			for(j=0;j<26;j++)if(s[i+j]=='?')
				for(k=0;k<26;k++)
					if(!t[k]++){
						s[i+j]=k+'A';
						break;
					}
			for(j=0;s[j];j++)
				printf("%c",s[j]=='?'?'A':s[j]);
			return 0;
		}
	}
	puts("-1");
}