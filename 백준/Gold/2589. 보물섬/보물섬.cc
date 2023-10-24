#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>
#include <list>

using namespace std;

int N, M;
int island_map[50][50] = {};
int visited[50][50] = {};

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };


int BFS(int y, int x)
{
	queue<pair<int, int>> que;
	que.push(make_pair(y, x));
	visited[y][x] = 1;

	int dist = numeric_limits<int>::min();
	while (!que.empty())
	{
		auto current = que.front();
		que.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = current.first + dy[dir];
			int nx = current.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (island_map[ny][nx] == 1 || visited[ny][nx] > 0)
				continue;

			visited[ny][nx] = visited[current.first][current.second] + 1;
			dist = max(dist, visited[ny][nx]);
			que.push(make_pair(ny, nx));
		}
	}

	return dist;
}

int main()
{
	cin >> N >> M;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			char t;
			cin >> t;
			if (t == 'W') island_map[n][m] = 1;
		}
	}

	int max_dist = numeric_limits<int>::min();
	for (int start_y = 0; start_y < N; start_y++)
	{
		for (int start_x = 0; start_x < M; start_x++)
		{
			if (island_map[start_y][start_x] == 1)
				continue;

			max_dist = max(max_dist, BFS(start_y, start_x));

			for (int v_i = 0; v_i < N; v_i++)
				fill(visited[v_i], visited[v_i] + M, 0);
		}
	}

	cout << max_dist - 1;
	return 0;
}