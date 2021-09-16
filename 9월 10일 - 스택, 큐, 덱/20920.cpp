#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	if(a.first.length() != b.first.length())
		return a.first.length() > b.first.length();
	
	return a.first < b.first;
}


int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> wordMap;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (temp.length() >= m) {
			wordMap[temp]++;
		}
	}

	vector<pair<string, int>> wordVec(wordMap.size());
	copy(wordMap.begin(), wordMap.end(), wordVec.begin());
	sort(wordVec.begin(), wordVec.end(), cmp);
	for (int i = 0; i < wordVec.size(); i++)
		cout << wordVec[i].first << '\n';

}