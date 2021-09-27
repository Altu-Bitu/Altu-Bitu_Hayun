#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, k, max_freq = 0, mode = 0;
	double total = 0;
	cin >> n;
	vector<int> v;
	vector<int> freq(8001, 0);
	while (n--) {
		cin >> k;
		v.push_back(k);
		freq[k + 4000]++;
		if (freq[k + 4000] > max_freq)
			max_freq = freq[k + 4000];
		total += double(k);
	}

	sort(v.begin(), v.end());

	int temp = 0;

	for (int i = 0; i < 8001; i++) {
		if (freq[i] == max_freq) {
			temp++;
			mode = i - 4000;
		}
		if (temp == 2) {
			break;
		}
	}
	
	cout << int(round(total / v.size())) << "\n";
	cout << v[int(v.size() / 2)] << "\n";
	cout << mode << "\n";
	cout << v[v.size() - 1] - v[0] << "\n";
	return 0;
}