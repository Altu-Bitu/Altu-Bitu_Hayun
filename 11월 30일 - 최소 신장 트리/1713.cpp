#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, candidate;
	cin >> n >> m;
	map<int, ci> photo;	//{학생 번호, {추천 횟수, 게시 시간}}
	int time = 0;

	while(m--) {
		cin >> candidate;
		//이미 게시된 학생이면 추천 횟수만 증가
		if (photo.find(candidate) != photo.end()) {
			photo[candidate].first++;
		}
		//아니라면
		else {
			//비어있는 사진틀이 없으면
			if (photo.size() >= n) {
				int temp = 1001;
				map<int, ci>::iterator erase;
				
				//추천수가 적은 학생 삭제
				for (auto iter = photo.begin(); iter != photo.end(); iter++) {
					if (temp > iter->second.first) {
						temp = iter->second.first;
						erase = iter;
					}
				}

				//아니면 오래된 학생 삭제
				for (auto iter = photo.begin(); iter != photo.end(); iter++) {
					if (temp == iter->second.first) {
						if (erase->second.second > iter->second.second)
							erase = iter;
					}
				}
				photo.erase(erase);
				photo.insert({ candidate, {1, time++} });
			}

			//비어있는 사진틀이 있으면 그냥 삽입
			else {
				photo.insert({ candidate, {1, time++} });
			}
		}
	}
	for (auto iter = photo.begin(); iter != photo.end(); iter++) {
		cout << iter->first << " ";
	}
	return 0;
}