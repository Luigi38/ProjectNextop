#include <iostream>
#include <vector>
#include <string>

struct operato {
	int number;
	int pm; //0: addition, 1: subtraction, -1: nothing
};
using namespace std;

void string_to_operatos(const string& str, vector<operato>& v) {
	int number = 0;
	bool isMinus = false;

	for (char ch : str) {
		if (ch >= '0' && ch <= '9') {
			number = number * 10 + ch - '0';
		}
		else if (ch == '+') {
			int pm = (isMinus ? 1 : 0);

			v.push_back({ number, pm });
			number = 0;
		}
		else if (ch == '-') {
			v.push_back({ number, 1 });
			number = 0;
			isMinus = true;
		}
	}
	v.push_back({ number, -1 });
}

int main() {
	vector<operato> v;
	string str;

	cin >> str;
	string_to_operatos(str, v);

	int result = 0;

	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && v[i - 1].pm == 1) v[i].number = -v[i].number;
		result += v[i].number;
	}

	cout << result << '\n';
	return 0;
}