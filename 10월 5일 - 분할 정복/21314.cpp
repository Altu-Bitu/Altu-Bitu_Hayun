#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//틀렸습니다.
//어디서 틀린지 모르겠다..???

int toDec(string s) {	//민겸 수 -> 10진수
	int dec = 1;
	if (s[s.size() - 1] == 'K')
		dec *= 5;
	if (s.size() >= 2)
		dec *= pow(10, s.size() - 1);
	return dec;
}

void getMax(string s) {	//K로 끝나는 민겸 수를 십진수로 변환
	string temp = "";
	vector<int> max_mk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {
			temp += s[i];
			max_mk.push_back(toDec(temp));
			temp = "";
		}
		else
			temp += s[i];
	}
	for(int i = 0; i < temp.size(); i++)	//K로 끝나지 않는다면 전부 1로 출력
		max_mk.push_back(1);
	for (int i = 0; i < max_mk.size(); i++) {
		cout << max_mk[i];
	}
	cout << endl;
}

void getMin(string s) {	//M끼리는 합치고 K는 5로 변환
	string temp = "";
	vector<int> min_mk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {
			if (temp != "") {
				min_mk.push_back(toDec(temp));
				temp = "";
			}
			min_mk.push_back(5);
		}
		else {
			temp += s[i];
		}
	}
	if(temp != "")
		min_mk.push_back(toDec(temp));
	for (int i = 0; i < min_mk.size(); i++) {
		cout << min_mk[i];
	}
	cout << endl;
}


int main() {
	string s;
	cin >> s;
	getMax(s);
	getMin(s);
}