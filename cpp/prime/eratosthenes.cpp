#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;

// O(n log log n)
class EratosthenesSieve{
private:
  int maxN;
  vector<bool> isPrimeMap;
  vector<int> primes;
public:
  EratosthenesSieve(int n){
    maxN = n;
    isPrimeMap = vector<bool>(1 + maxN, true);
    isPrimeMap[0] = false;
    isPrimeMap[1] = false;
    for (int i = 2; i <= maxN; i++) {
      if (isPrimeMap[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= maxN; j += i) {
          isPrimeMap[j] = false;
        }
      }
    }
  };

  // nが素数か判定
  bool isPrime(int n){
    return isPrimeMap[n];
  }

  // 素数リストを取得
  vector<int> getPrimes(){
    return primes;
  }
};

void solve(){
  EratosthenesSieve es(1000);
  vector<int> primes = es.getPrimes();
  for (int i = 0; i < primes.size(); i++){
    printf("%d\n", primes[i]);
  }
}

int main(){
  solve();
  return 0;
}
