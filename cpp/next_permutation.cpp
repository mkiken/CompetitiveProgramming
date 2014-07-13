#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
                        BidirectionalIterator last1 ,
                        BidirectionalIterator first2 ,
                        BidirectionalIterator last2 )
{
  if (( first1 == last1 ) || ( first2 == last2 )) {
    return false ;
  }
  BidirectionalIterator m1 = last1 ;
  BidirectionalIterator m2 = last2 ; --m2;
  while (--m1 != first1 && !(* m1 < *m2 )){
  }
  bool result = (m1 == first1 ) && !(* first1 < *m2 );
  if (! result ) {
    while ( first2 != m2 && !(* m1 < * first2 )) {
      ++ first2 ;
    }
    first1 = m1;
    iter_swap (first1 , first2 );
    ++ first1 ;
    ++ first2 ;
  }
  if (( first1 != last1 ) && ( first2 != last2 )) {
    m1 = last1 ; m2 = first2 ;
    while (( m1 != first1 ) && (m2 != last2 )) {
      iter_swap (--m1 , m2 );
      ++ m2;
    }
    reverse (first1 , m1 );
    reverse (first1 , last1 );
    reverse (m2 , last2 );
    reverse (first2 , last2 );
  }
  return ! result ;
}
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
                        BidirectionalIterator middle ,
                        BidirectionalIterator last )
{
  return next_combination (first , middle , middle , last );
}

void doIt3(){
  int ary[] = {1, 2, 3, 4, 5};
  //ソートが必要！
  sort(ary, ary + 5);
  do{
    for(int i = 0; i < 3; i++) cout << ary[i] << " " ;
    cout << endl;
  }
  while(next_combination(ary, ary + 3, ary + 5));
}

//http://www.programming-magic.com/20090123132035/
void doIt2(){
  const int n = 40, r = 3;
  vector<int> data;
  // [0, 1, 2, ....]というサイズnの配列を作成
  for(int i=0; i<n; ++i){
    data.push_back(i);
  }
  // 全ての組み合わせを出力
  do{
    cout << "[ " << data[0];
    for(unsigned int i=1; i<r; ++i){
      cout << ", " << data[i];
    }
    cout << " ]" << endl;
  }while(next_combination(data.begin(), data.begin()+r, data.end()));

}

void all_permutate(int n){
  vector<int> v(n, 0);
  for(int i = 0; i < n; i++) v[i] = i;
  do{
    //do action
    cout << 1 << endl;
  } while(next_permutation(v.begin(), v.end()));
}

void doIt(){
  const int n = 3;
  vector<int> data;
  // [0, 1, 2, ....]というサイズnの配列を作成
  for(int i=1; i<=3; ++i){
    data.push_back(i);
  }
  // 全ての順列を出力
  do{
    cout << data[0] << " " << data[1] << " " << data[2] << endl;
  }while(next_permutation(data.begin(), data.end()));
  // // 全ての順列を出力
  // do{
  // 	int s = data[0]*1000 + data[1] * 100 + data[2] * 10 + data[3];
  //   int t = data[5]*1000 + data[6] * 100 + data[7] * 10 + data[8];
  // 	if(s * data[4] == t) cout << s << " * " << data[4] << " = " << t << endl;
  // }while(next_permutation(data.begin(), data.end()));
}

int main(){
  // doIt3();
  all_permutate(4);
  return 0;
}
