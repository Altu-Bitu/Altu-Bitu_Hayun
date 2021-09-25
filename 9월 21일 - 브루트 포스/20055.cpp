#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 구현, 시뮬레이션
// 못 풀겠다... 어렵...

vector<int> belt;
vector<bool> robot;
queue<int> robot_q;
int step = 0, broken = 0;
int up, down;

void rotate(int n, int k) {
	while (true) {
		step++;
		// 1번
		up = up - 1 > 0 ? up - 1 : 2 * n - 1;
		down = down - 1 > 0 ? down - 1 : 2 * n - 1;

		robot[down] = false;

		// 2번
		for (int i = 0; i < robot.size(); i++) {
			if (robot[i] == true && robot[(i + 1) % (2 * n - 1)] == false && belt[(i + 1) % (2 * n)] > 0) {
				robot[i] = false;
				robot[(i + 1) % (2 * n - 1)] = true;
				belt[(i + 1) % (2 * n - 1)]--;
				if (belt[(i + 1) % (2 * n - 1)] == 0)
					broken++;
			}
		}

		// 3번
		if (belt[up] > 0) {
			robot[up] = true;
			belt[up]--;
			if (belt[up] == 0)
				broken++;
		}
		
		// 4번
		if (broken >= k)
			break;
	}
}

int main() {
	// 컨테이너 벨트가 회전하는 걸 굳이 직접 구현할 필욘 없을 것 같아요.벨트를 고정해볼까요 ? 이 상태에서 회전은 어떻게 표현할 수 있을까요 ? 그리고 가장 먼저 올라온 로봇은 항상 내리는 위치와 제일 가깝죠.

	// 올: 1, 내: N -> 회전 -> 올: 2N, 내: N-1
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> temp;
		belt.push_back(temp);
	}
	up = 0;
	down = 2 * n - 1;
	for (int i = 0; i < 2 * n; i++) {
		robot.push_back(false);
	}
	rotate(n, k);
	cout << step;
}