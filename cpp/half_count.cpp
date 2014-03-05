#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#define rg(i, s, t) s <= i && i < t
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;
// #define MAX_N 1000

// http://arc017.contest.atcoder.jp/tasks/arc017_3
void doIt(){
  int n, x, w[33];
  cin >> n >> x;
  Rep(i, n){
    cin >> w[i];
  }

  // sort(w, w+n, greater<int>());
  map<int, int> grpA[2], grpB[2];
  int prev = 0, now = 1, ptr;
  grpA[prev][0]++;
  map<int, int>::iterator it;

  Rep(i, n/2+1){
    it = grpA[prev].begin();
    grpA[now].clear();
    while(it != grpA[prev].end()){
      grpA[now][(*it).first + w[i]] += (*it).second;
      grpA[now][(*it).first] += (*it).second;
      it++;
    }
    prev = 1 - prev;
    now = 1 - now;
  }
  ptr = prev;

  prev = 0;
  now = 1;
  grpB[prev][0]++;
  rep(i, n/2+1, n){
    it = grpB[prev].begin();
    grpB[now].clear();
    while(it != grpB[prev].end()){
      grpB[now][(*it).first + w[i]] += (*it).second;
      grpB[now][(*it).first] += (*it).second;
      it++;
    }
    prev = 1 - prev;
    now = 1 - now;
  }

  it = grpA[ptr].begin();
  ll ans = 0;
  while(it != grpA[ptr].end()){
    // printf("itA = %d\n", (*it).first);
    if(grpB[prev].count(x - (*it).first)) ans += (*it).second * grpB[prev][x - (*it).first];
    it++;
  }

  cout << ans << endl;
}

int main() {
  doIt();
  return 0;
}
