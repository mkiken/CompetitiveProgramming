#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
//#include <stack>
//#include <limit>
//#include <functional>
#include <complex>
using namespace std;
typedef pair<int, int> P;
typedef complex<double> p;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#define len(a) (sizeof(a) / sizeof(*a))
#define rep(i, s, e) for(int i = s; i < e; i++)
#define rrep(i, e, s) for(int i = e; s <= i; i--)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define arange(a) a, a + len(a)
#define afill(a, v) fill(a, a + len(a), v)
#define afill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define vrsort(v) sort(vrrange(v))
#define asort(a) sort(a, a + len(a))
#define arsort(a, t) sort(a, a + len(a), greater<t>())
#define fmax(a, b) (a < b? b : a)
#define fmin(a, b) (a > b? b : a)
#define fabs(a) (a < 0? -a : a)
#define X real()
#define Y imag()
const double EPS = 1e-10;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0, 1, 10, 100, 1000, 10000};
//priority_queue< int, vector<int>, greater<int> > q;

int MAX_N = 16;

// int bitcount(int x)
// {
//     int b;
//     for (b = 0; x != 0; x &= x - 1)
//         b++;
//     return b;
// }

//http://www.mwsoft.jp/programming/java/java_lang_integer_bit_count.html
int bitcount(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}


class GUMIAndSongsDiv2 {
	public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
	  int n = duration.size(), ans = 0;
	  //int dp[1 << MAX_N][MAX_N][MAX_N + 1];
	  int dp[1 << MAX_N][MAX_N];
	  afill2(dp, INF, int);
	  rep(i, 0, n){
		if(duration[i] <= T){
		  dp[1 << i][i] = duration[i];
		  ans = 1;
		}
	  }
	  rep(i, 0, 1 << n){
		rep(j, 0, n){
		  if(dp[i][j] != INF){
			  rep(l, 0, n){
				if(!(i >> l & 1)){
				  dp[i | 1 << l][l] = min(dp[i | 1 << l][l], dp[i][j] + duration[l] + abs(tone[j] - tone[l]));
				  if(dp[i | 1 << l][l] <= T){
					ans = max(ans, bitcount(i | 1 << l));
				  }
				  else dp[i | 1 << l][l] = INF;
				}
			  }
		  }
		}
	  }
	  return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 4, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; int Arg3 = 3; verify_case(0, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 200, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 0; verify_case(1, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 4; verify_case(2, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 58, 58}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; int Arg3 = 3; verify_case(3, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {8, 11, 7, 15, 9, 16, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 8, 5, 4, 2, 7, 4, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arg3 = 1; verify_case(4, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 302606; int Arg3 = 8; verify_case(5, Arg3, maxSongs(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	GUMIAndSongsDiv2 _test;
	_test.run_test(-1);
	//cout << _test.maxSongs(vector <int> duration, vector <int> tone, int T) << endl;
	return 0;
}
// END CUT HERE
