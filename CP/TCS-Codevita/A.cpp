#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define INF 1000000000
#define faster_io() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int n, x, y, reach, ans_steps, ans_poles;
int A_x, A_y;
int B_x, B_y;
int grid[20][20];
bool vis[20][20];
int steps = 0, poles = 0;
char UP = 'U', DOWN = 'D', LEFT = 'L', RIGHT = 'R';
string direct = "UDLR";
void int_t() {
	for (int i = 0 ; i < 20 ; i++) {
		for (int j = 0 ; j < 20 ; j++) {
			vis[i][j] = false;
		}
	}
}
char get_dir(char move, int pole) {
	char dr;
	if (pole == 2) {
		if (move == DOWN) {
			dr = RIGHT;
		}
		else if (move == UP) {
			dr = LEFT;
		}
		else if (move == LEFT) {
			dr = UP;
		}
		else if (move == RIGHT) {
			dr = DOWN;
		}
	}
	else if (pole == 1) {
		if (move == DOWN) {
			dr = LEFT;
		}
		else if (move == UP) {
			dr = RIGHT;
		}
		else if (move == LEFT) {
			dr = DOWN;
		}
		else if (move == RIGHT) {
			dr = UP;
		}
	}
	return dr;
}
void move(char dir) {

	if (dir == UP) {
		x -= 1;
	}
	else if (dir == DOWN) {
		x += 1;
	}
	else if (dir == LEFT) {
		y -= 1;
	}
	else if (dir == RIGHT) {
		y += 1;
	}

	// decided now move
	while (true) {

		if (x < 0 | x >= n || y < 0 || y >= n) {
			//steps -= 1;
			break;
		}
		else {
			//cout << x << " " << y << "\n";
			if (grid[x][y] == -1) {
				reach = 1;
				//cout << "Reached\n";
				steps += 1;
				break;
			}
			else if (grid[x][y] == 0) {
				steps += 1;
				move(dir);
			}
			else if (grid[x][y] == 1) {
				steps += 1;
				poles += 1;
				char d = get_dir(dir, 1);
				//cout << d << "\n";
				move(d);
			}
			else if (grid[x][y] == 2) {
				steps += 1;
				poles += 1;
				char d = get_dir(dir, 2);
				//cout << d << "\n";
				move(d);
			}
		}
		if (reach == 1) {
			break;
		}
	}
}
int main() {
	faster_io();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<pair<int , int> > ans;
	cin >> n;
	cin >> A_x >> A_y;
	cin >> B_x >> B_y;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			cin >> grid[i][j];
		}
	}
	// // disp maze
	// for (int i = 0 ; i < n ; i++) {
	// 	for (int j = 0; j < n ; j++) {
	// 		cout << grid[i][j];
	// 	} cout << endl;
	// }
	if ((A_x == B_x ) && (A_y == B_y)) {
		cout << "0 0\n";
	}
	else {
		grid[A_x][A_y] = -1;
		int hope = 4;
		int_t();
		vis[B_x][B_y] = true;
		for (int i = 0 ; i < 4 ; i++) {
			steps = 0; poles = 0;
			x = B_x; y = B_y;
			reach = 0;
			move(direct[i]);
			if (!reach) {
				hope -= 1;
				//cout << "Can't Reach\n";
			}
			else {
				//cout << steps << " " << poles << "\n";
				ans.pb(mp(steps, poles));
			}
		}
		if (!hope) {
			cout << "-1\n";
		} else {
			sort(ans.begin(), ans.end());
			ans_steps = ans[0].f;
			ans_poles = ans[0].sc;
			for (unsigned int i = 0 ; i < ans.size(); i++) {
				if (ans_steps == ans[i].f) {
					if (ans[i].sc < ans_poles) {
						ans_poles = ans[i].sc;
					}
				}
			}
			cout << ans_steps << " " << ans_poles << "\n";
		}
	}
	ans.clear();
	return 0;
}