#include<stdio.h>
#include<string.h>
int main()
{
    char a[101];
    int i,count=0;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i+1]==a[i])
        {
            count++;
            if(count>=6)
            {
                printf("YES");
                break;
            }
        }
        else
            count=0;
    }
    if(count<6)
        printf("NO");
    return(0);
}