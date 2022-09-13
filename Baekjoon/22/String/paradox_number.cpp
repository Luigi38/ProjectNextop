#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct option {
	vector<int> result;
	set<int> except;
	vector<string> v;
};

void dfs(const int select, const int index, const string& X, option& op) {
	op.result.push_back(select);

	if (index == X.size() - 1) {
		string s = "";

		for (int i = 0; i < op.result.size(); i++) s.push_back(X[op.result[i]]);
		op.v.push_back(s);
	}
	else {
		for (int i = 0; i < X.size(); i++) {
			if (op.except.find(i) != op.except.end()) continue;

			op.except.insert(i);
			dfs(i, index + 1, X, op);
			op.except.erase(i);
		}
	}

	op.result.pop_back();
}

int main() {
	string X; //same as int
	int composition = 1000000;
	option op = { vector<int>(), set<int>(), vector<string>() };

	cin >> X;
	
	for (int i = 0; i < X.size(); i++) {
		op.except.insert(i);
		dfs(i, 0, X, op);
		op.except.erase(i);
		op.result.clear();
	}

	int Xi = stoi(X);

	for (int i = 0; i < op.v.size(); i++) {
		int composed = stoi(op.v[i]);
		if (composed > Xi) composition = min(composition, composed);
	}

	if (composition == 1000000) composition = 0;
	cout << composition << '\n';

	return 0;
}