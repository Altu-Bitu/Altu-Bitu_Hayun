#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

//어렵지 않은 문제인데 방법을 바꿔서 해볼 걸 그랬다
//deque 사용한 것이 좋은 것 같다. 정렬을 한 번만 하면 됨

typedef vector<vector<int>> matrix;
typedef tuple<int, int, int> tp;


queue<tp> spring(matrix &land, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {	//봄
	queue<tp> dead_tree;
	int size = tree.size();
	while (size--) {	//모든 나무 검사
		int age = get<0>(tree.front());	//나이
		int row = get<1>(tree.front());	//행
		int col = get<2>(tree.front());	//열
		tree.pop_front();	//가장 어린 나무 pop하기
		
		if (land[row][col] < age) {	//자신의 나이만큼 양분을 먹을 수 없다면
			dead_tree.push({ age, row, col });	//즉시 죽음 (dead_tree 큐에 삽입)
			continue;
		}
		land[row][col] -= age;	//나이만큼 양분 먹기
		tree.emplace_back(age + 1, row, col);	//나이 1 증가하고 추가
		if ((age + 1) % 5 == 0)	//나이가 5의 배수라면
			breeding_tree.push({ row, col });	//가을에 번식함 (breeding_tree 큐에 삽입)
	}
	return dead_tree;	//죽은 나무 정보를 반환 (여름에 양분이 됨)
}

void summer(queue<tp> &dead_tree, matrix &land) {	//여름
	while (!dead_tree.empty()) {	//더 이상 죽은 나무가 없을 때까지
		int age = get<0>(dead_tree.front());	//죽은 나무의 나이
		int row = get<1>(dead_tree.front());	//죽은 나무의 행
		int col = get<2>(dead_tree.front());	//죽은 나무의 열
		dead_tree.pop();	//현재 나무 pop하기
		land[row][col] += (age / 2);	//죽은 나무의 나이 / 2만큼 해당 땅에 양분 추가
	}
}

void fall(int n, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {
	int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };	//인접한 8칸의 행 정보
	int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };	//인접한 8칸의 열 정보

	while (!breeding_tree.empty()) {	//더 이상 번식할 나무가 없을 때까지
		int row = breeding_tree.front().first; //번식할 나무의 행
		int col = breeding_tree.front().second; //번식할 나무의 열
		breeding_tree.pop();	//현재 나무 pop하기

		for (int j = 0; j < 8; j++) {	//인접한 8개 칸에 대해서
			int nr = row + dr[j];	//새로운 칸의 행
			int nc = col + dc[j];	//새로운 칸의 열
			if (nr < 0 || nr >= n || nc < 0 || nc >= n)	//범위를 벗어나면 패스
				continue;
			tree.push_front({ 1, nr, nc });	//새로 생긴 나무 (나이가 1, tree의 front에 삽입)
		}
	}
}

void winter(int n, matrix &a, matrix &land) {	//겨울
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			land[i][j] += a[i][j];	//입력받은 a만큼 양분 추가
}

/*
[문제 설명] - 단순 구현 문제
봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
	각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
가을: 나이가 5의 배수인 나무가 번식, 인접한 8개 칸에 나이가 1인 나무가 생김
겨울: 로봇이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가

K년이 지난 후 상도의 땅에 살아있는 나무의 개수

[문제 풀이]
a: 로봇이 겨우렝 주는 양분의 양
land: 땅의 양분
breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
tree: 땅에 심은 나무 나이, 행, 열 정보
-> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능

문제의 설명대로 계절별 연산을 진행
*/

int main() {
	int n, m, k, x, y, z;

	//입력
	cin >> n >> m >> k;
	matrix a(n, vector<int>(n, 0));
	matrix land(n, vector<int>(n, 5));	//처음 양분 모든 칸에 5로 초기화
	queue<pair<int, int>> breeding_tree;	//번식할 트리
	deque<tp> tree;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	while (m--) {
		cin >> x >> y >> z;
		tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 1을 빼준 인덱스에 접근
	}

	//연산
	sort(tree.begin(), tree.end());	//상도가 심은 나무만 정렬함 (새로운 나무는 front에 삽입해서 이후엔 정렬 필요없음)
	while (k--) {
		queue<tp> dead_tree = spring(land, tree, breeding_tree);	//봄이 지나고 죽은 나무
		summer(dead_tree, land);		//죽은 나무 정보로 양분 추가
		fall(n, tree, breeding_tree);	//번식할 나무 정보로 tree에 추가
		winter(n, a, land);				//a 정보로 양분 추가
	}

	//출력
	cout << tree.size();

}