#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

bool check_brackets_expressions(string code) {
	map<char, char> bracketf;
	stack<char> s;

	bracketf[')'] = '(';
	bracketf[']'] = '[';
	bracketf['}'] = '{';
	
	for (int i = 0; i < code.size(); i++) {
		char bracket = code[i];

		switch (bracket) {
			case '(': case '[': case '{':
				s.push(bracket);
				break;

			case ')': case ']': case '}':
				if (s.top() == bracketf[bracket]) s.pop();
				else return false;

				break;
		}
	}

	return s.empty();
}

int main() {
	string code;
	getline(cin, code);

	bool expression = check_brackets_expressions(code);

	if (expression) cout << "성공" << endl;
	else cout << "오류" << endl;

	return 0;
}