#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���̳��� ���α׷��� Ȱ��

vector<int> dp(100001, 100000);	//���� �� �����ϴ� dp �迭 (������ ��ġ�� 100,000���� �۰ų� ����)
vector<int> coin(100);			//���Ǵ� ������ �� �迭
int minCoin(int n, int k) {
	for (int i = 0; i < n; i++) {		//�� �������� �ּҰ� ��� �� ����
		for (int j = 1; j <= k; j++) {
			if (j > coin[i])			//���� ������ �������� Ŀ����
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] >= 100000) //�Ұ����� ��� (�ʱ�ȭ�� �� ��Ŵ)
		return -1;
	return dp[k];
}

int main() {
	int n, k, temp;
	//�Է�
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp;
		coin[i] = temp;
		dp[temp] = 1;
	}
	//����
	cout << minCoin(n, k);
}