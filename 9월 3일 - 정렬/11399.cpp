#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calTime(vector<int> a) {
	int time = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j <= i; j++) {
			time += a[j];
		}
	}
	return time;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << calTime(a);
}