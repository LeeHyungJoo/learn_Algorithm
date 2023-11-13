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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char maps[20][20] = { };
char visited[26] = {};

int max_v;

void DFS(int y, int x, int cnt)
{
	visited[maps[y][x] - 'A'] = 1;
	max_v = max(cnt, max_v);

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1 || visited[maps[ny][nx] - 'A'] > 0)
		{
			continue;
		}

		DFS(ny, nx, cnt +1);
	}

	visited[maps[y][x] - 'A'] = 0;
}


int main()
{
	cin >> R >> C;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> maps[r][c];
		}
	}

	DFS(0, 0, 1);

	cout << max_v;

	return 0;
}