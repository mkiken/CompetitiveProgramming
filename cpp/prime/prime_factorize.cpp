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
typedef pair<ll, ll> lpair;
typedef tuple<int, int, int> ituple;

// const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;

#define PI acosl(-1)
#define MAX_N 100 + 2

/**
 * 素因数分解クラス
 */
class PrimeFactorizer{

protected:
  VI primes;
  ll maxNum;
  vector<bool> isPrimeMap;
public:
  PrimeFactorizer(ll maxN){
    maxNum = maxN;
    int primeMaxN = (int)sqrt(maxN) + 1;
    isPrimeMap = vector<bool>(1 + primeMaxN, true);
    isPrimeMap[0] = false;
    isPrimeMap[1] = false;
    for (int i = 2; i <= primeMaxN; i++) {
      if (isPrimeMap[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= primeMaxN; j += i) {
          isPrimeMap[j] = false;
        }
      }
    }
  }

  // nが素数か判定
  bool isPrime(int n){
    return isPrimeMap[n];
  }

  // 素数リストを取得
  vector<int> getPrimes(){
    return primes;
  }

  vector<lpair> factorize(ll n){
    assert(n <= maxNum);

    vector<lpair> result;
    ll threshold = (ll)sqrt(n) + 1;

    for (int i = 0; i < (int)primes.size(); i++){
      if (n < primes[i] || threshold < primes[i]){
        break;
      }
      ll div = 0;
      while (n % primes[i] == 0){
        div++;
        n /= primes[i];
      }
      if (div){
        result.push_back(lpair(primes[i], div));
      }
    }

    if (n > 1){
      result.push_back(lpair(n, 1));
    }

    return result;
  }

};

void check(int n, PrimeFactorizer pf){
    vector<lpair> factors = pf.factorize(n);
    printf("----- result %d -----\n", n);
    for (int j = 0; j < (int)factors.size(); j++){
      ipair e = factors[j];
      printf("%d:[%d] = (%d, %d)\n", n, j, e.first, e.second);
    }
}

void exec(){
  PrimeFactorizer pf = PrimeFactorizer(1000000);

  for (int i = 1; i < 1000; i++){
    check(i, pf);
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
