#include <string>
#include <vector>

using namespace std;

struct privacy {
    string lang;
    string job;
    string career;
    string food;
    int score;
};

bool operator ==(const privacy& a, const privacy& b) {
    bool equals = true;

    if (b.lang != "-") equals = a.lang == b.lang;
    if (b.job != "-" && equals) equals = a.job == b.job;
    if (b.career != "-" && equals) equals = a.career == b.career;
    if (b.food != "-" && equals) equals = a.food == b.food;
    if (b.score != -1 && equals) equals = a.score >= b.score;

    return equals;
}

void get_privacies(const vector<string>& info, vector<privacy>& v) {
    for (string str : info) {
        privacy pr = { "-", "-", "-", "-", -1 };

        int in = 0;
        string info = "";
        bool whitespace = false;

        for (char ch : str) {
            if (ch == ' ') {
                switch (in) {
                case 0:
                    pr.lang = info;

                    info = "";
                    in++;
                    break;

                case 1:
                    pr.job = info;

                    info = "";
                    in++;
                    break;

                case 2:
                    pr.career = info;

                    info = "";
                    in++;
                    break;

                case 3:
                    pr.food = info;

                    info = "";
                    in++;
                    break;
                }
                continue;
            }

            info += ch;
        }

        pr.score = stoi(info);
        v.push_back(pr);
    }
}

privacy get_privacy_from_string(string query) {
    privacy pr = { "-", "-", "-", "-", -1 };

    int in = 0;
    string info = "";
    bool whitespace = false;

    for (char ch : query) {
        if (ch == ' ') whitespace = !whitespace;
        if (in == 3 && ch == ' ') whitespace = false;
        if (whitespace) continue;

        if (ch == ' ' && !whitespace) {
            switch (in) {
            case 0:
                pr.lang = info;

                info = "";
                in++;
                break;
            case 1:
                pr.job = info;

                info = "";
                in++;
                break;
            case 2:
                pr.career = info;

                info = "";
                in++;
                break;
            case 3:
                pr.food = info;

                info = "";
                in++;
                break;
            }
            continue;
        }

        info += ch;
    }

    pr.score = stoi(info);
    return pr;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    vector<privacy> v;
    get_privacies(info, v);

    for (auto str : query) {
        privacy q = get_privacy_from_string(str);
        int count = 0;

        for (privacy pr : v) {
            if (pr == q) count++;
        }
        answer.push_back(count);
    }

    return answer;
}