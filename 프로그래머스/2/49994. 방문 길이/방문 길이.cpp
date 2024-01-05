#include <string>
#include <unordered_map>
using namespace std;

int visited[4][11][11];
pair<int, int> direction[4] = { 
	make_pair(1,0),
	make_pair(0,1),
	make_pair(-1,0),
	make_pair(0,-1)
};
unordered_map<char, int> direction_map({
	{'U', 0},
	{'R', 1},
	{'D', 2},
	{'L', 3}
	});

int solution(string dirs) {
    int answer = 0;
	pair<int, int> pos(5, 5);

	for (auto dir : dirs)
	{
		int dir_type = direction_map[dir];
		int ny = pos.first + direction[dir_type].first;
		int nx = pos.second + direction[dir_type].second;

		if (ny < 0 || nx < 0 || ny > 10 || nx > 10)
			continue;

		if (visited[dir_type][ny][nx] == 0)
		{
			visited[dir_type][ny][nx] = 1;
			visited[(dir_type + 2) % 4][pos.first][pos.second] = 1;
			answer++;
		}
		pos = make_pair(ny, nx);
	}

    return answer;
}