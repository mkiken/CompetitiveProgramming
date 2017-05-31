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

class Trie {
protected:
  static const int CHAR_SIZE = 27;
  char value = ' ';
  bool isRoot = false;
  Trie *next[CHAR_SIZE];

  void _initialize(){
    for (int i = 0; i < CHAR_SIZE; i++){
      next[i] = NULL;
    }
  }
public:
  Trie() {
    _initialize();
    isRoot = true;
  }
  Trie(char c) {
    _initialize();
    value = c;
  }
  void add(string t) {
    Trie *r = this;
    for (int i = 0; i < t.length(); i++) {
      int c = t[i] - 'a';
      if (!r->next[c]) r->next[c] = new Trie(t[i]);
      r = r->next[c];
    }
  }
  void retrieval(){
    for (int i = 0; i < CHAR_SIZE; i++){
      if (next[i]){
        next[i]->retrieval();
      }
    }
  }
  void debug(int depth = 0, string s = ""){
    if (isRoot){
      printf("o\n");
    }
    else{
      string prefix = "";
      for (int i = 0; i < depth; i++){
        prefix += "|";
      }
      prefix += "-";
      s += value;
      printf("%s'%c' (%s)\n", prefix.c_str(), value, s.c_str());
    }
    for (int i = 0; i < CHAR_SIZE; i++){
      if (next[i]){
        next[i]->debug(depth + 1, s);
      }
    }
  }
};

// const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

void exec(){
  Trie t = Trie();
  // t.add("a");
  // t.add("b");
  // t.add("c");
  // t.add("ab");
  t.add("shadowverse");
  t.add("shadowwitch");
  t.debug();

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
