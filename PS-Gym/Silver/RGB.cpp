#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

string rgb_to_string(const rgb& a) {
	string s;

	s += to_string(a.r);
	s += ";";
	s += to_string(a.g);
	s += ";";
	s += to_string(a.b);

	return s;
}

int main() {
	int N, M;
	cin >> N >> M;

	set<string> s;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rgb color;
			string str;

			cin >> color.r >> color.g >> color.b;
			str = rgb_to_string(color);

			s.insert(str);
		}
	}

	cout << s.size() << '\n';
	return 0;
}