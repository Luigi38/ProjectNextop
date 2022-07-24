#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef pair<int, int> id;

int mod2(const int a) {
	if (a == 0) return 0;
	return abs(a) % 2;
}

void swap(vector<id>& v, const int i, const int j, map<id, set<id>>& m) {
	id tmp = v[j];
	
	v[j] = v[i];
	v[i] = tmp;

	auto idi = m.find(v[i]);
	auto idj = m.find(v[j]);

	if (idi == m.end()) idi = m.insert({ v[i], set<id>() }).first;
	if (idj == m.end()) idj = m.insert({ v[j], set<id>() }).first;

	idi->second.insert(v[j]);
	idj->second.insert(v[i]);
}

void lets_avoid(vector<id>& v, map<id, set<id>>& m, const int indent, int& mini) {
	int count = 0;
	id prev = v[0];
	
	for (int i = 1; i < v.size(); i++) {
		if (mod2(prev.first) != mod2(v[i].first)) {
			auto ids = m.find(prev);
			count++;
			
			if (ids != m.end() && ids->second.find(v[i]) != ids->second.end()) {
				prev = v[i];
				continue;
			}

			swap(v, i - 1, i, m);
			lets_avoid(v, m, indent + 1, mini);

			swap(v, i - 1, i, m);
			m[prev].erase(v[i]);
			m[v[i]].erase(prev);

			prev = v[i];
		}
	}

	if (count == 1) mini = min(mini, indent);
}

int main() {
	int N;
	vector<id> v;
	map<int, int> overlapped;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int count_odd = 0;
	int count_even = 0;

	for (int i = 0; i < N; i++) {
		int an;
		cin >> an;

		auto overlap = overlapped.find(an);

		if (overlap == overlapped.end()) overlap = overlapped.insert({ an, 0 }).first;
		v.push_back({ an, ++(*overlap).second });

		if (mod2(an) == 0) count_even++;
		else count_odd++;
	}

	if (N == 1 || count_odd == 0 || count_even == 0) {
		cout << "0\n";
		return 0;
	}

	map<id, set<id>> m; //to avoid
	int mini = 1000;

	lets_avoid(v, m, 0, mini);

	cout << mini << '\n';
	return 0;
}