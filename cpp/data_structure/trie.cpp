#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>
#include <cassert>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
#define pb push_back
#define fst(e) (e).first
#define snd(e) (e).second
#define rg(e, s, t) (s <= e && e < t)
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size())
#define lg(s) ((int)(s).length())
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<int> VI;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
typedef struct _Datum {
  int fst,snd,trd;
  _Datum(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	fst = arg1; snd = arg2; trd = arg3;
  }
  bool operator <(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd < e.trd : snd < e.snd) : fst < e.fst;
  }
  bool operator >(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd > e.trd : snd > e.snd) : fst > e.fst;
  }
}datum;


void prtAI(int *a, int n, bool display = true){
    if(display) printf("---printAI---\n");
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
    if(display) printf("-----------------\n");
}
void prtVI(const VI &v, bool display = true){
    if(display) printf("-----printVI-----\n");
    Rep(i, sz(v)) printf("%d%c", v[i], i==sz(v)-1?'\n':' ');
    if(display) printf("-----------------\n");
}

#define MAX_N 100005


/****************************************************************************
* Name: main.cpp
* Author: Carlos F. Perea
* Description: Trie data structure
* Copyright: OPEN
****************************************************************************/

// http://cperea.com/programming/implementation-of-a-trie-in-c/


//Trie内で扱う文字を操作
#if 0

#define TRIE_CHARACTER_SIZE 26
int char2Idx(char c){
    if('a' <= c && c <= 'z'){
        return c - 'a';
    }
    assert('a' <= c && c <= 'z');
    return -1;
}
#elif 0

#define TRIE_CHARACTER_SIZE 2
int char2Idx(char c){
    if('0' <= c && c <= '1'){
        return c - '0';
    }
    assert('0' <= c && c <= '1');
    return -1;
}

#else

#define TRIE_CHARACTER_SIZE 62
int char2Idx(char c){
    if('a' <= c && c <= 'z'){
        return c - 'a';
    } else if('A' <= c && c <= 'Z'){
        return c - 'A' + 26;
    } else if('0' <= c && c <= '9'){
        return c - '0' + 52;
    }
    assert('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9');
    return -1;
}

#endif

class Node {
public:
    char value;             // the character value (a-z)
    bool end;               // indicates whether this node completes a word
    Node * children[TRIE_CHARACTER_SIZE];    // represents the TRIE_CHARACTER_SIZE letters in the alphabet
    int cnt; //このノードを通過する文字列の数

    Node(char value);
    ~Node();
};
Node::Node(char value) {
    this->cnt = 1;
    this->value = value;
    // Initializes all of the children with NULL value
    for (int i = 0; i < TRIE_CHARACTER_SIZE; ++i) children[i] = NULL;
}
Node::~Node() {
    // free resources
}

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string word);
    bool searchForWord(string word);
    void deleteWord(string word);
    Node * getRoot();
private:
    Node * root;
};
Trie::Trie() {
    // Initialize the trie
    root = new Node(' ');
    root->end = true;
}
Trie::~Trie() {
    // Free resources
}
Node * Trie::getRoot() {
    return root;
}
void Trie::addWord(string word) {
    Node * currentNode = root;

    for (int i = 0; i < word.size(); ++i) {
        char currentChar = word.at(i);
        int index = char2Idx(currentChar);
        if (currentNode->children[index] != NULL) {
            // check if the current node has the current character as one of its decendants
            currentNode = currentNode->children[index];
            currentNode->cnt++;
        } else {
            // the current node doesn't have the current character as one of its decendants
            Node * newNode = new Node(currentChar);
            currentNode->children[index] = newNode;
            currentNode = newNode;
        }
        if (i == word.size() - 1) currentNode->end = true;
    }
}
/**
* Searches for a word in the trie
* @param string The word to search in the trie
* @return bool  True if it's found, false otherwise
*/
bool Trie::searchForWord(string word) {
    Node * currentNode = root;
    for (int i = 0; i < word.size(); ++i) {
        char currentChar = word.at(i);
        int index = char2Idx(currentChar);

        if (currentNode->children[index] != NULL) currentNode = currentNode->children[index];
        else return false;
        // makes sure the last node is marked as an end for a word
        if (i == word.size() - 1 && !currentNode->end) return false;
    }
    return true;
}
/**
* Deletes a word from the trie
* @param string The word to be deleted from the trie
* @return void
*/
void Trie::deleteWord(string word) {
    Node * currentNode = root;
    Node * lastWord = root;
    for (int i = 0; i < word.size(); ++i) {
        char currentChar = word.at(i);
        int index = char2Idx(currentChar);

        // if the current node has the current character as one of its decendants
        if (currentNode->children[index] != NULL) currentNode = currentNode->children[index];
        // the current node doesn't have the current character which means the word is not in the trie
        else return;
        if (i == word.size() - 1 && currentNode->end) currentNode->end = false;
    }
}
/**
* Traverse the trie in-order fashion to print the words in lexicographical order
*/
void alphabetize(Node * node, string prefix = "") {
    if (node->end) cout << prefix << endl;
    for (int i = 0; i < TRIE_CHARACTER_SIZE; ++i) {
        if (node->children[i] != NULL) {
            string currentString = prefix + node->children[i]->value;
            alphabetize(node->children[i], currentString);
        }
    }
}

string b2s(ull x, int len) {
    string c = "";
    for(int i = 0; i < len; i++){
        int digit = x & (1 << i);
        if(digit) c += '1';
        else c += '0';
    }
    reverse(c.begin(), c.end());
    return c;
}

int test() {
    Trie * t = new Trie();
    t->addWord("Carlos");
    t->addWord("Perea");
    t->addWord("Hello");
    t->addWord("Ball");
    t->addWord("Balloon");
    t->addWord("Show");
    t->addWord("Shower");
    t->addWord("Terry01");
    alphabetize(t->getRoot());
    t->deleteWord("Show");
    alphabetize(t->getRoot());
    /*
      Outputs:
      ball
      balloon
      carlos
      hello
      perea
      show
      shower
    */
    return 0;
}

const int MAX_BIT = 31;

void doIt(){
    int n, a[2002];
    Trie* t = new Trie();
    scanf("%d", &n);
    Rep(i, n){
        scanf("%d", &a[i]);
        t->addWord(b2s(a[i], MAX_BIT));
    }
    // alphabetize(t->getRoot());
    ll ans = -1;
    Rep(i, n){
        rep(j, i+1, n){
            ll e = a[i] ^ a[j];
            ll tmp = 0;
            Node* cNode = t->getRoot();
            bool bi = true, bj = true;
            Rrep(k, MAX_BIT - 1){
                int digit = (e & (1 << (k))) == 0? 0 : 1;
                if(cNode->children[1 - digit] != NULL){
                    int avail = cNode->children[1-digit]->cnt;

                    if(bi && ((a[i] & (1 << (k))) == 0? 0 : 1) == 1 - digit) avail--;
                    if(bj && ((a[j] & (1 << (k))) == 0? 0 : 1) == 1 - digit) avail--;
                    if(avail > 0){
                        cNode = cNode->children[1 - digit];
                        tmp += 1 << (k);
                        if(bi && (((a[i] & 1 << k) == 0? 0 : 1) != 1 - digit)){
                            bi = false;
                        }
                        if(bj && (((a[j] & 1 << k) == 0? 0 : 1) != 1 - digit)){
                            bj = false;
                        }
                    } else{
                        cNode = cNode->children[digit];
                        if(bi && (((a[i] & 1 << k) == 0? 0 : 1) != digit)){
                            bi = false;
                        }
                        if(bj && (((a[j] & 1 << k) == 0? 0 : 1) != digit)){
                            bj = false;
                        }

                    }
                } else{
                    cNode = cNode->children[digit];
                    if(bi && (((a[i] & 1 << k) == 0? 0 : 1) != digit)){
                        bi = false;
                    }
                    if(bj && (((a[j] & 1 << k) == 0? 0 : 1) != digit)){
                        bj = false;
                    }
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;


}

int solve(){
    int t;
    cin >> t;
    while(t--){
        doIt();
    }
    return 0;
}

int main(){
    test();
}
