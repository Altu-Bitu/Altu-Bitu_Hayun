#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void getMax(string s) {	
	string max_mk = "";		//바로 push back할 수 있도록 string으로
	int last_k = -1;
	string temp = "";	//M을 변환해 담아둘 string
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {	//K가 나오면 5를 붙이고
			max_mk.push_back('5');
			max_mk += temp;
			temp = "";
			last_k = i;	//K 인덱스 업데이트

		}
		else {
			temp.push_back('0');
		}
	}
	for(int i = last_k + 1; i < s.size(); i++)	//남은 M의 개수는 전부 1로 붙인다
		max_mk.push_back('1');

	cout << max_mk << endl;
}

void getMin(string s) {	
	string min_mk = "";
	int last_k = -1;
	string temp = "";	//M을 변환해 담아둘 string
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {	//K가 나오면
			min_mk += temp;
			min_mk.push_back('5');	//5를 붙인다.
			temp = "";
			last_k = i;		//K 인덱스 업데이트
		}
		else {
			if (temp.size() == 0)
				temp.push_back('1');
			else
				temp.push_back('0');
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