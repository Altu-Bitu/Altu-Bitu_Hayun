#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//동적계획법 역추적
//메모리가..... 괜찮은건가

string lcs(int n, int m, string s1, string s2, vector<vector<string>> &path) {
	vector<vector<int>> dp(n, vector<int>(m, 0));	//LCS DP 배열
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s1[i - 1] == s2[j - 1]) {	//두 문자가 서로 같다면 공통 부분 문자열에 추가됨
				dp[i][j] = dp[i - 1][j - 1] + 1;
				path[i][j] = path[i - 1][j - 1];
				path[i][j].append({ s1[i - 1] });	//추가되기 전 string + 같은 문자
			}
			else {	//두 문자가 서로 다르다면 그 전의 길이 최댓값 그대로, string도 그대로
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					path[i][j] = path[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
					path[i][j] = path[i][j - 1];
				}				
			}
		}
	}
	return path[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;

	//입력
	cin >> s1 >> s2;

	int n = s1.size() + 1, m = s2.size() + 1;
	vector<vector<string>> path(n, vector<string>(m));
	
	//연산
	string result = lcs(n, m, s1, s2, path);

	//출력
	if (result.size() > 0)
		cout << result.size() << '\n' << result;
	else
		cout << "0";
	return 0;
}