#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a,b,x,y,i,j;
string s="tttt",s1,s2;

main(){
	
	cin>>n>>m>>s1;
	
	while(i<n-1){
		cin>>s2;
		
		while(j<m-1){
			s[0]=s1[j];s[1]=s1[j+1];s[2]=s2[j];s[3]=s2[j+1];sort(s.begin(),s.end());if(s=="acef"){x++;}s="tttt";
			j++;
		}i++;j=0;s1=s2;
	}
	cout<<x;
}