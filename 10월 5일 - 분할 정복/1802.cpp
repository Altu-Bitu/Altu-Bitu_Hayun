#include <iostream>
#include <string>
using namespace std;

//문자열, 분할 정복

bool foldable(string paper) {
	//Conquer
	if (paper.size() == 1)
		return true;
	string l, r;
	//중심을 기준으로 차례대로 양옆 문자가 반대여야 한다.
	//Divide: 중심 기준 왼/오른쪽 문자열로 나누기
	for (int i = 1; i <= paper.size() / 2; i++) {
		l += paper[paper.size() / 2 - i];
		r += paper[paper.size() / 2 + i];
		if (paper[paper.size() / 2 - i] == paper[paper.size() / 2 + i])
			return false;
	}
	//Combine
	return foldable(l);	//*왼쪽이 만족하면 어차피 좌우 반대이기 때문에 오른쪽도 만족 -> 오른쪽은 확인할 필요가 없다
}

int main() {
	int n;
	cin >> n;
	string paper;
	for (int i = 0; i < n; i++) {
		cin >> paper;

		if (foldable(paper))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}