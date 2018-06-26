#include <iostream>

int n, m, k, b[1002][1002];

int sq(int r, int c)
{
    return b[r][c] && b[r][c + 1] && b[r + 1][c] && b[r + 1][c + 1];
}

int g(void)
{
    int i;
    for (i = 1; i <= k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        b[r][c] = 1;
        if (sq(r - 1, c - 1) || sq(r - 1, c) || sq(r, c - 1) || sq(r, c))
            return i;
    }
    return 0;
}

int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", g());
    return 0;
}