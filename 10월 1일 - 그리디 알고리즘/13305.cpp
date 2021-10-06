#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll minCost(vector<ll> len, vector<ll> cost) {
	ll min = cost[0];
	ll total = 0;
	for (int i = 0; i < len.size(); i++) {
		if (min > cost[i])
			min = cost[i];
		total += min * len[i];
	}
	return total;
}

int main() {
	int n;
	cin >> n;
	vector<ll> len(n-1), cost(n);

	for (int i = 0; i < n - 1; i++)
		cin >> len[i];

	for (int i = 0; i < n; i++)
		cin >> cost[i];
	cout << minCost(len, cost);
}