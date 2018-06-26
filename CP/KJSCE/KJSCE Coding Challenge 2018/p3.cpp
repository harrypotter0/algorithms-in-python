// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k,int sum)
{
	if (n < k)
	{
	return -1;
	}

	int max_sum = 0;
	for (int i=0; i<k; i++)
	max_sum += arr[i];
	if(max_sum == sum){
	    cout<<1<<" "<<k<<endl;
	    return 1;
	}

	int window_sum = max_sum;
	for (int i=k; i<n; i++)
	{
	window_sum += arr[i] - arr[i-k];
	if(window_sum == sum){
	    cout<<i-k+2<<" "<<i+1<<endl;
	    return 1;
	}
	}
	return -1;
}

// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[100005] ;
	    for(int i=0;i<n;i++)cin>>arr[i];
        int q;
        cin>>q;
        while(q--){
            int k,y;
            cin>>k>>y;
            int lodu = maxSum(arr,n,k,y);
            if(lodu==-1)cout<<"-1"<<endl;
        }
    }
	return 0;
}
