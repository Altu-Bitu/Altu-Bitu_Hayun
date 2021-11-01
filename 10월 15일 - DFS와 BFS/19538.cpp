#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//너비 우선 탐색
//시간 초과 주의! + 맞았는데도 시간이 엄청 오래 걸린다..

int n;
vector<vector<int>> ppl;
vector<int> infected;
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		
		for (int i = 0; i < ppl[node].size(); i++) {
			int next_node = ppl[node][i];
			if (infected[next_node] != -1) continue;	//루머를 믿고 있는지 먼저 확인

			int infect_cnt = 0;
			for (int i = 0; i < ppl[next_node].size(); i++) {
				if (infected[ppl[next_node][i]] > -1 && infected[ppl[next_node][i]] <= infected[node])	 //next_node의 주변인이 몇 명이나 루머를 믿고 있는지 (현재 node 시점에서 확인해야하므로 조건 추가)
					infect_cnt++;
			}
			if (ppl[next_node].size() <= infect_cnt * 2) {
				q.push(next_node);
				infected[next_node] = infected[node] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, input;
	//입력
	cin >> n;
	ppl.assign(n + 1, vector<int>());
	infected.assign(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		while (true) {
			cin >> input;
			if (!input)
				break;
			ppl[i].push_back(input);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		infected[input] = 0;
		q.push(input);
	}

	//연산
	bfs();
	
	//출력
	for (int i = 1; i <= n; i++)
		cout << infected[i] << ' ';
	return 0;
}