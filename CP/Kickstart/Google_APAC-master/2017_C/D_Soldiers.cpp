#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream in;
	in.open("../test.in");
	int T;
	in >> T;
	fstream out;
	out.open("../test.out", ios::out);
	for(int j = 1; j <= T; j++){
		int n;
		in >> n;
		vector<int> a(n, 0);
		vector<int> d(n, 0);
		int ai = 0;
		int di = 0;
		for(int i = 0; i < n; i++)
			in >> a[i] >> d[i];
		vector<int>::iterator r;
	    r = max_element(a.begin(), a.end());
	    ai = distance(a.begin(), r);
	    r = max_element(d.begin(), d.end());
	    di = distance(d.begin(), r);
	    bool res = true;
	    while(true){
	    	if(a.size() == 0){
	    		res = false;
	    		break;
	    	}
	    	if(a.size() == 1){
	    		res = true;
	    		break;
	    	}
	    	if(d[di] == d[ai] || a[ai] == a[di]){
	    		res = true;
	    		break;
	    	}
			int amax = a[ai];
	    	int dmax = d[di];
	    	for(vector<int>::iterator it=a.begin(), itd = d.begin(); it!=a.end(); )
		    {
		        if(* it == amax)
		        {
		            it = a.erase(it);
		            itd = d.erase(itd);
		        }
		        else
		        {
		            ++it;
		            ++itd;
		        }
		    }
		    for(vector<int>::iterator it=a.begin(), itd = d.begin(); it!=a.end(); )
		    {
		        if(* itd == dmax)
		        {
		            itd = d.erase(itd);
		            it = a.erase(it);
		        }
		        else
		        {
		            ++it;
		            ++itd;
		        }
		    }
		    r = max_element(a.begin(), a.end());
		    ai = distance(a.begin(), r);
		    r = max_element(d.begin(), d.end());
		    di = distance(d.begin(), r);
	    }
		if(res)
			out << "Case #" << j << ": Yes" << endl;
		else
			out << "Case #" << j << ": No" << endl;
	}
	return 0;
}
