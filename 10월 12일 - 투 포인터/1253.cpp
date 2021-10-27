#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//투 포인터
//항상 음수도 테스트해보기!

vector<int> arr;

bool isGood(int i) {	//좋은 수: 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다
	bool ans = false;
	int target = arr[i];
	int left = 0, right = arr.size() - 1, sum;	//right = i - 1이 안되는 이유: Ai는 음수도 포함이다. 그래서 배열의 처음부터 끝까지 탐색해야함.

	while (left < right) {	
		sum = arr[left] + arr[right];
		if (sum == target) {	//target이 두 개의 합이면
			if (left != i && right != i) {	//left 또는 right가 i가 아닌지 확인
				ans = true;
				break;
			}
			else if (left == i) {	//만약 left가 i였다면 예외이므로 left 증가
				left++;
			}
			else if (right == i) {	//만약 right가 i였다면 예외이므로 right 감소
				right--;
			}
		}
		else if (sum < target) {	//sum이 target보다 작다면 수를 증가시켜야하므로 left 이동
			left++;
		}
		else if (sum > target) {	//sum이 target보다 크다면 수를 감소시켜야하므로 right 감소
			right--;
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int n;
	//입력
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산
	sort(arr.begin(), arr.end());

	int result = 0;
	for (int i = 0; i < n; i++) {
		if(isGood(i))	//Ai가 좋은 수인가? 맞다면 result 증가
			result++;
	}

	//출력
	cout << result;
}