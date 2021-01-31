#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

size_t get_bracket_end(const string& str, const size_t start) {
	stack<char> s;
	
	for (size_t i = start; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')') {
			s.pop();
			if (s.empty()) return i;
		}
	}

	return 0U;
}

int get_operator_priority(char ch) {
	if (ch == '+' || ch == '-') return 0;
	if (ch == '*' || ch == '/') return 1;
}

void infix_to_prefix(const string& infix, const size_t start, const size_t end) {
	stack<char> operato;

	for (size_t i = start; i < end; i++) {
		char ch = infix[i];

		if (ch >= 'A' && ch <= 'Z') { //피연산자
			cout << ch;
		}
		else if (ch == '(') { //식
			size_t bracket_end = get_bracket_end(infix, i);

			infix_to_prefix(infix, i + 1U, bracket_end);
			i = bracket_end;
		}
		else { //연산자
			while (!operato.empty()) {
				if (get_operator_priority(operato.top()) >= get_operator_priority(ch)) {
					cout << operato.top();
					operato.pop();
				}
				else {
					break;
				}
			}

			operato.push(ch);
		}
	}

	while (!operato.empty()) {
		cout << operato.top();
		operato.pop();
	}
}

int main() {
	string infix;

	cin >> infix;
	infix_to_prefix(infix, 0U, infix.size());

	cout << endl;
	return 0;
}