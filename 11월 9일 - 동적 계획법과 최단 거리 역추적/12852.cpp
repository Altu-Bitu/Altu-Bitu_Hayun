#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1000001;

void makeOne(int n, vector<int> &dp, vector<int> &path) {

	//연산
	dp[1] = 0;	//타겟은 1

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;	//3번 연산
		path[i] = i - 1;

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {	//1번 연산
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {	//2번 연산
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}
	}
}

int main() {
	vector<int> dp(SIZE, SIZE);	//연산 최솟값 저장 배열
	vector<int> path(SIZE);		//경로 저장 배열

	int n;
	//입력
	cin >> n;

	//연산
	makeOne(n, dp, path);

	//출력
	cout << dp[n] << '\n';	//연산 횟수의 최솟값
	while (n != 0) {
		cout << n << " ";	//1로 만드는 방법에 포함되는 수
		n = path[n];
	}
	return 0;
}