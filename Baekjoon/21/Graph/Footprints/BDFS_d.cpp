#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int search_miro(int x, int y, int N, int M, map<pair<int, int>, int>& miro, int count) {
	int cc = count;

	while (1) {
		if (x + 1 == N && y + 1 == M) {
			return cc;
		}

		pair<int, int> points[4] = { make_pair(x, y + 1), make_pair(x, y - 1), make_pair(x + 1, y), make_pair(x - 1, y) };
		
		vector<int> indicies;

		for (int i = 0; i < 4; i++) {
			pair<int, int> p = points[i];

			if (p.first >= 0 && p.first < N && p.second >= 0 && p.second < M && miro[p] == 1) indicies.push_back(i);
		}

		if (indicies.size() == 0) {
			break;
		}
		else if (indicies.size() == 1) {
			int i = indicies[0];
			
			x = points[i].first;
			y = points[i].second;
			cc++;
		}
		else {
			for (int i = 0; i < indicies.size(); i++) {
				int index = indicies[i];
				auto p = points[index];

				cc += search_miro(p.first, p.second, N, M, miro, cc);
			}
		}
	}

	return 0;
}

int main() {
	int N, M;
	map<pair<int, int>, int> miro;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		string str;
		cin >> str;

		for (int x = 0; x < M; x++) {
			char ch = str[x];
			int can_move = ch == '1' ? 1 : 0;

			miro[make_pair(x, y)] = can_move;
		}
	}

	cout << search_miro(0, 0, N, M, miro, 0) + 1 << endl;
	return 0;
}
