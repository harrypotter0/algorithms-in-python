#include<stdio.h>
#include<string.h>
#define swap(a,b) {t=a;a=b;b=t;}
int main ()
{
 char a,b,t,str[10000000]={0};
 long long  int p,u,f=-1;
 gets(str);
 p=strlen(str);
 for(u=0;u<p;u++)
 {
	 if(!((str[u]-'0')%2))
	 {
		 f=u;
		if (str[u]<str[p-1])
  			break;
	 }
 }
if (f != -1)
	{
 swap(str[f],str[p-1]);
 puts(str);
	}
else
 puts("-1");
return 0;
}