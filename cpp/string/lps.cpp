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

// const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

class LPS{
  protected:
    static const int MAX = 1000 + 5;
    static const int UNPROCESS = -1;
    int len;
    int dp[MAX][MAX];

    // Returns the length of the longest palindromic subsequence in seq
    int _lps(string seq, int i, int j)
    {
      if (dp[i][j] != UNPROCESS){
        return dp[i][j];
      }

      int result = 0;
      if (i == j){
        // Base Case 1: If there is only 1 character
        result = 1;
      }
      else if (seq[i] == seq[j] && i + 1 == j){
        // Base Case 2: If there are only 2 characters and both are same
        result = 2;
      }
      else if (seq[i] == seq[j]){
        // If the first and last characters match
        result = _lps(seq, i+1, j-1) + 2;
      }
      else{
        // If the first and last characters do not match
        result = max(_lps(seq, i, j-1), _lps(seq, i+1, j));
      }

      dp[i][j] = result;

      return result;
    }

  public:
    LPS(){}
    LPS(int n){
      assert(n < MAX);
      len = n;
      initialize();
    }

    void initialize(){
      for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
          dp[i][j] = UNPROCESS;
        }
      }
    }

    int lps(string seq){
      return _lps(seq, 0, seq.length() - 1);
    }
};

void exec(){
  string seq = "GEEKSFORGEEKS";
  LPS l = LPS(seq.length());
  cout << l.lps(seq) << endl;
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
