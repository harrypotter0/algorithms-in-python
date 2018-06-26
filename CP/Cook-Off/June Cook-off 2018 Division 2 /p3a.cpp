#include <bits/stdc++.h>
    
#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
vii v;
vi vv;
ll bit[2][400005];
unordered_map<int,int> pos;
pair<ll,int> query(int index){
    ll sum1=0;
    int sum2=0;
    index++;
    while(index>0){
        sum1+=bit[0][index];
        sum2+=bit[1][index];
        index-=index&(-index);
    }
    return {sum1,sum2};
}
void update(int index, int val){
    index++;
    while(index<=n){
        bit[0][index]+=val;
        bit[1][index]++;
        index+=index&(-index);
    }
}
    
void solve(){
    v.clear();
    vv.clear();
    pos.clear();
    int ans=0;
    cin>>n;
    rep(i,0,n){
        bit[0][i]=0;
        bit[1][i]=0;
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
        vv.pb(b);
    }
    bit[0][n]=0;
    bit[1][n]=0;
    sort(all(vv));
    rep(i,0,n){
        pos[vv[i]]=i;
    }
    sort(all(v));
    reverse(all(v));
    rep(i,0,n){
        int lo=0,hi=n;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            pair<ll,int> d=query(mid);
            if(1LL*v[i].x*(d.y+1)>=(d.x+v[i].y)){
                lo=mid;
                ans=max(ans,d.y+1);
            }
            else{
                hi=mid;
            }
        }
        update(pos[v[i].y],v[i].y);
    }
    cout<<ans<<endl;
}
    
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 