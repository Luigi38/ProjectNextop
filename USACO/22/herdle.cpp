#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct point {
	int x;
	int y;
};

struct state {
	point p;
	bool is_allocated;
};

bool is_point_empty(const point& p) {
	return p.x == -1 && p.y == -1;
}

bool is_point_equals(const point& p1, const point& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

point find_and_allocate(map<char, vector<state>>& maap, const char key, const point& p) {
	for (state& s : maap[key]) if (is_point_equals(s.p, p)) return { -1, -1 }; //guess point == correct point => is_green
	for (state& s : maap[key]) {
		if (!s.is_allocated) {
			s.is_allocated = true;
			return s.p;
		}
	}

	return { -1, -1 };
}

int main() {
	vector<string> grid_correct;
	vector<string> grid_guess;

	int count_green = 0;
	int count_yellow = 0;

	map<char, vector<state>> maap; //guess

	for (int i = 0; i < 3; i++) {
		string str;

		cin >> str;
		grid_correct.push_back(str);
	}
	for (int i = 0; i < 3; i++) {
		string str;

		cin >> str;
		grid_guess.push_back(str);
	}

	for (int y = 0; y < 3; y++) { //fills with green
		for (int x = 0; x < 3; x++) {
			char guessed = grid_guess[y][x];
			bool is_allo = grid_correct[y][x] == guessed; //correct alphabet == guess alphabet [same point]

			maap[guessed].push_back({ {x, y}, is_allo });
			if (is_allo) count_green++;
		}
	}

	for (int y = 0; y < 3; y++) { //fills with yellow
		for (int x = 0; x < 3; x++) {
			point curp = { x, y };
			char corrected = grid_correct[y][x]; //alphabet

			point p = find_and_allocate(maap, corrected, curp);
			if (!is_point_empty(p)) count_yellow++;
		}
	}

	cout << count_green << '\n' << count_yellow << '\n';
	return 0;
}