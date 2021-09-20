#include <iostream>
#include <stack>
using namespace std;

// 탑 (높이에 따라 수신) -> 스택 활용
// 맞긴 했으나 효율성은 모르겠음?


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int, int>> s;
	int n, input, index = 1;
	cin >> n;
	while (n--) {
		cin >> input;
		if (s.empty())
			cout << "0 ";
		else if (s.top().second >= input) {
			cout << s.top().first << " ";
		}
		else if (s.top().second < input) {
			while (true) {
				 if (s.top().second < input) {
					s.pop();
					if (s.empty()) {
						cout << "0 ";
						break;
					}
				}
				 else if (s.top().second >= input) {

					 cout << s.top().first << " ";
					 break;
				 }
			}
		}
		s.push(make_pair(index++, input));
	}
}