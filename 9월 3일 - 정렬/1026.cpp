#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a, b;
	a.assign(n, 0), b.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(b.begin(), b.end(), greater<int>());
	sort(a.begin(), a.end(), less<int>());
	
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] * b[i];
	cout << s;
	
}