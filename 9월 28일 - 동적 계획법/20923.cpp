#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//구현, 자료 구조, 시뮬레이션, 덱 활용
//푸는데 시간이 너무 오래 걸린다

void ring(int win, vector<deque<int>> &deques, vector<deque<int>> &grounds) {	  //이기는 사람의 덱에 그라운드 카드 합치는 함수
	while (!grounds[(win + 1) % 2].empty()) {	//상대의 그라운드 카드 합치기
		deques[win].push_back(grounds[(win + 1) % 2].back());
		grounds[(win + 1) % 2].pop_back();
	}
	while (!grounds[win].empty()) {	//자신의 그라운드 카드 합치기
		deques[win].push_back(grounds[win].back());
		grounds[win].pop_back();
	}
}

void halligalli(vector<deque<int>> &deques, int m) {
	int rounds = 1;
	vector<deque<int>> grounds(2);
	while (rounds <= m) {	//m번 진행 후 종료
		//2 도도를 시작으로 차례대로 그라운드에 자신이 가진 덱에서 가장 위에 위치한 카드를 내려놓는다.
		grounds[(rounds + 1) % 2].push_front(deques[(rounds + 1) % 2].front());
		deques[(rounds + 1) % 2].pop_front();
		
		//진행 도중 종료 조건: 자신의 덱에 있는 카드의 수가 0개가 되는 즉시
		if (deques[0].empty() || deques[1].empty())
			break;

		//3+4 종을 먼저 치는 사람이 그라운드에 나와 있는 카드 더미를 모두 가져갈 수 있다
		if ((!grounds[0].empty() && grounds[0].front() == 5) || (!grounds[1].empty() && grounds[1].front() == 5)) //도도가 종 치는 조건
			ring(0, deques, grounds);
		if (!grounds[1].empty() && !grounds[0].empty() && grounds[0].front() + grounds[1].front() == 5) //수연이가 종 치는 조건
			ring(1, deques, grounds);
		rounds++;
	}
}

int main() {
	int n, m;
	//입력
	cin >> n >> m;
	vector<deque<int>> deques(2);
	int do_temp, su_temp;
	while (n--) {
		cin >> do_temp >> su_temp;
		deques[0].push_front(do_temp);
		deques[1].push_front(su_temp);
	}

	//연산
	halligalli(deques, m);
	if (deques[0].size() > deques[1].size())
		cout << "do";
	else if (deques[0].size() < deques[1].size())
		cout << "su";
	else
		cout << "dosu";
}