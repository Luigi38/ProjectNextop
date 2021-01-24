#include <iostream>
#include <stack>
#include <string>
using namespace std;

void infix_to_prefix(const string& infix, const size_t start, const size_t end) {
	stack<char> operato;
	int bracket_start;

	for (size_t i = start; i < end; i++) {
		char ch = infix[i];

		if (ch >= 'A' && ch <= 'Z') { //�ǿ�����
			cout << ch;
		}
		else if (ch == '(') { //��ȣ
			size_t bracket_end = 0U;

			for (size_t j = end - 1U; j >= i + 1U; j--) {
				if (infix[j] == ')') {
					bracket_end = j;
					break;
				}
			}

			infix_to_prefix(infix, i + 1U, bracket_end);
			i += bracket_end - i;
		}
		else { //������
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