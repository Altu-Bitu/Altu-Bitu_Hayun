#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//그리디 알고리즘

int main() {
	int n;
	cin >> n;
	vector<int> stick(n);
	for (int i = 0; i < n; i++)
		cin >> stick[i];

	sort(stick.begin(), stick.end(), less<>());
	bool check = 0;
	for (int i = n - 1; i > 1; i--) {
		if (stick[i] < stick[i - 1] + stick[i - 2]) {	//삼각형 조건 확인
			cout << stick[i] + stick[i - 1] + stick[i - 2];
			check = 1;
			break;
		}
	}
	if (!check)	//삼각형을 만들 수 없으면 -1을 출력
		cout << "-1";
}