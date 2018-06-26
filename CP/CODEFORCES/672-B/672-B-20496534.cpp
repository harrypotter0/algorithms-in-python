#include <bits\stdc++.h>
using namespace std;
main()
{
    int n; string s;  
    cin >> n >> s;
    cout << ((n > 26) ? -1 : n - (int)set<char>(s.begin(), s.end()).size());
}