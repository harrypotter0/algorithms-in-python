#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define faster_io() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int tot_case;
int prime_number;
int moves[78500];
char direction[78500];
int axis[78500];
int x_axis = 0;
int y_axis = 1;
char UP = 'U', DOWN = 'D', LEFT = 'L', RIGHT = 'R';
string movement = "RULD";
int prime_location[1000000];
pair<int , int >  prime_co_ordinates[78500];
void Gen_Prime_Numbers(int n)
{
	bool pr[n + 1];
	for (int i = 0 ; i < n + 1; i++) {
		pr[i] = true;
	}

	for (int j = 2; j * j <= n; j++)
	{
		if (pr[j] == true)
		{
			for (int i = j * 2; i <= n; i += j) {
				pr[i] = false;
			}
		}
	}

	int cnt = 0;
	for (int j = 2; j <= n; j++)
		if (pr[j]) {
			cnt += 1;
			//cout << j << " " << cnt << "\n";
			prime_location[j] = cnt;
		}

}
void pre_comp() {
	Gen_Prime_Numbers(1000000);
	//set counters
	//int cnt = 1;
	int fill = 1;
	int at = 0;
	int loc = 0;
	int ax = x_axis;
	while (true) {
		for (int j = 1 ; j <= fill * 2 ; j++) {
			at += 1;
			moves[at] = fill;
			direction[at] = movement[loc % 4];
			axis[at] = ax;
			if (j == (1 + (fill * 2)) / 2) {
				loc += 1;
				if (ax == x_axis) {
					ax = y_axis;
				}
				else if (ax == y_axis) {
					ax = x_axis;
				}
			}
			//cout << at << " ";
			//cout << fill << " ";
			//cout << axis[at] << " ";
			//cout << direction[at] << "\n";
			if (at == 78498) {
				fill = -1;
				break;
			}
		}
		if (fill == -1) {
			break;
		}
		fill += 1;
		loc += 1;
		if (ax == x_axis) {
			ax = y_axis;
		}
		else if (ax == y_axis) {
			ax = x_axis;
		}
	}
	prime_co_ordinates[1].f = 0;
	prime_co_ordinates[1].sc = 0;
	int x, y;
	int _x_, _y_;
	int ref;
	int d, a;
	for (int i = 2 ; i <= 78498 ; i++) {
		ref = i - 1;
		x = prime_co_ordinates[ref].f;
		y = prime_co_ordinates[ref].sc;
		a = axis[ref];
		d = direction[ref];
		_x_ = x;
		_y_ = y;
		if (a == x_axis) {
			if (d == RIGHT) {
				_x_ += 1;
			}
			else if (d == LEFT) {
				_x_ -= 1;
			}
		}
		else if (a == y_axis) {
			if (d == UP) {
				_y_ += 1;
			}
			else if (d == DOWN) {
				_y_ -= 1;
			}
		}
		prime_co_ordinates[i].f = _x_;
		prime_co_ordinates[i].sc = _y_;
		//cout << _x_ << " " << _y_ << "\n";
	}

}

int main() {
	// faster_io();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	pre_comp();
	cin >> tot_case;
	while (tot_case--) {
		cin >> prime_number;
		cout << prime_co_ordinates[prime_location[prime_number]].f << " "
		     << prime_co_ordinates[prime_location[prime_number]].sc << "\n";
	}
	return 0;
}