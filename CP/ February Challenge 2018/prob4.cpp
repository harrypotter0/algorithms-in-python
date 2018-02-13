/*
 *
 ********************************************************************************************
 * AUTHOR : harrypotter0                                                                    *
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

int main() {
	// your code goes here
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    long double c,d,s;
	    cin>>n;
	    long double arr[n],sum=0;
	    for(i=0;i<n;i++){cin>>arr[i];sum+=arr[i];}
	    cin>>c>>d>>s;
	    long double t1=sum,t2=0;
	    long double wait[n];
	    wait[0]=arr[0];
	    long double totwait=0,zero=0,curr=0;
	    totwait+=wait[0];
	    for(i=1;i<n;i++)
	    {
	        wait[i]=arr[i]-arr[i-1]+ (wait[i-1]<0?wait[i-1]:0);
	        totwait+=max(wait[i],zero);
	    }
	    cout<<fixed<<setprecision(10)<<(c-1)*totwait<<endl;
	}

	return 0;
}
