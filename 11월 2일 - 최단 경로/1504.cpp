#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//다익스트라

typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

vector<int> dijkstra(int vertex, int start, vector<vector<ci>> &graph) {	//변수: 정점 개수, 시작점, 그래프
	vector<int> dist(vertex + 1, INF);	//정점까지의 최단 거리 저장 배열 (모든 정점까지의 거리를 INF로 초기화)
	priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점 (최단 거리므로 greater<>)

	//시작 위치 초기화
	dist[start] = 0;	//시작 정점까지의 거리는 0
	pq.push({ 0, start });	//거리 0과 시작 정점 삽입

	while (!pq.empty()) {	//갱신할 정점이 있을 때까지
		int weight = pq.top().first;	//시작정점에서 정점까지의 거리
		int node = pq.top().second;		//탐색하지 않은 정점 중 시작점에서 가장 가까운 정점
		pq.pop();	//우선순위 큐에서 해당 정점을 pop

		if (weight > dist[node]) //이미 확인했던 정점 (중복 처리)
			continue;	//다음 정점 탐색

		for (int i = 0; i < graph[node].size(); i++) {	//node와 연결된 모든 정점에 대해
			int next_node = graph[node][i].first; //연결된 정점
			int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리

			if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
				dist[next_node] = next_weight;		//더 짧은 거리로 갱신
				pq.push({ next_weight, next_node });	//우선순위 큐에 삽입
			}
		}
	}
	return dist;	//최단 거리 배열 반환
}

/*
 가능한 경로
 1. 1 -> v1 -> v2 -> n
 2. 1 -> v2 -> v1 -> n
 -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 
 !주의!
 1. 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 2. 출력에서 (ans == 3*INF)을 하지 않고 INF을 3*INF 값으로 초기화 하는 이유
	조건에 의하면 E의 값이 0일 수도 있음. 이 경우에선 1->1->N->N의 값이 INF이라 경로가 없음에도 3*INF 조건에 걸리지 않음.
    INF을 3*INF으로 초기화하면 해결 가능
 */
int main() {
	int n, e, a, b, c, v1, v2;	//정점의 개수, 간선의 개수, a 정점, b 정점, a와 b의 거리, 반드시 거쳐야 하는 서로 다른 두 정점

	//입력
	cin >> n >> e;

	vector<vector<ci>> graph(n + 1, vector<ci>(0));		//그래프
	vector<vector<int>> dist(3, vector<int>(n + 1, 0));	//최단 거리 배열, 시작점 3개로 기존 dist 배열을 3번 저장함.
	while (e--) { //무방향 그래프
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);	//a->b, 거리 그래프에 삽입
		graph[b].emplace_back(a, c);	//b->a, 거리 그래프에 삽입
	}
	cin >> v1 >> v2;

	//연산
	vector<int> start_nodes = { 1, v1, v2 };	//1, v1, v2를 시작점으로 함
	for (int i = 0; i < 3; i++) //1, v1, v2에서 시작한 다익스트라 결과 저장
		dist[i] = dijkstra(n, start_nodes[i], graph);	//각 시작점에 대해 최단 거리 계산

	//1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
	//무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값이다
	int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

	//출력
	cout << ((ans >= INF) ? -1 : ans);	//최단 경로가 없을 때는 -1 출력
}