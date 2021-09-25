#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 이게 최선인가?
// 정렬 활용, 최빈값 주의

int first(vector<int> v) {
	double total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += double(v[i]);
	}
	return int(round(total / v.size()));
}

int second(vector<int> v) {
	sort(v.begin(), v.end());
	return v[int(v.size() / 2)];
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int third(vector<int> v) {
	if (v.size() == 1)
		return v[0];
	vector<pair<int, int>> freq(8001); // -4000 [0] ~ 4000 [8000]
	for (int i = 0; i < v.size(); i++) {
		freq[v[i] + 4000].first = v[i];
		freq[v[i] + 4000].second++;
	}
	sort(freq.begin(), freq.end(), cmp);
	if (freq[0].second == freq[1].second)
		return freq[1].first;
	else
		return freq[0].first;

}

int fourth(vector<int> v) {
	sort(v.begin(), v.end());
	return v[v.size() -1] - v[0];
}

int main() {
	int n, k;
	cin >> n;
	vector<int> v;
	while (n--) {
		cin >> k;
		v.push_back(k);
	}
	cout << first(v) << "\n";
	cout << second(v) << "\n";
	cout << third(v) << "\n";
	cout << fourth(v) << "\n";
	return 0;
}