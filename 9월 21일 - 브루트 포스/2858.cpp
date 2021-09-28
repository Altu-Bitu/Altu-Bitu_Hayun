#include <iostream>
#include <algorithm>
using namespace std;

// 브루트포스 알고리즘 활용

pair<int, int> getLW(int r, int b) {
	for (int i = 3; i < (r + b)/2; i++) {
		if ((r + b) % i == 0) {
			int w = (r + b) / i;
			if ((w - 2)*(i - 2) == b) {
				return make_pair(i, w);
			}
		}
	}
	
}

int main() {
	int r, b;
	cin >> r >> b;
	pair<int, int> lw = getLW(r, b);
	cout << max(lw.first, lw.second) << " " << min(lw.first, lw.second);
	return 0;
}