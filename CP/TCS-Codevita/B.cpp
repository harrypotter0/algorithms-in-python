#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define mp make_pair
#define f first
#define sc second
#define faster_io() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int m, n, r, c;
char forest[25][25];
char water = 'W', tree = 'T';
bool burnt[25][25];
int ans;
queue<pair<int, int > > trees;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
void set_vis() {
	for (int i = 0 ; i < 25; i++) {
		for (int j = 0 ; j < 25 ; j++) {
			burnt[i][j] = false;
		}
	}
}
int main() {
	set_vis();
	int r_, c_, tot_trees = 0;
	// faster_io();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> m >> n;
	cin >> r >> c;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> forest[i][j];
			if (forest[i][j] == tree) {
				tot_trees += 1;
			}
		}
	}
	// add inital tree location in min priority queue
	int n_t = 0;
	burnt[r][c] = true;
	for (int i = 0 ; i < 8 ; i++) {
		r_ = r + dr[i];
		c_ = c + dc[i];
		if (r_ < 1 || r_ > m || c_ < 1 || c_ > n ) {
			continue;
		} else {
			if (forest[r_][c_] == tree &&  burnt[r_][c_]==false) {
				trees.push(mp(r_, c_));
				n_t += 1;
				burnt[r_][c_]=true;
			}
		}
	}
	ans += 1;
	int x, y, t_n_t = 0;
	int t_tot_tree = 0;
	t_tot_tree += n_t;
	// while (!trees.empty()) {
	// 	cout << trees.front().f << " " << trees.front().sc << "\n";
	// 	trees.pop();
	// }
	while (!trees.empty()) {
		pair<int, int> t;
		t = trees.front();
		x = t.f;
		y = t.sc;
		trees.pop();
		n_t -= 1;
		burnt[x][y] = true;
		for (int i = 0 ; i < 8 ; i++) {
			r_ = x + dr[i];
			c_ = y + dc[i];
			if (r_ < 1 || r_ > m || c_ < 1 || c_ > n) {
				continue;
			} else {
				if (forest[r_][c_] == tree && burnt[r_][c_]==false) {
					//cout << r_ << " " << c_ << "\n";
					trees.push(mp(r_, c_));
					t_n_t += 1;
					burnt[r_][c_]=true;
				}
			}
		}
		if (n_t == 0) {
			n_t = t_n_t;
			t_n_t = 0;
			ans += 1;
			//cout<<"a="<<ans<<"\n";
		}
		//cout<<"a="<<ans<<"\n";
	}
	cout << ans;
		return 0;
}