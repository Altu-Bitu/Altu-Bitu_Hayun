#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
// �� �𸣰ڴ�...!
// �켱���� +- < */
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> s;
	string before; 
	cin >> before;

	for (int i = 0; i < before.size(); i++) {
		switch (before[i]) {
			case '+': case '-':
				// * /�� top�� ������ ��� �� pop?
				s.push(before[i]);
				break;
			case '*': case '/':

				s.push(before[i]);
				break;
			case '(':
				s.push(before[i]);
				break;
			case ')':
				while (true) {
					if (s.top() == '(')
						s.pop(); break;
					cout << s.top();
					s.pop();
				}
				break;
			default:
				cout << before[i];
				break;
		}
	}
	if (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}