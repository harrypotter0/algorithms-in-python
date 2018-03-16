// Akash Kandpal
// harrypotter0
// King is set for the hunt
// Best is the enemy of Good

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef priority_queue< pii , vector< pii > , greater< pii > > pq;
const ll N=2e5+10;

ll a[N];
vector<ll> v[4*N];

vector<ll> lol;

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0 || b == 0)
       return 0;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void construct_tree(ll low,ll high,ll pos){
	if(low==high){
		v[pos].pb(a[low]);
		return ;
	}
	ll mid=(low+high)/2;
	construct_tree(low,mid,2*pos+1);
	construct_tree(mid+1,high,2*pos+2);

// edited
	ll cnt=0,i=0,j=0,left=2*pos+1,right=left+1,lsz=v[left].size(),rsz=v[right].size();

	while(i<lsz && j<rsz){
		if(cnt>=50)
			break;

		cnt++;
		if(v[left][i] > v[right][j]){
			v[pos].pb(v[left][i]);
			i++;
		}
		else{
			v[pos].pb(v[right][j]);
			j++;
		}
	}

	while(i<lsz){
		if(cnt>=50)
			break;
		cnt++;
		v[pos].pb(v[left][i]);
		i++;
	}

	while(j<rsz){
		if(cnt>=50)
			break;
		cnt++;
		v[pos].pb(v[right][j]);
		j++;
	}

}



void update(ll low,ll high,ll pos,ll qlow,ll qhigh,ll val){
	if(high<qlow || low>qhigh)
		return ;

	if(low>=qlow && high<=qhigh){
		//while(!v[pos].empty())
			v[pos].clear();
  		v[pos].pb(val);
		return ;
	}

	ll mid=(low+high)/2;
	update(low,mid,2*pos+1,qlow,qhigh,val);
	update(mid+1,high,2*pos+2,qlow,qhigh,val);
// edited
	ll cnt=0,i=0,j=0,left=2*pos+1,right=left+1,lsz=v[left].size(),rsz=v[right].size();

	// while(!v[pos].empty())
	// 	v[pos].pop_back();
	v[pos].clear();

	while(i<lsz && j<rsz){
		if(cnt>=50)
			break;

		cnt++;
		if(v[left][i] > v[right][j]){
			v[pos].pb(v[left][i]);
			i++;
		}
		else{
			v[pos].pb(v[right][j]);
			j++;
		}
	}

	while(i<lsz){
		if(cnt>=50)
			break;
		cnt++;
		v[pos].pb(v[left][i]);
		i++;
	}

	while(j<rsz){
		if(cnt>=50)
			break;
		cnt++;
		v[pos].pb(v[right][j]);
		j++;
	}
}


vector<ll> query(ll low,ll high,ll pos,ll qlow,ll qhigh){

	if(high<qlow || low>qhigh){
		return lol;
	}

	if(low>=qlow && high<=qhigh){
		return v[pos];
	}

	ll mid=(low+high)/2;
	vector<ll> tmp1,tmp2,ans;

	tmp1=query(low,mid,2*pos+1,qlow,qhigh);
	tmp2=query(mid+1,high,2*pos+2,qlow,qhigh);

// Edited part
	ll cnt=0,i=0,j=0,lsz=tmp1.size(),rsz=tmp2.size();

	while(i<lsz && j<rsz){
		if(cnt>=50)
			break;

		cnt++;
		if(tmp1[i] > tmp2[j]){
			ans.pb(tmp1[i]);
			i++;
		}
		else{
			ans.pb(tmp2[j]);
			j++;
		}
	}

	while(i<lsz){
		if(cnt>=50)
			break;
		cnt++;
		ans.pb(tmp1[i]);
		i++;
	}

	while(j<rsz){
		if(cnt>=50)
			break;
		cnt++;
		ans.pb(tmp2[j]);
		j++;
	}
	return ans;
  //edited
}

int main(){
	boost;
	ll n,q,i;
	cin>>n>>q;
	for(i=0;i<=n-1;i++)
		cin>>a[i];

	construct_tree(0,n-1,0);

	while(q--){
		ll type;
		cin>>type;
		if(type==1){
			ll pos,val;
			cin>>pos>>val;
			pos--;
      // ll low,ll high,ll pos,ll qlow,ll qhigh,ll val
			update(0,n-1,0,pos,pos,val);
			a[pos]=val;
		}
		else{
			ll l,r;
			cin>>l>>r;
			l--;
			r--;
			vector<ll> ans=query(0,n-1,0,l,r);
			ll res=0;
			assert(ans.size()<=50);
			ll sz=ans.size();
			for(i=2;i<sz;i++){
				if(ans[i]+ans[i-1] > ans[i-2]){
					res=max(res,ans[i]+ans[i-1]+ans[i-2]);
					break;
				}
			}
			cout<<res<<endl;
		}
	}

	return 0;
}
