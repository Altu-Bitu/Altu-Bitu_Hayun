#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;


int main() {
	int n, k;
	
	deque<int> dq;

	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> k;
			
			dq.push_front(k);
			continue;
		}
		if (cmd == "push_back") {
			cin >> k;
			dq.push_back(k);
			continue;
		}
		if (cmd == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			continue;
		}
		if (cmd == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			continue;
		}
		if (cmd == "size") {
			cout << dq.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << dq.empty() << '\n';
			continue;
		}
		if (cmd == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
			continue;
		}
		if (cmd == "back") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
			continue;
		}
	}
	
}