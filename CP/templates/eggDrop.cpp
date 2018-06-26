#include <bits/stdc++.h>
using namespace std;
int a[15][5009], p[15];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, i, j, n, h, k, x, res;
    p[0] = 1;
    for(i = 1; i < 15; i++)
        p[i] = p[i-1]*2;
    cin >> t;
    while(t--)
    {
        cin >> n >> h;
        for(x = 14; x >= 0; x--)
        {
            if(p[x] <= h)
                break;
        }
        x++;
        if(n >= x)
            cout << x << '\n';
        else
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 0; j <= h; j++)
                {
                    if(j == 0 || j == 1 || i == 1)
                        a[i][j] = j;
                    else
                    {
                        a[i][j] = INT_MAX;
                        for(k = 1; k <= j; k++)
                        {
                            res = 1 + max(a[i-1][k-1],a[i][j-k]);
                            a[i][j] = min(res,a[i][j]);
                        }
                    }
                }
            }
            cout << a[n][h] << '\n';
        }
    }
    return 0;
}
