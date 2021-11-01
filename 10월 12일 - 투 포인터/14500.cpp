#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구현

int n, m, max_sum = 0;
int paper[500][500];
int visited[500][500];

//상하좌우
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dfsRecur(int cnt, int sum, int cr, int cc) {	//보라색 이외 블록은 연속으로 탐색 가능
	if (cnt == 4) {	//4개면 테트로미노 완성
		max_sum = max(max_sum, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = cr + dr[i];
		int nc = cc + dc[i];
		if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] == 0) {
			visited[nr][nc] = 1;
			dfsRecur(cnt + 1, sum + paper[nr][nc], nr, nc);
			visited[nr][nc] = 0;
		}
	}
}

void purple(int cr, int cc) {	//보라색은 연속으로 탐색 불가능하므로 따로 처리
	int sum = 0;
	if (cc + 2 < m) {	//ㅗ, ㅜ 가능한지 확인
		sum = paper[cr][cc] + paper[cr][cc + 1] + paper[cr][cc + 2];
		if (cr - 1 >= 0)	//ㅗ 가능
			max_sum = max(max_sum, sum + paper[cr - 1][cc + 1]);
		if (cr + 1 < n)		//ㅜ 가능
			max_sum = max(max_sum, sum + paper[cr + 1][cc + 1]);
	}
	if (cr + 2 < n) {	//ㅓ, ㅏ 가능한지 확인
		sum = paper[cr][cc] + paper[cr + 1][cc] + paper[cr + 2][cc];
		if (cc - 1 >= 0)	//ㅓ 가능
			max_sum = max(max_sum, sum + paper[cr + 1][cc - 1]);
		if (cc + 1 < m)		//ㅏ 가능
			max_sum = max(max_sum, sum + paper[cr + 1][cc + 1]);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfsRecur(1, paper[i][j], i, j);
			visited[i][j] = 0;

			purple(i, j);
		}
	}

	cout << max_sum;
}