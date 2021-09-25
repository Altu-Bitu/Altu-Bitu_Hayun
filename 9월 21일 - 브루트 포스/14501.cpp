#include <iostream>
#include <vector>
using namespace std;

// 못 풀음. 방법을 모르겠다...

vector<pair<int, int>> tp;
int max = 0;

void maxPay(int day, int sum) {
	if (day >= tp.size() || day + tp[day].first - 1 > tp.size())
		return;
	for (int i = day; i < tp.size(); i++) {
		if (i + tp[i].first - 1 <= tp.size()) {
			sum += tp[i].second;
			maxPay(i + tp[i].first, sum);
			sum -= tp[i].second;
		}

		max = sum > max ? sum : max;
	}
}

int main() {
	int n, t, p;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		tp.push_back(make_pair(t, p));
	}

	maxPay(0, 0);
	cout << max;
	
	return 0;
}