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

int answer;
int R,C,K;
char maps[5][5];
int visited[5][5];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1, 0,-1 };

void DFS(int y, int x, int cnt)
{
	if (cnt > K) 
	{
		return;
	}

	if (y == 0 && x == C - 1 && cnt == K)
	{
		answer++;
	}

	visited[y][x] = 1;

	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1 || visited[ny][nx] || maps[ny][nx] =='T')
			continue;

		DFS(ny, nx, cnt + 1);
	}


	visited[y][x] = 0;
}

int main()
{
	cin >> R >> C >> K;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> maps[r][c];
		}
	}

	DFS(R - 1, 0, 1);
	cout << answer << endl;

	return 0;
}