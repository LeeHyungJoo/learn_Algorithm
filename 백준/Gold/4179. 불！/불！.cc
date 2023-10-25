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

int R, C;
char game_map[1000][1000] = {};
int visited[1000][1000] = {};
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

struct Point
{
	Point(int y, int x) : y(y), x(x) {}

	int x;
	int y;
};

int main()
{
	cin >> R >> C;

	queue<Point> fire_q;
	queue<Point> jh_q;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			char t;
			cin >> t;

			game_map[c][r] = t;

			if (t == 'J')
			{
				jh_q.push({ c, r });
				visited[c][r] = 1;
			}
			else if (t == 'F')
			{
				fire_q.push({ c, r });
			}
		}
	}

	int exit_depth = -1;
	while (!jh_q.empty())
	{
		int fire_q_count = fire_q.size();
		if (fire_q_count != 0)
		{
			for (int i = 0; i < fire_q_count; i++)
			{
				auto current_fire = fire_q.front();
				fire_q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = current_fire.y + dy[dir];
					int nx = current_fire.x + dx[dir];

					if (ny < 0 || nx < 0 || ny > C - 1 || nx > R - 1)
						continue;

					if (game_map[ny][nx] == '#' || game_map[ny][nx] == 'F')
						continue;

					fire_q.push({ ny, nx });
					game_map[ny][nx] = 'F';
				}
			}
		}

		int jh_q_count = jh_q.size();
		for (int i = 0; i < jh_q_count; i++)
		{
			auto current_jh = jh_q.front();
			jh_q.pop();

			if (current_jh.y == 0 || current_jh.x == 0 || current_jh.y == C - 1 || current_jh.x == R - 1)
			{
				exit_depth = visited[current_jh.y][current_jh.x];
				break;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = current_jh.y + dy[dir];
				int nx = current_jh.x + dx[dir];

				if (ny < 0 || nx < 0 || ny > C - 1 || nx > R - 1)
					continue;

				if (game_map[ny][nx] == '#' || game_map[ny][nx] == 'F' || visited[ny][nx] > 0)
					continue;

				visited[ny][nx] = visited[current_jh.y][current_jh.x] + 1;
				jh_q.push({ ny, nx });
			}
		}

		if (exit_depth > 0)
			break;
	}

	cout << (exit_depth == -1 ? "IMPOSSIBLE" : to_string(exit_depth));

	return 0;
}