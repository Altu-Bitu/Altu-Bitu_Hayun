#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0 || parent[node] == node) //값이 음수, 자신 인덱스라면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
		return;
	if (xp == parent[xp])	
		parent[yp] = xp;
	else
		parent[xp] = yp;
}

int main() {
	int n, m, num, idx;
	//입력
	cin >> n >> m >> num;
	parent.assign(n + 1, -1);
	vector<vector<int>> party(m, vector<int>());

	if (num == 0) {	//진실을 아는 사람이 없으면 바로 출력
		cout << m << "\n";
		return 0;
	}

	for(int i = 0; i < num; i++) {
		cin >> idx;
		parent[idx] = idx;	//진실을 아는 사람은 자신의 인덱스로 저장, 모르는 사람은 -1
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> idx;
			party[i].push_back(idx);
		}
		
		for (int j = 1; j < num; j++) {
			unionInput(party[i][0], party[i][j]);
		}
	}
	
	//연산
	int count = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			int tmp = findParent(party[i][j]);
			if (parent[tmp] != tmp) { //진실을 알고 있는 사람이 없으면 과장 (모르는 사람은 -1)
				count++;
				break;
			}
		}
	}

//	for (int i = 1; i <= n; i++)
//		cout << parent[i] << " ";
//	cout << '\n';

	//출력
	cout << count << '\n';
	return 0;

}