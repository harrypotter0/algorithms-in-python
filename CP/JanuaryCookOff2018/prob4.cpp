#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int A[N][N];
vector<int> adj[N];
bool visited[N];
int ans[N][N];
bool myParity[N];

int p[N], sz[N];

int par(int x){
	if(p[x] != x)	p[x] = par(p[x]);
	return p[x];
}

void join(int a, int b){
	int p1 = par(a), p2 = par(b);
	if(p1 == p2)	return ;
	if(sz[p2] > sz[p1])	swap(p1, p2);
	sz[p1] += sz[p2];
	p[p2] = p1;
}

bool BipartiteCheck(int u, int parity) {
	visited[u] = 1;
	myParity[u] = parity;
	for(auto v : adj[u]) {
		if(A[u][v] == 1)	continue;
		if(visited[v] == 1 and myParity[v] == myParity[u])	return 0;
	}
	for(auto v : adj[u]){
		if(visited[v] == 1 or A[u][v] == 1)	continue;
		if(BipartiteCheck(v, parity^1) == 0)	return 0;
	}
	return 1;
}

void dfs_assign(int u, int val, int col_number) {
	visited[u] = 1;
	ans[u][col_number] = val;
	for(auto v : adj[u]) {
		if(visited[v])	continue;
		dfs_assign(v, val * A[u][v], col_number);
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	//assert(n >= 1 and n <= 1000);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			assert(A[i][j] >= -1 and A[i][j] <= 1);
		}
	}

	for(int i = 1; i <= n; i++) {
		p[i] = i, sz[i] = 1;
		visited[i] = 0;
		adj[i].clear();
    for(int j = 1; j <= n; j++) ans[i][j] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(A[i][j] != A[j][i]) {
				cout<<-1<<endl;
				//cout<<"non symmetric"<<endl;
				return ;
			}
		}
	}

	// ^ensured matrix is symmetric.

	for(int i = 1; i <= n; i++) {
		if(A[i][i] == -1) {
			cout<<-1<<endl;
			//cout<<"diagonal fucked"<<endl;
			return ;
		}
	}

	// ^ensured none of the diagonal entries is -1.

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(A[i][j] != 0) {
				if(A[i][i] == 0 or A[j][j] == 0) {
					cout<<-1<<endl;
					//cout<<"involve zero row"<<endl;
					return ;
				}
				join(i, j);
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	// ^joined the rows, which have non - zero entries in dsu
	// and added edges between those rows which have opposite parities.
	// also verified that no pure zero row is involved.

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(A[i][j] == 0 and par(i) == par(j)) {
				cout<<-1<<endl;
				//cout<<"non - transitive"<<endl;
				return ;
			}
		}
	}

  //cout<<"BC"<<endl;

	// ^ensured that all the pair of rows which are not connected are not indirectly in the same dsu.

	for(int i = 1; i <= n; i++) {
		if(visited[i])	continue;
		if(!BipartiteCheck(i, 0)) {
			cout<<-1<<endl;
			//cout<<"non - bipartite"<<endl;
			return ;
		}
	}

	// ^ensured there are no parity issues and that all the graphs are bipartite in nature.

	for(int i = 1; i <= n; i++) {
		visited[i] = (A[i][i] == 0);
	}

	int colNumber = 1;

	for(int i = 1; i <= n; i++) {
		if(visited[i])	continue;
		dfs_assign(i, -1, colNumber++);
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
