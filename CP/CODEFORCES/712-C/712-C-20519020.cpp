#include <iostream>
using namespace std;
int x,y;
int ctr=0;
void cnt(int a, int b, int c){
	if(c==x) return;
	++ctr;
	c=min(x, a-1+b);
	cnt(c,a,b);
}

int main() {
	cin>>x>>y;
	cnt(y,y,y);
	cout<<ctr;
}