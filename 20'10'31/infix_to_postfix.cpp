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
		case '+': case '-': case '*': case '/': //������
			//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!s.empty() && (prec(ch) <= prec(s.top()))) {
				postfix += s.top();
				s.pop();
			}
			s.push(ch);
			break;

		case '(': //���� ��ȣ
			s.push(ch);
			break;

		case ')': //������ ��ȣ
			top_op = s.top();
			s.pop();

			//���� ��ȣ�� ���� �� ���� ���
			while (top_op != '(') {
				postfix += top_op;
				top_op = s.top();
				s.pop();
			}

			break;

		default: //�ǿ�����
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
			int value = ch - '0'; //�Է��� �ǿ������̸�
			s.push(value);
		}
		else { //�������̸� �ǿ����ڸ� ���ÿ��� ����
			int op1, op2;
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();

			switch (ch) { //������ �����ϰ� ���ÿ� ����
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

	cout << "����ǥ�ü���: " << s << endl;
	cout << "����ǥ�ü���: " << infix_to_postfix(s) << endl;
	cout << "��: " << eval(s2_postfix) << endl;

	return 0;
}