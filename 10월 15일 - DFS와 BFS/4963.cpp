#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//너비 우선 탐색, 깊이 우선 탐색
//모든 노드 방문, 자료구조만 제외하면 구현 방식은 동일하다

typedef pair<int, int> ci;	//row, col 저장하기 위한 pair

int dfs(vector<vector<int>> &map, int w, int h, int r, int c) {
	//대각선 + 상하좌우
	int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	stack<ci> st;
	st.push(ci(r, c));
	map[r][c] = 0;
	while (!st.empty()) {
		int cr = st.top().first, cc = st.top().second;
		st.pop();
		for (int i = 0; i < 8; i++) {		//대각선 + 상하좌우 탐색
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) {	//연결되어있고, 처음 방문하는 노드
				st.push(ci(nr, nc));		//앞으로 탐색할 노드
				map[nr][nc] = 0;			//방문 체크
			}
		}
	}
	
	return 1;
}

int bfs(vector<vector<int>> &map, int w, int h, int r, int c) {
	int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	queue<ci> q;
	q.push(ci(r, c));
	map[r][c] = 0;
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) {
				q.push(ci(nr, nc));
				map[nr][nc] = 0;
			}
		}
	}
	return 1;
}

int main() {
	while (true) {
		int w, h, cnt = 0;
		//입력
		cin >> w >> h;			//주의) 입력이 w -> h 순서로 들어온다
		if (w == 0 && h == 0)	
			break;
		vector<vector<int>> map(h, vector<int>(w));
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//연산
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1)			//떨어져 있는 섬 탐색
					cnt += dfs(map, w, h, i, j);
			}
		}

		//출력
		cout << cnt << '\n';
	}
}