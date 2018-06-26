#include<stdio.h>
#include<string.h>
int main ()
{
    char str[100];
    int i=0,j=0,len1=0,len2=0,k,kk,temp,c=0;
    gets(str);
    len1=strlen(str);
    for(k=0;k<len1;k++)
    {
        for(kk=0;kk<len1-1;kk++)
        {
            if(str[kk]>str[kk+1])
            {
              temp=str[kk];
              str[kk]=str[kk+1];
              str[kk+1]=temp;
            }  
        }
    }
    for(i=0;i<len1;i++)
    {
        if(str[i]!=str[i+1])
        {
            c++;
        }
    }
    if((c)%2==0)
    printf("CHAT WITH HER!\n");
    else
    printf("IGNORE HIM!\n");
    return 0;
}