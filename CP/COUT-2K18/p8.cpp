#include <iostream>
using namespace std;
int sum =0 ;
int fun(int n, int k)
{
    // cout<<sum;
	if (n == 1)return 1;
	else
	return (fun(n - 1, k) + k - 1) % n + 1;
}
int saveMary(int n, int k){
	if (n<=0 || k<=0)return -1;
	else return fun(n, k);
  }
int main()
{
    int n,t,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<saveMary(n, k)<<endl;
        // cout<<sum;
    }
    return 0;
}
