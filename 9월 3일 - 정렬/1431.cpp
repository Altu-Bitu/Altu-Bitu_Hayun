#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2) {
	/*
	A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
	만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
	*/

	if (s1.length() != s2.length()) // 1번 조건
		return s1.length() < s2.length();

	int tot1 = 0, tot2 = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (isdigit(s1[i]))
			tot1 += atoi(new char(s1[i]));
		if (isdigit(s2[i]))
			tot2 += atoi(new char(s2[i]));
	}
	if (tot1 != tot2) { // 2번 조건
		if (tot1 < tot2)
			return true;
		else
			return false;
	}

	return s1 < s2; // 3번 조건
}
int main() {
	int n;
	cin >> n;
	vector<string> guitar(n, "");
	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}
	sort(guitar.begin(), guitar.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << guitar[i] << '\n';
}