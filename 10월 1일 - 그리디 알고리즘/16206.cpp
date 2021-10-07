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

int m;
/*
void cutRecur(int len) {
	if (m == 0 || len < 10) {
		if (len == 10)
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
*/
int cut(vector<int> cake) {
	int cnt = 0;
	for (int i = 0; i < cake.size(); i++) {
		int check = cake[i] / 10;
		if (cake[i] % 10 == 0) {
			if (check - 1 > m) {
				cnt += m;
				m = 0;
			}
			else {
				cnt += check;
				m -= (check - 1);
			}
		}
		else {
			if (check > m) {
				cnt += m;
				m = 0;
			}
			else {
				cnt += check;
				m-= check;
			}
		}
	}
	return cnt;
}

int main() {
	int n;
	cin >> n >> m;
	vector<int> cake(n);
	for (int i = 0; i < n; i++) {
		cin >> cake[i];
	}
	sort(cake.begin(), cake.end(), cmp);	//10의 배수인 케이크 먼저 자르기
	
	cout << cut(cake);
}