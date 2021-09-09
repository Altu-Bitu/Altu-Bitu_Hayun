#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2) {
	/*
	A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
	���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
	���� 1,2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
	*/

	if (s1.length() != s2.length()) // 1�� ����
		return s1.length() < s2.length();

	int tot1 = 0, tot2 = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (isdigit(s1[i]))
			tot1 += atoi(new char(s1[i]));
		if (isdigit(s2[i]))
			tot2 += atoi(new char(s2[i]));
	}
	if (tot1 != tot2) { // 2�� ����
		if (tot1 < tot2)
			return true;
		else
			return false;
	}

	return s1 < s2; // 3�� ����
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