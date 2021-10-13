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

	//입력
	cin >> n >> m;
	lecture.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		sum += lecture[i];
	}

	//연산 & 출력
	cout << lowerSearch(1, sum, m);
}