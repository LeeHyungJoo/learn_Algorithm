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

using namespace std;


int M, N;
int board[100][100] = {};
int visited[100][100] = {};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//치즈 녹임. 
void DFS(int y, int x, set<pair<int, int>>& melts)
{
	visited[y][x] = 1;

	if (board[y][x] == 1)
	{
		melts.insert(make_pair(y, x));
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny > N || nx < 0 || nx > M || visited[ny][nx] == 1) continue;

		DFS(ny, nx, melts);
	}
}


int  main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
		}
	}

	int last_count = 0;
	int whole_count = 0;
	while (true)
	{
		set<pair<int, int>> melts;

		for (auto y : {0, N-1})
		{
			for (int x = 0; x < M; x++)
			{
				if (board[y][x] == 1 || visited[y][x] == 1) continue;
				DFS(y, x, melts);
			}
		}

		for (auto x : { 0, M - 1 })
		{
			for (int y = 0; y < N; y++)
			{
				if (board[y][x] == 1 || visited[y][x] == 1) continue;
				DFS(y, x, melts);
			}
		}

		if (melts.empty())
			break;

		last_count = melts.size();
		for (auto melt : melts)
			board[melt.first][melt.second] = 0;

		for (int y = 0; y < N ; y++)
			fill(visited[y], visited[y] + M, 0);

		whole_count++;
	}

	cout << whole_count << '\n' << last_count;
	return 0;
}