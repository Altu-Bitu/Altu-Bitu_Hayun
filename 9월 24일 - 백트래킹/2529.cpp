#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//브루트포스 알고리즘, 백트래킹 활용 (백트래킹을 잘 활용했는지..? 잘 모르겠다)

const int SIZE = 10;
int num[SIZE]; //만들어지는 정수 배열
vector<string> total;
bool check[SIZE] = { false, }; //사용된 수 체크하는 배열
char sign[SIZE]; //부등호 기호가 들어가는 배열
int n;

void search(int cnt, int k) {	//cnt: num의 인덱스, k: num[cnt]에 들어갈 수
	if (cnt == n) {				//기저조건: 인덱스가 n이 되었을 때 (num배열을 0부터 n까지 채워야함)
		num[cnt] = k;			//num[n]은 k로 채움
		string temp;			//0부터 시작할 수 있어서 string으로 만듦
		for (int i = 0; i <= n; i++)
			temp += to_string(num[i]); // **to_string으로 int -> string
		total.push_back(temp);	//total에 추가
		return;
	}
	check[k] = true;	//k는 사용되었으므로 check
	num[cnt] = k;		//num[cnt]를 k로 채움
	for (int i = 0; i < 10; i++) {
		if (check[i])	//i가 이미 사용되었다면 사용하지 못하므로 continue
			continue;
		if (sign[cnt] == '<' && num[cnt] < i)	//부등호가 <라면 num[cnt]보다 큰 수로 재귀
			search(cnt + 1, i);
		else if (sign[cnt] == '>' && num[cnt] > i) //부등호가 >라면 num[cnt]보다 작은 수로 재귀
			search(cnt + 1, i);
	}
	check[k] = false;	//다시 check 원상복구 
}



int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> sign[i];
	}
	for (int i = 0; i < 10; i++) {
		search(0, i); //시작하는 수 0부터 9까지
	}
	sort(total.begin(), total.end());
	cout << total[total.size() - 1] << '\n';
	cout << total[0];
}