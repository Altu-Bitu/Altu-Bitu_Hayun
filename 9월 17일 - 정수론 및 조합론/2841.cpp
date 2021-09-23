#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 스택 활용

int main() {
	int n, p, result = 0;
	cin >> n >> p;
	vector<stack<int>> guitar(7);
	while (n--) {
		int s, t;
		cin >> s >> t;
		while (true) {
			if (guitar[s].empty() || guitar[s].top() < t) {
				result++;
				guitar[s].push(t);
				break;
			}
			else if (guitar[s].top() == t) {
				break;
			}
			else if (guitar[s].top() > t) {
				result++;
				guitar[s].pop();
			}
		}
	}
	cout << result;
}