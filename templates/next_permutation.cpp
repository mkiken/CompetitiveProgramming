#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  const int n = 3;
  std::vector<int> data;
  // [0, 1, 2, ....]というサイズnの配列を作成
  for(int i=1; i<=9; ++i){
    data.push_back(i);
  }
  // 全ての順列を出力
  do{
	int s = data[0]*1000 + data[1] * 100 + data[2] * 10 + data[3];
    int t = data[5]*1000 + data[6] * 100 + data[7] * 10 + data[8];
	if(s * data[4] == t) cout << s << " * " << data[4] << " = " << t << endl;

  }while(next_permutation(data.begin(), data.end()));

  return 0;
}
