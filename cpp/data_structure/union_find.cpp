#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

// const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

class UnionFind {
protected:
  const static int MAX = 100000 + 2;
  int par[MAX];
  int rank[MAX];
  int size;

  int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }
public:
  UnionFind(){}
  UnionFind(int n) {
    size = n;
    for (int i = 0; i < n; i++){
      par[i] = i;
      rank[i] = 0;
    }
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else{
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){
    return find(x) == find(y);
  }
};

void exec(){
  int n = 5;
  UnionFind uf = UnionFind(n);
  for (int i = 1; i < n; i++){
    uf.unite(i, i-1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        printf("%dth, [%d, %d] = %d\n", i, j, k, uf.same(j, k));
      }
    }

  }

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
