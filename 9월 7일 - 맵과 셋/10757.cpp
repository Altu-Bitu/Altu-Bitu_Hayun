#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> bigPlus(string a, string b) {
	vector<int> c;
	bool check = false;
	int n = a.length() > b.length() ? a.length() : b.length();
	for (int i = 1 ; i <= n; i++) {
		int tempA = a.length() - i >= 0 ? atoi(new char(a[a.length() - i])) : 0;
		int tempB = b.length() - i >= 0 ? atoi(new char(b[b.length() - i])) : 0;
		if (check) { // 이전 자릿수 합이 10 이상
			if (tempA + tempB + 1 <= 9) {
				check = false;
				c.push_back(tempA + tempB + 1);
			}
			else {
				check = true;
				c.push_back((tempA + tempB + 1) % 10);
			}
		}
		else {
			if (tempA + tempB <= 9) {
				check = false;
				c.push_back(tempA + tempB);
			}
			else {
				check = true;
				c.push_back((tempA + tempB) % 10);
			}
		}
	}
	if (check)
		c.push_back(1);
	return c;
}

int main() {
	string a, b;

	cin >> a >> b;
	vector<int> c = bigPlus(a, b);
	for (int i = 1; i <= c.size(); i++) {
		cout << c[c.size() - i];
	}
}