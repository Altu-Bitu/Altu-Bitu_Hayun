#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
// Æ²·È½À´Ï´Ù.
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s1(n);
	set<string> s2;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> s1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		s2.insert(temp);
	}
	int count = 0;
	set<string>::iterator it;
	for (int i = 0; i < n; i++) {
		it = s2.find(s1[i]);
		if (it != s2.end())
			count++;
	}
	cout << count;
}