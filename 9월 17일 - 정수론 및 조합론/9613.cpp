#include <iostream>
#include <vector>
using namespace std;

// 유클리드 호제법 활용
// 모든 쌍을 구하는 가장 쉬운 방법? 의도대로 했는지 모르겠다
// int VS long long 판단 어떻게 하는지

int gcdRecursion(int a, int b) {
	if (b == 0)
		return a;
	return gcdRecursion(b, a%b);
}

vector<pair<int, int>> makePair(vector<int> v) {
	vector<pair<int,int>> pv;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			pv.push_back(make_pair(v[i], v[j]));
		}
	}
	return pv;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		while (n--) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		vector<pair<int, int>> pv = makePair(v);
		long long result = 0;
		for (int i = 0; i < pv.size(); i++) {
			result += gcdRecursion(pv[i].first, pv[i].second);
		}
		cout << result << "\n";
	}
}