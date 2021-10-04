#include <iostream>
#include <algorithm>
using namespace std;

//다이내믹 프로그래밍 활용

int minCost(int rgb[][3], int n) {
	for (int i = 1; i < n; i++) {
		rgb[i][0] += min(rgb[i - 1][1], rgb[i - 1][2]); //현재 빨강은 이전 초록, 이전 파랑 중 최소값과 합산
		rgb[i][1] += min(rgb[i - 1][0], rgb[i - 1][2]); 
		rgb[i][2] += min(rgb[i - 1][0], rgb[i - 1][1]);
	}
	return min(rgb[n - 1][0], min(rgb[n - 1][1], rgb[n - 1][2])); //min함수는 매개변수를 2개만 받음
}

int main() {
	int n;
	//입력
	cin >> n;
	int rgb[1000][3];
	for (int i = 0; i < n; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	//연산
	cout << minCost(rgb, n);
}