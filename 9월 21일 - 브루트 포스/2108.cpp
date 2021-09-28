#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int avg(int total, vector<int> v) {
	return int(round(total / v.size()));
}

int median(vector<int> v) {
	return v[int(v.size() / 2)];
}

int mode(int max_freq, vector<int> freq) {
	int temp = 0, mode = 0;

	for (int i = 0; i < 8001; i++) {
		if (freq[i] == max_freq) {
			temp++;
			mode = i - 4000;
		}
		if (temp == 2) {
			break;
		}
	}
}

int range(vector<int> v) {
	return v[v.size() - 1] - v[0];
}


int main() {
	int n, k, max_freq = 0;
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
	
	cout << avg(total, v) << "\n";
	cout << median(v) << "\n";
	cout << mode(max_freq, freq) << "\n";
	cout << range(v) << "\n";
	return 0;
}