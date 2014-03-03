#include <vector>
#include <map>
#include <time.h>
#define INF (int)1.0e9;
#define MAX_V 100
using namespace std;

typedef pair<int, int> P;

//from wikipedia
//http://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%9E%E3%83%B3-%E3%83%95%E3%82%A9%E3%83%BC%E3%83%89%E6%B3%95
void BellmanFord(int V, vector<P> edges, int source){
   // この実装では、グラフを頂点のリストと辺のリストで表す。
   // そして、各頂点の distance と predecessor 属性が
   // 最短経路を格納するよう変更していく。
   int dist[MAX_V];
   int pred[MAX_V];

   // Step 1: グラフの初期化
   for(int i = 0; i < V; i++){
       if (i == source) dist[i] = 0;
       else dist[i] = INF;
       pred[i] = -1;
   }

   // Step 2: 辺の緩和を反復
   for (int k = 0; k < V; k++){ //
       for (int i = 0;  i < edges.size(); i++){ // uv は u から v に向かう辺
           int u = edges[i].first;
           int v = edges[i].second; //
           if (dist[u] + 1 < dist[v]){
               dist[v] = dist[u] + 1;
               pred[v] = u;
           }
       }

   // Step 3: 負の重みの閉路がないかチェック
   // for each edge uv in edges:
       // u := uv.source
       // v := uv.destination
       // if u.distance + uv.weight < v.distance:
           // error "Graph contains a negative-weight cycle"
  }
   // for(int i = 0; i < n; i++){
      // printf("");
   // }
   // int pos = source;
   // while(pos != -1){
      // printf("%d ", pos);
      // pos = pred[pos];
   // }
   // printf("\n");

}

int main(){
	int n, from, to, V;
	vector<P> edge;
	scanf("%d%d", &V, &n);
	clock_t start, end;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &from, &to);
		edge.push_back(P(from, to));
	}
	start = clock();
	for(int i = 0; i < n; i++) BellmanFord(V, edge, i);
	end = clock();
	printf("%.9f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

		return 0;
}
