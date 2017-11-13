#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
#define pb push_back
 
vector<int> primes; // vector to store primes
 
int spf[1000005]; // storing the smallest prime factor for all numbers till 1e6 
 
vi pf[100005]; // storing all the primes for numbers in range [a,b]
               // it will only store the primes and not their frequencies
               // for example for 30 it will be [2,3,5]
               // for 60 also it will be [2,3,5]
               // pf[i] = primes for [i-a]
               // for example a = 20, b = 40, pf[10] = [2,3,5] which is actually primes of 30 but this is done to save numbers as big as 1e18
 
ll a,b;
 
ll solve(ll n){
    ll x = n;
    ll ans = 1;
    priority_queue<ll> pq; // priority queue to store the frequency of primes so as to calculate the number of divisors of the next numbers.
    
    
    // prime factorizing
    for (int i = 0; i < pf[n-a].size() and x != 1; i++){
        int cnt = 0;
        while (x%pf[n-a][i] == 0){
            x /= pf[n-a][i];
            cnt ++;
        }
        pq.push(cnt+1);
        ans *= cnt+1;
    }
    if (x != 1){
        pq.push(2);
        ans *= 2;
    }
    
    ll cur = ans;
 
    // calculating answers
    ans = 0;
    while (!pq.empty()){
        ans += cur;
        ll highest_freq = pq.top(); // the highest frequency amoung the divisors left
        pq.pop();
        cur /= highest_freq;
        cur *= (highest_freq-1);
        if (highest_freq > 2) pq.push(highest_freq-1);
    }
    
    return ans;
}
 
int main() {
	
	ios::sync_with_stdio(false);
	
	cin >> a >> b;
	 
	for (int i = 0; i < 1000005; i++){
	    spf[i] = -1;
	}
 
    // calculating smallest prime factor and list of primes 
    // see the explanation here - https://www.hackerrank.com/topics/sieve-of-eratosthenes-linear-time
	for (int i = 2; i < 1000005; i++){
	    if (spf[i] == -1){
    	    spf[i] = i;
    	    if (i < 1000) primes.pb(i);
    	    for (ll j = ((a-1)-((a-1)%i))+i; j <= b; j += i){
    	        pf[j-a].pb(i);
    	    }
    	    
	    }
	    for (int j = 0; j < primes.size() and primes[j] <= spf[i] and i*primes[j] <= 1000000; j++){
	        spf[primes[j]*i] = primes[j];
	    }
	}
	
    // 	getting the answer
	
    ll total = 0;
    
    for (ll j = a; j <= b; j++){
        total += solve(j);
    }
    cout << total << endl;
}   
