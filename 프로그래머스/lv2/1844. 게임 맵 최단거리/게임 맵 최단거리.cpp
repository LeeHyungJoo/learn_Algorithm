#include<vector>
#include<limits>
#include <queue>
using namespace std;

bool visited[101][101] = {};
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };

struct Node
{
	int y, x;
	int count;
};

int solution(vector<vector<int>> maps)
{
	int N = maps.size(), M = maps[0].size();
    
	queue<Node> coord;
	coord.push({ 0, 0 ,1});
    visited[0][0] = true;

	while (!coord.empty())
	{
		auto c = coord.front();
		coord.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = c.y + dy[dir];
			int nx = c.x + dx[dir];

			if (ny < 0 || nx < 0 || N - 1 < ny || M - 1 < nx || maps[ny][nx] == 0 || visited[ny][nx])
				continue;

			if (ny == N - 1 && nx == M - 1)
				return c.count + 1;
            
            visited[ny][nx] = true;
			coord.push({ ny,nx, c.count +1 });
		}
	}

	return -1;
}