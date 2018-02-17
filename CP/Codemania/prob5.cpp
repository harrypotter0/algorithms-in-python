#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll siz = 5e5 + 4;
const ll inf = 1e18;
ll arr[siz], tree[4 * siz];	//Size of Segment tree is never going to be more than 4 * siz.

void build(ll node, ll start, ll end) {
  if(start == end)
    tree[node] = arr[start];       // Leaf node will have a single element.
  else {
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);	// Recurse on the left child.
    build(2 * node + 1, mid + 1, end);	// Recurse on the right child.
    // Internal node will have the sum of both of its children.
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}

ll query(ll node, ll start, ll end, ll l, ll r) {
  if(r < start || end < l)
    return -inf;	// range represented by a node is completely outside the given range.
  if(l <= start && end <= r)
    return tree[node];	// range represented by a node is completely inside the given range.
  // range represented by a node is partially inside and partially outside the given range.
  ll mid = (start + end) / 2;
  ll s1 = query(2 * node, start, mid, l, r);
  ll s2 = query(2 * node + 1, mid + 1, end, l, r);
  return max(s1 ,s2);
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
  /*for(int i = 0; i < v1.size(); ++i){
    cout<<v[i].first<<" "<<arr[i]<<"\n";
  }*/
  build(1, 0, v1.size() - 1);
  while(q--){
    ll l, r;
    scanf("%lld %lld", &l, &r);
    ll left = lower_bound(v1.begin(), v1.end(), l) - v1.begin();
    if(v1[left] > l && left > 0)
      left--;
    ll right = upper_bound(v1.begin(), v1.end(), r) - v1.begin();
    right--;
    if(right < 0 || v1[v1.size() - 1] < l){
      //cout<<"OK\n";
      printf("0\n");
    }
    else{
      printf("%lld\n", query(1, 0, v1.size() - 1, left, right));
    }
  }
}
