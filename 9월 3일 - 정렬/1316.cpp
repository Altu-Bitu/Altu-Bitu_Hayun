#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isGroup(string word) { 
	vector<bool> a(26, false);
	a[word[0] - 'a'] = true;
	for (int i = 1; i < word.length(); i++) {
		if (word[i] == word[i - 1]) // 연속글자 패스
			continue;
		else {
			if (a[word[i] - 'a'])
				return false;
			a[word[i] - 'a'] = true;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (isGroup(word))
			total++;
	}
	cout << total;
}