#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> button(10, true);
int n;

bool check(int a) {
	while (a > 0) {
		if (!button[a % 10])
			return false;
		a /= 10;
	}
	if (a == 0 && !button[0]) {
		return false;
	}
	return true;
}

int numLen(int a) {
	int len = 1;
	while (a >= 10) {
		a /= 10;
		len++;
	}
	return len;
}

int getChnl() {
	int result = abs(n - 100);

	for (int i = 0; i < 1000000; i++) {
		if (abs(n - i) + numLen(i) < result && check(i))
			result = abs(n - i) + numLen(i);
	}
	return result;
}

int main() {
	int m, temp;
	cin >> n;
	cin >> m;
	
	while (m--) {
		cin >> temp;
		button[temp] = false;
	}
	cout << getChnl();
}
