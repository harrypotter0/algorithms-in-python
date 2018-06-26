#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main ()
{
    char str[1000];
    gets(str);
    printf("\n");
    if(islower(str[0]))
    {
        str[0]-=32;
    }
    puts(str);
    return 0;
}