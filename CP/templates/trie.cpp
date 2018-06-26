#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
typedef vector<string> vs;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define SIZE 26

struct Node{
  bool isEnd;
  Node *childs[SIZE];
}*Root;

Node* GetNode(){
  Node* node=new Node;
  node->isEnd=false;
  rep(i,SIZE)
    node->childs[i]=NULL;
  return node;
};

void Init(){
  Root=GetNode();
}

bool Insert( string str){
  Node *node=Root;
  bool flag=false;
  rep(i,str.size()) {
    if(!(node->childs[str[i]-'a'])){
      flag=true;
      node->childs[str[i]-'a']=GetNode();
    }
    node=node->childs[str[i]-'a'];
    if(!flag && node->isEnd)//reached on a leaf node without creating any new node
      return false;

  }
  node->isEnd=true;
  if(!flag)//did not create any new node
    return false;
  return true;
}

void Free(Node* node){
  if(!node)
    return;
  rep(i,SIZE)
    if(!node->childs[i])
      Free(node->childs[i]);
  free(node);
}
int main(){
  csl;
  int t;
  string str;
  bool myflag;
  myflag=true;
  Free(Root);
  Init();
  cin>>t;
  while(t-->0){
    cin>>str;
    myflag = myflag && Insert(str);
  }
  if(myflag)
    cout<<"non vulnerable"<<endl;
  else
    cout<<"vulnerable"<<endl;
  return 0;
}
