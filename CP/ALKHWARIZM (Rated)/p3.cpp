// A Dynamic Programming based C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;
#define ll          long long

// m is size of coins array (number of different coins)
void minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V+1];
	int table2[V+1];
	// Base case (If given value V is 0)
	table[0] = 0;
	table2[0] = 0;
	// Initialize all table values as Infinite
	for (int i=1; i<=V; i++){
	    table[i] = INT_MAX;
	    table2[i]= -INT_MAX;
	}
	// Compute minimum coins required for all
	// values from 1 to V

	for (int i=1; i<=V; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m; j++)
		{
		    if (coins[j] <= i)
		{
			int sub_res = table[i-coins[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
			if (sub_res != INT_MAX && sub_res + 1 >= table2[i])
				table2[i] = sub_res + 1;
		}
		}
	}
	int mini =table[V];
	int maxi =table2[V];

	if(table[V]==INT_MAX )
	mini = -1;
	if(table2[V]==-INT_MAX )
	maxi = -1;

	cout<<mini<<" "<<maxi<<endl;
}

// Driver program to test above function
int main()
{
	int coins[100021] ;
	int m ;
	int V ;
	cin>>V>>m;
	for(int i=0;i<m;i++){
	    cin>>coins[i];
	}

	minCoins(coins, m, V);
	return 0;
}
