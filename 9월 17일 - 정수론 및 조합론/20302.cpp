#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

// ���̵� ����, ���� ���� (����, 0 ��� ó���ϴ���..)
// ���μ����� (�����佺�׳׽��� ü) Ȱ��
// ������ ������ ��������� ���� Ȱ��


const int SIZE = 100000;

vector<int> isPrime() {
	vector<int> prime(SIZE + 1, 0);
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) {
			for (int j = i * i; j <= SIZE; j += i) {
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
	return prime;
}

int main() {
	//������ *�� / �ۿ� ���׿�! ������ ���� ����� �Ǵ����� �ʰ�, �������� �Ǵ��� �� �ִ� ����� �������? ���� ���ذ� ��������.
	int n;
	cin >> n;
	vector<int> prime = isPrime();
	map<int, int> m;

	char c;
	int k;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> k;
			k = abs(k);
			if (k == 0) {
				zero = true;
				break;
			}
			while (k > 1) {
				m[prime[k]]++;
				k /= prime[k];
			}
			continue;
		}
		cin >> c >> k;
		k = abs(k);
		if (k == 0) {
			zero = true;
			break;
		}
		while (k > 1) {
			if (c == '*')
				m[prime[k]]++;
			else
				m[prime[k]]--;
			k /= prime[k];
		}
	}

	bool is_mint = true;
	for (auto iter : m) {
		if (iter.second < 0)
			is_mint = false;
	}
	if (is_mint || zero)
		cout << "mint chocolate\n";
	else
		cout << "toothpaste\n";

}