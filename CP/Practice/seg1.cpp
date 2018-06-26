#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

const int MAX   = 1e6 + 6;
const int MAX2  = 1e5 + 5;
const int LIM   = 3e5 + 5;   //equals 2 * 2^ceil(log2(n))
const int MOD   = 1e9 + 7;
const LD  EPS   = 1e-10;
const double PI = acos(-1.0);

#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inchar          getchar_unlocked
#define outchar(x)      putchar_unlocked(x)

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

double tick(){static clock_t oldt;clock_t newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt = newt;return diff;}
template<typename T> void inPos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outPos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar(' ');}

//Segment tree operations: Point update and Range Query

int a[MAX2]; //input array
int lp[MAX]; // preprocess 1
int seg[LIM][2]; // segment_tree
vector<int> primes; // preprocess 2

//Complexity: O(1)
//Stores what info. segment[i..j] should store
void solve() {
    lp[1] = 1;
    for (int i=2; i<MAX; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<primes.size() && primes[j]<=lp[i]; ++j) {
            int x = i * primes[j];
            if (x >= MAX) break;
            lp[x] = primes[j];
        }
    }
}


//Complexity: O(n)
void build(int t, int i, int j) {
	if (i == j) {
		//base case : leaf node information to be stored here
    seg[t][0] = a[i];
    seg[t][1] = lp[seg[t][0]];
    return ;
		return ;
	}
  int left = t<<1;
  int right = left | 1;
	int mid = (i + j) / 2;
	build(t*2, i, mid);
	build(t*2 + 1, mid + 1, j);
  seg[t][0] = max(seg[left][0], seg[right][0]);
  seg[t][1] = max(seg[left][1], seg[right][1]);

}

//Complexity: O(log n)
void update(int t, int i, int j, int l, int r) {
  if (seg[t][0] == 1) {
      return ;
  }
  if (i > r || j < l) {
      return ;
  }
	if (i == j) {
		//base case : leaf node information to be stored here
		// seg[t] = y;
		// return ;
    seg[t][0] /= seg[t][1];
    seg[t][1] = lp[seg[t][0]];
    return ;
	}
  int left = t<<1;
  int right = left | 1;
  int mid = (i + j) / 2;
	update(t*2, i, mid, l, r);
	update(t*2 + 1, mid + 1, j, l, r);
  seg[t][0] = max(seg[left][0], seg[right][0]);
  seg[t][1] = max(seg[left][1], seg[right][1]);

}

//Complexity: O(log n)
int query(int t, int i, int j, int l, int r) {
    if (i > r || j < l) {
        return INT_MIN;
    }
    if(seg[t][1] == 1) {
      return 1;
    }
    if (l <= i && j <= r) {
        // cout<<"["<<seg[t][1]<<"]";
        return seg[t][1];
    }
    int mid = (i+j)/2;
    return max(query(t*2, i, mid, l, r), query(t*2+1, mid+1, j, l, r));
}

int main() {
    solve();
    int t, n, q, type, l, r, ans;
    inPos(t);
    while(t--) {
        inPos(n), inPos(q);
        for(int i=1; i<=n; ++i) {
            inPos(a[i]);
        }
        build(1, 1, n);
        while(q--) {
            inPos(type), inPos(l), inPos(r);
            if (type == 0) {
                update(1, 1, n, l, r);
            }
            else {
                ans = query(1, 1, n, l, r);
                outPos(ans);
            }
        }
        outchar('\n');
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
