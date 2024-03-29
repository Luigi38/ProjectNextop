#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct privacy {
    vector<vector<string>> v; //lang, job, career, food
    vector<int> vscore;
};

bool operator ==(const vector<string>& a, const vector<string>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) if (a[i] != b[i] && b[i] != "-") return false;
    return true;
}

void get_privacies(const vector<string>& info, privacy &v) {
    int i = 0;

    for (string str : info) {
        string a = "";

        for (char ch : str) {
            if (ch == ' ') {
                v.v[i].push_back(a);

                a = "";
                continue;
            }
            a += ch;
        }

        int score = stoi(a);
        v.vscore.push_back(score);

        i++;
    }
}

void get_privacy_from_query(const vector<string> query, privacy &pr) {
    int i = 0;

    for (string str : query) {
        string a = "";

        for (char ch : str) {
            if (ch == ' ') {
                if (a != "and") pr.v[i].push_back(a);

                a = "";
                continue;
            }

            a += ch;
        }

        int score = stoi(a);
        pr.vscore.push_back(score);

        i++;
    }
}

void make_case(const vector<string>& lang, const vector<string>& job, const vector<string>& career, const vector<string>& food, vector<vector<string>>& info) {
    for (string one : lang)
        for (string two : job)
            for (string three : career)
                for (string four : food)
                    info.push_back({ one, two, three, four });
}

void init_map(map<vector<string>, vector<int>>& m, const vector<vector<string>>& cases, const privacy& v) {
    for (vector<string> c : cases) {
        vector<int> vscore;
        
        for (int i = 0; i < v.v.size(); i++) if (v.v[i] == c) vscore.push_back(v.vscore[i]);
        sort(vscore.begin(), vscore.end());
        m[c] = vscore;
    }
}

int search(map<vector<string>, vector<int>>& m, const vector<string>& query, const int score) {
    int count = 0;

    vector<int> vscore = m[query];
    count += vscore.end() - lower_bound(vscore.begin(), vscore.end(), score);

    return count;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    privacy v = { vector<vector<string>>(info.size(), vector<string>()), vector<int>() };
    privacy pr = { vector<vector<string>>(query.size(), vector<string>()), vector<int>() };

    get_privacies(info, v);
    get_privacy_from_query(query, pr);

    vector<vector<string>> cases;
    make_case({"cpp", "java", "python", "-"}, {"frontend", "backend", "-"}, {"junior", "senior", "-"}, {"chicken", "pizza", "-"}, cases);

    map<vector<string>, vector<int>> m;
    init_map(m, cases, v);

    for (int i = 0; i < query.size(); i++) {
        int count = search(m, pr.v[i], pr.vscore[i]);
        answer.push_back(count);
    }

    return answer;
}