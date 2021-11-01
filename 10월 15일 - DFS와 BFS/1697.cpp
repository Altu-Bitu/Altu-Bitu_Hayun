#include <iostream>
#include <queue>

using namespace std;

//너비 우선 탐색
//두 노드 사이 최단 거리 -> BFS

int bfs(queue<int> q, int n, int k) {
	vector<int> visited(100000, 0);	//방문 노드 체크 (몇번째 방문인지 저장)
	
	q.push(n);		//처음 탐색 노드 삽입
	visited[n] = 1;	//방문 체크

	while (q.front() != k) {	//동생 위치를 찾을 때까지
		int node = q.front();	//현재 탐색하려는 노드
		q.pop();
		if (node - 1 >= 0 && visited[node-1] == 0) {	//수빈이 위치 - 1 조건 확인 후 방문
			q.push(node - 1);
			visited[node - 1] = visited[node] + 1;		//현재까지 걸린 시간 + 1
		}
		if (node + 1 <= 100000 && visited[node + 1] == 0) {	//수빈이 위치 + 1 조건 확인 후 방문
			q.push(node + 1);
			visited[node + 1] = visited[node] + 1;
		}
		if (node * 2 <= 100000 && visited[node * 2] == 0) {	//수빈이 위치 * 2 조건 확인 후 방문
			q.push(node * 2);	
			visited[node * 2] = visited[node] + 1;
		}
	}

	return visited[k] - 1;	//수빈이 위치 노드를 1초로 시작해서 - 1
}

int main() {
	int n, k;
	//입력
	cin >> n>> k;

	queue<int> q;	//BFS는 큐 이용
	
	//연산 & 출력
	cout << bfs(q, n, k);
}