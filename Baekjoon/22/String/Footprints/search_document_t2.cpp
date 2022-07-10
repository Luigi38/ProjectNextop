#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void get_count_without_overlapped(const vector<int>& v, const string& prefix, const int i, int& count) {
	for (int j = i; j < v.size(); j++) {
		if (j == 0) continue;
		if (v[i] + prefix.size() <= v[j]) {
			get_count_without_overlapped(v, prefix, j, count);
			count++;
		}
	}
}

int main() {
	string str;
	string prefix;

	map<string, vector<int>> s;

	getline(cin, str);
	getline(cin, prefix);

	for (int i = 0; i < str.size(); i++) {
		string a = "";

		for (int j = i; j < str.size(); j++) {
			a += str[j];

			if (s.find(a) == s.end()) {
				s[a] = vector<int>();
			}
			s[a].push_back(i);
		}
	}

	int count = 0;
	vector<int> v = s[prefix];

	get_count_without_overlapped(v, prefix, 0, count);

	cout << count << '\n';
	return 0;
}