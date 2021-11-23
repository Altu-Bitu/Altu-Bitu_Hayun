#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int n, m;

//북 동 남 서
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int result = 0;

void clean(int r, int c, int d) {	//로봇 청소기 있는 칸부터

	while (true) {
		if (board[r][c] == 0) {	//현 위치 청소 (1)
			board[r][c] = 2;
			result++;
		}

		bool check = false;
		for (int i = 0; i < 4; i++) {	//네 방향 체크
			d = (d + 3) % 4;	//현재 방향에서 왼쪽 방향으로 (2-a, b)
			int nr = r + dr[d];	//다음 칸 확인용 변수
			int nc = c + dc[d];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m)	//범위 내 체크
				continue;

			if (board[nr][nc] == 0) {	//다음 칸이 청소되어있지 않다면 (2-a)
				r = nr; c = nc;		//다음 칸으로 전진
				check = true;		
				break;				//1번부터
			}
		}

		if (check) {	//네 방향 모두 청소된 경우가 아니라면 2번으로
			continue;
		}

		else {	//네 방향 모두 청소되어있다면 (2-c, d)
			int nr = r - dr[d];	
			int nc = c - dc[d];
			if (board[nr][nc] == 1)	//뒤쪽이 벽이라면 (2-d)
				return;	//작동 그만
			else {	//후진하고 2번으로 (2-c)
				r = nr;	c = nc;
			}
		}
	}
}

int main() {
	int r, c, d;
	//입력
	cin >> n >> m >> r >> c >> d;
	board.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	//연산
	clean(r, c, d);

	//출력
	cout << result;

	return 0;
}