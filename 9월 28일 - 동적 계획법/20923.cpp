#include <iostream>
#include <queue>
using namespace std;

//구현, 자료 구조, 시뮬레이션, 덱 활용
//푸는데 시간이 너무 오래 걸린다

void halligalli(deque<int> &do_deque, deque<int> &su_deque, int m) {
	int rounds = 1;
	deque<int> do_ground, su_ground;
	while (rounds <= m) {	//m번 진행 후 종료
		//2 도도를 시작으로 차례대로 그라운드에 자신이 가진 덱에서 가장 위에 위치한 카드를 내려놓는다.
		if (rounds % 2 == 1) {
			do_ground.push_front(do_deque.front());
			do_deque.pop_front();
		}
		else {
			su_ground.push_front(su_deque.front());
			su_deque.pop_front();
		}
		//진행 도중 종료 조건: 자신의 덱에 있는 카드의 수가 0개가 되는 즉시
		if (do_deque.empty() || su_deque.empty())
			break;

		//3+4 종을 먼저 치는 사람이 그라운드에 나와 있는 카드 더미를 모두 가져갈 수 있다
		if ((!do_ground.empty() && do_ground.front() == 5) || (!su_ground.empty() && su_ground.front() == 5)) { //도도가 종 치는 조건
			while (!su_ground.empty()) {	//상대의 그라운드 카드 합치기
				do_deque.push_back(su_ground.back());
				su_ground.pop_back();
			}
			while (!do_ground.empty()) {	//자신의 그라운드 카드 합치기
				do_deque.push_back(do_ground.back());
				do_ground.pop_back();
			}
		}
		if (!su_ground.empty() && !do_ground.empty() && do_ground.front() + su_ground.front() == 5) { //수연이가 종 치는 조건
			while (!do_ground.empty()) {	//상대의 그라운드 카드 합치기
				su_deque.push_back(do_ground.back());
				do_ground.pop_back();
			}
			while (!su_ground.empty()) {	//자신의 그라운드 카드 합치기
				su_deque.push_back(su_ground.back());
				su_ground.pop_back();
			}
		}
		rounds++;
	}
}

int main() {
	int n, m;
	//입력
	cin >> n >> m;
	deque<int> do_deque, su_deque;
	int do_temp, su_temp;
	while (n--) {
		cin >> do_temp >> su_temp;
		do_deque.push_front(do_temp);
		su_deque.push_front(su_temp);
	}

	//연산
	halligalli(do_deque, su_deque, m);
	if (do_deque.size() > su_deque.size())
		cout << "do";
	else if (do_deque.size() < su_deque.size())
		cout << "su";
	else
		cout << "dosu";
}