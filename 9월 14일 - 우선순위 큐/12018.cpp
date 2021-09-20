#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 크기 제한 있는 최소힙 활용

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, p, l, result = 0;
	vector<int> v;
	cin >> n >> m;
	while (n--) {
		priority_queue<int, vector<int>, greater<>> pq;
		cin >> p >> l;
		int input;
		while (p--) {
			cin >> input;
			if (pq.size() < l)
				pq.push(input);
			else if (pq.top() < input) {
				pq.pop();
				pq.push(input);
			}
		}
		if (pq.size() < l)
			v.push_back(1);
		else
			v.push_back(pq.top());
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		m -= v[i];
		if (m < 0)
			break;
		result++;
	}
	cout << result << '\n';
}