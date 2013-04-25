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
#include <sstream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef unsigned int ui;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(ll i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v) fill((int *)a, (int *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define msort(a) sort(a, a + len(a))
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int INF = INT_MAX;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};


//http://www.cplusplus.com/articles/D9j2Nwbp/
//http://blog.goo.ne.jp/linux_ekyu/e/3a89ea531b6a0ea6997dd68238b198ce


vector<string> split( string s, string c )
{
  vector<string> ret;
  for(int i = 0, n; i <= s.length(); i = n + 1 ){
	n = s.find_first_of( c, i );
	if( n == string::npos ) n = s.length();
	string tmp = s.substr( i, n-i );
	ret.push_back(tmp);
  }
  return ret;
}

//int to string
string i2s(int Number){
  return static_cast<ostringstream*>( &(ostringstream() << Number) )->str();
}
//string to int
int s2i(string Text){
  int Number;
  if ( ! (istringstream(Text) >> Number) ) Number = 0;
  return Number;
}

//is s palindrome?
bool isPalindrome(string s){
  return s==string( s.rbegin(), s.rend() )? true : false;
}

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

//ipv4 format to ui
ui ip2ui(string ip){
  ui ret = 0;
  const ui weight[] = {(ui)pow(2, 24, MOD), (ui)pow(2, 16, MOD), (ui)pow(2, 8, MOD), (ui)pow(2, 0, MOD)};
  vector<string> ss = split(ip, ".");
  rep(i, 0, ss.size()) ret += s2i(ss[i])*weight[i];
  return ret;
}
//ui to ipv4 format
string ui2ip(ui ip){
  string ret = "";
  ui mask = 255;
  for(int i = 24; 8 <= i; i -= 8) ret += i2s((ip >> i) & mask) + ".";
  ret += i2s((ip >> 0) & mask);
  return ret;
}

void doIt(){
  cout << s2i("12") + 3 << endl;
}

int main() {
  doIt();
  return 0;
}