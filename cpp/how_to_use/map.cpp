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
  map<ull, ull> mmap;
  map<ull, ull>::iterator it;
  if(mmap.count(2) == 0) ;
  else{
    if(1 < mmap[2]) mmap[2] = 3;
  }
  mmap[3] = 4;
  mmap[3] = 5;
  mmap[7] = 2;
  mmap[1] = 1;
  it = mmap.begin();
  while( it != mmap.end() )
  {
    cout << (*it).second << endl;
    ++it;
  }
}

int main() {
  doIt();
  return 0;
}
