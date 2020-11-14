#define MAZE_WIDTH 6
#define MAZE_HEIGHT 6
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct point {
	int x;
	int y;
};

enum class rect {
	Allow,
	Block,
	Entry,
	Exit,
	Here
};

vector<vector<rect>> maze;

void push_loc(stack<point>* s, int x, int y) {
	if (x < 0 || y < 0 || x > MAZE_WIDTH - 1 || y > MAZE_HEIGHT - 1) return;
	if (maze[y][x] != rect::Block && maze[y][x] != rect::Here) s->push({ x, y });
}

void print_maze(vector<vector<rect>>* v) {
	cout << '\n';
	for (int y = 0; y < v->size(); y++) {
		vector<rect> m = (*v)[y];

		for (int x = 0; x < m.size(); x++) cout << static_cast<int>(m[x]);
		cout << '\n';
	}
}

void search_maze(vector<vector<rect>>* maze, point entry) {
	stack<point> s;
	point here = entry;
	int x, y;

	while ((*maze)[here.y][here.x] != rect::Exit) {
		x = here.x;
		y = here.y;

		(*maze)[y][x] = rect::Here;
		//print_maze(maze);

		push_loc(&s, x - 1, y);
		push_loc(&s, x + 1, y);
		push_loc(&s, x, y - 1);
		push_loc(&s, x, y + 1);

		if (s.empty()) {
			cout << ":<" << endl;
			return;
		}
		else {
			here = s.top();
			s.pop();
		}
	}
}

int maze_array[MAZE_HEIGHT][MAZE_WIDTH] = {
	{ 1, 1, 1, 1, 1, 1 },
	{ 2, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 3 },
	{ 1, 1, 1, 1, 1, 1 }
};

int main() {
	rect maze_array_rect[MAZE_HEIGHT][MAZE_WIDTH];
	
	for (int y = 0; y < MAZE_HEIGHT; y++) {
		for (int x = 0; x < MAZE_WIDTH; x++) {
			maze_array_rect[y][x] = static_cast<rect>(maze_array[y][x]);
		}
		vector<rect> m(maze_array_rect[y], maze_array_rect[y] + MAZE_WIDTH);
		maze.push_back(m);
	}
	
	search_maze(&maze, { 1, 0 });

	cout << ":>" << endl;
	return 0;
}