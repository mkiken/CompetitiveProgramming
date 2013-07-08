#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
//#include <limits>
#include <sstream>
//#include <functional>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define fmax(a, b) (a < b? b : a)
#define fmin(a, b) (a > b? b : a)
#define fabs(a) (a < 0? -a : a)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue<int, vector<int>, greater<int>> q;
typedef struct _Node {
  _Node(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	i = arg1;
	j = arg2;
	k = arg3;
  }
  int i,j,k;
  bool operator <(const struct _Node &e) const{
    return i == e.i? j < e.j : i < e.i;
  }
  bool operator >(const struct _Node &e) const{
    return i == e.i? j > e.j : i > e.i;
  }
}node;

void doIt(){
  const int MAX_N = 10002;
  bool bPrimes[MAX_N];
  vector<int> primes;
  afill(bPrimes, true);
  bPrimes[0] = bPrimes[1] = false;
  rep(i, 2, MAX_N){
	if(bPrimes[i]){
	  primes.push_back(i);
	  for(int j = 2*i; j < MAX_N; j += i) bPrimes[j] = false;
	}
  }

}

//偶数は無視する
void doIt2(){
  const int MAX_N = 10002;
  bool bPrimes[MAX_N];
  vector<int> primes;
  afill(bPrimes, true);
  bPrimes[0] = bPrimes[1] = false;
  primes.push_back(2);
  for(int i = 3; i < MAX_N; i += 2){
	if(bPrimes[i]){
	  primes.push_back(i);
	  for(int j = 3*i; j < MAX_N; j += 2*i) bPrimes[j] = false;
	}
  }
  cout << primes.size() << endl;

}

int main() {
  doIt();
  return 0;
}
