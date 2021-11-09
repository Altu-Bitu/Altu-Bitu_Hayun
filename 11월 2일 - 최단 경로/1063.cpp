#include <iostream>
#include <vector>
#include <string>

using namespace std;

int king_r, king_c, rock_r, rock_c, n;

//R, L, B, T, RT, LT, RB, LB
int dr[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int dir(string move) {
	if (move == "R")
		return 0;
	if (move == "L")
		return 1;
	if (move == "B")
		return 2;
	if (move == "T")
		return 3;
	if (move == "RT")
		return 4;
	if (move == "LT")
		return 5;
	if (move == "RB")
		return 6;
	if (move == "LB")
		return 7;
}

void move(vector<string> moves) {
	for (int i = 0; i < n; i++) {
		int nr = king_r + dr[dir(moves[i])];
		int nc = king_c + dc[dir(moves[i])];

		if (nr < 1 || nr > 8 || nc < 1 || nc > 8)	//킹이 움질일 수 있는지 확인
			continue;

		if (nr == rock_r && nc == rock_c) {			//돌도 움직여야하는지 확인
			int rock_nr = rock_r + dr[dir(moves[i])];
			int rock_nc = rock_c + dc[dir(moves[i])];
			if (rock_nr < 1 || rock_nr > 8 || rock_nc < 1 || rock_nc > 8)	//돌이 움직일 수 있는지 확인 (못한다면 건너뛰기)
				continue;
			else {
				rock_r = rock_nr;
				rock_c = rock_nc;
			}
		}
		king_r = nr;
		king_c = nc;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	//입력
	char c;
	cin >> c >> king_r;
	king_c = c - 'A' + 1;
	cin >> c >> rock_r;
	rock_c = c - 'A' + 1;
	cin >> n;

	vector<string> moves(n);
	for (int i = 0; i < n; i++)
		cin >> moves[i];
	
	//연산
	move(moves);
	
	//출력
	cout << char(king_c + 'A' - 1) << king_r << '\n';
	cout << char(rock_c + 'A' - 1) << rock_r << '\n';
}