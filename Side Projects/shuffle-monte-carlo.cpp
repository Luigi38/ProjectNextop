#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 1);

bool compare(const int a, const int b) {
    return dis(gen) == 1;
}

void print_array(const vector<int>& v) {
    for (int val : v) cout << val << ' ';
    cout << '\n';
}

int main() {
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<vector<int>> distribution(11, vector<int>(11, 0));

    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        random_shuffle(v.begin(), v.end());
        
        for (int j = 0; j < 11; j++) {
            distribution[j][v[j]]++;
        }
    }

    for (int i = 0; i < 11; i++) {
        float avg = 0;
        float dispersion = 0;

        for (int j = 0; j < 11; j++) {
            avg += distribution[i][j];
        }
        avg /= 11.0;
        
        for (int j = 0; j < 11; j++) {
            dispersion = pow(distribution[i][j] - avg, 2);
        }
        dispersion /= 11.0;

        cout << sqrt(dispersion) << '\n';
    }
    return 0;
}