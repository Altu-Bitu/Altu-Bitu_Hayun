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
	vector<pair<int, int>> v(SIZE+1);

	char c = '*';
	int k;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		if (i != 0)
			cin >> c;

		cin >> k;
		k = abs(k);
		if (k == 0) {
			zero = true;
			break;
		}
		while (k > 1) {
			if (c == '*')
				v[prime[k]].second++;
			else
				v[prime[k]].second--;
			k /= prime[k];
		}
	}

	bool is_mint = true;
	for (auto iter : v) {
		if (iter.second < 0)
			is_mint = false;
	}
	if (is_mint || zero)
		cout << "mint chocolate\n";
	else
		cout << "toothpaste\n";

}