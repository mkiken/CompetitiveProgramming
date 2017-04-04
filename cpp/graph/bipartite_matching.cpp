#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

// const int INF = (int)2e9;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;

#define MAX_N 100 + 2

class BipartiteMatching{
private:
  int V;
  vector<VI> G;
  VI match;
  vector<bool> used;

  bool dfs(int v){
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++){
      int u = G[v][i], w = match[u];
      if(w < 0 || (!used[w] && dfs(w))){
        match[u] = v;
        match[v] = u;
        return true;
      }
    }
    return false;
  }
public:
  BipartiteMatching(int v){
    V = v;
    G = vector<VI>(v + 1);
    match = VI(v + 1, -1);
    used = vector<bool>(v + 1, -1);
  }

  void initializeEdge(){
    for (int i = 0; i < V + 1; i++){
      G[i].clear();
    }
  }

  void addEdge(int v, int u){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int bipartiteMatching(){
    int res = 0;
    fill(match.begin(), match.end(), -1);
    for (int v = 0; v < V; v++){
      if(match[v] < 0){
        fill(used.begin(), used.end(), -1);
        if(dfs(v)) res++;
      }
    }
    return res;
  }
};

void test(){
  BipartiteMatching bp = BipartiteMatching(5);
  bp.initializeEdge();
  bp.addEdge(1, 3);
  bp.addEdge(1, 4);
  bp.addEdge(2, 4);
  cout << bp.bipartiteMatching() << endl;

}

int main(){
  test();
  return 0;
}
