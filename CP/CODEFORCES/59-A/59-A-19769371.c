#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,a=0,count=0,l;
    gets(str);
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        if(str[i]>=65 && str[i]<=90)
        count++;
        else
        a++;
    }
    if(count>a)
        strupr(str);
    else
      strlwr(str);
      printf("%s\n",str);
      return 0;
}