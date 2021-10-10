#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//분할 정복
//메모리 줄이는 구현방식 -> 샘플코드

int secondMax(int a, int b, int c, int d) {	//2번째로 큰 수 리턴
	int arr[] = { a, b, c, d };

	sort(arr, arr + 4, greater<>());
	return arr[1];
}

vector<vector<int>> divide(int size, vector<vector<int>> matrix) {
	if (size == 1) {
		return matrix;
	}

	vector<vector<int>> sub_problem(size/2, vector<int>(size/2, 0));

	// 2*2 배열들에서 2번째 큰 수를 계산해 (size/2) * (size/2) 행렬을 만든다
	int sub_size = size / 2;
	for (int i = 0; i < sub_size; i++) {
		for (int j = 0; j < sub_size; j++) {
			sub_problem[i][j] = secondMax(matrix[i * 2][j * 2], matrix[i * 2 + 1][j * 2], matrix[i * 2][j * 2 + 1], matrix[i * 2 + 1][j * 2 + 1]);
		}
	}

	return divide(sub_size, sub_problem);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	vector<vector<int>> result = divide(n, matrix);
	cout << result[0][0];
}