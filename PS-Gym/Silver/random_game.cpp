#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool compare_by_score(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
	if (a.second.first != b.second.first) return a.second.first > b.second.first; //score (descending)
	return a.second.second < b.second.second; //time (ascending)
}

int main() {
	int N = 0; //round
	map<string, pair<int, int>> dict; //(score, time)

	cin >> N;

	for (int i = 0; i < N; i++) {
		string name;
		char color;
		int number;

		cin >> name >> color >> number;

		auto it = dict.find(name);
		int score = (color == 'B' ? number : -number);

		if (it == dict.end()) { //is not key
			dict[name] = {score, i};
		}
		else {
			it->second.first += score;
			it->second.second = i;
		}
	}

	vector<pair<string, pair<int, int>>> v(dict.begin(), dict.end());
	sort(v.begin(), v.end(), compare_by_score);

	cout << v[0].first << '\n';
	return 0;
}