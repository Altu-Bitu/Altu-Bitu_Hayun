#include <iostream>
#include <vector>

using namespace std;

//브루트포스 알고리즘

// 오른쪽 아래 방향, 아래 방향, 오른쪽 방향, 오른쪽 위 방향
int dx[] = { 1, 1, 0, -1 };
int dy[] = { 1, 0, 1, 1 };

vector<vector<int>> board(19, vector<int>(19));		//바둑판

bool check_five(int x, int y, int color) {	//오목인지 확인하는 함수
	for (int i = 0; i < 3; i++) {	//오른쪽 아래, 아래, 오른쪽 방향으로 탐색
		int cnt = 0;
		int nx = x + dx[i], ny = y + dy[i];
		while (true) {
			if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
				continue;

			if (board[nx][ny] == color) {
				cnt++;
				nx += dx[i];
				ny += dy[i];
			}
			else
				break;
		}
		if (cnt == 4)
			return true;
	}
	return false;
}


int main() {
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] > 0 && check_five(i, j, board[i][j])) {
				cout << board[i][j] << '\n';
				cout << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	}
	cout << "0";
	return 0;
}