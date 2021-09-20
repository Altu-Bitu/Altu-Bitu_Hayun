#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 틀렸습니다. 
// 어떻게 푸는지 모르겠다

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first != b.first)
			return a.first > b.first;
		return a.second > b.second;
	}
};

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//  필요 강의실이 최소가 되려면 최대한 많은 수업을 이어서 해야겠죠. 이어서 수업이 가능한 강의실이 여러 개라면 어떤 강의실을 선택해야 강의실을 효율적으로 사용할 수 있을까요?
	// 이전 t보다 크거나 같은 s 중 t가 가장 작은 수업?

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	vector<pair<int, int>> v;
	int n, s, t, result;
	cin >> n;
	while (n--) {
		cin >> s >> t;
		v.push_back(make_pair(s, t));
	}
	sort(v.begin(), v.end(), cmp);
	pq.push(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (pq.top().second <= v[i].first) {
			pq.pop();
			pq.push(v[i]);
		}
		else
			pq.push(v[i]);
	}

	cout << pq.size();
}