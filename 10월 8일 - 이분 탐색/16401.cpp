#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이분 탐색
//시간이 너무 오래 걸려서 배열로 풀어보았다.

int n;
int snack[1000000];

int count(int len) {	//주어진 길이일 때 최대 몇 명의 조카에게 과자를 줄 수 있는지 계산
	int total = 0;
	for (int i = n - 1; snack[i] >= len; i--) {	//과자의 길이가 len 이상인 경우만 확인하기
		total += (snack[i] / len);
	}
	return total;
}

int upperSearch(int left, int right, int target) {	//과자의 최대 길이 -> upper bound를 구한다
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int kids = count(mid);	//길이가 mid일 때 최대 몇 명의 조카에게 과자를 줄 수 있는가?
		if (kids >= target) {	//target 이상의 조카에게 줄 수 있다면 -> 길이를 늘린다
			ans = mid;	//현재의 mid값 저장. 최종 갱신되는 값은 upper bound
			left = mid + 1;
		}
		else {	//target 미만의 조카에게 줄 수 있다면 -> 길이를 줄인다
			right = mid - 1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	//입력
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> snack[i];

	//연산
	sort(snack, snack + n);

	//연산 & 출력
	cout << upperSearch(1, snack[n - 1], m);
	return 0;
}