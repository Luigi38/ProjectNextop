#include <iostream>
#include <vector>
#include <string>
using namespace std;

void add_indent(const int indent) {
	for (int i = 0; i < indent; i++) cout << "____";
}

void talk(const vector<string>& v, const int start, const int end, const int indent) {
	for (int i = start; i <= end; i++) {
		add_indent(indent);
		cout << v[i] << '\n';
	}
}

void ask(const vector<string>& v, const int N, const int indent) {
	if (indent == 0) cout << v[0] << '\n';

	talk(v, 1, 1, indent);

	if (N != indent) {
		talk(v, 2, 4, indent);
		ask(v, N, indent + 1);
		talk(v, 6, 6, indent);
	}
	else {
		talk(v, 5, 6, indent);
	}
}

int main() {
	int N;
	vector<string> v;
	
	v.push_back("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");

	v.push_back("\"재귀함수가 뭔가요?\"");
	v.push_back("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
	v.push_back("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
	v.push_back("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");

	v.push_back("\"재귀함수는 자기 자신을 호출하는 함수라네\"");

	v.push_back("라고 답변하였지.");

	cin >> N;
	ask(v, N, 0);

	return 0;
}