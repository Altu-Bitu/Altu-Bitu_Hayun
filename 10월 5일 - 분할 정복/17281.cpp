#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구현, 브루트포스 알고리즘
//시간 초과

int n;	//이닝 수
int max_score = 0;
int player[50][10];	//각 선수가 각 이닝에서 얻는 결과
vector<int> order(10);


pair<int, int> inning(int i, int hitter) {	//각 이닝 (매개변수: 첫번째 순서)
	pair<int, int> result;
	bool base[3] = { false, };	//주자 (1루, 2루, 3루)
	int score = 0;		//점수 (3루 지나쳐서 홈에 들어오면 ++)
	int out = 0;		//아웃 (아웃이면 ++, 3이면 이닝 종료)
	while (out < 3) {
		if (player[i][order[hitter]] == 0)
			out++;
		else {
			for (int j = 2; j >= 0; j--) {	//3루부터 주자 이동
				if (base[j]) {
					base[j] = false;
					if (j + player[i][order[hitter]] >= 3)
						score++;
					else
						base[j + player[i][order[hitter]]] = true;
				}
			}
			//타자 이동
			if (player[i][order[hitter]] == 4)
				score++;
			else
				base[player[i][order[hitter]] - 1] = true;
		}

		//다음 타자 선정
		if (hitter == 9)
			hitter = 1;
		else
			hitter++;
	}
	result.first = score;
	result.second = hitter;
	return result;
}

int game() {	//전체 게임
	int score = 0;
	int hitter = 1;	//현재 순서 (이닝이 변경되어도 순서 유지, 9 -> 1)
	
	for (int i = 0; i < n; i++) {
		pair<int, int> temp = inning(i, hitter);
		score += temp.first;
		hitter = temp.second;
	}
	return score;
}

void permu() {	//타순 (브루트포스 순열 검색 -> 참고: http://www.cplusplus.com/reference/algorithm/next_permutation/)
	vector<int> test(9, 0);
	for (int i = 1; i < 9; i++)
		test[i] = i + 1;	//2 ~ 9
	do {
		order = test;
		order.insert(order.begin() + 4, 1);	//4번 타자는 1번 선수로 정했다
		//게임하고 max 업데이트
		max_score = max(max_score, game());

	} while (next_permutation(test.begin() + 1, test.end()));	//2번부터 9번까지 순열 생성 -> *begin()+1으로 2번부터 순열 생성하도록

	//return max_score;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++)
			cin >> player[i][j];
	}
	//연산 & 출력
	permu();
	cout << max_score;
}