#include <bits/stdc++.h>
using namespace std;

void findPair(int arr[], int n)
{
	unordered_set<float> s;
	for (int i = 0; i < n; i++)
		s.insert((float)arr[i]);
    int count = 0;
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			float x = ((float)arr[i] + (float)arr[j])/2.0;
			if (s.find(x) != s.end()) {
				// cout << arr[i] << " " << arr[j] << endl;
				count++;
			}
		}
	}
	cout<<count<<"\n";

}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[100005];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	findPair(arr, n);
	}
	return 0;
}
