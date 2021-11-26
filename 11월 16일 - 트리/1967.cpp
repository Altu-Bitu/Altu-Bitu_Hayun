#include <iostream>
#include <vector>

using namespace std;

//그래프 탐색, 트리, 깊이 우선 탐색
//트리 -> 무방향 그래프로 저장
//재귀 함수 dfs 연습

typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {	//깊이 우선 탐색 (가중치, 특정 경로)
	int pos = node, len = 0;	//지름을 구성하는 노드 중 하나, 그 노드까지의 거리
	for (int i = 0; i < graph[node].size(); i++) {	//node와 연결된 다른 노드들 
		int next_node = graph[node][i].first;	//다음 탐색할 노드의 인덱스
		if (next_node == parent)	//부모 인덱스라면 패스 (방향 유지)
			continue;

		ci dfs_search = dfs(next_node, node, graph);	//다음 노드 탐색 (부모 인덱스는 현재 노드)
		if (graph[node][i].second + dfs_search.first > len) {	//현재 노드의 가중치 + 탐색한 경로의 총 가중치 합이 len보다 크면
			len = graph[node][i].second + dfs_search.first;	//해당 값으로 업데이트
			pos = dfs_search.second;	//해당 리프 노드 저장 -> dfs return해서 값을 유지하도록
		}
	}
	return { len, pos };	//최강 거리와 해당 리프 노드를 리턴
}

/*
1. 지름을 이루는 두 점은 모두 리프 노드
2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드

부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
*/

int main() {
	int n, a, b, c;
	
	//입력
	cin >> n;
	vector<vector<ci>> graph(n + 1, vector<ci>());
	for (int i = 0; i < n - 1; i++) {	//무방향 그래프로 만들기
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });	//부모 인덱스에 자식, 가중치 삽입
		graph[b].push_back({ a, c });	//자식 인덱스에 부모, 가중치 삽입
	}

	//연산
	ci first_node = dfs(1, -1, graph);	//루트에서 가장 거리가 먼 노드를 찾음
	ci second_node = dfs(first_node.second, -1, graph);	//first_node에서 가장 거리가 먼 노드를 찾음

	//출력
	cout << second_node.first;	//트리의 지름 (모든 경로 중 가장 긴 것)
}