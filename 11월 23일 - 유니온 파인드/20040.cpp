#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0)	//값이 음수라면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
		return;
	if (parent[xp] > parent[yp]) //새로운 루트 xp
		parent[yp] = xp;
	else //새로운 루트 yp
		parent[xp] = yp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y;
	
	//입력
	cin >> n >> m;
	parent.assign(n, -1);

	//연산
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (findParent(x) == findParent(y)) {	//루트 노드가 같다면 사이클 만들어짐
			//출력
			cout << i + 1;
			return 0;
		}
		unionInput(x, y);
	}
	cout << 0;	//m번 이후에 종료되지 않았다면 0 출력
	return 0;
}