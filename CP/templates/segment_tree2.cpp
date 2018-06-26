#include<iostream>
#include<set>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[100001];
multiset< int > seg[400001];
multiset< int > :: iterator it;
ll solve(int i, int j, ll b){
    ll A = - (b * b);
    ll B = (arr[i] + arr[j]);
    B *= b;
    ll C = -(arr[i] * 1LL * arr[j]);
    return A + B + C;
}

ll query(int node, int l, int r, int s, int e, int b){
    if(s > r || l > e) return LONG_LONG_MIN;
    if(l >= s && r <= e){
        it = seg[node].lower_bound(b);
        // cout<<*it<<"it"<<endl;
        ll curr = LONG_LONG_MIN;
        if(it != seg[node].end()){
            // cout<<*it<<"it"<<(*seg[node].end())<<"chu";
            // printf("lodu1\n");
          curr =  max(curr, solve(s, e, *it));
        }
        if(it != seg[node].begin()){
            // cout<<*it<<"it"<<(*seg[node].begin())<<"chu";
            // printf("lodu2\n");
            --it;
            curr = max(curr, solve(s, e, *it));
        }
           return curr;
     }
    ll p = query(2 * node, l , (l + r)/2 , s, e, b);
    ll q = query(2 * node + 1, (l + r)/2 + 1, r, s, e, b);
    return max(p, q);
}
void update(int node, int l, int r, int idx, int value){
    if(idx > r || l > idx) return;
    it = seg[node].find(arr[idx]);
    seg[node].erase(it);
    seg[node].insert(value);
    if(l != r){
        update(2 * node, l, (l + r)/2 , idx, value);
        update(2 * node + 1, (l + r)/2 + 1, r, idx, value);
    }
}
void build(int node, int l, int r){
    if(l == r){
        seg[node].insert(arr[l]);
        return;
    }
    build(2 * node, l, (l + r)/2);
    build(2 * node + 1, (l + r)/2 + 1,  r);
    for(it = seg[2 * node].begin() ; it != seg[2 * node].end(); ++it) seg[node].insert(*it);
    for(it = seg[2 * node + 1].begin() ; it != seg[2 * node + 1].end(); ++it) seg[node].insert(*it);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1 ; i <= 4 * n ; ++i) seg[i].clear();
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d", arr + i);
        }
        build(1, 1, n);
        while(q--){
            int ty;
            scanf("%d", &ty);
            if(ty == 2){
                int idx, val;
                scanf("%d%d", &idx, &val);
                update(1, 1, n, idx, val);
                arr[idx] = val;
            } else {
                int l, r;
                scanf("%d%d", &l, &r);
                int b = (arr[l] + arr[r] + 1)/2;
                printf("%lld\n", query(1, 1, n, l, r, b));
            }
        }
    }
}
