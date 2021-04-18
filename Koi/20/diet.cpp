#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Nut {
	int p1;
	int f2;
	int s3;
	int v4; //Vitamin
	int c5; //Cost
};

struct NutOutput {
	int cost;
	vector<int> indicies;
};

struct NutCase {
	int k;
	vector<Nut> S;

	vector<bool> result;
	int count;

	vector<vector<int>> indicies;
};

struct NutCase2 {
	Nut nut;
	vector<int> indicies;
};

Nut operator +(Nut nut1, Nut nut2) {
	return { nut1.p1 + nut2.p1, nut1.f2 + nut2.f2, nut1.s3 + nut2.s3, nut1.v4 + nut2.v4, nut1.c5 + nut2.c5 };
}

void dfs(const int index, const bool select, NutCase& nc) {
	nc.result.push_back(select);

	if (select) {
		nc.count++;
	}

	if (index >= nc.S.size() - 1) {
		if (nc.count >= nc.k) {
			nc.indicies.push_back(vector<int>());

			for (int i = 0; i < nc.S.size(); i++) {
				if (nc.result[i]) {
					nc.indicies[nc.indicies.size() - 1].push_back(i + 1);
				}
			}
		}

		if (nc.result.back()) {
			nc.count--;
		}
		nc.result.pop_back();
		return;
	}

	dfs(index + 1, false, nc);
	dfs(index + 1, true, nc);

	if (nc.result.back()) {
		nc.count--;
	}
	nc.result.pop_back();
}

vector<NutCase2> higher_than_minimum(const vector<Nut>& nuts, const vector<vector<int>>& indicies, const Nut& minimum) {
	vector<NutCase2> v;
	vector<NutCase2> v2;

	for (int i = 0; i < indicies.size(); i++) {
		vector<int> inddex = indicies[i];

		Nut nut = { 0, 0, 0, 0, 0 };

		for (int j = 0; j < inddex.size(); j++) {
			Nut current = nuts[j];
			nut = nut + current;
		}

		v2.push_back({ nut, inddex });
	}

	for (int i = 0; i < v2.size(); i++) {
		NutCase2 nc2 = v2[i];

		if (nc2.nut.p1 >= minimum.p1 && nc2.nut.f2 >= minimum.f2 && nc2.nut.s3 >= minimum.s3 && nc2.nut.v4 >= minimum.v4) {
			v.push_back(nc2);
		}
	}

	return v;
}

bool compare_by_cost(const NutCase2& nut1, const NutCase2& nut2) {
	return nut1.nut.c5 < nut2.nut.c5;
}

NutOutput diet(const vector<Nut>& nuts, const int N, const Nut& minimum) { //this code is problem
	NutOutput output = { 0, vector<int>() };
	vector<NutCase2> v2;
	
	for (int i = 0; i < 15; i++) {
		NutCase nc = { i + 1, nuts, vector<bool>(), 0, vector<vector<int>>() };
		dfs(0, true, nc);

		vector<NutCase2> v = higher_than_minimum(nuts, nc.indicies, minimum);
		sort(v.begin(), v.end(), compare_by_cost);

		if (v.size() > 0) {
			v2.push_back(v[0]);
		}

		nc = { i + 1, nuts, vector<bool>(), 0, vector<vector<int>>() };
		dfs(0, false, nc);

		v = higher_than_minimum(nuts, nc.indicies, minimum);
		sort(v.begin(), v.end(), compare_by_cost);

		if (v.size() > 0) {
			v2.push_back(v[0]);
		}
	}

	if (v2.size() > 0) {
		sort(v2.begin(), v2.end(), compare_by_cost);
		output = { v2[0].nut.c5, v2[0].indicies };
	}

	return output;
}

int main() {
	Nut minimum;

	vector<Nut> nuts;
	int N;

	cin >> N;
	cin >> minimum.p1 >> minimum.f2 >> minimum.s3 >> minimum.v4;

	for (int i = 0; i < N; i++) {
		Nut nut = { 0, 0, 0, 0, 0 };
		
		cin >> nut.p1 >> nut.f2 >> nut.s3 >> nut.v4 >> nut.c5;
		nuts.push_back(nut);
	}

	NutOutput output = diet(nuts, N, minimum);

	cout << output.cost << '\n';
	for (auto i = 0; i < output.indicies.size(); i++) cout << output.indicies[i] << '\n';

	return 0;
}