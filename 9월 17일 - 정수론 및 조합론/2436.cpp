#include <iostream>
#include <algorithm>

using namespace std;

// ��Ŭ���� ȣ���� Ȱ��, A * B = G * L
// A/G�� B/G�� ���μҶ�� ���� Ȱ��

int gcdRecursion(int a, int b) {
	if (b == 0)
		return a;
	return gcdRecursion(b, a%b);
}

int getA(int g, int l) {
	// A = a*g, B = b*g, l = a*b*g
	int x = l / g;
	int a;
	for (a = int(floor(sqrt(x))); a >= 1; a--) {
		if (x % a == 0) {
			int b = x / a;
			if (gcdRecursion(a, b) == 1)
				return a;
		}
	}
}

int main() {
	//�ִ������� �ּҰ������ ������ ���÷�������. �� �� A, B�� ���� �� A�� B�� ���� �ִ������� �ּҰ������ ���� ���Ҿ���? �׸��� �� � ������ �־�����?
	
	int g, l;
	cin >> g >> l;
	int a = getA(g, l);
	cout << a * g << " " << l / a;

}