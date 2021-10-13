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
		level.insert(make_pair(val, name));
	}
	
	//연산 & 출력
	while (m--) {
		cin >> power;
		auto it = level.lower_bound(power);	//level의 key 값들 중 power의 lower bound에 해당하는 iter를 반환받는다
		cout << it->second << '\n';		//해당 iter의 value값(칭호)을 출력한다
	}
}