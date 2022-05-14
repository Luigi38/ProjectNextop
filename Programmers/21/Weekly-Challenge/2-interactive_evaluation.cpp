#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char get_credit(int average) {
    if (average >= 90) return 'A';
    if (average >= 80 && average < 90) return 'B';
    if (average >= 70 && average < 80) return 'C';
    if (average >= 50 && average < 70) return 'D';
    if (average < 50) return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for (int i = 0; i < scores.size(); i++) {
        pair<int, int> mi = { 0, scores[0][i] };
        pair<int, int> ma = { 0, scores[0][i] };
        int average = scores[0][i];
        int count = scores.size();
        
        for (int j = 1; j < scores.size(); j++) {
            if (scores[j][i] == mi.second) mi.first = -1;
            if (scores[j][i] < mi.second) mi = { j, scores[j][i] };
            if (scores[j][i] == ma.second) ma.first = -1;
            if (scores[j][i] > ma.second) ma = { j, scores[j][i] };
            average += scores[j][i];
        }
        
        if (mi.first == i) {
            average -= mi.second;
            count--;
        }
        if (ma.first == i) {
            average -= ma.second;
            count--;
        }
        average /= count;
        answer.push_back(get_credit(average));
    }
    
    return answer;
}