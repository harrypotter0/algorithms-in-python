#include <bits/stdc++.h>

using namespace std;

long long a,b,c,d,k;

int main()
{
	cin>>a>>b>>c>>d>>k,a=max(a,c),b=min(b,d);
	cout<<max(b-a+(k>b||k<a),0LL)<<endl;
}