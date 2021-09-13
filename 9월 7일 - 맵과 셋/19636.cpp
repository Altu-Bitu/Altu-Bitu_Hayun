#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Æ²·È½À´Ï´Ù
bool dangerDiet(int w, int i) {
	if (w <= 0 || i <= 0)
		return true;
	else
		return false;
}

bool yoyo(int i, int afteri) {
	if ((i - afteri) > 0)
		return true;
	else
		return false;
}

pair<int, int> cal(int w0, int i0, int t, int d, int i, int a) {
	pair<int, int> after;
	while (d--) {
		int c = i - i0 - a;
		w0 += c;
		if (abs(c) > t) {
			i0 += floor(c / 2);
		}
	}
	after.first = w0;
	after.second = i0;
	return after;
}

int main() {
	int w0, i0, t, d, i, a;
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	if (dangerDiet(w0 + d * (i - i0 - a), i0))
		cout << "Danger Diet" << endl;
	else
		cout << w0 + d * (i - i0 - a) << " " << i0 << endl;

	pair<int, int> after = cal(w0, i0, t, d, i, a);
	if (dangerDiet(after.first, after.second))
		cout << "Danger Diet" << endl;
	else {
		cout << after.first << " " << after.second << " ";
		if (yoyo(i0, after.second))
			cout << "YOYO" << endl;
		else
			cout << "NO" << endl;

	}
}