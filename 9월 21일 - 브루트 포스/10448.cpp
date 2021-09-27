#include <iostream>
#include <vector>
using namespace std;

// 브루트포스 알고리즘 활용

vector<bool> check() {
	int n = 1;
	vector<int> v;
	while (true) {
		int tn = n * (n + 1) / 2;
		v.push_back(tn);
		if (tn > 1000)
			break;
		n++;
	}

	vector<bool> num(1001, 0);
	for (int i = 0; i <n; i++) {
		for (int j =0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int tri = v[i] + v[j] + v[k];
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