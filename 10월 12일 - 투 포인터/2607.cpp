#include <iostream>
#include <vector>
#include <string>

using namespace std;

//구현, 문자열
//더 간단한 방법이 있을 것 같다..

int main() {
	int n;
	//입력
	cin >> n;
	vector<vector<int>> alphabet(n, vector<int>(26));	//각 단어의 알파벳 개수 저장하는 이차원 벡터

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		for (int j = 0; j < word.size(); j++) {
			alphabet[i][word[j] - 'A']++;
		}
	}

	int result = 0;		//비슷한 단어 개수
	for (int i = 1; i < n; i++) {
		int count = 0;	//알파벳 개수 차이가 나는 경우를 세는 변수 
		int check = 0;	//알파벳 개수 차이를 합하는 변수

		for (int j = 0; j < 26; j++) {
			int diff = alphabet[0][j] - alphabet[i][j];
			if (abs(diff) != 0) {
				check += diff;
				count++;
				if (abs(diff) > 1)	//차이가 2 이상이면 걸러지도록
					count++;
			}
		}
		if ((check == 0 && (count == 2) || (count == 0)) || (abs(check) == 1 && count == 1))
			result++;
	}



	/*
	int result = 0;		//비슷한 단어 개수
	for (int i = 1; i < n; i++) {
		int count = 0;	//알파벳 개수 차이가 1인 경우를 세는 변수 (한 문자를 다른 문자로 바꾸는 경우 count = 2, 한 문자를 더하거나 뺴는 경우 count = 1)
		int check = 0;	//알파벳 개수 차이를 합하는 변수 (한 문자를 다른 문자로 바꾸는 경우 check = 0, 한 문자를 더하거나 빼는 경우는 check = 1)
		bool two_diff = false;	//알파벳 개수 차이가 2 이상이라면 예외
		for (int j = 0; j < 26; j++) {
			if (abs(alphabet[0][j] - alphabet[i][j]) >= 2) {
				two_diff = true;
				break;
			}
			else if (abs(alphabet[0][j] - alphabet[i][j]) == 1) {
				check += (alphabet[0][j] - alphabet[i][j]);
				count++;
			}
		}
		if (abs(check) <= 1 && count <= 2 && !two_diff)	//하나의 문자가 더해지거나 빼지거나 바뀌는 경우만 걸러지게 된다.
			result++;
	}
	*/
	//출력
	cout << result;
}