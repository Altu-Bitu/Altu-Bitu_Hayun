#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//구현,자료 구조, 시뮬레이션, 덱, 큐 활용
//dir 변환 정보를 어떻게 저장할지 구현하는 것에 어려움을 겪었는데(dir를 int 배열로, cmd마다 하나하나 switch문?, 이동은 어떻게 해야할지 고민했음) pair 배열을 이용해 간단하게 구현하셨다..!
//cmd를 map에 저장하여 방향 변환(D, L)을 time(키값)으로 가져오도록 구현하셨다.
//board 2차원 배열에 사과 정보(2), 뱀의 위치 정보(1)를 한 번에 담아서 구현하셨다.

ci dir[4] = { {0, 1},	//우 (col 한칸 앞으로)
			  {-1, 0},	//상	 (row 한칸 뒤로)
			  {0, -1},	//좌 (col 한칸 뒤로)
			  {1, 0} };	//하 (row 한칸 앞으로)

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
	//뱀 초기화
	deque<ci> snake;	//뱀이 위치한 칸 정보
	snake.push_front(ci(0, 0));	//시작 시 맨위 맨좌측에 위치
	board[0][0] = 1;	//board 칸에 뱀이 위치할 때 1로 변경

	int t = 0, head = 0; //시간, 뱀의 머리 방향 (시작 시 오른쪽 방향으로 전진)
	while (true) {
		t++;
		//뱀의 머리가 위치하게 될 칸
		int nr = snake.front().first + dir[head].first;		//다음 행: 현재 head의 행 + dir의 row만큼 이동
		int nc = snake.front().second + dir[head].second;	//다음 열: 현재 head의 열 + dir의 col만큼 이동

		//게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)	 //다음 행이 상, 하로 이동 불가 || 다음 열이 좌, 우로 이동 불가, 다음 이동할 칸이 이미 1로 채워짐
			break;

		if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
			board[snake.back().first][snake.back().second] = 0;	//꼬리가 있는 칸을 1 -> 0로 변경
			snake.pop_back();	//덱의 back에서 꼬리 삭제
		}

		//뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
		snake.push_front(ci(nr, nc));	//덱의 front에 머리 추가
		board[nr][nc] = 1;	//해당 칸 1로 변경

		//이번에 방향을 변환하는지 확인 (x초가 끝난 뒤에 회전하므로 t++ 이후에 작성)
		if (cmd[t] == 'L')	//왼쪽 회전
			head = (head + 1) % 4;	//우->상, 상->좌, 좌->하, 하->우
		if (cmd[t] == 'D')	//오른쪽 회전
			head = (head + 3) % 4;	//우->하, 상->우, 좌->상, 하->좌
	}
	return t; //출력: 게임이 몇 초에 끝나는지
}

/*
0 0 1
0 2 1
0 0 1

편의를 위해 문제와 달리 (0, 0)부터 시작

보드의 상태가 위와 같을 때
뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
-> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
-> 덱의 front: 머리, 덱의 back: 꼬리

원활한 방향 변환을 위해 dir 배열 사용
*/

int main() {
	int n, k, row, col, l, x;
	char c;

	//입력
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		board[row - 1][col - 1] = 2; //사과 표시 (인덱스는 0부터)
	}
	cin >> l;
	map<int, char> cmd; //뱀의 방향 변환 정보
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		cmd[x] = c;
	}
	
	//연산 & 출력
	cout << playGame(n, board, cmd);
}