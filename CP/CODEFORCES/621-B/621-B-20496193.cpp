#include <bits/stdc++.h>

using namespace std;

int n, y, c, x;
map <int, int> xy, xyy;


int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> x >> y;
		c+=xy[x+y]++;
		c+=xyy[x-y]++;	
	}
	cout << c;
}