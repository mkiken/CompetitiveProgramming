#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
//#include <string>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v, t) sort(v.begin(), v.end(), greater<t>())
#define asort(a) sort(a, a + len(a))
#define rasort(a, t) sort(a, a + len(a), greater<t>())
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int INF = INT_MAX;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};


void doIt(){
  const int MAX_N = 10002;
  bool bPrimes[MAX_N];
  vector<int> primes;
  mfill(bPrimes, true);
  bPrimes[0] = bPrimes[1] = false;
  rep(i, 2, MAX_N){
	if(bPrimes[i]){
	  primes.push_back(i);
	  for(int j = 2*i; j < MAX_N; j += i) bPrimes[j] = false;
	}
  }

}

int main() {
  doIt();
  return 0;
}
