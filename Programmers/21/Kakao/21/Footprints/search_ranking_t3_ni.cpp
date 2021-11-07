#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct privacy {
    vector<vector<string>> v; //lang, job, career, food
    vector<int> vscore;
};

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

void replace_hypen(const vector<string>& query, vector<vector<string>>& replaced) {
    vector<string> vlang;
    vector<string> vjob;
    vector<string> vcareer;
    vector<string> vfood;

    if (query[0] != "-") vlang = { query[0] };
    else vlang = { "cpp", "java", "python" };

    if (query[1] != "-") vjob = { query[1] };
    else vjob = { "frontend", "backend" };

    if (query[2] != "-") vcareer = { query[2] };
    else vcareer = { "junior", "senior" };

    if (query[3] != "-") vfood = { query[3] };
    else vfood = { "chicken", "pizza" };

    for (string one : vlang)
        for (string two : vjob)
            for (string three : vcareer)
                for (string four : vfood)
                    replaced.push_back({ one, two, three, four });
}

int search(map<vector<string>, vector<int>>& m, const vector<string>& query, const int score) {
    vector<vector<string>> replaced;
    replace_hypen(query, replaced);

    int count = 0;

    for (vector<string> q : replaced) {
        vector<int> vscore = m[q];
        count += vscore.end() - lower_bound(vscore.begin(), vscore.end(), score);
    }

    return count;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    privacy v = { vector<vector<string>>(info.size(), vector<string>()), vector<int>() };
    privacy pr = { vector<vector<string>>(query.size(), vector<string>()), vector<int>() };

    get_privacies(info, v);
    get_privacy_from_query(query, pr);

    vector<vector<string>> cases;
    make_case({ "cpp", "java", "python" }, { "frontend", "backend" }, { "junior", "senior" }, { "chicken", "pizza" }, cases);

    map<vector<string>, vector<int>> m;
    init_map(m, cases, v);

    for (int i = 0; i < query.size(); i++) {
        int count = search(m, pr.v[i], pr.vscore[i]);
        answer.push_back(count);
    }

    return answer;
}