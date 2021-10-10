#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void getMax(string s) {	
	string max_mk = "";		//바로 push back할 수 있도록 string으로
	int last_k = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {	//K가 나오면 5를 붙이고
			max_mk.push_back('5');
			for (int j = 0; j < i - last_k -1; j++) {	//M 개수만큼 0을 붙인다 (이전 K 위치로 M 개수 파악)
				max_mk.push_back('0');
			}
			last_k = i;	//K 인덱스 업데이트
		}
	}
	for(int i = last_k + 1; i < s.size(); i++)	//남은 M의 개수는 전부 1로 붙인다
		max_mk.push_back('1');

	cout << max_mk << endl;
}

void getMin(string s) {	
	string min_mk = "";
	int last_k = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {	//K가 나오면
			for (int j = 0; j < i - last_k - 1; j++) {	//M의 개수만큼 10...0 붙인다
				if (j == 0)
					min_mk.push_back('1');
				else
					min_mk.push_back('0');
			}
			min_mk.push_back('5');	//5를 붙인다.
			last_k = i;		//K 인덱스 업데이트
		}
	}
	for (int i = last_k + 1; i < s.size(); i++) {	//남은 M의 개수만큼 10...0 붙인다
		if (i == last_k + 1)
			min_mk.push_back('1');
		else
			min_mk.push_back('0');
	}
	cout << min_mk << endl;
}


int main() {
	string s;
	cin >> s;
	getMax(s);
	getMin(s);
}