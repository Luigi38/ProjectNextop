#define MAX 100000

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_h_index(const int N, const vector<int>& citations) {
	int h_index = 0;

	for (int i = 1; i <= MAX; i++) {
		auto it = lower_bound(citations.begin(), citations.end(), i);
		int count = citations.end() - it;

		if (count >= i) h_index = i;
	}

	return h_index;
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

	int h = get_h_index(N, citations);

	if (L > 0) {
		auto cut_line = lower_bound(citations.begin(), citations.end(), h + 1);
		cut_line--;

		for (auto it = cut_line;;it--) {
			(*it)++;

			if (--L == 0) break;
			if (it == citations.begin()) break;
		}
		int h2 = get_h_index(N, citations);

		h = max(h, h2);
	}

	std::cout << h << '\n';
	return 0;
}