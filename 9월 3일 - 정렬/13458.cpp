#include <iostream>
#include <vector>
using namespace std;

long long totalSup(int n, vector<int> a, int b, int c) {
	long long total = 0; // int -> unsigned long long
	for (int i = 0; i < n; i++) {
		if (a[i] <= b) total++;
		else if (a[i] - b <= c) total += 2;
		else total += (a[i] - b) % c == 0 ? (a[i] - b) / c + 1 : (a[i] - b) / c + 2;
	}
	return total;
}

int main() {
	int n, b, c;
	cin >> n;
	vector<int> a;
	a.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;

	cout << totalSup(n, a, b, c);
	return 0;
}