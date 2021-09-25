#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Ʋ�Ƚ��ϴ�. (�� 3~40�۱����� ���µ�)
// ��� Ʋ������ �𸣰ڴ�. ����..

int getChnl(int n, vector<char> broken) {
	int min = 100;

	for (int i = 0; i < 1000000; i++) {
		bool flag = true;
		string s = to_string(i);
		for (int j = 0; j < broken.size(); j++) {
			if (s.find(broken[j]) != s.npos)
				flag = false;
		}
		if (flag && abs(i - n) < abs(min - n))
			min = i;
	}
	return min;
}

int main() {
	int n, m;
	char k;
	cin >> n;
	cin >> m;
	vector<char> broken;
	while (m--) {
		cin >> k;
		broken.push_back(k);
	}
	int channel = getChnl(n, broken);
	int button = abs(channel - n);

	if (channel == 100)
		cout << button;
	else {
		int cnt = 1;
		while (channel >= 10) {
			channel /= 10;
			cnt++;
		}
		cout << cnt + button;
	}
}
