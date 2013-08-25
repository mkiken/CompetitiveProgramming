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


double combi[1001][1001]; //aCb = combi[a][b]
int MAX_N = 1000;

void makeCombi(){
  mfill2(combi, 0, ll);
  rep(i, 0, MAX_N+1) combi[i][0] = 1;
  rep(i, 1, MAX_N+1){
	rep(j, 1, i+1) combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
  }
}

//n**p % m
int powMod(int n, int p, int m){
  ll ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = (ans*ln) % m;
	ln = (ln * ln) % m;
	p = p >> 1;
  }
  return (int)ans;
}

int gcd(int a, int b) {
  if( a < b ) swap( a, b );
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
  rep(i, 2, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nPk mod m
int perm(int n, int k, int m){
  ll ret = 1;
  rep(i, n-k+1, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nCk mod m
int comb(int n, int k, int m){
  ll l = 1, c = 1;
  if(n - k < k) k = n - k;
  rep(i, 0, k - 1){
	l = (l * (n - i)) % m;
	c = (c * (k - i)) % m;
  }
  return (int)((l * mod_inverse(c, m)) % m);
}

//n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
int rep_perm(int n, vector<int> a, int m){
  ll ret = fact(n, m), pdt = 1;
  rep(i, 0, a.size()) pdt = (pdt * fact(a[i], m)) % m;
  return (int)((ret * mod_inverse(pdt, m)) % m);
}

//calculate (a*b)%m
//http://discuss.codechef.com/questions/9723/witmath-editorial
ull bigMul(ull a, ull b, int m){
	int base = (int)1e9;
	ull a_low = a % base, a_high = a / base, b_low = b % base, b_high = b / base, result; 
	result = (a_high * b_high) % m;
	rep(i, 0, 9) result = (result * 10) % m;
	result = (result + a_low*b_high + b_low*a_high) % m;
	rep(i, 0, 9) result = (result * 10) % m;
	result = (result + a_low*b_low) % m;
	return result;
}


void doIt(){
    //cout << pow(2, 400, MOD) << endl;
}

int main() {
  doIt();
  return 0;
}
