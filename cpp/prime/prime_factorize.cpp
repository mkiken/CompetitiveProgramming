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

// const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

/**
 * 素因数分解クラス
 */
class PrimeFactorizer{
public:
  PrimeFactorizer(VI ps){
    primes = ps;
    maxNum = (ll)primes[primes.size()-1] * primes[primes.size()-1];
  }

  vector<ipair> factorize(ll n){
    assert(n <= maxNum);

    vector<ipair> result;
    int threshold = (int)sqrt(n) + 1;

    for (int i = 0; i < primes.size(); i++){
      if (n < primes[i] || threshold < primes[i]){
        break;
      }
      int div = 0;
      while (n % primes[i] == 0){
        div++;
        n /= primes[i];
      }
      if (div){
        result.push_back(make_pair(primes[i], div));
      }
    }

    if (n > 1){
      result.push_back(ipair(n, 1));
    }

    return result;
  }

protected:
  VI primes;
  ll maxNum;

};

void check(int n, PrimeFactorizer pf){
    vector<ipair> factors = pf.factorize(n);
    printf("----- result %d -----\n", n);
    for (int j = 0; j < factors.size(); j++){
      ipair e = factors[j];
      printf("%d:[%d] = (%d, %d)\n", n, j, e.first, e.second);
    }
}

void exec(){
  int org_data[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977
  };
  VI primes(org_data, org_data + 126);
  PrimeFactorizer pf = PrimeFactorizer(primes);

  for (int i = 1; i < 100; i++){
    check(i, pf);
  }

  check(983, pf);

  // check(1000000000, pf);

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
