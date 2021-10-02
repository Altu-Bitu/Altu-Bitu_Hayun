#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//다이나믹 프로그래밍 활용

vector<int> dp(100001, 100000);	//이전 값 저장하는 dp 배열 (동전의 가치는 100,000보다 작거나 같다)
vector<int> coin(100);			//사용되는 동전의 값 배열
int minCoin(int n, int k) {
	for (int i = 0; i < n; i++) {		//매 동전마다 최소값 계산 및 저장
		for (int j = 1; j <= k; j++) {
			if (j > coin[i])			//현재 값보다 동전값이 커야함
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] >= 100000) //불가능한 경우 (초기화를 못 시킴)
		return -1;
	return dp[k];
}

int main() {
	int n, k, temp;
	//입력
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp;
		coin[i] = temp;
		dp[temp] = 1;
	}
	//연산
	cout << minCoin(n, k);
}