#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<pair<int, string>> favorites;

    for (string subjects : table) {
        vector<string> v(6, "");
        int index = 0;
        
        for (char c : subjects) {
            if (c == ' ') index++;
            else v[index] += c;
        }
        
        favorites.push_back({ 0, v[0] });
        
        for (int i = 1; i < 6; i++) {
            for (int j = 0; j < languages.size(); j++) {
                if (v[i] == languages[j]) favorites[favorites.size() - 1].first += preference[j] * (6 - i);
            }
        }
    }
    
    sort(favorites.begin(), favorites.end(), greater<pair<int, string>>());
    
    int prev_val = favorites[0].first;
    
    vector<pair<int, string>> last_v;
    last_v.push_back({ prev_val, favorites[0].second });
    
    for (int i = 1; i < favorites.size(); i++) {
        if (prev_val == favorites[i].first) {
            last_v.push_back({ prev_val, favorites[i].second });
        }
        else {
            break;
        }
    }
    
    sort(last_v.begin(), last_v.end());
    return last_v[0].second;
}