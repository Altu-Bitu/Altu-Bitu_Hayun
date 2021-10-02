#include <iostream>
#include <algorithm>
using namespace std;

//���̳��� ���α׷��� Ȱ��

int minCost(int rgb[][3], int n) {
	for (int i = 1; i < n; i++) {
		rgb[i][0] += min(rgb[i - 1][1], rgb[i - 1][2]); //���� ������ ���� �ʷ�, ���� �Ķ� �� �ּҰ��� �ջ�
		rgb[i][1] += min(rgb[i - 1][0], rgb[i - 1][2]); 
		rgb[i][2] += min(rgb[i - 1][0], rgb[i - 1][1]);
	}
	return min(rgb[n - 1][0], min(rgb[n - 1][1], rgb[n - 1][2])); //min�Լ��� �Ű������� 2���� ����
}

int main() {
	int n;
	//�Է�
	cin >> n;
	int rgb[1000][3];
	for (int i = 0; i < n; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	//����
	cout << minCost(rgb, n);
}