#include <iostream>
#include <algorithm>

using namespace std;

// 유클리드 호제법 활용, A * B = G * L
// A/G와 B/G는 서로소라는 성질 활용

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
	//최대공약수와 최소공배수의 성질을 떠올려보세요. 두 수 A, B가 있을 때 A와 B의 곱은 최대공약수와 최소공배수의 곱과 같았었죠? 그리고 또 어떤 성질이 있었나요?
	
	int g, l;
	cin >> g >> l;

	cout << getA(g, l) * g << " " << l / getA(g, l);

}