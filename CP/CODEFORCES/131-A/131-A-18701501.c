#include<stdio.h>
#include<string.h>
int lc(char c);
int main()
{
    int i=1,n,l,count=0;
    char ch[105];
    scanf("%s",ch);
    l=strlen(ch);
    
    for(i=1;i<l;i++)
    {
        if(!lc(ch[i]))
        count++;
        
    }
    if(count==l-1){
    for(i=1;i<l;i++)
    ch[i]+=32;
    if(lc(ch[0]))
    ch[0]=ch[0]-32;
    else
    ch[0]+=32;
    }
    puts(ch);
    return 0;
}
int lc(char c){return (c>='a'&&c<='z')?1:0;}