#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<vector<int>> parent;

//Find 연산
int findParent(int m, int row, int col) {
	if (parent[row][col] < 0)	//루트 정점
		return row * m + col;	//좌표 정보를 int 값 하나로
	int pos = parent[row][col];
	return parent[row][col] = findParent(m, pos / m, pos % m);	//그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int m, int r1, int c1, int r2, int c2) {	//현재 행, 현재 좌표, 유니온 될 좌표
	int xp = findParent(m, r1, c1);	//현재 좌표가 속한 집합의 루트 정점
	int yp = findParent(m, r2, c2);	//유니온 될 좌표가 속한 집합의 루트 정점
	int xr = xp / m, xc = xp % m;	//루트 정점 -> 좌표값으로
	int yr = yp / m, yc = yp % m;	//루트 정점 -> 좌표값으로

	if (xp == yp)	//이미 같은 집합에 있다면 유니온 할 수 없음
		return;
	if (parent[xr][xc] < parent[yr][yc]) {	//새로운 루트 xp로 union
		parent[xr][xc] += parent[yr][yc];	//xp의 값에 yp의 값 더함 (음수)
		parent[yr][yc] = xp;				//yp의 루트를 xp로
	}
	else {	//새로운 루트 yp로 union
		parent[yr][yc] += parent[xr][xc];	//yp의 값에 xp의 값 더함 (음수)
		parent[xr][xc] = yp;				//xp의 루트를 yp로
	}
}

void unionPair(int n, int m, vector<vector<char>> &board) {
	map<char, pair<int, int>> dir;	//맵을 이용해 각 문자를 방향에 대입
	dir['U'] = { -1, 0 };	//위로 이동
	dir['D'] = { 1, 0 };	//아래로 이동
	dir['L'] = { 0, -1 };	//왼쪽으로 이동
	dir['R'] = { 0, 1 };	//오른쪽으로 이동

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pair<int, int> d = dir[board[i][j]];	//유니온 될 좌표가 있는 방향
			unionInput(m, i, j, i + d.first, j + d.second);	//현재 행, 현재 좌표와 유니온 될 좌표를 유니온하기
		}
	}
}


int cntZone(int n, int m) {	//루트 정점 개수 세기
	int cnt = 0;	//집합 개수 = 루트 정점 개수 변수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (parent[i][j] < 0)	//루트 정점이라면	
				cnt++;	//증가
		}
	}
}
/*
1. 화살표를 통해 접근할 수 있는 좌표 = 하나의 집합으로 연결된 좌표
2. 같은 집합 안에 속해있는 좌표들은 모두 언젠가 방문 가능한 좌표
3. 서로소인 각 집합에서 한 개씩의 좌표만 SAFE ZONE이어도 모든 회원들이 안전할 수 있음
4. 2차원 좌표를 int 값 하나로 저장하기 위해 모든 행을 일렬로 나열하는 방법 사용 (각 좌표에 pair 변수를 저장해 부모를 표시할 수도 있음)
*/

int main() {
	int n, m;
	string input;

	//입력
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));	//지도 정보 저장하는 배열
	parent.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++)
			board[i][j] = input[j];
	}

	//연산
	unionPair(n, m, board);	//방향 정보에 따라 좌표들 유니온하기

	//출력
	cout << cntZone(n, m);	//집합의 개수 = 루트 정점의 개수 세고 출력
}