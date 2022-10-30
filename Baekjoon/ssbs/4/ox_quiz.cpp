#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	vector<string> v;
	vector<int> v2;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;

		cin >> str;
		v.push_back(str);
	}

	for (int t = 0; t < T; t++) {
		vector<int> score;
		string ox = v[t];
		int total = 0;

		if (ox[0] == 'O') score.push_back(1);
		else score.push_back(0);

		for (int i = 1; i < ox.size(); i++) {
			char ch = ox[i];
			score.push_back(ch == 'O' ? score[i - 1] + 1 : 0);
		}
		for (int i = 0; i < score.size(); i++) total += score[i];
		v2.push_back(total);
	}

	for (int i = 0; i < T; i++) cout << v2[i] << '\n';
	return 0;
}