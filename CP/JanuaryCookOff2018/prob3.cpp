#include <bits/stdc++.h>
using namespace std;
int A[100009];
int D1[100009];
int D2[100009];
bool ok(int i)
{
	if (i % 2 == 1)
		return A[i] < A[i + 1];
	else
		return A[i] > A[i + 1];
}
int N;
int ans()
{
	int i = (N + 1) / 2;
	int j = (N + 2) / 2;
	int id = 0;
	D1[id] = N + 2;
	D2[id] = N + 2;
	if (i == j)
	{
		D1[id] = 0;
		D2[id] = 0;
	}
	else
	{
		if (ok(i))
			D1[id] = 0;
		swap(A[i], A[j]);
		if (ok(i))
			D2[id] = 1;
		swap(A[i], A[j]);
	}
	while (true)
	{
		i--;
		j++;
		if (i < 1)
			break;
		id++;
		D1[id] = N + 2;
		D2[id] = N + 2;
		{
			if (ok(i) && ok(j - 1))
				D1[id] = min(D1[id], D1[id - 1]);
			swap(A[i + 1], A[j - 1]);
			if (ok(i) && ok(j - 1))
				D1[id] = min(D1[id], D2[id - 1]);
			swap(A[i + 1], A[j - 1]);
		}
		swap(A[i], A[j]);
		{
			if (ok(i) && ok(j - 1))
				D2[id] = min(D2[id], 1 + D1[id - 1]);
			swap(A[i + 1], A[j - 1]);
			if (ok(i) && ok(j - 1))
				D2[id] = min(D2[id], 1 + D2[id - 1]);
			swap(A[i + 1], A[j - 1]);
		}
		swap(A[i], A[j]);
	}
	return min(D1[id], D2[id]);
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		int out = N + 2;
		out = min(out, ans());
		for (int i = 1; i <= N; i++)
			A[i] *= -1;
		out = min(out, ans());
		if (out > N)
			out = -1;
		cout << out << '\n';
	}
}
