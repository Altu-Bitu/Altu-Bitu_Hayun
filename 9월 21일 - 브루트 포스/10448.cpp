#include <iostream>
#include <vector>
using namespace std;

// 브루트포스 알고리즘 활용

vector<int> triNum() { //삼각수 저장하는 함수
	int n = 1;
	vector<int> v;
	while (true) {
		int tn = n * (n + 1) / 2;
		v.push_back(tn);
		if (tn > 1000)
			break;
		n++;
	}
	return v;
}

vector<bool> check(vector<int> v) { //세 개의 삼각수를 더한 수 검사하는 함수
	vector<bool> num(1001, 0);
	for (int i = 0; i < v.size(); i++) {
		for (int j =0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
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
	vector<int> v = triNum();
	vector<bool> result = check(v);
	while (n--) {
		int k;
		cin >> k;
		cout << result[k] << "\n";
	}
	return 0;
}