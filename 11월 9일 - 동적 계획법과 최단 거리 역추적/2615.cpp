#include <iostream>
#include <vector>

using namespace std;

//브루트포스 알고리즘
//틀렸습니다. 코드의 방향성이 맞는지도 모르겠고 여섯 알 이상이 되는 경우를 어떻게 알 수 있는지도 모르겠다.

typedef pair<int, int> ci;

// 오른쪽 아래 방향, 아래 방향, 오른쪽 방향
int dx[] = { 1, 1, 0 };
int dy[] = { 1, 0, 1 };

vector<vector<int>> board(19, vector<int>(19));		//바둑판

ci find_left(ci left, int color) {		//이전에 탐색한 위치 다음으로 등장하는 바둑알 -> 왼쪽에 있는 바둑알
	bool flag = false;
	for (int i = left.first; i < 19; i++) {
		for (int j = left.second; j < 19; j++) {
			if (i == left.first && j == left.second)	//이전에 탐색한 바둑알은 패스
				continue;
			if (!flag && board[i][j] == color) {
				flag = true;
				return { i, j };
			}
		}
	}
	return { -1, -1 };
}

bool check_five(ci left, int color) {	//오목인지 확인하는 함수
	int cnt[3] = { 0, };
	ci save = left;
	for (int i = 0; i < 3; i++) {	//오른쪽 아래, 아래, 오른쪽 방향으로 탐색
		left = save;
		while (true) {
			if (board[left.first + dx[i]][left.second + dy[i]] == color) {
				left = { left.first + dx[i] , left.second + dy[i] };
				cnt[i]++;
			}
			else
				break;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (cnt[i] == 4)	//오목 완성
			return true;
	}
	return false;
}


int main() {

	bool b_flag = false, w_flag = false;
	ci ball[2];	//처음으로 등장하는 바둑알 저장

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];

			if (!b_flag && board[i][j] == 1) {
				b_flag = true;
				ball[0] = { i, j };
			}

			if (!w_flag && board[i][j] == 2) {
				w_flag = true;
				ball[1] = { i, j };
			}
		}
	}
	
	for (int i = 1; i <= 2; i++) {	//검은 색, 흰 색 차례로
		ci left = ball[i - 1];		//처음 등장한 바둑알
		while (left.first > 0) {	//더 이상 탐색할 바둑알이 없다면
			if (check_five(left, i)) {	//오목 완성
				cout << i << '\n' << left.first + 1 << " " << left.second + 1;
				return 0;
			}
			left = find_left(left, i);	//다음 바둑알 탐색
		}
	}

	cout << "0";
	return 0;
}