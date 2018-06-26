#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101], sub[201];
    int i, j=0;
    scanf("%s", str);

    for(i=0; i<101; i++) {
	char c;
	if(str[i] == '\0') {
	    sub[j] = '\0';
	    break;
	}
	c = tolower(str[i]);
	if(!(c == 'a' || c == 'i' || c == 'u' ||
	     c == 'e' || c == 'o' || c == 'y') ) {
	    sub[j] = '.';
	    sub[j+1] = c;
	    j += 2;
	}
    }

    printf("%s", sub);
    return 0;
}