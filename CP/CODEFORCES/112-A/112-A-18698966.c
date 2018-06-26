#include<stdio.h>
#include<string.h>
int main ()
{
    char str1[100];
    char str2[100];
    int i=0,a;
    scanf("%s",str1);
    scanf("%s",str2);
    a = strcmpi(str1,str2);
    printf("%d\n",a);
    return 0 ;
}