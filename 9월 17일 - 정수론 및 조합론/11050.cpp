#include <iostream>
#include <algorithm>
using namespace std;

// 이항계수 정의 활용
// 의도대로 작성한지 모르겠음

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
	//수학의 정의와 완벽하게 일치해요. 이항계수는 무엇과 같았죠?
	int a, b;
	cin >> a >> b;
	cout << coef(a, b);
}