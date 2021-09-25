#include <iostream>
#include <vector>
using namespace std;

// 브루트포스 알고리즘 활용

int getT(int i) {
	return i * (i + 1) / 2;
}

vector<bool> check() {
	int n = 1;
	while (true) {
		int tn = n * (n + 1) / 2;
		if (tn > 1000)
			break;
		n++;
	}

	vector<bool> num(1001, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int tri = getT(i) + getT(j) + getT(k);
				if (tri > 1000)
					break;
				num[tri] = 1;
			}
		}
	}
	return num;
}

int main() {
	int n;
	cin >> n;
	vector<bool> num = check();
	while (n--) {
		int k;
		cin >> k;
		cout << num[k] << "\n";
	}
	return 0;
}