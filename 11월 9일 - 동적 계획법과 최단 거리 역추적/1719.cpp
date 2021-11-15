#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 2e6;

//플로이드-워셜

//만약 둘 사이의 경로가 i->t->k->j라면?
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &path) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int dist = graph[i][k] + graph[k][j];	//중간에 k를 거쳐서 i에서 j로 감 (i->k, k->j)
				//graph[i][j] = min(graph[i][j], dist);		
				if (graph[i][j] > dist) {
					graph[i][j] = dist;
					//path[i][j] = k;		//안되는 이유: 제일 먼저 이동하는 접점을 저장해야함 (i->t->k->j라면 t를 저장해야함.)
					path[i][j] = path[i][k];
				}
			}
		}
	}
}


int main() {
	int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    while (m--) {
        cin >> a >> b >> c;
		graph[a][b] = c;	//양방향
		graph[b][a] = c;

		//path 초기값
		path[a][b] = b;
		path[b][a] = a;
    }

    //연산
    floydWarshall(n, graph, path);

    //출력
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "-";
			else
				cout << path[i][j];
			cout << ' ';
		}
        cout << '\n';
    }
	return 0;
}