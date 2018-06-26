#include<stdio.h>
#include<stdlib.h>

int main(){
    char s[201] = {};
    int i, f, g;
    gets(s);
    for (i = 0 ; s[i] ; ++i){
        f = 0;
        g = i;
        while (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
              i += 3;
              f = 1;
        }
        if (s[i]){
           if (f && g)putchar(' ');
           putchar(s[i]);
        }
    }
    putchar('\n');
    scanf(" ");
    return 0;
}