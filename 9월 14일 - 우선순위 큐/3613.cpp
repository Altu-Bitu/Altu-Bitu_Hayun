#include <iostream>
#include <string>
using namespace std;

// Æ²·È½À´Ï´Ù

bool isCpp(string a){
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z')
			return false;
	}
	return true;
}

bool isJava(string a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '_')
			return false;
	}
	return true;
}

string toJava(string a) {
	string b;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '_') {
			b.push_back(toupper(a[i + 1]));
			i++;
		}
		else
			b.push_back(a[i]);
	}
	return b;
}
string toCpp(string a) {
	string b;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			b.push_back('_');
			b.push_back(tolower(a[i]));
		}
		else
			b.push_back(a[i]);
	}
	return b;
}

int main() {
	string a;
	cin >> a;
	if (!isJava(a) && isCpp(a))
		cout << toJava(a);
	else if (isJava(a) && !isCpp(a))
		cout << toCpp(a);
	else
		cout << "Error!";
}