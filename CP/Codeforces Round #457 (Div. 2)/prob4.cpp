#include <bits/stdc++.h>
using namespace std;

typedef long long lint; typedef pair<int, int> ii;
const int MOD = 1'000'000'007, MOD2 = 1'000'000'009;
const int INF = 0x3f3f3f3f; const lint BINF = 0x3f3f3f3f3f3f3f3fLL;

struct StringTrie{

	StringTrie *chi[26];
	int dat;

	StringTrie(){
		for(int i=0;i<26;i++) chi[i] = nullptr;
		dat = -1;
	}

	StringTrie(StringTrie *old){
		for(int i=0;i<26;i++) chi[i] = old->chi[i];
		dat = old->dat;
	}

	StringTrie *set(string &s, int val, int pos = 0){
		StringTrie *rt = new StringTrie(this);
		if(pos >= s.size()){
      //printf("choot1\n", );
			rt->dat = val;
		}else{
      //printf("choot2\n", );
			int v = s[pos] - 'a';
			if(!chi[v]) chi[v] = new StringTrie();
			rt->chi[v] = chi[v]->set(s, val, pos + 1);
		}
		return rt;
	}

	int get(string &s, int pos = 0){
		if(pos >= s.size()){
			return dat;
		}else{
			int v = s[pos] - 'a';
			if(!chi[v]) return -1;
			return chi[v]->get(s, pos + 1);
		}
	}

};

struct BinaryTrie{

	BinaryTrie *chi[2];
	int dat;

	BinaryTrie(){
		chi[0] = chi[1] = nullptr;
		dat = 0;
	}

	BinaryTrie(BinaryTrie *old){
		chi[0] = old->chi[0];
		chi[1] = old->chi[1];
		dat = old->dat;
	}

	BinaryTrie *add(int s, int val, int pos = 30){
		BinaryTrie *rt = new BinaryTrie(this);
		rt->dat += val;
		if(pos >= 0){
			int v = (s >> pos) & 1;
			if(!chi[v]) chi[v] = new BinaryTrie();
			rt->chi[v] = chi[v]->add(s, val, pos - 1);
		}
		return rt;
	}

	int get(int s, int pos = 30){
		if(pos < 0){
			return 0;
		}else{
			int v = (s >> pos) & 1;
			if(v){
				int ans = 0;
				// add 0
				if(chi[0]) ans += chi[0]->dat;
				// query 1
				if(chi[1]) ans += chi[1]->get(s, pos - 1);
				return ans;
			}else{
				// query 0
				if(chi[0])
					return chi[0]->get(s, pos - 1);
				else
					return 0;
			}
		}
	}

};

int solve(){
	int q; cin >> q;
	StringTrie **st = new StringTrie*[q + 5];
	BinaryTrie **bt = new BinaryTrie*[q + 5];
	st[0] = new StringTrie();
	bt[0] = new BinaryTrie();
	for(int i=1;i<=q;i++){
		string op; cin >> op;
		if(op == "set"){
			string str; int val;
			cin >> str >> val;
			int x = st[i-1]->get(str);
			st[i] = st[i-1]->set(str, val);
			if(x >= 0){
				bt[i] = bt[i-1]->add(x, -1);
				bt[i] = bt[i]->add(val, 1);
			}else{
				bt[i] = bt[i-1]->add(val, 1);
			}
		}else if(op == "remove"){
			string str; cin >> str;
			int x = st[i-1]->get(str);
			st[i] = st[i-1]->set(str, -1);
			if(x >= 0)
				bt[i] = bt[i-1]->add(x, -1);
			else
				bt[i] = bt[i-1];
		}else if(op == "undo"){
			int x; cin >> x;
			st[i] = st[i - x - 1];
			bt[i] = bt[i - x - 1];
		}else{
			st[i] = st[i - 1];
			bt[i] = bt[i - 1];
			string str; cin >> str;
			int x = st[i]->get(str);
			if(x >= 0)
				cout << bt[i]->get(x) << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	// int t; cin >> t; while(t--)
	solve();
	// cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}
