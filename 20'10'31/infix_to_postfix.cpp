#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}

	return -1;
}

string infix_to_postfix(string exp) {
	stack<char> s;
	string postfix = "";
	char top_op;

	for (int i = 0; i < exp.size(); i++) {
		char ch = exp[i];

		switch (ch) {
		case '+': case '-': case '*': case '/': //연산자
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!s.empty() && (prec(ch) <= prec(s.top()))) {
				postfix += s.top();
				s.pop();
			}
			s.push(ch);
			break;

		case '(': //왼쪽 괄호
			s.push(ch);
			break;

		case ')': //오른쪽 괄호
			top_op = s.top();
			s.pop();

			//왼쪽 괄호를 만날 때 까지 출력
			while (top_op != '(') {
				postfix += top_op;
				top_op = s.top();
				s.pop();
			}

			break;

		default: //피연산자
			postfix += ch;
			break;

		}
	}

	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

int eval(string exp) {
	stack<char> s;

	for (int i = 0; i < exp.size(); i++) {
		char ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			int value = ch - '0'; //입력이 피연산자이면
			s.push(value);
		}
		else { //연산자이면 피연산자를 스택에서 제거
			int op1, op2;
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();

			switch (ch) { //연산을 수행하고 스택에 저장
			case '+': s.push(op1 + op2); break;
			case '-': s.push(op1 - op2); break;
			case '*': s.push(op1 * op2); break;
			case '/': s.push(op1 / op2); break;
			}
		}
	}

	int value = s.top();
	s.pop();

	return value;
}

int main() {
	string s = "(2+3)*4+9";
	string s2_postfix = "82/3-32*+";

	cout << "중위표시수식: " << s << endl;
	cout << "후위표시수식: " << infix_to_postfix(s) << endl;
	cout << "값: " << eval(s2_postfix) << endl;

	return 0;
}