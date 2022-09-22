#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct option {
	vector<bool> result;
	int result_true_size;
	int vowels;
	vector<string> v;
};

bool is_vowels(const char ch) {
	string s = "aeiou";

	for (char c : s) if (ch == c) return true;
	return false;
}

void dfs(const bool select, const int index, const int L, const vector<char>& pass, option& op) {
	if (select) {
		op.result_true_size++;
		if (is_vowels(pass[index])) op.vowels++;
	}
	op.result.push_back(select);

	if (index == pass.size() - 1) {
		if (op.result_true_size == L && op.vowels >= 1 && (op.result_true_size - op.vowels) >= 2) {
			string str = "";

			for (int i = 0; i < op.result.size(); i++) if (op.result[i]) str.push_back(pass[i]);
			op.v.push_back(str);
		}
	}
	else {
		dfs(false, index + 1, L, pass, op);
		dfs(true, index + 1, L, pass, op);
	}

	if (select) {
		op.result_true_size--;
		if (is_vowels(pass[index])) op.vowels--;
	}
	op.result.pop_back();
}

int main() {
	int L, C;
	vector<char> pass;

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char ch;

		cin >> ch;
		pass.push_back(ch);
	}
	sort(pass.begin(), pass.end());

	option op = { vector<bool>(), 0, 0, vector<string>() };
	dfs(false, 0, L, pass, op);

	op = { vector<bool>(), 0, 0, op.v };
	dfs(true, 0, L, pass, op);

	sort(op.v.begin(), op.v.end());
	for (string& str : op.v) cout << str << '\n';

	return 0;
}