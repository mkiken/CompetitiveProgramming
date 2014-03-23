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
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
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
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
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
#define MAX_N 1000

//Knuth–Morris–Pratt algorithm
//文字列Sから単語Wを探す
//O(|S| + |W|)

//http://ankitsjain22.wordpress.com/2013/07/17/kmp-algorithm-c-code/
// int v[2002];
// void table(string p) {
//     //v[i] :where to go(what to compare next) if mismatch occur at i
//     v[0]=0;  //obviously we ll stay at zero only even if its a mismatch
//     v[1]=0;  //just think naturally where will u go if mismatch occur at 1
//     int cur=0;
//     for(int j=2;j<p.size();j++){
//         while(cur!=0 && p[cur]!=p[j-1])
//         cur=v[cur];
//         if(p[cur]==p[j-1]) cur=cur+1;
//         v[j]=cur;
//     }
// }
// bool kmp(string p,string text) {
//     table(p);
//     int cur=0; //cur: All locations before cur have been matched.
//     for(int j=0;j<text.size();j++) {
//         while(cur>0 && p[cur]!=text[j]) cur=v[cur];
//         if(p[cur]==text[j])
//             if(++cur==p.size()) return true;
//     }
//     return false;
// }

// http://www.prefield.com/algorithm/string/knuth_morris_pratt.html
int *buildFail(string p) {
  int m = p.length();
  int *fail = new int[m+1];
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
  return fail;
}
int match(string t, string p, int *fail) {
  int n = t.length(), m = p.length();
  int count = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      ++count; // match at t[i-m+1 .. i]
      k = fail[k];
    }
  }
  return count;
}

int kmp(string t, string p){
  return match(t, p, buildFail(p));
}

void doIt(){
  string t = "ababac", p = "ab";
  printf("kmp(%s, %s) = %d\n", t.c_str(), p.c_str(), kmp(t, p));
}

int main() {
  doIt();
  return 0;
}
