#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
const int SIZE = 100 + 1; //격자 사이즈

//우, 상, 좌, 하 -> 시계 방향으로 90도 회전하는 방향 순서
int dy[4] = { 0, -1, 0, 1 };	//y좌표의 변화값
int dx[4] = { 1, 0, -1, 0 };	//x좌표의 변화값

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 구하기
int cntSquare(vector<vector<bool>> &board) {	//모든 드래곤 커브를 그리고 나서 정사각형 개수 세는 함수
	int ans = 0;	//정사각형 개수를 저장할 ans
	for (int i = 0; i < SIZE - 1; i++) {	//row를 격자사이즈 - 1만큼 (다음 인덱스를 탐색해야하므로 -1)
		for (int j = 0; j < SIZE - 1; j++) {	//col을 격자사이즈 - 1만큼 
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])	//지금 위치, 오른쪽, 아래쪽, 오른쪽 아래가 1이면 모든 꼭지점이 1인 정사각형
				ans++;
		}
	}
	return ans;
}

ci makeDragonCurve(vector<vector<bool>> &board, vector<int> &direc, ci point) {	//이전 세대들의 방향을 거꾸로 순회하며 새로운 방향으로 그려나가는 함수
	int size = direc.size();//그 전 세대까지의 방향 정보의 개수
	for (int i = size - 1; i >= 0; i--) {	//이전 세대의 방향을 거꾸로 순회하며 새로운 방향을 추가함
		int new_direc = (direc[i] + 1) % 4; //새로 그리는 방향 (이전 세대의 방향에서 90도 회전)
		point = { point.first + dy[new_direc], point.second + dx[new_direc] }; //현재 끝 점 = 그 전 끝점(point) + 새로 그리는 방향의 변화값
		board[point.first][point.second] = true;	//드래곤커브를 그렸으므로 true로 초기화
		direc.push_back(new_direc);	//새로 그린 방향을 삽입
	}
	return point;	//이번 세대의 최종 끝 점
}

/*
x: 열, y: 행

드래곤 커브 = 선분들로 이루어짐
=> 각 선분들의 방향을 저장해서 드래곤 커브의 자푯값을 구해나가자

드래곤 커브는 각 세대마다 끝 점을 기준으로 시계 방향으로 90도 회전
-> 드래곤 커브 세대의 각 선분 방향 = 전 세대 방향들에서 차례로 끝 점을 기준으로 시계 방향으로 이동한 것과 같음
-> (우(0) -> 상(1), 상(1) -> 좌(2), 좌(2) -> 하(3), 하(3) -> 우(0))로 이동
ex)	0세대: 우
	1세대: 상
	2제대: 좌 상 (1세대 + 0세대의 상, 우에서 각각 시계방향 이동)
	3세대: 좌 하 좌 상 (2세대 + 1세대 + 0세대에서 각각 시계방향 이동)

0세대는 이미 방향이 주어지므로 먼저 처리
드래곤커브는 격자 밖으로 나가지 않음 -> 범위 검사 필요 x

(어차피 선분은 길이가 1이므로 선분을 그릴 필요 없이 방향만 알면 드래곤커브를 그릴 수 있다)

*/


int main() {
	int n, x, y, d, g;

	//입력 & 연산
	cin >> n;	//드래곤 커브의 개수 입력
	vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 격자

	while (n--) {	//드래곤 커브의 개수만큼 각각 그려나감
		cin >> x >> y >> d >> g;	//x, y: 드래곤커브의 시작점, d: 시작 방향, g: 세대
		vector<int> direc;			//세대의 방향 정보 저장 및 보존하는 벡터
		ci end_point = { y + dy[d], x + dx[d] };	//0세대 끝점: 시작점 + 시작 방향의 변화값
		board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 끝점 초기화 (y를 row, x를 col으로 생각한다)
		direc.push_back(d);		//0세대 방향 삽입
		while (g--) {			//각 세대마다 드래곤 커브 만들기
			end_point = makeDragonCurve(board, direc, end_point);	//변수: 격자(각 점이 드래곤커브인지), direc(이전세대까지의 방향 정보), end_point(이전 세대의 끝점)
		}
	}

	//출력
	cout << cntSquare(board) << '\n';	//모든 꼭지점이 1인 정사각형 개수
	return 0;
}