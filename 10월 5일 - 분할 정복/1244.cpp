#include <iostream>
#include <vector>
using namespace std;

//구현, 시뮬레이션

int n;
bool light[101];

void male(int num) {	//스위치 번호가 자기가 받은 수의 배수라면 상태를 바꾼다.
	for (int i = num; i <= n; i+=num) {
		light[i] = !light[i];
	}
}

void female(int num) {	//좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간의 스위치의 상태를 모두 바꾼다. 
	light[num] = 1 - light[num];
	for (int i = 1; ; i++) {
		if (num - i >= 1 && num + i <= n && light[num - i] == light[num + i]) {
			light[num - i] = !light[num - i];
			light[num + i] = !light[num + i];
		}
		else
			break;
	}
}

void onOff(vector<pair<int, int>> student) {
	for (int i = 0; i < student.size(); i++) {
		if (student[i].first == 1)
			male(student[i].second);
		else
			female(student[i].second);
	}
}

int main() {
	int  m;
	//입력
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> light[i];
	cin >> m;
	vector<pair<int, int>> student(m);
	for (int i = 0; i < m; i++) {
		cin >> student[i].first >> student[i].second;
	}
	
	//연산
	onOff(student);

	//출력
	for (int i = 1; i <= n; i++) {
		cout << light[i] << " ";
		if (i % 20 == 0)
			cout << '\n';
	}
}