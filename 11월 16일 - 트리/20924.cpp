#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

ci bfs(int n, int r, vector<vector<ci>> &tree) {	//first: 기둥의 길이, second: 가장 긴 가지의 길이
	queue<int> q;	//bfs를 위한 큐 생성
	vector<int> visited(n + 1, -1);	//방문 여부 + 길이 저장
	int trunk_len = -1, max_branch = 0, len = 0;	//기둥의 길이, 가장 긴 가지의 길이, 탐색 중인 가지의 길이

	//루트 노드 초기화
	q.push(r); //큐에 루트 노드 삽입
	visited[r] = 0; //루트 노드 방문 체크 + 길이 0
	if (tree[r].size() >= 2)	//루트가 자식이 2개 이상이라면	 기가 노드
		trunk_len = 0;			//기둥의 길이는 0

	while (!q.empty()) {
		int node = q.front();	//현재 탐색하려는 노드
		q.pop();	//큐에서 해당 노드 pop

		len = visited[node];	//현재 탐색 노드까지의 길이 
		if (trunk_len != -1)	//기둥의 길이가 존재한다면 (현재 노드는 가지에 해당)
			max_branch = max(max_branch, len);	//가장 긴 가지의 길이 갱신
		else if (tree[node].size() > 2) {	//기가 노드 발견
			trunk_len = len;	//기둥의 길이 저장
			len = 0;			//len 초기화
		}

		for (int i = 0; i < tree[node].size(); i++) {	//현재 노드와 연결된 노드들
			int next_node = tree[node][i].first;	//다음 탐색할 노드
			if (visited[next_node] != -1)	//방문했던 노드라면 패스
				continue;
			q.push(next_node);	//다음 탐색할 노드를 큐에 삽입
			visited[next_node] = len + tree[node][i].second;	//다음 노드 길이 업데이트 (현재 노드와 간선의 길이의 합)
		}
	}

	if (trunk_len == -1)	//리프 노드가 기가 노드일 경우
		trunk_len = len;	//가지는 없음, len이 기둥의 길이
	return { trunk_len, max_branch };	//기둥의 길이와 가장 긴 가지의 길이를 리턴

}


/*
BFS 풀이

visited: 방문 여부 + 길이 저장 (-1: 방문 안한 상태)

기가 노드: 3개 이상의 노드와 연결된 정점 (단, 루트 노드는 2개 이상 (자식 2개) 연결된 경우 기가 노드에 해당
기둥: BFS 탐색을 이어나가다 기가 노드를 찾으면 지금까지 저장된 길이가 기둥의 길이
가장 긴 가지의 길이: 기가 노드를 찾은 후부터 길이를 다시 더하여 가장 긴 가지 길이 계속 갱신
*/

int main() {
	int n, r, a, b, d;

	//입력
	cin >> n >> r;
	vector<vector<ci>> tree(n + 1, vector<ci>());
	for (int i = 0; i < n - 1; i++) {	//무방향 그래프
		cin >> a >> b >> d;
		tree[a].emplace_back(b, d);
		tree[b].emplace_back(a, d);
	}

	//연산
	ci ans = bfs(n, r, tree);

	//출력
	cout << ans.first << ' ' << ans.second << '\n';	//기둥의 길이와 가장 긴 가지 길이
}