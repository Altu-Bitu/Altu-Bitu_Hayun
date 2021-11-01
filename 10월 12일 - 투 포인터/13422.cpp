#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//투 포인터 (슬라이딩 윈도우)
//예외인 경우 생각해내기

int slidingWindow(vector<int> &house, int n, int m, int k) {
	int cnt = 0;	//돈을 훔치는 방법의 가짓수
	int curr = 0;	//현재 훔치는 돈 액수
	for (int i = 0; i < m; i++)		//처음 집부터 m번째 집까지 돈 액수
		curr += house[i];
	
	if (curr < k)
		cnt++;

	if (m == n)	//n == m이라면 슬라이딩 윈도우를 할 필요 없이 한 가지 경우밖에 없음.
		return cnt;

	for (int i = m; i < n + m - 1; i++) {	//원형이기 때문에 마지막~(k-1) 윈도우까지 확인
		curr -= house[i - m];	//이번 윈도우에 제외되는 값
		curr += house[(i%n)];	//이번 윈도우에 추가되는 값
		if (curr < k)	//돈 액수가 k보다 작으면 훔칠 수 있음
			cnt++;
	}
	return cnt;
}

int twoPointer(vector<int> &house, int n, int m, int k) {
	int cnt = 0;	
	int curr = 0;	
	for (int i = 0; i < m; i++) 	
		curr += house[i];
	
	if (curr < k)
		cnt++;

	if (m == n)
		return cnt;

	for (int left = 0; left < n - 1; left++) {
		int right = (left + m) % n;
		curr -= house[left];
		curr += house[right];
		if (curr < k)
			cnt++;
	}
	return cnt;
}

int main() {
	//훔친 돈이 k보다 작은지 생각해보기 전에...도둑질을 할 수 있는 경우의 수는 어떻게 되나요?: n가지 -> 예외: n == m인 경우!!!!!!!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		//입력
		cin >> n >> m >> k;
		vector<int> house(n);
		for (int i = 0; i < n; i++)
			cin >> house[i];

		//연산 & 출력
		cout << slidingWindow(house, n, m, k) << '\n';
		//cout << twoPointer(house, n, m, k) << '\n';
	}
}