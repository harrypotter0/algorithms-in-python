// Pishty and Triangles
// just maintain first 46 largest numbers
// problem is just to find consequtive triplet x, y, z such that x + y > z
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int BLOCK = 317;
const int TOT = 317;
int segtree[TOT << 2];
int tmp_segtree[TOT << 3];
int tmp_pt[TOT << 3];
int pt[TOT << 2];
bool done[TOT];
int aval[TOT];
vector <int> t_s;
multiset <int> ms[TOT];
multiset <int> :: iterator it[TOT];
int n , q;
int arr[N];

int getBlock(int idx) {
  return (idx / BLOCK) + !!(idx % BLOCK);
}

void add(int blockid, int val) {
  ms[blockid].insert(val);
}

void remove(int blockid, int val) {
  assert(ms[blockid].find(val) != ms[blockid].end());
  ms[blockid].erase(ms[blockid].find(val));
}

void build(int node, int u, int v) {
  if(u > v) return;
  if(u == v) {
    segtree[node] = aval[u];
    pt[node] = u;
    return;
  }
  int m = (u + v) / 2;
  build(node * 2, u, m);
  build(1 + (node * 2), m + 1, v);
  if(segtree[node * 2] >= segtree[1 + (node * 2)]) {
    segtree[node] = segtree[node * 2];
    pt[node] = pt[node * 2];
  } else {
    segtree[node] = segtree[1 + (node * 2)];
    pt[node] = pt[1 + (node * 2)];
  }
}

void update(int node, int u, int v, int idx, int val) {
  if(u > v | u > idx | v < idx) return;
  if(u >= idx and v <= idx) {
    segtree[node] = val;
    pt[node] = idx;
    return;
  }
  int m = (u + v) / 2;
  update(node * 2, u, m, idx, val);
  update(1 + (node * 2), m + 1, v, idx, val);
  if(segtree[node * 2] >= segtree[1 + (node * 2)]) {
    segtree[node] = segtree[node * 2];
    pt[node] = pt[node * 2];
  } else {
    segtree[node] = segtree[1 + (node * 2)];
    pt[node] = pt[1 + (node * 2)];
  }
}

void build2(int node, int u, int v) {
  if(u > v) return;
  if(u == v) {
    tmp_segtree[node] = t_s.size() > u ? t_s[u] : 0;
    tmp_pt[node] = u;
    return;
  }
  int m = (u + v) / 2;
  build2(node * 2, u, m);
  build2(1 + (node * 2), m + 1, v);
  if(tmp_segtree[node * 2] >= tmp_segtree[1 + (node * 2)]) {
    tmp_segtree[node] = tmp_segtree[node * 2];
    tmp_pt[node] = tmp_pt[node * 2];
  } else {
    tmp_segtree[node] = tmp_segtree[1 + (node * 2)];
    tmp_pt[node] = tmp_pt[1 + (node * 2)];
  }
}

void update2(int node, int u, int v, int idx, int val) {
  if(u > v | u > idx | v < idx) return;
  if(u >= idx and v <= idx) {
    tmp_segtree[node] = val;
    tmp_pt[node] = idx;
    return;
  }
  int m = (u + v) / 2;
  update2(node * 2, u, m, idx, val);
  update2(1 + (node * 2), m + 1, v, idx, val);
  if(tmp_segtree[node * 2] >= tmp_segtree[1 + (node * 2)]) {
    tmp_segtree[node] = tmp_segtree[node * 2];
    tmp_pt[node] = tmp_pt[node * 2];
  } else {
    tmp_segtree[node] = tmp_segtree[1 + (node * 2)];
    tmp_pt[node] = tmp_pt[1 + (node * 2)];
  }
}

long long query(int l, int r) {

  int bl = getBlock(l);
  int br = getBlock(r);

  for(int i = 0; i < TOT; ++i) aval[i] = 0, done[i] = false;

  if(bl == br) {
    for(int i = l; i <= r; ++i) {
      aval[i - l + 1] =  arr[i];
    }
    build(1, 1, TOT);
    vector <int> v(46, 0);
    for(int i = 45; i >= 0; --i) {
      if(segtree[1] == 0) break;
      v[i] = segtree[1];
      if(i + 2 <= 45) {
        long long cur1 = v[i] + v[i + 1];
        if(cur1 > v[i + 2]) {
          cur1 += v[i + 2];
          return cur1;
        }
      }
      update(1, 1, TOT, pt[1], 0);
    }
    return 0;
  }
  t_s.clear();
  t_s.push_back(0);
  for(int i = l; i <= bl * BLOCK; ++i) {
    t_s.push_back(arr[i]);
  }
  for(int i = 1 + ((br - 1) * BLOCK); i <= r; ++i) {
    t_s.push_back(arr[i]);
  }
  build2(1, 1, 2 * BLOCK);
  if(t_s.size() > 1) {
    aval[bl] = tmp_segtree[1];
    update2(1, 1, 2 * BLOCK, tmp_pt[1], 0);
  }
  for(int i = bl + 1; i <= br - 1; ++i) {
    it[i] = ms[i].end();
    if(ms[i].size()) {
      --it[i];
      aval[i] = *it[i];
      if(it[i] == ms[i].begin()) {
        done[i] = true;
      } else {
        --it[i];
      }
    } else {
      done[i] = true;
    }
  }
  build(1, 1, TOT);
  vector < int > v(46, 0);
  for(int i = 45; i >= 0; --i) {
    //printf("First : %d\n", segtree[1]);
    if(segtree[1] == 0) break;
    v[i] = segtree[1];
    if(i + 2 <= 45) {
      long long cur1 = v[i] + v[i + 1];
      if(cur1 > v[i + 2]) {
        cur1 += v[i + 2];
        return cur1;
      }
    }
    int from = pt[1];
    update(1, 1, TOT, from, 0);
    if(from == bl) {
      if(tmp_segtree[1] > 0) {
        update(1, 1, TOT, from, tmp_segtree[1]);
        update2(1, 1, 2 * BLOCK, tmp_pt[1], 0);
      }
    } else {
      if(!done[from]) {
        update(1, 1, TOT, from, *it[from]);
        if(it[from] == ms[from].begin()) {
          done[from] = true;
        } else {
          --it[from];
        }
      }
    }
  }
  return 0;
}

int main() {
  //freopen("test.txt", "r", stdin);
  //freopen("test_out.txt", "w", stdout);
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for(int i = 1; i <= n; ++i) {
    add(getBlock(i), arr[i]);
  }
  while(q--) {
    int typ;
    scanf("%d", &typ);
    if(typ == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      remove(getBlock(x), arr[x]);
      arr[x] = y;
      add(getBlock(x), arr[x]);
    } else {
      int l , r;
      scanf("%d %d", &l, &r);
      if(r - l + 1 < 3) {
        printf("0\n");
      } else {
        printf("%lld\n", query(l, r));
      }
    }
  }
  return 0;
} 
