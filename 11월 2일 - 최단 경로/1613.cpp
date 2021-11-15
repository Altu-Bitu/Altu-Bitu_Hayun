#include <iostream>
#include <vector>

using namespace std;

//플로이드-워셜

void floydWarshall(int n, vector<vector<bool>> &graph) {	//정점들의 전후 관계가 있는지 여부를 그래프에 갱신하는 함수
	//정점 i와 j의 전후관계 확인 시 i와 k, j와 k의 관계가 있는지
	for (int k = 1; k <= n; k++) {	//i와 j 사이에 일어난 사건
		for (int i = 1; i <= n; i++) {	//전에 일어난 사건
			for (int j = 1; j <= n; j++) {	//후에 일어난 사건
				if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
					graph[i][j] = true;			//i와 j도 전후관계가 있다
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, s, a, b;	//사건의 개수, 전후관계의 개수, 알고싶은 사건 쌍의 개수, 전후관계의 두 사건

	//입력
	cin >> n >> k;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));	//인접 행렬 형태의 그래프 (모두 모르는 것으로, false로 초기화)
	while (k--) {
		cin >> a >> b;
		graph[a][b] = true; //전후관계 -> 단방향 그래프
	}

	//연산
	floydWarshall(n, graph);	//전후관계 갱신한 그래프

	//입력 & 출력
	cin >> s;	//사건의 전후 관계를 알고 싶은 사건 쌍의 수
	while (s--) {
		cin >> a >> b;	//서로 다른 두 사건의 번호
		if (graph[a][b])		//앞에 있는 번호의 사건이 먼저 일어났으면 -1
			cout << "-1";
		else if (graph[b][a])	//뒤에 있는 번호의 사건이 먼저 일어났으면 1
			cout << "1";
		else					//모르면 0
			cout << "0";
		cout << '\n';
	}
	return 0;
}