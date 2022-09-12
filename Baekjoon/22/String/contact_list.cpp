#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> v;
	int t;

	cin >> t;

	for (int T = 0; T < t; T++) {
		vector<string> contact; //n
		set<string> prefixes;
		int n;

		cin >> n;

		for (int N = 0; N < n; N++) {
			string call;

			cin >> call;
			contact.push_back(call);
		}

		for (int i = 0; i < contact.size(); i++) {
			string prefix = "";

			for (int j = 0; j < contact[i].size() - 1; j++) {
				prefix += contact[i][j];
				prefixes.insert(prefix);
			}
		}

		string result = "YES";

		for (int i = 0; i < contact.size(); i++) { // n * log n
			if (prefixes.find(contact[i]) != prefixes.end()) {
				result = "NO";
				break;
			}
		}
		v.push_back(result);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}