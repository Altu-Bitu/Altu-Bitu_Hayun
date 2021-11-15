#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1000001;

vector<int> makeOne(int n, vector<int> &path) {
	
	vector<int> dp(SIZE, SIZE);	//연산 최솟값 저장 배열
	vector<int> result;
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
	while (n != 0) {
		result.push_back(n);
		n = path[n];
	}
	return result;
}

int main() {
	
	vector<int> path(SIZE);		//경로 저장 배열

	int n;
	//입력
	cin >> n;

	//연산
	vector<int> result = makeOne(n, path);

	//출력
	cout << result.size() - 1 << '\n';	//연산 횟수의 최솟값
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}