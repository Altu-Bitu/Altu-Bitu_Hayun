#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) // y좌표 오름차순
		return a.second < b.second;
	if (a.first != b.first) // x좌표 오름차순
		return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> dot(n);
	for (int i = 0; i < n; i++) {
		cin >> dot[i].first >> dot[i].second;
	}
	sort(dot.begin(), dot.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << dot[i].first << " " << dot[i].second << '\n';
}