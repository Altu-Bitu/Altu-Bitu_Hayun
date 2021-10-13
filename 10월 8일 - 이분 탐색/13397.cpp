#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이분 탐색

vector<int> arr;

int section(int mid) {	//주어진 구간의 점수에 대해 구간 개수 구하기
	int total = 1;		//구간은 1개에서 시작
	int min_sec = arr[0];
	int max_sec = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		min_sec = min(min_sec, arr[i]);
		max_sec = max(max_sec, arr[i]);
		if (max_sec - min_sec > mid) {		//구간 점수 = 구간 내 최댓값 - 구간 내 최솟값이 mid보다 크다면 구간을 나눈다
			total++;	//구간 개수 증가
			min_sec = arr[i];
			max_sec = arr[i];
		}
	}
	return total;
}

int lowerSearch(int left, int right, int target) {	//구간의 점수의 최댓값의 최솟값 -> lower bound를 구한다
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sections = section(mid);	//mid가 구간의 점수의 최댓값이라면 구간이 최소 몇 개 나오는가?
		if (sections <= target) {		//target 이하의 구간의 개수라면 -> 구간의 점수를 줄인다
			ans = mid;	//현재의 mid값 저장. 최종 갱신되는 값은 lower bound
			right = mid - 1;
		}
		else {		//target 초과의 구간의 개수라면 -> 구간의 점수를 늘린다
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, m;
	int right = 0;
	
	//입력
	cin >> n >> m;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}
	
	//연산 & 출력
	//left : 모두 같은 수가 나올 수 있으므로 0
	//right : 최댓값을 초과하는 구간의 점수는 나올 없다
	cout << lowerSearch(0, right, m);
}