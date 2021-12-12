#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct marathon {
	string name;
	int score;
};

bool compare(const marathon& a, const marathon& b) {
	return a.score > b.score;
}

int main() {
	int N;
	vector<marathon> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		marathon m;
		
		cin >> m.name >> m.score;
		v.push_back(m);
	}
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < 3; i++) cout << v[i].name << '\n';
	return 0;
}