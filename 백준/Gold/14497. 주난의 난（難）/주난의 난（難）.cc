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
int x2, y2;

char maps[300][300] = { };
bool visited[300][300] = {};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void DFS(int y, int x, vector<pair<int,int>>& deleted_coords, bool& bFind)
{
	if (bFind)
	{
		return;
	}

	visited[y][x] = 1;

	if (maps[y][x] == '#')
	{
		bFind = true;
		return;
	}
	else if (maps[y][x] == '1')
	{
		deleted_coords.push_back(make_pair(y, x));
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1 || visited[ny][nx])
		{
			continue;
		}

		DFS(ny, nx, deleted_coords, bFind);
	}


	return;
}

int main()
{
	cin >> N >> M;

	int x1, y1; 
	cin >> y1 >> x1 >> y2 >> x2;
	--x1;--y1;--x2, --y2;

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> maps[n][m];
		}
	}

	int count = 0;
	while (true)
	{
		count++;
		bool bFind = false;
		vector<pair<int, int>> deleted_coords;
		DFS(y1, x1, deleted_coords, bFind);

		if (bFind)
		{
			break;
		}
		else
		{
			for (auto c : deleted_coords)
			{
				maps[c.first][c.second] = '0';
			}
		}

		memset(visited, 0, sizeof(visited));
	}

	cout << count;

	return 0;
}