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

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (50 + 2)

typedef vector<VL> matrix;

//行列A * B % m
matrix mulMod(matrix &A, matrix &B, int m){
  matrix C(A.size(), VL(B[0].size()));
  for (int i = 0; i < A.size(); i++){
    for (int k = 0; k < B.size(); k++){
      for (int j = 0; j < B[0].size(); j++){
        C[i][j] = (C[i][j] + (A[i][k] * B[k][j] % m)) % m;
      }
    }
  }
  return C;
}

//A^n
matrix powMod(matrix A, ll n, int m){
  matrix B(A.size(), VL(A.size()));
  for (int i = 0; i < A.size(); i++){
    B[i][i] = 1;
  }
  while(n > 0){
    if(n & 1) B = mulMod(B, A, m);
    A = mulMod(A, A, m);
    n >>= 1;
  }
  return B;
}


void solve(){
}

void doIt(){
  int t = 1;
  // scanf("%d", &t);
  while(t--){
    solve();
  }
}

int main() {
  doIt();
  return 0;
}
