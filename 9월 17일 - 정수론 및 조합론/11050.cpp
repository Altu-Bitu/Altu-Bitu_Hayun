#include <iostream>
#include <algorithm>
using namespace std;

// ���װ�� ���� Ȱ��
// �ǵ���� �ۼ����� �𸣰���

int coef(int a, int b) {
	int coef_a = 1, coef_b = 1;
	for (int i = b + 1; i <= a; i++) {
		coef_a *= i;
	}
	for (int i = 1; i <= a-b; i++) {
		coef_b *= i;
	}
	return coef_a / coef_b;
}

int main() {
	//������ ���ǿ� �Ϻ��ϰ� ��ġ�ؿ�. ���װ���� ������ ������?
	int a, b;
	cin >> a >> b;
	cout << coef(a, b);
}