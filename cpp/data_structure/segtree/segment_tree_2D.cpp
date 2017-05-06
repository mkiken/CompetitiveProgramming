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

const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

class SegmentTree2D {
protected:
    int H, W;
    vector< VL > dat;

  // 木の子から親を定義する関数
    virtual ll _func(ll a, ll b) = 0;

  // 木のインデックス範囲外の時に返すデフォルト値
    virtual ll _getDefaultValue() = 0;

    ll query_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
        if(ri <= si or ti <= li) return _getDefaultValue();
        if(li <= si and ti <= ri) return query_w(lj,rj,0,W,k,0);
        const int mi = (si+ti)/2;
        return _func(query_h(li,lj,ri,rj,si,mi,2*k+1), query_h(li,lj,ri,rj,mi,ti,2*k+2));
    }
    ll query_w(int lj, int rj, int sj, int tj, int i, int k) {
        if(rj <= sj or tj <= lj) return _getDefaultValue();
        if(lj <= sj and tj <= rj) return dat[i][k];
        const int mj = (sj+tj)/2;
        return _func(query_w(lj,rj,sj,mj,i,2*k+1),query_w(lj,rj,mj,tj,i,2*k+2));
    }
public:
    SegmentTree2D(){}
    SegmentTree2D(vector< VI > &f) {
        H = W = 1;
        while(H < (int)f.size()) H <<= 1;
        while(W < (int)f[0].size()) W <<= 1;
        init(f);
    }

    void init(vector< VI > &f) {
        dat.assign(2*H-1,VL(2*W-1, _getDefaultValue()));
        for (int i = 0; i < (int)f.size(); i++)
            for (int j = 0; j < (int)f[0].size(); j++)
                dat[i+H-1][j+W-1] = f[i][j];
        for (int i = 2*H-2; i > H-2; i--)
            for (int j = W-2; j >= 0; j--)
                dat[i][j] = _func(dat[i][2*j+1], dat[i][2*j+2]);
        for (int i = H-2; i >= 0; i--)
            for (int j = 0; j < 2*W-1; j++)
                dat[i][j] = _func(dat[2*i+1][j], dat[2*i+2][j]);
    }
    // [(li, ri), (lj, rj)]区間のクエリを求める
    ll query(int li, int lj, int ri, int rj) { return query_h(li,lj,ri + 1,rj + 1,0,H,0); }
};

class SegmentTree2DMin : public SegmentTree2D {
  using SegmentTree2D::SegmentTree2D;
protected:
  // 木の子から親を定義する関数
  ll _func(ll a, ll b){
    return min(a, b);
  }

  // 木のインデックス範囲外の時に返すデフォルト値
  ll _getDefaultValue(){
    return LLONG_MAX;
  }
};

class SegmentTree2DMax : public SegmentTree2D {
  using SegmentTree2D::SegmentTree2D;
protected:
  // 木の子から親を定義する関数
  ll _func(ll a, ll b){
    return max(a, b);
  }

  // 木のインデックス範囲外の時に返すデフォルト値
  ll _getDefaultValue(){
    return LLONG_MIN;
  }
};

void exec(){
    int h = 4, w = 3, weight = 3;
    vector< VI > v;

    for (int i = 0; i < h; i++){
        VI tmp;
        for (int j = 0; j < w; j++){
            tmp.push_back(i + j + weight);
        }
        v.push_back(tmp);
    }

    // SegmentTree2DMin st2 = SegmentTree2DMin(v);
    SegmentTree2DMin st2 = SegmentTree2DMin();

    cout << st2.query(0, 0, h, w) << endl;
    cout << st2.query(0, 0, 0, 0) << endl;
    cout << st2.query(1, 1, 1, 1) << endl;
    cout << st2.query(1, 1, h, w) << endl;
    cout << st2.query(h - 1, w - 1, h - 1, w - 1) << endl;


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
