#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//이분 탐색 (map의 lower_bound 활용)

int main() {
	// map의 lower_bound 함수 검색 -> https://docs.microsoft.com/ko-kr/cpp/standard-library/map-class?view=msvc-160#lower_bound
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, m, power;
	//입력
	cin >> n >> m;
	map<int, string> level;
	for (int i = 0; i < n; i++) {
		string name;
		int val;
		cin >> name >> val;
		//map의 operator[]는 항목이 없으면 자동으로 초기값을 만든다 (int 0, double 0.0, string "")
		if (!level[val].empty())	//칭호가 여러 개인 경우 가장 먼저 입력된 칭호 하나만 출력한다.
			level[val] = name;
	}
	
	//연산 & 출력
	while (m--) {
		cin >> power;
		auto it = level.lower_bound(power);	//level의 key 값들 중 power의 lower bound에 해당하는 iter를 반환받는다
		cout << it->second << '\n';		//해당 iter의 value값(칭호)을 출력한다
	}
}