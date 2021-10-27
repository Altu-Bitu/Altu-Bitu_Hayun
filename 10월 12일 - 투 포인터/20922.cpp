#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//투포인터 (같은 위치에서 시작하는 투 포인터)

int longest(vector<int> &arr, int k) {
	vector<int> cnt(100001, 0);	//현재 연속 부분 수열의 원소(정수)가 각 몇 개씩 있는지 저장하는 벡터
	int temp = 0, ans = 0;	//현재 연속 부분 수열의 길이 변수와 최장 길이 변수
	int size = arr.size(), left = 0, right = 0;

	while (left <= right && right < size) {
		cout << left << ' ' << right << endl;
		if (cnt[arr[right]] < k) {	//만약 right이 가리키는 정수가 k개 미만이라면 right 이동 (이동 후에 cnt를 증가시키기 떄문에 '<='가 아니라 '<'이여야 함)
			cnt[arr[right]]++;
			right++;
			temp++;
		}
		else {	//만약 right이 가리키는 정수가 k개 이상이라면 left 이동 (더 이상 부분 수열에 해당 정수를 포함시키면 안됨)
			cnt[arr[left]]--;
			left++;
			temp--;
		}
		ans = max(temp, ans);
	}
	return ans;
}
int main() {
	int n, k;

	//입력
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산 & 출력
	int result = longest(arr, k);
	cout << result;
}