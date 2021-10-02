#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 브루트 포스 알고리즘 이용

int s[20][20];
int n;
vector<int> start;
vector<int> link;
int min_diff = 100000;

void check(int cnt) {
	if (cnt == n) {
		int total_s = 0, total_l = 0;
		for (int i = 0; i < start.size(); i++) {	//start팀의 점수 구하기
			for (int j = 0; j < start.size(); j++)
				total_s += s[start[i]][start[j]];
		}
		for (int i = 0; i < link.size(); i++) {		//link팀의 점수 구하기
			for (int j = 0; j < link.size(); j++)
				total_l += s[link[i]][link[j]];
		}
		min_diff = min(min_diff, abs(total_s - total_l)); //점수 차의 최소
		return;
	}

	start.push_back(cnt);	//인덱스를 start팀에 지정
	check(cnt + 1);
	start.pop_back();		//원상복구

	link.push_back(cnt);	//인덱스를 link팀에 지정
	check(cnt + 1);
	link.pop_back();		//원상복구
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	}
	check(0);
	cout << min_diff;
	return 0;
}