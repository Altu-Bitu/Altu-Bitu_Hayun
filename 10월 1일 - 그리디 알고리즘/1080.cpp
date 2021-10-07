#include <iostream>
#include <vector>
#include <string>
using namespace std;

//그리디 알고리즘

vector<vector<int>> matrix_a, matrix_b;

void swap_3x3(int r, int c) {
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			matrix_a[i][j] = 1 - matrix_a[i][j];
		}
	}
}

int getAns(int n, int m) {
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (matrix_a[i][j] != matrix_b[i][j]) {
				swap_3x3(i, j);
				ans++;
			}
		}
	}
}

int main() {
	//입력
	int n, m;
	cin >> n >> m;
	matrix_a.assign(n, vector<int>(m));
	matrix_b.assign(n, vector<int>(m));
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			matrix_a[i][j] = c - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			matrix_b[i][j] = c - '0';
		}
	}
	
	int ans = getAns(n, m);

	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix_a[i][j] != matrix_b[i][j]) {
				check = true;
			}
		}
	}
	if (!check)
		cout << ans;
	else
		cout << "-1";
}