#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이분 탐색

typedef long long ll;	//M과 Tk의 범위가 10^9까지라 long long을 써준다
vector<ll> tk;	//각 심사대에서 걸리는 시간

ll count(ll second) {	//주어진 시간 동안 최대 몇 명을 심사할 수 있는지 계산
	ll total = 0;
	for (int i = 0; i < tk.size(); i++)
		total += (second / tk[i]);
	return total;
}

ll lowerSearch(ll left, ll right, ll target) {	//시간의 최솟값 -> lower bound를 구한다
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll ppl = count(mid);	//mid초가 주어졌을 때 최대 몇 명을 심사할 수 있는가?
		if (ppl >= target) {	//target 이상의 사람을 심사했다면 -> 초를 줄인다
			ans = mid;	//현재의 mid값 저장. 최종 갱신되는 값은 lower bound
			right = mid - 1;
		}
		else {	//target 미만의 사람을 심사했다면 -> 초를 늘린다
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	int n;
	ll m;

	//입력
	cin >> n >> m;
	tk.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> tk[i];

	//연산
	sort(tk.begin(), tk.end());

	//연산 & 출력
	//left: tk 중 가장 낮은 값 (확실X)
	//right: 최악의 경우 가장 오래 걸리는 줄에서 전부 심사
	cout << lowerSearch(tk[0], tk[n - 1] * m, m);
}