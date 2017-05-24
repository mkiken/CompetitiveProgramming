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
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

/**
 * O(|E||V|)
 */
class BellmanFord{
  const static int MAX_VERTEX = 10000;
  const static int MAX_EDGE = 10000;

protected:
  int V, E;
  int from[MAX_EDGE], to[MAX_EDGE];
  ll cost[MAX_EDGE];
  bool isNegativeLoop = false;

public:
  BellmanFord(int v, int e){
    assert(v <= MAX_VERTEX);
    assert(e <= MAX_EDGE);
    V = v;
    E = 0;
  }

  void addEdge(int f, int t, ll c){
    from[E] = f;
    to[E] = t;
    cost[E] = c;
    E++;
  }

  /**
   * 負の閉路がない場合: 各頂点への最短経路
   * 負の閉路がある場合: 空のvector
   */
  vector<ll> shortestPath(int start){
    vector<ll> result(V, INF);
    result[start] = 0;
    int count = 0;

    while (true){
      bool isUpdate = false;
      for (int i = 0; i < E; i++){
        if (result[from[i]] != INF && (result[to[i]] > result[from[i]] + cost[i])){
          result[to[i]] = result[from[i]] + cost[i];
          isUpdate = true;
        }
      }
      if (!isUpdate){
        break;
      }
      count++;
      if (count == V){
        // 負の閉路がある
        isNegativeLoop = true;
        break;
      }
    }
    return result;
  }

  /* 負閉路があるかどうか */
  bool hasNegativeLoop(){
    return isNegativeLoop;
  }

  /**
   * shortestPathの結果を使って負閉路を出す
   */
  vector<bool> findNegativeLoop(vector<ll> result){
    vector<bool> negative(V, false);
    for (int j = 0; j < V; j++){
      for (int i = 0; i < E; i++){
        if (result[from[i]] != INF && (result[to[i]] > result[from[i]] + cost[i])){
          result[to[i]] = result[from[i]] + cost[i];
          negative[to[i]] = true;
        }

        if (negative[from[i]]){
          negative[to[i]] = true;
        }
      }
    }

    return negative;
  }

};

void case4(){
  BellmanFord bf = BellmanFord(4, 4);
  bf.addEdge(0, 3, -1000000000);
  bf.addEdge(0, 1, -1);
  bf.addEdge(1, 2, -1);
  bf.addEdge(2, 1, -1);
  vector<ll> result = bf.shortestPath(0);

  for (int i = 0; i < result.size(); i++){
    printf("%d: %lld\n", i, result[i]);
  }

  vector<bool> negative = bf.findNegativeLoop(result);
  for (int i = 0; i < result.size(); i++){
    printf("negative %d: %d\n", i, (int)negative[i]);
  }
}

void case3(){
  BellmanFord bf = BellmanFord(6, 5);
  bf.addEdge(0, 1, 1000000000);
  bf.addEdge(1, 2, 1000000000);
  bf.addEdge(2, 3, 1000000000);
  bf.addEdge(3, 4, 1000000000);
  bf.addEdge(4, 5, 1000000000);
  vector<ll> result = bf.shortestPath(0);

  for (int i = 0; i < result.size(); i++){
    printf("%d: %lld\n", i, result[i]);
  }

  vector<bool> negative = bf.findNegativeLoop(result);
  for (int i = 0; i < result.size(); i++){
    printf("negative %d: %d\n", i, (int)negative[i]);
  }
}

void case2(){
  BellmanFord bf = BellmanFord(2, 2);
  bf.addEdge(0, 1, -1);
  bf.addEdge(1, 0, -1);
  vector<ll> result = bf.shortestPath(0);

  for (int i = 0; i < result.size(); i++){
    printf("%d: %lld\n", i, result[i]);
  }

  vector<bool> negative = bf.findNegativeLoop(result);
  for (int i = 0; i < result.size(); i++){
    printf("negative %d: %d\n", i, (int)negative[i]);
  }
}

void case1(){
  BellmanFord bf = BellmanFord(3, 3);
  bf.addEdge(0, 1, -4);
  bf.addEdge(1, 2, -3);
  bf.addEdge(0, 3, -5);
  vector<ll> result = bf.shortestPath(0);

  for (int i = 0; i < result.size(); i++){
    printf("%d: %lld\n", i, result[i]);
  }

  vector<bool> negative = bf.findNegativeLoop(result);
  for (int i = 0; i < result.size(); i++){
    printf("negative %d: %d\n", i, (int)negative[i]);
  }
}

void exec(){
  cout << "------------------------------" << endl;
  case1();
  cout << "------------------------------" << endl;
  case2();
  cout << "------------------------------" << endl;
  case3();
  cout << "------------------------------" << endl;
  case4();
  cout << "------------------------------" << endl;
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
