#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//어디가 틀린지 모르겠다.

int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n;
vector<int> tree[10][10];
vector<vector<int>> nutrient;		//각 위치의 양분 정보
vector<vector<int>> a;				//겨울에 추가되는 각 위치의 양분 정보



void grow() {
	//봄: 나무가 자신의 나이만큼 양분 먹기(한 칸만) -> 나이 1 증가, 어린나무부터 양분 먹음, 못 먹으면 즉시 죽음
	//여름: 죽은 나무 -> 양분, 죽은 나무의 나이를 2로 나눈 값
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() <= 0)
				continue;

			sort(tree[i][j].begin(), tree[i][j].end());

			int summer = 0;
			vector<int> alive;
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (nutrient[i][j] - age >= 0) {
					nutrient[i][j] -= age;
					alive.push_back(age++);
				}
				else {
					summer += age / 2;
					
				}
			}
			nutrient[i][j] += summer;

			tree[i][j].clear();
			for (int k = 0; k < alive.size(); k++)
				tree[i][j].push_back(alive[k]);
		}
	}

	//가을: 나무 번식, 번식 나무는 나이가 5의 배수, 인접한 8칸에 나이 1인 나무 생김.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() <= 0)
				continue;

			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nr = i + dr[d], nc = j + dc[d];
						if (nr < 0 || nr >= n || nc < 0 || nc >= n)
							continue;
						tree[nr][nc].push_back(1);
					}
				}
			}
		}
	}
	//겨울: 각 칸에 양분 추가
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			nutrient[i][j] += a[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, k, r, c, age;
	cin >> n >> m >> k;
	
	nutrient.assign(n, vector<int>(n));
	a.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}
	for (int i = 0; i < k; i++) {
		grow();
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += tree[i][j].size();
		}
	}
	cout << result;
}