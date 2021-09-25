#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����, �ùķ��̼�
// �� Ǯ�ڴ�... ���...

vector<int> belt;
vector<bool> robot;
queue<int> robot_q;
int step = 0, broken = 0;
int up, down;

void rotate(int n, int k) {
	while (true) {
		step++;
		// 1��
		up = up - 1 > 0 ? up - 1 : 2 * n - 1;
		down = down - 1 > 0 ? down - 1 : 2 * n - 1;

		robot[down] = false;

		// 2��
		for (int i = 0; i < robot.size(); i++) {
			if (robot[i] == true && robot[(i + 1) % (2 * n - 1)] == false && belt[(i + 1) % (2 * n)] > 0) {
				robot[i] = false;
				robot[(i + 1) % (2 * n - 1)] = true;
				belt[(i + 1) % (2 * n - 1)]--;
				if (belt[(i + 1) % (2 * n - 1)] == 0)
					broken++;
			}
		}

		// 3��
		if (belt[up] > 0) {
			robot[up] = true;
			belt[up]--;
			if (belt[up] == 0)
				broken++;
		}
		
		// 4��
		if (broken >= k)
			break;
	}
}

int main() {
	// �����̳� ��Ʈ�� ȸ���ϴ� �� ���� ���� ������ �ʿ� ���� �� ���ƿ�.��Ʈ�� �����غ���� ? �� ���¿��� ȸ���� ��� ǥ���� �� ������� ? �׸��� ���� ���� �ö�� �κ��� �׻� ������ ��ġ�� ���� ������.

	// ��: 1, ��: N -> ȸ�� -> ��: 2N, ��: N-1
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