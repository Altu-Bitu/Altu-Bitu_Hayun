#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

// 난이도 높음, 함정 주의 (음수, 0 어떻게 처리하는지..)
// 소인수분해 (에라토스테네스의 체) 활용
// 지수가 음수면 유리수라는 성질 활용


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
	//연산은 *와 / 밖에 없네요! 연산한 최종 결과로 판단하지 않고, 과정에서 판단할 수 있는 방법이 없을까요? 수는 분해가 가능하죠.
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