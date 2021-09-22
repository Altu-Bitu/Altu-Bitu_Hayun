#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 우선순위 큐에서 우선순위 정의하는 방법

struct compare {
	bool operator()(int a, int b) {
		if(abs(a) != abs(b))
			return abs(a) > abs(b);
		return a > b;
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, x;
	priority_queue<int, vector<int>, compare> pq;
	cin >> n;

	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0"<< '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			pq.push(x);
		}
	}
}