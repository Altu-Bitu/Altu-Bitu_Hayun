#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

bool isGood(vector<int> &arr, int i) {
	bool ans = false;
	int target = arr[i];
	int size = arr.size(), left = 0, right = size - 1, sum;

	while (left < right) {
		sum = arr[left] + arr[right];
		if (sum == target) {
			if (left != i && right != i) {
				ans = true;
				break;
			}
			else if (left == i) {
				left++;
			}
			else if (right == i) {
				right--;
			}
		}
		else if (sum < target) {
			left++;
		}
		else if (sum > target) {
			right--;
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int n; 
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	
	int result = 0;
	for (int i = 2; i < n; i++) {
		if(isGood(arr, i))
			result++;
	}
	cout << result;
}