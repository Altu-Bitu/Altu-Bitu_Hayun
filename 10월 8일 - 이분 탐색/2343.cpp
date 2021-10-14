#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//이분 탐색
//틀렸습니다

vector<int> lecture;

int count(int minute) {		//주어진 블루레이의 크기에 대해서 몇 개의 블루레이가 필요한가?
	int temp = 0;
	int cnt = 1;
	for (int i = 0; i < lecture.size(); i++) {
		if (temp + lecture[i] > minute) {	//temp와 현재 강의 길이의 합이 minute을 넘으면 블루레이 개수 증가
			temp = 0;
			cnt++;
		}
		temp += lecture[i];
	}
	return cnt;
}

int lowerSearch(int left, int right, int target) {	//블루레이 크기 중 최소 -> lower bound를 구한다
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int blueray = count(mid);

		if (blueray <= target) {	//target 이하의 개수라면 -> 블루레이 크기를 줄인다
			ans = mid;
			right = mid - 1;
		}
		else {		//target 초과의 개수라면 -> 블루레이 크기를 늘린다
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n, m, sum = 0;
	int left = 0;

	//입력
	cin >> n >> m;
	lecture.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		sum += lecture[i];
		left = max(left, lecture[i]);
	}

	//연산 & 출력
	//left: lecture의 최댓값도 블루레이에 저장되어야한다 (1로 하면 안된다, 반례: n = m인 경우, 답이 1이 됨)
	//right: 블루레이 개수가 하나인 경우 모든 강의의 합을 초과할 수 없다
	cout << lowerSearch(left, sum, m);
}