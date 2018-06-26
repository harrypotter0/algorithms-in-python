#include<bits/stdc++.h>
#define up 1
#define right 2
#define down 3
#define left 4
#define mod 1000000007
#define ll long long

using namespace std;

int arr[10001];
int segment[40001];

int query(int node, int l, int r, int s, int e)
{
    if(s > r || l > e) return 0;
    if(l >= s && r <= e) return segment[node];
    return max(query(2 * node, l, (l + r)/2 , s , e) , query(2 * node + 1, (l + r)/2 + 1 , r , s , e));
}

void update(int node, int l, int r, int idx, int value)
{
    if(idx > r || l > idx) return;
    if(l == r){
        segment[node] = max(segment[node], value);
        return;
    }
    update(2 * node, l, (l + r)/2 , idx, value);
    update(2 * node + 1, (l + r)/2 + 1, r, idx, value);
    segment[node] = max(segment[2 * node], segment[2 * node + 1]);
}

vector< pair< int , int > > qu[10001];
int ret[500001];
int have[100000001];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1 ; i <= n ;  ++i){
        scanf("%d", arr + i);
    }
    for(int i = 1 ; i <= q ; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        qu[r].push_back({l, i});
    }

    for(int i = 1 ; i <= n ; ++i){
        int x = arr[i];
        for(int j = 1 ; j * j <= x;  ++j){
            if(x % j == 0){
                if(have[j]) update(1, 1, n, have[j], j);
                have[j] = i;
                if(j != (x/j)){
                    if(have[x/j]) update(1, 1, n, have[x/j], x/j);
                    have[x/j] = i;
                }
            }
        }
        for(int j = 0 ; j < qu[i].size();  ++j)
            ret[qu[i][j].second] = query(1, 1, n, qu[i][j].first, i);
    }
    for(int i = 1 ; i <= q ; ++i)
        printf("%d\n", ret[i]);

    return 0;
}
