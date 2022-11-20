#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string S;
	vector<int> v(26, -1);

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		char ch = S[i];

		if (v[ch - 'a'] == -1) {
			v[ch - 'a'] = i;
		}
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << (i != v.size() - 1 ? ' ' : '\n');
	return 0;
}