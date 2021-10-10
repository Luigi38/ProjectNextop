#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct temp {
    vector<bool> result;
    int size;
    int size_start;
    int size_end;
};

bool exists(const int value, const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) if (v[i] == value) return true;
    return false;
}

void dfs(const bool select, const int index, const int N, const string& order, temp& tmp, map<string, int>& m) {
    tmp.result.push_back(select);
    if (select) tmp.size++;
    
    if (index + 1 >= N) {
        if (tmp.size >= tmp.size_start && tmp.size <= tmp.size_end) {
            string prefix = "";

            for (int i = 0; i < tmp.result.size(); i++) if (tmp.result[i]) prefix += order[i];
            m[prefix]++;
        }

        tmp.result.pop_back();
        if (select) tmp.size--;

        return;
    }

    dfs(false, index + 1, N, order, tmp, m);
    dfs(true, index + 1, N, order, tmp, m);

    tmp.result.pop_back();
    if (select) tmp.size--;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());

        temp tmp = { vector<bool>(), 0, course[0], course[course.size() - 1] };
        dfs(false, 0, orders[i].length(), orders[i], tmp, m);
        tmp = { vector<bool>(), 0, course[0], course[course.size() - 1] };
        dfs(true, 0, orders[i].length(), orders[i], tmp, m);
    }

    map<string, int>::iterator iter;
    vector<pair<int, string>> tmp_answer;

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second >= 2 && exists((iter->first).length(), course)) tmp_answer.push_back({iter->second, iter->first});
    }

    sort(tmp_answer.begin(), tmp_answer.end(), greater<pair<int, string>>());

    map<int, int> maximize;

    for (int i = 0; i < tmp_answer.size(); i++) {
        maximize[tmp_answer[i].second.length()] = max(tmp_answer[i].first, maximize[tmp_answer[i].second.length()]);
    }
    for (int i = 0; i < tmp_answer.size(); i++) {
        if (maximize[tmp_answer[i].second.length()] == tmp_answer[i].first) {
            answer.push_back(tmp_answer[i].second);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}