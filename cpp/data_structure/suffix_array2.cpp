#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define Rep(i, e) for(int i = 0;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
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
#define pb push_back
#define rg(e, s, t) s <= e && e < t
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name;
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
#define MAX_N 20001
// #define MAX_N 6
#define MIN_VALUE -INF

int n, k, _rank[MAX_N + 1], tmp[MAX_N + 1];

bool compare_sa(int i, int j){
  if(_rank[i] != _rank[j]) return _rank[i] < _rank[j];
  else{
    int ri = i + k <= n? _rank[i + k] : MIN_VALUE;
    int rj = j + k <= n? _rank[j + k] : MIN_VALUE;
    return ri < rj;
  }
}

//O(NlogN)
void construct_sa(string S, int *sa){
  n = S.length();
  Rep(i, n + 1){
    sa[i] = i;
    _rank[i] = i < n? S[i] : MIN_VALUE;
  }
  for(k = 1; k <= n; k *= 2){
    sort(sa, sa + n + 1, compare_sa);
    tmp[sa[0]] = 0;
    rep(i, 1, n+1){
      tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i])? 1 : 0);
    }
    Rep(i, n+1){
      _rank[i] = tmp[i];
    }
  }
}

// O(N)
void construct_lcp(string S, int *sa, int *lcp){
  // int n = S.length();
  Rep(i, n+1) _rank[sa[i]] = i;
  int h = 0;
  lcp[0] = 0;
  Rep(i, n){
    int j = sa[_rank[i] - 1];
    if(h > 0) h--;
    for(; j + h < n && i + h < n; h++){
      if(S[j + h] != S[i + h]) break;
    }
    lcp[_rank[i] - 1] = h;
  }
}

int sa[MAX_N], lcp[MAX_N];

// http://poj.org/problem?id=2217
void doIt(){
  int tt;
  string s, t;
  cin >> tt;
  getline(cin, s);
  while(tt--){
    getline(cin, s);
    getline(cin, t);
    int sl = s.length();
    s += '$' + t;
    construct_sa(s, sa);
    construct_lcp(s, sa, lcp);
    int ans = 0, idx = 0;
    Rep(i, s.length()){
      if(sa[i] < sl != sa[i+1] < sl){
        ans = max(ans, lcp[i]);
      }
    }
    printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
  }


}

int main() {
  doIt();
  return 0;
}
