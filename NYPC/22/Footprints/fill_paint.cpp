#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void fill_H(vector<vector<int>>& v, const int index, const int color) {
	for (int i = 0; i < v[index].size(); i++) {
		v[index][i] = color;
	}
}

void fill_V(vector<vector<int>>& v, const int index, const int color) {
	for (int i = 0; i < v.size(); i++) {
		v[i][index] = color;
	}
}

bool is_annoyed_H(vector<vector<int>>& v, const int index) {
	int color = 0;

	for (int i = 0; i < v[index].size(); i++) {
		if (color == 0 && color != v[index][i]) color = v[index][i];
		if (color != 0 && color != v[index][i]) return false;
	}

	return true;
}

bool is_annoyed_V(vector<vector<int>>& v, const int index) {

}

void pop_annoyed(vector<vector<int>>& v, stack<string>& s) {

}

int main() {
	int N, M;

	vector<vector<int>> v;
	stack<string> s;



	return 0;
}