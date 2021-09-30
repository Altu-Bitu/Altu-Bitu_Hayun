#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 조합론, 백트래킹 활용

bool checkPw(string s) {	// 자음 모음 체크하는 함수
	int vow = 0, con = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
			case 'a': case 'e': case 'i': case 'o': case 'u':
				vow++; break;
			default:
				con++; break;
		}
	}
	if (vow >= 1 && con >= 2) // 최소 한 개의 모음 & 최소 두 개의 자음
		return true;
	else
		return false;
}
/*
permutation 이용한 조합 풀이
크기가 n인 배열에서 k개의 원소를 뽑는 방법
n 크기의 배열을 준비하고 그 중 k개의 원소를 true로 셋팅
*/
int main() {

	int l, c;
	char temp;
	
	//입력
	cin >> l >> c;

	vector<char> chars(c);
	for(int i = 0; i< c; i++){
		cin >> temp;
		chars[i] = temp;
	}

	//연산
	sort(chars.begin(), chars.end());

	vector<bool> check(c, false);	//c크기의 조합정보
	for (int i = 0; i < l; i++)		//l개의 원소를 true로 설정
		check[i] = true;
	
	string s;
	do {
		for (int i = 0; i < c; i++) {
			if (check[i])		//true라면 사용
				s += chars[i];	//해당 char를 string에 붙임
		}
		if (checkPw(s))			//모음, 자음 개수 체크
			cout << s << '\n';
		s = ""; //초기화
	} while (prev_permutation(check.begin(), check.end()));
	
	return 0;
}