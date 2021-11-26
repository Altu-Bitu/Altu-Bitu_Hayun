#include <iostream>

using namespace std;

struct node_info {
	int data;
	node_info *left;
	node_info *right;
};

node_info *makeTree(node_info *node, int data) {	//재귀로 트리 생성하는 함수
	if (node == NULL) {	//이번 노드가 들어가게 될 위치
		node = new node_info();	//동적할당
		node->data = data;	//data 초기화
		node->left = node->right = NULL;	//left, right 포인터 초기화
	}
	else if (node->data > data) {	//왼쪽 서브트리로 이동
		node->left = makeTree(node->left, data);	//왼쪽 서브트리에서 재귀
	}
	else if (node->data < data) {	//오른쪽 서브트리로 이동
		node->right = makeTree(node->right, data);	//오른쪽 서브트리에서 재귀
	}
	return node;
}

void postorder(node_info *node) {	//후위순회
	if (node == NULL)	//현재 node가 NULL이면
		return;	//바로 리턴

	postorder(node->left);	//왼쪽 서브트리 순회
	postorder(node->right);	//오른쪽 서브트리 순회
	cout << node->data << '\n';	//루트 출력
}

/*
맵과 셋 PPT 중 BST 노드 삽입 과정 참고

트리 구성 풀이
1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
4. 완성한 트리를 후위 순회
*/

int main() {
	int input;

	//입력 & 연산
	node_info *root = NULL;
	while (cin >> input)
		root = makeTree(root, input);	//input 받으면서 바로 tree 생성

	//출력
	postorder(root);
}