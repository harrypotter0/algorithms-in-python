#include <bits/stdc++.h>

using namespace std;

#define MAXN 111
#define MOD 100003
#define LL long long int

LL dp[MAXN][MAXN] = {0};
LL a, b, c, i, j;

inline void Solve(){
    cin>>a>>b>>c;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j <= a;j++)
        {
            if(j>=b)
            {
                dp[i+1][j] += dp[i][j] * (j - b);
                dp[i + 1][j] %= MOD;
                dp[i+1][j+1] += dp[i][j] * (a - j);
                dp[i + 1][j + 1] %= MOD;
            }
            else{
                dp[i+1][j+1] += dp[i][j] * (a - j);
                dp[i + 1][j + 1] %= MOD;
            }
        }
    }
    cout<<dp[c][a]<<endl;
}

int main()
{
    Solve();
    return 0;
}
