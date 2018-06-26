#include<stdio.h>
#include<string.h>
int main()
{
    char a[101];
    int i,flag=0;
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='9'||a[i]=='H'||a[i]=='Q')
            flag++;
    }
    if(flag>0)
        printf("YES");
    else
        printf("NO");
    return(0);
}