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
	    string s;
	    cin>>s;
	    int n=s.length();
	    vector<int> ind[26];
	    int freq[26]={0};
	    int i;
	    for(i=0;i<n;i++)
	    {
	        freq[s[i]-'a']++;
	        ind[s[i]-'a'].push_back(i);
	    }
	    int odd=0;
	    for(i=0;i<26;i++)
	        if(freq[i]&1)
	            odd++;
  	   if(odd>1)
  	   {
  	       cout<<-1<<endl;
  	       continue;
  	   }
	    int ans[n];
	    for(i=0;i<n;i++)ans[i]=-1;
	    int index=0;
	    for(i=0;i<26;i++)
	    {
	        int j=0;
	        if(freq[i]&1)continue;
	        for(j=0;j<freq[i]/2;j++)
	        {
	           ans[index++]=ind[i][j];
	           ans[n-index]=ind[i][freq[i]-1-j];
	        }
	    }
	    char ch;
	    for(i=0;i<26;i++)
	        if(freq[i]&1)
	        {
	            ch='a'+i;
	            break;
	        }
	    int k=0;
	    for(i=0;i<n;i++)
	        if(ans[i]==-1)ans[i]=ind[ch-'a'][k++];

	    for(i=0;i<n;i++)cout<<ans[i]+1<<" ";cout<<endl;
	}

	return 0;
}
