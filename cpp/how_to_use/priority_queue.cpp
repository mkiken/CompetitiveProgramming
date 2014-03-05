#include <iostream>
//#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
//#include <string>
//#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> P;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(s, e) for(int i = s;i < e;i++)
#define rep2(s, e) for(int j = s;j < e;j++)
#define rrep(e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
const double EPS = 1e-10;


void doIt(){
  //昇順
  //priority_queue<ull, vector<ull>, greater<ull> > queue;
  //降順
  priority_queue<ull> queue;

  queue.push(4);
  queue.push(5);
  queue.push(2);
  while(queue.empty() == false){
	ull val = queue.top();
	cout << val << endl;
	queue.pop();
  }
}

int main() {
  doIt();
  return 0;
}
