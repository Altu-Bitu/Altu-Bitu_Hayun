#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//다익스트라

typedef pair<int, int> ci;
const int INF = 1e5; //최대 n-1개의 간선을 지나게 됨

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph) {	//변수: 정점 개수, 시작점, 그래프, 반환: 최단 시간 배열
	vector<int> dist(n + 1, INF); //정점까지의 최단 시간 저장 배열 (모든 정점까지의 시간을 INF로 초기화)
	
	priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터 소요시간, second : 정점 (최단 시간이므로 greater<>)

	//시작 위치 초기화
	dist[start] = 0;	//시작 정점까지의 시간 0으로 초기화
	pq.push({ 0, start });	//소요시간 0과 시작 정점 삽입

	while (!pq.empty()) {	//갱신할 정점이 있을 때까지
		int t = pq.top().first;		//시작 정점에서 정점까지의 소요시간
		int node = pq.top().second;	//탐색하지 않은 정점 중 시작점에서 가장 가까운 정점
		pq.pop();	//우선순위 큐에서 해당 정점을 pop

		if (t > dist[node]) //이미 더 짧은 경로가 존재한다면 (어차피 큐에 들어가지 못함, 중복)
			continue;		//다음 정점 탐색

		for (int i = 0; i < graph[node].size(); i++) {	//node와 연결된 모든 정점에 대해
			int next_node = graph[node][i].first; //node와 연결된 정점
			int next_t = t + graph[node][i].second; //시작점으로부터 연결된 정점까지의 소요시간
			if (dist[next_node] > next_t) { //더 짧은 시간에 갈 수 있다면
				dist[next_node] = next_t;	//더 짧은 시간으로 갱신
				pq.push({ next_t, next_node });	//우선순위 큐에 삽입
			}
		}
	}
	return dist;	//최단 시간 배열 반환
}

/*
 1. 각 학생들이 X를 가는 데 걸리는 최단 시간 (i -> x)
 2. X에서 다시 돌아오는 데 걸리는 최단 시간 (x -> i)
 
 우선 단방향 그래프이므로 위의 2개 값은 다를 수 있어 따로 구해주어야 함
 2번은 시작점이 X인 다익스트라로 무난히 구현
 1번은 역뱡향 그래프에서 시작점이 X인 다익스트라로 구현 -> 역방향을 다시 원상태로 돌리면 결국 도착점이 X가 됨 (4ms)

 해당 문제는 N이 크지 않아 1번도 시작점이 i인 다익스트라를 N번 또는 1번 2번을 통틀어 조금 더 효율적인 플로이드-워셜로 구현 가능 (220ms)
 */

int main() {
	int n, m, x, a, b, c, ans = 0;

	//입력
	cin >> n >> m >> x;
	vector<vector<ci>> graph(n + 1, vector<ci>());		//단방향 그래프
	vector<vector<ci>> rev_graph(n + 1, vector<ci>());	//역방향 그래프
	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c }); //단방향 그래프에 정점과 시간 삽입
		rev_graph[b].push_back({ a, c }); //역방향 그래프에 정점과 시간 삽입
	}

	//연산
	vector<int> dist_go = dijkstra(n, x, rev_graph); //역방향 그래프에서 시작점이 x인 모든 정점의 최단 시간
	vector<int> dist_back = dijkstra(n, x, graph); //시작점이 x인 모든 정점의 최단 시간
	for (int i = 1; i <= n; i++)	//N명의 학생들 중
		ans = max(dist_go[i] + dist_back[i], ans);	//가장 오래 걸리는 학생의 소요시간

	//출력
	cout << ans << '\n';
	return 0;
}