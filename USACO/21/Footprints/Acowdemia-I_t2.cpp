#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct h_index {
	int index;
	int value;
};

h_index get_h_index(const int N, const vector<int>& citations) {
	h_index h = { -1, 0 };
	
	for (int i = 1; i <= N; i++) {
		auto it = lower_bound(citations.begin(), citations.end(), i);

		if (i > h.value && citations.end() - it >= i) {
			h.index = i;
			h.value = citations[i];
		}
		else {
			break;
		}
	}

	return h;
}

h_index get_max(const h_index& a, const h_index& b) {
	if (a.value >= b.value) return a;
	else return b;
}

int main() {
	int N, L;
	vector<int> citations;

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int c;

		cin >> c;
		citations.push_back(c);
	}
	sort(citations.begin(), citations.end());

	h_index h = get_h_index(N, citations);

	if (L > 0) {
		for (int i = 0; i <= h.index; i++) citations[i]++;
		h_index h2 = get_h_index(N, citations);

		h = get_max(h, h2);
	}

	cout << h.value << '\n';
	return 0;
}