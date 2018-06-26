#include<stdio.h>
int main()
{
	char s[101],a[]="hello";
	int len,i,k;
	scanf("%s",s);
	for(i=0,k=0;s[i]!='\0';i++)
	{
		if(s[i]==a[k])
			k++;
		
	}
	if(k>4)
		{
			printf("YES");
		}
	else
		printf("NO");
	return 0;



}