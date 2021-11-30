#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;	//최대 거리보다 큰 값
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
	int dr[] = { -1, 1, 0, 0 };	//상하좌우 row 변화값
	int dc[] = { 0, 0, -1, 1 };	//상하좌우 col 변화값

	int min_dist = INF;	//최소 거리 초기화 (최대 거리보다 무조건 큰 값)
	queue<ci> q;	//상어가 갈 수 있는 곳
	vector<vector<int>> visited(n, vector<int>(n, 0));	//상어의 방문 여부
	vector<ci> list;	//상어가 먹을 수 있는 물고기들의 위치

	visited[shark.first][shark.second] = 1;	//처음 상어 위치 방문 체크
	q.push(shark);	//처음 탐색 위치 삽입
	while (!q.empty()) {	//더 이상 갈 곳이 없을 때까지
		int row = q.front().first;		//현재 탐색히려는 위치의 row
		int col = q.front().second;		//현재 탐색하려는 위치의 col
		int dist = visited[row][col];	//현재 위치까지의 거리
		q.pop();	//현재 위치는 큐에서 pop

		if (dist >= min_dist)	//최단거리 이상은 탐색할 필요 없음
			continue;
		for (int i = 0; i < 4; i++) {	//상하좌우 탐색
			int nr = row + dr[i];	//다음 탐색할 위치의 row
			int nc = col + dc[i];	//다음 탐색할 위치의 col
			if (nr < 0 || nr >= n || nc <0 || nc >= n || visited[nr][nc] || board[nr][nc]>shark_size)	//범위 밖이거나 방문했거나 물고기 크기가 상어보다 크거나 같다면 
				continue;	//탐색하지 않음

			visited[nr][nc] = visited[row][col] + 1;	//방문 체크 & 다음 탐색할 위치의 거리 저장
			if (board[nr][nc] && board[nr][nc] < shark_size) {	//먹을 수 있는 물고기 발견 (해당 위치에 물고기가 있고 상어보다 작음)
				list.emplace_back(nr, nc);	//list에 추가
				min_dist = visited[nr][nc];	//최단거리 갱신 (어차피 현재 거리가 min_dist보다 크면 탐색을 안해서 min()이 필요없는 듯)
				continue;
			}
			q.push({ nr, nc });	//다음 위치를 큐에 삽입
		}
	}

	if (list.empty())	//상어가 갈 수 있는 곳이 없음
		return { min_dist, {-1, -1} };	//min_dist = INF

	sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) {	//정렬 기준
		if (p1.first != p2.first)	//거리가 가까운 물고기가 많다면
			return p1.first < p2.first;	//가장 위에 있는 물고기부터
		return p1.second < p2.second;	//그런 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기부터
	});
	return { min_dist - 1, list[0] };	//최단 거리(처음 위치가 1이었으므로 -1), 정렬 결과 가장 가까운 물고기
}

int simulation(int n, ci &shark, vector<vector<int>> &board) {
	int ans = 0, size = 2, cnt = 0;	//최종 소요 시간, 상어 크기, 잡아먹은 물고기 개수
	while (true) {
		pair<int, ci> result = nextPos(n, size, shark, board);
		if (result.first == INF)	//더 이상 먹을 수 있는 물고기가 공간에 없음
			break;	//엄마 상어에게 도움 요청(연산 종료)
		ans += result.first;	//최단거리(=시간) 더해서 저장
		cnt++;	//현재 상어 크기에 잡아먹은 물고기 개수
		if (cnt == size) {	//상어 크기 증가 (자신의 크기와 같은 수의 물고기를 먹으면)
			cnt = 0;	//먹은 물고기 개수 초기화
			size++;		//크기 증가
		}

		//상어 이동
		ci pos = result.second;	//먹은 물고기 위치
		board[shark.first][shark.second] = 0;	//상어 위치는 0으로
		shark = pos;	//상어가 먹은 물고기 위치로 이동
	}
	return ans;	//도움 요청하면 걸리는 시간 반환
}

/*
1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
   탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복

입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
가능한 물고기의 최대 마리 수 : 399마리
최대 BFS 탐색 횟수: 399회, 1회 탐색마다 while문은 최대 400회 미만으로 순회
총 연산 횟수 약 160000번으로 충분히 가능
*/

int main() {
	int n;
	ci shark_pos;

	//입력
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) shark_pos = { i, j };
		}
	}

	//연산 & 출력
	cout << simulation(n, shark_pos, board);
}