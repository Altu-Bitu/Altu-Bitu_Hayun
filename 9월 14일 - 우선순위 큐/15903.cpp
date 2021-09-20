#include <iostream>
#include <queue>
using namespace std;

// ÃÖ¼ÒÈü È°¿ë

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long input;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<>> pq;

	while (n--) {
		cin >> input;
		pq.push(input);
	}

	while (m--) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	long long result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
}