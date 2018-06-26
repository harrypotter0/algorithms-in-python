#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define FOR(i,n) for(int i=0;i<n;i++)

// God is real, unless declared integer.


long long countSubarrays(long long arr[], long long  n, long long k)
{
    long long start = 0, end = 0, count = 0, sum = arr[0];

    while (end < n) {

        // If sum is less than k, move end
        // by one position. Update count
        // and sum accordingly.
        if (sum <= k) {
            end++;
            count += end - start;

            // For last element, end may
            // become n.
            if (end < n)
               sum += arr[end];
        }

        // If sum is greater than or equal
        // to k, subtract arr[start] from
        // sum and decrease sliding window
        // by moving start by one position
        else {
            sum -= arr[start];
            start++;
        }
    }

    return count;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   int t = 1;
  // cin >> t;
   while(t--){
  long long n, k;
  cin >> n >> k;
  long long a[n];
  FOR(i, n)
    cin >> a[i];
    cout << countSubarrays(a,n, k);

   }
   return 0;
}
