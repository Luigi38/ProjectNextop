#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int recognize_type(const string& str) {
	char prev = str[0];
	bool selected_row = false;

	for (char ch : str) {
		if (prev == 'R' && ch >= '0' && ch <= '9') {
			selected_row = true;
		}
		else if (prev == 'C' && ch >= '0' && ch <= '9') {
			if (selected_row) return 2;
		}
		prev = ch;
	}

	return 1;
}

int convert_to_number(const string& alphabet) {
	int Q = 0;

	for (int i = 0; i < alphabet.size(); i++) {
		Q = 26 * Q + (alphabet[i] - 'A');
		if (i != 0) Q += 26;
	}

	return Q + 1;
}

char convert_moded(const int moded) {
	if (moded == 0) return 'Z';
	return moded - 1 + 'A';
}

string convert_to_alphabet(const string& number) {
	string alphabet = "";
	int num = stoi(number);

	vector<int> Z;

	for (int i = 0; i < 5; i++) {
		int Q = (num - 1) / 26;
		int R = (num - 1) % 26;

		Z.push_back(R);
		num = Q;

		if (Q == 0) break;
	}

	for (int i = 0; i < Z.size(); i++) {
		alphabet += 'A' + Z[Z.size() - 1 - i];
	}

	return alphabet;
}

void convert_to_one(const string& str, string& converted) {
	/*
	[column][row]
	column: Alphabet St.
	row: Number St.
	*/
	char prev = str[0];
	string row = "";
	string column = "";

	for (char ch : str) {
		if (ch != prev && prev == 'R' && ch != 'C') {
			row += ch;
		}
		else if (ch != prev && prev == 'C') {
			column += ch;
		}
		else {
			prev = ch;
		}
	}

	converted += convert_to_alphabet(column);
	converted += row;
}

void convert_to_two(const string& str, string& converted) {
	/*
	R[row]C[column]
	row & column: Number St.
	*/

	char prev = str[0];
	string row = "";
	string column = "";

	for (char ch : str) {
		if (ch >= 'A' && ch <= 'Z') column += ch;
		else row += ch;
	}

	converted += "R";
	converted += row;
	converted += "C";
	converted += to_string(convert_to_number(column));
}

int main() {
	string str;
	string converted;

	cin >> str;

	if (recognize_type(str) == 1) convert_to_two(str, converted);
	else convert_to_one(str, converted);

	cout << converted << '\n';
	return 0;
}