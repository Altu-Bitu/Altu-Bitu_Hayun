#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 브루트 포스 알고리즘 활용
// 모든 경우의 수 - 아닌 경우 (세 자리 다른수, 0 사용 X 주의)

vector<bool> total;
vector<bool> init() {
	vector<bool> total(1000, 1);
	for (int i = 100; i < 999; i++) {
		string temp = to_string(i);
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2] || temp[1] == '0' || temp[2] == '0')
			total[stoi(temp)] = 0;
	}
	return total;
}

void check(string k, int s, int b) {
	for (int i = 100; i < 999; i++) {
		if (!total[i])
			continue;
		string temp_i = to_string(i);
		int temp_s = 0, temp_b = 0;
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (a == b && temp_i[a] == k[b]) temp_s++;
				if (a != b && temp_i[a] == k[b]) temp_b++;
			}
		}
		if (temp_s != s || temp_b != b) total[i] = 0;
	}
	
}

int main() {
	total = init();
	int n, s, b;
	string k;
	cin >> n;
	while (n--) {
		cin >> k >> s >> b;
		check(k, s, b);
	}

	int result = 0;
	for (int i = 100; i < 999; i++) {
		if (total[i])
			result++;
	}
	cout << result;
	
	return 0;
}