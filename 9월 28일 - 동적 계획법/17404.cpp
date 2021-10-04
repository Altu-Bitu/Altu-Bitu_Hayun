#include <iostream>
#include <algorithm>
using namespace std;

//다이내믹 프로그래밍 활용

int minCost(int rgb[][3], int i, int n, int cost) {
	int dp[1000][3];	//기존 배열이 for문 돌리면서 바뀌면 안되니까 새로운 배열 생성
	dp[0][i] = rgb[0][i];
	dp[0][(i + 1) % 3] = 1001;
	dp[0][(i + 2) % 3] = 1001;

	for (int j = 1; j < n; j++) {
		dp[j][0] = rgb[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
		dp[j][1] = rgb[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
		dp[j][2] = rgb[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
	}
	return min(cost, min(dp[n - 1][(i + 1) % 3], dp[n - 1][(i + 2) % 3]));	 //마지막 집도 1번 집과 색이 겹치면 안됨

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
	int cost = 1000000;
	for (int i = 0; i < 3; i++) {	//1번 집의 색 선택하기
		cost = minCost(rgb, i, n, cost);
	}
	cout << cost;
}