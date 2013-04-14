#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
//#include <string>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(s, e) for(int i = s;i < e;i++)
#define rep2(s, e) for(int j = s;j < e;j++)
#define rrep(e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
const double EPS = 1e-10;


void doIt(){
  const int MAX_N = 10002;
  bool bPrimes[MAX_N];
  vector<int> primes;
  mfill(bPrimes, true);
  bPrimes[0] = bPrimes[1] = false;
  rep(2, MAX_N){
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
