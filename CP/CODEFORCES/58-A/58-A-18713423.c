#include<stdio.h>
#include<string.h>
int main()
{
int i=0,count=0,l;
char s[101];
scanf("%s",s);
l=strlen(s);
while(i<l&&s[i]!='h')
i++;
count++;
while(i<l&&s[i]!='e')
i++;
count++;
while(i<l&&s[i]!='l')
i++;
i++;
count++;
while(i<l&&s[i]!='l')
i++;
count++;
while(i<l&&s[i]!='o')
i++;
if(i<l)
count++;
if(count==5)
printf("YES");
else
printf("NO");
return 0;
}