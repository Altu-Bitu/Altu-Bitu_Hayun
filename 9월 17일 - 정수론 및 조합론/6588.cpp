#include <iostream>
#include <vector>
using namespace std;

// �����佺�׳׽��� ü Ȱ��
// �̸� �ִ� �������� ���͸� ���� �� �Է°� ó��

const int SIZE = 1000000;

vector<bool> isPrime() {
	vector<bool> is_prime(SIZE+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= SIZE; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j <= SIZE; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}


int main() {
	//n�� �� ũ�׿�. n������ �Ҽ��� ������ �Ǵ��� �� �ִ� ����� ��� �� �� ���ƿ�.
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> prime = isPrime();
	
	while (true) {
		int n;
		cin >> n;
		bool if_wrong = false;

		if (n == 0)
			break;
		for (int i = 3; i < n; i++) {
			if (prime[i] && prime[n - i]) {
				cout << n << " = " << i << " + " << n - i <<"\n";
				if_wrong = true;
				break;
			}
		}
		if (if_wrong)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}