#include <iostream>
using namespace std;
int main(){
	int n,d;
	cin >> n >> d;
	for(int i = 1; i < n; ++i){
		int a;
		cin >> a;
		if(i != (a+d*(i&1?1:-1)+n)%n){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}