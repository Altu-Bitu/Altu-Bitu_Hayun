#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Ʋ�Ƚ��ϴ�. 
// ��� Ǫ���� �𸣰ڴ�

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
	//  �ʿ� ���ǽ��� �ּҰ� �Ƿ��� �ִ��� ���� ������ �̾ �ؾ߰���. �̾ ������ ������ ���ǽ��� ���� ����� � ���ǽ��� �����ؾ� ���ǽ��� ȿ�������� ����� �� �������?
	// ���� t���� ũ�ų� ���� s �� t�� ���� ���� ����?

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