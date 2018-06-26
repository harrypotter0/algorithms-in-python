/*
For integer strings and their conversions without argument 
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int Nmax = 100005;
const int modulo = 1000000009;

int T, N, gap;
int SA[Nmax], poz[Nmax], tmp[Nmax], sir[Nmax];
int height[Nmax], lcp[Nmax];

inline int cmp( int i, int j )
{
    if ( poz[i] != poz[j] )
            return poz[i] < poz[j];

    i += gap;
    j += gap;

    if ( i < N && j < N )
            return poz[i] < poz[j];
    else
            return i > j;
}

void SuffixArray()
{
    for ( int i = 0; i < N; ++i )
            SA[i] = i,
            poz[i] = sir[i] - 97;

    for ( gap = 1; ; gap <<= 1 )
    {
        sort( SA, SA + N, cmp );

        for ( int i = 0; i < N - 1; ++i )
                tmp[i + 1] = tmp[i] + cmp( SA[i], SA[i + 1] );

        for ( int i = 0; i < N; ++i )
                poz[ SA[i] ] = tmp[i];

        if ( tmp[N - 1] == N - 1 )
                break;
    }
}

void LCP()
{
    for ( int i = 0, k = 0; i < N; ++i )
    {
        if ( poz[i] == N - 1 )
                continue;

        for ( int j = SA[ poz[i] + 1 ]; sir[i + k] == sir[j + k]; ) k++;

        lcp[ poz[i] ] = k;

        if ( k > 0 )
                k--;
    }
}

int main()
{
    //freopen("date.in", "r", stdin);

    scanf("%d", &T);

    for ( ; T; T-- )
    {
        scanf("%d", &N);

        for ( int i = 0; i < N; ++i )
                scanf("%d", &height[i]);

        for ( int i = 0; i < N - 1; ++i )
                sir[i] = height[i + 1] - height[i];

        sir[N - 1] = -10000;

        SuffixArray();
        LCP();

        long long total = 1LL * N * ( N - 1 ) / 2;

        for ( int i = 0; i < N; ++i )
        {
            total -= lcp[i];
        }

        total %= modulo;

        printf("%lld\n", total);
    }

    return 0;
}
