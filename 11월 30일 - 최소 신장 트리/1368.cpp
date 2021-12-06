#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//MST (프림)

const double INF = 1e5 + 1;
typedef pair<int, int> ci;

int prim(int v, int start, vector<vector<ci>> &graph) {
	int sum = 0;
	vector<int> dist(v, INF);		//각 정점까지의 비용
	vector<bool> visited(v, false); //정점 방문 여부
	priority_queue<ci, vector<ci>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int weight = pq.top().first; //간선 가중치
		int node = pq.top().second; //현재 정점
		pq.pop();

		if (visited[node])
			continue;

		sum += weight; //MST 간선 가중치 총합
		visited[node] = true; //방문 처리

		for (int i = 0; i < graph[node].size(); i++) {
			int next_weight = graph[node][i].first;
			int next_node = graph[node][i].second;
			if (!visited[next_node] && next_weight < dist[next_node]) { //미방문 정점 & 더 짧은 간선
				dist[next_node] = next_weight;
				pq.push({ dist[next_node], next_node });
			}
		}
	}
	return sum;
}

int main() {
	int n, w, p;

	//입력
	cin >> n;

	vector<vector<ci>> graph(n + 1, vector<ci>(0));
	for (int i = 1; i <= n; i++){
		cin >> w;
		graph[0].emplace_back(w, i);
		graph[i].emplace_back(w, 0);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> p;
			if (i != j)
				graph[i].emplace_back(p, j);
		}
	}


	//연산 & 출력
	cout << prim(n + 1, 0, graph);
}