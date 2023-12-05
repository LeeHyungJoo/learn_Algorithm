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
int walls[50][50];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

int visited[50][50];

int area_size[2500];
int merge_max_size = 0;

void DFS(int y, int x, int area)
{
	area_size[area]++;
	visited[y][x] = area;

	for (int dir = 0; dir < 4; dir++)
	{
		if (walls[y][x] & (1 << dir))
			continue;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny > M - 1 || nx > N - 1 || visited[ny][nx])
			continue;

		DFS(ny, nx, area);
	}
}

int main()
{
	cin >> N >> M;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> walls[y][x];
		}
	}

	int area = 0;
	int max_size = 0;
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x])
				continue;

			DFS(y, x, ++area);
			max_size = max(max_size, area_size[area]);
		}
	}

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (y + 1 < M && visited[y + 1][x] != visited[y][x])
					merge_max_size = max(merge_max_size, area_size[visited[y + 1][x]] + area_size[visited[y][x]]);

			if (x + 1 < N && visited[y][x + 1] != visited[y][x]) 
				merge_max_size = max(merge_max_size, area_size[visited[y][x + 1]] + area_size[visited[y][x]]);
		}
	}

	cout << area << '\n';
	cout << max_size << '\n';
	cout << merge_max_size;
	return 0;
}