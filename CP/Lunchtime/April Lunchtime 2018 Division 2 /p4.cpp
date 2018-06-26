#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define REP(i,a,b) for(i = a ; i <= b ; i++)
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    lli i,n,sum = 0;
    cin >> n;
    vector<lli > v(n);

    rep(i,n) {
        cin >> v[i];
        sum += v[i];
    }
    REP(i,1,n) {
        if (sum % i == 0) {
            lli temp = sum / i, sum1 = 0,k = 0;
            bool flag = false;
            for (int j = 0; j < n; ++j) {
                sum1 += v[j];
                if(sum1 > temp) {
                    cout << 0;
                    flag = true;
                    break;
                }
                if (sum1 == temp) {
                    k++;
                    sum1 = 0;
                }
            }
            if(flag)
                continue;
            if(k == i)
                cout << 1;
            else
                cout << 0;
        }
        else {
            cout << 0;
        }
    }
    cout << "\n";
}
int main()
{
	opt;
	int t = 1;
    cin >> t;
	while(t--)
	    solve();
	return 0;
}
