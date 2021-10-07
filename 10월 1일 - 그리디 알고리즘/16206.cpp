#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//그리디 알고리즘

bool cmp(int a, int b) {
	if (a % 10 != b % 10)
		return a % 10 < b % 10;
	return a < b;
}

int m, cnt = 0;

void cutRecur(int len) {
	if (m == 0 || len < 10) {
		if (len == 10)	//마지막 자른 조각이 10이면
			cnt++;
		return;
	}
	
	if (len > 10) {
		m--;
		cnt++;
		cutRecur(len - 10);
	}
	else if (len == 10) {
		cnt++;
		cutRecur(len - 10);
	}
	return;
}

int main() {
	int n;
	cin >> n >> m;
	vector<int> cake(n);
	for (int i = 0; i < n; i++) {
		cin >> cake[i];
	}
	sort(cake.begin(), cake.end(), cmp);	//10의 배수인 케이크 먼저 자르기
	for (int i = 0; i < n; i++) {
		cutRecur(cake[i]);
	}
	cout << cnt;
}