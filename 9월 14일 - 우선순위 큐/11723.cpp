#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 시간초과 주의

int main() {
	// 20개의 숫자를 입력/삭제하는게 아니라 20개에 숫자에 체크/언체크 표시를 하는거라고 생각해볼까요?
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, k;
	cin >> m;
	vector<bool> v(20, 0);
	while (m--) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			cin >> k;
			v[k-1] = 1;
		}
		if (cmd == "remove") {
			cin >> k;
			v[k-1] = 0;
		}
		if (cmd == "check") {
			cin >> k;
			if (v[k-1])
				cout << "1\n";
			else
				cout << "0\n";
		}
		if (cmd == "toggle") {
			cin >> k;
			if (v[k-1])
				v[k-1] = 0;
			else
				v[k-1] = 1;
		}
		if (cmd == "all") {
			for (int i = 0; i < 20; i++) {
				v[i] = 1;
			}
		}
		if (cmd == "empty") {
			for (int i = 0; i < 20; i++) {
				v[i] = 0;
			}
		}
	}
}