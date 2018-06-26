#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {
    int n;
    int maxx;
    int s;
    int x;
    int y;
    int i;
    scanf("%d", &n);
    s = 0;
    maxx = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        s -= x;
        s += y;
        if (s > maxx) {
            maxx = s;
        }
    }
    printf("%d", maxx);
    return 0;
}