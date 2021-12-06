#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;

//MST (크루스칼)

typedef pair<int, int> ci;
typedef tuple<double, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0) //값이 음수면 루트 정점
		return node;
	return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)	//같은 집합에 있다면 유니온 할 수 없음
		return false;
	if (parent[xp] < parent[yp]) { //새로운 루트 xp
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { //새로운 루트 yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

//kruskal
double kruskal(int v, int cnt, priority_queue<tp, vector<tp>, greater<>> &pq) {
	
	double sum = 0;

	while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
		double weight = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (unionInput(x, y)) { 
			cnt++;
			sum += weight;
		}
	}
	return sum;
}

int main() {
	int n, m, a, b, cnt = 0;
	priority_queue<tp, vector<tp>, greater<>> pq;

	//입력
	cin >> n >> m;
	parent.assign(n, -1);
	vector<ci> god(n);
	for (int i = 0; i < n; i++){
		cin >> god[i].first >> god[i].second;
	}

	//이미 연결된 통로 유니온 처리
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (unionInput(a - 1, b - 1))
			cnt++;
	}

	//연산
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double xd = god[i].first - god[j].first;
			double yd = god[i].second - god[j].second;
			pq.push({ sqrt(xd * xd + yd * yd), i, j });
		}
	}

	//연산 & 출력
	cout << fixed;
	cout.precision(2);
	cout << kruskal(n, cnt, pq);
}