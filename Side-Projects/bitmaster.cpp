#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

//supported up to hexademical
//decimal -> hex
string get_hex(const int num, const int hex) {
	vector<char> ch = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	stack<char> s;
	string str = "";

	int b = num;
	int q = 0;
	int r = 0;

	while (true) {
		q = b / hex;
		r = b % hex;

		s.push(ch[r]);
		b = q;

		if (b <= hex - 1) {
			s.push(ch[b]);
			break;
		}
	}

	while (!s.empty()) {
		str += s.top();
		s.pop();
	}

	return str;
}

//supported up to hexademical
//hex -> decimal
int get_decimal(const string& str, const int hex) {
	int sum = 0;
	int num = 0;
	int e = 0;

	for (int i = str.size() - 1; i >= 0; i--) {
		char ch = str[i];
		int weighted = (int)pow(hex, e++);

		if (ch >= '0' && ch <= '9') num = ch - '0';
		else if (ch >= 'a' && ch <= 'f') num = 10 + ch - 'a';

		sum += weighted * num;
	}

	return sum;
}

int main() {
	int option;
	bool need_to_exit = false;

	int num;
	string str;
	int hex;

	while (true) {
		cout << "BitMaster by syntaxERROR..\n\n" << "1. decimal -> hex\n" << "2. hex -> decimal\n" << "3. clear screen\n" << "4. exit\n" << "Please select the option: ";
		cin >> option;
		cout << '\n';

		switch (option) {
		case 1:
			cout << "Please input the number to convert (for decimal): ";
			cin >> num;
			cout << "Please input the hex number to convert (ex: 2, 8, 16): ";
			cin >> hex;

			str = get_hex(num, hex);
			cout << "\n\n" << str << "\n\n";

			break;

		case 2:
			cout << "Please input the string to convert (not decimal): ";
			cin >> str;
			cout << "Please input the hex number: ";
			cin >> hex;

			num = get_decimal(str, hex);
			cout << "\n\n" << num << "\n\n";

			break;

		case 3:
			system("cls");
			break;

		case 4:
			need_to_exit = true;
			break;
		}

		if (need_to_exit) break;
	}
	
	return 0;
}