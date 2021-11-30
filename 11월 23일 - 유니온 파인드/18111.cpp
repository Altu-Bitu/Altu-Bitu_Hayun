#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, b;
vector<vector<int>> ground;

int time(int z) {
	int plus = 0, minus = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] > z)
				minus += ground[i][j] - z;
			else if(ground[i][j] < z)
				plus += z - ground[i][j];
		}
	}
	
	if (minus + b < plus)
		return -1;
	return minus * 2 + plus;
}

int main() {
	
	cin >> n >> m >> b;
	int max_z = 0;
	ground.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			max_z = max(max_z, ground[i][j]);
		}
	}
	pair<int, int> result = { 7e7, 0 };
	if (max_z > 256)
		max_z = 256;
	for (int i = max_z; i >= 0; i--) {
		int time_z = time(i);
		if (time_z != -1) {
			if (result.first > time_z) {
				result.first = time_z;
				result.second = i;
			}
		}
	}
	cout << result.first << " " << result.second;
}