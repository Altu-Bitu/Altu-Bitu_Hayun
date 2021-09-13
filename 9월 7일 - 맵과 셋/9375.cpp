#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int wear(map<string, int> clothes) {
	map<string, int>::iterator it;
	int count = 1;
	for (it = clothes.begin(); it != clothes.end(); it++) {
		count *= (it->second + 1);
	}
	return count - 1;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		map<string, int> clothes;
		string temp;
		for (int j = 0; j < n; j++) {
			cin >> temp >> temp;
			clothes[temp] ++;
		}
		cout << wear(clothes) << endl;
	}
}