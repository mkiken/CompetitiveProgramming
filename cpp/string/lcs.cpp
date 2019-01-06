#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)

/*
 * 最長共通部分列(longest common subsequence)
 */

// https://qnighy.hatenablog.com/entry/20100119/1263911723
vector<char> lcs(string s1, string s2){
  vector<vector<pair<int, pair<int, int> > > > dp(s1.size()+1, vector<pair<int, pair<int, int> > >(s2.size()+1));
  for(int i = 0; i <= s1.size(); i++) {
    for(int j = 0; j <= s2.size(); j++) {
      if(i==0 || j==0) {
        dp[i][j] = make_pair(0, make_pair(-1, -1));
      } else {
        dp[i][j] = dp[i][j-1];
        if(dp[i][j].first < dp[i-1][j].first) {
          dp[i][j] = dp[i-1][j];
        }
        if(s1[i-1] == s2[j-1] && dp[i][j].first < dp[i-1][j-1].first+1) {
          dp[i][j] = make_pair(dp[i-1][j-1].first+1, make_pair(i-1, j-1));
        }
      }
    }
  }
  vector<char> subseq_stack;
  for(int i=s1.size(), j=s2.size();i>0 && j>0;) {
    pair<int, int> next = dp[i][j].second;
    //make_pair(i,j) = next;
    i = next.first; j = next.second;
    if(i < 0 || j < 0){
      break;
    }
    subseq_stack.push_back(s1[i]); // s1[i] == s2[j]
  }
  reverse(subseq_stack.begin(), subseq_stack.end());

  return subseq_stack;
}

void exec(){
  // https://atcoder.jp/contests/dp/tasks/dp_f
  vector<char> res = lcs("abracadabra", "avadakedavra");
  string ans = "aaadara";
  for (int i = 0; i < ans.length(); i++){
    assert(ans[i] == res[i]);
  }
  cout << "OK" << endl;
}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
