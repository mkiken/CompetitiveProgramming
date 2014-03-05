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
#define MAX_N 500 + 5

// 編集距離を求める
// http://d.hatena.ne.jp/ohnishiakira/20090809/1249845529
int LevenshteinDistance(string str1, string str2){
	int lenstr1 = str1.length() + 1, lenstr2 = str2.length() + 1, cost = 0;
	int d[lenstr1][lenstr2];
	Rep(i1, lenstr1) d[i1][0] = i1;
	Rep(i2, lenstr2) d[0][i2] = i2;
	rep(i1, 1, lenstr1){
		rep(i2, 1, lenstr2){
			cost = str1[i1 - 1] == str2[i2 - 1] ? 0 : 1;
			d[i1][i2] = min(d[i1 - 1][i2] + 1, min(d[i1][i2 - 1] + 1, d[i1 - 1][i2 - 1] + cost));
		}
	}
	return d[lenstr1 - 1][lenstr2 - 1];
}

// http://www.codechef.com/ODCD2013/problems/LEMAGIK
void doIt(){
	int t;
	string a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << LevenshteinDistance(a, b) << endl;
	}
}

int main() {
  doIt();
  return 0;
}
