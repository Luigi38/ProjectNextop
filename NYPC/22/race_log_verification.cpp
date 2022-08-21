#include <iostream>
#include <vector>
using namespace std;

struct race {
	int time;
	int user;
	int s;
};

bool is_unfair(const race& r, const vector<int>& verification) {
	if (r.s == 0 && verification[r.user - 1] != -1) return true;
	if (r.s == 1 && verification[r.user - 1] == -1) return true;
	if (r.s == 1 && r.time - verification[r.user - 1] < 60) return true;
	return false;
}

bool is_last_unfair(const vector<int>& verification) {
	for (int i = 0; i < verification.size(); i++) if (verification[i] != -1) return true;
	return false;
}

int main() {
	int N, M;
	vector<race> v;

	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		race r;
		
		cin >> r.time >> r.user >> r.s;
		v.push_back(r);
	}

	bool unfair = false;
	vector<int> verification(N, -1);

	for (int i = 0; i < M; i++) {
		if (is_unfair(v[i], verification)) {
			unfair = true;
			break;
		}

		if (v[i].s == 0) verification[v[i].user - 1] = v[i].time;
		else if (v[i].s == 1) verification[v[i].user - 1] = -1;
	}
	if (!unfair) unfair = is_last_unfair(verification);

	cout << (unfair ? "NO\n" : "YES\n");
	return 0;
}