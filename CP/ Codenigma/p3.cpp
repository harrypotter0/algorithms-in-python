// C++ program to to find all pairs such that
// a % b = k.
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define	endl		    '\n'

// Utiltity function to find the divisors of
// n and store in vector v[]
vector<int> findDivisors(int n)
{
	vector<int> v;

	// Vector is used to store the divisors
	for (int i = 1; i<= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If n is a square number, push
			// only one occurrence
			if (n/i == i)
				v.push_back(i);
			else
			{
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	}
	return v;
}

// Function to find pairs such that (a%b = k)
ll printPairs(ll arr[], ll n, ll k)
{
	// Store all the elements in the map
	// to use map as hash for finding elements
	// in O(1) time.
  int ans =0;
	unordered_map<int, bool> occ;
	for (int i = 0; i < n; i++)
		occ[arr[i]] = true;

	// bool isPairFound = false;
	for (int i = 0; i<n ; i++ )
	{
		// Print all the pairs with (a, b) as
		// (k, numbers greater than k) as
		// k % (num (> k)) = k i.e. 2%4 = 2
		if (occ[k] && k < arr[i])
		{
			// cout << "(" << k << ", " << arr[i] << ") ";
      ans +=1;
			// isPairFound = true;
		}

		// Now check for the current element as 'a'
		// how many b exists such that a%b = k
		if (arr[i] >= k)
		{
			// find all the divisors of (arr[i]-k)
			vector<int> v = findDivisors(arr[i]-k);

			// Check for each divisor i.e. arr[i] % b = k
			// or not, if yes then print that pair.
			for (int j = 0; j < v.size(); j++)
			{
				if (arr[i]%v[j] == k &&
					arr[i]!= v[j] &&
					occ[v[j]])
				{
          ans+=1;
					// cout << "(" << arr[i] << ", "
					// 	<< v[j] << ") ";
					// isPairFound = true;
				}
			}

			// Clear vector
			v.clear();
		}
	}

	return ans;
}

// Driver program
int main()
{
  // your code goes here
  #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
	ll arr[651010];
	ll n,k,t;
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(ll i =0 ;i<n;i++){
      arr[i]=i+1;
    }
    ll ans = printPairs(arr, n, k);
    if (ans == 0)
  		cout <<"0"<<endl;
    else
      cout<<ans<<endl;
  }

	return 0;
}
