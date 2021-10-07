#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 그리디 알고리즘

typedef struct{
	int sender;
	int receiver;
	int box;
} delivery;

bool cmp(delivery a, delivery b) {	//받는 마을의 번호 오름차순으로
	if (a.receiver != b.receiver)
		return a.receiver < b.receiver;
	return a.sender > b.sender;
}

int main() {
	//  박스는 '일부'만 실어도 괜찮네요! 트럭의 용량을 충분히 확보하려면 어떤 박스를 먼저 실어야 할까요? 그리고 현재 운반하는 박스의 양이 얼만지 어떻게 관리하면 좋을까요?
	int n, c, m;
	cin >> n >> c >> m;
	vector<delivery> del(m);
	for (int i = 0; i < m; i++)
		cin >> del[i].sender >> del[i].receiver >> del[i].box;

	sort(del.begin(), del.end(), cmp);

	vector<int> capa(n);
	for (int i = 1; i < n; i++) {
		capa[i] = c;
	}

	int maxBox = 0;
	for (int i = 0; i < m; i++) {
		int min_capa = c;
		for (int j = del[i].sender; j < del[i].receiver; j++) {
			if (capa[j] < del[i].box) {	//보내는 마을부터 받는 마을 직전까지의 용량 확인
				min_capa = min(min_capa, capa[j]);
			}
		}
		if (min_capa == c)	//보내는 마을부터 받는 마을 직전까지의 용량이 모두 현재 보내려는 박스 양보다 많다면 박스 양만큼 배달
			min_capa = del[i].box;

		//보내는 마을부터 받는 마을 직전까지의 용량이 가장 작은 양만큼만 배달하기
		maxBox += min_capa;
		for (int j = del[i].sender; j < del[i].receiver; j++) {
			capa[j] -= min_capa;
		}
	}

	cout << maxBox;
}