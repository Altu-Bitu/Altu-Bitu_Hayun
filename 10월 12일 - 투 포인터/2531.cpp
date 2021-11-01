#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//투 포인터 (슬라이딩 윈도우가 더 쉬운 듯)

int slidingWindow(vector<int> &sushi, int n, int d, int k, int c) {

	vector<int> kinds(d + 1);		//종류별 몇 개의 초밥을 먹었는지
	int max_kinds = 0, count = 0;	//최대 가짓수, 현재 가짓수
	kinds[c]++; count++;			//쿠폰으로 받는 초밥은 무조건 먹는다
	for (int i = 0; i < k; i++) {	//첫 날부터 k번째까지 가짓수
		if (kinds[sushi[(i % n)]]++ == 0)
			count++;
	}
	max_kinds = count;

	for (int i = k; i < n + k - 1; i++) {	//회전 초밥이기 때문에 마지막 원소 ~ (k-1)번째 원소 윈도우까지 확인하기
		if (--kinds[sushi[i - k]] == 0) 	//이번 윈도우에 제외되는 값
			count--;
		
		if (kinds[sushi[(i % n)]]++ == 0) 	//이번 윈도우에 추가되는 값
			count++;
		
		max_kinds = max(max_kinds, count);	//최대 가짓수 갱신
	}
	return max_kinds;
}

int twoPointer(vector<int> &sushi, int n, int d, int k, int c) {
	vector<int> kinds(d + 1);
	int max_kinds = 0, count = 0;
	kinds[c]++; count++;
	for (int i = 0; i < k; i++) {
		if (kinds[sushi[(i % n)]]++ == 0)
			count++;
	}
	max_kinds = count;
	for (int left = 0; left < n - 1; left++) {
		int right = (left + k) % n;
		if (--kinds[sushi[left]] == 0)
			count--;
		if (kinds[sushi[right]]++ == 0)
			count++;
		max_kinds = max(max_kinds, count);
	}
	return max_kinds;
}

int main() {
	int n, d, k, c;
	//입력
	cin >> n >> d >> k >> c;

	vector<int> sushi(n);
	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	//연산 & 출력
	cout << slidingWindow(sushi, n, d, k, c);
	//cout << twoPointer(sushi, n, d, k, c);

	return 0;
}