#include<stdio.h>
#include<conio.h>
#include<string.h>
int main ()
{
    int a[26],b[26],i,l,flag=0; 
    char arr[101];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    gets(arr);
    l = strlen(arr);
    for(i=0;i<l;i++)
    a[arr[i]-65]++;
    gets(arr);
    l=strlen(arr);
    for(i=0;i<l;i++)
    a[arr[i]-65]++;
    gets(arr);
    l=strlen(arr);
    for(i=0;i<l;i++)
    b[arr[i]-65]++;
    for(i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            flag=1;
            printf("NO\n");
            break;
        }
    }
    if(flag==0)
    {
        printf("YES \n");
    }
    return 0;
    }