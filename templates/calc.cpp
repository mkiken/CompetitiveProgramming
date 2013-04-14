#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
//#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(s, e) for(int i = s;i < e;i++)
#define rep2(s, e) for(int j = s;j < e;j++)
#define rrep(e, s) for(int i = e;s <= i;i--)
#define rrep2(e, s) for(int j = e;s <= j;j--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v) fill((int *)a, (int *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end());
#define msort(a) sort(a, a + len(a))
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int INF = INT_MAX;

//n**p % m
int pow(int n, int p, int m){
  ll ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
	if(p & 1 == 1) ans = (ans*ln) % m;
	ln = (ln * ln) % m;
	p = p >> 1;
  }
  return (int)ans;
}

int gcd(int a, int b) {
  return b != 0 ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y) {
  int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

// 1/a mod m
int mod_inverse(int a, int m){
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

//n! mod m
int fact(int n, int m){
  ll ret = 1;
  rep(2, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nPk mod m
int perm(int n, int k, int m){
  ll ret = 1;
  rep(n-k+1, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nCk mod m
int combi(int n, int k, int m){
  ll l = 1, c = 1;
  if(n - k < k) k = n - k;
  rep(0, k - 1){
	l = (l * (n - i)) % m;
	c = (c * (k - i)) % m;
  }
  return (int)((l * mod_inverse(c, m)) % m);
}

//n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
int rep_perm(int n, vector<int> a, int m){
  ll ret = fact(n, m), pdt = 1;
  rep(0, a.size()) pdt = (pdt * fact(a[i], m)) % m;
  return (int)((ret * mod_inverse(pdt, m)) % m);
}



void doIt(){
    //cout << pow(2, 400, MOD) << endl;
}

int main() {
  doIt();
  return 0;
}
