#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;

//  MillerRabin primality test
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
//
// * how to use *
// MillerRabin mr;
// mr.check(1);

// 扱う値がsqrt(ullの最大値)より小さいかどうか
// 扱う値がsqrt(ullの最大値)より小さいのであればbig系の関数でなくてもよいので高速化できる
#define SMALL_ENOUGH 0

class MillerRabin{
private:
  static const int test[];
  //calculate (a*b)%m
  //http://discuss.codechef.com/questions/9723/witmath-editorial
  ull bigMul(ull a, ull b, ull m){
    int base = (int)1e9;
    ull a_low = a % base, a_high = a / base, b_low = b % base, b_high = b / base, result;
    result = (a_high * b_high) % m;
    for (int i = 0; i < 9; i++){
      result = (result * 10) % m;
    }
    result = (result + a_low*b_high + b_low*a_high) % m;
    for (int i = 0; i < 9; i++){
      result = (result * 10) % m;
    }
    result = (result + a_low*b_low) % m;
    return result;
  }

  //n**p % m
  ull bigPowMod(ull n, ull p, ull m){
    ull ans = 1, ln = n;
    if(p <= 0) return 1;
    while(p != 0){
      if((p & 1) == 1) ans = bigMul(ans, ln, m); //ans = (ans*ln) % m;
      //ln = (ln * ln) % m;
      ln = bigMul(ln, ln, m);
      p = p >> 1;
    }
    return ans;
  }

  int _powMod(int n, int p, int m){
    ll ans = 1, ln = n;
    if(p <= 0) return 1;
    while(p != 0){
      if((p & 1) == 1) ans = (ans*ln) % m;
      ln = (ln * ln) % m;
      p = p >> 1;
    }
    return (int)ans;
  }

  bool suspect(int a, int s, ull d, ull n) {
#if SMALL_ENOUGH
    ull x = _powMod(a, d, n);
#else
    ull x = bigPowMod(a, d, n);
#endif
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
      if (x == n - 1) return true;
#if SMALL_ENOUGH
      x = x * x % n;
#else
      x = bigMul(x, x, n);
#endif
    }
    return false;
  }

public:
  MillerRabin()
  {
  }

  bool check(ull n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
    if (!suspect(test[i], s, d, n)) return false;
    return true;
  }

};
const int MillerRabin::test[] = {2,3,5,7,11,13,17,19,23,-1};

void millerRabinTest(){
  MillerRabin mr;
  ull a = (ull)1e15;
  for (int i = 1; i < 21; i++){
    cout << a-i << " is " << mr.check(a-i) << endl;
  }
}
int main(){
  millerRabinTest();
  return 0;
}
