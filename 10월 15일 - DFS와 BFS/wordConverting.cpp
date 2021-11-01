#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//너비 우선 탐색
//두 노드 사이 최단 거리

int solution(string begin, string target, vector<string> words) {
	
	words.insert(words.begin(), begin);	//begin을 words에 삽입
	int n = words.size();

	vector<vector<int>> adj_list(n, vector<int>());	//인접리스트 생성 (문자 하나 차이나는 노드끼리 연결)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (i == j) continue;
			for (int k = 0; k < words[i].size(); k++) {
				if (words[i][k] != words[j][k])
					cnt++;
				if (cnt > 1)
					break;
			}
			if(cnt == 1)
				adj_list[i].push_back(j);
		}
	}
	
	queue<int> q;
	vector<int> visited(n, 0);

	q.push(0);		//begin 노드 삽입
	visited[0] = 1;	//방문 체크

	//탐색 시작
	while (!q.empty()) {
		int node = q.front();	//현재 탐색하려는 노드
		q.pop();
		for (int i = 0; i < adj_list[node].size(); i++) {	//연결된 노드만 탐색
			if (words[adj_list[node][i]] == target)			//만약 target을 찾았다면 현재까지의 거리 리턴
				return visited[node];
			if (!visited[adj_list[node][i]]) {	//이미 방문했는지
				visited[adj_list[node][i]] = visited[node] + 1;
				q.push(adj_list[node][i]);
			}
		}
	}

	return 0;
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

	cout << solution(begin, target, words);
}