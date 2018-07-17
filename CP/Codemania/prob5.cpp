#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define N 55555 + 4
#define inf 0x7fffffff
/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build(1, 0, N-1)
 * Update tree: update(1, 0, N-1, i, j, value)
 * Query tree: query(1, 0, N-1, i, j)
 */
ll arr[N];
ll tree[4*N];

/**
 * Build and init tree
 */
void build(ll node, ll a, ll b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build(node*2, a, (a+b)/2); // Init left child
	build(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update(ll node, ll a, ll b, ll i, ll j, ll value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] += value;
    		return;
	}

	update(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
ll query(ll node, ll a, ll b, ll i, ll j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = max(q1, q2); // Return final result

	return res;
}

int main(){
  ll n, q;
  scanf("%lld %lld", &n, &q);
  vector<pair<ll, ll> > v;
  map<ll, ll> mp;
  for(ll i = 0; i < n; ++i){
    ll l, r, s;
    scanf("%lld %lld %lld", &l, &r, &s);
    mp[l] += s;
    mp[r + 1] = mp[r + 1] - s;
  }
  vector<ll> v1;
  for(auto it = mp.begin(); it != mp.end(); ++it){
    v.push_back({it->first, it->second});
    v1.push_back(it->first);
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());

  arr[0] = v[0].second;
  for(ll i = 1; i < v1.size(); ++i){
    arr[i] = arr[i - 1] + v[i].second;
  }

  // build(1, 0, N-1);

	// update(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	// update(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	// update(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

	// cout << query(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]

  build(1, 0, v1.size() - 1);
  while(q--){
    ll l, r;
    scanf("%lld %lld", &l, &r);
    ll left = lower_bound(v1.begin(), v1.end(), l) - v1.begin();
    // cout<<left<<" "<<v1[left]<<" "<<l<<endl;
    if(v1[left] > l && left > 0)
      left--;
    ll right = upper_bound(v1.begin(), v1.end(), r) - v1.begin();
    right--;
    // cout<<left<<" "<<v1[left]<<" "<<l<<endl;

    // cout<<right<<" "<<v1[right]<<" "<<r<<endl;

    if(right < 0 || v1[v1.size() - 1] < l){
      //cout<<"OK\n";
      printf("0\n");
    }
    else{
      printf("%lld\n", query(1, 0, v1.size() - 1, left, right));
    }
  }
}
