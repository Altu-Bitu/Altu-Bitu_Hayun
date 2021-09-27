#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 브루트포스 알고리즘 활용

int getScore(vector<int> hw) {
	int score = 0;
	for (int i = 0; i < hw.size() - 1; i++) {
		for (int j = i + 1; j < hw.size(); j++) {
			if ((hw[i] - hw[j]) < 0)
				score++;
		}
	}
	return score;
}

int main() {
	int n;
	cin >> n;
	map<string, int> correct;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		correct[temp] = i;
	}
	vector<int> hw(n);
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		hw[i] = correct[temp];
	}

	int score = getScore(hw);
	cout << score << "/" << n * (n - 1) / 2;
	return 0;
}