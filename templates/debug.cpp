#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <limits>
//#include <sstream>
//#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef unsigned int ui;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v, t) sort(v.begin(), v.end(), greater<t>())
#define asort(a) sort(a, a + len(a))
#define rasort(a, t) sort(a, a + len(a), greater<t>())
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int INF = INT_MAX;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

void vprt(vector<int> v){
  cout << v[0];
  rep(i, 1, v.size()) cout << " " << v[i];
  cout << endl;
}
void aprt(int *v, int len){
  cout << v[0];
  rep(i, 1, len) cout << " " << v[i];
  cout << endl;
}


void doIt(){
}

int main() {
  doIt();
  return 0;
}
