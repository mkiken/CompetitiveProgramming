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

class CombinationMod {
 private:
  vector<vector<ll>> combi;
  int maxN;
  int maxK;
  int mod;

 public:
  CombinationMod(int n, int k, int m) {
    maxN = n;
    maxK = k;
    mod = m;
    combi = vector<vector<ll>>(maxN + 1, vector<ll>(maxK + 1, 0));

    for (int i = 0; i < maxN + 1; i++) {
      combi[i][0] = 1;
    }

    for (int i = 1; i < maxK + 1; i++) {
      combi[0][i] = 0;
    }

    for (int i = 1; i < maxN + 1; i++) {
      for (int j = 1; j < min(maxK, i + 1); j++) {
        combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % mod;
      }
    }
  }

  ll get(int n, int k) { return combi[n][k]; }
};

int main() {
  CombinationMod cm = CombinationMod(100, 100, (int)1e9 + 7);
  printf("%lld\n", cm.get(5, 2));
  return 0;
}
