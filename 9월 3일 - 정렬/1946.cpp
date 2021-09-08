#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		vector<pair<int, int>> a(t);
		for (int j = 0; j < t; j++) {
			cin >> a[j].first >> a[j].second;
		}
		sort(a.begin(), a.end(), cmp);

		int max = 1, tmp = a[0].second;;
		for (int k = 0; k < t; k++) {
			if (a[k].second < tmp) {
				tmp = a[k].second;
				max++;
			}
		}
		cout << max << endl;
	}
}