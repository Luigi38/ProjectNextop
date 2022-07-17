#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void get_count_without_overlapped(const vector<int>& v, const string& prefix, const int i, int& count) {
	for (int j = i + 1; j < v.size(); j++) {
		if (v[i] + prefix.size() <= v[j]) {
			get_count_without_overlapped(v, prefix, j, count);

			count++;
			break;
		}
	}
}

int main() {
	string str;
	string prefix;

	map<string, vector<int>> s;

	getline(cin, str);
	getline(cin, prefix);

	//일단 모든 prefix를 찾아보자는 마인드
	for (int i = 0; i < str.size(); i++) {
		string a = "";

		if ((i + prefix.size()) > str.size()) {
			break;
		}

		for (int j = 0; j < prefix.size(); j++) {
			a += str[i + j];
		}
		
		if (s.find(a) == s.end()) {
			s[a] = vector<int>();
		}
		s[a].push_back(i);

		/*for (int j = i; j < str.size(); j++) {
			a += str[j];

			if (s.find(a) == s.end()) {
				s[a] = vector<int>();
			}
			s[a].push_back(i);
		}*/
	}

	int count = 0;
	vector<int> v = s[prefix];

	for (int i = 0; i < v.size(); i++) {
		int h = 1;

		get_count_without_overlapped(v, prefix, i, h);

		count = max(count, h);
	}

	cout << count << '\n';
	return 0;
}