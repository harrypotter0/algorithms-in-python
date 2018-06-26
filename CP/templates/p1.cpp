/*
 *
 ********************************************************************************************
 * AUTHOR : Akash Kandpal                                                                    *
 * Language: C++14                                                                          *
 * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
 * IDE used: Atom                                                                           *
 * My Domain : http://harrypotter.tech/                                                     *
 ********************************************************************************************
 *
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		    '\n'
#define mod         1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define prec(n) fixed<<setprecision(n)
#define mem(dp) memset(dp,-1,sizeof(dp))
const int inf =1e9;
#define MAX  100005

using namespace std;

ll exp(ll a,ll b,ll mod=1e9+7)
{
	ll tem=1;
	while(b)
	{
		if(b%2)
			tem=(tem*a)%mod;
		a=(a*a)%mod;
		b=b/2;
	}
	return tem;
}
ll takemod(ll num)
{
    if(num<0)
	    num+=mod;
    num=num%mod;
    return num;
}
ll fast_power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int dad[100010];
int find(int x){
    if(dad[x]==x) return x;
    return dad[x]=find(dad[x]);
}
void uni(int x,int y){
    int X=find(x),Y=find(y);
    dad[X]=Y;
}

bool isOperand(char c) { return (c >= '0' && c <= '9'); }

// utility function to find value of and operand
int value(char c) {  return (c - '0'); }

// This function evaluates simple expressions. It returns -1 if the
// given expression is invalid.
int evaluate(char *exp)
{
    // Base Case: Given expression is empty
    if (*exp == '\0')  return -1;

    // The first character must be an operand, find its value
    int res = value(exp[0]);

    // Traverse the remaining characters in pairs
    for (int i = 1; exp[i]; i += 2)
    {
        // The next character must be an operator, and
        // next to next an operand
        char opr = exp[i], opd = exp[i+1];

        // If next to next character is not an operand
        if (!isOperand(opd))  return -1;

        // Update result according to the operator
        if (opr == '+')       res += value(opd);
        else if (opr == '-')  res -= value(opd);
        else if (opr == '*')  res *= value(opd);
        else if (opr == '/')  res /= value(opd);

        // If not a valid operator
        else                  return -1;
    }
    return res;
}

int main() {
  // your code goes here
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
    {
      ll n,k;
      cin>>
      // cout << setprecision(3) << dis << "\n";
    }

return 0;
}
