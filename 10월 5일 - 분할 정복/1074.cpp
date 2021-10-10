#include <iostream>
#include <cmath>
using namespace std;

//분할 정복, 재귀

int getZ(int n, int x, int y) {
	//Conquer
	 if (n == 0)
		return 0;

	int cnt = 0;
	//Divide
	int place;	//몇번째 칸인지 저장
	if (0 <= x && x < pow(2, (n - 1))) {
		if (0 <= y && y < pow(2, (n - 1)))
			place = 0;
		else {
			place = 1;
			y -= (pow(2, (n - 1)));
		}
	}
	else {
		if (0 <= y && y < pow(2, (n - 1)))
			place = 2;
		
		else {
			place = 3;
			y -= (pow(2, (n - 1)));
		}

		x -= (pow(2, (n - 1)));
	}

	//Combine
	cnt += (pow(2, (n - 1)) * pow(2, (n - 1)) * place);	//이전의 칸들을 합치고
	cnt += getZ(n - 1, x, y);	//2^(n-1) * 2^(n-1)에서 몇번째 칸인지 재귀로 구해 더한다

	return cnt;
}

int main() {
	int n, r, c;
	//입력
	cin >> n >> r >> c;
	
	//연산 & 출력
	cout << getZ(n, r, c);
}