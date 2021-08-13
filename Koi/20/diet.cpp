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
	vector<Nut> S;

	vector<bool> result;
	vector<vector<int>> indicies;
};

struct NutCase2 {
	Nut nut;
	vector<int> indicies;
};

Nut operator +(Nut nut1, Nut nut2) {
	return { nut1.p1 + nut2.p1, nut1.f2 + nut2.f2, nut1.s3 + nut2.s3, nut1.v4 + nut2.v4, nut1.c5 + nut2.c5 };
}

void dfs(const int index, const bool select, NutCase& nc) { //this function is normal
	nc.result.push_back(select);

	if (index >= nc.S.size() - 1) {
		nc.indicies.push_back(vector<int>());

		for (int i = 0; i < nc.S.size(); i++) {
			if (nc.result[i]) {
				nc.indicies[nc.indicies.size() - 1].push_back(i + 1);
			}
		}

		nc.result.pop_back();
		return;
	}

	dfs(index + 1, false, nc);
	dfs(index + 1, true, nc);

	nc.result.pop_back();
}

void higher_than_minimum(const vector<Nut>& nuts, const vector<vector<int>>& indicies, const Nut& minimum, vector<NutCase2>& v) { //this function is normal
	vector<NutCase2> v2;

	for (int i = 0; i < indicies.size(); i++) {
		vector<int> inddex = indicies[i];

		Nut nut = { 0, 0, 0, 0, 0 };

		for (int j = 0; j < inddex.size(); j++) {
			int index = inddex[j] - 1;

			Nut current = nuts[index];
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
}

bool compare_by_cost(const NutCase2& nut1, const NutCase2& nut2) { //this function is normal
	if (nut1.nut.c5 == nut2.nut.c5) {
		return nut1.indicies < nut2.indicies;
	}
	return nut1.nut.c5 < nut2.nut.c5;
}

NutOutput diet(const vector<Nut>& nuts, const int N, const Nut& minimum) { //this function is only problem
	NutOutput output = { 0, vector<int>() };

	vector<NutCase2> v;

	NutCase nc = { nuts, vector<bool>(), vector<vector<int>>() };
	dfs(0, true, nc);
		
	higher_than_minimum(nuts, nc.indicies, minimum, v);

	nc = { nuts, vector<bool>(), vector<vector<int>>() };
	dfs(0, false, nc);

	higher_than_minimum(nuts, nc.indicies, minimum, v);

	if (v.size() > 0) {
		sort(v.begin(), v.end(), compare_by_cost);
		output = { v[0].nut.c5, v[0].indicies };
	}
	
	return output;
}

int main() { //this function is normal
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

	if (output.indicies.size() > 0) {
		cout << output.cost << '\n';

		for (auto i = 0; i < output.indicies.size(); i++) {
			cout << output.indicies[i];

			if (i != output.indicies.size() - 1) {
				cout << ' ';
			}
			else {
				cout << '\n';
			}
		}
	}
	else {
		cout << "-1\n";
	}

	return 0;
}
