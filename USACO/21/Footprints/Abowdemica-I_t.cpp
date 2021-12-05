#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct h_index {
	int index;
	int value;
};

h_index get_h_index(const int N, const vector<pair<int, int>>& citations) {
	vector<pair<int, int>> v = citations;
	h_index h = { -1, 0 };

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (v[i].first > h.value && N - i >= v[i].first) {
			h = { v[i].second, v[i].first };
		}
	}

	return h;
}

int main() {
	int N, L;
	vector<pair<int, int>> citations; //first: value, second: original index

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int c;

		cin >> c;
		citations.push_back({ c, i });
	}

	h_index h = get_h_index(N, citations);
	
	if (L > 0) {
		for (int i = 0; i < L; i++) {
			citations[h.index].first++;
			h_index h2 = get_h_index(N, citations);

			if (h2.value > h.value) h = h2;
		}
	}

	cout << h.value << '\n';
	return 0;
}